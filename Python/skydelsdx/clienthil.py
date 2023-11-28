#!/usr/bin/env python3

import socket
from .units import *
import struct
import datetime
from .client import Client

class MsgId:
  Hello = 1
  Bye = 2
  VehicleInfo = 3
  PushEcef = 5
  PushEcefNed = 6
  PushEcefDynamics = 7
  PushEcefNedDynamics = 8

class DynamicType:
  Velocity = 0
  Acceleration = 1
  Jerk = 2

class VehicleInfo:
  def __init__(self):
    self.elapsedTime = 0
    self.ecef = Ecef(0, 0, 0)
    self.attitude = Attitude(0, 0, 0)
    self.speed = 0
    self.heading = 0
    self.odometer = 0
  
class ClientHil(Client):
  def __init__(self, address, port):
    Client.__init__(self, address, port, False)
    self.sock.sendto(struct.pack('<B', MsgId.Hello), self.server_address)
   
  def _sendMessage(self, message):
    self.sock.sendto(message, self.server_address)
    
  def pollVehicleInfo(self):
    _start = datetime.datetime.now()
    sent = None
    oldTimeout = self.sock.gettimeout()
    self.sock.settimeout(0)
    try:
      result, addr = self.sock.recvfrom(255)
      id = result[0]
      if type(result[0]) != int:
          id = ord(result[0])
      if id == MsgId.VehicleInfo:
        sent = VehicleInfo()
        (sent.elapsedTime,
          sent.ecef.x, sent.ecef.y, sent.ecef.z,
          sent.attitude.yaw, sent.attitude.pitch, sent.attitude.roll,
          sent.speed, sent.heading, sent.odometer) = struct.unpack('<Qddddddddd', result[1:])
    except socket.timeout:
      pass
    except socket.error as e:
      if e.args[0] != socket.EWOULDBLOCK:
        raise
    self.sock.settimeout(oldTimeout)
    return sent
  
  def clearVehicleInfo(self):
    oldTimeout = self.sock.gettimeout()
    self.sock.settimeout(0)
    try:
      while True:
        result, addr = self.sock.recvfrom(255)
    except socket.timeout:
      self.sock.settimeout(oldTimeout)
    except socket.error as e:
      self.sock.settimeout(oldTimeout)
      if e.args[0] != socket.EWOULDBLOCK:
        raise
    except:
      self.sock.settimeout(oldTimeout)
      raise
   
  # Send Skydel a timed position, orientation, and the associated dynamics of the vehicle. 
  # The position is provided in the ECEF coordinate system, while the body's orientation is specified relative 
  # to the local NED reference frame.
  #
  #  Parameter      Type                   Units            Description
  #  -------------------------------------------------------------------------------------------------------
  #  elapsedTime    float                  milliseconds     Time since the beginning of the simulation.
  #  position       Ecef Object            x, y, z (m)      Position of the vehicle.
  #  velocity       optional Ecef Object   x, y, z (m/s)    Velocity of the vehicle.
  #  acceleration   optional Ecef Object   x, y, z (m/s²)   Acceleration of the vehicle.
  #  jerk           optional Ecef Object   x, y, z (m/s³)   Jerk of the vehicle.
  #  dest           optional string                         If empty, sends the position for the vehicle. 
  #                                                         If set with a jammerID, sends the position 
  #                                                         for the specified jammer's vehicle.
  #
  def pushEcef(self, elapsedTime, position, velocity, acceleration, jerk, dest):
    hasVelocity = velocity is not None
    hasAcceleration = hasVelocity and acceleration is not None 
    hasJerk = hasAcceleration and jerk is not None

    if (not hasVelocity and not hasAcceleration and not hasJerk):
      message = self._msgId2Packet(MsgId.PushEcef)
    else:
      message = self._msgId2Packet(MsgId.PushEcefDynamics)

    if hasJerk:
      message += self._dynamicType2Packet(DynamicType.Jerk)
    elif hasAcceleration:
      message += self._dynamicType2Packet(DynamicType.Acceleration)
    elif hasVelocity:
      message += self._dynamicType2Packet(DynamicType.Velocity)

    message += struct.pack('<d', float(elapsedTime))

    message += self._ecef2Packet(position)

    if hasVelocity:
      message += self._ecef2Packet(velocity)
      if hasAcceleration:
        message += self._ecef2Packet(acceleration)
        if hasJerk:
          message += self._ecef2Packet(jerk)

    message += struct.pack('<I', len(dest))
    message = message + dest.encode("UTF-8")
    self._sendMessage(message)

  # Send Skydel a timed position, orientation, and the associated dynamics of the vehicle. 
  # The position is provided in the ECEF coordinate system, while the body's orientation is specified relative 
  # to the local NED reference frame.
  #
  #  Parameter             Type                       Units                       Description
  #  -------------------------------------------------------------------------------------------------------
  #  elapsedTime           float                      milliseconds                Time since the beginning of the simulation.
  #  position              Ecef Object                x, y, z (m)                 Position of the vehicle.
  #  attitude              Attitude Object            yaw, pitch, roll (rad/s)    Orientation of the vehicle's body.
  #  velocity              optional Ecef Object       x, y, z (m/s)               Velocity of the vehicle.
  #  angularVelocity       optional Attitude Object   yaw, pitch, roll (rad/s)    Rotational velocity of the vehicle's body.
  #  acceleration          optional Ecef Object       x, y, z (m/s²)              Acceleration of the vehicle.
  #  angularAcceleration   optional Attitude Object   yaw, pitch, roll (rad/s²)   Rotational acceleration of the vehicle's body.
  #  jerk                  optional Ecef Object       x, y, z (m/s³)              Jerk of the vehicle.
  #  angularJerk           optional Attitude Object   yaw, pitch, roll (rad/s³)   Rotational jerk of the vehicle's body.
  #  dest                  optional string                                        If empty, sends the position for the vehicle. 
  #                                                                               If set with a jammerID, sends the position 
  #                                                                               for the specified jammer's vehicle.
  #
  def pushEcefNed(self, elapsedTime, position, attitude, velocity, angularVelocity, acceleration, angularAcceleration, jerk, angularJerk, dest):
    hasPosVelocity = velocity is not None
    hasPosAcceleration = acceleration is not None
    hasPosJerk = jerk is not None
    hasAngularVelocity = angularVelocity is not None
    hasAngularAcceleration = angularAcceleration is not None
    hasAngularJerk = angularJerk is not None

    if (hasPosVelocity != hasAngularVelocity):
      raise Exception("Velocity and angular velocity must be sent in pairs.")
    if (hasPosAcceleration != hasAngularAcceleration):
      raise Exception("Acceleration and angular acceleration must be sent in pairs.")
    if (hasPosJerk != hasAngularJerk):
      raise Exception("Jerk and angular jerk must be sent in pairs.")
    
    hasVelocity = hasPosVelocity and hasAngularVelocity
    hasAcceleration = hasPosAcceleration and hasAngularVelocity
    hasJerk = hasPosJerk and hasAngularJerk

    if (hasAcceleration and not hasVelocity):
      raise Exception("Velocity must be sent in order to send acceleration.")
    if (hasJerk and (not hasVelocity or not hasAcceleration)):
      raise Exception("Velocity and acceleration must be sent in order to send jerk.")

    if (not hasVelocity and not hasAcceleration and not hasJerk):
      message = self._msgId2Packet(MsgId.PushEcefNed)
    else:
      message = self._msgId2Packet(MsgId.PushEcefNedDynamics)

    if hasJerk:
      message += self._dynamicType2Packet(DynamicType.Jerk)
    elif hasAcceleration:
      message += self._dynamicType2Packet(DynamicType.Acceleration)
    elif hasVelocity:
      message += self._dynamicType2Packet(DynamicType.Velocity)

    message += struct.pack('<d', float(elapsedTime))

    message += self._ecef2Packet(position)
    message += self._angle2Packet(attitude)

    if hasVelocity:
      message += self._ecef2Packet(velocity)
      message += self._angle2Packet(angularVelocity)
      if hasAcceleration:
        message += self._ecef2Packet(acceleration)
        message += self._angle2Packet(angularAcceleration)
        if hasJerk:
          message += self._ecef2Packet(jerk)
          message += self._angle2Packet(angularJerk)

    message += struct.pack('<I', len(dest))
    message = message + dest.encode("UTF-8")
    self._sendMessage(message)
