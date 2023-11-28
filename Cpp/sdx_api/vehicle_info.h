#ifndef SIM_STATS
#define SIM_STATS

#include <cstdint>

#include "attitude.h"
#include "ecef.h"

namespace Sdx
{

struct VehicleInfo
{
  uint64_t elapsedTime; // ms
  Ecef ecef;
  Attitude attitude;
  double speed;    // km/h
  double heading;  // rad
  double odometer; // meters since start
};

} // namespace Sdx

#endif // SIM_STATS
