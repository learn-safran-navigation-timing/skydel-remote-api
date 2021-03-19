#include "attitude.h"
#define _USE_MATH_DEFINES
#include <math.h>
#include "gps_constants.h"

namespace Sdx
{

Attitude::Attitude() : yaw(0), pitch(0), roll(0)
{
}

Attitude::Attitude(double _yaw, double _pitch, double _roll) : yaw(_yaw), pitch(_pitch), roll(_roll)
{
}

double Attitude::yawDeg() const
{
  return yaw / M_PI * 180;
}

double Attitude::pitchDeg() const
{
  return pitch / M_PI * 180;
}

double Attitude::rollDeg() const
{
  return roll / M_PI * 180;
}

bool Attitude::operator==(const Attitude &other) const
{
  return yaw == other.yaw && pitch == other.pitch && roll == other.roll;
}

bool Attitude::operator!=(const Attitude &other) const
{
  return !(*this == other);
}

}//namespace Sdx
