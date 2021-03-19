#!/usr/bin/python

# This Python script describe how to get the power of all visible satellite.

# Before running this script, make sure Skydel is runnin and the splash screen is closed.

import skydelsdx
from skydelsdx.commands import *

sim = skydelsdx.RemoteSimulator()

# Connect
sim = skydelsdx.RemoteSimulator() 
sim.setVerbose(True)
sim.connect() #same as sim.connect("localhost")

# Create new config
sim.call(New(True)) 

# Change configuration before starting the simulation
sim.call(SetModulationTarget("NoneRT", "", "", True, "uniqueId"))
sim.call(ChangeModulationTargetSignals(0, 12500000, 100000000, "UpperL", "L1CA", -1, False, "uniqueId"))

# Arm the simulation
sim.arm()

# Get the list of all visible satellite
visibles = sim.call(GetVisibleSV("GPS"))

for svId in visibles.svId():
  # Get the power of that satellite
  power = sim.call(GetPowerForSV("GPS", svId))

  print("SV ID {0} received power: {1}".format(svId, power.total()))

sim.stop()

sim.disconnect()
