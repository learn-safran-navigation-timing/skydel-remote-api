#!/usr/bin/env python3

import socket
import struct
import time
from typing import Optional, Tuple

_STRUCT_B = struct.Struct('<B')
_STRUCT_3D = struct.Struct('<3d')


class Client:
    def __init__(self, address: str, port: int, use_connection: bool, timeout: Optional[float] = None):
        sock_type = socket.SOCK_STREAM if use_connection else socket.SOCK_DGRAM
        self.sock = socket.socket(socket.AF_INET, sock_type)
        self.sock.settimeout(timeout)
        self.server_address: Tuple[str, int] = (address, port)
        self.port: int = port
        self.address: str = address

        if use_connection:
            # Connect the socket to the port where the server is listening
            self.sock.connect(self.server_address)

    def __del__(self):
        try:
            time.sleep(0.5)
            self.sock.close()
        except Exception:
            pass

    def getPort(self) -> int:
        return self.port

    def getAddress(self) -> str:
        return self.address

    def setTimeout(self, time_val: Optional[float]) -> None:
        self.sock.settimeout(time_val)

    def _getPacket(self, size: int) -> bytes:
        packet = bytearray()
        while len(packet) < size:
            chunk = self.sock.recv(size - len(packet))
            if not chunk:
                raise Exception("Server closed connection.")
            packet.extend(chunk)
        return bytes(packet)

    def _msgId2Packet(self, msgId: int) -> bytes:
        return _STRUCT_B.pack(msgId)

    def _dynamicType2Packet(self, dynamicType: int) -> bytes:
        return _STRUCT_B.pack(dynamicType)

    def _ecef2Packet(self, triplet) -> bytes:
        return _STRUCT_3D.pack(triplet.x, triplet.y, triplet.z)

    def _angle2Packet(self, triplet) -> bytes:
        return _STRUCT_3D.pack(triplet.yaw, triplet.pitch, triplet.roll)

    def _getPacketMsgId(self) -> int:
        return _STRUCT_B.unpack(self._getPacket(1))[0]