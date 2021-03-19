using System;

namespace Sdx
{
  public struct Attitude
  {
    public double Yaw { get; set; }
    public double Pitch { get; set; }
    public double Roll { get; set; }

    public double YawDeg { get { return Yaw / Math.PI * 180; } }
    public double PitchDeg { get { return Pitch / Math.PI * 180; } }
    public double RollDeg { get { return Roll / Math.PI * 180; } }

    public Attitude(double yaw, double pitch, double roll)
      : this()
    {
      Yaw = yaw;
      Pitch = pitch;
      Roll = roll;
    }
  }
} // namespace Bb
