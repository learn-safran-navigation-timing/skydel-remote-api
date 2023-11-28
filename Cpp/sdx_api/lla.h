#ifndef LLA_H
#define LLA_H

namespace Sdx
{
class Ecef;
class Enu;

class Lla
{
public:
  Lla();
  Lla(double lat, double lon, double alt);
  void toEnu(const Lla& origin, Enu& enu) const;
  void toEcef(Ecef& ecef) const;
  double latDeg() const;
  double lonDeg() const;
  Lla addEnu(const Enu& enu) const;
  bool operator==(const Lla& lla) const;
  bool operator!=(const Lla& lla) const;

  double lat; // latitude  (rad)
  double lon; // longitude (rad)
  double alt; // altitude  (meter)
};

} // namespace Sdx

#endif // LLA_H
