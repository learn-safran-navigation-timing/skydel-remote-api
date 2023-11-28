#ifndef HIL_CLIENT_H
#define HIL_CLIENT_H

#include <cstdint>
#include <memory>
#include <string>
#include <utility>

namespace Sdx
{

enum HilMessageId
{
  HilMsgId_Hello = 1,
  HilMsgId_Bye = 2,
  HilMsgId_VehicleInfo = 3,
  HilMsgId_PushEcef = 5,
  HilMsgId_PushEcefNed = 6,
  HilMsgId_PushEcefDynamics = 7,
  HilMsgId_PushEcefNedDynamics = 8
};

enum class HilDynamics
{
  Velocity = 0,
  Acceleration = 1,
  Jerk = 2
};

struct HilMessageEcef
{
  double time;
  double x;
  double y;
  double z;
};

struct HilMessageEcefNed
{
  double time;
  double x;
  double y;
  double z;
  double yaw;
  double pitch;
  double roll;
};

class Ecef;
class Attitude;
struct VehicleInfo;
class HilClient
{
public:
  HilClient(bool exceptionOnError = true);
  virtual ~HilClient(void);

  bool hasError() const; // returns 0 if there are no errors
  void clearError();

  bool connectToHost(const std::string& ip, int port);
  bool isConnected() const;

  bool isVerbose() const;
  void setVerbose(bool verbose);

  // Send Skydel a timed position of the vehicle. The position is provided in the ECEF coordinate system.
  //
  //  Parameter     Type      Units          Description
  //  --------------------------------------------------------------------------------------
  //  elapsedTime             milliseconds   Time since the beginning of the simulation.
  //  position      x, y, z   m              Position of the vehicle.
  //  name                                   If empty, sends the position for the vehicle. If set with a jammerID, sends
  //                                         the position for the specified jammer's vehicle.
  //
  virtual bool pushEcef(double elapsedTime, const Ecef& position, const std::string& name = "");

  // Send Skydel a timed position and the associated dynamics of the vehicle. The position is provided in the ECEF
  // coordinate system.
  //
  //  Parameter     Type      Units          Description
  //  --------------------------------------------------------------------------------------
  //  elapsedTime             milliseconds   Time since the beginning of the simulation.
  //  position      x, y, z   m              Position of the vehicle.
  //  velocity      x, y, z   m/s            Velocity of the vehicle.
  //  name                                   If empty, sends the position for the vehicle. If set with a jammerID, sends
  //                                         the position for the specified jammer's vehicle.
  //
  virtual bool pushEcef(double elapsedTime, const Ecef& position, const Ecef& velocity, const std::string& name = "");

  // Send Skydel a timed position and the associated dynamics of the vehicle. The position is provided in the ECEF
  // coordinate system.
  //
  //  Parameter      Type      Units          Description
  //  ---------------------------------------------------------------------------------------
  //  elapsedTime              milliseconds   Time since the beginning of the simulation.
  //  position       x, y, z   m              Position of the vehicle.
  //  velocity       x, y, z   m/s            Velocity of the vehicle.
  //  acceleration   x, y, z   m/s²           Acceleration of the vehicle.
  //  name                                    If empty, sends the position for the vehicle. If set with a jammerID,
  //                                          sends the position for the specified jammer's vehicle.
  //
  virtual bool pushEcef(double elapsedTime,
                        const Ecef& position,
                        const Ecef& velocity,
                        const Ecef& acceleration,
                        const std::string& name = "");

  // Send Skydel a timed position and the associated dynamics of the vehicle. The position is provided in the ECEF
  // coordinate system.
  //
  //  Parameter      Type      Units          Description
  //  ---------------------------------------------------------------------------------------
  //  elapsedTime              milliseconds   Time since the beginning of the simulation.
  //  position       x, y, z   m              Position of the vehicle.
  //  velocity       x, y, z   m/s            Velocity of the vehicle.
  //  acceleration   x, y, z   m/s²           Acceleration of the vehicle.
  //  jerk           x, y, z   m/s³           Jerk of the vehicle.
  //  name                                    If empty, sends the position for the vehicle. If set with a jammerID,
  //                                          sends the position for the specified jammer's vehicle.
  //
  virtual bool pushEcef(double elapsedTime,
                        const Ecef& position,
                        const Ecef& velocity,
                        const Ecef& acceleration,
                        const Ecef& jerk,
                        const std::string& name = "");

  // Send Skydel a timed position and orientation of the vehicle. The position is provided in the ECEF coordinate
  // system, while the body's orientation is specified relative to the local NED reference frame.
  //
  //  Parameter     Type               Units          Description
  //  -----------------------------------------------------------------------------------------------
  //  elapsedTime                      milliseconds   Time since the beginning of the simulation.
  //  position      x, y, z            m              Position of the vehicle.
  //  attitude      yaw, pitch, roll   rad            Orientation of the vehicle's body.
  //  name                                            If empty, sends the position for the vehicle. If set with a
  //                                                  jammerID, sends the position for the specified jammer's vehicle.
  //
  virtual bool pushEcefNed(double elapsedTime,
                           const Ecef& position,
                           const Attitude& attitude,
                           const std::string& name = "");

  // Send Skydel a timed position, orientation, and the associated dynamics of the vehicle. The position is provided in
  // the ECEF coordinate system, while the body's orientation is specified relative to the local NED reference frame.
  //
  //  Parameter         Type               Units          Description
  //  ---------------------------------------------------------------------------------------------------
  //  elapsedTime                          milliseconds   Time since the beginning of the simulation.
  //  position          x, y, z            m              Position of the vehicle.
  //  attitude          yaw, pitch, roll   rad            Orientation of the vehicle's body.
  //  velocity          x, y, z            m/s            Velocity of the vehicle.
  //  angularVelocity   yaw, pitch, roll   rad/s          Rotational velocity of the vehicle's body.
  //  name                                                If empty, sends the position for the vehicle. If set with a
  //                                                      jammerID, sends the position for the specified jammer's
  //                                                      vehicle.
  //
  virtual bool pushEcefNed(double elapsedTime,
                           const Ecef& position,
                           const Attitude& attitude,
                           const Ecef& velocity,
                           const Attitude& angularVelocity,
                           const std::string& name = "");

  // Send Skydel a timed position, orientation, and the associated dynamics of the vehicle. The position is provided in
  // the ECEF coordinate system, while the body's orientation is specified relative to the local NED reference frame.
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
  virtual bool pushEcefNed(double elapsedTime,
                           const Ecef& position,
                           const Attitude& attitude,
                           const Ecef& velocity,
                           const Attitude& angularVelocity,
                           const Ecef& acceleration,
                           const Attitude& angularAcceleration,
                           const std::string& name = "");

  // Send Skydel a timed position, orientation, and the associated dynamics of the vehicle. The position is provided in
  // the ECEF coordinate system, while the body's orientation is specified relative to the local NED reference frame.
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
  virtual bool pushEcefNed(double elapsedTime,
                           const Ecef& position,
                           const Attitude& attitude,
                           const Ecef& velocity,
                           const Attitude& angularVelocity,
                           const Ecef& acceleration,
                           const Attitude& angularAcceleration,
                           const Ecef& jerk,
                           const Attitude& angularJerk,
                           const std::string& name = "");

  void disconnect();

  bool hasRecvVehicleInfo(int timeout, bool errorAtTimeout = true);
  bool recvLastVehicleInfo(VehicleInfo& vehicleInfo);
  bool recvNextVehicleInfo(VehicleInfo& vehicleInfo);
  void clearVehicleInfo();

private:
  struct Pimpl;
  Pimpl* m;

  bool recvVehicleInfo(VehicleInfo& vehicleInfo);
  void errorMessage(const std::string& msg);
  bool receiveMessage();
  bool sendMessage(const char* message, int length);
};

} // namespace Sdx

#endif // HIL_CLIENT_H
