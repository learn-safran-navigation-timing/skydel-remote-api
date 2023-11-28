#include "lla.h"

#include "enu.h"
#define _USE_MATH_DEFINES
#include <math.h>

#include "ecef.h"
#include "gps_constants.h"

namespace Sdx
{

Lla::Lla() : lat(0), lon(0), alt(0)
{
}

Lla::Lla(double _lat, double _lon, double _alt) : lat(_lat), lon(_lon), alt(_alt)
{
}

void Lla::toEcef(Ecef& ecef) const
{
  double cos_lat = cos(lat);
  double tmp = (1 - GPS::EFLAT) * (1 - GPS::EFLAT);
  double ex2 = (2 - GPS::EFLAT) * GPS::EFLAT / tmp;
  double c = GPS::ESMAJ * sqrt(1 + ex2);
  double n = c / sqrt(1 + ex2 * cos_lat * cos_lat);
  ecef.x = (n + alt) * cos_lat * cos(lon);
  ecef.y = (n + alt) * cos_lat * sin(lon);
  ecef.z = (tmp * n + alt) * sin(lat);
}

void Lla::toEnu(const Lla& origin, Enu& enu) const
{
  enu.e = (lon - origin.lon) * GPS::ESMAJ * cos(lat);
  enu.n = (lat - origin.lat) * GPS::ESMAJ;
  enu.u = alt - origin.alt;
}

Lla Lla::addEnu(const Enu& enu) const
{
  Lla lla;
  enu.toLla(*this, lla);
  return lla;
}

double Lla::latDeg() const
{
  return lat / M_PI * 180;
}

double Lla::lonDeg() const
{
  return lon / M_PI * 180;
}

bool Lla::operator==(const Lla& lla) const
{
  return lat == lla.lat && lon == lla.lon && alt == lla.alt;
}

bool Lla::operator!=(const Lla& lla) const
{
  return !(*this == lla);
}

} // namespace Sdx
