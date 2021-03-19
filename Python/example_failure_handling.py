#!/usr/bin/python

# This Python script illustrates how to manually handle Skydel errors.

# Before running this script, make sure Skydel is runnin and the splash screen is closed.


import datetime
import skydelsdx
from skydelsdx.commands import SetModulationTarget
from skydelsdx.commands import ChangeModulationTargetSignals
from skydelsdx.commands import SetVehicleTrajectoryCircular
from skydelsdx.commands import SetGpsStartTime
from skydelsdx.commands import Start
from skydelsdx.commands import SetPowerForSV
from skydelsdx.commands import ResetAllSatPower
from skydelsdx.commands import Stop
from skydelsdx.commands import New
from skydelsdx.commands import Open
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
result = sim.call(SetPowerForSV("GPS", 12, -10, True))
print(result.getMessage())

# Start the simulation
if sim.start():
  # Change satellite 14 power to -15dB (relative to nominal power)
  sim.call(SetPowerForSV("GPS", 14, -15, False))

  # The following command is not allowed after you start the simulation. 
  # Error message will be displayed
  result = sim.call(SetGpsStartTime(datetime.datetime(2021, 2, 15, 7, 0, 0)))
  print(result.getRelatedCommand().toString() + ": " + result.getMessage())

  # Asynchronous command examples

  # When simulation elapsed time is 9.567 sec, change satellite 31 power to -25 dB
  cmd1 = sim.post(SetPowerForSV("GPS", 31, -25, False), 9.567)

  # When simulation elapsed time is 12.05 sec, change satellite 26 power to +10 dB
  cmd2 = sim.post(SetPowerForSV("GPS", 26, 10, False), 12.05)

  # Wait for commands to complete
  result1 = sim.wait(cmd1)
  result2 = sim.wait(cmd2)
  if result1.isSuccess() and result2.isSuccess():
    # When simulation elapsed time is 15, reset all satellites to nominal power
    cmd3 = ResetAllSatPower("GPS")
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
