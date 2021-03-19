#!/usr/bin/python

# This Python script illustrates HIL circular trajectory for Skydel

# Before running this script, make sure Skydel is runnin and the splash screen is closed.

import skydelsdx
from skydelsdx.commands import New
from skydelsdx.commands import SetModulationTarget
from skydelsdx.commands import ChangeModulationTargetSignals
from skydelsdx.commands import SetVehicleTrajectory
from skydelsdx.commands import Start
from skydelsdx.commands import Stop

import math
import time
from skydelsdx.units import Lla
from skydelsdx.units import Enu
from skydelsdx.units import toRadian

HOST = "localhost"

currentTime = lambda: int(round(time.time() * 1000))

class CircleTrajectory:
  LAT = 45.0
  LON = -74.0
  ALT = 1.0
  SPEED = 1    # M/S
  RADIUS = 10  # Meters

  def __init__(self, sim):
    self.sim = sim
    self.startTime = 0
    self.lastElapsedTime = 0
    
  def _generateEnu(self, elapsedTime):
    time = elapsedTime / 1000.0
    posOnCircle = time*CircleTrajectory.SPEED/CircleTrajectory.RADIUS
    e = math.cos(posOnCircle) * CircleTrajectory.RADIUS
    n = math.sin(posOnCircle) * CircleTrajectory.RADIUS
    return Enu(e, n, 0)

  def send(self, duration):
    origin = Lla(toRadian(CircleTrajectory.LAT), 
                   toRadian(CircleTrajectory.LON), 
                   CircleTrajectory.ALT)
    sim.start()

    # -- Sending positions in real time --
    self.startTime = currentTime()
    while 1 == 1:
      elapsedTime = currentTime() - self.startTime
      
      if elapsedTime > duration * 1000:
        sim.stop()
        return True
        
      enu = self._generateEnu(elapsedTime)
      self.sim.pushLla(elapsedTime, origin.addEnu(enu))
  
      # if the client disconnect during simulation,
      # it is because there is an error and you must increase Sleep delay
      # or use an ethernet cable instead of wifi
      time.sleep(10.0 / 1000.0)

# Connect
sim = skydelsdx.RemoteSimulator()
sim.setVerbose(True)
sim.connect(HOST)

# Create new config
sim.call(New(True))
# Change configuration before starting the simulation
sim.call(SetModulationTarget("NoneRT", "", "", True, "uniqueId"))
sim.call(ChangeModulationTargetSignals(0, 12500000, 100000000, "UpperL", "L1CA", -1, False, "uniqueId"))
# Change configuration to HIL before starting the simulation
sim.call(SetVehicleTrajectory("HIL"))
  
trajectory = CircleTrajectory(sim)
trajectory.send(100)

sim.disconnect()
    
