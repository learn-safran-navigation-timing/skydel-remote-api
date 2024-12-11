#!/usr/bin/env python3

# This Python script illustrates how to turn off/on specific satellites and signals for Skydel.

# Before running this script, make sure Skydel is runnin and the splash screen is closed.

import datetime
import skydelsdx
from skydelsdx.commands import New
from skydelsdx.commands import SetModulationTarget
from skydelsdx.commands import ChangeModulationTargetSignals
from skydelsdx.commands import Start
from skydelsdx.commands import Stop
from skydelsdx.commands import EnableRFOutputForSV
from skydelsdx.commands import EnableSignalForSV
from skydelsdx.commands import EnableSignalForEachSV

# Connect
sim = skydelsdx.RemoteSimulator() 
sim.setVerbose(True)
sim.connect()

# Create new config
sim.call(New(True))
# Change configuration before starting the simulation
sim.call(SetModulationTarget("NoneRT", "", "", True, "uniqueId1"))
sim.call(SetModulationTarget("NoneRT", "", "", True, "uniqueId2"))
sim.call(ChangeModulationTargetSignals(0, 12500000, 100000000, "UpperL", "L1CA,G1", -1, False, "uniqueId1"))
sim.call(ChangeModulationTargetSignals(0, 12500000, 100000000, "LowerL", "L2C,G2", -1, False, "uniqueId2"))

# Start the simulation
sim.start()

sim.call(EnableRFOutputForSV("GPS", 18, False), 4)
sim.call(EnableRFOutputForSV("GPS", 18, True), 6)
sim.call(EnableSignalForSV("L1CA", 22, False), 8)
sim.call(EnableSignalForSV("L2C", 24, False), 9)
sim.call(EnableSignalForSV("L1CA", 22, True), 10)
sim.call(EnableSignalForSV("L2C", 24, True), 10)

sim.call(EnableSignalForSV("L1CA", 0, False), 12)
sim.call(EnableSignalForSV("L2C", 0, False), 13)
sim.call(EnableSignalForSV("L1CA", 0, True), 14)
sim.call(EnableSignalForSV("L2C", 0, True), 14)


sim.call(EnableSignalForEachSV("L2C", [True, True, False, False, True, False, False, False,\
                                        True, True, True, True, False, False, True, False, \
                                        True, True, False, False, True, False, False, False, \
                                        True, True, True, True, False, False, True, False,\
                                        True, True, False, False, True, False, False, False,\
                                        True, True, True, True, False, False, True, False, \
                                        True, True, False, False, True, False, False, False, \
                                        True, True, True, True, False, False, True]), \
                                        15)

# Stop simulation when elapsed time is 20 sec
sim.stop(20)

sim.disconnect()
