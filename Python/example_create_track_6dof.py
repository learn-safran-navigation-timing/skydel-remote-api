#!/usr/bin/env python3

# This Python script illustrates how to create a circular 6DOF (Six degree of freedom) track for Skydel.

# Before running this script, make sure Skydel is runnin and the splash screen is closed.

import skydelsdx
from skydelsdx.commands import New
from skydelsdx.commands import SetModulationTarget
from skydelsdx.commands import ChangeModulationTargetSignals
from skydelsdx.commands import SetVehicleTrajectory
from skydelsdx.commands import EnableLogRaw

import math
from skydelsdx.units import Lla
from skydelsdx.units import Enu
from skydelsdx.units import Attitude
from skydelsdx.units import toRadian

HOST = "localhost"

class CircleTrajectory:
  LAT = 45.0
  LON = -74.0
  ALT = 1.0
  SPEED = 5    # M/S
  RADIUS = 50  # Meters

  def __init__(self, sim):
    self.sim = sim
  
  def _generateEnu(self, elapsedTime):
    time = elapsedTime / 1000.0
    posOnCircle = time*CircleTrajectory.SPEED/CircleTrajectory.RADIUS
    e = math.cos(posOnCircle) * CircleTrajectory.RADIUS
    n = math.sin(posOnCircle) * CircleTrajectory.RADIUS
    return Enu(e, n, 0)

  def send(self, duration):
    origin = Lla(toRadian(CircleTrajectory.LAT), toRadian(CircleTrajectory.LON), CircleTrajectory.ALT)
    for i in range(0,duration*100):
      elapsedTime = 10 * i   # time in msec
      enu = self._generateEnu(elapsedTime)
      attitude = Attitude(-math.atan2(enu.north, enu.east), 0, toRadian(-5))
      self.sim.pushTrackLlaNed(elapsedTime, origin.addEnu(enu), attitude)

# Connect
sim = skydelsdx.RemoteSimulator()
sim.setVerbose(True)
sim.connect(HOST)

# Create new config
sim.call(New(True))

# Change configuration before starting the simulation
sim.call(SetModulationTarget("NoneRT", "", "", True, "uniqueId"))
sim.call(ChangeModulationTargetSignals(0, 12500000, 100000000, "UpperL", "L1CA", -1, False, "uniqueId"))
sim.call(EnableLogRaw(True))

# Create a track (trajectory) for the vehicle
sim.call(SetVehicleTrajectory("Track"))
sim.beginTrackDefinition()
trajectory = CircleTrajectory(sim)
duration = 10
trajectory.send(duration)
count = sim.endTrackDefinition()

# Start the simulator
sim.start()
sim.stop(duration)

sim.disconnect()
