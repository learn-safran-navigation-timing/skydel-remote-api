#!/usr/bin/env python3

# This file contains code used across the HIL examples.

from skydelsdx.units import Lla
from skydelsdx.units import Enu
from skydelsdx.units import Ecef
from skydelsdx.units import toRadian

import math
import time
import sys

if sys.platform == "win32":
  BUSY_WAIT_DURATION_MS = 15.
else:
  BUSY_WAIT_DURATION_MS = 1.

# Generator for the circular trajectory
class CircleTrajectory:
  LAT = 45.0
  LON = -74.0
  ALT = 1.0
  SPEED = 1.0    # M/S
  RADIUS = 10.0  # Meters
  ORIGIN = Lla(toRadian(LAT), toRadian(LON), ALT)

  sinLon = math.sin(ORIGIN.lon)
  cosLon = math.cos(ORIGIN.lon)
  sinLat = math.sin(ORIGIN.lat)
  cosLat = math.cos(ORIGIN.lat)

  def _computeVelocity(self, posOnCircle):
    ve = -self.SPEED * math.sin(posOnCircle)
    vn = self.SPEED * math.cos(posOnCircle)
    
    return Ecef(-self.sinLon * ve - self.sinLat * self.cosLon * vn, self.cosLon * ve - self.sinLat * self.sinLon * vn, self.cosLat * vn)

  def generateEcefWithDynamics(self, elapsedTime):
    time = elapsedTime / 1000.0
    posOnCircle = time * self.SPEED / self.RADIUS
    e = math.cos(posOnCircle) * self.RADIUS
    n = math.sin(posOnCircle) * self.RADIUS
    
    llaPos = self.ORIGIN.addEnu(Enu(e, n, 0))
    position = llaPos.toEcef()

    return position, self._computeVelocity(posOnCircle)


# Generator for the straight trajectory
class StraightTrajectory:
  def __init__(self, speed=1.0, latDeg=45.0, lonDeg=-74.0, alt=1.0):
    self.SPEED = speed    # M/S
    self.LAT = latDeg
    self.LONG = lonDeg
    self.ALT = alt
    self.ORIGIN = Lla(toRadian(self.LAT), toRadian(self.LONG), self.ALT)
    self.sinLon = math.sin(self.ORIGIN.lon)
    self.cosLon = math.cos(self.ORIGIN.lon)
    self.sinLat = math.sin(self.ORIGIN.lat)
    self.cosLat = math.cos(self.ORIGIN.lat)

  def _computeVelocityToTheNorth(self):
    vn = self.SPEED
    
    return Ecef(-self.sinLat * self.cosLon * vn, -self.sinLat * self.sinLon * vn, self.cosLat * vn)
    
  def _computeVelocityToTheEast(self):
    ve = -self.SPEED
    
    return Ecef(-self.sinLon * ve, self.cosLon * ve, 0)

  def generateEcefWithDynamicsGoingNorth(self, elapsedTime):
    timeSec = elapsedTime / 1000.0
    
    llaPos = self.ORIGIN.addEnu(Enu(0, self.SPEED * timeSec, 0))
    position = llaPos.toEcef()

    return position, self._computeVelocityToTheNorth()

  def generateEcefWithDynamicsGoingEast(self, elapsedTime):
    timeSec = elapsedTime / 1000.0
    
    llaPos = self.ORIGIN.addEnu(Enu(self.SPEED * timeSec, 0, 0))
    position = llaPos.toEcef()

    return position, self._computeVelocityToTheEast()


# Get the system time in milliseconds
def getCurrentTimeMs():
  return time.time() * 1000.


# This implies your OS time is synced with the radio's PPS signal
def getClosestPpsTimeMs():
  return round(getCurrentTimeMs() / 1000.) * 1000.

# Sleep until a given timestamp
def preciseSleepUntilMs(timestampMs, busyWaitDurationMs = BUSY_WAIT_DURATION_MS):
  currentTimeMs = getCurrentTimeMs()

  # We already passed the timestamp
  if currentTimeMs > timestampMs:
    print("Warning: tried to sleep to a timestamp in the past")
    return

  # Since time.sleep might not be super precise, we busy wait some period of time
  sleepDurationSec = (timestampMs - currentTimeMs - busyWaitDurationMs) / 1000.

  # If negative, we only busy wait
  if sleepDurationSec > 0:
    time.sleep(sleepDurationSec)

  # Busy wait until we reach our timestamp
  while getCurrentTimeMs() < timestampMs:
    pass


# Helper function to exit with an error message
def error(message):
  print(message)
  sys.exit(-1)
