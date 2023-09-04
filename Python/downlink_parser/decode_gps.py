#!/usr/bin/env python3
"""
    Messages supported :
        GPS L5 type : 10 - 11 - 12 - 30 - 32 - 33
        GPS L1CA
        GPS L1C
"""

import utility

"""
    Informations for decoding GPS L5 navigation messages.
"""
L5DictType10 = [
    {'name':"Preamble",    'range':[0,7]},
    {'name':"PRN",         'range':[8,13]},
    {'name':"Type ID",     'range':[14,19]},
    {'name':"TOW",         'range':[20,36]},
    {'name':"Alert",       'range':[37,37]},
    {'name':"WNn",         'range':[38,50],                                   'unit':utility.WEEK},
    {'name':"L1H",         'range':[51,51]},
    {'name':"L2H",         'range':[52,52]},
    {'name':"L5H",         'range':[53,53]},
    {'name':"top",         'range':[54,64],                  'factor':300,    'unit':utility.SECOND},
    {'name':"URAED",       'range':[65,69],   'signed':True},
    {'name':"toe",         'range':[70,80],                  'factor':300,    'unit':utility.SECOND},
    {'name':"DeltaA",      'range':[81,106],  'signed':True, 'factor':2**-9,  'unit':utility.METER},
    {'name':"Adot",        'range':[107,131], 'signed':True, 'factor':2**-21, 'unit':utility.METER_PER_SECOND},
    {'name':"Delta-n0",    'range':[132,148], 'signed':True, 'factor':2**-44, 'unit':utility.SEMICIRCLE_PER_SECOND},
    {'name':"Delta-n0dot", 'range':[149,171], 'signed':True, 'factor':2**-57, 'unit':utility.SEMICIRCLE_PER_SECOND_SQUARED},
    {'name':"M0-n",        'range':[172,204], 'signed':True, 'factor':2**-32, 'unit':utility.SEMICIRCLE},
    {'name':"en",          'range':[205,237],                'factor':2**-34},
    {'name':"Omega-n",     'range':[238,270], 'signed':True, 'factor':2**-32, 'unit':utility.SEMICIRCLE},
    {'name':"Integrity",   'range':[271,271]},
    {'name':"L2C",         'range':[272,272]},
    {'name':"Reserved",    'range':[273,275]},
    {'name':"CRC",         'range':[276,299] }]

L5DictType11 = [
    {'name':"Preamble",       'range':[0,7]},
    {'name':"PRN",            'range':[8,13]},
    {'name':"Type ID",        'range':[14,19]},
    {'name':"TOW",            'range':[20,36]},
    {'name':"Alert",          'range':[37,37]},
    {'name':"toe",            'range':[38,48],                  'factor':300,    'unit':utility.SECOND},
    {'name':"Omega0-n",       'range':[49,81],   'signed':True, 'factor':2**-32, 'unit':utility.SEMICIRCLE},
    {'name':"i0-n",           'range':[82,114],  'signed':True, 'factor':2**-32, 'unit':utility.SEMICIRCLE},
    {'name':"DeltaOmegaDot",  'range':[115,131], 'signed':True, 'factor':2**-44, 'unit':utility.SEMICIRCLE_PER_SECOND},
    {'name':"i0-ndot",        'range':[132,146], 'signed':True, 'factor':2**-44, 'unit':utility.SEMICIRCLE_PER_SECOND},
    {'name':"Cis-n",          'range':[147,162], 'signed':True, 'factor':2**-30, 'unit':utility.RADIAN},
    {'name':"Cic-n",          'range':[163,178], 'signed':True, 'factor':2**-30, 'unit':utility.RADIAN},
    {'name':"Crs-n",          'range':[179,202], 'signed':True, 'factor':2**-8,  'unit':utility.METER},
    {'name':"Crc-n",          'range':[203,226], 'signed':True, 'factor':2**-8,  'unit':utility.METER},
    {'name':"Cus-n",          'range':[227,247], 'signed':True, 'factor':2**-30, 'unit':utility.RADIAN},
    {'name':"Cuc-n",          'range':[248,268], 'signed':True, 'factor':2**-30, 'unit':utility.RADIAN},
    {'name':"Reserved",       'range':[269,275]},
    {'name':"CRC",            'range':[276,299]}]

L5DictType12 = [
    {'name':"Preamble",       'range':[0,7]},
    {'name':"PRN",            'range':[8,13]},
    {'name':"Type ID",        'range':[14,19]},
    {'name':"TOW",            'range':[20,36]},
    {'name':"Alert",          'range':[37,37]},
    {'name':"WNa",            'range':[38,50],                  		         'unit':utility.WEEK},
    {'name':"toa",            'range':[51,58],   'signed':True, 'factor':2**12,  'unit':utility.SECOND},
    {'name':"RAP1-Prn",       'range':[59,64]},
    {'name':"RAP1-DeltaA",    'range':[65,72],   'signed':True, 'factor':2**9,   'unit':utility.METER},
    {'name':"RAP1-Omega0",    'range':[73,79],   'signed':True, 'factor':2**-6,  'unit':utility.SEMICIRCLE},
    {'name':"RAP1-Phi0",      'range':[80,86],   'signed':True, 'factor':2**-6,  'unit':utility.SEMICIRCLE},
    {'name':"RAP1-L1Health",  'range':[87,87]},
    {'name':"RAP1-L2Health",  'range':[88,88]},
    {'name':"RAP1-L5Health",  'range':[89,89]},
    {'name':"RAP2-Prn",       'range':[90,95]},
    {'name':"RAP2-DeltaA",    'range':[96,103],   'signed':True, 'factor':2**9,   'unit':utility.METER},
    {'name':"RAP2-Omega0",    'range':[104,110],  'signed':True, 'factor':2**-6,  'unit':utility.SEMICIRCLE},
    {'name':"RAP2-Phi0",      'range':[111,117],  'signed':True, 'factor':2**-6,  'unit':utility.SEMICIRCLE},
    {'name':"RAP2-L1Health",  'range':[118,118]},
    {'name':"RAP2-L2Health",  'range':[119,119]},
    {'name':"RAP2-L5Health",  'range':[120,120]},
    {'name':"RAP3-Prn",       'range':[121,126]},
    {'name':"RAP3-DeltaA",    'range':[127,134],  'signed':True, 'factor':2**9,   'unit':utility.METER},
    {'name':"RAP3-Omega0",    'range':[135,141],  'signed':True, 'factor':2**-6,  'unit':utility.SEMICIRCLE},
    {'name':"RAP3-Phi0",      'range':[142,148],  'signed':True, 'factor':2**-6,  'unit':utility.SEMICIRCLE},
    {'name':"RAP3-L1Health",  'range':[149,149]},
    {'name':"RAP3-L2Health",  'range':[150,150]},
    {'name':"RAP3-L5Health",  'range':[151,151]},
    {'name':"RAP4-Prn",       'range':[152,157]},
    {'name':"RAP4-DeltaA",    'range':[158,165],  'signed':True, 'factor':2**9,   'unit':utility.METER},
    {'name':"RAP4-Omega0",    'range':[166,172],  'signed':True, 'factor':2**-6,  'unit':utility.SEMICIRCLE},
    {'name':"RAP4-Phi0",      'range':[173,179],  'signed':True, 'factor':2**-6,  'unit':utility.SEMICIRCLE},
    {'name':"RAP4-L1Health",  'range':[180,180]},
    {'name':"RAP4-L2Health",  'range':[181,181]},
    {'name':"RAP4-L5Health",  'range':[182,182]},
    {'name':"RAP5-Prn",       'range':[183,188]},
    {'name':"RAP5-DeltaA",    'range':[189,196],  'signed':True, 'factor':2**9,   'unit':utility.METER},
    {'name':"RAP5-Omega0",    'range':[197,203],  'signed':True, 'factor':2**-6,  'unit':utility.SEMICIRCLE},
    {'name':"RAP5-Phi0",      'range':[204,210],  'signed':True, 'factor':2**-6,  'unit':utility.SEMICIRCLE},
    {'name':"RAP5-L1Health",  'range':[211,211]},
    {'name':"RAP5-L2Health",  'range':[212,212]},
    {'name':"RAP5-L5Health",  'range':[213,213]},
    {'name':"RAP6-Prn",       'range':[214,219]},
    {'name':"RAP6-DeltaA",    'range':[220,227],  'signed':True, 'factor':2**9,   'unit':utility.METER},
    {'name':"RAP6-Omega0",    'range':[228,234],  'signed':True, 'factor':2**-6,  'unit':utility.SEMICIRCLE},
    {'name':"RAP6-Phi0",      'range':[235,241],  'signed':True, 'factor':2**-6,  'unit':utility.SEMICIRCLE},
    {'name':"RAP6-L1Health",  'range':[242,242]},
    {'name':"RAP6-L2Health",  'range':[243,243]},
    {'name':"RAP6-L5Health",  'range':[244,244]},
    {'name':"RAP7-Prn",       'range':[245,250]},
    {'name':"RAP7-DeltaA",    'range':[251,258],  'signed':True, 'factor':2**9,   'unit':utility.METER},
    {'name':"RAP7-Omega0",    'range':[259,265],  'signed':True, 'factor':2**-6,  'unit':utility.SEMICIRCLE},
    {'name':"RAP7-Phi0",      'range':[266,272],  'signed':True, 'factor':2**-6,  'unit':utility.SEMICIRCLE},
    {'name':"RAP7-L1Health",  'range':[273,273]},
    {'name':"RAP7-L2Health",  'range':[274,274]},
    {'name':"RAP7-L5Health",  'range':[275,275]},
    {'name':"CRC",            'range':[276,299]}]

L5DictType30 = [
    {'name':"Preamble",  'range':[0,7]},
    {'name':"PRN",       'range':[8,13]},
    {'name':"Type ID",   'range':[14,19]},
    {'name':"TOW",       'range':[20,36]},
    {'name':"Alert",     'range':[37,37]},
    {'name':"top",       'range':[38,48],                  'factor':300,    'unit':utility.SECOND},
    {'name':"URANED0",   'range':[49,53],   'signed':True},
    {'name':"URANED1",   'range':[54,56]},
    {'name':"URANED2",   'range':[57,59]},
    {'name':"toc",       'range':[60,70],                  'factor':300,    'unit':utility.SECOND},
    {'name':"af0-n",     'range':[71,96],   'signed':True, 'factor':2**-35, 'unit':utility.SECOND},
    {'name':"af1-n",     'range':[97,116],  'signed':True, 'factor':2**-48, 'unit':utility.SECOND_PER_SECOND},
    {'name':"af2-n",     'range':[117,126], 'signed':True, 'factor':2**-60, 'unit':utility.SECOND_PER_SECOND_SQUARED},
    {'name':"TGD",       'range':[127,139], 'signed':True, 'factor':2**-35, 'unit':utility.SECOND},
    {'name':"ISCL1C/A",  'range':[140,152], 'signed':True, 'factor':2**-35, 'unit':utility.SECOND},
    {'name':"ISCL2C",    'range':[153,165], 'signed':True, 'factor':2**-35, 'unit':utility.SECOND},
    {'name':"ISCL5I5",   'range':[166,178], 'signed':True, 'factor':2**-35, 'unit':utility.SECOND},
    {'name':"ISCL5Q5",   'range':[179,191], 'signed':True, 'factor':2**-35, 'unit':utility.SECOND},
    {'name':"Alpha0",    'range':[192,199], 'signed':True, 'factor':2**-30, 'unit':utility.SECOND},
    {'name':"Alpha1",    'range':[200,207], 'signed':True, 'factor':2**-27, 'unit':utility.SECOND_PER_SEMICIRCLE},
    {'name':"Alpha2",    'range':[208,215], 'signed':True, 'factor':2**-24, 'unit':utility.SECOND_PER_SEMICIRCLE_SQUARED},
    {'name':"Alpha3",    'range':[216,223], 'signed':True, 'factor':2**-24, 'unit':utility.SECOND_PER_SEMICIRCLE_CUBE},
    {'name':"Beta0",     'range':[224,231], 'signed':True, 'factor':2**11,  'unit':utility.SECOND},
    {'name':"Beta1",     'range':[232,239], 'signed':True, 'factor':2**14,  'unit':utility.SECOND_PER_SEMICIRCLE},
    {'name':"Beta2",     'range':[240,247], 'signed':True, 'factor':2**16,  'unit':utility.SECOND_PER_SEMICIRCLE_SQUARED},
    {'name':"Beta3",     'range':[248,255], 'signed':True, 'factor':2**16,  'unit':utility.SECOND_PER_SEMICIRCLE_CUBE},
    {'name':"WNOP",      'range':[256,263],                                 'unit':utility.WEEK},
    {'name':"Reserved",  'range':[263,275]},
    {'name':"CRC",       'range':[276,299]}]

L5DictType32 = [
    {'name':"Preamble",    'range':[0,7]},
    {'name':"PRN",         'range':[8,13]},
    {'name':"Type ID",     'range':[14,19]},
    {'name':"TOW",         'range':[20,36]},
    {'name':"Alert",       'range':[37,37]},
    {'name':"top",         'range':[38,48],                  'factor':300,    'unit':utility.SECOND},
    {'name':"URANED0",     'range':[49,53],   'signed':True},
    {'name':"URANED1",     'range':[54,56]},
    {'name':"URANED2",     'range':[57,59]},
    {'name':"toc",         'range':[60,70],                  'factor':300,    'unit':utility.SECOND},
    {'name':"af0-n",       'range':[71,96],   'signed':True, 'factor':2**-35, 'unit':utility.SECOND},
    {'name':"af1-n",       'range':[97,116],  'signed':True, 'factor':2**-48, 'unit':utility.SECOND_PER_SECOND},
    {'name':"af2-n",       'range':[117,126], 'signed':True, 'factor':2**-60, 'unit':utility.SECOND_PER_SECOND_SQUARED},
    {'name':"tEOP",        'range':[127,142],                'factor':2**4,   'unit':utility.SECOND},
    {'name':"PM-X",        'range':[143,163], 'signed':True, 'factor':2**-20, 'unit':utility.ARC_SECOND},
    {'name':"PM-Xdot",     'range':[164,178], 'signed':True, 'factor':2**-21, 'unit':utility.ARC_SECOND_PER_DAY},
    {'name':"PM-Y",        'range':[179,199], 'signed':True, 'factor':2**-20, 'unit':utility.ARC_PER_SECOND},
    {'name':"PM-Ydot",     'range':[200,214], 'signed':True, 'factor':2**-21, 'unit':utility.ARC_SECOND_PER_DAY},
    {'name':"DeltaUT1",    'range':[215,245], 'signed':True, 'factor':2**-24, 'unit':utility.SECOND},
    {'name':"DeltaUTdot1", 'range':[246,264], 'signed':True, 'factor':2**-25, 'unit':utility.SECOND_PER_DAY},
    {'name':"Reserved",    'range':[265,275]},
    {'name':"CRC",         'range':[276,299]}]

L5DictType33 = [
    {'name':"Preamble",   'range':[0,7]},
    {'name':"PRN",        'range':[8,13]},
    {'name':"Type ID",    'range':[14,19]},
    {'name':"TOW",        'range':[20,36]},
    {'name':"Alert",      'range':[37,37]},
    {'name':"top",        'range':[38,48],                   'factor':300,    'unit':utility.SECOND},
    {'name':"URANED0",    'range':[49,53],   'signed':True},
    {'name':"URANED1",    'range':[54,56]},
    {'name':"URANED2",    'range':[57,59]},
    {'name':"toc",        'range':[60,70],                  'factor':300,    'unit':utility.SECOND},
    {'name':"af0-n",      'range':[71,96],   'signed':True, 'factor':2**-35, 'unit':utility.SECOND},
    {'name':"af1-n",      'range':[97,116],  'signed':True, 'factor':2**-48, 'unit':utility.SECOND_PER_SECOND},
    {'name':"af2-n",      'range':[117,126], 'signed':True, 'factor':2**-60, 'unit':utility.SECOND_PER_SECOND_SQUARED},
    {'name':"A0-n",       'range':[127,143], 'signed':True, 'factor':2**-35, 'unit':utility.SECOND},
    {'name':"A1-n",       'range':[143,155], 'signed':True, 'factor':2**-51, 'unit':utility.SECOND_PER_SECOND},
    {'name':"A2-n",       'range':[156,162], 'signed':True, 'factor':2**-68, 'unit':utility.SECOND_PER_SECOND_SQUARED},
    {'name':"Delta-tLS",  'range':[163,170], 'signed':True,                  'unit':utility.SECOND},
    {'name':"tot",        'range':[171,186],                'factor':2**4,   'unit':utility.SECOND},
    {'name':"WNot",       'range':[187,199],                                 'unit':utility.WEEK},
    {'name':"WNLSF",      'range':[200,212],                                 'unit':utility.WEEK},
    {'name':"DN",         'range':[213,216],                                 'unit':utility.DAY},
    {'name':"Delta-tLSF", 'range':[217,224],                                 'unit':utility.SECOND},
    {'name':"Reserved",   'range':[225,275]},
    {'name':"CRC",        'range':[276,299]}]

L5DictType37 = [
    {'name':"Preamble",     'range':[0,7]},
    {'name':"PRN",          'range':[8,13]},
    {'name':"Type ID",      'range':[14,19]},
    {'name':"TOW",          'range':[20,36]},
    {'name':"Alert",        'range':[37,37]},
    {'name':"top",          'range':[38,48],                   'factor':300,    'unit':utility.SECOND},
    {'name':"URANED0",      'range':[49,53],   'signed':True},
    {'name':"URANED1",      'range':[54,56]},
    {'name':"URANED2",      'range':[57,59]},
    {'name':"toc",          'range':[60,70],                  'factor':300,    'unit':utility.SECOND},
    {'name':"af0-n",        'range':[71,96],   'signed':True, 'factor':2**-35, 'unit':utility.SECOND},
    {'name':"af1-n",        'range':[97,116],  'signed':True, 'factor':2**-48, 'unit':utility.SECOND_PER_SECOND},
    {'name':"af2-n",        'range':[117,126], 'signed':True, 'factor':2**-60, 'unit':utility.SECOND_PER_SECOND_SQUARED},
    {'name':"WNa",          'range':[127,139],                  		       'unit':utility.WEEK},
    {'name':"toa",          'range':[140,147], 'signed':True, 'factor':2**12,  'unit':utility.SECOND},
    {'name':"Alm-PRN",      'range':[148,153]},
    {'name':"Alm-L1Health", 'range':[154,154]},
    {'name':"Alm-L2Health", 'range':[155,155]},
    {'name':"Alm-L5Health", 'range':[156,156]},
    {'name':"Alm-e",        'range':[157,167],                'factor':2**-16},
    {'name':"Alm-DeltaI",   'range':[168,178], 'signed':True, 'factor':2**-14, 'unit':utility.SEMICIRCLE},
    {'name':"Alm-OmegaDot", 'range':[179,189], 'signed':True, 'factor':2**-33, 'unit':utility.SEMICIRCLE_PER_SECOND},
    {'name':"Alm-SqrtA",    'range':[190,206],                'factor':2**-4,  'unit':utility.METER_SQUARE_ROOT},
    {'name':"Alm-Omega0",   'range':[207,222], 'signed':True, 'factor':2**-15, 'unit':utility.SEMICIRCLE},
    {'name':"Alm-w",        'range':[223,238], 'signed':True, 'factor':2**-15, 'unit':utility.SEMICIRCLE},
    {'name':"Alm-M0",       'range':[239,254], 'signed':True, 'factor':2**-15, 'unit':utility.SEMICIRCLE},
    {'name':"Alm-af0",      'range':[255,265], 'signed':True, 'factor':2**-20, 'unit':utility.SECOND},
    {'name':"Alm-af1",      'range':[266,275], 'signed':True, 'factor':2**-37, 'unit':utility.SECOND_PER_SECOND},
    {'name':"CRC",          'range':[276,299]}]

L5GpsDictAll = {10:L5DictType10, 11:L5DictType11, 12:L5DictType12, 30:L5DictType30, 32:L5DictType32, 33:L5DictType33, 37:L5DictType37}

"""
    Informations for decoding GPS L1C/A navigation messages.
"""
L1CADictEphemeris1 = [
    {'name':"Preamble",            'range':[0,7]},
    {'name':"TLM Message",         'range':[8,21]},
    {'name':"ISF",                 'range':[22,22]},
    {'name':"Reserved",            'range':[23,23]},
    {'name':"Parity 1",            'range':[24,29]},

    {'name':"Truncated TOW Count", 'range':[30,46]},
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
    {'name':"t0C",                 'range':[218,233],                'factor':2**4,   'unit':utility.SECOND},
    {'name':"Parity 8",            'range':[234,239]},

    {'name':"af2",                 'range':[240,247], 'signed':True, 'factor':2**-55, 'unit':utility.SECOND_PER_SECOND_SQUARED},
    {'name':"af1",                 'range':[248,263], 'signed':True, 'factor':2**-43, 'unit':utility.SECOND_PER_SECOND},
    {'name':"Parity 9",            'range':[264,269]},

    {'name':"af0",                 'range':[270,291], 'signed':True, 'factor':2**-31, 'unit':utility.SECOND},
    {'name':"PC 2",                'range':[292,293]},
    {'name':"Parity 10",           'range':[294,299]}]

L1CADictEphemeris2 = [
    {'name':"Preamble",            'range':[0,7]},
    {'name':"TLM Message",         'range':[8,21]},
    {'name':"ISF",                 'range':[22,22]},
    {'name':"Reserved",            'range':[23,23]},
    {'name':"Parity 1",            'range':[24,29]},
    {'name':"Truncated TOW Count", 'range':[30,46]},
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
    {'name':"t0e",                 'range':[270,285],                            'factor':2**4,   'unit':utility.SECOND},
    {'name':"FIT",                 'range':[286,286]},
    {'name':"AODO",                'range':[287,291],                            'factor':900,    'unit':utility.SECOND},
    {'name':"PC 2",                'range':[292,293]},
    {'name':"Parity 10",           'range':[294,299]}]

L1CADictEphemeris3 = [
    {'name':"Preamble",            'range':[0,7]},
    {'name':"TLM Message",         'range':[8,21]},
    {'name':"ISF",                 'range':[22,22]},
    {'name':"Reserved",            'range':[23,23]},
    {'name':"Parity 1",            'range':[24,29]},
    {'name':"Truncated TOW Count", 'range':[30,46]},
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

L1CAGpsDictEphemeris = {1:L1CADictEphemeris1, 2:L1CADictEphemeris2, 3:L1CADictEphemeris3}

L1CADictSubframe4Reserved = [
    {'name':"Preamble",            'range':[0,7]},
    {'name':"TLM Message",         'range':[8,21]},
    {'name':"ISF",                 'range':[22,22]},
    {'name':"Reserved",            'range':[23,23]},
    {'name':"Parity 1",            'range':[24,29]},
    {'name':"Truncated TOW Count", 'range':[30,46]},
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

L1CADictSubframe4SystemUse= [
    {'name':"Preamble",              'range':[0,7]},
    {'name':"TLM Message",           'range':[8,21]},
    {'name':"ISF",                   'range':[22,22]},
    {'name':"Reserved",              'range':[23,23]},
    {'name':"Parity 1",              'range':[24,29]},
    {'name':"Truncated TOW Count",   'range':[30,46]},
    {'name':"AF",                    'range':[47,47]},
    {'name':"AS",                    'range':[48,48]},
    {'name':"SubFrame ID",           'range':[49,51]},
    {'name':"PC 1",                  'range':[52,53]},
    {'name':"Parity 2",              'range':[54,59]},
    {'name':"Data ID",               'range':[60,61]},
    {'name':"svID",                  'range':[62,67]},
    {'name':"Reserved system use 1", 'range':[68,83]},
    {'name':"Parity 3",              'range':[84,89]},
    {'name':"Reserved system use 2", 'range':[90,113]},
    {'name':"Parity 4",              'range':[114,119]},
    {'name':"Reserved system use 3", 'range':[120,143]},
    {'name':"Parity 5",              'range':[144,149]},
    {'name':"Reserved system use 4", 'range':[150,173]},
    {'name':"Parity 6",              'range':[174,179]},
    {'name':"Reserved system use 5", 'range':[180,203]},
    {'name':"Parity 7",              'range':[204,209]},
    {'name':"Reserved system use 6", 'range':[210,233]},
    {'name':"Parity 8",              'range':[234,239]},
    {'name':"Reserved system use 7", 'range':[240,263]},
    {'name':"Parity 9",              'range':[264,269]},
    {'name':"Reserved system use 8", 'range':[290,291]},
    {'name':"PC 2",                  'range':[292,293]},
    {'name':"Parity 10",             'range':[294,299]}]

L1CADictSubframe4SpecialMessage= [
    {'name':"Preamble",            'range':[0,7]},
    {'name':"TLM Message",         'range':[8,21]},
    {'name':"ISF",                 'range':[22,22]},
    {'name':"Reserved",            'range':[23,23]},
    {'name':"Parity 1",            'range':[24,29]},
    {'name':"Truncated TOW Count", 'range':[30,46]},
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

L1CADictSubframe4NMCT = [
    {'name':"Preamble",            'range':[0,7]},
    {'name':"TLM Message",         'range':[8,21]},
    {'name':"ISF",                 'range':[22,22]},
    {'name':"Reserved",            'range':[23,23]},
    {'name':"Parity 1",            'range':[24,29]},
    {'name':"Truncated TOW Count", 'range':[30,46]},
    {'name':"AF",                  'range':[47,47]},
    {'name':"AS",                  'range':[48,48]},
    {'name':"SubFrame ID",         'range':[49,51]},
    {'name':"PC 1",                'range':[52,53]},
    {'name':"Parity 2",            'range':[54,59]},
    {'name':"Data ID",             'range':[60,61]},
    {'name':"svID",                'range':[62,67]},
    {'name':"Availability",        'range':[68,69]},
    {'name':"ERD1",                'range':[70,75]},
    {'name':"ERD2",                'range':[76,81]},
    {'name':"ERD3",                'range':[[82,83],[90,93]]},
    {'name':"Parity 3",            'range':[84,89]},
    #        ERD3                          [90,93]
    {'name':"ERD4",                'range':[94,99]},
    {'name':"ERD5",                'range':[100,105]},
    {'name':"ERD6",                'range':[106,111]},
    {'name':"ERD7",                'range':[[112,113],[120,123]]},
    {'name':"Parity 4",            'range':[114,119]},
    #        ERD7                          [120,123]
    {'name':"ERD8",                'range':[124,129]},
    {'name':"ERD9",                'range':[130,135]},
    {'name':"ERD10",               'range':[136,141]},
    {'name':"ERD11",               'range':[[142,143],[150,153]]},
    {'name':"Parity 5",            'range':[144,149]},
    #        ERD11                         [150,153]
    {'name':"ERD12",               'range':[154,159]},
    {'name':"ERD13",               'range':[160,165]},
    {'name':"ERD14",               'range':[166,171]},
    {'name':"ERD15",               'range':[[172,173],[180,183]]},
    {'name':"Parity 6",            'range':[174,179]},
    #        ERD15                         [180,183]
    {'name':"ERD16",               'range':[184,189]},
    {'name':"ERD17",               'range':[190,195]},
    {'name':"ERD18",               'range':[196,201]},
    {'name':"ERD19",               'range':[[202,203],[210,213]]},
    {'name':"Parity 7",            'range':[204,209]},
    #        ERD19                         [210,213]
    {'name':"ERD20",               'range':[214,219]},
    {'name':"ERD21",               'range':[220,225]},
    {'name':"ERD22",               'range':[226,231]},
    {'name':"ERD23",               'range':[[232,233],[240,243]]},
    {'name':"Parity 8",            'range':[234,239]},
    #        ERD23                         [240,243]
    {'name':"ERD24",               'range':[244,249]},
    {'name':"ERD25",               'range':[250,255]},
    {'name':"ERD26",               'range':[256,261]},
    {'name':"ERD27",               'range':[[262,263],[270,273]]},
    {'name':"Parity 9",            'range':[264,269]},
    #        ERD27                         [270,273]
    {'name':"ERD28",               'range':[274,279]},
    {'name':"ERD29",               'range':[280,285]},
    {'name':"ERD30",               'range':[286,291]},
    {'name':"PC 2",                'range':[292,293]},
    {'name':"Parity 10",           'range':[294,299]}]

L1CADictSubframe4UTCIONO = [
    {'name':"Preamble",            'range':[0,7]},
    {'name':"TLM Message",         'range':[8,21]},
    {'name':"ISF",                 'range':[22,22]},
    {'name':"Reserved",            'range':[23,23]},
    {'name':"Parity 1",            'range':[24,29]},
    {'name':"Truncated TOW Count", 'range':[30,46]},
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

L1CADictSubframe4HAC = [
    {'name':"Preamble",            'range':[0,7]},
    {'name':"TLM Message",         'range':[8,21]},
    {'name':"ISF",                 'range':[22,22]},
    {'name':"Reserved",            'range':[23,23]},
    {'name':"Parity 1",            'range':[24,29]},
    {'name':"Truncated TOW Count", 'range':[30,46]},
    {'name':"AF",                  'range':[47,47]},
    {'name':"AS",                  'range':[48,48]},
    {'name':"SubFrame ID",         'range':[49,51]},
    {'name':"PC 1",                'range':[52,53]},
    {'name':"Parity 2",            'range':[54,59]},
    {'name':"Data ID",             'range':[60,61]},
    {'name':"svID",                'range':[62,67]},
    {'name':"AS/SV1",              'range':[68,71]},
    {'name':"AS/SV2",              'range':[72,75]},
    {'name':"AS/SV3",              'range':[76,79]},
    {'name':"AS/SV4",              'range':[80,83]},
    {'name':"Parity 3",            'range':[84,89]},
    {'name':"AS/SV5",              'range':[90,93]},
    {'name':"AS/SV6",              'range':[94,97]},
    {'name':"AS/SV7",              'range':[98,101]},
    {'name':"AS/SV8",              'range':[102,105]},
    {'name':"AS/SV9",              'range':[106,109]},
    {'name':"AS/SV10",             'range':[110,113]},
    {'name':"Parity 4",            'range':[114,119]},
    {'name':"AS/SV11",             'range':[120,123]},
    {'name':"AS/SV12",             'range':[124,127]},
    {'name':"AS/SV13",             'range':[128,131]},
    {'name':"AS/SV14",             'range':[132,135]},
    {'name':"AS/SV15",             'range':[136,139]},
    {'name':"AS/SV16",             'range':[140,143]},
    {'name':"Parity 5",            'range':[144,149]},
    {'name':"AS/SV17",             'range':[150,153]},
    {'name':"AS/SV18",             'range':[154,157]},
    {'name':"AS/SV19",             'range':[158,161]},
    {'name':"AS/SV20",             'range':[162,165]},
    {'name':"AS/SV21",             'range':[166,169]},
    {'name':"AS/SV22",             'range':[170,173]},
    {'name':"Parity 6",            'range':[174,179]},
    {'name':"AS/SV23",             'range':[180,183]},
    {'name':"AS/SV24",             'range':[184,187]},
    {'name':"AS/SV25",             'range':[188,191]},
    {'name':"AS/SV26",             'range':[192,195]},
    {'name':"AS/SV27",             'range':[196,199]},
    {'name':"AS/SV28",             'range':[200,203]},
    {'name':"Parity 7",            'range':[204,209]},
    {'name':"AS/SV29",             'range':[210,213]},
    {'name':"AS/SV30",             'range':[214,217]},
    {'name':"AS/SV31",             'range':[218,221]},
    {'name':"AS/SV32",             'range':[222,225]},
    {'name':"Spare 1",             'range':[226,227]},
    {'name':"SV25 Health",         'range':[228,233]},
    {'name':"Parity 8",            'range':[234,239]},
    {'name':"SV26 Health",         'range':[240,245]},
    {'name':"SV27 Health",         'range':[246,251]},
    {'name':"SV28 Health",         'range':[252,257]},
    {'name':"SV29 Health",         'range':[258,263]},
    {'name':"Parity 9",            'range':[264,269]},
    {'name':"SV25 Health",         'range':[270,275]},
    {'name':"SV25 Health",         'range':[276,281]},
    {'name':"SV25 Health",         'range':[282,287]},
    {'name':"Spare 2",             'range':[288,291]},
    {'name':"PC 2",                'range':[292,293]},
    {'name':"Parity 10",           'range':[294,299]}]

L1CADictSubframe4And5Almanac = [
    {'name':"Preamble",            'range':[0,7]},
    {'name':"TLM Message",         'range':[8,21]},
    {'name':"ISF",                 'range':[22,22]},
    {'name':"Reserved",            'range':[23,23]},
    {'name':"Parity 1",            'range':[24,29]},
    {'name':"Truncated TOW Count", 'range':[30,46]},
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

L1CADictSubframe5HealthSum = [
    {'name':"Preamble",            'range':[0,7]},
    {'name':"TLM Message",         'range':[8,21]},
    {'name':"ISF",                 'range':[22,22]},
    {'name':"Reserved",            'range':[23,23]},
    {'name':"Parity 1",            'range':[24,29]},
    {'name':"Truncated TOW Count", 'range':[30,46]},
    {'name':"AF",                  'range':[47,47]},
    {'name':"AS",                  'range':[48,48]},
    {'name':"SubFrame ID",         'range':[49,51]},
    {'name':"PC 1",                'range':[52,53]},
    {'name':"Parity 2",            'range':[54,59]},
    {'name':"Data ID",             'range':[60,61]},
    {'name':"svID",                'range':[62,67]},
    {'name':"t0a",                 'range':[68,75], 'factor':2**12, 'unit':utility.SECOND},
    {'name':"WNa",                 'range':[76,83],                 'unit':utility.WEEK},
    {'name':"Parity 3",            'range':[84,89]},
    {'name':"SV1 Health",          'range':[90,95]},
    {'name':"SV2 Health",          'range':[96,101]},
    {'name':"SV3 Health",          'range':[102,107]},
    {'name':"SV4 Health",          'range':[108,113]},
    {'name':"Parity 4",            'range':[114,119]},
    {'name':"SV5 Health",          'range':[120,125]},
    {'name':"SV6 Health",          'range':[126,131]},
    {'name':"SV7 Health",          'range':[132,137]},
    {'name':"SV8 Health",          'range':[138,143]},
    {'name':"Parity 5",            'range':[144,149]},
    {'name':"SV9 Health",          'range':[150,155]},
    {'name':"SV10 Health",         'range':[156,161]},
    {'name':"SV11 Health",         'range':[162,167]},
    {'name':"SV12 Health",         'range':[168,173]},
    {'name':"Parity 6",            'range':[174,179]},
    {'name':"SV13 Health",         'range':[180,185]},
    {'name':"SV14 Health",         'range':[186,191]},
    {'name':"SV15 Health",         'range':[192,197]},
    {'name':"SV16 Health",         'range':[198,203]},
    {'name':"Parity 7",            'range':[202,209]},
    {'name':"SV17 Health",         'range':[210,215]},
    {'name':"SV18 Health",         'range':[216,221]},
    {'name':"SV19 Health",         'range':[222,227]},
    {'name':"SV20 Health",         'range':[228,233]},
    {'name':"Parity 8",            'range':[234,239]},
    {'name':"SV21 Health",         'range':[240,245]},
    {'name':"SV22 Health",         'range':[246,251]},
    {'name':"SV23 Health",         'range':[252,257]},
    {'name':"SV24 Health",         'range':[258,263]},
    {'name':"Parity 9",            'range':[264,269]},
    {'name':"Reserved 2",          'range':[270,275]},
    {'name':"Reserved system use", 'range':[276,291]},
    {'name':"PC 2",                'range':[292,293]},
    {'name':"Parity 10",           'range':[294,299]}]

L1CDictPage1 = [
    {'name':"TOI",            	   'range':[0,8]},
    {'name':"WN",                  'range':[9,21],                                      'unit':utility.WEEK},
    {'name':"ITOW",                'range':[22,29]},
    {'name':"tOP",                 'range':[30,40],                    'factor':300,    'unit':utility.SECOND},
    {'name':"L1CHealth",           'range':[41,41]},
    {'name':"URAEDIndex",          'range':[42,46],     'signed':True},
    {'name':"tOE",                 'range':[47,57],                    'factor':300,    'unit':utility.SECOND},
    {'name':"deltaA",              'range':[58,83],     'signed':True, 'factor':2**-9,  'unit':utility.METER},
    {'name':"ADot",                'range':[84,108],    'signed':True, 'factor':2**-21, 'unit':utility.METER_PER_SECOND},
    {'name':"deltan0",             'range':[109,125],   'signed':True, 'factor':2**-44, 'unit':utility.SEMICIRCLE_PER_SECOND},
    {'name':"deltan0Dot",          'range':[126,148],   'signed':True, 'factor':2**-57, 'unit':utility.SEMICIRCLE_PER_SECOND_SQUARED},
    {'name':"M0n",                 'range':[149,181],   'signed':True, 'factor':2**-32, 'unit':utility.SEMICIRCLE},
    {'name':"en",                  'range':[182,214],                  'factor':2**-34},
    {'name':"omegan",              'range':[215,247],   'signed':True, 'factor':2**-32, 'unit':utility.SEMICIRCLE},
    {'name':"omega0n",             'range':[248,280],   'signed':True, 'factor':2**-32, 'unit':utility.SEMICIRCLE},
    {'name':"i0n",                 'range':[281,313],   'signed':True, 'factor':2**-32, 'unit':utility.SEMICIRCLE},
    {'name':"deltaOmegaDot",       'range':[314,330],   'signed':True, 'factor':2**-44, 'unit':utility.SEMICIRCLE_PER_SECOND},
    {'name':"i0nDot",              'range':[331,345],   'signed':True, 'factor':2**-44, 'unit':utility.SEMICIRCLE_PER_SECOND},
    {'name':"Cisn",                'range':[346,361],   'signed':True, 'factor':2**-30, 'unit':utility.RADIAN},
    {'name':"Cicn",                'range':[362,377],   'signed':True, 'factor':2**-30, 'unit':utility.RADIAN},
    {'name':"Crsn",                'range':[378,401],   'signed':True, 'factor':2**-8,  'unit':utility.RADIAN},
    {'name':"Crcn",                'range':[402,425],   'signed':True, 'factor':2**-8,  'unit':utility.RADIAN},
    {'name':"Cusn",           	   'range':[426,446],   'signed':True, 'factor':2**-30, 'unit':utility.RADIAN},
    {'name':"Cucn",                'range':[447,467],   'signed':True, 'factor':2**-30, 'unit':utility.RADIAN},
    {'name':"URANED0Index",        'range':[468,472],   'signed':True},
    {'name':"URANED1Index",        'range':[473,475]},
    {'name':"URANED2Index",        'range':[476,478]},
    {'name':"af0n",                'range':[479,504],   'signed':True, 'factor':2**-35, 'unit':utility.SECOND},
    {'name':"af1n",                'range':[505,524],   'signed':True, 'factor':2**-48, 'unit':utility.SECOND_PER_SECOND},
    {'name':"af2n",                'range':[525,534],   'signed':True, 'factor':2**-60, 'unit':utility.SECOND_PER_SECOND_SQUARED},
    {'name':"TGD",                 'range':[535,547],   'signed':True, 'factor':2**-35, 'unit':utility.SECOND},
    {'name':"ISCL1CP",             'range':[548,560],   'signed':True, 'factor':2**-35, 'unit':utility.SECOND},
    {'name':"ISCL1CD",             'range':[561,573],   'signed':True, 'factor':2**-35, 'unit':utility.SECOND},
    {'name':"ISF",                 'range':[574,574]},
    {'name':"WNOP",                'range':[575,582],                                   'unit':utility.WEEK},
    {'name':"reserved2",           'range':[583,584]},
    {'name':"CRC2",                'range':[585,608]},
    {'name':"PRN",                 'range':[609,616]},
    {'name':"pageNb",              'range':[617,622]},
    {'name':"A0n",                 'range':[623,638],   'signed':True, 'factor':2**-35, 'unit':utility.SECOND},
    {'name':"A1n",                 'range':[639,651],   'signed':True, 'factor':2**-51, 'unit':utility.SECOND_PER_SECOND},
    {'name':"A2n",                 'range':[652,658],   'signed':True, 'factor':2**-68, 'unit':utility.SECOND_PER_SECOND_SQUARED},
    {'name':"deltatLS",            'range':[659,666],   'signed':True,                  'unit':utility.SECOND},
    {'name':"tot",                 'range':[667,682],                  'factor':2**4,   'unit':utility.SECOND},
    {'name':"WNot",                'range':[683,695],                  'factor':2**-32, 'unit':utility.WEEK},
    {'name':"WNLSF",               'range':[696,708],                  'factor':2**-32, 'unit':utility.WEEK},
    {'name':"DN",                  'range':[709,712],                  'factor':2**-32, 'unit':utility.DAY},
    {'name':"deltatLSF",           'range':[713,720],   'signed':True, 'factor':2**-32, 'unit':utility.SECOND},
    {'name':"alpha0",              'range':[721,728],   'signed':True, 'factor':2**-30, 'unit':utility.SECOND},
    {'name':"alpha1",              'range':[729,736],   'signed':True, 'factor':2**-27, 'unit':utility.SECOND_PER_SEMICIRCLE},
    {'name':"alpha2",              'range':[737,744],   'signed':True, 'factor':2**-24, 'unit':utility.SECOND_PER_SEMICIRCLE_SQUARED},
    {'name':"alpha3",              'range':[745,752],   'signed':True, 'factor':2**-24, 'unit':utility.SECOND_PER_SEMICIRCLE_CUBE},
    {'name':"beta0",               'range':[753,760],   'signed':True, 'factor':2**11,  'unit':utility.SECOND},
    {'name':"beta1",               'range':[761,768],   'signed':True, 'factor':2**14,  'unit':utility.SECOND_PER_SEMICIRCLE},
    {'name':"beta2",               'range':[769,776],   'signed':True, 'factor':2**16,  'unit':utility.SECOND_PER_SEMICIRCLE_SQUARED},
    {'name':"beta3",               'range':[777,784],   'signed':True, 'factor':2**16,  'unit':utility.SECOND_PER_SEMICIRCLE_CUBE},
    {'name':"ISCL1CA",             'range':[785,797],   'signed':True, 'factor':2**-35, 'unit':utility.SECOND},
    {'name':"ISCL2C",              'range':[798,810],   'signed':True, 'factor':2**-35, 'unit':utility.SECOND},
    {'name':"ISCL5I5",             'range':[811,823],   'signed':True, 'factor':2**-35, 'unit':utility.SECOND},
    {'name':"ISCL5Q5",             'range':[824,836],   'signed':True, 'factor':2**-35, 'unit':utility.SECOND},
    {'name':"reserved3",           'range':[837,858]},
    {'name':"CRC3",                'range':[859,882]}]

L1CDictPage2 = [
    {'name':"TOI",            	   'range':[0,8]},
    {'name':"WN",                  'range':[9,21],                                      'unit':utility.WEEK},
    {'name':"ITOW",                'range':[22,29]},
    {'name':"tOP",                 'range':[30,40],                    'factor':300,    'unit':utility.SECOND},
    {'name':"L1CHealth",           'range':[41,41]},
    {'name':"URAEDIndex",          'range':[42,46],     'signed':True},
    {'name':"tOE",                 'range':[47,57],                    'factor':300,    'unit':utility.SECOND},
    {'name':"deltaA",              'range':[58,83],     'signed':True, 'factor':2**-9,  'unit':utility.METER},
    {'name':"ADot",                'range':[84,108],    'signed':True, 'factor':2**-21, 'unit':utility.METER_PER_SECOND},
    {'name':"deltan0",             'range':[109,125],   'signed':True, 'factor':2**-44, 'unit':utility.SEMICIRCLE_PER_SECOND},
    {'name':"deltan0Dot",          'range':[126,148],   'signed':True, 'factor':2**-57, 'unit':utility.SEMICIRCLE_PER_SECOND_SQUARED},
    {'name':"M0n",                 'range':[149,181],   'signed':True, 'factor':2**-32, 'unit':utility.SEMICIRCLE},
    {'name':"en",                  'range':[182,214],                  'factor':2**-34},
    {'name':"omegan",              'range':[215,247],   'signed':True, 'factor':2**-32, 'unit':utility.SEMICIRCLE},
    {'name':"omega0n",             'range':[248,280],   'signed':True, 'factor':2**-32, 'unit':utility.SEMICIRCLE},
    {'name':"i0n",                 'range':[281,313],   'signed':True, 'factor':2**-32, 'unit':utility.SEMICIRCLE},
    {'name':"deltaOmegaDot",       'range':[314,330],   'signed':True, 'factor':2**-44, 'unit':utility.SEMICIRCLE_PER_SECOND},
    {'name':"i0nDot",              'range':[331,345],   'signed':True, 'factor':2**-44, 'unit':utility.SEMICIRCLE_PER_SECOND},
    {'name':"Cisn",                'range':[346,361],   'signed':True, 'factor':2**-30, 'unit':utility.RADIAN},
    {'name':"Cicn",                'range':[362,377],   'signed':True, 'factor':2**-30, 'unit':utility.RADIAN},
    {'name':"Crsn",                'range':[378,401],   'signed':True, 'factor':2**-8,  'unit':utility.RADIAN},
    {'name':"Crcn",                'range':[402,425],   'signed':True, 'factor':2**-8,  'unit':utility.RADIAN},
    {'name':"Cusn",           	   'range':[426,446],   'signed':True, 'factor':2**-30, 'unit':utility.RADIAN},
    {'name':"Cucn",                'range':[447,467],   'signed':True, 'factor':2**-30, 'unit':utility.RADIAN},
    {'name':"URANED0Index",        'range':[468,472],   'signed':True},
    {'name':"URANED1Index",        'range':[473,475]},
    {'name':"URANED2Index",        'range':[476,478]},
    {'name':"af0n",                'range':[479,504],   'signed':True, 'factor':2**-35, 'unit':utility.SECOND},
    {'name':"af1n",                'range':[505,524],   'signed':True, 'factor':2**-48, 'unit':utility.SECOND_PER_SECOND},
    {'name':"af2n",                'range':[525,534],   'signed':True, 'factor':2**-60, 'unit':utility.SECOND_PER_SECOND_SQUARED},
    {'name':"TGD",                 'range':[535,547],   'signed':True, 'factor':2**-35, 'unit':utility.SECOND},
    {'name':"ISCL1CP",             'range':[548,560],   'signed':True, 'factor':2**-35, 'unit':utility.SECOND},
    {'name':"ISCL1CD",             'range':[561,573],   'signed':True, 'factor':2**-35, 'unit':utility.SECOND},
    {'name':"ISF",                 'range':[574,574]},
    {'name':"WNOP",                'range':[575,582],                                   'unit':utility.WEEK},
    {'name':"reserved2",           'range':[583,584]},
    {'name':"CRC2",                'range':[585,608]},
    {'name':"PRN",                 'range':[609,616]},
    {'name':"pageNb",              'range':[617,622]},
    {'name':"GNSSID",              'range':[623,625]},
    {'name':"tGGTO",               'range':[626,641],                  'factor':2**4,   'unit':utility.SECOND},
    {'name':"WNGGTO",              'range':[642,654],                  'factor':2**0,   'unit':utility.WEEK},
    {'name':"A0GGTO",              'range':[655,670],   'signed':True, 'factor':2**-35, 'unit':utility.SECOND},
    {'name':"A1GGTO",              'range':[671,683],   'signed':True, 'factor':2**-51, 'unit':utility.SECOND_PER_SECOND},
    {'name':"A2GGTO",              'range':[684,690],   'signed':True, 'factor':2**-68, 'unit':utility.SECOND_PER_SECOND_SQUARED},
    {'name':"tEOP",                'range':[691,706],                  'factor':2**4,   'unit':utility.SECOND},
    {'name':"PMX",                 'range':[707,727],   'signed':True, 'factor':2**-20, 'unit':utility.ARC_SECOND},
    {'name':"PMXDot",              'range':[728,742],   'signed':True, 'factor':2**-21, 'unit':utility.ARC_SECOND_PER_DAY},
    {'name':"PMY",                 'range':[743,763],   'signed':True, 'factor':2**-20, 'unit':utility.ARC_SECOND},
    {'name':"PMYDot",              'range':[764,778],   'signed':True, 'factor':2**-21, 'unit':utility.ARC_SECOND_PER_DAY},
    {'name':"deltaUT1",            'range':[779,809],   'signed':True, 'factor':2**-24, 'unit':utility.SECOND},
    {'name':"deltaUT1Dot",         'range':[810,828],   'signed':True, 'factor':2**-25, 'unit':utility.SECOND_PER_DAY},
    {'name':"reserved3",           'range':[829,858]},
    {'name':"CRC3",                'range':[859,882]}]

L1CDictPage3 = [
    {'name':"TOI",            	   'range':[0,8]},
    {'name':"WN",                  'range':[9,21],                                      'unit':utility.WEEK},
    {'name':"ITOW",                'range':[22,29]},
    {'name':"tOP",                 'range':[30,40],                    'factor':300,    'unit':utility.SECOND},
    {'name':"L1CHealth",           'range':[41,41]},
    {'name':"URAEDIndex",          'range':[42,46],     'signed':True},
    {'name':"tOE",                 'range':[47,57],                    'factor':300,    'unit':utility.SECOND},
    {'name':"deltaA",              'range':[58,83],     'signed':True, 'factor':2**-9,  'unit':utility.METER},
    {'name':"ADot",                'range':[84,108],    'signed':True, 'factor':2**-21, 'unit':utility.METER_PER_SECOND},
    {'name':"deltan0",             'range':[109,125],   'signed':True, 'factor':2**-44, 'unit':utility.SEMICIRCLE_PER_SECOND},
    {'name':"deltan0Dot",          'range':[126,148],   'signed':True, 'factor':2**-57, 'unit':utility.SEMICIRCLE_PER_SECOND_SQUARED},
    {'name':"M0n",                 'range':[149,181],   'signed':True, 'factor':2**-32, 'unit':utility.SEMICIRCLE},
    {'name':"en",                  'range':[182,214],                  'factor':2**-34},
    {'name':"omegan",              'range':[215,247],   'signed':True, 'factor':2**-32, 'unit':utility.SEMICIRCLE},
    {'name':"omega0n",             'range':[248,280],   'signed':True, 'factor':2**-32, 'unit':utility.SEMICIRCLE},
    {'name':"i0n",                 'range':[281,313],   'signed':True, 'factor':2**-32, 'unit':utility.SEMICIRCLE},
    {'name':"deltaOmegaDot",       'range':[314,330],   'signed':True, 'factor':2**-44, 'unit':utility.SEMICIRCLE_PER_SECOND},
    {'name':"i0nDot",              'range':[331,345],   'signed':True, 'factor':2**-44, 'unit':utility.SEMICIRCLE_PER_SECOND},
    {'name':"Cisn",                'range':[346,361],   'signed':True, 'factor':2**-30, 'unit':utility.RADIAN},
    {'name':"Cicn",                'range':[362,377],   'signed':True, 'factor':2**-30, 'unit':utility.RADIAN},
    {'name':"Crsn",                'range':[378,401],   'signed':True, 'factor':2**-8,  'unit':utility.RADIAN},
    {'name':"Crcn",                'range':[402,425],   'signed':True, 'factor':2**-8,  'unit':utility.RADIAN},
    {'name':"Cusn",           	   'range':[426,446],   'signed':True, 'factor':2**-30, 'unit':utility.RADIAN},
    {'name':"Cucn",                'range':[447,467],   'signed':True, 'factor':2**-30, 'unit':utility.RADIAN},
    {'name':"URANED0Index",        'range':[468,472],   'signed':True},
    {'name':"URANED1Index",        'range':[473,475]},
    {'name':"URANED2Index",        'range':[476,478]},
    {'name':"af0n",                'range':[479,504],   'signed':True, 'factor':2**-35, 'unit':utility.SECOND},
    {'name':"af1n",                'range':[505,524],   'signed':True, 'factor':2**-48, 'unit':utility.SECOND_PER_SECOND},
    {'name':"af2n",                'range':[525,534],   'signed':True, 'factor':2**-60, 'unit':utility.SECOND_PER_SECOND_SQUARED},
    {'name':"TGD",                 'range':[535,547],   'signed':True, 'factor':2**-35, 'unit':utility.SECOND},
    {'name':"ISCL1CP",             'range':[548,560],   'signed':True, 'factor':2**-35, 'unit':utility.SECOND},
    {'name':"ISCL1CD",             'range':[561,573],   'signed':True, 'factor':2**-35, 'unit':utility.SECOND},
    {'name':"ISF",                 'range':[574,574]},
    {'name':"WNOP",                'range':[575,582],                                   'unit':utility.WEEK},
    {'name':"reserved2",           'range':[583,584]},
    {'name':"CRC2",                'range':[585,608]},
    {'name':"PRN",                 'range':[609,616]},
    {'name':"pageNb",              'range':[617,622]},
    {'name':"WNa",                  'range':[623,635],                                   'unit':utility.WEEK},
    {'name':"t",                   'range':[636,643],                                   'unit':utility.SECOND},
    {'name':"PRN-1",               'range':[644,651]},
    {'name':"deltaA-1",            'range':[652,659],   'signed':True, 'factor':2**9,   'unit':utility.METER},
    {'name':"Omega0-1",            'range':[660,666],   'signed':True, 'factor':2**-6,  'unit':utility.SEMICIRCLE},
    {'name':"phi0-1",              'range':[667,673],   'signed':True, 'factor':2**-6,  'unit':utility.SEMICIRCLE},
    {'name':"L1Health-1",          'range':[674,674]},
    {'name':"L2Health-1",          'range':[675,675]},
    {'name':"L5Health-1",          'range':[676,676]},
    {'name':"PRN-2",               'range':[677,684]},
    {'name':"deltaA-2",            'range':[685,692],   'signed':True, 'factor':2**9,   'unit':utility.METER},
    {'name':"Omega0-2",            'range':[693,699],   'signed':True, 'factor':2**-6,  'unit':utility.SEMICIRCLE},
    {'name':"phi0-2",              'range':[700,706],   'signed':True, 'factor':2**-6,  'unit':utility.SEMICIRCLE},
    {'name':"L1Health-2",          'range':[707,707]},
    {'name':"L2Health-2",          'range':[708,708]},
    {'name':"L5Health-2",          'range':[709,709]},
    {'name':"PRN-3",               'range':[710,717]},
    {'name':"deltaA-3",            'range':[718,725],   'signed':True, 'factor':2**9,   'unit':utility.METER},
    {'name':"Omega0-3",            'range':[726,732],   'signed':True, 'factor':2**-6,  'unit':utility.SEMICIRCLE},
    {'name':"phi0-3",              'range':[733,739],   'signed':True, 'factor':2**-6,  'unit':utility.SEMICIRCLE},
    {'name':"L1Health-3",          'range':[740,740]},
    {'name':"L2Health-3",          'range':[741,741]},
    {'name':"L5Health-3",          'range':[742,742]},
    {'name':"PRN-4",               'range':[743,750]},
    {'name':"deltaA-4",            'range':[751,758],   'signed':True, 'factor':2**9,   'unit':utility.METER},
    {'name':"Omega0-4",            'range':[759,765],   'signed':True, 'factor':2**-6,  'unit':utility.SEMICIRCLE},
    {'name':"phi0-4",              'range':[766,772],   'signed':True, 'factor':2**-6,  'unit':utility.SEMICIRCLE},
    {'name':"L1Health-4",          'range':[773,773]},
    {'name':"L2Health-4",          'range':[774,774]},
    {'name':"L5Health-4",          'range':[775,775]},
    {'name':"PRN-5",               'range':[776,783]},
    {'name':"deltaA-5",            'range':[784,791],   'signed':True, 'factor':2**9,   'unit':utility.METER},
    {'name':"Omega0-5",            'range':[792,798],   'signed':True, 'factor':2**-6,  'unit':utility.SEMICIRCLE},
    {'name':"phi0-5",              'range':[799,805],   'signed':True, 'factor':2**-6,  'unit':utility.SEMICIRCLE},
    {'name':"L1Health-5",          'range':[806,806]},
    {'name':"L2Health-5",          'range':[807,807]},
    {'name':"L5Health-5",          'range':[808,808]},
    {'name':"PRN-6",               'range':[809,816]},
    {'name':"deltaA-6",            'range':[817,824],   'signed':True, 'factor':2**9,   'unit':utility.METER},
    {'name':"Omega0-6",            'range':[825,831],   'signed':True, 'factor':2**-6,  'unit':utility.SEMICIRCLE},
    {'name':"phi0-6",              'range':[832,838],   'signed':True, 'factor':2**-6,  'unit':utility.SEMICIRCLE},
    {'name':"L1Health-6",          'range':[839,839]},
    {'name':"L2Health-6",          'range':[840,840]},
    {'name':"L5Health-6",          'range':[841,841]},
    {'name':"reserved3",           'range':[842,858]},
    {'name':"CRC3",                'range':[859,882]}]

L1CDictPage4 = [
    {'name':"TOI",            	   'range':[0,8]},
    {'name':"WN",                  'range':[9,21],                                      'unit':utility.WEEK},
    {'name':"ITOW",                'range':[22,29]},
    {'name':"tOP",                 'range':[30,40],                    'factor':300,    'unit':utility.SECOND},
    {'name':"L1CHealth",           'range':[41,41]},
    {'name':"URAEDIndex",          'range':[42,46],     'signed':True},
    {'name':"tOE",                 'range':[47,57],                    'factor':300,    'unit':utility.SECOND},
    {'name':"deltaA",              'range':[58,83],     'signed':True, 'factor':2**-9,  'unit':utility.METER},
    {'name':"ADot",                'range':[84,108],    'signed':True, 'factor':2**-21, 'unit':utility.METER_PER_SECOND},
    {'name':"deltan0",             'range':[109,125],   'signed':True, 'factor':2**-44, 'unit':utility.SEMICIRCLE_PER_SECOND},
    {'name':"deltan0Dot",          'range':[126,148],   'signed':True, 'factor':2**-57, 'unit':utility.SEMICIRCLE_PER_SECOND_SQUARED},
    {'name':"M0n",                 'range':[149,181],   'signed':True, 'factor':2**-32, 'unit':utility.SEMICIRCLE},
    {'name':"en",                  'range':[182,214],                  'factor':2**-34},
    {'name':"omegan",              'range':[215,247],   'signed':True, 'factor':2**-32, 'unit':utility.SEMICIRCLE},
    {'name':"omega0n",             'range':[248,280],   'signed':True, 'factor':2**-32, 'unit':utility.SEMICIRCLE},
    {'name':"i0n",                 'range':[281,313],   'signed':True, 'factor':2**-32, 'unit':utility.SEMICIRCLE},
    {'name':"deltaOmegaDot",       'range':[314,330],   'signed':True, 'factor':2**-44, 'unit':utility.SEMICIRCLE_PER_SECOND},
    {'name':"i0nDot",              'range':[331,345],   'signed':True, 'factor':2**-44, 'unit':utility.SEMICIRCLE_PER_SECOND},
    {'name':"Cisn",                'range':[346,361],   'signed':True, 'factor':2**-30, 'unit':utility.RADIAN},
    {'name':"Cicn",                'range':[362,377],   'signed':True, 'factor':2**-30, 'unit':utility.RADIAN},
    {'name':"Crsn",                'range':[378,401],   'signed':True, 'factor':2**-8,  'unit':utility.RADIAN},
    {'name':"Crcn",                'range':[402,425],   'signed':True, 'factor':2**-8,  'unit':utility.RADIAN},
    {'name':"Cusn",           	   'range':[426,446],   'signed':True, 'factor':2**-30, 'unit':utility.RADIAN},
    {'name':"Cucn",                'range':[447,467],   'signed':True, 'factor':2**-30, 'unit':utility.RADIAN},
    {'name':"URANED0Index",        'range':[468,472],   'signed':True},
    {'name':"URANED1Index",        'range':[473,475]},
    {'name':"URANED2Index",        'range':[476,478]},
    {'name':"af0n",                'range':[479,504],   'signed':True, 'factor':2**-35, 'unit':utility.SECOND},
    {'name':"af1n",                'range':[505,524],   'signed':True, 'factor':2**-48, 'unit':utility.SECOND_PER_SECOND},
    {'name':"af2n",                'range':[525,534],   'signed':True, 'factor':2**-60, 'unit':utility.SECOND_PER_SECOND_SQUARED},
    {'name':"TGD",                 'range':[535,547],   'signed':True, 'factor':2**-35, 'unit':utility.SECOND},
    {'name':"ISCL1CP",             'range':[548,560],   'signed':True, 'factor':2**-35, 'unit':utility.SECOND},
    {'name':"ISCL1CD",             'range':[561,573],   'signed':True, 'factor':2**-35, 'unit':utility.SECOND},
    {'name':"ISF",                 'range':[574,574]},
    {'name':"WNOP",                'range':[575,582],                                   'unit':utility.WEEK},
    {'name':"reserved2",           'range':[583,584]},
    {'name':"CRC2",                'range':[585,608]},
    {'name':"PRN",                 'range':[609,616]},
    {'name':"pageNb",              'range':[617,622]},
    {'name':"WNa",                  'range':[623,635],                                   'unit':utility.WEEK},
    {'name':"t",                   'range':[636,643],                  'factor':2**12,  'unit':utility.SECOND},
    {'name':"prn",                 'range':[644,651]},
    {'name':"L1Health",            'range':[652,652]},
    {'name':"L2Health",            'range':[653,653]},
    {'name':"L5Health",            'range':[654,654]},
    {'name':"e",                   'range':[655,665],                  'factor':2**-16},
    {'name':"delta",               'range':[666,676],   'signed':True, 'factor':2**-14, 'unit':utility.SEMICIRCLE},
    {'name':"omegaDot",            'range':[677,687],   'signed':True, 'factor':2**-33, 'unit':utility.SEMICIRCLE_PER_SECOND},
    {'name':"sqrtA",               'range':[688,704],                  'factor':2**-4,  'unit':utility.METER_SQUARE_ROOT},
    {'name':"bigOmega0",           'range':[705,720],   'signed':True, 'factor':2**-15, 'unit':utility.SEMICIRCLE},
    {'name':"smallOmega0",         'range':[721,736],   'signed':True, 'factor':2**-15, 'unit':utility.SEMICIRCLE},
    {'name':"M0",                  'range':[737,752],   'signed':True, 'factor':2**-15, 'unit':utility.SEMICIRCLE},
    {'name':"af0",                 'range':[753,763],   'signed':True, 'factor':2**-20, 'unit':utility.SECOND},
    {'name':"af1",                 'range':[764,773],   'signed':True, 'factor':2**-37, 'unit':utility.SECOND_PER_SECOND},
    {'name':"reserved3",           'range':[774,858]},
    {'name':"CRC3",                'range':[859,882]}]

L1CDictPage5 = [
    {'name':"TOI",            	   'range':[0,8]},
    {'name':"WN",                  'range':[9,21],                                      'unit':utility.WEEK},
    {'name':"ITOW",                'range':[22,29]},
    {'name':"tOP",                 'range':[30,40],                    'factor':300,    'unit':utility.SECOND},
    {'name':"L1CHealth",           'range':[41,41]},
    {'name':"URAEDIndex",          'range':[42,46],     'signed':True},
    {'name':"tOE",                 'range':[47,57],                    'factor':300,    'unit':utility.SECOND},
    {'name':"deltaA",              'range':[58,83],     'signed':True, 'factor':2**-9,  'unit':utility.METER},
    {'name':"ADot",                'range':[84,108],    'signed':True, 'factor':2**-21, 'unit':utility.METER_PER_SECOND},
    {'name':"deltan0",             'range':[109,125],   'signed':True, 'factor':2**-44, 'unit':utility.SEMICIRCLE_PER_SECOND},
    {'name':"deltan0Dot",          'range':[126,148],   'signed':True, 'factor':2**-57, 'unit':utility.SEMICIRCLE_PER_SECOND_SQUARED},
    {'name':"M0n",                 'range':[149,181],   'signed':True, 'factor':2**-32, 'unit':utility.SEMICIRCLE},
    {'name':"en",                  'range':[182,214],                  'factor':2**-34},
    {'name':"omegan",              'range':[215,247],   'signed':True, 'factor':2**-32, 'unit':utility.SEMICIRCLE},
    {'name':"omega0n",             'range':[248,280],   'signed':True, 'factor':2**-32, 'unit':utility.SEMICIRCLE},
    {'name':"i0n",                 'range':[281,313],   'signed':True, 'factor':2**-32, 'unit':utility.SEMICIRCLE},
    {'name':"deltaOmegaDot",       'range':[314,330],   'signed':True, 'factor':2**-44, 'unit':utility.SEMICIRCLE_PER_SECOND},
    {'name':"i0nDot",              'range':[331,345],   'signed':True, 'factor':2**-44, 'unit':utility.SEMICIRCLE_PER_SECOND},
    {'name':"Cisn",                'range':[346,361],   'signed':True, 'factor':2**-30, 'unit':utility.RADIAN},
    {'name':"Cicn",                'range':[362,377],   'signed':True, 'factor':2**-30, 'unit':utility.RADIAN},
    {'name':"Crsn",                'range':[378,401],   'signed':True, 'factor':2**-8,  'unit':utility.RADIAN},
    {'name':"Crcn",                'range':[402,425],   'signed':True, 'factor':2**-8,  'unit':utility.RADIAN},
    {'name':"Cusn",           	   'range':[426,446],   'signed':True, 'factor':2**-30, 'unit':utility.RADIAN},
    {'name':"Cucn",                'range':[447,467],   'signed':True, 'factor':2**-30, 'unit':utility.RADIAN},
    {'name':"URANED0Index",        'range':[468,472],   'signed':True},
    {'name':"URANED1Index",        'range':[473,475]},
    {'name':"URANED2Index",        'range':[476,478]},
    {'name':"af0n",                'range':[479,504],   'signed':True, 'factor':2**-35, 'unit':utility.SECOND},
    {'name':"af1n",                'range':[505,524],   'signed':True, 'factor':2**-48, 'unit':utility.SECOND_PER_SECOND},
    {'name':"af2n",                'range':[525,534],   'signed':True, 'factor':2**-60, 'unit':utility.SECOND_PER_SECOND_SQUARED},
    {'name':"TGD",                 'range':[535,547],   'signed':True, 'factor':2**-35, 'unit':utility.SECOND},
    {'name':"ISCL1CP",             'range':[548,560],   'signed':True, 'factor':2**-35, 'unit':utility.SECOND},
    {'name':"ISCL1CD",             'range':[561,573],   'signed':True, 'factor':2**-35, 'unit':utility.SECOND},
    {'name':"ISF",                 'range':[574,574]},
    {'name':"WNOP",                'range':[575,582],                                   'unit':utility.WEEK},
    {'name':"reserved2",           'range':[583,584]},
    {'name':"CRC2",                'range':[585,608]},
    {'name':"PRN",                 'range':[609,616]},
    {'name':"pageNb",              'range':[617,622]},
    {'name':"tOP",                 'range':[623,633],                  'factor':300,    'unit':utility.SECOND},
    {'name':"t",                   'range':[634,644],                  'factor':300,    'unit':utility.SECOND},
    {'name':"DCDataType",          'range':[645,645]},
    {'name':"prnId-CDC",           'range':[646,653]},
    {'name':"deltaAf0-CDC",        'range':[654,666],   'signed':True, 'factor':2**-35, 'unit':utility.SECOND},
    {'name':"deltaAf1-CDC",        'range':[667,674],   'signed':True, 'factor':2**-51, 'unit':utility.SECOND_PER_SECOND},
    {'name':"UDRA-CDC",            'range':[675,679],   'signed':True},
    {'name':"prnId-EDC",           'range':[680,687]},
    {'name':"deltaAlpha-EDC",      'range':[688,701],   'signed':True, 'factor':2**-34},
    {'name':"deltaBeta-EDC",       'range':[702,715],   'signed':True, 'factor':2**-34},
    {'name':"deltaGamma-EDC",      'range':[716,730],   'signed':True, 'factor':2**-32, 'unit':utility.SEMICIRCLE},
    {'name':"deltaI-EDC",          'range':[731,742],   'signed':True, 'factor':2**-32, 'unit':utility.SEMICIRCLE},
    {'name':"deltaOmega-EDC",      'range':[743,754],   'signed':True, 'factor':2**-32, 'unit':utility.SEMICIRCLE},
    {'name':"deltaA-EDC",          'range':[755,766],   'signed':True, 'factor':2**-9,  'unit':utility.METER},
    {'name':"udraDot-EDC",         'range':[767,771],   'signed':True},
    {'name':"reserved3",           'range':[772,858]},
    {'name':"reserved3",           'range':[772,858]},
    {'name':"CRC3",                'range':[859,882]}]

L1CDictPage6 = [
    {'name':"TOI",            	   'range':[0,8]},
    {'name':"WN",                  'range':[9,21],                                      'unit':utility.WEEK},
    {'name':"ITOW",                'range':[22,29]},
    {'name':"tOP",                 'range':[30,40],                    'factor':300,    'unit':utility.SECOND},
    {'name':"L1CHealth",           'range':[41,41]},
    {'name':"URAEDIndex",          'range':[42,46],     'signed':True},
    {'name':"tOE",                 'range':[47,57],                    'factor':300,    'unit':utility.SECOND},
    {'name':"deltaA",              'range':[58,83],     'signed':True, 'factor':2**-9,  'unit':utility.METER},
    {'name':"ADot",                'range':[84,108],    'signed':True, 'factor':2**-21, 'unit':utility.METER_PER_SECOND},
    {'name':"deltan0",             'range':[109,125],   'signed':True, 'factor':2**-44, 'unit':utility.SEMICIRCLE_PER_SECOND},
    {'name':"deltan0Dot",          'range':[126,148],   'signed':True, 'factor':2**-57, 'unit':utility.SEMICIRCLE_PER_SECOND_SQUARED},
    {'name':"M0n",                 'range':[149,181],   'signed':True, 'factor':2**-32, 'unit':utility.SEMICIRCLE},
    {'name':"en",                  'range':[182,214],                  'factor':2**-34},
    {'name':"omegan",              'range':[215,247],   'signed':True, 'factor':2**-32, 'unit':utility.SEMICIRCLE},
    {'name':"omega0n",             'range':[248,280],   'signed':True, 'factor':2**-32, 'unit':utility.SEMICIRCLE},
    {'name':"i0n",                 'range':[281,313],   'signed':True, 'factor':2**-32, 'unit':utility.SEMICIRCLE},
    {'name':"deltaOmegaDot",       'range':[314,330],   'signed':True, 'factor':2**-44, 'unit':utility.SEMICIRCLE_PER_SECOND},
    {'name':"i0nDot",              'range':[331,345],   'signed':True, 'factor':2**-44, 'unit':utility.SEMICIRCLE_PER_SECOND},
    {'name':"Cisn",                'range':[346,361],   'signed':True, 'factor':2**-30, 'unit':utility.RADIAN},
    {'name':"Cicn",                'range':[362,377],   'signed':True, 'factor':2**-30, 'unit':utility.RADIAN},
    {'name':"Crsn",                'range':[378,401],   'signed':True, 'factor':2**-8,  'unit':utility.RADIAN},
    {'name':"Crcn",                'range':[402,425],   'signed':True, 'factor':2**-8,  'unit':utility.RADIAN},
    {'name':"Cusn",           	   'range':[426,446],   'signed':True, 'factor':2**-30, 'unit':utility.RADIAN},
    {'name':"Cucn",                'range':[447,467],   'signed':True, 'factor':2**-30, 'unit':utility.RADIAN},
    {'name':"URANED0Index",        'range':[468,472],   'signed':True},
    {'name':"URANED1Index",        'range':[473,475]},
    {'name':"URANED2Index",        'range':[476,478]},
    {'name':"af0n",                'range':[479,504],   'signed':True, 'factor':2**-35, 'unit':utility.SECOND},
    {'name':"af1n",                'range':[505,524],   'signed':True, 'factor':2**-48, 'unit':utility.SECOND_PER_SECOND},
    {'name':"af2n",                'range':[525,534],   'signed':True, 'factor':2**-60, 'unit':utility.SECOND_PER_SECOND_SQUARED},
    {'name':"TGD",                 'range':[535,547],   'signed':True, 'factor':2**-35, 'unit':utility.SECOND},
    {'name':"ISCL1CP",             'range':[548,560],   'signed':True, 'factor':2**-35, 'unit':utility.SECOND},
    {'name':"ISCL1CD",             'range':[561,573],   'signed':True, 'factor':2**-35, 'unit':utility.SECOND},
    {'name':"ISF",                 'range':[574,574]},
    {'name':"WNOP",                'range':[575,582],                                   'unit':utility.WEEK},
    {'name':"reserved2",           'range':[583,584]},
    {'name':"CRC2",                'range':[585,608]},
    {'name':"PRN",                 'range':[609,616]},
    {'name':"pageNb",              'range':[617,622]},
    {'name':"TextPage",            'range':[623,626]},
    {'name':"TextMessage",         'range':[627,858]},
    {'name':"CRC3",                'range':[859,882]}]

L1CDictPage7 = [
    {'name':"TOI",            	   'range':[0,8]},
    {'name':"WN",                  'range':[9,21],                                      'unit':utility.WEEK},
    {'name':"ITOW",                'range':[22,29]},
    {'name':"tOP",                 'range':[30,40],                    'factor':300,    'unit':utility.SECOND},
    {'name':"L1CHealth",           'range':[41,41]},
    {'name':"URAEDIndex",          'range':[42,46],     'signed':True},
    {'name':"tOE",                 'range':[47,57],                    'factor':300,    'unit':utility.SECOND},
    {'name':"deltaA",              'range':[58,83],     'signed':True, 'factor':2**-9,  'unit':utility.METER},
    {'name':"ADot",                'range':[84,108],    'signed':True, 'factor':2**-21, 'unit':utility.METER_PER_SECOND},
    {'name':"deltan0",             'range':[109,125],   'signed':True, 'factor':2**-44, 'unit':utility.SEMICIRCLE_PER_SECOND},
    {'name':"deltan0Dot",          'range':[126,148],   'signed':True, 'factor':2**-57, 'unit':utility.SEMICIRCLE_PER_SECOND_SQUARED},
    {'name':"M0n",                 'range':[149,181],   'signed':True, 'factor':2**-32, 'unit':utility.SEMICIRCLE},
    {'name':"en",                  'range':[182,214],                  'factor':2**-34},
    {'name':"omegan",              'range':[215,247],   'signed':True, 'factor':2**-32, 'unit':utility.SEMICIRCLE},
    {'name':"omega0n",             'range':[248,280],   'signed':True, 'factor':2**-32, 'unit':utility.SEMICIRCLE},
    {'name':"i0n",                 'range':[281,313],   'signed':True, 'factor':2**-32, 'unit':utility.SEMICIRCLE},
    {'name':"deltaOmegaDot",       'range':[314,330],   'signed':True, 'factor':2**-44, 'unit':utility.SEMICIRCLE_PER_SECOND},
    {'name':"i0nDot",              'range':[331,345],   'signed':True, 'factor':2**-44, 'unit':utility.SEMICIRCLE_PER_SECOND},
    {'name':"Cisn",                'range':[346,361],   'signed':True, 'factor':2**-30, 'unit':utility.RADIAN},
    {'name':"Cicn",                'range':[362,377],   'signed':True, 'factor':2**-30, 'unit':utility.RADIAN},
    {'name':"Crsn",                'range':[378,401],   'signed':True, 'factor':2**-8,  'unit':utility.RADIAN},
    {'name':"Crcn",                'range':[402,425],   'signed':True, 'factor':2**-8,  'unit':utility.RADIAN},
    {'name':"Cusn",           	   'range':[426,446],   'signed':True, 'factor':2**-30, 'unit':utility.RADIAN},
    {'name':"Cucn",                'range':[447,467],   'signed':True, 'factor':2**-30, 'unit':utility.RADIAN},
    {'name':"URANED0Index",        'range':[468,472],   'signed':True},
    {'name':"URANED1Index",        'range':[473,475]},
    {'name':"URANED2Index",        'range':[476,478]},
    {'name':"af2n",                'range':[479,488],   'signed':True, 'factor':2**-60, 'unit':utility.SECOND_PER_SECOND_SQUARED},
    {'name':"af1n",                'range':[489,508],   'signed':True, 'factor':2**-48, 'unit':utility.SECOND_PER_SECOND},
    {'name':"af0n",                'range':[509,534],   'signed':True, 'factor':2**-35, 'unit':utility.SECOND},
    {'name':"TGD",                 'range':[535,547],   'signed':True, 'factor':2**-35, 'unit':utility.SECOND},
    {'name':"ISCL1CP",             'range':[548,560],   'signed':True, 'factor':2**-35, 'unit':utility.SECOND},
    {'name':"ISCL1CD",             'range':[561,573],   'signed':True, 'factor':2**-35, 'unit':utility.SECOND},
    {'name':"ISF",                 'range':[574,574]},
    {'name':"WNOP",                'range':[575,582],                                   'unit':utility.WEEK},
    {'name':"reserved2",           'range':[583,584]},
    {'name':"CRC2",                'range':[585,608]},
    {'name':"PRN",                 'range':[609,616]},
    {'name':"pageNb",              'range':[617,622]},
    {'name':"ReservedPage7",       'range':[623,858]},
    {'name':"CRC3",                'range':[859,882]}]

def getGPSL1CANavigationMessageInBinary(message):
    words = message.split(" ")
    decodedMessage = ''
    for word in words[0:]:
        word = bin(int(word, 16))[2:].zfill(utility.WORD_SIZE)
        decodedMessage = decodedMessage + word[2:] # Remove padding at the start of the word
    return decodedMessage

def decodeGPSL1CANavigationMessageInBinary(message):
    words = message.split(" ")
    decodedMessage = bin(int(words[0], 16))[2:].zfill(utility.WORD_SIZE)[2:]
    inverseWord = decodedMessage[utility.WORD_SIZE - 3]
    for word in words[1:]:
        word = bin(int(word, 16))[2:].zfill(utility.WORD_SIZE)[2:]
        if inverseWord == '1':
            decodedMessage = decodedMessage + utility.getInversedBinaryValue(word[0:24]) + word[24:31]
        else:
            decodedMessage = decodedMessage + word
        inverseWord = word[utility.WORD_SIZE - 3]
    return decodedMessage

"""
    Main functions for decoding a GPS downlink navigation message.
"""
def getDictGPSL5NavigationMessage(message):
    binaryMessage = utility.convertToBinaryNavigationMessage(message, 320)
    dictToUse = {}
    type = int(binaryMessage[14:20], 2)
    if type in L5GpsDictAll:
        dictToUse = L5GpsDictAll[type]
    else:
        return dictToUse

    return utility.fillDict(binaryMessage, dictToUse)

def getDictGPSL1CANavigationMessageFromBinary(binaryMessage):
    sfID = int(binaryMessage[49:52], 2)
    svID = int(binaryMessage[62:68], 2)
    dictToUse = {}
    if sfID in L1CAGpsDictEphemeris:
        dictToUse = L1CAGpsDictEphemeris[sfID]
    elif  sfID == 4:
        if svID == 52: # Page 13.
            dictToUse = L1CADictSubframe4NMCT
        elif svID in [53, 54]: # Page 14-15.
            dictToUse = L1CADictSubframe4SystemUse
        elif svID == 55: # Page 17.
            dictToUse =  L1CADictSubframe4SpecialMessage
        elif svID == 56: # Page 18.
            dictToUse = L1CADictSubframe4UTCIONO
        elif svID == 63: # Page 25.
            dictToUse = L1CADictSubframe4HAC
        elif svID in [57, 58, 59, 60, 61, 62]: # Page 6-11-16-21 & 12-19-20-22-23-24.
            dictToUse = L1CADictSubframe4Reserved
        else: # Page 2 to 5 & 7 to 10.
            dictToUse = L1CADictSubframe4And5Almanac
    elif sfID == 5:
        if svID == 51: # Page 25.
            dictToUse = L1CADictSubframe5HealthSum
        else: # Page 1 to 24.
            dictToUse = L1CADictSubframe4And5Almanac
    else:
        return dictToUse

    return utility.fillDict(binaryMessage, dictToUse)

def getDictGPSL1CAEncodedNavigationMessage(message):
    binaryMessage = decodeGPSL1CANavigationMessageInBinary(message)
    return getDictGPSL1CANavigationMessageFromBinary(binaryMessage)

def getDictGPSL1CADecodedNavigationMessage(message):
    binaryMessage = getGPSL1CANavigationMessageInBinary(message)
    return getDictGPSL1CANavigationMessageFromBinary(binaryMessage)

def getDictGPSL1CEncodedNavigationMessage(message):
    binaryMessage = utility.convertToBinaryNavigationMessage(message, 1824)

    subframe1 = binaryMessage[0]
    for index in range(1,9):
        if binaryMessage[index]==binaryMessage[0]:
            subframe1 += "0"
        else:
            subframe1 += "1"
    
    subframe2and3 = binaryMessage[52:1800]
    subframe2 = ""
    subframe3 = ""

    for row in range(38):
        tmpRow = ""
        for column in range(46):
            tmpRow = tmpRow + subframe2and3[row + column * 38]
        
        if row < 26:
            subframe2 = subframe2 + tmpRow
        elif row == 26:
            subframe2 = subframe2 + tmpRow[0:4]
            subframe3 = subframe3 + tmpRow[4:46]
        else:
           subframe3 = subframe3 + tmpRow

    msg = subframe1[0:9] + subframe2[0:600] + subframe3[0:274]

    return getDictGPSL1CNavigationMessage(msg)

def getDictGPSL1CDecodedNavigationMessage(message):
    msg = utility.convertToBinaryNavigationMessage(message, 896)
    return getDictGPSL1CNavigationMessage(msg)

def getDictGPSL1CPartialNavigationMessage(message):
    tmp = utility.convertToBinaryNavigationMessage(message, 1824)
    subframe1 = tmp[0]
    for index in range(1,9):
        if tmp[index]==tmp[0]:
            subframe1 += "0"
        else:
            subframe1 += "1"
    msg = subframe1[0:9] + tmp[52:652] + tmp[1252:1526]
    return getDictGPSL1CNavigationMessage(msg)

def getDictGPSL1CNavigationMessage(binaryMessage):
    dictToUse = {}
    page = int(binaryMessage[617:623], 2)
    if page == 1:
        dictToUse = L1CDictPage1
    elif page==2:
        dictToUse = L1CDictPage2
    elif page==3:
        dictToUse = L1CDictPage3
    elif page==4:
        dictToUse = L1CDictPage4
    elif page==5:
        dictToUse = L1CDictPage5
    elif page==6:
        dictToUse = L1CDictPage6
    elif page==7:
        dictToUse = L1CDictPage7
    else:
        return dictToUse

    return utility.fillDict(binaryMessage, dictToUse)
