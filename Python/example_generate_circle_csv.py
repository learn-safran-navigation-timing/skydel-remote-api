#!/usr/bin/env python3

# This Python script generates a circular trajectory into a csv file.
# The generated file can be used in example_hil_csv.py

import math
import sys
import time

import skydelsdx
from skydelsdx.units import Lla
from skydelsdx.units import Enu
from skydelsdx.units import Ecef
from skydelsdx.units import Attitude
from skydelsdx.units import toRadian
import csv
import codecs

class CircleTrajectory:
  LAT = 45.0
  LON = -74.0
  ALT = 1.0
  SPEED = 5    # m/s
  RADIUS = 50  # m
    
  def _generateEnu(self, elapsedTime):
    time = elapsedTime // 1000.0
    posOnCircle = time*CircleTrajectory.SPEED/CircleTrajectory.RADIUS
    e = math.cos(posOnCircle) * CircleTrajectory.RADIUS
    n = math.sin(posOnCircle) * CircleTrajectory.RADIUS
    return Enu(e, n, 0)

  def generateLla(self, duration, rate):
    print('Generating LLA circle trajectory for ' + str(duration) + ' seconds and a rate of ' + str(rate) +'Hz')
    origin = Lla(toRadian(CircleTrajectory.LAT), toRadian(CircleTrajectory.LON), CircleTrajectory.ALT)
    
    elapsedTime = 0
    filename = 'circle_'+str(rate)+'Hz.csv'
    print('Creating file ' + filename)
    with codecs.open(filename, 'wb', encoding="utf-8") as csvfile:
      llawriter = csv.writer(csvfile, delimiter=',',quotechar='#', quoting=csv.QUOTE_MINIMAL)
      llawriter.writerow(['Timestamp (ms)','Latitude (deg)', 'Longitude (deg)', 'Altitude (m)'])
      # -- Sending positions --
      while 1 == 1:
        if elapsedTime > duration * 1000:
          break
        enu = self._generateEnu(elapsedTime)
        lla = origin.addEnu(enu)
        llawriter.writerow([str(elapsedTime), str(lla.latDeg()), str(lla.lonDeg()), str(lla.alt)])
        elapsedTime += 1000//rate
      
    #6-degree-of-freedom  
    elapsedTime = 0
    filename = 'circle_'+str(rate)+'Hz_6dof.csv'
    print('Creating file ' + filename)
    with codecs.open(filename, 'wb', encoding="utf-8") as csvfile:
      llawriter = csv.writer(csvfile, delimiter=',',quotechar='#', quoting=csv.QUOTE_MINIMAL)
      llawriter.writerow(['Timestamp (ms)','Latitude (deg)', 'Longitude (deg)', 'Altitude (m)','Yaw (deg)', 'Pitch (deg)', 'Roll (deg)'])
      # -- Sending positions --
      while 1 == 1:
        if elapsedTime > duration * 1000:
          return
        enu = self._generateEnu(elapsedTime)
        lla = origin.addEnu(enu)
        attitude = Attitude(-math.atan2(enu.north, enu.east), 0, toRadian(-5))
        llawriter.writerow([str(elapsedTime), str(lla.latDeg()), str(lla.lonDeg()), str(lla.alt), 
          str(attitude.yawDeg()), str(attitude.pitchDeg()), str(attitude.rollDeg())])
        elapsedTime += 1000//rate
        
    
  def generateEcef(self, duration, rate):
    print('Generating ECEF circle trajectory for ' + str(duration) + ' seconds and a rate of ' + str(rate) + 'Hz')
    origin = Lla(toRadian(CircleTrajectory.LAT), toRadian(CircleTrajectory.LON), CircleTrajectory.ALT)
    
    elapsedTime = 0
    filename = 'circle_'+str(rate)+'Hz_ecef.csv'
    print('Creating file ' + filename)
    with codecs.open(filename, 'wb', encoding="utf-8") as csvfile:
      ecefwriter = csv.writer(csvfile, delimiter=',',quotechar='#', quoting=csv.QUOTE_MINIMAL)
      ecefwriter.writerow(['Timestamp (ms)','X (m)', 'Y (m)', 'Z (m)'])
      # -- Sending positions --
      while 1 == 1:
        if elapsedTime > duration * 1000:
          break
        enu = self._generateEnu(elapsedTime)
        lla = origin.addEnu(enu)
        ecef = lla.toEcef()
        ecefwriter.writerow([str(elapsedTime), str(ecef.x), str(ecef.y), str(ecef.z)])
        elapsedTime += 1000//rate
      
    #6-degree-of-freedom  
    elapsedTime = 0
    filename = 'circle_'+str(rate)+'Hz_6dof_ecef.csv'
    print('Creating file '+ filename)
    with codecs.open(filename, 'wb', encoding="utf-8") as csvfile:
      ecefwriter = csv.writer(csvfile, delimiter=',',quotechar='#', quoting=csv.QUOTE_MINIMAL)
      ecefwriter.writerow(['Timestamp (ms)','X (m)', 'Y (m)', 'Z (m)','Yaw (deg)', 'Pitch (deg)', 'Roll (deg)'])
      # -- Sending positions --
      while 1 == 1:
        if elapsedTime > duration * 1000:
          return
        enu = self._generateEnu(elapsedTime)
        lla = origin.addEnu(enu)
        ecef = lla.toEcef()
        attitude = Attitude(-math.atan2(enu.north, enu.east), 0, toRadian(-5))
        ecefwriter.writerow([str(elapsedTime), str(ecef.x), str(ecef.y), str(ecef.z), 
          str(attitude.yawDeg()), str(attitude.pitchDeg()), str(attitude.rollDeg())])
        elapsedTime += 1000//rate

trajectory = CircleTrajectory()
duration = 100
rate = int(sys.argv[1]) if len(sys.argv) > 1 else 1000
trajectory.generateLla(duration,rate)
trajectory.generateEcef(duration,rate)
