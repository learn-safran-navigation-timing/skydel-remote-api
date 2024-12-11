#!/usr/bin/env python3

import collections

"""
    Units.
"""
ARC_PER_SECOND                  = "arc/s"
ARC_SECOND                      = "arc-s"
ARC_SECOND_PER_DAY              = "arc-s/day"
DAY                             = "day"
DEGREE                          = "degree"
FOUR_YEAR_INTERVAL              = "4-year interval"
HOUR                            = "h"
KILOMETER                       = "km"
KILOMETER_PER_SECOND            = "km/s"
KILOMETER_PER_SECOND_SQUARED    = "km/s^2"
METER                           = "m"
CENTIMETER                      = "cm"
MILLIMETER                      = "mm"
METER_PER_SECOND                = "m/s"
METER_PER_SECOND_SQUARED        = "m/s^2"
METER_SQUARE_ROOT               = "m^1/2"
METER_PER_DEGREE                = "m/degree"
METER_PER_DEGREE_SQUARED        = "m/degree^2"
MINUTE                          = "min"
NANO_SECOND                     = "ns"
NANO_SECOND_PER_SECOND          = "ns/s"
PI                              = "pi"
PI_PER_SECOND                   = "pi/s"
PI_PER_SECOND_SQUARED           = "pi/s^2"
SECOND                          = "s"
SECOND_PER_DAY                  = "s/day"
SECOND_PER_MSD                  = "s/msd"
SECOND_PER_ORBITAL              = "s/orbital-period"
SECOND_PER_ORBITAL_SQUARED      = "s/orbital-period^2"
SECOND_PER_SECOND               = "s/s"
SECOND_PER_SECOND_SQUARED       = "s/s^2"
SECOND_PER_SEMICIRCLE           = "s/semicicle"
SECOND_PER_SEMICIRCLE_CUBE      = "s/semicicle^3"
SECOND_PER_SEMICIRCLE_SQUARED   = "s/semicicle^2"
SEMICIRCLE                      = "semicircle"
SEMICIRCLE_PER_SECOND           = "semicircle/s"
SEMICIRCLE_PER_SECOND_SQUARED   = "semicircle/s^2"
SOLAR_FLUX                      = "sfu"
SOLAR_FLUX_PER_DEGREE           = "sfu/degree"
SOLAR_FLUX_PER_DEGREE_SQUARED   = "sfu/degree^2"
TEC_U                           = "TECu"
TEC_U_PER_DEGREE                = "TECu/degree"
TEC_U_PER_DEGREE_SQUARED        = "TECu/degree^2"
RADIAN                          = "rad"
WEEK                            = "week"

"""
    Constants.
"""
WORD_SIZE = 32

"""
    Utility functions to help decoding the downlink.
"""
def convertToDecimalWithFactor(value, signed, factor):
    if signed:
        mask = 2 ** (len(value) - 1)
        return str(((int(value, 2) & ~mask) - (int(value, 2) & mask)) * factor)
    else:
        return str(int(value, 2) * factor)

def convertToBinaryNavigationMessage(message, size):
    return bin(int(message.replace(" ", ""), 16))[2:].zfill(size)

def getInversedBinaryValue(value):
    binaryLength = len(value)
    value = bin(~int(value, 2) & 0xFFFFFFFF)[3:].zfill(binaryLength )
    return value[len(value) - binaryLength:len(value)]

def fillDict(binaryMessage, referenceDict):
    messageDict = collections.OrderedDict()
    for par in referenceDict:
        if isinstance(par['range'][0], list):
            value = binaryMessage[par['range'][0][0]:par['range'][0][1] + 1] + binaryMessage[par['range'][1][0]:par['range'][1][1] + 1]
        else:
            value = binaryMessage[par['range'][0]:par['range'][1] + 1]
        messageDict[par['name']] = {'range':par['range'],
                                    'binary':value,
                                    'decimal':convertToDecimalWithFactor(value, par.get('signed', False), par.get('factor', 1)),
                                    'unit':par.get('unit', "")}
    return messageDict
