#!/usr/bin/python

# This Python script transmits a csv file as the HIL trajectory to Skydel.

# The script will send positions until it is one (1) second ahead of the
# simulator. Once it is one second ahead, it will throttle the transmission of
# next positions to stay 1 second ahead, and no more. Pay attention to how the
# script reads the system time after the sleep. The algorithm compensates for
# sleep duration variability.

# Before running this script, make sure Skydel is runnin and the splash screen is closed.

# You must execute "example_generate_circle_6dof_csv.py" before to generate the csv
# file used in this example.

import skydelsdx
from skydelsdx.commands import New
from skydelsdx.commands import SetModulationTarget
from skydelsdx.commands import ChangeModulationTargetSignals
from skydelsdx.commands import SetVehicleTrajectory
from skydelsdx.commands import Start
from skydelsdx.commands import Stop
from skydelsdx.commands import EnableLogRaw

from skydelsdx.units import Lla
from skydelsdx.units import Attitude
from skydelsdx.units import toRadian

import os
import sys
import csv
import time
import codecs

FILE_PATH = 'circle_1000Hz_6dof.csv'
BUFFER_DURATION = 1000 # The script will try to stay 1000 ms ahead of the simulator
BATCH_DURATION = 200   # Sleep duration should not exceed 10-20% of BUFFER_DURATION

# Returns csv timestamp
def readRow(row):
  if len(row) < 7: raise StopIteration('Found invalid csv row at line %d' % (reader.line_num))
  # Each row has [Timestamp (ms), Lat (deg), Lon (deg), Alt (m), Yaw (deg), Pitch (deg), Roll (deg)] as string
  timestamp = int(row[0])
  lat = float(row[1])
  lon = float(row[2])
  alt = float(row[3])
  yaw = float(row[4])
  pitch = float(row[5])
  roll = float(row[6])
  lla = Lla(toRadian(lat), toRadian(lon), alt)
  attitude = Attitude(toRadian(yaw), toRadian(pitch), toRadian(roll))
  yield timestamp
  yield lla
  yield attitude

if not os.path.isfile(FILE_PATH): 
  print('Please execute "example_generate_circle_csv.py" before to generate' + FILE_PATH)
  sys.exit(-1)

sim = skydelsdx.RemoteSimulator()
sim.connect()

# Create new config
# Note: It is not necessary to create a new config if the simulator already has
#       a config with all the settings you want to test. Creating a new config
#       ensures we are in a known state.
sim.call(New(True))

# Change configuration to HIL before starting the simulation
sim.call(SetVehicleTrajectory("HIL"))

# Change configuration before starting the simulation
sim.call(SetModulationTarget("NoneRT", "", "", True, "uniqueId"))
sim.call(ChangeModulationTargetSignals(0, 12500000, 100000000, "UpperL", "L1CA", -1, False, "uniqueId"))
sim.call(EnableLogRaw(True))

sim.start()


print("Reading " + FILE_PATH)
with codecs.open(FILE_PATH, 'rb', encoding="utf-8") as f:
  reader = csv.reader(f)
  field_names = next(reader) #Read CSV Header
  
  targetCsvTimeStamp = BUFFER_DURATION
  startTime = time.time()
  csvTimestamp = 0
  lla = None
  eof = False
  
  while not eof:
    pushCount = 0
    while not eof:
      if csvTimestamp >= targetCsvTimeStamp:
        break
      if lla is not None:
        sim.pushLlaNed(csvTimestamp, lla, attitude)
        pushCount += 1
        lla = None
      try: 
        row = next(reader)
        csvTimestamp, lla, attitude = readRow(row)
      except StopIteration: 
        eof = True
    if pushCount > 0: print(str(pushCount) + " positions pushed")
    time.sleep(BATCH_DURATION/1000.0)
    elapsedTime = (time.time() - startTime) * 1000
    targetCsvTimeStamp = elapsedTime + BUFFER_DURATION
    
posCount = reader.line_num-1
print("A total of " + str(posCount) + " positions have been sent to the simulator")
print("Stopping simulation at " + str(csvTimestamp) + "ms")
sim.stop(csvTimestamp/1000.0)
sim.disconnect()
    
