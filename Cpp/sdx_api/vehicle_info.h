#ifndef SIM_STATS
#define SIM_STATS

#include "ecef.h"
#include "attitude.h"
#include <cstdint>

namespace Sdx
{

struct VehicleInfo
{
  uint64_t elapsedTime; //ms
  Ecef ecef;
  Attitude attitude;
  double speed; //km/h
  double heading; //rad
  double odometer; //meters since start
};

}//namespace Bb

#endif // SIM_STATS

