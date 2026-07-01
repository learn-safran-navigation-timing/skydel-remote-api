#!/usr/bin/env python3
import sys
from enum import Enum, auto
from .commandexception import CommandException
from .clientcmd import ClientCmd
from .clienthil import ClientHil
from .commands import *
import logging

logger = logging.getLogger("RemoteSimulator")
logger.propagate = False
_console_handler = logging.StreamHandler(sys.stdout)
_console_handler.setFormatter(logging.Formatter("%(message)s"))
logger.addHandler(_console_handler)

def spooferInstance(id: int) -> int:
    return 128 + id


class DeprecatedMessageMode(Enum):
    ALL = auto()
    LATCH = auto()
    NONE = auto()


class RemoteSimulator:
    def __init__(self, exception_on_error: bool = True):
        self.exception_on_error = exception_on_error
        self.client = None
        self.hilStreamingCheckEnabled = True
        self.hil = None
        self._last_vehicle_info = None
        self.checkRunningTime = 0.0
        self.beginRoute = False
        self.beginTrack = False
        self.beginIntTxTrack = {}
        self._serverApiVersion = 0
        self.deprecatedMessageMode = DeprecatedMessageMode.LATCH
        self.latchDeprecated = set()

        self.verbose = False

    @property
    def verbose(self) -> bool:
        return logger.getEffectiveLevel() == logging.DEBUG

    @verbose.setter
    def verbose(self, value: bool) -> None:
        logger.setLevel(logging.DEBUG if value else logging.INFO)

    def connect(self, ip: str = "localhost", id: int = 0, failIfApiVersionMismatch: bool = False) -> None:
        if self.isConnected():
            raise Exception("Cannot connect. Already connected. Disconnect first.")

        port = 4820 + id
        logger.debug(f"Connecting to {ip} on port {port}...")
        self.client = ClientCmd(ip, port)

        self._serverApiVersion = self.client.getServerApiVersion()
        if ApiVersion != self._serverApiVersion:
            msg = f"Client Api Version ({ApiVersion}) != Server Api Version ({self._serverApiVersion})"
            if failIfApiVersionMismatch:
                raise Exception(msg)
            else:
                print(f"Warning: {msg}")

        hilPort = self._callCommand(GetHilPort()).port()
        self.hil = ClientHil(self.client.getAddress(), hilPort)

    def disconnect(self) -> None:
        self._checkConnect()
        logger.debug('Commands Client Disconnecting')
        del self.client
        self.client = None
        del self.hil
        self.hil = None



    def setHilStreamingCheckEnabled(self, hilStreamingCheckEnabled: bool) -> None:
        self.hilStreamingCheckEnabled = hilStreamingCheckEnabled

    def isHilStreamingCheckEnabled(self) -> bool:
        return self.hilStreamingCheckEnabled

    def isConnected(self) -> bool:
        return self.client is not None

    def clientApiVersion(self) -> int:
        return ApiVersion

    def serverApiVersion(self) -> int:
        if self.isConnected():
            return self._serverApiVersion
        else:
            raise Exception("Server API Version unavailable. You must be connected to the server.")

    def _handleException(self, result) -> None:
        if self.exception_on_error and not result.isSuccess():
            stateResult = self._callCommand(GetSimulatorState())

            if stateResult.state() == "Error":
                simErrorMsg = f"\nAn error occured during simulation:\n{stateResult.error()}"
            else:
                simErrorMsg = ""
            raise CommandException(result, simErrorMsg)

        if not result.isSuccess():
            logger.debug(f"{result.getRelatedCommand().getName()} failed: {result.getMessage()}")

    def _resetTime(self) -> None:
        self.checkRunningTime = -99999999.9

    def arm(self) -> bool:
        self._checkConnect()
        logger.debug("Arming simulation...")

        if not self._callCommand(Arm()).isSuccess():
            logger.debug("Failed to arm simulation.")
            return False
        self._resetTime()
        logger.debug("Simulation armed.")
        return True

    def start(self) -> bool:
        self._checkConnect()
        logger.debug("Starting simulation...")

        if not self._callCommand(Start()).isSuccess():
            logger.debug("Failed to start simulation.")
            return False

        self.hil.clearVehicleInfo()
        self._resetTime()

        logger.debug("Simulation started.")
        if self._callCommand(GetSimulatorState()).subStateId() == SimulatorSubState.Started_HILSync:
            logger.debug("Please send HIL positions...")
        return True

    def stop(self, timestamp=None) -> None:
        self._checkConnect()
        self._resetTime()

        stopCmd = self._postCommand(Stop(), timestamp)

        if timestamp is not None:
            logger.debug(f"Stopping simulation at {timestamp} seconds...")

        self._waitCommand(stopCmd)

        logger.debug("Simulation stopped.")

    def _checkForbiddenPost(self, cmd) -> None:
        if cmd.getName() == "Start":
            raise Exception("You cannot send a Start command. Use RemoteSimulator.start() instead.")

    def _checkForbiddenCall(self, cmd) -> None:
        if cmd.getName() == "Start":
            raise Exception("You cannot send a Start command. Use RemoteSimulator.start() instead.")
        if cmd.getName() == "PushRouteEcef":
            raise Exception(
                "You cannot call a PushRouteEcef command. Post it or use RemoteSimulator.pushRouteLla() or RemoteSimulator.pushRouteEcef() instead.")
        if cmd.getName() == "PushTrackEcef":
            raise Exception(
                "You cannot call a PushTrackEcef command. Post it or use RemoteSimulator.pushTrackEcef() or RemoteSimulator.pushTrackLla() instead.")
        if cmd.getName() == "PushTrackEcefNed":
            raise Exception(
                "You cannot call a PushTrackEcefNed command. Post it or use RemoteSimulator.pushTrackEcefNed() or RemoteSimulator.pushTrackLlaNed() instead.")
        if cmd.getName() == "PushIntTxTrackEcef":
            raise Exception(
                "You cannot call a PushIntTxTrackEcef command. Post it or use RemoteSimulator.pushIntTxTrackEcef() or RemoteSimulator.pushIntTxTrackLla() instead.")
        if cmd.getName() == "PushIntTxTrackEcefNed":
            raise Exception(
                "You cannot call a PushIntTxTrackEcefNed command. Post it or use RemoteSimulator.pushIntTxTrackEcefNed() or RemoteSimulator.pushIntTxTrackLlaNed() instead.")

    def checkIfStreaming(self) -> bool:
        self._checkConnect()

        stateResult = self._callCommand(GetSimulatorState())

        if stateResult.state() == "Streaming RF":
            return True

        if stateResult.state() == "Error":
            errorMsg = f"An error occured during simulation. Error message:\n{stateResult.error()}"
        else:
            errorMsg = f"Simulator is not running. Current state is {stateResult.state()}."
        if self.exception_on_error:
            raise Exception(errorMsg)
        logger.debug(errorMsg)
        return False

    def waitState(self, state, failureState="") -> bool:
        self._checkConnect()
        logger.debug(f"Waiting for simulator state {state}...")

        stateResult = self._callCommand(WaitSimulatorState(state, failureState))

        if stateResult.state() == state:
            return True
        elif stateResult.state() == "Error":
            errorMsg = f"An error occured during simulation. Error message:\n{stateResult.error()}"
        else:
            errorMsg = f"Wrong simulator state. Expected {state} but received {stateResult.state()}"

        if self.exception_on_error:
            raise Exception(errorMsg)
        logger.debug(errorMsg)
        return False

    def _checkHil(self, pos, elapsedTime: float) -> bool:
        if self.hil is None:
            raise Exception("Cannot send positions to simulator because you are not connected.")

        if self.checkRunningTime < 0.0:
            self.checkRunningTime = elapsedTime

        if elapsedTime - self.checkRunningTime >= 1000.0:
            self.checkRunningTime = elapsedTime
            if self.hilStreamingCheckEnabled and not self.checkIfStreaming():
                self._resetTime()
                return False
            logger.debug(f"{pos} sent at {elapsedTime:.2f}ms")
        return True

    def _checkConnect(self) -> None:
        if not self.isConnected():
            raise Exception("You are not connected.")

    def pushLla(self, elapsedTime: float, lla, dest: str = ""):
        return self.pushEcef(elapsedTime, lla.to_ecef(), dest=dest)

    def pushEcef(self, elapsedTime: float, position, velocity=None, acceleration=None, jerk=None, dest: str = ""):
        self.hil.pushEcef(elapsedTime, position, velocity, acceleration, jerk, dest)
        return self._checkHil(position, elapsedTime)

    def pushEcefNed(self, elapsedTime: float, position, attitude, velocity=None, angularVelocity=None,
                    acceleration=None, angularAcceleration=None, jerk=None, angularJerk=None, dest: str = ""):
        self.hil.pushEcefNed(elapsedTime, position, attitude, velocity, angularVelocity, acceleration,
                             angularAcceleration, jerk, angularJerk, dest)
        return self._checkHil(f"{position}, {attitude}", elapsedTime)

    def pushLlaNed(self, elapsedTime: float, lla, attitude):
        return self.pushEcefNed(elapsedTime, lla.to_ecef(), attitude)

    def beginRouteDefinition(self):
        self._checkConnect()
        self.beginRoute = self._callCommand(BeginRouteDefinition())
        logger.debug("Begin Route Definition...")
        return self.beginRoute

    def beginTrackDefinition(self):
        self._checkConnect()
        self.beginTrack = self._callCommand(BeginTrackDefinition())
        logger.debug("Begin Track Definition...")
        return self.beginTrack

    def pushRouteEcef(self, speed: float, ecef) -> bool:
        self._checkConnect()
        if not self.beginRoute:
            raise Exception("You must call beginRouteDefinition first.")

        if speed <= 0:
            raise Exception("A route node must have a speed limit greater than zero.")

        self._postCommand(PushRouteEcef(speed, ecef.x, ecef.y, ecef.z))
        return True

    def pushTrackEcef(self, elapsedTime: float, ecef) -> bool:
        self._checkConnect()
        if not self.beginTrack:
            raise Exception("You must call beginTrackDefinition first.")

        self._postCommand(PushTrackEcef(elapsedTime, ecef.x, ecef.y, ecef.z))
        return True

    def pushTrackEcefNed(self, elapsedTime: float, ecef, attitude) -> bool:
        self._checkConnect()
        if not self.beginTrack:
            raise Exception("You must call beginTrackDefinition first.")

        self._postCommand(
            PushTrackEcefNed(elapsedTime, ecef.x, ecef.y, ecef.z, attitude.yaw, attitude.pitch, attitude.roll))
        return True

    def pushRouteLla(self, speed: float, lla):
        return self.pushRouteEcef(speed, lla.to_ecef())

    def pushTrackLla(self, elapsedTime: float, lla):
        return self.pushTrackEcef(elapsedTime, lla.to_ecef())

    def pushTrackLlaNed(self, elapsedTime: float, lla, attitude):
        return self.pushTrackEcefNed(elapsedTime, lla.to_ecef(), attitude)

    def endRouteDefinition(self) -> int:
        self._checkConnect()
        if not self.beginRoute:
            raise Exception("You must call beginRouteDefinition first.")
        self.beginRoute = None

        routeResult = self._callCommand(EndRouteDefinition())

        if not routeResult.isSuccess():
            return 0

        logger.debug(f"End route contains {routeResult.count()} nodes.")

        return routeResult.count()

    def endTrackDefinition(self) -> int:
        self._checkConnect()
        if not self.beginTrack:
            raise Exception("You must call beginTrackDefinition first.")
        self.beginTrack = None

        trackResult = self._callCommand(EndTrackDefinition())

        if not trackResult.isSuccess():
            return 0

        logger.debug(f"End route contains {trackResult.count()} nodes.")

        return trackResult.count()

    def beginIntTxTrackDefinition(self, id):
        self._checkConnect()
        self.beginIntTxTrack[id] = self._callCommand(BeginIntTxTrackDefinition(id))
        logger.debug("Begin Transmitter Track Definition...")
        return self.beginIntTxTrack[id]

    def pushIntTxTrackEcef(self, elapsedTime: float, ecef, id) -> bool:
        self._checkConnect()
        if not self.beginIntTxTrack[id]:
            raise Exception("You must call beginIntTxTrackDefinition first.")

        self._postCommand(PushIntTxTrackEcef(elapsedTime, ecef.x, ecef.y, ecef.z, id))
        return True

    def pushIntTxTrackEcefNed(self, elapsedTime: float, ecef, attitude, id) -> bool:
        self._checkConnect()
        if not self.beginIntTxTrack[id]:
            raise Exception("You must call beginIntTxTrackDefinition first.")

        self._postCommand(
            PushIntTxTrackEcefNed(elapsedTime, ecef.x, ecef.y, ecef.z, attitude.yaw, attitude.pitch, attitude.roll, id))
        return True

    def pushIntTxTrackLla(self, elapsedTime: float, lla, id):
        return self.pushIntTxTrackEcef(elapsedTime, lla.to_ecef(), id)

    def pushIntTxTrackLlaNed(self, elapsedTime: float, lla, attitude, id):
        return self.pushIntTxTrackEcefNed(elapsedTime, lla.to_ecef(), attitude, id)

    def endIntTxTrackDefinition(self, id) -> int:
        self._checkConnect()
        if not self.beginIntTxTrack[id]:
            raise Exception("You must call beginIntTxTrackDefinition first.")
        self.beginIntTxTrack[id] = None

        trackResult = self._callCommand(EndIntTxTrackDefinition(id))

        if not trackResult.isSuccess():
            return 0

        logger.debug(f"End transmitter track contains {trackResult.count()} nodes.")

        return trackResult.count()

    def _callCommand(self, cmd, timestamp=None):
        self._postCommand(cmd, timestamp)
        return self._waitCommand(cmd)

    def _postCommand(self, cmd, timestamp=None):
        deprecated = cmd.deprecated()
        if deprecated and (self.deprecatedMessageMode == DeprecatedMessageMode.ALL or (
                self.deprecatedMessageMode == DeprecatedMessageMode.LATCH and cmd.getName() not in self.latchDeprecated)):
            print(f"Warning: {deprecated}")
            self.latchDeprecated.add(cmd.getName())
        if timestamp is not None:
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
        logger.debug(f"Post {cmd.toString()}")
        self._postCommand(cmd, timestamp)
        return cmd

    def wait(self, cmd):
        self._checkConnect()
        logger.debug("Wait %s", cmd.toString())
        result = self._waitCommand(cmd)
        logger.debug(" => %s", result.getMessage())
        return result

    def call(self, cmd, timestamp=None):
        self._checkConnect()
        self._checkForbiddenCall(cmd)
        self._postCommand(cmd, timestamp)

        logger.debug("Call %s", cmd.toString())

        result = self._waitCommand(cmd)
        logger.debug(" => %s", result.getMessage())
        return result

    def beginVehicleInfo(self):
        return self.call(BeginVehicleInfo())

    def endVehicleInfo(self):
        return self.call(EndVehicleInfo())

    def hasVehicleInfo(self) -> bool:
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

    def setDeprecatedMessageMode(self, mode: DeprecatedMessageMode) -> None:
        self.deprecatedMessageMode = mode
        self.latchDeprecated.clear()


class RemoteSpooferSimulator(RemoteSimulator):
    def connect(self, ip: str = "localhost", id: int = 1, failIfApiVersionMismatch: bool = False) -> None:
        super().connect(ip, spooferInstance(id), failIfApiVersionMismatch)
