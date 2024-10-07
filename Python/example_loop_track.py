#!/usr/bin/env python3

FILE_PATH = 'circle_100Hz.csv'
BLOCK_DURATION = 3000 # in ms

import os
import time
import skydelsdx
from skydelsdx.commands import *
from skydelsdx.units import *
import csv
import sys
import codecs

if not os.path.isfile(FILE_PATH): 
  print('Please execute "python example_generate_circle_csv.py 100" before to generate' + FILE_PATH)
  sys.exit(0)

# We parse the csv track file
track = []
print("Reading " + FILE_PATH)
with codecs.open(FILE_PATH, 'rb', encoding="utf-8") as f:
  reader = csv.reader(f)
  field_names = next(reader) # Skip first line: CSV Header
  for row in reader:
    track.append((int(row[0]), Lla(toRadian(float(row[1])), toRadian(float(row[2])), float(row[3]))))

duration = track[-1][0] - track[0][0]
print("Track duration: " + str(duration) + "ms")

if track[0][1] != track[-1][1]:
  print("Different start and end point: {} vs {}".format(track[0][1], track[-1][1]))
track = track[:-1]

# This function extract a block of blockDuration ms from the track and set the right timestamp

def getTrackBlock(elapsed, blockDuration, track, trackDuration):
  i = 0
  j = 0
  while j < len(track) and track[j][0] < (elapsed % trackDuration):
    j += 1
  if j >= len(track):
    j = 0
  ref = track[j][0]
  while True:
    i = track[j][0] - ref
    if i < 0:
      i += trackDuration
    if i >= blockDuration:
      break
    yield (elapsed + i, track[j][1])
    j += 1
    if j >= len(track):
      j = 0


# Connect to Skydel
sim = skydelsdx.RemoteSimulator(True)
sim.connect()

sim.call(New(True))
# Change configuration before starting the simulation
sim.call(SetModulationTarget("NoneRT", "", "", True, "uniqueId"))
sim.call(ChangeModulationTargetSignals(0, 12500000, 100000000, "UpperL", "L1CA", -1, False, "uniqueId"))

# We use HIL to control the vehicle
sim.call(SetVehicleTrajectory("HIL"))

# Starting the simulation, it will actually wait until the first position is pushed
sim.start()

iteration = 0
# This loop can be stop by doing a KeyboardInterrupt (Ctrl+C) or by stopping the simulation on Skydel
try:
  while iteration < 100:
    print("Iteration " + str(iteration))
    # We push the next block
    for t, pos in getTrackBlock(iteration * BLOCK_DURATION, BLOCK_DURATION, track, duration):
      sim.pushLla(t, pos)
    # We wait until we are one block away from the next block
    while sim.call(GetSimulationElapsedTime()).milliseconds() / BLOCK_DURATION < iteration:
      time.sleep(0.1)
    iteration += 1
except BaseException as e:
  print("Stopped: "+ str(e))

sim.stop()

sim.disconnect()
