#!/usr/bin/env python3

# This Python script illustrates basic commands to automate Skydel.

# Before running this script, make sure Skydel is runnin and the splash screen is closed.

import time
import datetime
import skydelsdx
from skydelsdx.commands import *
from skydelsdx.units import toDegree

# Connect
sim = skydelsdx.RemoteSimulator() 
sim.setVerbose(True)
sim.connect() #same as sim.connect("localhost")

# Create new config
sim.call(New(True)) 

# Change configuration before starting the simulation
sim.call(SetModulationTarget("NoneRT", "", "", True, "uniqueId"))
sim.call(ChangeModulationTargetSignals(0, 12500000, 100000000, "UpperL", "L1CA", -1, False, "uniqueId"))
sim.call(SetVehicleTrajectoryCircular("Circular", 0.7853995339022749, -1.2740964277717111, 0, 50, 3, True))

#You must call beginVehicleInfo before getting vehicle informations
sim.beginVehicleInfo()
sim.start()

info = sim.lastVehicleInfo()
origLla = info.ecef.toLla()

while info.elapsedTime < 90000:
  
  info = sim.lastVehicleInfo()
  lla = info.ecef.toLla()
  enu = lla.toEnu(origLla)
  print("------------------------------------------------------------------")
  print("Time (ms): %d" % info.elapsedTime)
  print("ENU Position (meters): %.2f, %.2f, %.2f" % (enu.north, enu.east, enu.up))
  print("NED Attitude (deg): %.2f %.2f %.2f" % (info.attitude.yawDeg(), info.attitude.pitchDeg(), info.attitude.rollDeg()))
  print("Odometer (meters): %.2f | Heading (deg): %.2f | Speed (m/s): %.2f" % (info.odometer, toDegree(info.heading), info.speed))
  time.sleep(1)


sim.stop()
sim.endVehicleInfo()

sim.disconnect()
