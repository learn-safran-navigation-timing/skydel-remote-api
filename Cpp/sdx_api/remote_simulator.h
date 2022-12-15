#ifndef REMOTE_SIMULATOR_H__
#define REMOTE_SIMULATOR_H__

#include "command_result.h"
#include <queue>
#include <set>

namespace Sdx
{
class CmdClient;
class HilClient;
class Ecef;
class Lla;
class Attitude;
struct VehicleInfo;

int spooferInstance(int id);

class RemoteSimulator
{
public:
  RemoteSimulator(bool exceptionOnError = true);
  ~RemoteSimulator();

  bool connect(const std::string& ip = "localhost", int id = 0, bool failIfApiVersionMismatch = false);
  void disconnect();
  bool isConnected() const;

  static int clientApiVersion();
  int serverApiVersion() const;

  void setVerbose(bool verbose);
  bool isVerbose() const;

  void setHilStreamingCheckEnabled(bool hilStreamingCheckEnabled);
  bool isHilStreamingCheckEnabled();

  bool arm();
  bool start();
  void stop(double timestamp);
  void stop();

  CommandBasePtr post(CommandBasePtr cmd, double timestamp);
  CommandBasePtr post(CommandBasePtr cmd);

  CommandResultPtr wait(CommandBasePtr cmd);

  CommandResultPtr call(CommandBasePtr cmd, double timestamp);
  CommandResultPtr call(CommandBasePtr cmd);

  CommandResultPtr beginTrackDefinition();
  void pushTrackEcef(long long elapsedTime, const Ecef& ecef);
  void pushTrackEcefNed(long long elapsedTime, const Ecef& ecef, const Attitude& attitude);
  void pushTrackLla(long long elapsedTime, const Lla& lla);
  void pushTrackLlaNed(long long elapsedTime, const Lla& lla, const Attitude& attitude);
  CommandResultPtr endTrackDefinition(int& numberOfNodesInTrack);

  CommandResultPtr beginRouteDefinition();
  void pushRouteEcef(double speed, const Ecef& ecef);
  void pushRouteLla(double speed, const Lla& lla);
  CommandResultPtr endRouteDefinition(int& numberOfNodesInRoute);

  bool pushEcef(double elapsedTime, const Ecef& position, const std::string& name = "");
  bool pushEcef(double elapsedTime, const Ecef& position, const Ecef& velocity, const std::string& name = "");
  bool pushEcef(double elapsedTime, const Ecef& position, const Ecef& velocity, const Ecef& acceleration, const std::string& name = "");
  bool pushEcef(double elapsedTime, const Ecef& position, const Ecef& velocity, const Ecef& acceleration, const Ecef& jerk, const std::string& name = "");

  bool pushEcefNed(double elapsedTime, const Ecef& position, const Attitude& attitude, const std::string& name = "");
  bool pushEcefNed(double elapsedTime, const Ecef& position, const Attitude& attitude, const Ecef& velocity, const Attitude& angularVelocity, const std::string& name = "");
  bool pushEcefNed(double elapsedTime, const Ecef& position, const Attitude& attitude, const Ecef& velocity, const Attitude& angularVelocity, const Ecef& acceleration, const Attitude& angularAcceleration, const std::string& name = "");
  bool pushEcefNed(double elapsedTime, const Ecef& position, const Attitude& attitude, const Ecef& velocity, const Attitude& angularVelocity, const Ecef& acceleration, const Attitude& angularAcceleration, const Ecef& jerk, const  Attitude& angularJerk, const std::string& name = "");

  bool pushLla(double elapsedTime, const Lla& lla, const std::string& name = "");
  bool pushLlaNed(double elapsedTime, const Lla& lla, const Attitude& attitude, const std::string& name = "");

  CommandResultPtr beginVehicleInfo();
  CommandResultPtr endVehicleInfo();

  ///Return next pending vehicle info,
  ///Will wait if no vehicleInfo (timeout 200 ms)
  bool nextVehicleInfo(VehicleInfo& vehicleInfo);

  ///Flushes pending vehicle infos and returns last one,
  ///Will wait if no vehicleInfo (timeout 200 ms)
  bool lastVehicleInfo(VehicleInfo& vehicleInfo);

  bool hasVehicleInfo();

  bool checkIfStreaming();

  bool waitState(const std::string& state, const std::string& failureState = "");

  enum DeprecatedMessageMode {ALL, LATCH, NONE};
  void setDeprecatedMessageMode(DeprecatedMessageMode mode);

private:
  CommandBasePtr postCommand(CommandBasePtr cmd, double timestamp);
  CommandBasePtr postCommand(CommandBasePtr cmd);

  CommandResultPtr waitCommand(CommandBasePtr cmd);

  CommandResultPtr callCommand(CommandBasePtr cmd, double timestamp);
  CommandResultPtr callCommand(CommandBasePtr cmd);

  void resetTime();
  void checkForbidden(CommandBasePtr cmd);
  bool hilCheck(double elapsedTime);
  void handleException(CommandResultPtr result);
  void errorMessage(const std::string& msg);
  void deprecatedMessage(CommandBasePtr cmd);

  bool m_exceptionOnError;
  CmdClient* m_client;
  HilClient* m_hil;
  double m_checkRunningTime;
  bool m_verbose;
  bool m_hilStreamingCheckEnabled;
  bool m_beginTrack;
  bool m_beginRoute;

  std::set<std::string> m_latchDeprecated;
  DeprecatedMessageMode m_deprecatedMessageMode{DeprecatedMessageMode::LATCH};

  int m_serverApiVersion;
};
} //namespace Sdx

#endif //REMOTE_SIMULATOR_H__
