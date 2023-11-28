#pragma once

#define _USE_MATH_DEFINES
#include <chrono>
#include <cmath>
#include <tuple>

#include "ecef.h"
#include "enu.h"
#include "lla.h"

#ifdef _WIN32
#define BUSY_WAIT_DURATION_MS 15.
#else
#define BUSY_WAIT_DURATION_MS 1.
#endif

namespace Sdx
{
inline double toRadian(double degree)
{
  return (M_PI / 180.0) * degree;
}

// Generator for the circular trajectory

class CircleTrajectory
{
public:
  inline Ecef computeVelocity(double posOnCircle)
  {
    double ve = -SPEED * std::sin(posOnCircle);
    double vn = SPEED * std::cos(posOnCircle);

    return Ecef(-SinLon * ve - SinLat * CosLon * vn, CosLon * ve - SinLat * SinLon * vn, CosLat * vn);
  }

  inline std::tuple<Ecef, Ecef> generatePositionAndVelocityAt(double elapsedTime)
  {
    double time = elapsedTime / 1000.0;
    double posOnCircle = time * SPEED / RADIUS;

    double e = std::cos(posOnCircle) * RADIUS;
    double n = std::sin(posOnCircle) * RADIUS;
    Lla llaPos = ORIGIN.addEnu(Enu(e, n, 0));

    Ecef position;
    llaPos.toEcef(position);

    return std::tuple<Ecef, Ecef>(position, computeVelocity(posOnCircle));
  }

  double SPEED {10.0};
  double RADIUS {10.0}; // Meters
  Lla ORIGIN {toRadian(45.0), toRadian(-74.0), 1.0};
  double SinLon {std::sin(ORIGIN.lon)};
  double CosLon {std::cos(ORIGIN.lon)};
  double SinLat {std::sin(ORIGIN.lat)};
  double CosLat {std::cos(ORIGIN.lat)};
};

// Get the system time in milliseconds
inline double getCurrentTimeMs()
{
  using namespace std::chrono;
  return duration<double, std::milli>(system_clock::now().time_since_epoch()).count();
}

// This implies your OS time is synced with the radio's PPS signal
inline double getClosestPpsTimeMs()
{
  return round(getCurrentTimeMs() / 1000.) * 1000.;
}

// Sleep until a given timestamp
inline void preciseSleepUntilMs(double timestampMs, double busyWaitDurationMs = BUSY_WAIT_DURATION_MS)
{
  double currentTimeMs = getCurrentTimeMs();

  // We already passed the timestamp
  if (currentTimeMs > timestampMs)
  {
    std::cout << "Warning: tried to sleep to a timestamp in the past" << std::endl;
    return;
  }

  // Since std::this_thread::sleep_for might not be super precise, we busy wait some period of time
  int sleepDurationMs = static_cast<int>(timestampMs - currentTimeMs - busyWaitDurationMs);

  // If negative, we only busy wait
  if (sleepDurationMs > 0)
  {
    std::this_thread::sleep_for(std::chrono::milliseconds(sleepDurationMs));
  }

  // Busy wait until we reach our timestamp
  while (getCurrentTimeMs() < timestampMs)
  {
    continue;
  }
}
} // namespace Sdx