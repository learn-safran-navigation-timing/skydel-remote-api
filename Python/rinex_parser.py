
# This script provides a simple way to parse RINEX files to be used with the Skydel API

from datetime import datetime
from enum import Enum

class SatelliteSystem(Enum):
    BEIDOU = "C"
    GALILEO = "E"
    GPS = "G"
    NAVIC = "I"
    QZSS = "J"

def SatelliteSystemToString(satellite_system):
    if satellite_system == SatelliteSystem.BEIDOU:
        return "BEIDOU"
    elif satellite_system == SatelliteSystem.GALILEO:
        return "GALILEO"
    elif satellite_system == SatelliteSystem.GPS:
        return "GPS"
    elif satellite_system == SatelliteSystem.NAVIC:
        return "NAVIC"
    elif satellite_system == SatelliteSystem.QZSS:
        return "QZSS"

class RinexLineType(Enum):
    SV_EPOCH_SV_CLK = 0
    BROADCAST_ORBIT_1 = 1
    BROADCAST_ORBIT_2 = 2
    BROADCAST_ORBIT_3 = 3
    BROADCAST_ORBIT_4 = 4
    BROADCAST_ORBIT_5 = 5
    BROADCAST_ORBIT_6 = 6
    BROADCAST_ORBIT_7 = 7

    def __int__(self):
        return self.value

class RinexBlock:

    def __init__(self, satellite_system):
        self.params = {}
        self.satellite_system = satellite_system

    def set_sv_id(self, sv_id):
        self.sv_id = sv_id

    def set_toc(self, toc):
        self.toc = toc

    def add(self, key, value):
        self.params[key] = value

def parse(rinex_path):
    blocks = []

    with open(rinex_path) as rinex_file:
        is_header_parsed = False
        version = None

        for line in rinex_file:
            striped_line = line.strip()
            if not is_header_parsed:
                if not version and "RINEX VERSION" in striped_line:
                    version = float(striped_line.split()[0])
                    if int(version) > 3:
                        raise Exception(f"RINEX parser error: RINEX version {version} not supported.")
                if "END OF HEADER" in striped_line:
                    is_header_parsed = True
                    if not version:
                        raise Exception(f"RINEX parser error: Could not find RINEX version.")
            elif striped_line:
                try:
                    satellite_system = SatelliteSystem(striped_line[0])
                    blocks.append(RinexBlock(satellite_system))
                    rinex_line_type = RinexLineType.SV_EPOCH_SV_CLK
                except:
                    pass
                finally:
                    parse_line(satellite_system, rinex_line_type, blocks[-1], cleanup_line(striped_line))
                    rinex_line_type = next(rinex_line_type)

    return blocks

def next(rinex_line_type):
    try:
        return RinexLineType(int(rinex_line_type) + 1)
    except:
        return RinexLineType.SV_EPOCH_SV_CLK

def cleanup_line(line):
    return line.replace('e', 'E').replace('D', 'E').replace('E-', 'Eneg').replace('-', ' -').replace('Eneg', 'E-')

def parse_line(satellite_system, rinex_line_type, block, line):
    data = line.split()

    if rinex_line_type == RinexLineType.SV_EPOCH_SV_CLK:
        block.set_sv_id(int(data[0][1:3]))
        block.set_toc(datetime(int(data[1]), int(data[2]), int(data[3]), int(data[4]), int(data[5]), int(data[6])))
        block.add("ClockBias", float(data[7]))
        block.add("ClockDrift", float(data[8]))
        block.add("ClockDriftRate", float(data[9]))

    elif rinex_line_type == RinexLineType.BROADCAST_ORBIT_1:
        block.add("Crs", float(data[1]))
        block.add("DeltaN", float(data[2]))
        block.add("M0", float(data[3]))

    elif rinex_line_type == RinexLineType.BROADCAST_ORBIT_2:
        block.add("Cuc", float(data[0]))
        block.add("Eccentricity", float(data[1]))
        block.add("Cus", float(data[2]))
        block.add("SqrtA", float(data[3]))

    elif rinex_line_type == RinexLineType.BROADCAST_ORBIT_3:
        block.add("Time of ephemeris", float(data[0]))
        block.add("Cic", float(data[1]))
        block.add("BigOmega", float(data[2]))
        block.add("Cis", float(data[3]))

    elif rinex_line_type == RinexLineType.BROADCAST_ORBIT_4:
        block.add("I0", float(data[0]))
        block.add("Crc", float(data[1]))
        block.add("LittleOmega", float(data[2]))
        block.add("BigOmegaDot", float(data[3]))

    elif rinex_line_type == RinexLineType.BROADCAST_ORBIT_5:
        block.add("Idot", float(data[0]))
        block.add("Week Number", float(data[2]))

    elif rinex_line_type == RinexLineType.BROADCAST_ORBIT_6:
        pass

    elif rinex_line_type == RinexLineType.BROADCAST_ORBIT_7:
        block.add("Transmission Time", float(data[0]))

    if satellite_system == SatelliteSystem.GPS:
        parse_gps_qzss_line(rinex_line_type, block, data)

    elif satellite_system == SatelliteSystem.QZSS:
        parse_gps_qzss_line(rinex_line_type, block, data)

    elif satellite_system == SatelliteSystem.GALILEO:
        parse_galileo_line(rinex_line_type, block, data)

    elif satellite_system == SatelliteSystem.NAVIC:
        parse_navic_line(rinex_line_type, block, data)

def parse_gps_qzss_line(rinex_line_type, block, data):
    if rinex_line_type == RinexLineType.BROADCAST_ORBIT_1:
        block.add("IODE", float(data[0]))

    elif rinex_line_type == RinexLineType.BROADCAST_ORBIT_6:
        block.add("Tgd", float(data[2]))
        block.add("IODC", float(data[3]))

def parse_galileo_line(rinex_line_type, block, data):
    if rinex_line_type == RinexLineType.BROADCAST_ORBIT_1:
        block.add("IODNAV", float(data[0]))

def parse_navic_line(rinex_line_type, block, data):
    if rinex_line_type == RinexLineType.BROADCAST_ORBIT_1:
        block.add("IODEC", float(data[0]))
