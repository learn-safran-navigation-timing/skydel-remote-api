#include "enu.h"

#include <math.h>

#include "ecef.h"
#include "gps_constants.h"
#include "lla.h"

namespace Sdx
{

Enu::Enu() : e(0), n(0), u(0)
{
}

Enu::Enu(double _e, double _n, double _u) : e(_e), n(_n), u(_u)
{
}

void Enu::toEcef(const Lla& origin, Ecef& ecef) const
{
  Ecef originEcef;
  origin.toEcef(originEcef);

  double sinLon = sin(origin.lon);
  double cosLon = cos(origin.lon);
  double sinLat = sin(origin.lat);
  double cosLat = cos(origin.lat);

  ecef = Ecef(-sinLon * e - sinLat * cosLon * n + cosLat * cosLon * u + originEcef.x,
              cosLon * e - sinLat * sinLon * n + cosLat * sinLon * u + originEcef.y,
              cosLat * n + sinLat * u + originEcef.z);
}

void Enu::toLla(const Lla& origin, Lla& lla) const
{
  Ecef ecef;
  toEcef(origin, ecef);
  ecef.toLla(lla);
}

bool Enu::operator==(const Enu& other) const
{
  return e == other.e && n == other.n && u == other.u;
}

bool Enu::operator!=(const Enu& other) const
{
  return !(*this == other);
}

} // namespace Sdx
