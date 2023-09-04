#!/usr/bin/env python3

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

# Change the signal here
signal = "L1CA"

for svId in visibles.svId():
  # Get the signal power of that satellite
  power = sim.call(GetAllPowerForSV("GPS", svId, [signal]))

  print("SV ID {0} received power {1} for signal {2}".format(svId, power.signalPowerDict()[signal].Total, signal))

sim.stop()

sim.disconnect()
