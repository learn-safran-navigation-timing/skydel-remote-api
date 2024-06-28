#!/usr/bin/env python3
"""
    Messages supported :
        QZSS L1CA
"""

import utility
from qzss_clas_message_reader import getDictQzssCLASDecodedFrame

L1CADictSVClock = [
    {'name':"Preamble",            'range':[0,7]},
    {'name':"TLM Message",         'range':[8,21]},
    {'name':"ISF",                 'range':[22,22]},
    {'name':"Reserved",            'range':[23,23]},
    {'name':"Parity 1",            'range':[24,29]},

    {'name':"Truncated TOW Count", 'range':[30,46],                  'factor':6,      'unit':utility.SECOND},
    {'name':"AF",                  'range':[47,47]},
    {'name':"AS",                  'range':[48,48]},
    {'name':"SubFrame ID",         'range':[49,51]},
    {'name':"PC 1",                'range':[52,53]},
    {'name':"Parity 2",            'range':[54,59]},

    {'name':"WN",                  'range':[60,69],                                   'unit':utility.WEEK},
    {'name':"Code L2",             'range':[70,71]},
    {'name':"SV Accuracy(URA)",    'range':[72,75]},
    {'name':"SV Health",           'range':[76,81]},
    {'name':"IODC",                'range':[[82,83],[210,217]]},
    {'name':"Parity 3",            'range':[84,89]},

    {'name':"L2P",                 'range':[90,90]},
    {'name':"Reserved 1",          'range':[91,113]},
    {'name':"Parity 4",            'range':[114,119]},

    {'name':"Reserved 2",          'range':[120,143]},
    {'name':"Parity 5",            'range':[144,149]},

    {'name':"Reserved 3",          'range':[150,173]},
    {'name':"Parity 6",            'range':[174,179]},

    {'name':"Reserved 4",          'range':[180,195]},
    {'name':"TGD",                 'range':[196,203], 'signed':True, 'factor':2**-31, 'unit':utility.SECOND},
    {'name':"Parity 7",            'range':[204,209]},
    
    #        IODC                          [210,217]
    {'name':"toC",                 'range':[218,233],                'factor':2**4,   'unit':utility.SECOND},
    {'name':"Parity 8",            'range':[234,239]},

    {'name':"af2",                 'range':[240,247], 'signed':True, 'factor':2**-55, 'unit':utility.SECOND_PER_SECOND_SQUARED},
    {'name':"af1",                 'range':[248,263], 'signed':True, 'factor':2**-43, 'unit':utility.SECOND_PER_SECOND},
    {'name':"Parity 9",            'range':[264,269]},

    {'name':"af0",                 'range':[270,291], 'signed':True, 'factor':2**-31, 'unit':utility.SECOND},
    {'name':"PC 2",                'range':[292,293]},
    {'name':"Parity 10",           'range':[294,299]}]

L1CADictEphemeris1 = [
    {'name':"Preamble",            'range':[0,7]},
    {'name':"TLM Message",         'range':[8,21]},
    {'name':"ISF",                 'range':[22,22]},
    {'name':"Reserved",            'range':[23,23]},
    {'name':"Parity 1",            'range':[24,29]},

    {'name':"Truncated TOW Count", 'range':[30,46],                              'factor':6,      'unit':utility.SECOND},
    {'name':"AF",                  'range':[47,47]},
    {'name':"AS",                  'range':[48,48]},
    {'name':"SubFrame ID",         'range':[49,51]},
    {'name':"PC 1",                'range':[52,53]},
    {'name':"Parity 2",            'range':[54,59]},

    {'name':"IODE",                'range':[60,67]},
    {'name':"Crs",                 'range':[68,83],               'signed':True, 'factor':2**-5,  'unit':utility.METER},
    {'name':"Parity 3",            'range':[84,89]},

    {'name':"DeltaN",              'range':[90,105],              'signed':True, 'factor':2**-43, 'unit':utility.SEMICIRCLE_PER_SECOND},
    {'name':"M0",                  'range':[[106,113],[120,143]], 'signed':True, 'factor':2**-31, 'unit':utility.SEMICIRCLE},
    {'name':"Parity 4",            'range':[114,119]},

    #        M0                            [120,143]
    {'name':"Parity 5",            'range':[144,149]},

    {'name':"Cuc",                 'range':[150,165],             'signed':True, 'factor':2**-29, 'unit':utility.RADIAN},
    {'name':"e",                   'range':[[166,173],[180,203]],                'factor':2**-33},
    {'name':"Parity 6",            'range':[174,179]},

    #        e                             [180,203]
    {'name':"Parity 7",            'range':[204,209]},

    {'name':"Cus",                 'range':[210,225],             'signed':True, 'factor':2**-29, 'unit':utility.RADIAN},
    {'name':"SqrtA",               'range':[[226,233],[240,263]],                'factor':2**-19, 'unit':utility.METER_SQUARE_ROOT},
    {'name':"Parity 8",            'range':[234,239]},

    #        SqrtA                         [240,263]
    {'name':"Parity 9",            'range':[264,269]},

    {'name':"toe",                 'range':[270,285],                            'factor':2**4,   'unit':utility.SECOND},
    {'name':"FIT",                 'range':[286,286]},
    {'name':"AODO",                'range':[287,291],                            'factor':900,    'unit':utility.SECOND},
    {'name':"PC 2",                'range':[292,293]},
    {'name':"Parity 10",           'range':[294,299]}]

L1CADictEphemeris2 = [
    {'name':"Preamble",            'range':[0,7]},
    {'name':"TLM Message",         'range':[8,21]},
    {'name':"ISF",                 'range':[22,22]},
    {'name':"Reserved",            'range':[23,23]},
    {'name':"Parity 1",            'range':[24,29]},

    {'name':"Truncated TOW Count", 'range':[30,46],                              'factor':6,      'unit':utility.SECOND},
    {'name':"AF",                  'range':[47,47]},
    {'name':"AS",                  'range':[48,48]},
    {'name':"SubFrame ID",         'range':[49,51]},
    {'name':"PC 1",                'range':[52,53]},
    {'name':"Parity 2",            'range':[54,59]},

    {'name':"Cic",                 'range':[60,75],               'signed':True, 'factor':2**-29, 'unit':utility.RADIAN},
    {'name':"Omega0",              'range':[[76,83],[90,113]],    'signed':True, 'factor':2**-31, 'unit':utility.SEMICIRCLE},
    {'name':"Parity 3",            'range':[84,89]},

    #        Omega0                        [90,113]
    {'name':"Parity 4",            'range':[114,119]},

    {'name':"Cis",                 'range':[120,135],             'signed':True, 'factor':2**-29, 'unit':utility.RADIAN},
    {'name':"i0",                  'range':[[136,143],[150,173]], 'signed':True, 'factor':2**-31, 'unit':utility.SEMICIRCLE},
    {'name':"Parity 5",            'range':[144,149]},

    #        i0                            [150,173]
    {'name':"Parity 6",            'range':[174,179]},

    {'name':"Crc",                 'range':[180,195],             'signed':True, 'factor':2**-5,  'unit':utility.METER},
    {'name':"Omega",               'range':[[196,203],[210,233]], 'signed':True, 'factor':2**-31, 'unit':utility.SEMICIRCLE},
    {'name':"Parity 7",            'range':[204,209]},

    #        Omega                         [210,233]
    {'name':"Parity 8",            'range':[234,239]},

    {'name':"OmegaDot",            'range':[240,263],             'signed':True, 'factor':2**-43, 'unit':utility.SEMICIRCLE_PER_SECOND},
    {'name':"Parity 9",            'range':[264,269]},
    
    {'name':"IODE",                'range':[270,277]},
    {'name':"iDot",                'range':[278,291],             'signed':True, 'factor':2**-43, 'unit':utility.SEMICIRCLE_PER_SECOND},
    {'name':"PC 2",                'range':[292,293]},
    {'name':"Parity 10",           'range':[294,299]}]

L1CAQZSSDictEphemeris = {1:L1CADictSVClock, 2:L1CADictEphemeris1, 3:L1CADictEphemeris2}

L1CADictReserved = [
    {'name':"Preamble",            'range':[0,7]},
    {'name':"TLM Message",         'range':[8,21]},
    {'name':"ISF",                 'range':[22,22]},
    {'name':"Reserved",            'range':[23,23]},
    {'name':"Parity 1",            'range':[24,29]},

    {'name':"Truncated TOW Count", 'range':[30,46],    'factor':6, 'unit':utility.SECOND},
    {'name':"AF",                  'range':[47,47]},
    {'name':"AS",                  'range':[48,48]},
    {'name':"SubFrame ID",         'range':[49,51]},
    {'name':"PC 1",                'range':[52,53]},
    {'name':"Parity 2",            'range':[54,59]},

    {'name':"Data ID",             'range':[60,61]},
    {'name':"svID",                'range':[62,67]},
    {'name':"Reserved 1",          'range':[68,83]},
    {'name':"Parity 3",            'range':[84,89]},

    {'name':"Reserved 2",          'range':[90,113]},
    {'name':"Parity 4",            'range':[114,119]},

    {'name':"Reserved 3",          'range':[120,143]},
    {'name':"Parity 5",            'range':[144,149]},

    {'name':"Reserved 4",          'range':[150,173]},
    {'name':"Parity 6",            'range':[174,179]},
    {'name':"Reserved 5",          'range':[180,203]},
    {'name':"Parity 7",            'range':[204,209]},

    {'name':"Reserved 6",          'range':[210,233]},
    {'name':"Parity 8",            'range':[234,239]},

    {'name':"Reserved 7",          'range':[240,247]},
    {'name':"Reserved system use", 'range':[248,263]},
    {'name':"Parity 9",            'range':[264,269]},

    {'name':"Reserved 8",          'range':[270,291]},
    {'name':"PC 2",                'range':[291,293]},
    {'name':"Parity 10",           'range':[294,299]}]

L1CADictSpecialMessage = [
    {'name':"Preamble",            'range':[0,7]},
    {'name':"TLM Message",         'range':[8,21]},
    {'name':"ISF",                 'range':[22,22]},
    {'name':"Reserved",            'range':[23,23]},
    {'name':"Parity 1",            'range':[24,29]},

    {'name':"Truncated TOW Count", 'range':[30,46],   'factor':6, 'unit':utility.SECOND},
    {'name':"AF",                  'range':[47,47]},
    {'name':"AS",                  'range':[48,48]},
    {'name':"SubFrame ID",         'range':[49,51]},
    {'name':"PC 1",                'range':[52,53]},
    {'name':"Parity 2",            'range':[54,59]},

    {'name':"Data ID",             'range':[60,61]},
    {'name':"svID",                'range':[62,67]},
    {'name':"Special message 1",   'range':[68,83]},
    {'name':"Parity 3",            'range':[84,89]},

    {'name':"Special message 2",   'range':[90,113]},
    {'name':"Parity 4",            'range':[114,119]},

    {'name':"Special message 3",   'range':[120,143]},
    {'name':"Parity 5",            'range':[144,149]},

    {'name':"Special message 4",   'range':[150,173]},
    {'name':"Parity 6",            'range':[174,179]},

    {'name':"Special message 5",   'range':[180,203]},
    {'name':"Parity 7",            'range':[204,209]},

    {'name':"Special message 6",   'range':[210,233]},
    {'name':"Parity 8",            'range':[234,239]},

    {'name':"Special message 7",   'range':[240,263]},
    {'name':"Parity 9",            'range':[264,269]},

    {'name':"Special message 8",   'range':[290,291]},
    {'name':"PC 2",                'range':[292,293]},
    {'name':"Parity 10",           'range':[294,299]}]

L1CADictIONOAndUTC = [
    {'name':"Preamble",            'range':[0,7]},
    {'name':"TLM Message",         'range':[8,21]},
    {'name':"ISF",                 'range':[22,22]},
    {'name':"Reserved",            'range':[23,23]},
    {'name':"Parity 1",            'range':[24,29]},

    {'name':"Truncated TOW Count", 'range':[30,46],                              'factor':6,      'unit':utility.SECOND},
    {'name':"AF",                  'range':[47,47]},
    {'name':"AS",                  'range':[48,48]},
    {'name':"SubFrame ID",         'range':[49,51]},
    {'name':"PC 1",                'range':[52,53]},
    {'name':"Parity 2",            'range':[54,59]},

    {'name':"Data ID",             'range':[60,61]},
    {'name':"svID",                'range':[62,67]},
    {'name':"Alpha0",              'range':[68,75],               'signed':True, 'factor':2**-30, 'unit':utility.SECOND},
    {'name':"Alpha1",              'range':[76,83],               'signed':True, 'factor':2**-27, 'unit':utility.SECOND_PER_SEMICIRCLE},
    {'name':"Parity 3",            'range':[84,89]},

    {'name':"Alpha2",              'range':[90,97],               'signed':True, 'factor':2**-24, 'unit':utility.SECOND_PER_SEMICIRCLE_SQUARED},
    {'name':"Alpha3",              'range':[98,105],              'signed':True, 'factor':2**-24, 'unit':utility.SECOND_PER_SEMICIRCLE_CUBE},
    {'name':"Beta0",               'range':[106,113],             'signed':True, 'factor':2**11,  'unit':utility.SECOND},
    {'name':"Parity 4",            'range':[114,119]},

    {'name':"Beta1",               'range':[120,127],             'signed':True, 'factor':2**14,  'unit':utility.SECOND_PER_SEMICIRCLE},
    {'name':"Beta2",               'range':[128,135],             'signed':True, 'factor':2**16,  'unit':utility.SECOND_PER_SEMICIRCLE_SQUARED},
    {'name':"Beta3",               'range':[136,143],             'signed':True, 'factor':2**16,  'unit':utility.SECOND_PER_SEMICIRCLE_CUBE},
    {'name':"Parity 5",            'range':[144,149]},

    {'name':"A1",                  'range':[150,173],             'signed':True, 'factor':2**-50, 'unit':utility.SECOND_PER_SECOND},
    {'name':"Parity 6",            'range':[174,179]},

    {'name':"A0",                  'range':[[180,203],[210,217]], 'signed':True, 'factor':2**-30, 'unit':utility.SECOND},
    {'name':"Parity 7",            'range':[204,209]},

    #        A0                            [210,217]
    {'name':"tot",                 'range':[218,225],                            'factor':2**12,  'unit':utility.SECOND},
    {'name':"WNt",                 'range':[226,233],                                             'unit':utility.WEEK},
    {'name':"Parity 8",            'range':[234,239]},

    {'name':"Delta-tLS",           'range':[240,247],             'signed':True,                  'unit':utility.SECOND},
    {'name':"WNLSF",               'range':[248,255],                                             'unit':utility.WEEK},
    {'name':"DN",                  'range':[256,263],                                             'unit':utility.DAY},
    {'name':"Parity 9",            'range':[264,269]},
    
    {'name':"Delta-tLSF",          'range':[270,277],             'signed':True,                  'unit':utility.SECOND},
    {'name':"Reserved system use", 'range':[278,291]},
    {'name':"PC 2",                'range':[292,293]},
    {'name':"Parity 10",           'range':[294,299] }]

L1CADictAlmanac = [
    {'name':"Preamble",            'range':[0,7]},
    {'name':"TLM Message",         'range':[8,21]},
    {'name':"ISF",                 'range':[22,22]},
    {'name':"Reserved",            'range':[23,23]},
    {'name':"Parity 1",            'range':[24,29]},

    {'name':"Truncated TOW Count", 'range':[30,46],                              'factor':6,      'unit':utility.SECOND},
    {'name':"AF",                  'range':[47,47]},
    {'name':"AS",                  'range':[48,48]},
    {'name':"SubFrame ID",         'range':[49,51]},
    {'name':"PC 1",                'range':[52,53]},
    {'name':"Parity 2",            'range':[54,59]},

    {'name':"Data ID",             'range':[60,61]},
    {'name':"svID",                'range':[62,67]},
    {'name':"e",                   'range':[68,83],                              'factor':2**-21},
    {'name':"Parity 3",            'range':[84,89]},

    {'name':"toa",                 'range':[90,97],                              'factor':2**12,  'unit':utility.SECOND},
    {'name':"delta i",             'range':[98,113],              'signed':True, 'factor':2**-19, 'unit':utility.SEMICIRCLE},
    {'name':"Parity 4",            'range':[114,119]},

    {'name':"OmegaDot",            'range':[120,135],             'signed':True, 'factor':2**-38, 'unit':utility.SEMICIRCLE_PER_SECOND},
    {'name':"SV Health",           'range':[136,143]},
    {'name':"Parity 5",            'range':[144,149]},

    {'name':"SqrtA",               'range':[150,173],                            'factor':2**-11, 'unit':utility.METER_SQUARE_ROOT},
    {'name':"Parity 6",            'range':[174,179]},
    
    {'name':"Omega0",              'range':[180,203],             'signed':True, 'factor':2**-23, 'unit':utility.SEMICIRCLE},
    {'name':"Parity 7",            'range':[204,209]},

    {'name':"Omega",               'range':[210,233],             'signed':True, 'factor':2**-23, 'unit':utility.SEMICIRCLE},
    {'name':"Parity 8",            'range':[234,239]},

    {'name':"M0",                  'range':[240,263],             'signed':True, 'factor':2**-23, 'unit':utility.SEMICIRCLE},
    {'name':"Parity 9",            'range':[264,269]},
    
    {'name':"af0",                 'range':[[270,277],[289,291]], 'signed':True, 'factor':2**-20, 'unit':utility.SECOND},
    {'name':"af1",                 'range':[278,288],             'signed':True, 'factor':2**-38, 'unit':utility.SECOND_PER_SECOND},
    #        af0                           [289,291]
    {'name':"PC 2",                'range':[292,293]},
    {'name':"Parity 10",           'range':[294,299]}]

L1CADictAlmanacEpochAndHealth = [
    {'name':"Preamble",            'range':[0,7]},
    {'name':"TLM Message",         'range':[8,21]},
    {'name':"ISF",                 'range':[22,22]},
    {'name':"Reserved",            'range':[23,23]},
    {'name':"Parity 1",            'range':[24,29]},

    {'name':"Truncated TOW Count", 'range':[30,46], 'factor':6,     'unit':utility.SECOND},
    {'name':"AF",                  'range':[47,47]},
    {'name':"AS",                  'range':[48,48]},
    {'name':"SubFrame ID",         'range':[49,51]},
    {'name':"PC 1",                'range':[52,53]},
    {'name':"Parity 2",            'range':[54,59]},

    {'name':"Data ID",             'range':[60,61]},
    {'name':"svID",                'range':[62,67]},
    {'name':"toa",                 'range':[68,75], 'factor':2**12, 'unit':utility.SECOND},
    {'name':"WNa",                 'range':[76,83],                 'unit':utility.WEEK},
    {'name':"Parity 3",            'range':[84,89]},

    {'name':"SV Health PRN 193",   'range':[90,95]},
    {'name':"SV Health PRN 194",   'range':[96,101]},
    {'name':"SV Health PRN 195",   'range':[102,107]},
    {'name':"SV Health PRN 196",   'range':[108,113]},
    {'name':"Parity 4",            'range':[114,119]},

    {'name':"SV Health PRN 197",   'range':[120,125]},
    {'name':"SV Health PRN 198",   'range':[126,131]},
    {'name':"SV Health PRN 199",   'range':[132,137]},
    {'name':"SV Health PRN 200",   'range':[138,143]},
    {'name':"Parity 5",            'range':[144,149]},

    {'name':"SV Health PRN 201",   'range':[150,155]},
    {'name':"SV Health PRN 202",   'range':[156,161]},
    {'name':"Reserved 2",          'range':[162,167]},
    {'name':"Reserved 3",          'range':[168,173]},
    {'name':"Parity 6",            'range':[174,179]},

    {'name':"Reserved 4",          'range':[180,185]},
    {'name':"Reserved 5",          'range':[186,191]},
    {'name':"Reserved 6",          'range':[192,197]},
    {'name':"Reserved 7",          'range':[198,203]},
    {'name':"Parity 7",            'range':[202,209]},

    {'name':"Reserved 8",          'range':[210,215]},
    {'name':"Reserved 9",          'range':[216,221]},
    {'name':"Reserved 10",         'range':[222,227]},
    {'name':"Reserved 11",         'range':[228,233]},
    {'name':"Parity 8",            'range':[234,239]},

    {'name':"Reserved 12",         'range':[240,245]},
    {'name':"Reserved 13",         'range':[246,251]},
    {'name':"Reserved 14",         'range':[252,257]},
    {'name':"Reserved 15",         'range':[258,263]},
    {'name':"Parity 9",            'range':[264,269]},

    {'name':"Reserved 16",         'range':[270,275]},
    {'name':"Reserved system use", 'range':[276,291]},
    {'name':"PC 2",                'range':[292,293]},
    {'name':"Parity 10",           'range':[294,299]}]

def getQZSSL1CANavigationMessageInBinary(message):
    words = message.split(" ")
    decodedMessage = ''
    for word in words[0:]:
        word = bin(int(word, 16))[2:].zfill(utility.WORD_SIZE)
        decodedMessage = decodedMessage + word[2:] # Remove padding at the start of the word
    return decodedMessage

def decodeQZSSL1CANavigationMessageInBinary(message):
    words = message.split(" ")
    inverseWord = ''
    decodedMessage = ''

    for word in words[0:]:
        word = bin(int(word, 16))[2:].zfill(utility.WORD_SIZE)
        word = word[2:] # Remove padding at the start of the word
        if inverseWord == '1':
            decodedMessage = decodedMessage + utility.getInversedBinaryValue(word[0:24]) + word[24:31]
        else:
            decodedMessage = decodedMessage + word
        inverseWord = word[utility.WORD_SIZE - 3]

    return decodedMessage


L1SDictBase = [{'name':"Preamble",  'range':[0,7]},
               {'name':"TM",        'range':[8,13]}]

L1SDictStationInfo = [{'name':"Preamble", 'range':[0,7]},
                      {'name':"TM",       'range':[8,13]},

                      {'name':"GMScode1", 'range':[14,19]},
                      {'name':"GMSLat1",  'range':[20,34], 'signed':True, 'factor':0.005},
                      {'name':"GMSLon1",  'range':[35,49], 'signed':True, 'factor':0.005},
                      {'name':"GMSHgt1",  'range':[50,55], 'factor':50, 'unit':utility.METER},

                      {'name':"GMScode2", 'range':[56,61]},
                      {'name':"GMSLat2",  'range':[62,76], 'signed':True, 'factor':0.005},
                      {'name':"GMSLon2",  'range':[77,91], 'signed':True, 'factor':0.005},
                      {'name':"GMSHgt2",  'range':[92,97], 'factor':50, 'unit':utility.METER},

                      {'name':"GMScode3", 'range':[98,103]},
                      {'name':"GMSLat3",  'range':[104,118], 'signed':True, 'factor':0.005},
                      {'name':"GMSLon3",  'range':[119,133], 'signed':True, 'factor':0.005},
                      {'name':"GMSHgt3",  'range':[134,139], 'factor':50, 'unit':utility.METER},

                      {'name':"GMScode4", 'range':[140,145]},
                      {'name':"GMSLat4",  'range':[146,160], 'signed':True, 'factor':0.005},
                      {'name':"GMSLon4",  'range':[161,175], 'signed':True, 'factor':0.005},
                      {'name':"GMSHgt4",  'range':[176,181], 'factor':50, 'unit':utility.METER},

                      {'name':"GMScode5", 'range':[182,187]},
                      {'name':"GMSLat5",  'range':[188,202], 'signed':True, 'factor':0.005},
                      {'name':"GMSLon5",  'range':[203,217], 'signed':True, 'factor':0.005},
                      {'name':"GMSHgt5",  'range':[218,223], 'factor':50, 'unit':utility.METER},

                      {'name':"Spare",    'range':[224,225]}]

L1SDictPrnMask = [{'name':"Preamble",    'range':[0,7]},
                  {'name':"TM",          'range':[8,13]},
                  {'name':"IODP",        'range':[14,15]},
                  {'name':"GpsMask",     'range':[16,79]},
                  {'name':"QzssMask",    'range':[80,88]},
                  {'name':"GlonassMask", 'range':[89,124]},
                  {'name':"GalileoMask", 'range':[125,160]},
                  {'name':"BeiDouMask",  'range':[161,196]},
                  {'name':"Spare",       'range':[197,225]}]

L1SDictDataIssueNumber = [{'name':"Preamble", 'range':[0,7]},
                          {'name':"TM",       'range':[8,13]},
                          {'name':"IODI",     'range':[14,15]},
                          {'name':"MaskSVs",  'range':[16,38]},

                          {'name':"IOD1",     'range':[39,46]},
                          {'name':"IOD2",     'range':[47,54]},
                          {'name':"IOD3",     'range':[55,62]},
                          {'name':"IOD4",     'range':[63,70]},
                          {'name':"IOD5",     'range':[71,78]},
                          {'name':"IOD6",     'range':[79,86]},
                          {'name':"IOD7",     'range':[87,94]},
                          {'name':"IOD8",     'range':[95,102]},
                          {'name':"IOD9",     'range':[103,110]},
                          {'name':"IOD10",    'range':[111,118]},
                          {'name':"IOD11",    'range':[119,126]},
                          {'name':"IOD12",    'range':[127,134]},
                          {'name':"IOD13",    'range':[135,142]},
                          {'name':"IOD14",    'range':[143,150]},
                          {'name':"IOD15",    'range':[151,158]},
                          {'name':"IOD16",    'range':[159,166]},
                          {'name':"IOD17",    'range':[167,174]},
                          {'name':"IOD18",    'range':[175,182]},
                          {'name':"IOD19",    'range':[183,190]},
                          {'name':"IOD20",    'range':[191,198]},
                          {'name':"IOD21",    'range':[199,206]},
                          {'name':"IOD22",    'range':[207,214]},
                          {'name':"IOD23",    'range':[215,222]},

                          {'name':"IODP",     'range':[223,224]},
                          {'name':"Spare",    'range':[225,225]}]

L1SDictDGPSCorrection = [{'name':"Preamble",  'range':[0,7]},
                         {'name':"TM",        'range':[8,13]},
                         {'name':"IODP",      'range':[14,15]},
                         {'name':"IODI",      'range':[16,17]},
                         {'name':"GMScode",   'range':[18,23]},
                         {'name':"GMSHealth", 'range':[24,24]},
                         {'name':"MaskSVs",   'range':[25,47]},

                         {'name':"PRC1",      'range':[48,59],   'signed':True, 'factor':0.04, 'unit':utility.METER},
                         {'name':"PRC2",      'range':[60,71],   'signed':True, 'factor':0.04, 'unit':utility.METER},
                         {'name':"PRC3",      'range':[72,83],   'signed':True, 'factor':0.04, 'unit':utility.METER},
                         {'name':"PRC4",      'range':[84,95],   'signed':True, 'factor':0.04, 'unit':utility.METER},
                         {'name':"PRC5",      'range':[96,107],  'signed':True, 'factor':0.04, 'unit':utility.METER},
                         {'name':"PRC6",      'range':[108,119], 'signed':True, 'factor':0.04, 'unit':utility.METER},
                         {'name':"PRC7",      'range':[120,131], 'signed':True, 'factor':0.04, 'unit':utility.METER},
                         {'name':"PRC8",      'range':[132,143], 'signed':True, 'factor':0.04, 'unit':utility.METER},
                         {'name':"PRC9",      'range':[144,155], 'signed':True, 'factor':0.04, 'unit':utility.METER},
                         {'name':"PRC10",     'range':[156,167], 'signed':True, 'factor':0.04, 'unit':utility.METER},
                         {'name':"PRC11",     'range':[168,179], 'signed':True, 'factor':0.04, 'unit':utility.METER},
                         {'name':"PRC12",     'range':[180,191], 'signed':True, 'factor':0.04, 'unit':utility.METER},
                         {'name':"PRC13",     'range':[192,203], 'signed':True, 'factor':0.04, 'unit':utility.METER},
                         {'name':"PRC14",     'range':[204,215], 'signed':True, 'factor':0.04, 'unit':utility.METER},
                         
                         {'name':"Spare",     'range':[216,225]}]

L1SDictHealth = [{'name':"Preamble",      'range':[0,7]},
                 {'name':"TM",            'range':[8,13]},
                 {'name':"GpsHealth",     'range':[16,79]},
                 {'name':"QzssHealth",    'range':[80,88]},
                 {'name':"GlonassHealth", 'range':[89,124]},
                 {'name':"GalileoHealth", 'range':[125,160]},
                 {'name':"BeiDouHealth",  'range':[161,196]},
                 {'name':"Spare",         'range':[197,225]}]

"""
    Main functions for decoding a QZSS downlink navigation message.
"""

def getDictQZSSL1CANavigationMessageFromBinary(binaryMessage):
    sfID = int(binaryMessage[49:52], 2)
    svID = int(binaryMessage[62:68], 2)
    preamble = int(binaryMessage[0:8], 2)
	
    if preamble != 0b10001011:
        raise ValueError('Preambule value is wrong! Make sure your file has the correct format (check header commas).')

    dictToUse = {}
    if sfID in L1CAQZSSDictEphemeris:
        dictToUse = L1CAQZSSDictEphemeris[sfID]
    else:
        if svID in [1,2,3,4,5,6,7,8,9]:
            dictToUse = L1CADictAlmanac
        if svID == 51:
            dictToUse = L1CADictAlmanacEpochAndHealth
        elif svID == 55:
            dictToUse = L1CADictSpecialMessage
        elif svID in [56,61]:
            dictToUse = L1CADictIONOAndUTC
        else:
            dictToUse = L1CADictReserved

    return utility.fillDict(binaryMessage, dictToUse)

def getDictQZSSL1CAEncodedNavigationMessage(message):
    binaryMessage = decodeQZSSL1CANavigationMessageInBinary(message)
    return getDictQZSSL1CANavigationMessageFromBinary(binaryMessage)

def getDictQZSSL1CADecodedNavigationMessage(message):
    binaryMessage = getQZSSL1CANavigationMessageInBinary(message)
    return getDictQZSSL1CANavigationMessageFromBinary(binaryMessage)

def getDictQZSSL1SNavigationMessageFromBinary(binaryMessage):
    msgType = int(binaryMessage[8:14], 2)

    dictToUse = L1SDictBase

    if msgType == 47:
        dictToUse = L1SDictStationInfo
    elif msgType == 48:
        dictToUse = L1SDictPrnMask
    elif msgType == 49:
        dictToUse = L1SDictDataIssueNumber
    elif msgType == 50:
        dictToUse = L1SDictDGPSCorrection
    elif msgType == 51:
        dictToUse = L1SDictHealth

    return utility.fillDict(binaryMessage, dictToUse)

def getDictQZSSL1SDecodedNavigationMessage(message):
    binaryMessage = utility.convertToBinaryNavigationMessage(message, 256)
    return getDictQZSSL1SNavigationMessageFromBinary(binaryMessage)

def getDictQZSSL6DecodedNavigationMessage(message):
    dict, seq = getDictQzssCLASDecodedFrame(message)
    return dict
