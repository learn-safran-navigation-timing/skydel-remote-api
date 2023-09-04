#!/usr/bin/env python3

# This Python script illustrates how to create an aircraft track from a CSV file for Skydel.

# Before running this script, make sure Skydel is runnin and the splash screen is closed.

FILE_PATH = 'example_create_track_aircraft.csv'

from datetime import datetime
from datetime import timedelta
import skydelsdx
from skydelsdx.commands import New
from skydelsdx.commands import SetModulationTarget
from skydelsdx.commands import ChangeModulationTargetSignals
from skydelsdx.commands import SetGpsStartTime
from skydelsdx.commands import SetVehicleTrajectory
from skydelsdx.units import Ecef
from skydelsdx.units import Attitude
from skydelsdx.units import toRadian
import csv
import sys
import codecs

def readRow(row):
  # Each row has [Time, X (km), Y (km), Z (km), Yaw (deg), Pitch (deg), Roll (deg)] as string
  time = datetime.strptime(row[0], '%d %b %Y %H:%M:%S.%f')
  x = float(row[1]) * 1000
  y = float(row[2]) * 1000
  z = float(row[3]) * 1000
  yaw = toRadian(float(row[4]))
  pitch = toRadian(float(row[5]))
  roll = toRadian(float(row[6]))
  xyz = Ecef(x, y, z)
  ypr = Attitude(yaw, pitch, roll)
  yield time
  yield xyz
  yield ypr

#timedelta.total_seconds() (line 63) need Python 2.7 and above
assert sys.version_info >= (2,7)

sim = skydelsdx.RemoteSimulator(True)
sim.connect()

sim.call(New(True))
# Change configuration before starting the simulation
sim.call(SetModulationTarget("NoneRT", "", "", True, "uniqueId"))
sim.call(ChangeModulationTargetSignals(0, 12500000, 100000000, "UpperL", "L1CA", -1, False, "uniqueId"))
sim.call(SetGpsStartTime(datetime(2021, 2, 15, 7, 0, 0)))
sim.call(SetVehicleTrajectory("Track"))

sim.beginTrackDefinition()

startTime = 0
print("Reading " + FILE_PATH)
with codecs.open(FILE_PATH, 'rb', encoding="UTF-8") as f:
  reader = csv.reader(f)
  field_names = next(reader) # Skip first line: CSV Header
  for row in reader:
    time, xyz, ypr = readRow(row)
    elapsedTime = 0
    if startTime:
      elapsedTime = round((time-startTime).total_seconds() * 1000)  # elapsed time in msec since start of track
    else:
      startTime = time
    sim.pushTrackEcefNed(elapsedTime, xyz, ypr)

sim.endTrackDefinition()

sim.disconnect()
