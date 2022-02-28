#ifndef REMOTE_SIMULATOR_H__
#define REMOTE_SIMULATOR_H__

#include "command_result.h"
#include <queue>

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

  bool pushEcef(long long elapsedTime, const Ecef& ecef, const std::string& name = "");
  bool pushEcefNed(long long elapsedTime, const Ecef& ecef, const Attitude& attitude, const std::string& name = "");
  bool pushLla(long long elapsedTime, const Lla& lla, const std::string& name = "");
  bool pushLlaNed(long long elapsedTime, const Lla& lla, const Attitude& attitude, const std::string& name = "");

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

private:
  CommandBasePtr postCommand(CommandBasePtr cmd, double timestamp);
  CommandBasePtr postCommand(CommandBasePtr cmd);

  CommandResultPtr waitCommand(CommandBasePtr cmd);

  CommandResultPtr callCommand(CommandBasePtr cmd, double timestamp);
  CommandResultPtr callCommand(CommandBasePtr cmd);

  void resetTime();
  void checkForbidden(CommandBasePtr cmd);
  bool hilCheck(long long elapsedTime);
  void handleException(CommandResultPtr result);
  void errorMessage(const std::string& msg);

  bool m_exceptionOnError;
  CmdClient* m_client;
  HilClient* m_hil;
  long long m_checkRunningTime;
  bool m_verbose;
  bool m_hilStreamingCheckEnabled;
  bool m_beginTrack;
  bool m_beginRoute;

  int m_serverApiVersion;
};
} //namespace Sdx

#endif //REMOTE_SIMULATOR_H__
