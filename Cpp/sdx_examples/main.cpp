////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Orolia Canada Inc.
// Skydel - Software-Defined GNSS Simulator
// Remote API C++ Examples
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// NOTES:
// 1- Before executing the examples, make sure Simulator is running on local computer.
// 2- During the Execution, you can get execution details by enabling the verbose mode: sim.setVerbose(true);
// 3- All examples are set to run without hardware.
//    You can easily change the TARGET_TYPE to "X300", for example
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#if _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif

#include <iomanip>
#include <iostream>
#include <thread>
#include <chrono>
#define _USE_MATH_DEFINES
#include <math.h>

#include "remote_simulator.h"
#include "all_commands.h"
#include "command_exception.h"
#include "hil_client.h"
#include "lla.h"
#include "enu.h"
#include "ecef.h"
#include "vehicle_info.h"

using namespace Sdx;
using namespace Sdx::Cmd;

#define VERBOSE false
#define RADIAN(degree) degree/180.0*M_PI

int main(int argc, char * argv[]);

void runExampleBasic(const std::string& host, const std::string& targetType, const std::string& X300IP);
void runExampleFailureHandling(const std::string& host, const std::string& targetType, const std::string& X300IP);
void runExampleGetElapsedTime(const std::string& host, const std::string& targetType, const std::string& X300IP);
void runExampleCreateTrack(const std::string& host, const std::string& targetType, const std::string& X300IP);
void runExampleCreateTrack6dof(const std::string& host, const std::string& targetType, const std::string& X300IP);
void runExampleCreateRouteCar(const std::string& host, const std::string& targetType, const std::string& X300IP);
void runExampleHilRealtime(const std::string& host, const std::string& targetType, const std::string& X300IP, bool autoAttitude);
void runExampleInterferences(const std::string& host, const std::string& targetType, const std::string& X300IP);
void runExampleVehicleInfo(const std::string& host, const std::string& targetType, const std::string& X300IP);
void runExamplePauseResume(const std::string& host, const std::string& targetType, const std::string& X300IP);
void runExampleAutomaticStop(const std::string& host, const std::string& targetType, const std::string& X300IP);
void runExampleGetPower(const std::string& host, const std::string& targetType, const std::string& X300IP);

int main(int argc, char* argv[])
{
  // If you wish to connect to the simulator running on a remote computer,
  // change "localhost" for the remote computer's IP address, such as "192.168.1.100"
  const std::string HOST = "localhost";
  const std::string TARGET_TYPE = "NoneRT";       // Change to "X300" to execute on a X300 device
  const std::string X300_IP = ""; // Change to "192.168.XXX.XXX" to execute on a X300 device

  try
  {
    runExampleBasic(HOST, TARGET_TYPE, X300_IP);
    runExampleVehicleInfo(HOST, TARGET_TYPE, X300_IP);
    runExampleCreateTrack(HOST, TARGET_TYPE, X300_IP);
    runExampleCreateTrack6dof(HOST, TARGET_TYPE, X300_IP);
    runExampleCreateRouteCar(HOST, TARGET_TYPE, X300_IP);
    runExampleHilRealtime(HOST, TARGET_TYPE, X300_IP, true);
    runExampleHilRealtime(HOST, TARGET_TYPE, X300_IP, false);
    runExampleGetElapsedTime(HOST, TARGET_TYPE, X300_IP);
    runExampleInterferences(HOST, TARGET_TYPE, X300_IP);
    runExamplePauseResume(HOST, TARGET_TYPE, X300_IP);
    runExampleAutomaticStop(HOST, TARGET_TYPE, X300_IP);
    runExampleFailureHandling(HOST, TARGET_TYPE, X300_IP);
    runExampleGetPower(HOST, TARGET_TYPE, X300_IP);
  }
  catch (CommandException& e)
  {
    std::cout << "Simulator Command Exception caught:\n" << e.what() << std::endl;
  }
  catch (std::runtime_error& e)
  {
    std::cout << "Runtime Error Exception caught:\n" << e.what() << std::endl;
  }

  std::cout << "Press any key to exit..." << std::endl;
  std::cin.get(); //waits for character

  return 0;
}

static long long currentTime()
{
  using namespace std::chrono;
  return duration_cast<milliseconds>(high_resolution_clock::now().time_since_epoch()).count();
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Basic Example
// This example shows:
// 1- How to connect to the simulator
// 2- Set Basic Simulation Parameters
// 3- Start Simulation
// 4- Send command to the simulator during the simulation
// 5- Stop the simulation, and disconnect from the simulator
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void runExampleBasic(const std::string& host, const std::string& targetType, const std::string& X300IP)
{
  std::cout << "=== Basic Example ===" << std::endl;

  std::cout << "==> Connecting to the simulator" << std::endl;
  RemoteSimulator sim;
  sim.setVerbose(VERBOSE);
  sim.connect(host);

  std::cout << "==> Create New Configuration, discarding current simulator settings" << std::endl;
  sim.call(New::create(true));

  std::cout << "==> Modulation Settings" << std::endl;
  std::string targetId = "MyOutputId";
  SetModulationTargetPtr setModulationTargetCmd = SetModulationTarget::create(targetType, "", X300IP, true, targetId);
  sim.call(setModulationTargetCmd);
  // Select signals to simulate
  sim.call(ChangeModulationTargetSignals::create(0, 12500000, 12500000, "UpperL", "L1CA", -1, false, targetId));

  std::cout << "==> Vehicle Settings" << std::endl;
  sim.call(SetVehicleTrajectoryCircular::create("Circular", 0.7853995339022749, -1.2740964277717111, 0, 50, 3, true));
  sim.call(SetGpsStartTime::create(DateTime(2021, 2, 15, 7, 0, 0)));
  sim.call(SetVehicleAntennaGain::create({}, AntennaPatternType::AntennaNone, GNSSBand::L1));

  std::cout << "==> Arming the simulation" << std::endl;
  sim.arm();

  std::cout << "==> Change satellite 16 power to +5 dB  (relative to nominal power)" << std::endl;
  sim.post(SetPowerForSV::create("GPS", 16, 5, false));

  std::cout << "==> Starting the simulation" << std::endl;
  sim.start();

  std::cout << "==> Right after start, change satellite 25 power to -15dB (relative to nominal power)" << std::endl;
  sim.call(SetPowerForSV::create("GPS", 25, -15, false));

  // Asynchronous command examples
  std::cout << "==> CMD #1: At Simulation Time 9.567s, Change satellite 32 power to -25dB (relative to nominal power)" << std::endl;
  CommandBasePtr cmd1 = sim.post(SetPowerForSV::create("GPS", 32, -25, false), 9.567);
  std::cout << "==> CMD #2: At Simulation Time 12.05s, Change satellite 29 power to +10dB (relative to nominal power)" << std::endl;
  CommandBasePtr cmd2 = sim.post(SetPowerForSV::create("GPS", 29, 10, false), 12.05);

  // Wait for commands to complete
  std::cout << "==> Waiting for CMD #1..." << std::flush;
  sim.wait(cmd1);
  std::cout << "Done!" << std::endl;

  std::cout << "==> Waiting for CMD #2..." << std::flush;
  sim.wait(cmd2);
  std::cout << "Done!" << std::endl;

  std::cout << "==> At Simulation Time 15s, reset all satellites to nominal power" << std::endl;
  sim.call(ResetAllSatPower::create("GPS"), 15);

  std::cout << "==> Pause vehicle motion" << std::endl;
  sim.call(Pause::create());
  sim.call(Resume::create(), 18);
  std::cout << "==> Vehicle motion resumed at 18 sec" << std::endl;

  std::cout << "==> Stop simulation when elapsed time is 20 sec..." << std::endl;
  sim.stop(20);

  std::cout << "==> Disconnect from Simulator" << std::endl;
  sim.disconnect();
}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Failure Handling Example
// This example shows:
// 1- How to verify command result
// 2- How to get error messages from command failure
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void runExampleFailureHandling(const std::string& host, const std::string& targetType, const std::string& X300IP)
{
  std::cout << std::endl << "=== Failure handling Example ===" << std::endl;

  std::cout << "==> Connecting to the simulator" << std::endl;
  //RemoteSimulator sim(true); //Stop the script with a exception if a command fail
  RemoteSimulator sim(false); //Does not stop the script with a exception if a command fail
  sim.setVerbose(VERBOSE);
  if (!sim.connect(host))
    return;

  std::cout << "==> Create New Configuration, discarding current simulator settings" << std::endl;
  sim.call(New::create(true));

  std::cout << "==> Modulation Settings" << std::endl;
  std::string targetId = "MyOutputId";
  SetModulationTargetPtr setModulationTargetCmd = SetModulationTarget::create(targetType, "", X300IP, true, targetId);
  sim.call(setModulationTargetCmd);
  // Select signals to simulate
  sim.call(ChangeModulationTargetSignals::create(0, 12500000, 12500000, "UpperL", "L1CA", -1, false, targetId));

  // Command Success Example:
  // Changing configuration before starting the simulation.
  CommandResultPtr result1 = sim.call(ChangeModulationTargetSignals::create(0, 12500000, 50000000, "UpperL", "L1CA,G1", -1, false, targetId));
  std::cout << "SUCCESS MESSAGE EXAMPLE: " << result1->message() << std::endl; //Will print Success

  // Command Failure Example:
  // The following command is not allowed before you start the simulation.
  CommandResultPtr result2 = sim.call(SetPowerForSV::create("GPS", 12, -10, true));
  std::cout << "FAILURE MESSAGE EXAMPLE: " << result2->message() << std::endl;

  std::cout << "==> Starting Simulation" << std::endl;
  if (sim.start())
  {
    // Change satellite 14 power to -15dB (relative to nominal power)
    sim.call(SetPowerForSV::create("GPS", 14, -15, false));

    // Command Failure Example:
    // The following command (setting simulation start time) is not allowed once simulation is started.
    CommandResultPtr result3 = sim.call(SetGpsStartTime::create(DateTime(2021, 2, 15, 7, 0, 0)));
    std::cout << "FAILURE MESSAGE EXAMPLE: " << result3->relatedCommand()->toReadableCommand() << ": " << result3->message() << std::endl;

    // Asynchronous Success command example
    // When simulation elapsed time is 9.567 sec, change satellite 31 power to -25 dB
    CommandBasePtr cmd4 = sim.post(SetPowerForSV::create("GPS", 31, -25, false), 9.567);

    // Asynchronous Failure command example
    // When simulation elapsed time is 12.05 sec, change satellite 200 power to +10 dB
    CommandBasePtr cmd5 = sim.post(SetPowerForSV::create("GPS", 200, 10, false), 12.05);

    // Wait for Asynchronous commands to complete
    CommandResultPtr result4 = sim.wait(cmd4);
    CommandResultPtr result5 = sim.wait(cmd5);

    std::cout << "SUCCESS MESSAGE EXAMPLE: " << result4->relatedCommand()->toReadableCommand() + ": " + result4->message() << std::endl;
    std::cout << "FAILURE MESSAGE EXAMPLE: " << result5->relatedCommand()->toReadableCommand() + ": " + result5->message() << std::endl;

    std::cout << "==> Stop simulation when elapsed time is 20 sec" << std::endl;
    sim.stop(20);
  }

  SimulatorStateResultPtr stateResult = SimulatorStateResult::dynamicCast(sim.call(GetSimulatorState::create()));
  if (stateResult->state() == "Error")
    std::cout << "An error occured during simulation. Error message:\n" << stateResult->error() << std::endl;

  sim.disconnect();
}

////////////////////////////////////////////////////////////////////////////////////////////////////
// Elapsed Time Example
// This examples shows how to:
// 1- Get the simulation Start Time
// 2- Get the simulation Elapsed Time
////////////////////////////////////////////////////////////////////////////////////////////////////
void runExampleGetElapsedTime(const std::string& host, const std::string& targetType, const std::string& X300IP)
{
  std::cout << "=== Getting Time Example ===" << std::endl;

  std::cout << "==> Connecting to the simulator" << std::endl;
  RemoteSimulator sim;
  sim.setVerbose(VERBOSE);
  sim.connect(host);

  std::cout << "==> Create New Configuration, discarding current simulator settings" << std::endl;
  sim.call(New::create(true));

  std::cout << "==> Example #1: Get the Simulation Start Time: " << std::endl;
  // We will get the Simulation Start Time of a newly created configuration.
  GetGpsStartTimePtr        getGpsStartTimeCmd = GetGpsStartTime::create();
  CommandResultPtr          cmdResult = sim.call(getGpsStartTimeCmd);
  GetGpsStartTimeResultPtr  gpsStartTime = GetGpsStartTimeResult::dynamicCast(cmdResult);
  std::cout << std::endl;
  std::cout << "  Simulation Start Time (GPS TIME): "
    << gpsStartTime->startTime().year << "-"
    << gpsStartTime->startTime().month << "-"
    << gpsStartTime->startTime().day << " "
    << std::setfill('0') << std::setw(2) << gpsStartTime->startTime().hour << ":"
    << std::setfill('0') << std::setw(2) << gpsStartTime->startTime().minute << ":"
    << std::setfill('0') << std::setw(2) << gpsStartTime->startTime().second << std::endl;
  std::cout << "  Simulation Start Leap Seconds   : " << gpsStartTime->leapSecond() << "s" << std::endl;
  std::cout << std::endl;

  std::cout << "==> Modulation Settings" << std::endl;
  std::string targetId = "MyOutputId";
  SetModulationTargetPtr setModulationTargetCmd = SetModulationTarget::create(targetType, "", X300IP, true, targetId);
  sim.call(setModulationTargetCmd);
  // Select signals to simulate
  sim.call(ChangeModulationTargetSignals::create(0, 12500000, 12500000, "UpperL", "L1CA", -1, false, targetId));

  std::cout << "==> Starting Simulation" << std::endl;
  sim.start();

  std::cout << "Example #2: Getting Simulation Time in a loop" << std::endl;
  GetSimulationElapsedTimePtr        getSimElapsedTimeCmd = GetSimulationElapsedTime::create();
  SimulationElapsedTimeResultPtr     simulationElaspedTime;

  int elaspedTimeMs = 0;
  while (elaspedTimeMs < 20000)
  {
    cmdResult = sim.call(getSimElapsedTimeCmd);
    simulationElaspedTime = SimulationElapsedTimeResult::dynamicCast(cmdResult);

    if (simulationElaspedTime)
    {
      elaspedTimeMs = simulationElaspedTime->milliseconds();
      std::cout << " Elapsed Time = " << simulationElaspedTime->milliseconds() << " miliseconds" << std::endl;
    }
    else
    {
      // Should never happen
      std::cout << "ERROR: unable to get TimeResult pointer after sending GetTime Command" << std::endl;
    }
    std::this_thread::sleep_for(std::chrono::milliseconds(250));
  }
  std::cout << "==> Stop simulation after 20 seconds of time polling" << std::endl;
  sim.stop();
  sim.disconnect();
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Vehicle Information Example
// This example shows:
// 1- Get Information about the simulated Vehicle during the simulation
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void runExampleVehicleInfo(const std::string& host, const std::string& targetType, const std::string& X300IP)
{
  std::cout << "=== Simulation Statistics Example ===" << std::endl;

  std::cout << "==> Connecting to the simulator" << std::endl;
  RemoteSimulator sim;
  sim.setVerbose(VERBOSE);
  sim.connect(host);

  std::cout << "==> Create New Configuration, discarding current simulator settings" << std::endl;
  sim.call(New::create(true));

  std::cout << "==> Modulation Settings" << std::endl;
  std::string targetId = "MyOutputId";
  SetModulationTargetPtr setModulationTargetCmd = SetModulationTarget::create(targetType, "", X300IP, true, targetId);
  sim.call(setModulationTargetCmd);
  // Select signals to simulate
  sim.call(ChangeModulationTargetSignals::create(0, 12500000, 12500000, "UpperL", "L1CA", -1, false, targetId));

  std::cout << "==> Vehicle Settings" << std::endl;
  sim.call(SetVehicleTrajectoryCircular::create("Circular", 0.7853995339022749, -1.2740964277717111, 0, 50, 3, true));

  std::cout << "==> Starting the simulation" << std::endl;

  std::cout << "==> Begin receiving vehicle informations" << std::endl;

  //You must call BeginVehicleInfo before getting vehicle informations
  sim.beginVehicleInfo();
  sim.start();

  std::cout << "==> Getting vehicle statistics" << std::endl;
  VehicleInfo vehicleInfo;
  sim.lastVehicleInfo(vehicleInfo);
  Lla originLla, currentLla;
  Enu currentEnu;
  vehicleInfo.ecef.toLla(originLla); //convert ecef origin to lla
  do
  {
    //sim.lastVehicleInfo() will block till a vehicle info is received,
    //you can use sim.hasVehicleInfo(), if you do not want a blocking behavior :
    //if (!sim.hasVehicleInfo()) continue;

    sim.lastVehicleInfo(vehicleInfo);
    vehicleInfo.ecef.toLla(currentLla); //convert ecef to lla
    currentLla.toEnu(originLla, currentEnu); //convert lla to enu
    std::cout << "--------------------------------------------------" << std::endl;
    std::cout << "Time (ms): " << vehicleInfo.elapsedTime << std::endl;
    std::cout << "ENU Position (meters): " << std::fixed << std::setprecision(2);
    std::cout << currentEnu.n << ", " << currentEnu.e << ", " << currentEnu.u << std::endl;
    std::cout << "NED Attitude (deg): " << vehicleInfo.attitude.yawDeg() << ", ";
    std::cout << vehicleInfo.attitude.pitchDeg() << ", " << vehicleInfo.attitude.rollDeg() << std::endl;
    std::cout << "Odometer (meters): " << vehicleInfo.odometer << " | Heading (deg): " << (vehicleInfo.heading / M_PI * 180);
    std::cout << " | Speed (m/s): " << vehicleInfo.speed << std::endl;

    //You can remove or decrease this sleep to get more resolution
    //A vehicle info is sent each 10 ms from simulator
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
  } while (vehicleInfo.elapsedTime < 90000);

  std::cout << "==> Stop simulation when elapsed time is 90 sec..." << std::endl;
  sim.stop();
  sim.endVehicleInfo();

  std::cout << "==> Disconnect from Simulator" << std::endl;
  sim.disconnect();
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Track creation Example
// This example shows:
// 1- Create a vehicle trajectory from different nodes forming a track.
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void runExampleCreateTrack(const std::string& host, const std::string& targetType, const std::string& X300IP)
{
  std::cout << "=== Create Track Example ===" << std::endl;

  std::cout << "==> Connecting to the simulator" << std::endl;
  RemoteSimulator sim;
  sim.setVerbose(VERBOSE);
  sim.connect(host);

  std::cout << "==> Create New Configuration, discarding current simulator settings" << std::endl;
  sim.call(New::create(true));

  std::cout << "==> Modulation Settings" << std::endl;
  std::string targetId = "MyOutputId";
  SetModulationTargetPtr setModulationTargetCmd = SetModulationTarget::create(targetType, "", X300IP, true, targetId);
  sim.call(setModulationTargetCmd);
  // Select signals to simulate
  sim.call(ChangeModulationTargetSignals::create(0, 12500000, 12500000, "UpperL", "L1CA", -1, false, targetId));

  sim.call(SetVehicleTrajectory::create("Track"));
  sim.beginTrackDefinition();

  sim.pushTrackLla(0, Lla(RADIAN(45.0000), RADIAN(-73.0000), 0));
  sim.pushTrackLla(5000, Lla(RADIAN(45.0005), RADIAN(-73.0005), 0));
  sim.pushTrackLla(10000, Lla(RADIAN(45.0010), RADIAN(-73.0000), 0));
  sim.pushTrackLla(15000, Lla(RADIAN(45.0015), RADIAN(-73.0005), 0));
  sim.pushTrackLla(20000, Lla(RADIAN(45.0020), RADIAN(-73.0000), 0));

  int numberOfNodes;
  sim.endTrackDefinition(numberOfNodes);
  std::cout << "==> Track created, number of nodes in Track = " << numberOfNodes << std::endl;

  std::cout << "==> Starting Simulation" << std::endl;
  sim.start();

  std::cout << "==> Stopping Simulation when elapsed time will be 20s" << std::endl;
  sim.stop(20);

  std::cout << "==> Disconnect from Simulator" << std::endl;
  sim.disconnect();
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 6 Degrees of Freedom (6DOF) Track creation Example
// This example shows:
// 1- Create a vehicle trajectory from different nodes forming a 6DOF track.
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void runExampleCreateTrack6dof(const std::string& host, const std::string& targetType, const std::string& X300IP)
{
  std::cout << "=== Create Track 6 Degrees of Liberty Example ===" << std::endl;

  std::cout << "==> Connecting to the simulator" << std::endl;
  RemoteSimulator sim;
  sim.setVerbose(VERBOSE);
  sim.connect(host);

  std::cout << "==> Create New Configuration, discarding current simulator settings" << std::endl;
  sim.call(New::create(true));

  std::cout << "==> Modulation Settings" << std::endl;
  std::string targetId = "MyOutputId";
  SetModulationTargetPtr setModulationTargetCmd = SetModulationTarget::create(targetType, "", X300IP, true, targetId);
  sim.call(setModulationTargetCmd);
  // Select signals to simulate
  sim.call(ChangeModulationTargetSignals::create(0, 12500000, 12500000, "UpperL", "L1CA", -1, false, targetId));

  sim.call(SetVehicleTrajectory::create("Track"));
  sim.beginTrackDefinition();

  sim.pushTrackLlaNed(0, Lla(RADIAN(45.0000), RADIAN(-73.0000), 0), Attitude(RADIAN(-35), RADIAN(5), 0));
  sim.pushTrackLlaNed(4000, Lla(RADIAN(45.0004), RADIAN(-73.0004), 0), Attitude(RADIAN(-35), RADIAN(5), 0));
  sim.pushTrackLlaNed(5000, Lla(RADIAN(45.0005), RADIAN(-73.0005), 0), Attitude(RADIAN(35), RADIAN(5), 0));
  sim.pushTrackLlaNed(9000, Lla(RADIAN(45.0009), RADIAN(-73.0001), 0), Attitude(RADIAN(35), RADIAN(5), 0));
  sim.pushTrackLlaNed(10000, Lla(RADIAN(45.0010), RADIAN(-73.0000), 0), Attitude(RADIAN(-35), RADIAN(-5), 0));
  sim.pushTrackLlaNed(14000, Lla(RADIAN(45.0014), RADIAN(-73.0004), 0), Attitude(RADIAN(-35), RADIAN(-5), 0));
  sim.pushTrackLlaNed(15000, Lla(RADIAN(45.0015), RADIAN(-73.0005), 0), Attitude(RADIAN(35), RADIAN(-5), 0));
  sim.pushTrackLlaNed(19000, Lla(RADIAN(45.0019), RADIAN(-73.0001), 0), Attitude(RADIAN(35), RADIAN(-5), 0));
  sim.pushTrackLlaNed(20000, Lla(RADIAN(45.0020), RADIAN(-73.0000), 0), Attitude(RADIAN(-35), RADIAN(-5), 0));

  int numberOfNodes;
  sim.endTrackDefinition(numberOfNodes);
  std::cout << "==> Track created, number of nodes in Track = " << numberOfNodes << std::endl;

  std::cout << "==> Starting Simulation" << std::endl;
  sim.start();

  std::cout << "==> Stopping Simulation when elapsed time will be 20s" << std::endl;
  sim.stop(20);

  std::cout << "==> Disconnect from Simulator" << std::endl;
  sim.disconnect();
}

void pushRouteNode(RemoteSimulator& sim, double speedKmh, double latDeg, double lonDeg)
{
  // Push Route LLA in radian with speed in m/s
  sim.pushRouteLla(speedKmh / 3.6, Lla(RADIAN(latDeg), RADIAN(lonDeg), 0));
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Vehicle Route creation Example
// This example shows:
// 1- Create a vehicle trajectory from positions and speed limits
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void runExampleCreateRouteCar(const std::string& host, const std::string& targetType, const std::string& X300IP)
{
  std::cout << "=== Create Route Example ===" << std::endl;

  std::cout << "==> Connecting to the simulator" << std::endl;
  RemoteSimulator sim;
  sim.setVerbose(VERBOSE);
  sim.connect(host);

  std::cout << "==> Create New Configuration, discarding current simulator settings" << std::endl;
  sim.call(New::create(true));

  std::cout << "==> Modulation Settings" << std::endl;
  std::string targetId = "MyOutputId";
  SetModulationTargetPtr setModulationTargetCmd = SetModulationTarget::create(targetType, "", X300IP, true, targetId);
  sim.call(setModulationTargetCmd);
  // Select signals to simulate
  sim.call(ChangeModulationTargetSignals::create(0, 12500000, 12500000, "UpperL", "L1CA", -1, false, targetId));

  sim.call(SetVehicleTrajectory::create("Route"));
  sim.beginRouteDefinition();

  pushRouteNode(sim, 50.0, 42.719943, -73.830492);
  pushRouteNode(sim, 50.0, 42.718155, -73.833370);
  pushRouteNode(sim, 60.0, 42.718110, -73.833439);
  pushRouteNode(sim, 60.0, 42.717620, -73.832875);
  pushRouteNode(sim, 60.0, 42.717296, -73.832508);
  pushRouteNode(sim, 60.0, 42.716674, -73.831805);
  pushRouteNode(sim, 60.0, 42.715545, -73.830511);
  pushRouteNode(sim, 60.0, 42.715469, -73.830427);
  pushRouteNode(sim, 60.0, 42.714831, -73.829695);
  pushRouteNode(sim, 60.0, 42.714155, -73.828924);
  pushRouteNode(sim, 60.0, 42.714200, -73.828803);
  pushRouteNode(sim, 80.0, 42.714720, -73.827925);
  pushRouteNode(sim, 80.0, 42.714759, -73.827850);
  pushRouteNode(sim, 80.0, 42.714769, -73.827747);
  pushRouteNode(sim, 80.0, 42.714752, -73.827672);
  pushRouteNode(sim, 80.0, 42.714681, -73.827552);
  pushRouteNode(sim, 80.0, 42.714338, -73.827183);
  pushRouteNode(sim, 80.0, 42.713316, -73.826026);
  pushRouteNode(sim, 60.0, 42.713257, -73.825929);
  pushRouteNode(sim, 60.0, 42.713235, -73.825804);
  pushRouteNode(sim, 60.0, 42.713235, -73.825693);
  pushRouteNode(sim, 60.0, 42.713248, -73.825528);
  pushRouteNode(sim, 60.0, 42.713708, -73.823088);
  pushRouteNode(sim, 40.0, 42.713837, -73.823108);
  pushRouteNode(sim, 40.0, 42.713902, -73.823097);
  pushRouteNode(sim, 40.0, 42.713979, -73.823028);
  pushRouteNode(sim, 40.0, 42.714546, -73.822143);

  int numberOfNodes;
  sim.endRouteDefinition(numberOfNodes);
  std::cout << "==> Route created, number of nodes in Route = " << numberOfNodes << std::endl;

  std::cout << "==> Starting Simulation" << std::endl;
  sim.start();

  std::cout << "==> Stopping Simulation when elapsed time will be 60s" << std::endl;
  sim.stop(60);

  std::cout << "==> Disconnect from Simulator" << std::endl;
  sim.disconnect();
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Hardware-In-The-Loop (HIL) Example
// This example shows:
// 1- How to push simulated positions during the simulation
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void runExampleHilRealtime(const std::string& host, const std::string& targetType, const std::string& X300IP, bool autoAttitude)
{
  static const long long HIL_DURATION = 60000;
  static const double HIL_SPEED = 10;

  std::cout << std::endl << "=== HIL Example ===" << std::endl;

  std::cout << "==> Connecting to the simulator" << std::endl;
  RemoteSimulator sim;
  sim.setVerbose(VERBOSE);
  sim.connect(host);

  std::cout << "==> Create New Configuration, discarding current simulator settings" << std::endl;
  sim.call(New::create(true));

  std::cout << "==> Modulation Settings" << std::endl;
  std::string targetId = "MyOutputId";
  SetModulationTargetPtr setModulationTargetCmd = SetModulationTarget::create(targetType, "", X300IP, true, targetId);
  sim.call(setModulationTargetCmd);
  // Select signals to simulate
  sim.call(ChangeModulationTargetSignals::create(0, 12500000, 12500000, "UpperL", "L1CA", -1, false, targetId));

  std::cout << "==> Set to HIL Mode" << std::endl;
  sim.call(SetVehicleTrajectory::create("HIL"));

  std::cout << "==> Starting Simulation" << std::endl;
  sim.start();

  Lla origin(RADIAN(45.0), RADIAN(-74.0), 1.0);

  std::cout << "==> Sending positions in Real-Time, for " << (HIL_DURATION / 1000) << " seconds." << std::endl;
  long long startTime = currentTime();
  while (true)
  {
    // Here we use the PC time as an example. In reality time should come from the position's generator.
    long long elapsedTime = currentTime() - startTime;

    if (elapsedTime > HIL_DURATION)
      break;

    double t = elapsedTime / 1000.0;

    // Vehicule will head North/East
    Enu enu(HIL_SPEED * t, HIL_SPEED * t, 0);
    Lla lla = origin.addEnu(enu);

    if (autoAttitude)
    {
      sim.pushLla(elapsedTime, lla); //vehicle's attitude will be based on its heading
    }
    else
    {
      // You can also push vehicle attitude attached to the node
      sim.pushLlaNed(elapsedTime, lla, Attitude(RADIAN(45), RADIAN(2), 0));
    }

    // You can also push Ecef instead of Lla
    //Ecef ecef;
    //lla.toEcef(ecef);
    //sim.pushEcef(elapsedTime, ecef);

    //Send new position to simulator each 10 ms. This should be controlled by the position's generator.
    std::this_thread::sleep_for(std::chrono::milliseconds(10));
  }
  std::cout << "==> Stop simulation " << std::endl;
  sim.stop();

  sim.disconnect();
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Interferences Example
// This example shows:
// 1- How to add in-band interferences to the simulated signal
// 2- Change the parameters of the interferences during the simulation
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void runExampleInterferences(const std::string& host, const std::string& targetType, const std::string& X300IP)
{
  std::cout << std::endl << "=== Interferences Example ===" << std::endl;

  std::cout << "==> Connecting to the simulator" << std::endl;
  RemoteSimulator sim;
  sim.setVerbose(VERBOSE);
  sim.connect(host);

  std::cout << "==> Create New Configuration, discarding current simulator settings" << std::endl;
  sim.call(New::create(true));

  std::cout << "==> Modulation Settings" << std::endl;
  std::string targetId = "MyOutputId";
  SetModulationTargetPtr setModulationTargetCmd = SetModulationTarget::create(targetType, "", X300IP, true, targetId);
  sim.call(setModulationTargetCmd);
  // Select signals to simulate
  sim.call(ChangeModulationTargetSignals::create(0, 12500000, 12500000, "UpperL", "L1CA", -1, false, targetId));

  // Interference 1:
  // Basic Example: create a CW interference at 1.5751GHz, that will stay enabled for the whole simulation.
  std::string interferenceId1 = "CW Interference 1";
  sim.call(SetInterferenceCW::create(0, 0, 1575100000, -20, true, interferenceId1));

  // Interference 2:
  // Create a CW interference at 1.5752GHz
  std::string interferenceId2 = "CW Interference 2";
  sim.call(SetInterferenceCW::create(0, 0, 1575200000, -20, true, interferenceId2));
  // Update "CW Interference 2":
  // By using the same "InterferenceId", the simulators knows we want to update an interference.
  // We now set it to run between simulation time 2s and 5s (StartTime:2, EndTime:5)
  sim.call(SetInterferenceCW::create(2, 5, 1575200000, -20, true, interferenceId2));

  // Interference 3:
  // Create a CW Interference at 1.5753GHz
  // This time, we don't give an interferenceId.
  // The simulator will create an Id for us.
  // We will retreive the Id with the result of the call to the simulator
  SetInterferenceCWPtr cmd = SetInterferenceCW::create(0, 0, 1575300000, -20, true, "");
  CommandResultPtr result = sim.call(cmd);
  // Using the result, we can retreive the command that produced this result
  cmd = SetInterferenceCW::dynamicCast(result->relatedCommand());
  // The retreived command is a SetInterferenceCW command. It was updated by the simulator with a unique InterferenceId.
  // We can update this command to change the interference, and resend it to the simulator.
  // For example, we can disable this interference.
  cmd->setEnabled(false);
  sim.call(cmd);

  // Interference 4:
  // Create a CW Interference at 1.5754GHz
  // We will program updates to change periodically the power of this interference
  SetInterferenceCWPtr cmdInterference4 = SetInterferenceCW::create(0, 0, 1575400000, 0, true, "");
  cmdInterference4 = SetInterferenceCW::dynamicCast(sim.call(cmdInterference4)->relatedCommand());

  std::cout << "==> Starting Simulation" << std::endl;
  sim.start();

  sim.setVerbose(false);
  // Asynchronous command examples
  // Gradually increase cw interference power from 0 to 10 dB for 10 secs and
  // gradually decrease cw interference power from 10 to 0 dB for 20 secs after 10 secs of simulation
  for (int x = 0; x <= 100; ++x)
  {
    double power = x / 10.0;
    double timeStamp = x / 10.0;
    cmdInterference4->setPower(power);
    sim.post(cmdInterference4, timeStamp);

    cmdInterference4->setPower(10.0 - power);
    sim.post(cmdInterference4, 10.0 + timeStamp);
  }
  sim.setVerbose(VERBOSE);

  std::cout << "==> Stopping Simulation when elapsed time will be 30s" << std::endl;
  sim.stop(30);
  sim.disconnect();
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Vehicle Pause/Resume Example
// This example shows:
// 1- How to Pause and Resume the vehicle's motion during the simulation (GNSS signals are not paused)
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void runExamplePauseResume(const std::string& host, const std::string& targetType, const std::string& X300IP)
{
  std::cout << std::endl << "=== Simulation Pause/Resume Example ===" << std::endl;
  std::cout << "==> Connecting to the simulator" << std::endl;
  RemoteSimulator sim;
  CommandResultPtr result;
  sim.setVerbose(VERBOSE);
  sim.connect(host);

  std::cout << "==> Create New Configuration, discarding current simulator settings" << std::endl;
  sim.call(New::create(true));

  std::cout << "==> Modulation Settings" << std::endl;
  std::string targetId = "MyOutputId";
  SetModulationTargetPtr setModulationTargetCmd = SetModulationTarget::create(targetType, "", X300IP, true, targetId);
  sim.call(setModulationTargetCmd);
  // Select signals to simulate
  sim.call(ChangeModulationTargetSignals::create(0, 12500000, 12500000, "UpperL", "L1CA", -1, false, targetId));

  sim.call(SetVehicleTrajectory::create("Track"));
  sim.call(SetVehicleType::create("Ground / Water"));

  result = sim.beginTrackDefinition();
  Lla llaPos(RADIAN(37.78737073), RADIAN(-122.38205756), 0);
  long long time = 0;
  for (uint32_t i = 0; i < 60000; i++)
  {
    sim.pushTrackLla(time, llaPos);
    llaPos.lon += 0.00000001;
    time += 1;
  }
  int numberOfNodes = 0;
  result = sim.endTrackDefinition(numberOfNodes);
  std::cout << "RESULT (endTrackDefinition): " << result->message() << "; Number of nodes: " << numberOfNodes << std::endl;

  std::cout << "==> Starting Simulation" << std::endl;
  sim.start();

  std::cout << "==> Pausing vehicle motion after 10s" << std::endl;
  sim.call(Pause::create(), 10);
  std::cout << "==> Resuming vehicle motion after 30s" << std::endl;
  sim.call(Resume::create(), 30);

  std::cout << "==> Stopping Simulation when elapsed time will be 40s" << std::endl;
  sim.stop(40);

  sim.disconnect();
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Automatic simulation stop at trajectory end example
// This example shows:
// 1- Create a simple vehicle route and simulate it until the vehicle has reached destination
// 2- Create a simple vehicle track and simulate it until the vehicle has reached destination
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void runExampleAutomaticStop(const std::string& host, const std::string& targetType, const std::string& X300IP)
{
  std::cout << std::endl << "=== Automatic Stop Example ===" << std::endl;

  std::cout << "==> Connecting to the simulator" << std::endl;
  RemoteSimulator sim;
  sim.setVerbose(VERBOSE);
  sim.connect(host);

  std::cout << "==> Create New Configuration, discarding current simulator settings" << std::endl;
  sim.call(New::create(true));

  std::cout << "==> Modulation Settings" << std::endl;
  std::string targetId = "MyOutputId";
  SetModulationTargetPtr setModulationTargetCmd = SetModulationTarget::create(targetType, "", X300IP, true, targetId);
  sim.call(setModulationTargetCmd);
  // Select signals to simulate
  sim.call(ChangeModulationTargetSignals::create(0, 12500000, 12500000, "UpperL", "L1CA", -1, false, targetId));

  //When enabled, the simulation will stop when the vehicle will reach its trajectory destination
  std::cout << "==> Enable simulation automatic stop at trajectory end" << std::endl;
  sim.call(EnableSimulationStopAtTrajectoryEnd::create(true));

  int numberOfNodes;

  sim.call(SetVehicleTrajectory::create("Route"));
  sim.beginRouteDefinition();
  pushRouteNode(sim, 50.0, 42.719943, -73.830492);
  pushRouteNode(sim, 60.0, 42.718110, -73.833439);
  pushRouteNode(sim, 60.0, 42.717620, -73.832875);
  sim.endRouteDefinition(numberOfNodes);
  std::cout << "==> Route created, number of nodes in Route = " << numberOfNodes << std::endl;

  std::cout << "==> Starting Simulation" << std::endl;
  sim.start();

  std::cout << "==> Wait until the automatic stop happens when vehicle reaches route destination" << std::endl;
  sim.waitState("Ready");

  sim.call(SetVehicleTrajectory::create("Track"));
  sim.beginTrackDefinition();
  sim.pushTrackLla(0, Lla(RADIAN(42.719943), RADIAN(-73.830492), 0));
  sim.pushTrackLla(40000, Lla(RADIAN(42.718110), RADIAN(-73.833439), 0));
  sim.pushTrackLla(45000, Lla(RADIAN(42.717620), RADIAN(-73.832875), 0));
  sim.endTrackDefinition(numberOfNodes);
  std::cout << "==> Track created, number of nodes in Track = " << numberOfNodes << std::endl;

  std::cout << "==> Starting Simulation" << std::endl;
  sim.start();

  std::cout << "==> Wait until the automatic stop happens when vehicle reaches track destination" << std::endl;
  sim.waitState("Ready");

  std::cout << "==> Disconnect from Simulator" << std::endl;
  sim.disconnect();
}

void runExampleGetPower(const std::string & host, const std::string & targetType, const std::string & X300IP)
{
  std::cout << std::endl << "=== Get Power Example ===" << std::endl;

  std::cout << "==> Connecting to the simulator" << std::endl;
  RemoteSimulator sim;
  sim.setVerbose(VERBOSE);
  sim.connect(host);

  std::cout << "==> Create New Configuration, discarding current simulator settings" << std::endl;
  sim.call(New::create(true));

  std::cout << "==> Modulation Settings" << std::endl;
  std::string targetId = "MyOutputId";
  SetModulationTargetPtr setModulationTargetCmd = SetModulationTarget::create(targetType, "", X300IP, true, targetId);
  sim.call(setModulationTargetCmd);
  // Select signals to simulate
  sim.call(ChangeModulationTargetSignals::create(0, 12500000, 12500000, "UpperL", "L1CA", -1, false, targetId));

  std::cout << "==> Arming Simulation" << std::endl;
  sim.arm();

  GetVisibleSVResultPtr visbiles = GetVisibleSVResult::dynamicCast(sim.call(GetVisibleSV::create("GPS")));
  std::vector<int> svIds = visbiles->svId();

  for (int i = 0; i < static_cast<int>(svIds.size()); ++i)
  {
    GetPowerForSVResultPtr power = GetPowerForSVResult::dynamicCast(sim.call(GetPowerForSV::create("GPS", svIds[i])));

    std::cout << "SV ID " << svIds[i] << " received power: " << power->total() << " dBm" << std::endl;
  }

  std::cout << "==> Stopping Simulation" << std::endl;
  sim.stop();

  std::cout << "==> Disconnect from Simulator" << std::endl;
  sim.disconnect();
}
