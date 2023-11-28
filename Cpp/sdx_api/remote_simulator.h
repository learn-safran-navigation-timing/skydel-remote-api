#ifndef REMOTE_SIMULATOR_H__
#define REMOTE_SIMULATOR_H__

#include <queue>

#include <set>

#include "command_result.h"

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
  void pushTrackEcef(int elapsedTime, const Ecef& ecef);
  void pushTrackEcefNed(int elapsedTime, const Ecef& ecef, const Attitude& attitude);
  void pushTrackLla(int elapsedTime, const Lla& lla);
  void pushTrackLlaNed(int elapsedTime, const Lla& lla, const Attitude& attitude);
  CommandResultPtr endTrackDefinition(int& numberOfNodesInTrack);

  CommandResultPtr beginRouteDefinition();
  void pushRouteEcef(double speed, const Ecef& ecef);
  void pushRouteLla(double speed, const Lla& lla);
  CommandResultPtr endRouteDefinition(int& numberOfNodesInRoute);

  CommandResultPtr beginIntTxTrackDefinition(const std::string& id);
  void pushIntTxTrackEcef(int elapsedTime, const Ecef& ecef, const std::string& id);
  void pushIntTxTrackEcefNed(int elapsedTime, const Ecef& ecef, const Attitude& attitude, const std::string& id);
  void pushIntTxTrackLla(int elapsedTime, const Lla& lla, const std::string& id);
  void pushIntTxTrackLlaNed(int elapsedTime, const Lla& lla, const Attitude& attitude, const std::string& id);
  CommandResultPtr endIntTxTrackDefinition(int& numberOfNodesInTrack, const std::string& id);

  // Send Skydel an HIL timed position of the vehicle. The position is provided in the ECEF coordinate system.
  //
  //  Parameter     Type      Units          Description
  //  -----------------------------------------------------------------------------------------------
  //  elapsedTime             milliseconds   Time since the beginning of the simulation.
  //  position      x, y, z   m              Position of the vehicle.
  //  name                                   If empty, sends the position for the vehicle. If set with a jammerID, sends
  //                                         the position for the specified jammer's vehicle.
  //
  bool pushEcef(double elapsedTime, const Ecef& position, const std::string& name = "");

  // Send Skydel an HIL timed position and the associated dynamics of the vehicle. The position is provided in the ECEF
  // coordinate system.
  //
  //  Parameter     Type      Units          Description
  //  -----------------------------------------------------------------------------------------------
  //  elapsedTime             milliseconds   Time since the beginning of the simulation.
  //  position      x, y, z   m              Position of the vehicle.
  //  velocity      x, y, z   m/s            Velocity of the vehicle.
  //  name                                   If empty, sends the position for the vehicle. If set with a jammerID, sends
  //                                         the position for the specified jammer's vehicle.
  //
  bool pushEcef(double elapsedTime, const Ecef& position, const Ecef& velocity, const std::string& name = "");

  // Send Skydel an HIL timed position and the associated dynamics of the vehicle. The position is provided in the ECEF
  // coordinate system.
  //
  //  Parameter      Type      Units          Description
  //  ------------------------------------------------------------------------------------------------
  //  elapsedTime              milliseconds   Time since the beginning of the simulation.
  //  position       x, y, z   m              Position of the vehicle.
  //  velocity       x, y, z   m/s            Velocity of the vehicle.
  //  acceleration   x, y, z   m/s²           Acceleration of the vehicle.
  //  name                                    If empty, sends the position for the vehicle. If set with a jammerID,
  //                                          sends the position for the specified jammer's vehicle.
  //
  bool pushEcef(double elapsedTime,
                const Ecef& position,
                const Ecef& velocity,
                const Ecef& acceleration,
                const std::string& name = "");

  // Send Skydel an HIL timed position and the associated dynamics of the vehicle. The position is provided in the ECEF
  // coordinate system.
  //
  //  Parameter      Type      Units          Description
  //  ------------------------------------------------------------------------------------------------
  //  elapsedTime              milliseconds   Time since the beginning of the simulation.
  //  position       x, y, z   m              Position of the vehicle.
  //  velocity       x, y, z   m/s            Velocity of the vehicle.
  //  acceleration   x, y, z   m/s²           Acceleration of the vehicle.
  //  jerk           x, y, z   m/s³           Jerk of the vehicle.
  //  name                                    If empty, sends the position for the vehicle. If set with a jammerID,
  //                                          sends the position for the specified jammer's vehicle.
  //
  bool pushEcef(double elapsedTime,
                const Ecef& position,
                const Ecef& velocity,
                const Ecef& acceleration,
                const Ecef& jerk,
                const std::string& name = "");

  // Send Skydel an HIL timed position and orientation of the vehicle. The position is provided in the LLA coordinate
  // system, while the body's orientation is specified relative to the local NED reference frame.
  //
  //  Parameter     Type               Units          Description
  //  -----------------------------------------------------------------------------------------------
  //  elapsedTime                      milliseconds   Time since the beginning of the simulation.
  //  position      lat, long, alt     rad and m      Position of the vehicle.
  //  attitude      yaw, pitch, roll   rad            Orientation of the vehicle's body.
  //  name                                            If empty, sends the position for the vehicle. If set with a
  //                                                  jammerID, sends the position for the specified jammer's vehicle.
  //
  bool pushEcefNed(double elapsedTime, const Ecef& position, const Attitude& attitude, const std::string& name = "");

  // Send Skydel an HIL timed position, orientation, and the associated dynamics of the vehicle. The position is
  // provided in the ECEF coordinate system, while the body's orientation is specified relative to the local NED
  // reference frame.
  //
  //  Parameter             Type               Units          Description
  //  -------------------------------------------------------------------------------------------------------
  //  elapsedTime                              milliseconds   Time since the beginning of the simulation.
  //  position              x, y, z            m              Position of the vehicle.
  //  attitude              yaw, pitch, roll   rad            Orientation of the vehicle's body.
  //  velocity              x, y, z            m/s            Velocity of the vehicle.
  //  angularVelocity       yaw, pitch, roll   rad/s          Rotational velocity of the vehicle's body.
  //  name                                                    If empty, sends the position for the vehicle. If set with
  //                                                          a jammerID, sends the position for the specified jammer's
  //                                                          vehicle.
  //
  bool pushEcefNed(double elapsedTime,
                   const Ecef& position,
                   const Attitude& attitude,
                   const Ecef& velocity,
                   const Attitude& angularVelocity,
                   const std::string& name = "");

  // Send Skydel an HIL timed position, orientation, and the associated dynamics of the vehicle. The position is
  // provided in the ECEF coordinate system, while the body's orientation is specified relative to the local NED
  // reference frame.
  //
  //  Parameter             Type               Units          Description
  //  -------------------------------------------------------------------------------------------------------
  //  elapsedTime                              milliseconds   Time since the beginning of the simulation.
  //  position              x, y, z            m              Position of the vehicle.
  //  attitude              yaw, pitch, roll   rad            Orientation of the vehicle's body.
  //  velocity              x, y, z            m/s            Velocity of the vehicle.
  //  angularVelocity       yaw, pitch, roll   rad/s          Rotational velocity of the vehicle's body.
  //  acceleration          x, y, z            m/s²           Acceleration of the vehicle.
  //  angularAcceleration   yaw, pitch, roll   rad/s²         Rotational acceleration of the vehicle's body.
  //  name                                                    If empty, sends the position for the vehicle. If set with
  //                                                          a jammerID, sends the position for the specified jammer's
  //                                                          vehicle.
  //
  bool pushEcefNed(double elapsedTime,
                   const Ecef& position,
                   const Attitude& attitude,
                   const Ecef& velocity,
                   const Attitude& angularVelocity,
                   const Ecef& acceleration,
                   const Attitude& angularAcceleration,
                   const std::string& name = "");

  // Send Skydel an HIL timed position, orientation, and the associated dynamics of the vehicle. The position is
  // provided in the ECEF coordinate system, while the body's orientation is specified relative to the local NED
  // reference frame.
  //
  //  Parameter             Type               Units          Description
  //  -------------------------------------------------------------------------------------------------------
  //  elapsedTime                              milliseconds   Time since the beginning of the simulation.
  //  position              x, y, z            m              Position of the vehicle.
  //  attitude              yaw, pitch, roll   rad            Orientation of the vehicle's body.
  //  velocity              x, y, z            m/s            Velocity of the vehicle.
  //  angularVelocity       yaw, pitch, roll   rad/s          Rotational velocity of the vehicle's body.
  //  acceleration          x, y, z            m/s²           Acceleration of the vehicle.
  //  angularAcceleration   yaw, pitch, roll   rad/s²         Rotational acceleration of the vehicle's body.
  //  jerk                  x, y, z            m/s³           Jerk of the vehicle.
  //  angularJerk           yaw, pitch, roll   rad/s³         Rotational jerk of the vehicle's body.
  //  name                                                    If empty, sends the position for the vehicle. If set with
  //                                                          a jammerID, sends the position for the specified jammer's
  //                                                          vehicle.
  //
  bool pushEcefNed(double elapsedTime,
                   const Ecef& position,
                   const Attitude& attitude,
                   const Ecef& velocity,
                   const Attitude& angularVelocity,
                   const Ecef& acceleration,
                   const Attitude& angularAcceleration,
                   const Ecef& jerk,
                   const Attitude& angularJerk,
                   const std::string& name = "");

  // Send Skydel an HIL timed position of the vehicle. The position is provided in the LLA coordinate system.
  //
  //  Parameter     Type               Units          Description
  //  -----------------------------------------------------------------------------------------------
  //  elapsedTime                      milliseconds   Time since the beginning of the simulation.
  //  position      lat, long, alt     rad and m      Position of the vehicle.
  //  name                                            If empty, sends the position for the vehicle. If set with a
  //                                                  jammerID, sends the position for the specified jammer's vehicle.
  //
  bool pushLla(double elapsedTime, const Lla& lla, const std::string& name = "");

  // Send Skydel an HIL timed position and orientation of the vehicle. The position is provided in the LLA coordinate
  // system, while the body's orientation is specified relative to the local NED reference frame.
  //
  //  Parameter     Type               Units          Description
  //  -----------------------------------------------------------------------------------------------
  //  elapsedTime                      milliseconds   Time since the beginning of the simulation.
  //  position      lat, long, alt     rad and m      Position of the vehicle.
  //  attitude      yaw, pitch, roll   rad            Orientation of the vehicle's body.
  //  name                                            If empty, sends the position for the vehicle. If set with a
  //                                                  jammerID, sends the position for the specified jammer's vehicle.
  //
  bool pushLlaNed(double elapsedTime, const Lla& lla, const Attitude& attitude, const std::string& name = "");

  CommandResultPtr beginVehicleInfo();
  CommandResultPtr endVehicleInfo();

  /// Return next pending vehicle info,
  /// Will wait if no vehicleInfo (timeout 200 ms)
  bool nextVehicleInfo(VehicleInfo& vehicleInfo);

  /// Flushes pending vehicle infos and returns last one,
  /// Will wait if no vehicleInfo (timeout 200 ms)
  bool lastVehicleInfo(VehicleInfo& vehicleInfo);

  bool hasVehicleInfo();

  bool checkIfStreaming();

  bool waitState(const std::string& state, const std::string& failureState = "");

  enum DeprecatedMessageMode
  {
    ALL,
    LATCH,
    NONE
  };
  void setDeprecatedMessageMode(DeprecatedMessageMode mode);

private:
  CommandBasePtr postCommand(CommandBasePtr cmd, double timestamp);
  CommandBasePtr postCommand(CommandBasePtr cmd);

  CommandResultPtr waitCommand(CommandBasePtr cmd);

  CommandResultPtr callCommand(CommandBasePtr cmd, double timestamp);
  CommandResultPtr callCommand(CommandBasePtr cmd);

  void resetTime();
  void checkForbiddenPost(CommandBasePtr cmd);
  void checkForbiddenCall(CommandBasePtr cmd);
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

  std::set<std::string> m_beginIntTxTrack;
  std::set<std::string> m_latchDeprecated;
  DeprecatedMessageMode m_deprecatedMessageMode {DeprecatedMessageMode::LATCH};

  int m_serverApiVersion;
};
} // namespace Sdx

#endif // REMOTE_SIMULATOR_H__
