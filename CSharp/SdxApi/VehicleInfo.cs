using System;

namespace Sdx
{
  public class VehicleInfo
  {
    public long ElapsedTime {get; set;} //ms
    public Ecef Position { get; set; }
    public Attitude Attitude { get; set; } //ned
    public double Speed { get; set; } //km/h
    public double Heading { get; set; } //rad
    public double Odometer { get; set; } //meters since start
  };
}
