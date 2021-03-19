using System;

namespace Sdx
{
public struct Ecef
{
  public double X {get; set;}
  public double Y {get; set;}
  public double Z {get; set;}

  public Ecef(double x, double y, double z) 
    : this()
  {
    X = x;
    Y = y;
    Z = z;
  }

  public Ecef(Lla lla)
    : this()
  {
    Ecef ecef = lla.ToEcef();
    X = ecef.X;
    Y = ecef.Y;
    Z = ecef.Z;
  }

  public Lla ToLla()
  {
    Lla lla = new Lla();
    double radius_p = 0;
    double dist_to_z = Math.Sqrt(X*X + Y*Y);
    lla.Lat = Math.Atan2(Z, (1 - GPS.EECC_SQUARED) * dist_to_z);
    for (int i=1; i<=5; ++i)
    {
        double sin_lat = Math.Sin(lla.Lat);
        radius_p = GPS.ESMAJ / Math.Sqrt(1.0 - GPS.EECC_SQUARED * sin_lat * sin_lat);
        lla.Lat= Math.Atan2(Z + GPS.EECC_SQUARED * radius_p * sin_lat, dist_to_z);
    }
    lla.Lon = Math.Atan2(Y, X);
    if (lla.LatDeg < -85 || lla.LatDeg > 85) // If we are close to the poles
    {
      double L = Z + GPS.EECC_SQUARED * radius_p * Math.Sin(lla.Lat);
      lla.Alt = L / Math.Sin(lla.Lat) - radius_p;
    }
    else
    {
      lla.Alt = dist_to_z / Math.Cos(lla.Lat) - radius_p;
    }
    return lla;
  }
}
  
}//namespace Bb
