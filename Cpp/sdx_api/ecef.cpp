#include "ecef.h"

#include "lla.h"
#define _USE_MATH_DEFINES
#include <math.h>

#include "gps_constants.h"

namespace Sdx
{

Ecef::Ecef() : x(0), y(0), z(0)
{
}

Ecef::Ecef(double _x, double _y, double _z) : x(_x), y(_y), z(_z)
{
}

Ecef::Ecef(const Sdx::Lla& lla)
{
  lla.toEcef(*this);
}

void Ecef::toLla(Sdx::Lla& lla) const
{
  double radius_p;
  double dist_to_z = sqrt(x * x + y * y);
  lla.lat = atan2(z, (1 - GPS::EECC_SQUARED) * dist_to_z);
  for (int i = 1; i <= 5; ++i)
  {
    double sin_lat = sin(lla.lat);
    radius_p = GPS::ESMAJ / sqrt(1.0 - GPS::EECC_SQUARED * sin_lat * sin_lat);
    lla.lat = atan2(z + GPS::EECC_SQUARED * radius_p * sin_lat, dist_to_z);
  }
  lla.lon = atan2(y, x);
  if (lla.latDeg() < -85 || lla.latDeg() > 85) // If we are close to the poles
  {
    double L = z + GPS::EECC_SQUARED * radius_p * sin(lla.lat);
    lla.alt = L / sin(lla.lat) - radius_p;
  }
  else
  {
    lla.alt = dist_to_z / cos(lla.lat) - radius_p;
  }
}

bool Ecef::operator==(const Ecef& other) const
{
  return x == other.x && y == other.y && z == other.z;
}

bool Ecef::operator!=(const Ecef& other) const
{
  return !(*this == other);
}

} // namespace Sdx
