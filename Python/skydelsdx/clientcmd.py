#!/usr/bin/env python3

import socket
import sys
import struct

from .commandfactory import *
from .client import Client
from .commands import *



_STRUCT_H = struct.Struct('<H')
_STRUCT_I = struct.Struct('<I')
_STRUCT_i = struct.Struct('<i')

class MsgId:
  Command = 0
  Result  = 1
  ApiVersion = 2

class ClientCmd(Client):
  def __init__(self, address: str, port: int, timeout: float| None = None):
    super().__init__(address, port, True, timeout)

  def _getPacketSize(self) -> int:
    return _STRUCT_H.unpack(self._getPacket(2))[0]

  def _sendMessage(self, message: bytes) -> None:
    packet = _STRUCT_H.pack(len(message)) + message
    self.sock.sendall(packet)

  def getServerApiVersion(self) -> int:
    message = self._msgId2Packet(MsgId.ApiVersion) + _STRUCT_I.pack(ApiVersion)
    self._sendMessage(message)

    while True:
      msgSize = self._getPacketSize()
      msgId = self._getPacketMsgId()

      if msgId == MsgId.ApiVersion:
        return _STRUCT_I.unpack(self._getPacket(4))[0]
      else:
        self._getPacket(msgSize - 1)

  def sendCommand(self, cmd) -> None:
    json_str = cmd.toJson()
    message = self._msgId2Packet(MsgId.Command) + f"{json_str}\0".encode("UTF-8")
    self._sendMessage(message)

  def waitCommand(self, cmd):
    while True:
      msgSize = self._getPacketSize()
      msgId = self._getPacketMsgId()

      if msgId == MsgId.Result:
        msg_json_len = _STRUCT_i.unpack(self._getPacket(4))[0]
        msg_json = self._getPacket(msg_json_len)[:-1]
        result = createCommandResult(msg_json)
        if cmd.getUuid() == result.getRelatedCommand().getUuid():
          return result
      else:
        self._getPacket(msgSize - 1)  # Skip the packet