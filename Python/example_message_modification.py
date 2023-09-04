#!/usr/bin/env python3

# This Python script illustrates how to use message modification commands.

# Before running this script, make sure Skydel is running and the splash screen is closed.

import time
import skydelsdx
from datetime import datetime
from skydelsdx.commands import *

# Connect
sim = skydelsdx.RemoteSimulator() 
sim.setVerbose(True)
sim.connect() # Same as sim.connect("localhost")

# Create new config
sim.call(New(True)) 

# Change the configuration before starting the simulation
sim.call(SetGpsStartTime(datetime(2021, 6, 24, 12, 0, 0)))
sim.call(SetModulationTarget("NoneRT", "", "", True, "uniqueId"))
sim.call(ChangeModulationTargetSignals(0, 12500000, 100000000, "UpperL", "L1CA", -1, False, "uniqueId"))

# Use the downlink logging to validate the message modifications are applied correctly
# You can find the log files in the "Skydel-SDX/Output" folder
sim.call(EnableLogDownlink(True))

# To have less entries in the log file, we only enable SV 1 and 2
sim.call(EnableSV("GPS", 0, False))
sim.call(EnableSV("GPS", 1, True))
sim.call(EnableSV("GPS", 2, True))

# Set a message modification at idle time, for the first GPS L1CA message of all SVs (elapsed time 0s to 6s)
sim.call(SetMessageModificationToGpsLNav(["L1CA"], 0, 0, 6, 0, 0, 0, True, "001100000000000001000000XXX---", "GPS_L1CA_MOD_1"))

# Start the simulation
sim.start()

# Here the sleep is to simulate something else doing work in your script 
time.sleep(11)

# You should always prefer call rather than post when you set message modifications
# Set a message modification during the simulation, for the third GPS L1CA message of SV 1 (elapsed time 12s to 18s)
sim.call(SetMessageModificationToGpsLNav(["L1CA"], 1, 12, 18, 0, 0, 0, True, "XXXXXXXX1111111100000000------", "GPS_L1CA_MOD_2"))

# Stop simulation when elapsed time is 20 sec
sim.stop(20)

sim.disconnect()
