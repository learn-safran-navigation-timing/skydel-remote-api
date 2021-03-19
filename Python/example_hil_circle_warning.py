#!/usr/bin/python

# This Python script illustrates how to handle HIL warnings when some packets 
# drop during simulation.

# Before running this script, make sure Skydel is runnin and the splash screen is closed.

import skydelsdx
from skydelsdx.commands import New
from skydelsdx.commands import SetModulationTarget
from skydelsdx.commands import ChangeModulationTargetSignals
from skydelsdx.commands import SetVehicleTrajectory
from skydelsdx.commands import Start
from skydelsdx.commands import Stop
from skydelsdx.commands import GetLastHilWarning
from skydelsdx.commands import ResetHilWarning

import math
import time
import random
from skydelsdx.units import Lla
from skydelsdx.units import Enu
from skydelsdx.units import toRadian

HOST = "localhost"

currentTime = lambda: int(round(time.time() * 1000))

class CircleTrajectory:
  LAT = 45.0
  LON = -74.0
  ALT = 1.0
  SPEED = 10    # M/S
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
    warningTime = currentTime()
    while 1 == 1:
      elapsedTime = currentTime() - self.startTime
      
      if elapsedTime > duration * 1000:
        sim.stop()
        return True
           
      # It is recommended to call GetLastHilWarning() at 10 Hz or less to avoid TCP stack overflow. 
      # HIL is using UDP so you can send positions at 100 Hz or 1000 Hz without any problem
      if currentTime() > warningTime + 1000:
        warningTime = currentTime()
        sim.setVerbose(False)
        hilWarning = self.sim.call(GetLastHilWarning())
        if hilWarning.isExtrapolated():
          print("HIL Warning: Current receiver position had to be extrapolated because HIL client did not send receiver position in time.")
          print("To avoid jerk, the HIL Client should send receiver positions with timestamps ahead of current simulation time.")
          print("The last extrapolation has occured at", hilWarning.extrapolationTime(), "ms.")

          self.sim.post(ResetHilWarning())
        sim.setVerbose(True)    
        
      #Simulate random packet drop to get an hil extrapolation jerk warning
      if random.random() < 0.95: 
        enu = self._generateEnu(elapsedTime)
        self.sim.pushLla(elapsedTime, origin.addEnu(enu))
  
      time.sleep(100.0 / 1000.0)

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
    
