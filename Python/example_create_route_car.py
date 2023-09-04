#!/usr/bin/env python3

# This Python script illustrates how to create a car route with speed limits for Skydel.

# Before running this script, make sure Skydel is runnin and the splash screen is closed.

import skydelsdx
from skydelsdx.commands import New
from skydelsdx.commands import SetVehicleTrajectory

from skydelsdx.units import Ecef
from skydelsdx.units import Lla
from skydelsdx.units import toRadian


def pushRouteNode(sim, speedKmh, latDeg, lonDeg):
  #Push Route LLA in radian with speed in m/s
  sim.pushRouteLla(speedKmh/3.6, Lla(toRadian(latDeg), toRadian(lonDeg), 0));

sim = skydelsdx.RemoteSimulator()
sim.setVerbose(True)
sim.connect()

sim.call(SetVehicleTrajectory("Route"))

sim.beginRouteDefinition()

pushRouteNode(sim, 50.0, 42.719943, -73.830492)
pushRouteNode(sim, 50.0, 42.718155, -73.833370)
pushRouteNode(sim, 60.0, 42.718110, -73.833439)
pushRouteNode(sim, 60.0, 42.717620, -73.832875)
pushRouteNode(sim, 60.0, 42.717296, -73.832508)
pushRouteNode(sim, 60.0, 42.716674, -73.831805)
pushRouteNode(sim, 60.0, 42.715545, -73.830511)
pushRouteNode(sim, 60.0, 42.715469, -73.830427)
pushRouteNode(sim, 60.0, 42.714831, -73.829695)
pushRouteNode(sim, 60.0, 42.714155, -73.828924)
pushRouteNode(sim, 60.0, 42.714200, -73.828803)
pushRouteNode(sim, 80.0, 42.714720, -73.827925)
pushRouteNode(sim, 80.0, 42.714759, -73.827850)
pushRouteNode(sim, 80.0, 42.714769, -73.827747)
pushRouteNode(sim, 80.0, 42.714752, -73.827672)
pushRouteNode(sim, 80.0, 42.714681, -73.827552)
pushRouteNode(sim, 80.0, 42.714338, -73.827183)
pushRouteNode(sim, 80.0, 42.713316, -73.826026)
pushRouteNode(sim, 60.0, 42.713257, -73.825929)
pushRouteNode(sim, 60.0, 42.713235, -73.825804)
pushRouteNode(sim, 60.0, 42.713235, -73.825693)
pushRouteNode(sim, 60.0, 42.713248, -73.825528)
pushRouteNode(sim, 60.0, 42.713708, -73.823088)
pushRouteNode(sim, 40.0, 42.713837, -73.823108)
pushRouteNode(sim, 40.0, 42.713902, -73.823097)
pushRouteNode(sim, 40.0, 42.713979, -73.823028)
pushRouteNode(sim, 40.0, 42.714546, -73.822143)
    
count = sim.endRouteDefinition()

sim.disconnect()
    
