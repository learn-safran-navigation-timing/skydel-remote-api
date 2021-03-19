using System;

namespace Sdx
{
public struct Lla
{
  public double Lat {get; set;}
  public double Lon {get; set;}
  public double Alt {get; set;}

  public double LatDeg { get { return Lat / Math.PI * 180; } }
  public double LonDeg { get { return Lon / Math.PI * 180; } }

  public Lla(double lat, double lon, double alt)
    : this()
  {
    Lat = lat;
    Lon = lon;
    Alt = alt;
  }

  public Ecef ToEcef()
  {
    double cos_lat = Math.Cos(Lat);
    double tmp = (1-GPS.EFLAT)*(1-GPS.EFLAT);
    double ex2 = (2-GPS.EFLAT)*GPS.EFLAT/tmp;
    double c = GPS.ESMAJ*Math.Sqrt(1+ex2);
    double n = c / Math.Sqrt(1 + ex2 * cos_lat * cos_lat);
    Ecef ecef = new Ecef();
    ecef.X = (n+Alt)*cos_lat*Math.Cos(Lon);
    ecef.Y = (n+Alt)*cos_lat*Math.Sin(Lon);
    ecef.Z = (tmp*n+Alt)*Math.Sin(Lat);
    return ecef;
  }

  public Enu ToEnu(Lla origin)
  {
    Enu enu = new Enu();
    enu.East = (Lon - origin.Lon) * GPS.ESMAJ * Math.Cos(Lat);
    enu.North = (Lat - origin.Lat) * GPS.ESMAJ;
    enu.Up = Alt - origin.Alt;
    return enu;
  }

  public Lla AddEnu(Enu enu)
  {
    return enu.ToLla(this);
  }
}
} // namespace Bb
