#!/usr/bin/env python3

# This Python script illustrates how to send the receiver trajectory in real-time 
# using the hardware-in-the-loop (HIL) feature in MainInstance/WorkerInstance mode.
#
# Before running this script, make sure Skydel is running, and the splash screen is closed.
#
# There are two modes of operation with this script:
#
#   1 - You run this script on the same PC as Skydel, and haven't setup time synchronization
#       between the computer system time and the PPS signal driving your radio (or you run in NoneRT).
#       
#       This is the default use case (when the variable isOsTimeSyncWithPPS is False), it exists
#       to allow users to quickly and easily test HIL without having to set up time synchronization.
#       Note that if you use this mode with a radio, the time will drift between this script and 
#       the Skydel's simulation over time.
#
#   2 - You run this script on any PC which has it's time synchronized with the radio PPS signal.
#       
#       This is the recommended use case (when the variable isOsTimeSyncWithPPS is True).
#       We recommend using a time server, such as the SecureSync 2400 to provide the 10Mhz
#       and the PPS reference to the radio. The SecureSync is also a PTP server that can 
#       synchronize your computer system clock with the PPS to a high degree of precision.
#       In this mode, there will be no time drift between the script and the Skydel's simulation.
#
# Additional note: the script doesn't change the Skydel's engine latency by default,
# as this is a system wide preference. To set the preference, you can uncomment the line
# in the script. We recommend you set it back to the default value of 200ms once you are done
# using this script, unless you only plan to do low latency HIL on this machine.

import sys
import skydelsdx

from skydelsdx.commands import *
from example_hil_helper import *


def checkMainInstanceConnection(sim, nbWorkerInstanceExpected):
  getMainInstanceStatusResult = sim.call(GetMainInstanceStatus())

  # trying to wait few seconds expecting connection may not be set up yet.
  if not getMainInstanceStatusResult.isMainInstance() or getMainInstanceStatusResult.workerInstanceConnected() != nbWorkerInstanceExpected:
    time.sleep(1)
    getMainInstanceStatusResult = sim.call(GetMainInstanceStatus())

  if not getMainInstanceStatusResult.isMainInstance():
    raise RuntimeError("Simulator is not MainInstance")
  if getMainInstanceStatusResult.workerInstanceConnected() != nbWorkerInstanceExpected:
    raise RuntimeError("Only {0} connection, while {1} worker instance connections were expected".format(getMainInstanceStatusResult.workerInstanceConnected(), nbWorkerInstanceExpected))


def checkWorkerInstanceConnection(sim):
  getWorkerInstanceStatusResult = sim.call(GetWorkerInstanceStatus())

  if getWorkerInstanceStatusResult.isWorkerInstance() == False:
    raise RuntimeError("Simulator is not WorkerInstance")
  if getWorkerInstanceStatusResult.isConnected() == False:
    raise RuntimeError("Simulator is not Connected")


def setupSimulator(skydelIpAddress, simInstanceID, skydelEngineLatencyMs, hilTjoin, radioType, radioAddress, uniqueRadioId):
  sim = skydelsdx.RemoteSimulator()
  sim.setVerbose(True)
  sim.connect(skydelIpAddress, simInstanceID)

  # Check the engine latency (Skydel's system wide preference)
  if sim.call(GetEngineLatency()).latency() != skydelEngineLatencyMs:
    #sim.call(SetEngineLatency(skydelEngineLatencyMs))  # Uncomment this line to set the engine latency preference
    error("Please execute the SetEngineLatency({0}) command or change the skydelEngineLatencyMs value before executing this script.".format(skydelEngineLatencyMs))

  # Check the streaming buffer preference, do not change it from its default value
  if sim.call(GetStreamingBuffer()).size() != 200:
    error("Please do not change the Streaming Buffer preference.")

  # Uncomment these lines if you do very low latency HIL, as these features can impact Skydel's performance (Skydel's system wide preferences)
  # sim.call(ShowMapAnalysis(False))
  # sim.call(SetSpectrumVisible(False))

  # Create new config, ignore the default config if it's set
  sim.call(New(True, False))

  # Change the output
  sim.call(SetModulationTarget(radioType, "", radioAddress if radioType in ["X300", "N310"] else "", True, uniqueRadioId))
  sim.call(ChangeModulationTargetSignals(0, 12500000, 100000000, "UpperL", "L1CA", -1, False, uniqueRadioId))

  # Enable some logging
  sim.call(EnableLogRaw(False))  # You can enable raw logging and compare the logs (the receiver position is especially helpful)
  sim.call(EnableLogHILInput(False))  # This will give you exactly what Skydel has received through the HIL interface

  # Change the vehicle's trajectory to HIL
  sim.call(SetVehicleTrajectory("HIL"))

  # HIL Tjoin is a volatile parameter that must be set before every HIL simulation
  sim.call(SetHilTjoin(hilTjoin))

  # The streaming check is performed at the end of pushEcefNed. It's recommended to disable this check 
  # and do it asynchronously outside of the while loop when sending positions at high frequencies.
  sim.setHilStreamingCheckEnabled(True)

  return sim


# Change these as required
mainInstanceTrajectory = StraightTrajectory(speed=10.0)
workerInstanceTrajectory = StraightTrajectory(speed=10.0, latDeg=45.001)
simDurationMs = 60000
syncDurationMs = 2000
uniqueRadioId = "uniqueId"

# Can be "NoneRT", "DTA-2115B", "X300" or "N310", but don't combine NoneRT with a radio type for time synchronization
mainInstanceRadioType = "NoneRT" 
workerInstanceRadioType = "NoneRT"

# If this script isn't running on the same PC as the Skydel instances, set to the Skydel instances IP addresses
mainInstanceIpAddress = "127.0.0.1"
workerInstanceIpAddress = "127.0.0.1"
mainInstanceInstanceId = 0
workerInstanceInstanceId = 1
mainInstancePort = 4567

# Set to True if the computer which runs this script has it's time synchronized with the output radio PPS
isOsTimeSyncWithPPS = False

if (mainInstanceIpAddress != "127.0.0.1" or workerInstanceIpAddress != "127.0.0.1") and not isOsTimeSyncWithPPS:
  error("Can't run this script on a different computer if the OS time isn't in sync with the radios PPS.")

# Specific to X300 and N310 make sure these addresses points to your USRPs
mainInstanceRadioAddress = "192.168.40.2" 
workerInstanceRadioAddress  = "192.168.50.2"

# We suggest these values as a starting point, but they will have to be modified according 
# to your hardware, the configuration of the simulation and your requirements.
# Use the performance graph as well as the HIL graph to monitor Skydel and diagnose issues.
# It is strongly recommended to read the user manual before you try to optimize those settings.
timeBetweenPosMs = 15  # Send receiver position every 15 milliseconds
skydelEngineLatencyMs = 40  # How much in advance can Skydel be versus the radio time
hilTjoin = 65  # This value should be greater than skydelEngineLatencyMs + timeBetweenPosMs + network latency

# Setup mainInstance simulator
simMainInstance = setupSimulator(mainInstanceIpAddress, mainInstanceInstanceId, skydelEngineLatencyMs, hilTjoin, mainInstanceRadioType, mainInstanceRadioAddress, uniqueRadioId)
simMainInstance.call(SetSyncServer(mainInstancePort))
simMainInstance.call(EnableMainInstanceSync(True))

# Setup worker instance simulator
simWorkerInstance = setupSimulator(workerInstanceIpAddress, workerInstanceInstanceId, skydelEngineLatencyMs, hilTjoin, workerInstanceRadioType, workerInstanceRadioAddress, uniqueRadioId)
simWorkerInstance.call(SetSyncClient(mainInstanceIpAddress, mainInstancePort))  
simWorkerInstance.call(EnableWorkerInstanceSync(True))

# check connection between worker instance and main instance
checkMainInstanceConnection(simMainInstance, 1)
checkWorkerInstanceConnection(simWorkerInstance)

# From here we want to make sure to stop the simulation if something goes wrong
try:

  # Arm the simulator, when this command returns, we can start synchronizing with the PPS
  simMainInstance.call(ArmPPS())

  # The WaitAndResetPPS command returns immediately after a PPS signal, which is our PPS reference (PPS0)
  simMainInstance.call(WaitAndResetPPS())

  # If our PC clock is synchronized with the PPS, the nearest rounded second is the PPS0
  if isOsTimeSyncWithPPS:
    pps0TimestampMs = getClosestPpsTimeMs()

  # The command StartPPS will start the simulation at PPS0 + syncDurationMs
  # You can synchronize with your HIL simulation start, by changing the value of syncDurationMs (resolution in milliseconds)
  simMainInstance.call(StartPPS(syncDurationMs))

  # If the PC clock is NOT synchronized with the PPS, we can ask Skydel to tell us the PC time corresponding to PPS0
  if not isOsTimeSyncWithPPS:
    pps0TimestampMs = simMainInstance.call(GetComputerSystemTimeSinceEpochAtPps0()).milliseconds()

  # Compute the timestamp at the beginning of the simulation
  simStartTimestampMs = pps0TimestampMs + syncDurationMs

  # We send the first position outside of the loop, so initialize this variable for the second position
  nextTimestampMs = simStartTimestampMs + timeBetweenPosMs

  # Keep track of the simulation elapsed time in milliseconds
  elapsedMs = 0.0
  
  # Skydel must know the initial position of the receiver for initialization
  mainInstancePosition, mainInstanceVelocity = mainInstanceTrajectory.generateEcefWithDynamicsGoingEast(elapsedMs)
  workerInstancePosition, workerInstanceVelocity = workerInstanceTrajectory.generateEcefWithDynamicsGoingEast(elapsedMs)
  simMainInstance.pushEcef(elapsedMs, mainInstancePosition, mainInstanceVelocity)
  simWorkerInstance.pushEcef(elapsedMs, workerInstancePosition, workerInstanceVelocity)

  # Send positions in real time until the elapsed time reaches the desired simulation duration
  while elapsedMs <= simDurationMs:

    # Wait for the next position's timestamp
    preciseSleepUntilMs(nextTimestampMs)
    nextTimestampMs += timeBetweenPosMs

    # Get the current elapsed time in milliseconds
    elapsedMs = getCurrentTimeMs() - simStartTimestampMs

    # Generate the positions
    mainInstancePosition, mainInstanceVelocity = mainInstanceTrajectory.generateEcefWithDynamicsGoingEast(elapsedMs)
    workerInstancePosition, workerInstanceVelocity = workerInstanceTrajectory.generateEcefWithDynamicsGoingEast(elapsedMs)

    # Push the positions to Skydel
    simMainInstance.pushEcef(elapsedMs, mainInstancePosition, mainInstanceVelocity)
    simWorkerInstance.pushEcef(elapsedMs, workerInstancePosition, workerInstanceVelocity)

finally:
  # Stop the simulation
  simMainInstance.stop()

  # Disconnect from Skydel
  simMainInstance.disconnect()
  simWorkerInstance.disconnect()
