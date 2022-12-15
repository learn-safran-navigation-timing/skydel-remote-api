#include "remote_simulator.h"
#include "cmd_client.h"
#include "hil_client.h"
#include <iostream>
#include "all_commands.h"
#include "command_exception.h"
#include <exception>
#include "lla.h"
#include "ecef.h"
#include "attitude.h"
#include <sstream>

using namespace Sdx;

RemoteSimulator::RemoteSimulator(bool exceptionOnError)
  : m_exceptionOnError(exceptionOnError),
  m_client(0),
  m_hil(0),
  m_verbose(false),
  m_hilStreamingCheckEnabled(true),
  m_beginTrack(false),
  m_beginRoute(false),
  m_serverApiVersion(0)
{
  resetTime();
}

RemoteSimulator::~RemoteSimulator()
{
  if (isConnected())
  {
    disconnect();
  }
}

void RemoteSimulator::resetTime()
{
  m_checkRunningTime = -999999999;
}

bool RemoteSimulator::connect(const std::string& ip, int id, bool failIfApiVersionMismatch)
{
  if (isConnected())
  {
    errorMessage("Cannot connect. Already connected. Disconnect first.");
    return false;
  }

  int port = 4820 + id;
  if (isVerbose())
    std::cout << "Connecting to " << ip << " port on " << port << "..." << std::endl;

  delete m_client;
  m_client = new CmdClient(m_exceptionOnError);
  m_client->setVerbose(m_verbose);
  if (!m_client->connectToHost(ip, port))
  {
    delete m_client;
    m_client = 0;
    return false;
  }

  m_serverApiVersion = m_client->getServerApiVersion();
  if (clientApiVersion() != m_serverApiVersion)
  {
    std::stringstream ss;
    ss << "Client API Version (" << clientApiVersion() << ") != Server API Version (" << m_serverApiVersion << ")";
    if (failIfApiVersionMismatch)
    {
      delete m_client;
      m_client = 0;
      errorMessage(ss.str());
      return false;
    }
    else
    {
      std::cout << "Warning: " << ss.str() << std::endl;
    }
  }

  int hilPort = Cmd::HilPortResult::dynamicCast(callCommand(Cmd::GetHilPort::create()))->port();
  delete m_hil;
  m_hil = new HilClient(m_exceptionOnError);
  m_hil->setVerbose(m_verbose);
  if (!m_hil->connectToHost(m_client->address(), hilPort))
  {
    delete m_client;
    m_client = 0;
    delete m_hil;
    m_hil = 0;
    return false;
  }

  return true;
}

void RemoteSimulator::disconnect()
{
  if (isVerbose())
    std::cout << "Commands Client Disconnecting" << std::endl;
  delete m_client;
  m_client = 0;
  delete m_hil;
  m_hil = 0;
}

bool RemoteSimulator::isConnected() const
{
  return m_client && m_client->isConnected();
}

int RemoteSimulator::clientApiVersion()
{
  return COMMANDS_API_VERSION;
}

int RemoteSimulator::serverApiVersion() const
{
  if (isConnected())
  {
    return m_serverApiVersion;
  }
  else
  {
    throw std::runtime_error("Server API Version unavailable. You must be connected to the server first.");
  }
}

void RemoteSimulator::errorMessage(const std::string& msg)
{
  if (m_exceptionOnError)
    throw std::runtime_error(msg);
  if (m_verbose)
    std::cout << msg << std::endl;
}

void RemoteSimulator::setDeprecatedMessageMode(DeprecatedMessageMode mode)
{
  m_deprecatedMessageMode = mode;
  m_latchDeprecated.clear();
}

void RemoteSimulator::deprecatedMessage(CommandBasePtr cmd)
{
  auto deprecated = cmd->deprecated();
  if (deprecated && (m_deprecatedMessageMode == DeprecatedMessageMode::ALL || (m_deprecatedMessageMode == DeprecatedMessageMode::LATCH && m_latchDeprecated.find(cmd->name()) == m_latchDeprecated.end())))
  {
    std::cout << "Warning: " << *deprecated << std::endl;
    m_latchDeprecated.insert(cmd->name());
  }
}

void RemoteSimulator::setVerbose(bool verbose)
{
  m_verbose = verbose;
  if (m_client)
    m_client->setVerbose(verbose);
  if (m_hil)
    m_hil->setVerbose(verbose);
}

bool RemoteSimulator::isVerbose() const
{
  return m_verbose;
}

void RemoteSimulator::setHilStreamingCheckEnabled(bool hilStreamingCheckEnabled)
{
  m_hilStreamingCheckEnabled = hilStreamingCheckEnabled;
}

bool RemoteSimulator::isHilStreamingCheckEnabled()
{
  return m_hilStreamingCheckEnabled;
}

bool RemoteSimulator::arm()
{
  if (isVerbose())
    std::cout << "Arming simulation..." << std::endl;

  if (!callCommand(Cmd::Arm::create())->isSuccess())
  {
    if (isVerbose())
      std::cout << "Failed to arm, simulation." << std::endl;
    return false;
  }
  resetTime();
  if (isVerbose())
    std::cout << "Simulation armed." << std::endl;
  return true;
}

bool RemoteSimulator::start()
{
  if (isVerbose())
    std::cout << "Starting simulation..." << std::endl;

  if (!callCommand(Cmd::Start::create())->isSuccess())
  {
    if (isVerbose())
      std::cout << "Failed to start simulation." << std::endl;
    return false;
  }

  m_hil->clearVehicleInfo();
  resetTime();

  if (isVerbose())
  {
    std::cout << "Simulation started." << std::endl;
    Cmd::SimulatorStateResultPtr result = Cmd::SimulatorStateResult::dynamicCast(callCommand(std::make_shared<Cmd::GetSimulatorState>()));
    if (!result)
      std::cout << "Unable to find simulator state!" << std::endl;
    else if (result->subStateId() == Sdx::SimulatorSubState::Started_HILSync)
      std::cout << "HIL Mode: Please send positions" << std::endl;
  }
  return true;
}

void RemoteSimulator::stop()
{
  resetTime();

  callCommand(Cmd::Stop::create());

  if (isVerbose())
    std::cout << "Simulation stopped." << std::endl;
}

void RemoteSimulator::stop(double timestamp)
{
  resetTime();

  CommandBasePtr stopCmd = postCommand(Cmd::Stop::create(), timestamp);

  if (isVerbose())
    std::cout << "Stopping simulation at " << timestamp << " seconds..." << std::endl;

  waitCommand(stopCmd);

  if (isVerbose())
    std::cout << "Simulation stopped." << std::endl;
}

void RemoteSimulator::checkForbidden(CommandBasePtr cmd)
{
  if (cmd->name() == "Start")
    throw std::runtime_error("You cannot send a Start() command. Use RemoteSimulator.start() instead.");
  if (cmd->name() == "BeginTrackDefinition")
    throw std::runtime_error("You cannot send a BeginTrackDefinition command. Use RemoteSimulator.beginTrackDefinition() instead.");
  if (cmd->name() == "EndTrackDefinition")
    throw std::runtime_error("You cannot send a EndTrackDefinition command. Use RemoteSimulator.endTrackDefinition() instead.");
  if (cmd->name() == "BeginRouteDefinition")
    throw std::runtime_error("You cannot send a BeginRouteDefinition command. Use RemoteSimulator.beginRouteDefinition() instead.");
  if (cmd->name() == "EndRouteDefinition")
    throw std::runtime_error("You cannot send a EndRouteDefinition command. Use RemoteSimulator.endRouteDefinition() instead.");
  if (cmd->name() == "PushRouteEcef")
    throw std::runtime_error("You cannot send a PushRouteEcef command. Use RemoteSimulator.pushRouteEcef() or RemoteSimulator.pushRouteLla() instead.");
  if (cmd->name() == "PushTrackEcef")
    throw std::runtime_error("You cannot send a PushTrackEcef command. Use RemoteSimulator.pushTrackLla() or RemoteSimulator.pushTrackEcef() instead.");
  if (cmd->name() == "PushTrackEcefNed")
    throw std::runtime_error("You cannot send a PushTrackEcef command. Use RemoteSimulator.pushTrackLlaNed() or RemoteSimulator.pushTrackEcefNed() instead.");
}

bool RemoteSimulator::checkIfStreaming()
{
  Cmd::SimulatorStateResultPtr stateResult = Cmd::SimulatorStateResult::dynamicCast(callCommand(Cmd::GetSimulatorState::create()));

  if (stateResult->state() == "Streaming RF")
    return true;

  std::string errorMsg;
  if (stateResult->state() == "Error")
    errorMsg = "An error occured during simulation. Error message:\n" + stateResult->error();
  else
    errorMsg = "Simulator is no more streaming. Current state is " + stateResult->state() + ".";

  if (m_exceptionOnError)
    throw std::runtime_error(errorMsg);

  if (isVerbose())
    std::cout << errorMsg << std::endl;
  return false;
}

bool RemoteSimulator::waitState(const std::string& state, const std::string& failureState)
{
  if (isVerbose())
    std::cout << "Waiting for simulator state " << std::endl;

  Cmd::SimulatorStateResultPtr stateResult =
    Cmd::SimulatorStateResult::dynamicCast(callCommand(Cmd::WaitSimulatorState::create(state, failureState)));

  std::string errorMsg;
  if (stateResult->state() == state)
  {
    if (isVerbose())
      std::cout << "Simulator state is now to " << state << std::endl;
    return true;
  }
  else if (stateResult->state() == "Error")
  {
    errorMsg = "An error occured during simulation. Error message:\n" + stateResult->error();
  }
  else
  {
    errorMsg = "Wrong simulator state. Expected " + state + " but received " + stateResult->state();
  }

  if (m_exceptionOnError)
    throw std::runtime_error(errorMsg);

  if (isVerbose())
    std::cout << errorMsg << std::endl;
  return false;
}

bool RemoteSimulator::hilCheck(double elapsedTime)
{
  if (m_checkRunningTime < 0.0)
    m_checkRunningTime = elapsedTime;

  if (elapsedTime - m_checkRunningTime >= 1000)
  {
    m_checkRunningTime = elapsedTime;
    if (m_hilStreamingCheckEnabled && !checkIfStreaming())
    {
      resetTime();
      return false;
    }
    if (m_verbose)
      std::cout << "Position sent at " << elapsedTime << " ms" << std::endl;
  }

  return true;
}

bool RemoteSimulator::hasVehicleInfo()
{
  return m_hil->hasRecvVehicleInfo(0, false);
}

CommandResultPtr RemoteSimulator::beginVehicleInfo()
{
  return callCommand(Cmd::BeginVehicleInfo::create());
}

CommandResultPtr RemoteSimulator::endVehicleInfo()
{
  return callCommand(Cmd::EndVehicleInfo::create());
}

bool RemoteSimulator::nextVehicleInfo(VehicleInfo& vehicleInfo)
{
  return m_hil->recvNextVehicleInfo(vehicleInfo);
}

bool RemoteSimulator::lastVehicleInfo(VehicleInfo& vehicleInfo)
{
  return m_hil->recvLastVehicleInfo(vehicleInfo);
}

bool RemoteSimulator::pushEcef(double elapsedTime, const Ecef& position, const std::string& name)
{
  if (!m_hil)
    throw std::runtime_error("Cannot send position to simulator because you are not connected.");

  m_hil->pushEcef(elapsedTime, position, name);
  return hilCheck(elapsedTime);
}

bool RemoteSimulator::pushEcef(double elapsedTime, const Ecef& position, const Ecef& velocity, const std::string& name)
{
	if (!m_hil)
		throw std::runtime_error("Cannot send position to simulator because you are not connected.");

	m_hil->pushEcef(elapsedTime, position, velocity, name);
	return hilCheck(elapsedTime);
}

bool RemoteSimulator::pushEcef(double elapsedTime, const Ecef& position, const Ecef& velocity, const Ecef& acceleration, const std::string& name)
{
	if (!m_hil)
		throw std::runtime_error("Cannot send position to simulator because you are not connected.");

	m_hil->pushEcef(elapsedTime, position, velocity, acceleration, name);
	return hilCheck(elapsedTime);
}

bool RemoteSimulator::pushEcef(double elapsedTime, const Ecef& position, const Ecef& velocity, const Ecef& acceleration, const Ecef& jerk, const std::string& name)
{
	if (!m_hil)
		throw std::runtime_error("Cannot send position to simulator because you are not connected.");

	m_hil->pushEcef(elapsedTime, position, velocity, acceleration, jerk, name);
	return hilCheck(elapsedTime);
}

bool RemoteSimulator::pushLla(double elapsedTime, const Lla& lla, const std::string& name)
{
  Ecef ecef;
  lla.toEcef(ecef);
  return pushEcef(elapsedTime, ecef, name);
}

bool RemoteSimulator::pushEcefNed(double elapsedTime, const Ecef& position, const Attitude& attitude, const std::string& name)
{
  if (!m_hil)
    throw std::runtime_error("Cannot send position to simulator because you are not connected.");

  m_hil->pushEcefNed(elapsedTime, position, attitude, name);
  return hilCheck(elapsedTime);
}

bool RemoteSimulator::pushEcefNed(double elapsedTime, const Ecef& position, const Attitude& attitude, const Ecef& velocity, const Attitude& angularVelocity, const std::string& name)
{
	if (!m_hil)
		throw std::runtime_error("Cannot send position to simulator because you are not connected.");

	m_hil->pushEcefNed(elapsedTime, position, attitude, velocity, angularVelocity, name);
	return hilCheck(elapsedTime);
}

bool RemoteSimulator::pushEcefNed(double elapsedTime, const Ecef& position, const Attitude& attitude, const Ecef& velocity, const Attitude& angularVelocity, const Ecef& acceleration, const Attitude& angularAcceleration, const std::string& name)
{
	if (!m_hil)
		throw std::runtime_error("Cannot send position to simulator because you are not connected.");

	m_hil->pushEcefNed(elapsedTime, position, attitude, velocity, angularVelocity, acceleration, angularAcceleration, name);
	return hilCheck(elapsedTime);
}

bool RemoteSimulator::pushEcefNed(double elapsedTime, const Ecef& position, const Attitude& attitude, const Ecef& velocity, const Attitude& angularVelocity, const Ecef& acceleration, const Attitude& angularAcceleration, const Ecef& jerk, const  Attitude& angularJerk, const std::string& name)
{
	if (!m_hil)
		throw std::runtime_error("Cannot send position to simulator because you are not connected.");

	m_hil->pushEcefNed(elapsedTime, position, attitude, velocity, angularVelocity, acceleration, angularAcceleration, jerk, angularJerk, name);
	return hilCheck(elapsedTime);
}

bool RemoteSimulator::pushLlaNed(double elapsedTime, const Lla& lla, const Attitude& attitude, const std::string& name)
{
  Ecef ecef;
  lla.toEcef(ecef);
  return pushEcefNed(elapsedTime, ecef, attitude, name);
}

CommandResultPtr RemoteSimulator::beginTrackDefinition()
{
  CommandResultPtr result = callCommand(Cmd::BeginTrackDefinition::create());
  if (result->isSuccess())
    m_beginTrack = true;
  return result;
}

void RemoteSimulator::pushTrackEcef(long long elapsedTime, const Ecef& ecef)
{
  if (!m_beginTrack)
    throw std::runtime_error("You must call beginTrackDefinition first.");
  postCommand(Cmd::PushTrackEcef::create(elapsedTime, ecef.x, ecef.y, ecef.z));
}

void RemoteSimulator::pushTrackEcefNed(long long elapsedTime, const Ecef& ecef, const Attitude& attitude)
{
  if (!m_beginTrack)
    throw std::runtime_error("You must call beginTrackDefinition first.");
  postCommand(Cmd::PushTrackEcefNed::create(elapsedTime, ecef.x, ecef.y, ecef.z,
    attitude.yaw, attitude.pitch, attitude.roll));
}

void RemoteSimulator::pushTrackLla(long long elapsedTime, const Lla& lla)
{
  Ecef ecef;
  lla.toEcef(ecef);
  pushTrackEcef(elapsedTime, ecef);
}

void RemoteSimulator::pushTrackLlaNed(long long elapsedTime, const Lla& lla, const Attitude& attitude)
{
  Ecef ecef;
  lla.toEcef(ecef);
  pushTrackEcefNed(elapsedTime, ecef, attitude);
}

CommandResultPtr RemoteSimulator::endTrackDefinition(int& numberOfNodesInTrack)
{
  if (!m_beginTrack)
    throw std::runtime_error("You must call beginTrackDefinition first and pushTrackEcef/pushTrackLla with all the Track nodes before calling endTrackDefinition.");
  m_beginTrack = false;
  CommandResultPtr result = callCommand(Cmd::EndTrackDefinition::create());
  if (result->isSuccess())
  {
    Cmd::EndTrackDefinitionResultPtr trackResult = Cmd::EndTrackDefinitionResult::dynamicCast(result);
    numberOfNodesInTrack = trackResult->count();
  }
  else
  {
    numberOfNodesInTrack = 0;
  }
  return result;
}


CommandResultPtr RemoteSimulator::beginRouteDefinition()
{
  CommandResultPtr result = callCommand(Cmd::BeginRouteDefinition::create());
  if (result->isSuccess())
    m_beginRoute = true;
  return result;
}

void RemoteSimulator::pushRouteEcef(double speed, const Ecef& ecef)
{
  if (!m_beginRoute)
    throw std::runtime_error("You must call beginRouteDefinition first.");

  if (speed <= 0)
    throw std::runtime_error("A route node must have a speed limit greater than zero.");

  postCommand(Cmd::PushRouteEcef::create(speed, ecef.x, ecef.y, ecef.z));
}

void RemoteSimulator::pushRouteLla(double speed, const Lla& lla)
{
  Ecef ecef;
  lla.toEcef(ecef);
  pushRouteEcef(speed, ecef);
}

CommandResultPtr RemoteSimulator::endRouteDefinition(int& numberOfNodesInRoute)
{
  if (!m_beginRoute)
    throw std::runtime_error("You must call beginRouteDefinition first and pushRouteEcef/pushRouteLla with all the route nodes before calling endRouteDefinition.");
  m_beginRoute = false;
  CommandResultPtr result = callCommand(Cmd::EndRouteDefinition::create());
  if (result->isSuccess())
  {
    Cmd::EndRouteDefinitionResultPtr routeResult = Cmd::EndRouteDefinitionResult::dynamicCast(result);
    numberOfNodesInRoute = routeResult->count();
  }
  else
  {
    numberOfNodesInRoute = 0;
  }
  return result;
}


void RemoteSimulator::handleException(CommandResultPtr result)
{
  if (m_exceptionOnError && !result->isSuccess())
  {
    Cmd::SimulatorStateResultPtr stateResult = Cmd::SimulatorStateResult::dynamicCast(call(Cmd::GetSimulatorState::create()));
    std::string errorMsg;
    if (stateResult->state() == "Error")
      errorMsg = "\nAn error occured during simulation. Error message:\n" + stateResult->error();

    throw CommandException(result, errorMsg);
  }
  if (isVerbose() && !result->isSuccess())
    std::cout << result->relatedCommand()->name() << " failed: " << result->message() << std::endl;
}

CommandBasePtr RemoteSimulator::post(CommandBasePtr cmd, double timestamp)
{
  checkForbidden(cmd);
  if (isVerbose())
    std::cout << "Post " << cmd->toReadableCommand() << " at " << cmd->timestamp() << " secs" << std::endl;
  postCommand(cmd, timestamp);
  return cmd;
}

CommandBasePtr RemoteSimulator::post(CommandBasePtr cmd)
{
  checkForbidden(cmd);
  if (isVerbose())
    std::cout << "Post " << cmd->toReadableCommand() << std::endl;
  postCommand(cmd);
  return cmd;
}

CommandResultPtr RemoteSimulator::wait(CommandBasePtr cmd)
{
  if (isVerbose())
    std::cout << "Wait " << cmd->toReadableCommand() << std::flush;
  CommandResultPtr result = waitCommand(cmd);
  if (isVerbose())
    std::cout << " => " << result->message() << std::endl;
  return result;
}

CommandResultPtr RemoteSimulator::call(CommandBasePtr cmd, double timestamp)
{
  checkForbidden(cmd);
  postCommand(cmd, timestamp);
  if (isVerbose())
    std::cout << "Call " << cmd->toReadableCommand() << " at " << cmd->timestamp() << " secs" << std::flush;
  CommandResultPtr result = waitCommand(cmd);
  if (isVerbose())
    std::cout << " => " << result->message() << std::endl;
  return result;
}

CommandResultPtr RemoteSimulator::call(CommandBasePtr cmd)
{
  checkForbidden(cmd);
  postCommand(cmd);
  if (isVerbose())
    std::cout << "Call " << cmd->toReadableCommand() << std::flush;
  CommandResultPtr result = waitCommand(cmd);
  if (isVerbose())
    std::cout << " => " << result->message() << std::endl;
  return result;
}

CommandBasePtr RemoteSimulator::postCommand(CommandBasePtr cmd, double timestamp)
{
  deprecatedMessage(cmd);
  cmd->setTimestamp(timestamp);
  m_client->sendCommand(cmd);
  return cmd;
}

CommandBasePtr RemoteSimulator::postCommand(CommandBasePtr cmd)
{
  deprecatedMessage(cmd);
  m_client->sendCommand(cmd);
  return cmd;
}

CommandResultPtr RemoteSimulator::waitCommand(CommandBasePtr cmd)
{
  CommandResultPtr result = m_client->waitCommand(cmd);
  handleException(result);
  return result;
}

CommandResultPtr RemoteSimulator::callCommand(CommandBasePtr cmd, double timestamp)
{
  postCommand(cmd, timestamp);
  return waitCommand(cmd);
}

CommandResultPtr RemoteSimulator::callCommand(CommandBasePtr cmd)
{
  postCommand(cmd);
  return waitCommand(cmd);
}

int Sdx::spooferInstance(int id)
{
  return 128 + id;
}
