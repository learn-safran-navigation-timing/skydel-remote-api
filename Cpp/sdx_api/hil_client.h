#ifndef HIL_CLIENT_H
#define HIL_CLIENT_H

#include <memory>
#include <string>
#include <cstdint>

namespace Sdx
{

enum HilMessageId
{
  HilMsgId_PushEcef = 0,
  HilMsgId_Hello = 1,
  HilMsgId_Bye = 2,
  HilMsgId_VehicleInfo = 3,
  HilMsgId_PushEcefNed = 4
};

struct HilMessageEcef
{
  int64_t time;
  double  x;
  double  y;
  double  z;
};

struct HilMessageEcefNed
{
  int64_t time;
  double  x;
  double  y;
  double  z;
  double  yaw;
  double  pitch;
  double  roll;
};

class Lla;
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

  virtual bool pushEcef(long long elapsedTime, const Ecef& ecef, const std::string& name = "");
  virtual bool pushEcefNed(long long elapsedTime, const Ecef& ecef, const Attitude& attitude, const std::string& name = "");

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
