#!/usr/bin/env python3

import socket
import struct
from .units import *
from .client import Client

_STRUCT_B = struct.Struct('<B')
_STRUCT_D = struct.Struct('<d')
_STRUCT_I = struct.Struct('<I')
_STRUCT_VEHICLE  = struct.Struct('<d3d3ddd')

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
    def __init__(self) -> None:
        self.elapsedTime: float = 0.0
        self.ecef: ECEF = ECEF(0.0, 0.0, 0.0)
        self.attitude: Attitude = Attitude(0.0, 0.0, 0.0)
        self.speed: float = 0.0
        self.heading: float = 0.0
        self.odometer: float = 0.0


class ClientHil(Client):
    def __init__(self, address: str, port: int, timeout: float | None = None) -> None:
        super().__init__(address, port, use_connection=False, timeout=timeout)
        self.sock.sendto(_STRUCT_B.pack(MsgId.Hello), self.server_address)

    def _sendMessage(self, message: bytes) -> None:
        self.sock.sendto(message, self.server_address)

    def pollVehicleInfo(self) -> VehicleInfo | None:
        oldTimeout = self.sock.gettimeout()
        self.sock.settimeout(0.0)

        try:
            result, addr = self.sock.recvfrom(255)
            if not result:
                return None

            msgId = result[0]
            if msgId == MsgId.VehicleInfo:
                info = VehicleInfo()
                payload = result[1:]
                if len(payload) >= _STRUCT_VEHICLE.size:
                    unpacked = _STRUCT_VEHICLE.unpack_from(payload)
                    info.elapsedTime = unpacked[0]
                    info.ecef = ECEF(unpacked[1], unpacked[2], unpacked[3])
                    info.attitude = Attitude(unpacked[4], unpacked[5], unpacked[6])
                    info.speed = unpacked[7]
                    info.heading = unpacked[8]
                    if len(unpacked) > 9:
                        info.odometer = unpacked[9]
                return info
        except (socket.error, BlockingIOError):
            return None
        finally:
            self.sock.settimeout(oldTimeout)

    def pushEcefNed(
            self,
            elapsedTime: float,
            position: ECEF,
            attitude: Attitude,
            velocity: ECEF | None = None,
            angularVelocity: Attitude | None = None,
            acceleration: ECEF | None = None,
            angularAcceleration: Attitude | None = None,
            jerk: ECEF | None = None,
            angularJerk: Attitude | None = None,
            dest: bytes = b""
    ) -> None:
        hasVelocity = velocity is not None and angularVelocity is not None
        hasAcceleration = acceleration is not None and angularAcceleration is not None
        hasJerk = jerk is not None and angularJerk is not None

        if acceleration is not None and not hasVelocity:
            raise Exception("Velocity must be sent in order to send acceleration.")
        if jerk is not None and (not hasVelocity or not hasAcceleration):
            raise Exception("Velocity and acceleration must be sent in order to send jerk.")

        if not hasVelocity and not hasAcceleration and not hasJerk:
            message = self._msgId2Packet(MsgId.PushEcefNed)
        else:
            message = self._msgId2Packet(MsgId.PushEcefNedDynamics)

        if hasJerk:
            message += self._dynamicType2Packet(DynamicType.Jerk)
        elif hasAcceleration:
            message += self._dynamicType2Packet(DynamicType.Acceleration)
        elif hasVelocity:
            message += self._dynamicType2Packet(DynamicType.Velocity)

        message += _STRUCT_D.pack(float(elapsedTime))
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

        message += _STRUCT_I.pack(len(dest))
        message += dest

        self._sendMessage(message)