#!/usr/bin/env python3

from dataclasses import dataclass
import math

# WGS84 Constants
WGS84_A = 6378137.0  # Semi-major axis (meters)
WGS84_F = 1.0 / 298.257223563  # Flattening
WGS84_B = WGS84_A * (1.0 - WGS84_F)
E_SQUARED = ((WGS84_A ** 2) - (WGS84_B ** 2)) / (WGS84_A ** 2)


@dataclass
class LLA:
    lat: float  # Latitude in radians
    lon: float  # Longitude in radians
    alt: float = 0.0  # Altitude in meters

    @property
    def lat_deg(self) -> float:
        return math.degrees(self.lat)

    @property
    def lon_deg(self) -> float:
        return math.degrees(self.lon)

    def add_enu(self, enu: 'ENU') -> 'LLA':
        return enu.to_lla(self)

    def to_ecef(self) -> 'ECEF':
        cos_lat = math.cos(self.lat)
        sin_lat = math.sin(self.lat)

        tmp = (1 - WGS84_F) ** 2
        ex2 = (2 - WGS84_F) * WGS84_F / tmp
        c = WGS84_A * math.sqrt(1 + ex2)
        n = c / math.sqrt(1 + ex2 * cos_lat ** 2)

        x = (n + self.alt) * cos_lat * math.cos(self.lon)
        y = (n + self.alt) * cos_lat * math.sin(self.lon)
        z = (tmp * n + self.alt) * sin_lat
        return ECEF(x, y, z)

    def to_enu(self, origin: 'LLA') -> 'ENU':
        self_ecef = self.to_ecef()
        origin_ecef = origin.to_ecef()

        dx = self_ecef.x - origin_ecef.x
        dy = self_ecef.y - origin_ecef.y
        dz = self_ecef.z - origin_ecef.z

        sin_lon, cos_lon = math.sin(origin.lon), math.cos(origin.lon)
        sin_lat, cos_lat = math.sin(origin.lat), math.cos(origin.lat)

        east = -sin_lon * dx + cos_lon * dy
        north = -sin_lat * cos_lon * dx - sin_lat * sin_lon * dy + cos_lat * dz
        up = cos_lat * cos_lon * dx + cos_lat * sin_lon * dy + sin_lat * dz
        return ENU(east, north, up)

    def __add__(self, other):
        return LLA(self.lat + other.lat, self.lon + other.lon, self.alt + other.alt)

    def __str__(self) -> str:
        return f"{self.lat_deg:.7f}deg, {self.lon_deg:.7f}deg, {self.alt:.2f}m"


@dataclass
class ENU:
    east: float  # East deviation (meters)
    north: float  # North deviation (meters)
    up: float = 0.0  # Up deviation (meters)

    def to_ecef(self, origin_lla: LLA) -> 'ECEF':
        origin_ecef = origin_lla.to_ecef()
        sin_lon, cos_lon = math.sin(origin_lla.lon), math.cos(origin_lla.lon)
        sin_lat, cos_lat = math.sin(origin_lla.lat), math.cos(origin_lla.lat)

        x = -sin_lon * self.east - sin_lat * cos_lon * self.north + cos_lat * cos_lon * self.up + origin_ecef.x
        y = cos_lon * self.east - sin_lat * sin_lon * self.north + cos_lat * sin_lon * self.up + origin_ecef.y
        z = cos_lat * self.north + sin_lat * self.up + origin_ecef.z
        return ECEF(x, y, z)

    def to_lla(self, origin_lla: LLA) -> LLA:
        return self.to_ecef(origin_lla).to_lla()

    def __add__(self, other: 'ENU') -> 'ENU':
        return ENU(self.east + other.east, self.north + other.north, self.up + other.up)

    def __str__(self) -> str:
        return f"{self.east:.2f}m East, {self.north:.2f}m North, {self.up:.2f}m Up"


@dataclass
class ECEF:
    x: float
    y: float
    z: float

    def to_lla(self) -> LLA:
        dist_to_z = math.sqrt(self.x ** 2 + self.y ** 2)
        lat = math.atan2(self.z, (1 - E_SQUARED) * dist_to_z)

        radius_p = WGS84_A
        for _ in range(4):
            sin_lat = math.sin(lat)
            radius_p = WGS84_A / math.sqrt(1.0 - E_SQUARED * sin_lat ** 2)
            lat = math.atan2(self.z + E_SQUARED * radius_p * sin_lat, dist_to_z)

        lon = math.atan2(self.y, self.x)

        if -85 < math.degrees(lat) < 85:
            alt = dist_to_z / math.cos(lat) - radius_p
        else:
            alt = (self.z + E_SQUARED * radius_p * math.sin(lat)) / math.sin(lat) - radius_p

        return LLA(lat, lon, alt)

    def __add__(self, other: 'ECEF') -> 'ECEF':
        return ECEF(self.x + other.x, self.y + other.y, self.z + other.z)

    def __str__(self) -> str:
        return f"{self.x:.2f}m, {self.y:.2f}m, {self.z:.2f}m"


@dataclass
class Attitude:
    yaw: float
    pitch: float
    roll: float

    @property
    def yaw_deg(self) -> float:
        return math.degrees(self.yaw)

    @property
    def pitch_deg(self) -> float:
        return math.degrees(self.pitch)

    @property
    def roll_deg(self) -> float:
        return math.degrees(self.roll)

    def __str__(self) -> str:
        return f"{self.yaw_deg:.2f}deg, {self.pitch_deg:.2f}deg, {self.roll_deg:.2f}deg"

    def __add__(self, other):
        return Attitude(self.yaw + other.yaw, self.pitch + other.pitch, self.roll + other.roll)
