#!/usr/bin/env python3

# This Python script illustrates how to create and modify interferences to automate Skydel.

# Before running this script, make sure Skydel is runnin and the splash screen is closed.

import datetime
import skydelsdx
from skydelsdx.commands import New
from skydelsdx.commands import SetModulationTarget
from skydelsdx.commands import ChangeModulationTargetSignals
from skydelsdx.commands import Start
from skydelsdx.commands import Stop
from skydelsdx.commands import SetInterferenceCW
from skydelsdx.commands import RemoveAllInterferences

# Connect
sim = skydelsdx.RemoteSimulator() 
sim.setVerbose(True)
sim.connect()

# Create new config
sim.call(New(True))

# Change configuration before starting the simulation
sim.call(SetModulationTarget("NoneRT", "", "", True, "uniqueId"))
sim.call(ChangeModulationTargetSignals(0, 12500000, 100000000, "UpperL", "L1CA", -1, False, "uniqueId"))
sim.call(RemoveAllInterferences())

# ---------------
# Option no.1 (using interference id)
# Add Continuous Wave Interference from start with infinite duration (StartTime:0, EndTime:0) at 1.5754 Ghz
interferenceId = "CW Interference 1"
sim.call(SetInterferenceCW(0, 0, 1575400000, 0, True, interferenceId))
# Update "CW Interference 1" to run between 2 and 5 secs (StartTime:2, EndTime:5) with invalid central freq (outside gnss band)
sim.call(SetInterferenceCW(2, 5, 1000000000, 0, True, interferenceId))
# ----------------

# Option no.2 (let Skydel assign interference id)
# Add Continuous Wave Interference and update with same command instance
cmd = SetInterferenceCW(0, 10, 1580000000, 0, True, "")
result = sim.call(cmd)
# Reuse command SetInterferenceCW with the updated id
cmd = result.getRelatedCommand()
# Disable Interference
cmd.setEnabled(False)
# Update the last interference with enabled = False
sim.call(cmd)
# ---------------

# Prepare a CW Interference for gradual power control while simulating
cmdCW = SetInterferenceCW(0, 0, 1575400000, 0, True, "")
cmdCW = sim.call(cmdCW).getRelatedCommand()

# Start the simulation
sim.start()

# Asynchronous command examples

# Gradually increase CW interference power from 0 to 10 db in the first 10 secs
# and gradually decrease CW interference power from 10 to 0 db for the next 10 secs
sim.setVerbose(False)
for x in range(0, 100):
  power = x / 10.0
  timeStamp = x / 10.0
  cmdCW.setPower(power)
  sim.post(cmdCW, timeStamp)
  cmdCW.setPower(10 - power)
  sim.post(cmdCW, 10 + timeStamp)
sim.setVerbose(True)

# Stop simulation when elapsed time is 20 sec
sim.stop(20)

sim.disconnect()
