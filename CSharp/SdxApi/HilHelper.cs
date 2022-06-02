using System;

namespace Sdx
{
  // Generator for the circular trajectory

  public class CircleTrajectory
  {
    public double SPEED { set; get; }     // M/S
    static readonly double RADIUS = 10.0; // Meters
    static readonly Lla ORIGIN = new Lla(HilHelper.ToRadian(45.0), HilHelper.ToRadian(-74.0), 1.0);
    static readonly double SinLon = Math.Sin(ORIGIN.Lon);
    static readonly double CosLon = Math.Cos(ORIGIN.Lon);
    static readonly double SinLat = Math.Sin(ORIGIN.Lat);
    static readonly double CosLat = Math.Cos(ORIGIN.Lat);

    public CircleTrajectory()
    {
      SPEED = 10.0;
    }

    private Ecef ComputeVelocity(double posOnCircle)
    {
      double ve = -SPEED * Math.Sin(posOnCircle);
      double vn = SPEED * Math.Cos(posOnCircle);

      return new Ecef(-SinLon * ve - SinLat * CosLon * vn, CosLon * ve - SinLat * SinLon * vn, CosLat * vn);
    }

    public Tuple<Ecef, Ecef> GeneratePositionAndVelocityAt(double elapsedTime)
    {
      double time = elapsedTime / 1000.0;
      double posOnCircle = time * this.SPEED / RADIUS;

      double e = Math.Cos(posOnCircle) * RADIUS;
      double n = Math.Sin(posOnCircle) * RADIUS;
      Lla llaPos = ORIGIN.AddEnu(new Enu(e, n, 0));

      Ecef position = llaPos.ToEcef();

      return new Tuple<Ecef, Ecef>(position, ComputeVelocity(posOnCircle));
    }
  }

  public static class HilHelper
  {
    public static double ToRadian(double degree)
    {
      return (Math.PI / 180) * degree;
    }

    // Get the system time in milliseconds
    public static double GetCurrentTimeMs()
    {
      // Ticks is in hundred of nanoseconds
      return (DateTimeOffset.UtcNow - new DateTime(1970, 1, 1, 0, 0, 0, DateTimeKind.Utc)).Ticks / 10000.0;
    }

    // This implies your OS time is synced with the radio's PPS signal
    public static double GetClosestPpsTimeMs()
    {
      return Math.Round(GetCurrentTimeMs() / 1000.0) * 1000.0;
    }

    // Sleep until a given timestamp
    public static void PreciseSleepUntilMs(double timestampMs, double busyWaitDurationMs = 15.0)
    {
      double currentTimeMs = GetCurrentTimeMs();

      // We already passed the timestamp
      if (currentTimeMs > timestampMs)
      {
        Console.WriteLine("Warning: tried to sleep to a timestamp in the past");
        return;
      }

      // Since System.Threading.Thread.Sleep might not be super precise, we busy wait some period of time
      int sleepDurationMs = (int)(timestampMs - currentTimeMs - busyWaitDurationMs);

      // If negative, we only busy wait
      if (sleepDurationMs > 0)
      {
        System.Threading.Thread.Sleep(sleepDurationMs);
      }

      // Busy wait until we reach our timestamp
      while (GetCurrentTimeMs() < timestampMs)
      {
        continue;
      }
    }
  }
} // namespace Sdx