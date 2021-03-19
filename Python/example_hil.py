#!/usr/bin/python

# This Python script illustrates simple HIL (hardware in the loop) with Skydel.

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
DURATION = 60000 # simulation duration is in ms
SPEED = 10       # m/s

# In this example we are using the PC time. In reality, the position's generator should provide the timestamp to use.
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
  
  sim.pushLla(elapsedTime, origin.addEnu(enu))

  #Send new enu to simulator each 10 ms. This should be controlled by the position's genreator.
  time.sleep(10.0 / 1000.0)

sim.stop()
sim.disconnect()
    
