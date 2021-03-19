#!/usr/bin/python

# This Python script illustrates basic commands to automate Skydel.

# Before running this script, make sure Skydel is runnin and the splash screen is closed.


import datetime
import skydelsdx
from skydelsdx.commands import *
import time

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
sim.call(SetGpsStartTime(datetime.datetime(2021, 2, 15, 7, 0, 0)))
sim.call(SetVehicleAntennaGain([], AntennaPatternType.AntennaNone, GNSSBand.L1))

# Arm the simulation
sim.arm()

# Asynchronous command examples

# Change satellite 16 power to +5 dB (relative to nominal power)
sim.post(SetPowerForSV("GPS", 16, 5, False))

# When simulation elapsed time is 9.567 sec, change satellite 32 power to -25 dB (relative to nominal power)
cmd1 = sim.post(SetPowerForSV("GPS", 32, -25, False), 9.567)

# When simulation elapsed time is 12.05 sec, change satellite 29 power to +10 dB (relative to nominal power)
cmd2 = sim.post(SetPowerForSV("GPS", 29, 10, False), 12.05)

# Start the simulation
sim.start()

time.sleep(1);


# Right after start, change satellite 25 power to -15dB (relative to nominal power)
sim.call(SetPowerForSV("GPS", 25, -15, False))

# Wait for commands to complete
sim.wait(cmd1)
sim.wait(cmd2)

# When simulation elapsed time is 15, reset all satellites to nominal power
sim.call(ResetAllSatPower("GPS"), 15)

# Pause vehicle motion and resume at 18 sec
sim.call(Pause())
sim.call(Resume(), 18)

# Stop simulation when elapsed time is 20 sec
sim.stop(20)

#sim.call(Quit(True)) #will quit Skydel

sim.disconnect()
