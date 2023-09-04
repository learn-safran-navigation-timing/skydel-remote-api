#!/usr/bin/env python3

# This Python script illustrates how to get simulation time.

# Before running this script, make sure Skydel is runnin and the splash screen is closed.


import time
import datetime
import skydelsdx
from skydelsdx.commands import New
from skydelsdx.commands import GetSimulationElapsedTime
from skydelsdx.commands import SetModulationTarget
from skydelsdx.commands import ChangeModulationTargetSignals

# Connect
sim = skydelsdx.RemoteSimulator() 
sim.setVerbose(False)
sim.connect() #same as sim.connect("localhost")

# Create new config
sim.call(New(True)) 

sim.call(SetModulationTarget("NoneRT", "", "", True, "uniqueId"))
sim.call(ChangeModulationTargetSignals(0, 12500000, 100000000, "UpperL", "L1CA", -1, False, "uniqueId"))

# Start the simulation
sim.start()

for x in range(0, 20):
  elapsedTime = sim.call(GetSimulationElapsedTime())
  formattedTime = datetime.timedelta(seconds=elapsedTime.milliseconds()//1000)
  print("Simulation Elapsed Time: " + str(formattedTime)) 
  time.sleep(1)
  
# Stop simulation after 20 seconds of time polling
sim.stop()

sim.disconnect()
