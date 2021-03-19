using System;

namespace Sdx
{
public struct Enu
{
  public double East {get; set;}
  public double North {get; set;}
  public double Up {get; set;}

  public Enu(double east, double north, double up)
    : this()
  {
    East = east;
    North = north;
    Up = up;
  }

  public Ecef ToEcef(Lla origin)
  {
    Ecef originEcef = origin.ToEcef();

    double sinLon = Math.Sin(origin.Lon);
    double cosLon = Math.Cos(origin.Lon);
    double sinLat = Math.Sin(origin.Lat);
    double cosLat = Math.Cos(origin.Lat);

    return new Ecef(
          -sinLon * East - sinLat * cosLon * North + cosLat * cosLon * Up + originEcef.X,
          cosLon * East - sinLat * sinLon * North + cosLat * sinLon * Up + originEcef.Y,
          cosLat * North + sinLat * Up + originEcef.Z
          );
  }

  public Lla ToLla(Lla origin)
  {
    return ToEcef(origin).ToLla();
  }
}
} // namespace Bb
