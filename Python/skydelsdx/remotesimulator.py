#!/usr/bin/env python3

from .commandexception import CommandException
from .clientcmd import ClientCmd
from .clienthil import ClientHil
import sys
from .commands import *
from enum import Enum, auto

def spooferInstance(id):
  return 128 + id

class DeprecatedMessageMode(Enum):
  ALL = auto()
  LATCH = auto()
  NONE = auto()

class RemoteSimulator: 
  def __init__(self, exception_on_error=True):
    self.exception_on_error = exception_on_error
    self.client = None
    self.verbose = False
    self.hilStreamingCheckEnabled = True
    self.hil = None
    self._last_vehicle_info = None
    self.checkRunningTime = 0
    self.beginRoute = False
    self.beginTrack = False
    self.beginIntTxTrack = {}
    self._serverApiVersion = 0
    self.deprecatedMessageMode = DeprecatedMessageMode.LATCH
    self.latchDeprecated = set()
 
  def connect(self, ip = "localhost", id=0, failIfApiVersionMismatch=False):
    if self.isConnected():
      raise Exception("Cannot connect. Already connected. Disconnect first.");
    
    port = 4820 + id
    if self.verbose:
      print('Connecting to %s on port %s...' % (ip, port))
    self.client = ClientCmd(ip, port)
    
    self._serverApiVersion = self.client.getServerApiVersion()
    if ApiVersion != self._serverApiVersion:
      msg = "Client Api Version (" + str(ApiVersion) + ") != Server Api Version (" + str(self._serverApiVersion) + ")"
      if failIfApiVersionMismatch:
        raise Exception(msg)
      else:
        print("Warning: " + msg)
      
    hilPort = self._callCommand(GetHilPort()).port()
    self.hil = ClientHil(self.client.getAddress(), hilPort)
 
  def disconnect(self):
    self._checkConnect()
    if self.verbose: print('Commands Client Disconnecting')
    del self.client
    self.client = None
    del self.hil
    self.hil = None
    
  def setVerbose(self, verbose):
    self.verbose = verbose
    
  def isVerbose(self):
    return self.verbose

  def setHilStreamingCheckEnabled(self, hilStreamingCheckEnabled):
    self.hilStreamingCheckEnabled = hilStreamingCheckEnabled

  def isHilStreamingCheckEnabled(self):
    return self.hilStreamingCheckEnabled
    
  def isConnected(self):
    return self.client != None
    
  def clientApiVersion(self):
    return ApiVersion  
  
  def serverApiVersion(self):
    if self.isConnected():
      return self._serverApiVersion
    else:
      raise Exception("Server API Version unavailable. You must be connected to the server.")

  def _handleException(self, result):
    if self.exception_on_error and not result.isSuccess():
      stateResult = self._callCommand(GetSimulatorState())
      
      if stateResult.state() == "Error":
        simErrorMsg = "\nAn error occured during simulation:\n" + stateResult.error()
      else:
        simErrorMsg = ""
      raise CommandException(result, simErrorMsg)
      
    if self.verbose and not result.isSuccess():
      print(result.getRelatedCommand().getName() + " failed: "+ result.getMessage())

  def _resetTime(self):
    self.checkRunningTime = -99999999.9

  def arm(self):
    self._checkConnect()
    if self.verbose:
      print("Arming simulation...")
    
    if not self._callCommand(Arm()).isSuccess():
      if self.verbose:
        print("Failed to arm simulation.")
      return False
    self._resetTime()
    if self.verbose:
      print("Simulation armed.") 
    return True
      
  def start(self):
    self._checkConnect()
    if self.verbose:
      print("Starting simulation...")
    
    if not self._callCommand(Start()).isSuccess():
      if self.verbose:
        print("Failed to start simulation.")        
      return False
    
    self.hil.clearVehicleInfo()
    self._resetTime()

    if self.verbose:
      print("Simulation started.") 
      if self._callCommand(GetSimulatorState()).subStateId() == SimulatorSubState.Started_HILSync:
        print("Please send HIL positions...")
    return True
    
  def stop(self, timestamp=None):
    self._checkConnect()
    self._resetTime()
    
    stopCmd = self._postCommand(Stop(), timestamp)
 
    if timestamp != None and self.verbose:
      print("Stopping simulation at " +  str(timestamp) + " seconds...")
    
    self._waitCommand(stopCmd)
    
    if self.verbose: 
      print("Simulation stopped.")

  def _checkForbiddenPost(self, cmd):
    if cmd.getName() == "Start":
      raise Exception("You cannot send a Start command. Use RemoteSimulator.start() instead.")

  def _checkForbiddenCall(self, cmd):
    if cmd.getName() == "Start":
      raise Exception("You cannot send a Start command. Use RemoteSimulator.start() instead.")
    if cmd.getName() == "PushRouteEcef":
      raise Exception("You cannot call a PushRouteEcef command. Post it or use RemoteSimulator.pushRouteLla() or RemoteSimulator.pushRouteEcef() instead.")
    if cmd.getName() == "PushTrackEcef":
      raise Exception("You cannot call a PushTrackEcef command. Post it or use RemoteSimulator.pushTrackEcef() or RemoteSimulator.pushTrackLla() instead.")
    if cmd.getName() == "PushTrackEcefNed":
      raise Exception("You cannot call a PushTrackEcefNed command. Post it or use RemoteSimulator.pushTrackEcefNed() or RemoteSimulator.pushTrackLlaNed() instead.")
    if cmd.getName() == "PushIntTxTrackEcef":
      raise Exception("You cannot call a PushIntTxTrackEcef command. Post it or use RemoteSimulator.pushIntTxTrackEcef() or RemoteSimulator.pushIntTxTrackLla() instead.")
    if cmd.getName() == "PushIntTxTrackEcefNed":
      raise Exception("You cannot call a PushIntTxTrackEcefNed command. Post it or use RemoteSimulator.pushIntTxTrackEcefNed() or RemoteSimulator.pushIntTxTrackLlaNed() instead.")
  
  def checkIfStreaming(self):
    self._checkConnect()
    
    stateResult = self._callCommand(GetSimulatorState())
    
    if stateResult.state() == "Streaming RF":
      return True
    
    if stateResult.state() == "Error":
      errorMsg = "An error occured during simulation. Error message:\n" + stateResult.error()
    else:
      errorMsg = "Simulator is not running. Current state is " + stateResult.state() + "."
    if self.exception_on_error:
      raise Exception(errorMsg)
    if self.verbose: print(errorMsg)
    return False
    
  def waitState(self, state, failureState = ""):
    self._checkConnect()
    if self.verbose : print("Waiting for simulator state " + str(state) + "...")
      
    stateResult = self._callCommand(WaitSimulatorState(state, failureState))

    if stateResult.state() == state:
      return True
    elif stateResult.state() == "Error":
      errorMsg = "An error occured during simulation. Error message:\n" + stateResult.error() 
    else:
      errorMsg = "Wrong simulator state. Expected ", state, " but received ", stateResult.state()
      
    if self.exception_on_error:
      raise Exception(errorMsg)
    if self.verbose: 
      print(errorMsg)
    return False
    
  def _checkHil(self, pos, elapsedTime):
    if self.hil == None:
      raise Exception("Cannot send positions to simulator because you are not connected.")
    
    if self.checkRunningTime < 0.0:
      self.checkRunningTime = elapsedTime
      
    if elapsedTime - self.checkRunningTime >= 1000.0:
      self.checkRunningTime = elapsedTime
      if self.hilStreamingCheckEnabled and not self.checkIfStreaming(): 
        self._resetTime()
        return False
      if self.verbose: print(str(pos) + " sent at %2fms" % elapsedTime) 
    return True
  
  def _checkConnect(self):
    if not self.isConnected():
      raise Exception("You are not connected.")
  
  # Send Skydel an HIL timed position of the vehicle. The position is provided in the LLA coordinate system.
  #
  #  Parameter     Type              Units                            Description
  #  -------------------------------------------------------------------------------------------------------
  #  elapsedTime   double            milliseconds                     Time since the beginning of the simulation.
  #  position      LLA Object        lat (rad), long (rad), alt (m)   Position of the vehicle.
  #  dest          optional string                                    If empty, sends the position for the vehicle. 
  #                                                                   If set with a jammerID, sends the position for 
  #                                                                   the specified jammer's vehicle.
  #
  def pushLla(self, elapsedTime, lla, dest = ""):
    return self.pushEcef(elapsedTime, lla.toEcef(), dest = dest)

  # Send Skydel a timed ECEF-referenced position with the associated dynamics.
  #
  #  Parameter      Type                   Units            Description
  #  -------------------------------------------------------------------------------------------------------
  #  elapsedTime    double                 milliseconds     Time since the beginning of the simulation.
  #  position       Ecef Object            x, y, z (m)      Position of the vehicle.
  #  velocity       optional Ecef Object   x, y, z (m/s)    Velocity of the vehicle.
  #  acceleration   optional Ecef Object   x, y, z (m/s²)   Acceleration of the vehicle.
  #  jerk           optional Ecef Object   x, y, z (m/s³)   Jerk of the vehicle.
  #  dest           optional string)                        If empty, sends the position for the vehicle. 
  #                                                         If set with a jammerID, sends the position for 
  #                                                         the specified jammer's vehicle.
  #
  def pushEcef(self, elapsedTime, position, velocity = None, acceleration = None, jerk = None, dest = ""):
    self.hil.pushEcef(elapsedTime, position, velocity, acceleration, jerk, dest)
    return self._checkHil(position, elapsedTime)

  # Send Skydel an HIL timed position, orientation, and the associated dynamics of the vehicle. 
  # The position is provided in the ECEF coordinate system, while the body's orientation is specified relative
  # to the local NED reference frame.
  #
  #  Parameter             Type                       Units                       Description
  #  -------------------------------------------------------------------------------------------------------
  #  elapsedTime           double                     milliseconds                Time since the beginning of the simulation.
  #  position              Ecef Object                x, y, z (m)                 Position of the vehicle.
  #  attitude              Attitude Object            yaw, pitch, roll (rad)      Orientation of the vehicle's body.
  #  velocity              optional Ecef Object       x, y, z (m/s)               Velocity of the vehicle.
  #  angularVelocity       optional Attitude Object   yaw, pitch, roll(rad/s)     Rotational velocity of the vehicle's body.
  #  acceleration          optional Ecef Object       x, y , z (m/s²)             Acceleration of the vehicle.
  #  angularAcceleration   optional Attitude Object   yaw, pitch, roll (rad/s²)   Rotational acceleration of the vehicle's body.
  #  jerk                  optional Ecef Object       x, y, z (m/s³)              Jerk of the vehicle.
  #  angularJerk           optional Attitude Object   yaw, pitch, roll (rad/s³)   Rotational jerk of the vehicle's body.
  #  dest                  optional string                                        If empty, sends the position for the vehicle. 
  #                                                                               If set with a jammerID, sends the position for 
  #                                                                               the specified jammer's vehicle.
  #
  def pushEcefNed(self, elapsedTime, position, attitude, velocity = None, angularVelocity = None, acceleration = None, angularAcceleration = None, jerk = None, angularJerk = None, dest = ""):
    self.hil.pushEcefNed(elapsedTime, position, attitude, velocity, angularVelocity, acceleration, angularAcceleration, jerk, angularJerk, dest)
    return self._checkHil(str(position)+", "+str(attitude), elapsedTime)

  # Send Skydel an HIL timed position and orientation of the vehicle. 
  # The position is provided in the LLA coordinate system, while the body's orientation is specified relative 
  # to the local NED reference frame.
  #
  #  Parameter     Type              Units                            Description
  #  -------------------------------------------------------------------------------------------------------
  #  elapsedTime   double            milliseconds                     Time since the beginning of the simulation.
  #  position      LLA Object        lat (rad), long (rad), alt (m)   Position of the vehicle.
  #  attitude      Attitude Object   yaw, pitch, roll (rad)           Orientation of the vehicle's body.
  #
  def pushLlaNed(self, elapsedTime, lla, attitude):
    return self.pushEcefNed(elapsedTime, lla.toEcef(), attitude)
  
  def beginRouteDefinition(self):
    self._checkConnect()
    self.beginRoute = self._callCommand(BeginRouteDefinition())
    if self.verbose: 
      print("Begin Route Definition...")
    return self.beginRoute

  def beginTrackDefinition(self):
    self._checkConnect()
    self.beginTrack = self._callCommand(BeginTrackDefinition())
    if self.verbose: 
      print("Begin Track Definition...")
    return self.beginTrack
    
  def pushRouteEcef(self, speed, ecef):
    self._checkConnect()
    if not self.beginRoute:
      raise Exception("You must call beginRouteDefinition first.")

    if speed <= 0:
      raise Exception("A route node must have a speed limit greater than zero.")
      
    self._postCommand(PushRouteEcef(speed, 
      ecef.x, ecef.y, ecef.z))
    return True
    
  def pushTrackEcef(self, elapsedTime, ecef):
    self._checkConnect()
    if not self.beginTrack:
      raise Exception("You must call beginTrackDefinition first.")
      
    self._postCommand(PushTrackEcef(elapsedTime, 
      ecef.x, ecef.y, ecef.z))
    return True
    
  def pushTrackEcefNed(self, elapsedTime, ecef, attitude):
    self._checkConnect()
    if not self.beginTrack:
      raise Exception("You must call beginTrackDefinition first.")
      
    self._postCommand(PushTrackEcefNed(elapsedTime, 
      ecef.x, ecef.y, ecef.z, attitude.yaw, attitude.pitch, attitude.roll))
    return True
    
  def pushRouteLla(self, speed, lla):
    return self.pushRouteEcef(speed, lla.toEcef())
    
  def pushTrackLla(self, elapsedTime, lla):
    return self.pushTrackEcef(elapsedTime, lla.toEcef())
    
  def pushTrackLlaNed(self, elapsedTime, lla, attitude):
    return self.pushTrackEcefNed(elapsedTime, lla.toEcef(), attitude)

  def endRouteDefinition(self):
    self._checkConnect()
    if not self.beginRoute:
      raise Exception("You must call beginRouteDefinition first.")
    self.beginRoute = None
    
    routeResult = self._callCommand(EndRouteDefinition())
    
    if not routeResult.isSuccess():
      return 0
    
    if self.verbose: 
      print("End route contains " + str(routeResult.count()) + " nodes.")
      
    return routeResult.count()
  
  def endTrackDefinition(self):
    self._checkConnect()
    if not self.beginTrack:
      raise Exception("You must call beginTrackDefinition first.")
    self.beginTrack = None
    
    trackResult = self._callCommand(EndTrackDefinition())
    
    if not trackResult.isSuccess():
      return 0
    
    if self.verbose: 
      print("End route contains " + str(trackResult.count()) + " nodes.")
      
    return trackResult.count()

  def beginIntTxTrackDefinition(self, id):
    self._checkConnect()
    self.beginIntTxTrack[id] = self._callCommand(BeginIntTxTrackDefinition(id))
    if self.verbose: 
      print("Begin Transmitter Track Definition...")
    return self.beginIntTxTrack[id]
    
  def pushIntTxTrackEcef(self, elapsedTime, ecef, id):
    self._checkConnect()
    if not self.beginIntTxTrack[id]:
      raise Exception("You must call beginIntTxTrackDefinition first.")
      
    self._postCommand(PushIntTxTrackEcef(elapsedTime, 
      ecef.x, ecef.y, ecef.z, id))
    return True
    
  def pushIntTxTrackEcefNed(self, elapsedTime, ecef, attitude, id):
    self._checkConnect()
    if not self.beginIntTxTrack[id]:
      raise Exception("You must call beginIntTxTrackDefinition first.")
      
    self._postCommand(PushIntTxTrackEcefNed(elapsedTime, 
      ecef.x, ecef.y, ecef.z, attitude.yaw, attitude.pitch, attitude.roll, id))
    return True
    
  def pushIntTxTrackLla(self, elapsedTime, lla, id):
    return self.pushIntTxTrackEcef(elapsedTime, lla.toEcef(), id)
    
  def pushIntTxTrackLlaNed(self, elapsedTime, lla, attitude, id):
    return self.pushIntTxTrackEcefNed(elapsedTime, lla.toEcef(), attitude, id)
  
  def endIntTxTrackDefinition(self, id):
    self._checkConnect()
    if not self.beginIntTxTrack[id]:
      raise Exception("You must call beginIntTxTrackDefinition first.")
    self.beginIntTxTrack[id] = None
    
    trackResult = self._callCommand(EndIntTxTrackDefinition(id))
    
    if not trackResult.isSuccess():
      return 0
    
    if self.verbose: 
      print("End transmitter track contains " + str(trackResult.count()) + " nodes.")
	  
    return trackResult.count()
  
  def _callCommand(self, cmd, timestamp=None):
    self._postCommand(cmd, timestamp)
    return self._waitCommand(cmd)
  
  def _postCommand(self, cmd, timestamp=None):
    deprecated = cmd.deprecated()
    if deprecated and (self.deprecatedMessageMode == DeprecatedMessageMode.ALL or (self.deprecatedMessageMode == DeprecatedMessageMode.LATCH and cmd.getName() not in self.latchDeprecated)):
      print(f"Warning: {deprecated}")
      self.latchDeprecated.add(cmd.getName())
    if timestamp != None: 
      cmd.setTimestamp(timestamp) 
    self.client.sendCommand(cmd)
    return cmd
    
  def _waitCommand(self, cmd):
    result = self.client.waitCommand(cmd)
    self._handleException(result)
    return result
  
  def post(self, cmd, timestamp=None):
    self._checkConnect()
    self._checkForbiddenPost(cmd)
    if self.verbose:
      print("Post " + cmd.toString())
    self._postCommand(cmd, timestamp)
    return cmd
  
  def wait(self, cmd):
    self._checkConnect()
    if self.verbose:
      sys.stdout.write("Wait " + cmd.toString())
      sys.stdout.flush()
    result = self._waitCommand(cmd)
    if self.verbose:
      print(" => " + result.getMessage())
    return result
    
  def call(self, cmd, timestamp=None):
    self._checkConnect()
    self._checkForbiddenCall(cmd)
    self._postCommand(cmd, timestamp)
    if self.verbose:
      sys.stdout.write("Call " + cmd.toString())
      sys.stdout.flush()
   
    result = self._waitCommand(cmd)
    if self.verbose:
      print(" => " + result.getMessage())
    return result

  def beginVehicleInfo(self):
    return self.call(BeginVehicleInfo())

  def endVehicleInfo(self):
    return self.call(EndVehicleInfo())

  def hasVehicleInfo(self):
    pos = self.hil.pollVehicleInfo()
    if pos is not None:
      self._last_vehicle_info = pos
      return True
    return False
    
  def nextVehicleInfo(self):
    while self._last_vehicle_info is None:
      self.hasVehicleInfo()
    sent = self._last_vehicle_info
    self._last_vehicle_info = None
    return sent

  def lastVehicleInfo(self):
    while self.hasVehicleInfo():
      pass
    return self.nextVehicleInfo()

  def setDeprecatedMessageMode(self, mode):
    self.deprecatedMessageMode = mode
    self.latchDeprecated.clear()


class RemoteSpooferSimulator(RemoteSimulator):
  def connect(self, ip = "localhost", id = 1, failIfApiVersionMismatch = False):
    RemoteSimulator.connect(self, ip, spooferInstance(id), failIfApiVersionMismatch)
