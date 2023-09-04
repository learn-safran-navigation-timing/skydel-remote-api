#!/usr/bin/env python3

# This Python script illustrates how to create a car route with speed limits and a car track
# and enables automatic stop when the car reach the end of the route or track.

# Before running this script, make sure Skydel is runnin and the splash screen is closed.

import skydelsdx
from skydelsdx.commands import New
from skydelsdx.commands import SetModulationTarget
from skydelsdx.commands import ChangeModulationTargetSignals
from skydelsdx.commands import SetVehicleTrajectory
from skydelsdx.commands import EnableSimulationStopAtTrajectoryEnd

from skydelsdx.units import Lla
from skydelsdx.units import toRadian


def pushRouteNode(sim, speedKmh, latDeg, lonDeg):
  #Push Route LLA in radian with speed in m/s
  sim.pushRouteLla(speedKmh/3.6, Lla(toRadian(latDeg), toRadian(lonDeg), 0));
  
def pushTrackNode(sim, timestampSec, latDeg, lonDeg):
  #Push Track LLA in radian with timestamp in ms
  sim.pushTrackLla(timestampSec*1000, Lla(toRadian(latDeg), toRadian(lonDeg), 0));

sim = skydelsdx.RemoteSimulator()
sim.setVerbose(True)
sim.connect()

# Create new config
sim.call(New(True)) 

# Change configuration before starting the simulation
sim.call(SetModulationTarget("None", "", "", True, "uniqueId"))
sim.call(ChangeModulationTargetSignals(0, 12500000, 100000000, "UpperL", "L1CA", -1, False, "uniqueId"))

#When enabled, the simulation will stop when the vehicle will reach its trajectory destination
sim.call(EnableSimulationStopAtTrajectoryEnd(True))

#Create Route
sim.call(SetVehicleTrajectory("Route"))
sim.beginRouteDefinition()
pushRouteNode(sim, 50.0, 42.719943, -73.830492)
pushRouteNode(sim, 60.0, 42.718110, -73.833439)
pushRouteNode(sim, 60.0, 42.717620, -73.832875)
sim.endRouteDefinition()

sim.start()
#Wait until the automatic stop happens when vehicle reaches route destination
sim.waitState("Ready")

#Create Track
sim.call(SetVehicleTrajectory("Track"))
sim.beginTrackDefinition()
pushTrackNode(sim, 0, 42.719943, -73.830492)
pushTrackNode(sim, 40, 42.718110, -73.833439)
pushTrackNode(sim, 45, 42.717620, -73.832875)
sim.endTrackDefinition()

sim.start()
#Wait until the automatic stop happens when vehicle reaches track destination
sim.waitState("Ready")

sim.disconnect()
    
