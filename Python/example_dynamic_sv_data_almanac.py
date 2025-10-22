#!/usr/bin/env python3

# This Python script illustrates how to send Orbit, Ephemeris and Almanac satellite data 
# parsed from RINEX files to the Skydel simulator during a simulation. The script demonstrates
# sending different Almanac data sets to different satellites.

# Before running this script, make sure Skydel is running and the splash screen is closed.

import rinex_parser

from pathlib import Path
from datetime import timedelta
from skydelsdx import *
from skydelsdx.commands import *

# Utility functions to get the RINEX files used by Skydel
def getRinexFilePath(dataFolder, fileName):
    return Path(dataFolder, "Templates", fileName)

def getDefaultRinexFilePath(system, dataFolder):
    return getRinexFilePath(dataFolder, system.lower() + "_ephemeris.txt")


# Radio type ("NoneRT", "DTA-2115B", "X300", "N310", etc)
radio = "None"

# Delay when the blocks are applied from start of the simulation
postDelaySec = 2 

# Connect to Skydel
sim = RemoteSimulator(True)
sim.connect()
sim.setVerbose(True)

# Get Data folder where default RINEX files are located
dataFolder = sim.call(GetDataFolder()).folder()

# Get the GPS satellites data blocks
rinexEphemerisBlock = rinex_parser.parse(getDefaultRinexFilePath("GPS", dataFolder))

rinexAlmanacBlocks1 = rinex_parser.parse(getDefaultRinexFilePath("GPS", dataFolder))
rinexAlmanacBlocks2 = rinex_parser.parse(getRinexFilePath(dataFolder, "gps_ephemeris_23.8.txt"))

# Create a new configuration
sim.call(New(True, False))

firstToc = rinexEphemerisBlock[0].toc - timedelta(hours=2)

# With U-Blox receivers the start time relative to the block TOC is important to get a PVT
sim.call(SetGpsStartTime(firstToc))

# Enable Dynamic SV Data feature
sim.call(SetSVDataUpdateMode(SVDataUpdateMode.Dynamic))

# Almanac data must be pushed via the PushDynamicAlmanacData command
sim.call(EnableAlmanacExtrapolationFromEphemeris(False))

# Setup output
sim.call(SetModulationTarget(radio, "", "", True, "Radio"))
sim.call(ChangeModulationTargetSignals(0, 1250000, 85000000, "UpperL", "L1CA", -1, False, "Radio", None))

# Can only send PushDynamicSVData and PushDynamicAlmanacData after arm() or start()
sim.arm()

# Push data for Ephemeris and Orbit
# This will only post one block for each SV, you can post other blocks later in the simulation
for ephemerisBlock in rinexEphemerisBlock:
    # To prevent large spikes in performance, it helps to post on different milliseconds
    postTimestampSec = postDelaySec + ephemerisBlock.sv_id / 1000
    sim.post(PushDynamicSVData("GPS", ephemerisBlock.sv_id, ephemerisBlock.toc, ephemerisBlock.params, ["Ephemeris", "Orbit"]), postTimestampSec)

# Push a first set of Almanac for all SV
almanacDataSet1 = []
for almanacBlock in rinexAlmanacBlocks1:
    block = AlmanacSVData(almanacBlock.sv_id, almanacBlock.params)
    almanacDataSet1.append(block)
allSVs = 0 
sim.post(PushDynamicAlmanacData("GPS", firstToc + timedelta(hours=2), almanacDataSet1, allSVs)) 

# Push a second set of Almanac only for one SV, 5 minutes after the start of the simulation
almanacDataSet2 = []
for almanacBlock in rinexAlmanacBlocks2:
    block = AlmanacSVData(almanacBlock.sv_id, almanacBlock.params)
    almanacDataSet2.append(block)
svID = 8
postTimestampSec = 300 # 5 minutes
sim.post(PushDynamicAlmanacData("GPS", firstToc + timedelta(hours=4), almanacDataSet2, svID), postTimestampSec)

# Run the simulation
sim.start()
sim.stop(600) # 10 minutes

# Disconnect from Skydel
sim.disconnect()
