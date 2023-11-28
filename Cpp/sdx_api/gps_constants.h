#ifndef GNSS_CONSTANTS_H
#define GNSS_CONSTANTS_H

namespace Sdx
{
namespace GPS
{
// WGS-84 PARAMETERS
const double ESMAJ = 6378137.0; // Semi-major axis of Earth, meters
const double EFLAT = 0.00335281066474;
const double ESMIN = ESMAJ * (1.0 - EFLAT);
const double EECC_SQUARED = (((ESMAJ * ESMAJ) - (ESMIN * ESMIN)) / (ESMAJ * ESMAJ));
} // namespace GPS
} // namespace Sdx

#endif // GPS_CONSTANTS_H
