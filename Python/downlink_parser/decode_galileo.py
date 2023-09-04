#!/usr/bin/env python3
"""
    Messages supported :
        Galileo F/Nav E5a
        Galileo I/Nav E1/E5b
        Galileo C/Nav HAS Message
"""

import utility

"""
    Informations for decoding Galieo F/Nav navigation messages.
"""
FNavDictType1 = [
    {'name':"Type",         'range':[0,5]},
    {'name':"SVID",         'range':[6,11]},
    {'name':"IODnav",       'range':[12,21]},
    {'name':"t0c",          'range':[22,35],                  'factor':60,     'unit':utility.SECOND},
    {'name':"af0",          'range':[36,66],   'signed':True, 'factor':2**-34, 'unit':utility.SECOND},
    {'name':"af1",          'range':[67,87],   'signed':True, 'factor':2**-46, 'unit':utility.SECOND_PER_SECOND},
    {'name':"af2",          'range':[88,93],   'signed':True, 'factor':2**-59, 'unit':utility.SECOND_PER_SECOND_SQUARED},
    {'name':"SISA(E1,E5a)", 'range':[94,101]},
    {'name':"ai0",          'range':[102,112],                'factor':2**-2,  'unit':utility.SOLAR_FLUX},
    {'name':"ai1",          'range':[113,123], 'signed':True, 'factor':2**-8,  'unit':utility.SOLAR_FLUX_PER_DEGREE},
    {'name':"ai2",          'range':[124,137], 'signed':True, 'factor':2**-15, 'unit':utility.SOLAR_FLUX_PER_DEGREE_SQUARED},
    {'name':"Iono Flags",   'range':[138,142]},
    {'name':"BGD(E1,E5a)",  'range':[143,152], 'signed':True, 'factor':2**-32, 'unit':utility.SECOND},
    {'name':"E5aHS",        'range':[153,154]},
    {'name':"WN",           'range':[155,166],                                 'unit':utility.WEEK},
    {'name':"TOW",          'range':[167,186],                                 'unit':utility.SECOND},
    {'name':"E5aDVS",       'range':[187,187]},
    {'name':"Spare",        'range':[188,213]},
    {'name':"CRC",          'range':[214,237]},
    {'name':"Tail",         'range':[238,243]}]

FNavDictType2 = [
    {'name':"Type",         'range':[0,5]},
    {'name':"IODnav",       'range':[6,15]},
    {'name':"M0",           'range':[16,47],   'signed':True, 'factor':2**-31, 'unit':utility.SEMICIRCLE},
    {'name':"Omegadot",     'range':[48,71],   'signed':True, 'factor':2**-43, 'unit':utility.SEMICIRCLE_PER_SECOND},
    {'name':"e",            'range':[72,103],                 'factor':2**-33,                    },
    {'name':"SqrtA",        'range':[104,135],                'factor':2**-19, 'unit':utility.METER_SQUARE_ROOT},
    {'name':"Omega0",       'range':[136,167], 'signed':True, 'factor':2**-31, 'unit':utility.SEMICIRCLE},
    {'name':"idot",         'range':[168,181], 'signed':True, 'factor':2**-43, 'unit':utility.SEMICIRCLE_PER_SECOND},
    {'name':"WN",           'range':[182,193],                                 'unit':utility.WEEK},
    {'name':"TOW",          'range':[194,213],                                 'unit':utility.SECOND},
    {'name':"CRC",          'range':[214,237]},
    {'name':"Tail",         'range':[238,243]}]

FNavDictType3 = [
    {'name':"Type",         'range':[0,5]},
    {'name':"IODnav",       'range':[6,15]},
    {'name':"i0",           'range':[16,47],   'signed':True, 'factor':2**-31, 'unit':utility.SEMICIRCLE},
    {'name':"Omega",        'range':[48,79],   'signed':True, 'factor':2**-31, 'unit':utility.SEMICIRCLE},
    {'name':"Delta-n",      'range':[80,95],   'signed':True, 'factor':2**-43, 'unit':utility.SEMICIRCLE_PER_SECOND},
    {'name':"Cuc",          'range':[96,111],  'signed':True, 'factor':2**-29, 'unit':utility.RADIAN},
    {'name':"Cus",          'range':[112,127], 'signed':True, 'factor':2**-29, 'unit':utility.RADIAN},
    {'name':"Crc",          'range':[128,143], 'signed':True, 'factor':2**-5,  'unit':utility.METER},
    {'name':"Crs",          'range':[144,159], 'signed':True, 'factor':2**-5,  'unit':utility.METER},
    {'name':"t0e",          'range':[160,173],                'factor':60,     'unit':utility.SECOND},
    {'name':"WN",           'range':[174,185],                                 'unit':utility.WEEK},
    {'name':"TOW",          'range':[186,205],                                 'unit':utility.SECOND},
    {'name':"Spare",        'range':[206,213], 'signed':True},
    {'name':"CRC",          'range':[214,237]},
    {'name':"Tail",         'range':[238,243]}]

FNavDictType4 = [
    {'name':"Type",         'range':[0,5]},
    {'name':"IODnav",       'range':[6,15]},
    {'name':"Cic",          'range':[16,31],   'signed':True, 'factor':2**-29, 'unit':utility.RADIAN},
    {'name':"Cis",          'range':[32,47],   'signed':True, 'factor':2**-29, 'unit':utility.RADIAN},
    {'name':"A0",           'range':[48,79],   'signed':True, 'factor':2**-30, 'unit':utility.SECOND},
    {'name':"A1",           'range':[80,103],  'signed':True, 'factor':2**-50, 'unit':utility.SECOND_PER_SECOND},
    {'name':"Delta-tLS",    'range':[104,111], 'signed':True,                  'unit':utility.SECOND},
    {'name':"t0t",          'range':[112,119],                'factor':3600,   'unit':utility.SECOND},
    {'name':"WN0t",         'range':[120,127],                                 'unit':utility.WEEK},
    {'name':"WNLSF",        'range':[128,135],                                 'unit':utility.WEEK},
    {'name':"DN",           'range':[136,138],                                 'unit':utility.DAY},
    {'name':"Delta-tLSF",   'range':[139,146], 'signed':True,                  'unit':utility.SECOND},
    {'name':"t0G",          'range':[147,154],                'factor':3600,   'unit':utility.SECOND},
    {'name':"A0G",          'range':[155,170], 'signed':True, 'factor':2**-35, 'unit':utility.SECOND},
    {'name':"A1G",          'range':[171,182], 'signed':True, 'factor':2**-51, 'unit':utility.SECOND_PER_SECOND},
    {'name':"WN0G",         'range':[183,188],                                 'unit':utility.WEEK},
    {'name':"TOW",          'range':[189,208],                                 'unit':utility.SECOND},
    {'name':"Spare",        'range':[209,213]},
    {'name':"CRC",          'range':[214,237]},
    {'name':"Tail",         'range':[238,243]}]

FNavDictType5 = [
    {'name':"Type",         'range':[0,5]},
    {'name':"IODa",         'range':[6,9]},
    {'name':"WNa",          'range':[10,11],                                   'unit':utility.WEEK},
    {'name':"t0a",          'range':[12,21],                  'factor':600,    'unit':utility.SECOND},
    {'name':"SVID 1",       'range':[22,27]},
    {'name':"DeltaSqrtA 1", 'range':[28,40],   'signed':True, 'factor':2**-9,  'unit':utility.METER_SQUARE_ROOT},
    {'name':"e 1",          'range':[41,51],                  'factor':2**-16},
    {'name':"Omega 1",      'range':[52,67],   'signed':True, 'factor':2**-15, 'unit':utility.SEMICIRCLE},
    {'name':"Delta-i 1",    'range':[68,78],   'signed':True, 'factor':2**-14, 'unit':utility.SEMICIRCLE},
    {'name':"Omega0 1",     'range':[79,94],   'signed':True, 'factor':2**-15, 'unit':utility.SEMICIRCLE},
    {'name':"OmegaDot 1",   'range':[95,105],  'signed':True, 'factor':2**-33, 'unit':utility.SEMICIRCLE_PER_SECOND},
    {'name':"M0 1",         'range':[106,121], 'signed':True, 'factor':2**-15, 'unit':utility.SEMICIRCLE},
    {'name':"af0 1",        'range':[122,137], 'signed':True, 'factor':2**-19, 'unit':utility.SECOND},
    {'name':"af1 1",        'range':[138,150], 'signed':True, 'factor':2**-38, 'unit':utility.SECOND_PER_SECOND},
    {'name':"E5aHS 1",      'range':[151,152]},
    {'name':"SVID 2",       'range':[153,158]},
    {'name':"DeltaSqrtA 2", 'range':[159,171], 'signed':True, 'factor':2**-9,  'unit':utility.METER_SQUARE_ROOT},
    {'name':"e 2",          'range':[172,182],                'factor':2**-16},
    {'name':"Omega 2",      'range':[183,198], 'signed':True, 'factor':2**-15, 'unit':utility.SEMICIRCLE},
    {'name':"Delta-i 2",    'range':[199,209], 'signed':True, 'factor':2**-14, 'unit':utility.SEMICIRCLE},
    {'name':"Omega0 2 p1",  'range':[210,213], 'signed':True, 'factor':2**-15, 'unit':utility.SEMICIRCLE},
    {'name':"CRC",          'range':[214,237]},
    {'name':"Tail",         'range':[238,243]}]

FNavDictType6 = [
    {'name':"Type",         'range':[0,5]},
    {'name':"IODa",         'range':[6,9]},
    {'name':"Omega0 2 p2",  'range':[10,21],   'signed':True, 'factor':2**-15, 'unit':utility.SEMICIRCLE},
    {'name':"OmegaDot 2",   'range':[22,32],   'signed':True, 'factor':2**-33, 'unit':utility.SEMICIRCLE_PER_SECOND},
    {'name':"M0 2",         'range':[33,48],   'signed':True, 'factor':2**-15, 'unit':utility.SEMICIRCLE},
    {'name':"af0 2",        'range':[49,64],   'signed':True, 'factor':2**-19, 'unit':utility.SECOND},
    {'name':"af1 2",        'range':[65,77],   'signed':True, 'factor':2**-38, 'unit':utility.SECOND_PER_SECOND},
    {'name':"E5aHS 2",      'range':[78,79]},
    {'name':"SVID 3",       'range':[80,85]},
    {'name':"DeltaSqrtA 3", 'range':[86,98],   'signed':True, 'factor':2**-9,  'unit':utility.METER_SQUARE_ROOT},
    {'name':"e 3",          'range':[99,109],                 'factor':2**-16},
    {'name':"Omega 3",      'range':[110,125], 'signed':True, 'factor':2**-15, 'unit':utility.SEMICIRCLE},
    {'name':"Delta-i 3",    'range':[126,136], 'signed':True, 'factor':2**-14, 'unit':utility.SEMICIRCLE},
    {'name':"Omega0 3",     'range':[137,152], 'signed':True, 'factor':2**-15, 'unit':utility.SEMICIRCLE},
    {'name':"OmegaDot 3",   'range':[153,163], 'signed':True, 'factor':2**-33, 'unit':utility.SEMICIRCLE_PER_SECOND},
    {'name':"M0 3",         'range':[164,179], 'signed':True, 'factor':2**-15, 'unit':utility.SEMICIRCLE},
    {'name':"af0 3",        'range':[180,195], 'signed':True, 'factor':2**-19, 'unit':utility.SECOND},
    {'name':"af1 3",        'range':[196,208], 'signed':True, 'factor':2**-38, 'unit':utility.SECOND_PER_SECOND},
    {'name':"E5-HS 3",      'range':[209,210]},
    {'name':"Spare",        'range':[211,213]},
    {'name':"CRC",          'range':[214,237]},
    {'name':"Tail",         'range':[238,243]}]

FNavDictAll = {1:FNavDictType1, 2:FNavDictType2, 3:FNavDictType3, 4:FNavDictType4, 5:FNavDictType5, 6:FNavDictType6}

"""
    Informations for decoding Galieo I/Nav navigation messages.
"""
INavDictType0 = [
    {'name':"Even",        'range':[0,0]},
    {'name':"Type even",   'range':[1,1]},
    {'name':"Type",        'range':[2,7]},
    {'name':"Time",        'range':[8,9]},
    {'name':"Spare",       'range':[10,97]},
    {'name':"WN",          'range':[98,109],              'unit':utility.WEEK},
    {'name':"TOW",         'range':[[110,113],[122,137]], 'unit':utility.SECOND},
    {'name':"Tail even",   'range':[114,119]},

    {'name':"Odd",         'range':[120,120]},
    {'name':"Type odd",    'range':[121,121]},
    # TOW                          [122,137]
    {'name':"Reserved 1",  'range':[138,177]},
    {'name':"SAR",         'range':[178,199]},
    {'name':"Spare",       'range':[200,201]},
    {'name':"CRC",         'range':[202,225]},
    {'name':"SSP",         'range':[226,233]},
    {'name':"Tail odd",    'range':[234,239]}]

INavDictType1 = [
    {'name':"Even",        'range':[0,0]},
    {'name':"Type even",   'range':[1,1]},
    {'name':"Type",        'range':[2,7]},
    {'name':"IODnav",      'range':[8,17]},
    {'name':"t0e",         'range':[18,31],                'factor':60,     'unit':utility.SECOND},
    {'name':"M0",          'range':[32,63], 'signed':True, 'factor':2**-31, 'unit':utility.SEMICIRCLE},
    {'name':"e",           'range':[64,95],                'factor':2**-33},
    {'name':"SqrtA",       'range':[[96,113],[122,135]],   'factor':2**-19, 'unit':utility.METER_SQUARE_ROOT},
    {'name':"Tail even",   'range':[114,119]},

    {'name':"Odd",         'range':[120,120]},
    {'name':"Type odd",    'range':[121,121]},
    # SqrtA                        [122,135]
    {'name':"Reserved",    'range':[136,137]},
    {'name':"Reserved 1",  'range':[138,177]},
    {'name':"SAR",         'range':[178,199]},
    {'name':"Spare",       'range':[200,201]},
    {'name':"CRC",         'range':[202,225]},
    {'name':"SSP",         'range':[226,233]},
    {'name':"Tail odd",    'range':[234,239]}]

INavDictType2 = [
    {'name':"Even",        'range':[0,0]},
    {'name':"Type even",   'range':[1,1]},
    {'name':"Type",        'range':[2,7]},
    {'name':"IODnav",      'range':[8,17]},
    {'name':"Omega0",      'range':[18,49],   'signed':True, 'factor':2**-31, 'unit':utility.SEMICIRCLE},
    {'name':"i0",          'range':[50,81],   'signed':True, 'factor':2**-31, 'unit':utility.SEMICIRCLE},
    {'name':"Omega",       'range':[82,113],  'signed':True, 'factor':2**-31, 'unit':utility.SEMICIRCLE},
    {'name':"Tail even",   'range':[114,119]},

    {'name':"Odd",         'range':[120,120]},
    {'name':"Type odd",    'range':[121,121]},
    {'name':"idot",        'range':[122,135], 'signed':True, 'factor':2**-43, 'unit':utility.SEMICIRCLE_PER_SECOND},
    {'name':"Reserved",    'range':[136,137]},
    {'name':"Reserved 1",  'range':[138,177]},
    {'name':"SAR",         'range':[178,199]},
    {'name':"Spare",       'range':[200,201]},
    {'name':"CRC",         'range':[202,225]},
    {'name':"SSP",         'range':[226,233]},
    {'name':"Tail odd",    'range':[234,239]}]

INavDictType3 = [
    {'name':"Even",        'range':[0,0]},
    {'name':"Type even",   'range':[1,1]},
    {'name':"Type",        'range':[2,7]},
    {'name':"IODnav",      'range':[8,17]},
    {'name':"OmegaDot",    'range':[18,41],               'signed':True, 'factor':2**-43, 'unit':utility.SEMICIRCLE},
    {'name':"Delta-n",     'range':[42,57],               'signed':True, 'factor':2**-43, 'unit':utility.SEMICIRCLE_PER_SECOND},
    {'name':"Cuc",         'range':[58,73],               'signed':True, 'factor':2**-29, 'unit':utility.RADIAN},
    {'name':"Cus",         'range':[74,89],               'signed':True, 'factor':2**-29, 'unit':utility.RADIAN},
    {'name':"Crc",         'range':[90,105],              'signed':True, 'factor':2**-5,  'unit':utility.METER},
    {'name':"Crs",         'range':[[106,113],[122,129]], 'signed':True, 'factor':2**-5,  'unit':utility.METER},
    {'name':"Tail even",   'range':[114,119]},

    {'name':"Odd",         'range':[120,120]},
    {'name':"Type odd",    'range':[121,121]},
    #Crs                           [122,129]
    {'name':"SISA(E1,E5b)",'range':[130,137]},
    {'name':"Reserved 1",  'range':[138,177]},
    {'name':"SAR",         'range':[178,199]},
    {'name':"Spare",       'range':[200,201]},
    {'name':"CRC",         'range':[202,225]},
    {'name':"SSP",         'range':[226,233]},
    {'name':"Tail odd",    'range':[234,239]}]

INavDictType4 = [
    {'name':"Even",        'range':[0,0]},
    {'name':"Type even",   'range':[1,1]},
    {'name':"Type",        'range':[2,7]},
    {'name':"IODnav",      'range':[8,17]},
    {'name':"SVID",        'range':[18,23]},
    {'name':"Cic",         'range':[24,39],               'signed':True, 'factor':2**-29, 'unit':utility.RADIAN},
    {'name':"Cis",         'range':[40,55],               'signed':True, 'factor':2**-29, 'unit':utility.RADIAN},
    {'name':"t0c",         'range':[56,69],                              'factor':60,     'unit':utility.SECOND},
    {'name':"af0",         'range':[70,100],              'signed':True, 'factor':2**-34, 'unit':utility.SECOND},
    {'name':"af1",         'range':[[101,113],[122,129]], 'signed':True, 'factor':2**-46, 'unit':utility.SECOND_PER_SECOND},
    {'name':"Tail even",   'range':[114,119]},

    {'name':"Odd",         'range':[12,120]},
    {'name':"Type odd",    'range':[121,121]},
    #af1                           [122,129]
    {'name':"af2",         'range':[130,135],             'signed':True, 'factor':2**-59, 'unit':utility.SECOND_PER_SECOND_SQUARED},
    {'name':"Reserved",    'range':[136,137]},
    {'name':"Reserved 1",  'range':[138,177]},
    {'name':"SAR",         'range':[178,199]},
    {'name':"Spare",       'range':[200,201]},
    {'name':"CRC",         'range':[202,225]},
    {'name':"SSP",         'range':[226,233]},
    {'name':"Tail odd",    'range':[234,239]}]

INavDictType5 = [
    {'name':"Even",        'range':[0,0]},
    {'name':"Type even",   'range':[1,1]},
    {'name':"Type",        'range':[2,7]},
    {'name':"ai0",         'range':[8,18],                 'factor':2**-2,  'unit':utility.SOLAR_FLUX},
    {'name':"ai1",         'range':[19,29], 'signed':True, 'factor':2**-8,  'unit':utility.SOLAR_FLUX_PER_DEGREE},
    {'name':"ai2",         'range':[30,43], 'signed':True, 'factor':2**-15, 'unit':utility.SOLAR_FLUX_PER_DEGREE_SQUARED},
    {'name':"Iono Flags",  'range':[44,48]},
    {'name':"BGD(E1,E5b)", 'range':[49,58], 'signed':True, 'factor':2**-32, 'unit':utility.SECOND},
    {'name':"BGD(E1,E5a)", 'range':[59,68], 'signed':True, 'factor':2**-32, 'unit':utility.SECOND},
    {'name':"E5bHS",       'range':[69,70]},
    {'name':"E1BHS",       'range':[71,72]},
    {'name':"E5bDVS",      'range':[73,73]},
    {'name':"E1BDVS",      'range':[74,74]},
    {'name':"WN",          'range':[75,86],                                 'unit':utility.WEEK},
    {'name':"TOW",         'range':[87,106],                                'unit':utility.SECOND},
    {'name':"Spare",       'range':[[107,113],[122,137]],                   'unit':utility.SECOND},
    {'name':"Tail even",   'range':[114,119]},

    {'name':"Odd",         'range':[120,120]},
    {'name':"Type odd",    'range':[121,121]},
    #spare                         [122,137]
    {'name':"Reserved 1",  'range':[138,177]},
    {'name':"SAR",         'range':[178,199]},
    {'name':"Spare",       'range':[200,201]},
    {'name':"CRC",         'range':[202,225]},
    {'name':"SSP",         'range':[226,233]},
    {'name':"Tail odd",    'range':[234,239]}]

INavDictType6 = [
    {'name':"Even",        'range':[0,0]},
    {'name':"Type even",   'range':[1,1]},
    {'name':"Type",        'range':[2,7]},
    {'name':"A0",          'range':[8,39],                'signed':True, 'factor':2**-30, 'unit':utility.SECOND},
    {'name':"A1",          'range':[40,63],               'signed':True, 'factor':2**-50, 'unit':utility.SECOND_PER_SECOND},
    {'name':"Delta-tLS",   'range':[64,71],                                               'unit':utility.SECOND},
    {'name':"t0t",         'range':[72,79],                              'factor':3600,   'unit':utility.SECOND},
    {'name':"WN0t",        'range':[80,87],                                               'unit':utility.WEEK},
    {'name':"WNLSF",       'range':[88,95],                                               'unit':utility.WEEK},
    {'name':"DN",          'range':[96,98],               'signed':True,                  'unit':utility.DAY},
    {'name':"Delta-tLSF",  'range':[99,106],                                              'unit':utility.SECOND},
    {'name':"TOW",         'range':[[107,113],[122,134]], 'signed':True,                  'unit':utility.SECOND},
    {'name':"Tail even",   'range':[114,119]},

    {'name':"Odd",         'range':[120,120]},
    {'name':"Type odd",    'range':[121,121]},
    #TOW                           [122,134]
    {'name':"Spare",       'range':[135,137]},
    {'name':"Reserved 1",  'range':[138,177]},
    {'name':"SAR",         'range':[178,199]},
    {'name':"Spare",       'range':[200,201]},
    {'name':"CRC",         'range':[202,225]},
    {'name':"SSP",         'range':[226,233]},
    {'name':"Tail odd",    'range':[234,239]}]

INavDictType7 = [
    {'name':"Even",        'range':[0,0]},
    {'name':"Type even",   'range':[1,1]},
    {'name':"Type",        'range':[2,7]},
    {'name':"IODa",        'range':[8,11]},
    {'name':"WNa",         'range':[12,13],                                               'unit':utility.WEEK},
    {'name':"t0a",         'range':[14,23],               'signed':True, 'factor':600,    'unit':utility.SECOND},
    {'name':"SVID 1",      'range':[24,29]},
    {'name':"DeltaSqrtA 1",'range':[30,42],               'signed':True, 'factor':2**-9,  'unit':utility.METER_SQUARE_ROOT},
    {'name':"e 1",         'range':[43,53],                              'factor':2**-16},
    {'name':"Omega 1",     'range':[54,69],               'signed':True, 'factor':2**-15, 'unit':utility.SEMICIRCLE},
    {'name':"Delta-i 1",   'range':[70,80],               'signed':True, 'factor':2**-14, 'unit':utility.SEMICIRCLE},
    {'name':"Omega0 1",    'range':[81,96],               'signed':True, 'factor':2**-15, 'unit':utility.SEMICIRCLE},
    {'name':"OmegaDot 1",  'range':[97,107],              'signed':True, 'factor':2**-33, 'unit':utility.SEMICIRCLE},
    {'name':"M0 1",        'range':[[108,113],[122,131]], 'signed':True, 'factor':2**-15, 'unit':utility.SEMICIRCLE},
    {'name':"Tail even",   'range':[114,119]},

    {'name':"Odd",         'range':[120,120]},
    {'name':"Type odd",    'range':[121,121]},
    # M0 1                         [122,131]
    {'name':"Reserved",    'range':[132,137]},
    {'name':"Reserved 1",  'range':[138,177]},
    {'name':"SAR",         'range':[178,199]},
    {'name':"Spare",       'range':[200,201]},
    {'name':"CRC",         'range':[202,225]},
    {'name':"SSP",         'range':[226,233]},
    {'name':"Tail odd",    'range':[234,239]}]

INavDictType8 = [
    {'name':"Even",         'range':[0,0]},
    {'name':"Type even",    'range':[1,1]},
    {'name':"Type",         'range':[2,7]},
    {'name':"IODa",         'range':[8,11]},
    {'name':"af0 1",        'range':[12,27],               'signed':True, 'factor':2**-19, 'unit':utility.SECOND},
    {'name':"af1 1",        'range':[28,40],               'signed':True, 'factor':2**-38, 'unit':utility.SECOND_PER_SECOND},
    {'name':"E5bHS 1",      'range':[41,42]},
    {'name':"E1BHs 1",      'range':[43,44]},
    {'name':"SVID 2",       'range':[45,50]},
    {'name':"DeltaSqrtA 2", 'range':[51,63],               'signed':True, 'factor':2**-9,  'unit':utility.METER_SQUARE_ROOT},
    {'name':"e 2",          'range':[64,74],                              'factor':2**-16},
    {'name':"Omega 2",      'range':[75,90],               'signed':True, 'factor':2**-15, 'unit':utility.SEMICIRCLE},
    {'name':"Delta-i 2",    'range':[91,101],              'signed':True, 'factor':2**-14, 'unit':utility.SEMICIRCLE},
    {'name':"Omega0 2",     'range':[[102,113],[122,125]], 'signed':True, 'factor':2**-15, 'unit':utility.SEMICIRCLE},
    {'name':"Tail even",    'range':[114,119]},

    {'name':"Odd",          'range':[120,120]},
    {'name':"Type odd",     'range':[121,121]},
    # Omega0 2                      [122,125]
    {'name':"OmegaDot 2",   'range':[126,136],             'signed':True, 'factor':2**-15, 'unit':utility.SEMICIRCLE},
    {'name':"Spare",        'range':[137,137]},
    {'name':"Reserved 1",   'range':[138,177]},
    {'name':"SAR",          'range':[178,199]},
    {'name':"Spare",        'range':[200,201]},
    {'name':"CRC",          'range':[202,225]},
    {'name':"SSP",          'range':[226,233]},
    {'name':"Tail odd",     'range':[234,239]}]

INavDictType9 = [
    {'name':"Even",        'range':[0,0]},
    {'name':"Type even",   'range':[1,1]},
    {'name':"Type",        'range':[2,7]},
    {'name':"IODa",        'range':[8,11]},
    {'name':"WNa",         'range':[12,13],                                               'unit':utility.WEEK},
    {'name':"t0a",         'range':[14,23],                              'factor':600,    'unit':utility.SEMICIRCLE},
    {'name':"M0 2",        'range':[24,39],               'signed':True, 'factor':2**-15, 'unit':utility.SEMICIRCLE},
    {'name':"af0 2",       'range':[40,55],               'signed':True, 'factor':2**-19, 'unit':utility.SECOND},
    {'name':"af1 2",       'range':[56,68],               'signed':True, 'factor':2**-38, 'unit':utility.SECOND_PER_SECOND},
    {'name':"E5bHS 2",     'range':[69,70]},
    {'name':"E1BHs 2",     'range':[71,72]},
    {'name':"SVID 3",      'range':[73,78]},
    {'name':"DeltaSqrtA 3",'range':[79,91],               'signed':True, 'factor':2**-9,  'unit':utility.METER_SQUARE_ROOT},
    {'name':"e 3",         'range':[92,102],                             'factor':2**-16},
    {'name':"Omega 3",     'range':[[103,113],[122,126]], 'signed':True, 'factor':2**-15, 'unit':utility.SEMICIRCLE},
    {'name':"Tail even",   'range':[114,119]},

    {'name':"Odd",         'range':[120,120]},
    {'name':"Type odd",    'range':[121,121]},
    # Omega 3                      [122,126]
    {'name':"Delta-i 3",   'range':[127,137],             'signed':True, 'factor':2**-14, 'unit':utility.SEMICIRCLE},
    {'name':"Reserved 1",  'range':[138,177]},
    {'name':"SAR",         'range':[178,199]},
    {'name':"Spare",       'range':[200,201]},
    {'name':"CRC",         'range':[202,225]},
    {'name':"SSP",         'range':[226,233]},
    {'name':"Tail odd",    'range':[234,239]}]

INavDictType10 = [
    {'name':"Even",        'range':[0,0]},
    {'name':"Type even",   'range':[1,1]},
    {'name':"Type",        'range':[2,7]},
    {'name':"IODa",        'range':[8,11]},
    {'name':"Omega0 3",    'range':[12,27],               'signed':True, 'factor':2**-15, 'unit':utility.SEMICIRCLE},
    {'name':"OmegaDot 3",  'range':[28,38],               'signed':True, 'factor':2**-33, 'unit':utility.SEMICIRCLE_PER_SECOND},
    {'name':"M0 3",        'range':[39,54],               'signed':True, 'factor':2**-15, 'unit':utility.SEMICIRCLE},
    {'name':"af0 3",       'range':[55,70],               'signed':True, 'factor':2**-19, 'unit':utility.SECOND},
    {'name':"af1 3",       'range':[71,83],               'signed':True, 'factor':2**-38, 'unit':utility.SECOND_PER_SECOND},
    {'name':"E5bHS 3",     'range':[84,85]},
    {'name':"E1BHs 3",     'range':[86,87]},
    {'name':"A0G",         'range':[88,103],              'signed':True, 'factor':2**-35, 'unit':utility.SECOND},
    {'name':"A1G",         'range':[[104,113],[122,123]], 'signed':True, 'factor':2**-51, 'unit':utility.SECOND_PER_SECOND},
    {'name':"Tail even",   'range':[114,119]},

    {'name':"Odd",         'range':[120,120]},
    {'name':"Type odd",    'range':[121,121]},
    # A1G                          [122,123]
    {'name':"t0G",         'range':[124,131],                            'factor':3600,   'unit':utility.SECOND},
    {'name':"WN0G",        'range':[132,137],                                             'unit':utility.WEEK},
    {'name':"Reserved 1",  'range':[138,177]},
    {'name':"SAR",         'range':[178,199]},
    {'name':"Spare",       'range':[200,201]},
    {'name':"CRC",         'range':[202,225]},
    {'name':"SSP",         'range':[226,233]},
    {'name':"Tail odd",    'range':[234,239]}]

INavDictType16 = [
    {'name':"Even",       'range':[0,0]},
    {'name':"Type even",  'range':[1,1]},
    {'name':"Type",       'range':[2,7]},
    {'name':"DeltaA",     'range':[8,12],                'signed':True, 'factor':2**8,   'unit':utility.METER},
    {'name':"ex",         'range':[13,25],               'signed':True, 'factor':2**-22},
    {'name':"ey",         'range':[26,38],               'signed':True, 'factor':2**-22},
    {'name':"Delta-i0",   'range':[39,55],               'signed':True, 'factor':2**-22, 'unit':utility.SEMICIRCLE},
    {'name':"Omega0",     'range':[56,78],               'signed':True, 'factor':2**-22, 'unit':utility.SEMICIRCLE},
    {'name':"Lambda0",    'range':[79,101],              'signed':True, 'factor':2**-22, 'unit':utility.SEMICIRCLE},
    {'name':"af0",        'range':[[102,113],[122,131]], 'signed':True, 'factor':2**-26, 'unit':utility.SECOND},
    {'name':"Tail even",  'range':[114,119]},

    {'name':"Odd",        'range':[120,120]},
    {'name':"Type odd",   'range':[121,121]},
    # af0                         [122, 131]
    {'name':"af1",        'range':[132,137],             'signed':True, 'factor':2**-35, 'unit':utility.SECOND_PER_SECOND},
    {'name':"Reserved 1", 'range':[138,177]},
    {'name':"SAR",        'range':[178,199]},
    {'name':"Spare",      'range':[200,201]},
    {'name':"CRC",        'range':[202,225]},
    {'name':"SSP",        'range':[226,233]},
    {'name':"Tail odd",   'range':[234,239]}]

INavDictType17To20 = [
    {'name':"Even",        'range':[0,0]},
    {'name':"Type even",   'range':[1,1]},
    {'name':"Type",        'range':[2,7]},
    {'name':"FEC2 RS 1",   'range':[8,15]},
    {'name':"IODlsb",      'range':[16,17]},
    {'name':"FEC2 RS 2",   'range':[[18,113],[122,137]]},
    {'name':"Tail even",   'range':[114,119]},

    {'name':"Odd",         'range':[120,120]},
    {'name':"Type odd",    'range':[121,121]},
    # FEC2 RS 2                    [122,137]
    {'name':"Reserved 1",  'range':[138,177]},
    {'name':"SAR",         'range':[178,199]},
    {'name':"Spare",       'range':[200,201]},
    {'name':"CRC",         'range':[202,225]},
    {'name':"SSP",         'range':[226,233]},
    {'name':"Tail odd",    'range':[234,239]}]

INavDictAll = {0:INavDictType0, 1:INavDictType1, 2:INavDictType2, 3:INavDictType3, 4:INavDictType4, 5:INavDictType5, 6:INavDictType6, 7:INavDictType7, 8:INavDictType8, 9:INavDictType9, 10:INavDictType10, 16:INavDictType16, 17:INavDictType17To20, 18:INavDictType17To20, 19:INavDictType17To20, 20:INavDictType17To20}

def decodeGalileoINavigationMessageInBinary(message, size):
	raw = bin(int(message.replace(" ", ""), 16))[2:].zfill(size)
	return raw[0:120] + raw[128:]

"""
    Informations for decoding Galieo C/Nav HAS navigation messages.
"""

CNavHASDict = [
    {'name':"TOH",                   'range':[0,11]},
    {'name':"Mask Flag",             'range':[12,12]},
    {'name':"Orbit Correction Flag", 'range':[13,13]},
    {'name':"Clock Fullset Flag",    'range':[14,14]},
    {'name':"Clock Subset Flag",     'range':[15,15]},
    {'name':"Code Bias Flag",        'range':[16,16]},
    {'name':"Phase Bias Flag",       'range':[17,17]},
    {'name':"Reserved",              'range':[18,21]},
    {'name':"Mask ID",               'range':[22,26]},
    {'name':"IOD Set ID",            'range':[27,31]}]

"""
    Main functions for decoding a Galileo downlink navigation message.
"""
def getDictGalileoFNavigationMessage(message):
    binaryMessage = utility.convertToBinaryNavigationMessage(message, 256)
    dictToUse = {}
    type = int(binaryMessage[0:6], 2)
    if type in FNavDictAll:
        dictToUse = FNavDictAll[type]
    else:
        return dictToUse

    return utility.fillDict(binaryMessage, dictToUse)

def getDictGalileoINavigationMessage(message):
    binaryMessage = decodeGalileoINavigationMessageInBinary(message, 256)
    dictToUse = {}
    type = int(binaryMessage[2:8], 2)
    if type in INavDictAll:
        dictToUse = INavDictAll[type]
    else:
        return dictToUse

    return utility.fillDict(binaryMessage, dictToUse)

class GalileoCNavHasDictGenerator:
    binaryMessage = 0
    dictToUse = CNavHASDict
    currentBitIndex = 32

    def __init__(self, pages):
        self.binaryMessage = utility.convertToBinaryNavigationMessage(pages[0], 424)
        pageIndex = 1
        while pageIndex < len(pages) - 1:
            self.binaryMessage = self.binaryMessage + utility.convertToBinaryNavigationMessage(pages[pageIndex], 424)
            pageIndex += 1

    def addParametertoDict(self, name, size, signed = False, factor = 1, unit = ""):
        self.dictToUse.append({'name':name, 'range':[self.currentBitIndex, self.currentBitIndex + size - 1], 'signed':signed, 'factor':factor, 'unit':unit})
        self.currentBitIndex += size

    def getParameterValue(self, size):
        return int(self.binaryMessage[self.currentBitIndex:self.currentBitIndex + size], 2)

def getIODSize(nsys, sys):
    if nsys == 1 or sys == 2:
        return 10
    else:
        return 8

def getDictGalileoCNavigationMessage(message):
    pages = str(message).split(' ')

    gen = GalileoCNavHasDictGenerator(pages)
    satCounts = []
    sigCounts = []

    # Mask Block
    nsys = gen.getParameterValue(4)
    gen.addParametertoDict("NSys", 4)
    for sys in range(1, nsys + 1):
        gen.addParametertoDict("GNSS ID {0}".format(sys), 4)
        satM = gen.getParameterValue(40)
        gen.addParametertoDict("SatM {0}".format(sys), 40)
        sigM = gen.getParameterValue(16)
        gen.addParametertoDict("SigM {0}".format(sys), 16)
        gen.addParametertoDict("CMAF {0}".format(sys), 1)
        satCount = bin(satM).count("1")
        sigCount = bin(sigM).count("1")
        for sat in range(1, satCount + 1):
            for sig in range(1, sigCount + 1):
                gen.addParametertoDict("CM {0} Sat{1} Sig{2}".format(sys, sat, sig), 1)
        gen.addParametertoDict("NM {0}".format(sys), 3)
        satCounts.append(satCount)
        sigCounts.append(sigCount)
    gen.addParametertoDict("Mask Block Reserved", 6)

    # Orbit Block
    gen.addParametertoDict("Orbit Block Validity Interval", 4)
    for sys in range(1, nsys + 1):
        for sat in range(1, satCounts[sys - 1] + 1):
            gen.addParametertoDict("IODref Sys{0} Sat{1}".format(sys, sat), getIODSize(nsys, sys))
            gen.addParametertoDict("DR Sys{0} Sat{1}".format(sys, sat), 13, True, 0.0025, utility.METER)
            gen.addParametertoDict("DIT Sys{0} Sat{1}".format(sys, sat), 12, True, 0.0080, utility.METER)
            gen.addParametertoDict("DCT Sys{0} Sat{1}".format(sys, sat), 12, True, 0.0080, utility.METER)

    # Clock Full-Set Block
    gen.addParametertoDict("Clock Full-Set Validity Interval", 4)
    for sys in range(1, nsys + 1):
        gen.addParametertoDict("DCM {0}".format(sys), 2)
    for sys in range(1, nsys + 1):
        for sat in range(1, satCounts[sys - 1] + 1):
            gen.addParametertoDict("DCC Sys{0} Sat{1}".format(sys, sat), 13, True, 0.0025, utility.METER)

    # Code Biases Block
    gen.addParametertoDict("Code Biases Validity Interval", 4)
    for sys in range(1, nsys + 1):
        for sat in range(1, satCounts[sys - 1] + 1):
            for sig in range(1, sigCounts[sys - 1] + 1):
                gen.addParametertoDict("CB Sys{0} Sat{1} Sig{2}".format(sys, sat, sig), 11, True, 0.02, utility.METER)

    # Phase Biases Block
    gen.addParametertoDict("Phase Biases Validity Interval", 4)
    for sys in range(1, nsys + 1):
        for sat in range(1, satCounts[sys - 1] + 1):
            for sig in range(1, sigCounts[sys - 1] + 1):
                gen.addParametertoDict("PB Sys{0} Sat{1} Sig{2}".format(sys, sat, sig), 11, True, 0.01)
                gen.addParametertoDict("PDI Sys{0} Sat{1} Sig{2}".format(sys, sat, sig), 2)

    return utility.fillDict(gen.binaryMessage, gen.dictToUse)
