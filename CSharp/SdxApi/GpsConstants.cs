namespace Sdx
{
  public static class GPS
  {
    // WGS-84 PARAMETERS
    public const double ESMAJ = 6378137.0; // Semi-major axis of Earth, meters
    public const double EFLAT = 0.00335281066474;
    public const double ESMIN = ESMAJ * (1.0 - EFLAT);
    public const double EECC_SQUARED = (((ESMAJ * ESMAJ) - (ESMIN * ESMIN)) / (ESMAJ * ESMAJ));
  }
}
