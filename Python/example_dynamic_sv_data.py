#!/usr/bin/env python3

# This Python script illustrates how to send satellite data parsed from RINEX files
# to the Skydel simulator during a simulation.

# Before running this script, make sure Skydel is runnin and the splash screen is closed.

import rinex_parser

from pathlib import Path
from datetime import timedelta
from skydelsdx import *
from skydelsdx.commands import *

# Uitlity function to get the default RINEX files used by Skydel
def getDefaultRINEXFilePath(system, data_folder):
    return Path(data_folder, "Templates", system.lower() + "_ephemeris.txt")

# Radio type ("NoneRT", "DTA-2115B", "X300", "N310", etc)
radio = "NoneRT"

# Delay when the blocks are applied from start of the simulation
post_delay_sec = 2 

# Connect to Skydel
sim = RemoteSimulator(True)
sim.connect()
sim.setVerbose(True)

# Get Data folder where default RINEX files are located
data_folder = sim.call(GetDataFolder()).folder()

# Get the GPS satellites data blocks
blocks = rinex_parser.parse(getDefaultRINEXFilePath("GPS", data_folder))

# Create a new configuration
sim.call(New(True, False))

# With U-Blox receivers the start time relative to the block TOC is important to get a PVT
sim.call(SetGpsStartTime(blocks[0].toc - timedelta(hours=2)))

# Enable Dynamic SV Data feature
sim.call(SetSVDataUpdateMode(SVDataUpdateMode.Dynamic))

# Setup output
sim.call(SetModulationTarget(radio, "", "", True, "Radio"))
sim.call(ChangeModulationTargetSignals(0, 1250000, 85000000, "UpperL", "L1CA", -1, False, "Radio", None))

# Can only send PushDynamicSVData after arm() or start()
sim.arm()

# This will only post one block for each SV, you can post other blocks later in the simulation
for block in blocks:
    # To prevent large spikes in performance, it helps to post on different milliseconds
    post_timestamp_sec = post_delay_sec + block.sv_id / 1000
    sim.post(PushDynamicSVData("GPS", block.sv_id, block.toc, block.params), post_timestamp_sec)

# Run the simulation
sim.start()
sim.stop(60)

# Disconnect from Skydel
sim.disconnect()
