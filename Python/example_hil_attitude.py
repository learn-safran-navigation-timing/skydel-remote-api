#!/usr/bin/python

# This Python script illustrates attitude control in HIL (hardware in the loop) with Skydel.

# Before running this script, make sure Skydel is running and the splash screen is closed.

import skydelsdx
from skydelsdx.commands import *

import math
import time
from skydelsdx.units import *

HOST = "localhost"
DURATION = 60000 # simulation duration is in ms
SPEED = 10       # m/s

currentTime = lambda: int(round(time.time() * 1000))

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
    
# Remote HIL

origin = Lla(toRadian(45.0), toRadian(-74.0), 1.0)
sim.start()

# -- Sending positions in real time --
startTime = currentTime()
while True:
  elapsedTime = currentTime() - startTime
  
  if elapsedTime > DURATION: 
    break
    
  t = elapsedTime / 1000.0   
  
  # Vehicule will head North/East
  enu = Enu(0, SPEED * t, 0)
  
  sim.pushLlaNed(elapsedTime, origin.addEnu(enu), Attitude(toRadian(45), toRadian(2), 0))

  #Send new enu to simulator each 10 ms
  time.sleep(10.0 / 1000.0)

sim.stop()
sim.disconnect()
    
