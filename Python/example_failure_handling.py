#!/usr/bin/env python3

# This Python script illustrates how to manually handle Skydel errors.

# Before running this script, make sure Skydel is runnin and the splash screen is closed.


import datetime
import skydelsdx
from skydelsdx.commands import SetModulationTarget
from skydelsdx.commands import ChangeModulationTargetSignals
from skydelsdx.commands import SetGpsStartTime
from skydelsdx.commands import SetManualPowerOffsetForSV
from skydelsdx.commands import ResetManualPowerOffsets
from skydelsdx.commands import New
from skydelsdx.commands import GetSimulatorState

# Connect
#sim = skydelsdx.RemoteSimulator(True) #Stop the script with an exception if a command fails (automatic failure handling)
sim = skydelsdx.RemoteSimulator(False) #Does not stop the script with an exception if a command fails (manual failure handling)
sim.setVerbose(True) 
sim.connect() #same as sim.connect("localhost")

sim.call(New(True)) 

# Change configuration before starting the simulation
sim.call(SetModulationTarget("NoneRT", "", "", True, "uniqueId"))
sim.call(ChangeModulationTargetSignals(0, 12500000, 100000000, "UpperL", "L1CA", -1, False, "uniqueId"))

# The following command is not allowed before you start the simulation.
# Error message will be displayed
result = sim.call(SetManualPowerOffsetForSV("GPS", 12, {"All": -10}, True))
print(result.getMessage())

# Start the simulation
if sim.start():
  # Right after start, set -15 dB of manual power offset to all signals of satellite 15
  sim.call(SetManualPowerOffsetForSV("GPS", 15, {"All": -15}, False))

  # The following command is not allowed after you start the simulation. 
  # Error message will be displayed
  result = sim.call(SetGpsStartTime(datetime.datetime(2021, 2, 15, 7, 0, 0)))
  print(result.getRelatedCommand().toString() + ": " + result.getMessage())

  # Asynchronous command examples

  # When simulation elapsed time is 9.567 sec, set -25 dB of manual power offset to signal L1CA of satellite 31
  cmd1 = sim.post(SetManualPowerOffsetForSV("GPS", 31, {"L1CA": -25}, False), 9.567)

  # When simulation elapsed time is 12.05 sec, add 10 dB of manual power offset to all signals of satellite 26
  cmd2 = sim.post(SetManualPowerOffsetForSV("GPS", 26, {"All": 10}, True), 12.05)

  # Wait for commands to complete
  result1 = sim.wait(cmd1)
  result2 = sim.wait(cmd2)
  if result1.isSuccess() and result2.isSuccess():
    # When simulation elapsed time is 15, reset all satellites to nominal power
    cmd3 = ResetManualPowerOffsets("GPS")
    sim.post(cmd3, 15)
    sim.wait(cmd3)
  else: #Print failed message
    print(result1.getRelatedCommand().toString() + ": " + result1.getMessage())
    print(result2.getRelatedCommand().toString() + ": " + result2.getMessage())
  
  # Stop simulation when elapsed time is 20 sec
  sim.stop(20)

  stateResult = sim.call(GetSimulatorState())
      
  if stateResult.state() == "Error":
    print("An error occured during simulation. Error message:\n" + stateResult.error())
  
sim.disconnect()
