#!/usr/bin/python

import socket
from .units import *
import struct
import datetime
from .client import Client

class MsgId:
  PushEcef = 0
  Hello = 1
  Bye = 2
  VehicleInfo = 3
  PushEcefNed = 4

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
      if e.args[0] != 10035 and e.args[0] != 11:
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
      if e.args[0] != 10035 and e.args[0] != 11:
        raise
    except:
      self.sock.settimeout(oldTimeout)
      raise
   
  def pushEcef(self, elapsedTime, ecef, dest):
    message = self._msgId2Packet(MsgId.PushEcef)
    message += struct.pack('<q', int(elapsedTime))
    message += struct.pack('<d', ecef.x)
    message += struct.pack('<d', ecef.y)
    message += struct.pack('<d', ecef.z)
    message += struct.pack('<I', len(dest))
    message = message + dest.encode("UTF-8")
    self._sendMessage(message)
 
  def pushEcefNed(self, elapsedTime, ecef, attitude, dest):
    message = self._msgId2Packet(MsgId.PushEcefNed)
    message += struct.pack('<q', elapsedTime)
    message += struct.pack('<d', ecef.x)
    message += struct.pack('<d', ecef.y)
    message += struct.pack('<d', ecef.z)
    message += struct.pack('<d', attitude.yaw)
    message += struct.pack('<d', attitude.pitch)
    message += struct.pack('<d', attitude.roll)
    message += struct.pack('<I', len(dest))
    message = message + dest.encode("UTF-8")
    self._sendMessage(message)
