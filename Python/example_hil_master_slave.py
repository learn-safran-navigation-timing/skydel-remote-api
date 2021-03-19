#!/usr/bin/python
import sys
import time
import skydelsdx
from skydelsdx.units import *
from skydelsdx.commands import *


target = "NoneRT"
#target = "X300"
masterX300IP = "192.168.40.2"
slaveX300IP  = "192.168.50.2"

masterIP = "127.0.0.1"
masterInstanceID = 0
slaveIP = "127.0.0.1"
slaveInstanceID = 1
masterPort = 4567


def checkMasterConnection(sim, nbSlaveExpected):
  getMasterStatusResult = sim.call(GetMasterStatus())
  #print("isMaster : ", str(getMasterStatusResult.isMaster()))
  #print("Nb Slaves: ", str(getMasterStatusResult.slaveConnected()))
  #print("Port     : ", str(getMasterStatusResult.port()))
  if not getMasterStatusResult.isMaster():
    raise RuntimeError("Simulator is not Master")
  if getMasterStatusResult.slaveConnected() != nbSlaveExpected:
    raise RuntimeError("Only " + str(getMasterStatusResult.slaveConnected()) + ", while " + str(nbSlaveExpected) + " were expected")


def checkSlaveConnection(sim):
  getSlaveStatusResult = sim.call(GetSlaveStatus())
  #print("IsSlave    : " + str(getSlaveStatusResult.isSlave()))
  #print("IsConnected: " + str(getSlaveStatusResult.isConnected()))
  #print("Host Name  : " + str(getSlaveStatusResult.hostName()))
  #print("Host Port  : " + str(getSlaveStatusResult.hostPort()))
  if getSlaveStatusResult.isSlave() == False:
    raise RuntimeError("Simulator is not Slave")
  if getSlaveStatusResult.isConnected() == False:
    raise RuntimeError("Simulator is not Connected")


def runTest():
      print("Connecting to Master Skydel...")
    
      simMaster = skydelsdx.RemoteSimulator() 
      simMaster.connect(masterIP, masterInstanceID)
      simMaster.call(New(True)) 
      simMaster.call(SetSyncServer(masterPort))
      simMaster.call(EnableMasterPps(True))
    
      print("Connecting to Slave Skydel...")
      simSlave = skydelsdx.RemoteSimulator() 
      simSlave.connect(slaveIP, slaveInstanceID)
      simSlave.call(New(True)) 
      simSlave.call(SetSyncClient(masterIP, masterPort))
      simSlave.call(EnableSlavePps(True))
    
      print("Configure Master Skydel...")
      simMaster.call(SetModulationTarget(target, "", masterX300IP, True, "MasterUniqueId"))
      simMaster.call(ChangeModulationTargetSignals(0, 25000000, 100000000, "UpperL", "L1CA", -1, False, "MasterUniqueId"))
      simMaster.call(SetVehicleTrajectory("HIL"))
    
      print("Configure Slave Skydel...")
      simSlave.call(SetModulationTarget(target, "", slaveX300IP, True, "SlaveUniqueID"))
      simSlave.call(ChangeModulationTargetSignals(0, 25000000, 100000000, "UpperL", "L1CA", -1, False, "SlaveUniqueID"))
      simSlave.call(SetVehicleTrajectory("HIL"))
    
      checkMasterConnection(simMaster, 1)
      checkSlaveConnection(simSlave)

      print("Init H/W and Arm system for PPS synchronization")
      simMaster.call(ArmPPS())
    
      print("Wait for next PPS signal, and Reset Time to 0 on next PPS")
      simMaster.call(WaitAndResetPPS())
    
      print("Start Simulation when PPS reaches 10 ticks")
      simMaster.call(StartPPS(10000))
      
      originMaster    = Lla(toRadian(45.0), toRadian(-74.0), 1.0)
      nextMasterPos   = originMaster
      deltaPosMaster  = Enu(0.01, 0, 0) # This will give a speed of 10m/s, going East.
    
      originSlave     = Lla(toRadian(45.001), toRadian(-74.0), 1.0)
      nextSlavePos    = originMaster
      deltaPosSlave   = Enu(0.01, 0, 0) # This will give a speed of 10m/s, going East.
    
      simDurationMs   = 60*1000
      curTimeToPushMs = 0
      curSimTimeMs    = 0
      
      try:
        while curTimeToPushMs < simDurationMs:
          print("Simulation elapsed Time: " + str(curSimTimeMs) + " ms")
          if (curTimeToPushMs - curSimTimeMs) < 1000:
            print("Pushing 1000 positions")
            curPos = 0
            while curPos < 1000:
              nextMasterPos = nextMasterPos.addEnu(deltaPosMaster)
              simMaster.pushLla(curTimeToPushMs, nextMasterPos)
              nextSlavePos = nextSlavePos.addEnu(deltaPosSlave)
              simSlave.pushLla(curTimeToPushMs, nextSlavePos)
              
              curTimeToPushMs += 1
              curPos += 1
          else:
            sleepTimeS = ((curTimeToPushMs - curSimTimeMs) - 300.0) / 1000.0
            if sleepTimeS > 0:
              print("Sleeping for: " + str(sleepTimeS) + " secs.")
              time.sleep(sleepTimeS)
          simElaspedTime = simMaster.call(GetSimulationElapsedTime())
          curSimTimeMs = simElaspedTime.milliseconds()
      except Exception as e:
        print("Exception during simulation: " + str(e))

      print("Stopping simulation when at simulation time = " + str(simDurationMs) + " ms")
      simMaster.stop(simDurationMs/1000.0)

      simMaster.disconnect()
      simSlave.disconnect()

         
def main(argv):
  runTest()


if __name__ == "__main__":
  main(sys.argv[1:])


