#!/usr/bin/env python3

# This Python script imports a route from a csv file and sends it to Skydel.

# Before running this script, make sure Skydel is runnin and the splash screen is closed.

import skydelsdx
from skydelsdx.commands import New
from skydelsdx.commands import SetVehicleTrajectory

from skydelsdx.units import Lla
from skydelsdx.units import Ecef
from skydelsdx.units import toRadian

import os
import csv
import codecs
import sys

FILE_PATH = 'example_route_boat.csv'

def readRow(row):
  if len(row) < 4: raise StopIteration('Found invalid csv row at line %d' % (reader.line_num))
  # Each row has [Speed (m/s), Lat (deg), Lon (deg), Alt (m)] as string
  speed = float(row[0])
  lat = float(row[1])
  lon = float(row[2])
  alt = float(row[3])
  lla = Lla(toRadian(lat), toRadian(lon), alt)
  return [speed, lla]

if not os.path.isfile(FILE_PATH): 
  print('File not found', FILE_PATH)
  sys.exit(0)

positions = []

print("Reading " + FILE_PATH)

with codecs.open(FILE_PATH, 'rb', encoding="utf-8") as f:
  reader = csv.reader(f)
  field_names = next(reader) #Read CSV Header
 
  for row in reader:
    position = readRow(row)
    positions.append(position)  
    
sim = skydelsdx.RemoteSimulator()
sim.setVerbose(True)
sim.connect()

sim.call(SetVehicleTrajectory("Route"))

sim.beginRouteDefinition()

for i in range(len(positions)):
  speed = positions[i][0]
  lla = positions[i][1]
  print("{0}: {1}, {2}m/s".format(i, lla, speed))
  sim.pushRouteLla(speed, lla)
    
count = sim.endRouteDefinition()

sim.disconnect()
    
