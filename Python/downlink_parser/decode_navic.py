#!/usr/bin/env python3
"""
    Messages supported :
        NavIC L1
        NavIC L5
        NavIC S
"""

import utility

"""
    Structure for NavIC L5
"""

NavICNAVDictSubframe1 = [
    {'name':"TLM",         'range':[0,7]},
    {'name':"TOWC",        'range':[8,24]},
    {'name':"ALERT",       'range':[25,25]},
    {'name':"AUTONAV",     'range':[26,26]},
    {'name':"SUBFRAME ID", 'range':[27,28]},
    {'name':"SPARE",       'range':[29,29]},
    
    {'name':"WN",          'range':[30,39],                                   'unit':utility.WEEK},
    {'name':"af0",         'range':[40,61],   'signed':True, 'factor':2**-31, 'unit':utility.SECOND},
    {'name':"af1",         'range':[62,77],   'signed':True, 'factor':2**-43, 'unit':utility.SECOND_PER_SECOND},
    {'name':"af2",         'range':[78,85],   'signed':True, 'factor':2**-55, 'unit':utility.SECOND_PER_SECOND_SQUARED},
    {'name':"URA",         'range':[86,89]},
    {'name':"toc",         'range':[90,105],                 'factor':16,     'unit':utility.SECOND},
    {'name':"TGD",         'range':[106,113], 'signed':True, 'factor':2**-31, 'unit':utility.SECOND},
    {'name':"deltan",      'range':[114,135], 'signed':True, 'factor':2**-41, 'unit':utility.SEMICIRCLE_PER_SECOND},
    {'name':"IODEC",       'range':[136,143]},
    {'name':"Res",         'range':[144,153]},
    {'name':"L5Flag",      'range':[154,154]},
    {'name':"SFlag",       'range':[155,155]},
    {'name':"Cuc",         'range':[156,170], 'signed':True, 'factor':2**-28, 'unit':utility.RADIAN},
    {'name':"Cus",         'range':[171,185], 'signed':True, 'factor':2**-28, 'unit':utility.RADIAN},
    {'name':"Cic",         'range':[186,200], 'signed':True, 'factor':2**-28, 'unit':utility.RADIAN},
    {'name':"Cis",         'range':[201,215], 'signed':True, 'factor':2**-28, 'unit':utility.RADIAN},
    {'name':"Crc",         'range':[216,230], 'signed':True, 'factor':2**-4,  'unit':utility.METER},
    {'name':"Crs",         'range':[231,245], 'signed':True, 'factor':2**-4,  'unit':utility.METER},
    {'name':"IDOT",        'range':[246,259], 'signed':True, 'factor':2**-43, 'unit':utility.SEMICIRCLE_PER_SECOND},
    {'name':"Spare",       'range':[260,261]},

    {'name':"CRC",         'range':[262,285]},
    {'name':"TAIL",        'range':[286,291]}]

NavICNAVDictSubframe2 = [
    {'name':"TLM",         'range':[0,7]},
    {'name':"TOWC",        'range':[8,24]},
    {'name':"ALERT",       'range':[25,25]},
    {'name':"AUTONAV",     'range':[26,26]},
    {'name':"SUBFRAME ID", 'range':[27,28]},
    {'name':"SPARE",       'range':[29,29]},

    {'name':"M0",          'range':[30,61],   'signed':True, 'factor':2**-31,  'unit':utility.SEMICIRCLE},
    {'name':"toe",         'range':[62,77],                  'factor':16,      'unit':utility.SECOND},
    {'name':"e",           'range':[78,109],                 'factor':2**-33},
    {'name':"sqrtA",       'range':[110,141],                'factor':2**-19,  'unit':utility.METER_SQUARE_ROOT},
    {'name':"omega0",      'range':[142,173], 'signed':True, 'factor':2**-31,  'unit':utility.SEMICIRCLE},
    {'name':"omega",       'range':[174,205], 'signed':True, 'factor':2**-31,  'unit':utility.SEMICIRCLE},
    {'name':"omegaDot",    'range':[206,227], 'signed':True, 'factor':2**-41,  'unit':utility.SEMICIRCLE_PER_SECOND},
    {'name':"i0",          'range':[228,259], 'signed':True, 'factor':2**-31,  'unit':utility.SEMICIRCLE},
    {'name':"Spare",       'range':[260,261]},

    {'name':"CRC",         'range':[262,285]},
    {'name':"TAIL",        'range':[286,291]}]

NavICNAVDictMessage0 = [
    {'name':"TLM",         'range':[0,7]},
    {'name':"TOWC",        'range':[8,24]},
    {'name':"ALERT",       'range':[25,25]},
    {'name':"AUTONAV",     'range':[26,26]},
    {'name':"SUBFRAME ID", 'range':[27,28]},
    {'name':"SPARE",       'range':[29,29]},
    {'name':"MESSAGE ID",  'range':[30,35]},

    {'name':"DATA",        'range':[36,255]},

    {'name':"PRN ID",      'range':[256,261]},
    {'name':"CRC",         'range':[262,285]},
    {'name':"TAIL",        'range':[286,291]}]

NavICNAVDictMessage5 = [
    {'name':"TLM",           'range':[0,7]},
    {'name':"TOWC",          'range':[8,24]},
    {'name':"ALERT",         'range':[25,25]},
    {'name':"AUTONAV",       'range':[26,26]},
    {'name':"SUBFRAME ID",   'range':[27,28]},
    {'name':"SPARE",         'range':[29,29]},
    {'name':"MESSAGE ID",    'range':[30,35]},

    {'name':"RegionsMasked", 'range':[36,45]},
    {'name':"RegionId",      'range':[46,49]},
    {'name':"GIVEI1",        'range':[50,53]},
    {'name':"GIVD1",         'range':[54,62],   'factor':0.125, 'unit':utility.METER},
    {'name':"GIVEI2",        'range':[63,66]},
    {'name':"GIVD2",         'range':[67,75],   'factor':0.125, 'unit':utility.METER},
    {'name':"GIVEI3",        'range':[76,79]},
    {'name':"GIVD3",         'range':[80,88],   'factor':0.125, 'unit':utility.METER},
    {'name':"GIVEI4",        'range':[89,92]},
    {'name':"GIVD4",         'range':[93,101],  'factor':0.125, 'unit':utility.METER},
    {'name':"GIVEI5",        'range':[102,105]},
    {'name':"GIVD5",         'range':[106,114], 'factor':0.125, 'unit':utility.METER},
    {'name':"GIVEI6",        'range':[115,118]},
    {'name':"GIVD6",         'range':[119,127], 'factor':0.125, 'unit':utility.METER},
    {'name':"GIVEI7",        'range':[128,131]},
    {'name':"GIVD7",         'range':[132,140], 'factor':0.125, 'unit':utility.METER},
    {'name':"GIVEI8",        'range':[141,144]},
    {'name':"GIVD8",         'range':[145,153], 'factor':0.125, 'unit':utility.METER},
    {'name':"GIVEI9",        'range':[154,157]},
    {'name':"GIVD9",         'range':[158,166], 'factor':0.125, 'unit':utility.METER},
    {'name':"GIVEI10",       'range':[167,170]},
    {'name':"GIVD10",        'range':[171,179], 'factor':0.125, 'unit':utility.METER},
    {'name':"GIVEI11",       'range':[180,183]},
    {'name':"GIVD11",        'range':[184,192], 'factor':0.125, 'unit':utility.METER},
    {'name':"GIVEI12",       'range':[193,196]},
    {'name':"GIVD12",        'range':[197,205], 'factor':0.125, 'unit':utility.METER},
    {'name':"GIVEI13",       'range':[206,209]},
    {'name':"GIVD13",        'range':[210,218], 'factor':0.125, 'unit':utility.METER},
    {'name':"GIVEI14",       'range':[219,222]},
    {'name':"GIVD14",        'range':[223,231], 'factor':0.125, 'unit':utility.METER},
    {'name':"GIVEI15",       'range':[232,235]},
    {'name':"GIVD15",        'range':[236,244], 'factor':0.125, 'unit':utility.METER},   
    {'name':"IODI",          'range':[245,247]},
    {'name':"Spare",         'range':[248,255]},

    {'name':"PRN ID",        'range':[256,261]},
    {'name':"CRC",           'range':[262,285]},
    {'name':"TAIL",          'range':[286,291]}]

NavICNAVDictMessage7 = [
    {'name':"TLM",         'range':[0,7]},
    {'name':"TOWC",        'range':[8,24]},
    {'name':"ALERT",       'range':[25,25]},
    {'name':"AUTONAV",     'range':[26,26]},
    {'name':"SUBFRAME ID", 'range':[27,28]},
    {'name':"SPARE",       'range':[29,29]},
    {'name':"MESSAGE ID",  'range':[30,35]},

    {'name':"WNa",         'range':[36,45]},
    {'name':"e",           'range':[46,61],                  'factor':2**-21},
    {'name':"toa",         'range':[62,77],                  'factor':2**4,   'unit':utility.SECOND},
    {'name':"i0",          'range':[78,101],  'signed':True, 'factor':2**-23, 'unit':utility.SEMICIRCLE}, 
    {'name':"omegaDot",    'range':[102,117], 'signed':True, 'factor':2**-38, 'unit':utility.SEMICIRCLE_PER_SECOND},
    {'name':"sqrtA",       'range':[118,141],                'factor':2**-11, 'unit':utility.METER_SQUARE_ROOT},
    {'name':"omega0",      'range':[142,165], 'signed':True, 'factor':2**-23, 'unit':utility.SEMICIRCLE},
    {'name':"omega",       'range':[166,189], 'signed':True, 'factor':2**-23, 'unit':utility.SEMICIRCLE},
    {'name':"M0",          'range':[190,213], 'signed':True, 'factor':2**-23, 'unit':utility.SEMICIRCLE},
    {'name':"af0",         'range':[214,224], 'signed':True, 'factor':2**-20, 'unit':utility.SECOND},
    {'name':"af1",         'range':[225,235], 'signed':True, 'factor':2**-38, 'unit':utility.SECOND_PER_SECOND},
    {'name':"PRN ID AL",   'range':[236,241]},
    {'name':"ISC",         'range':[242,249], 'signed':True, 'factor':2**-31, 'unit':utility.SECOND},
    {'name':"Spare",       'range':[250,255]},

    {'name':"PRN ID",      'range':[256,261]},
    {'name':"CRC",         'range':[262,285]},
    {'name':"TAIL",        'range':[286,291]}]

NavICNAVDictMessage9 = [
    {'name':"TLM",         'range':[0,7]},
    {'name':"TOWC",        'range':[8,24]},
    {'name':"ALERT",       'range':[25,25]},
    {'name':"AUTONAV",     'range':[26,26]},
    {'name':"SUBFRAME ID", 'range':[27,28]},
    {'name':"SPARE",       'range':[29,29]},
    {'name':"MESSAGE ID",  'range':[30,35]},

    {'name':"A0utc",       'range':[36,51], 'signed':True,  'factor':2**-35,  'unit':utility.SECOND},
    {'name':"A1utc",       'range':[52,64], 'signed':True,  'factor':2**-51,  'unit':utility.SECOND_PER_SECOND},
    {'name':"A2utc",       'range':[65,71], 'signed':True,  'factor':2**-68,  'unit':utility.SECOND_PER_SECOND_SQUARED},
    {'name':"deltatLS",    'range':[72,79], 'signed':True,                    'unit':utility.SECOND},
    {'name':"toutc",       'range':[80,95],                 'factor':2**4,    'unit':utility.SECOND},
    {'name':"WNoutc",      'range':[96,105],                                  'unit':utility.WEEK},
    {'name':"WNLSF",       'range':[106,115],                                 'unit':utility.WEEK},
    {'name':"DN",          'range':[116,119],                                 'unit':utility.DAY},
    {'name':"deltatLSF",   'range':[120,127], 'signed':True,                  'unit':utility.SECOND},
    {'name':"A0",          'range':[128,143], 'signed':True, 'factor':2**-35, 'unit':utility.SECOND},
    {'name':"A1",          'range':[144,156], 'signed':True, 'factor':2**-51, 'unit':utility.SECOND_PER_SECOND},
    {'name':"A2",          'range':[157,163], 'signed':True, 'factor':2**-68, 'unit':utility.SECOND_PER_SECOND_SQUARED},
    {'name':"tot",         'range':[164,179],                'factor':2**4,   'unit':utility.SECOND},
    {'name':"WNot",        'range':[180,189],                                 'unit':utility.WEEK},
    {'name':"GNSSID",      'range':[190,192]},
    {'name':"Spare",       'range':[193,255]},

    {'name':"PRN ID",      'range':[256,261]},
    {'name':"CRC",         'range':[262,285]},
    {'name':"TAIL",        'range':[286,291]}]

NavICNAVDictMessage11 = [
    {'name':"TLM",         'range':[0,7]},
    {'name':"TOWC",        'range':[8,24]},
    {'name':"ALERT",       'range':[25,25]},
    {'name':"AUTONAV",     'range':[26,26]},
    {'name':"SUBFRAME ID", 'range':[27,28]},
    {'name':"SPARE",       'range':[29,29]},
    {'name':"MESSAGE ID",  'range':[30,35]},

    {'name':"tEOP",        'range':[36,51],                  'factor':2**4,   'unit':utility.SECOND},
    {'name':"PM_X",        'range':[52,72],   'signed':True, 'factor':2**-20, 'unit':utility.ARC_SECOND},
    {'name':"PM_Xdot",     'range':[73,87],   'signed':True, 'factor':2**-21, 'unit':utility.ARC_SECOND_PER_DAY},
    {'name':"PM_Y",        'range':[88,108],  'signed':True, 'factor':2**-20, 'unit':utility.ARC_SECOND},
    {'name':"PM_Ydot",     'range':[109,123], 'signed':True, 'factor':2**-21, 'unit':utility.ARC_SECOND_PER_DAY},
    {'name':"deltaUT1",    'range':[124,154], 'signed':True, 'factor':2**-24, 'unit':utility.DAY},
    {'name':"deltaUT1dot", 'range':[155,173], 'signed':True, 'factor':2**-25, 'unit':utility.SECOND_PER_DAY},
    {'name':"alpha1",      'range':[174,181], 'signed':True, 'factor':2**-30, 'unit':utility.SECOND},
    {'name':"alpha2",      'range':[182,189], 'signed':True, 'factor':2**-27, 'unit':utility.SECOND_PER_SEMICIRCLE},
    {'name':"alpha3",      'range':[190,197], 'signed':True, 'factor':2**-24, 'unit':utility.SECOND_PER_SEMICIRCLE_SQUARED},
    {'name':"alpha4",      'range':[198,205], 'signed':True, 'factor':2**-24, 'unit':utility.SECOND_PER_SEMICIRCLE_CUBE},
    {'name':"beta1",       'range':[206,213], 'signed':True, 'factor':2**11,  'unit':utility.SECOND},
    {'name':"beta2",       'range':[214,221], 'signed':True, 'factor':2**14,  'unit':utility.SECOND_PER_SEMICIRCLE},
    {'name':"beta3",       'range':[222,229], 'signed':True, 'factor':2**16,  'unit':utility.SECOND_PER_SEMICIRCLE_SQUARED},
    {'name':"beta4",       'range':[230,237], 'signed':True, 'factor':2**16,  'unit':utility.SECOND_PER_SEMICIRCLE_CUBE},
    {'name':"Spare",       'range':[238,255]},

    {'name':"PRN ID",      'range':[256,261]},
    {'name':"CRC",         'range':[262,285]},
    {'name':"TAIL",        'range':[286,291]}]

NavICNAVDictMessage14 = [
    {'name':"TLM",         'range':[0,7]},
    {'name':"TOWC",        'range':[8,24]},
    {'name':"ALERT",       'range':[25,25]},
    {'name':"AUTONAV",     'range':[26,26]},
    {'name':"SUBFRAME ID", 'range':[27,28]},
    {'name':"SPARE",       'range':[29,29]},
    {'name':"MESSAGE ID",  'range':[30,35]},

    {'name':"Reserved 1",  'range':[36,36]},
    {'name':"PRN ID DC",   'range':[37,42]},
    {'name':"deltaaf0",    'range':[43,55],   'signed':True, 'factor':2**-35, 'unit':utility.SECOND},
    {'name':"deltaaf1",    'range':[56,63],   'signed':True, 'factor':2**-51, 'unit':utility.SECOND_PER_SECOND},
    {'name':"UDRA",        'range':[64,68],   'signed':True},
    {'name':"deltaalpha",  'range':[69,82],   'signed':True, 'factor':2**-34},
    {'name':"deltabeta",   'range':[83,96],   'signed':True, 'factor':2**-34},
    {'name':"deltagamma",  'range':[97,113],  'signed':True, 'factor':2**-32, 'unit':utility.SEMICIRCLE},
    {'name':"deltai",      'range':[114,123], 'signed':True, 'factor':2**-32, 'unit':utility.SEMICIRCLE},
    {'name':"deltaomega",  'range':[124,135], 'signed':True, 'factor':2**-32, 'unit':utility.SEMICIRCLE},
    {'name':"deltaA",      'range':[136,147], 'signed':True, 'factor':2**-9,  'unit':utility.METER},
    {'name':"UDRAdot",     'range':[148,152], 'signed':True},
    {'name':"IODEC",       'range':[153,160]},
    {'name':"Reserved 2",  'range':[161,170]},
    {'name':"tod",         'range':[171,186],                'factor':16,     'unit':utility.SECOND},
    {'name':"Spare",       'range':[187,255]},

    {'name':"PRN ID",      'range':[256,261]},
    {'name':"CRC",         'range':[262,285]},
    {'name':"TAIL",        'range':[286,291]}]

NavICNAVDictMessage18 = [
    {'name':"TLM",         'range':[0,7]},
    {'name':"TOWC",        'range':[8,24]},
    {'name':"ALERT",       'range':[25,25]},
    {'name':"AUTONAV",     'range':[26,26]},
    {'name':"SUBFRAME ID", 'range':[27,28]},
    {'name':"SPARE",       'range':[29,29]},
    {'name':"MESSAGE ID",  'range':[30,35]},

    {'name':"Text ID",      'range':[36,39]},
    {'name':"Block count",  'range':[40,47]},
    {'name':"Block Id",     'range':[48,55]},
    {'name':"Text data",    'range':[56,255]},

    {'name':"PRN ID",      'range':[256,261]},
    {'name':"CRC",         'range':[262,285]},
    {'name':"TAIL",        'range':[286,291]}]

NavICNAVDictMessage26= [
    {'name':"TLM",         'range':[0,7]},
    {'name':"TOWC",        'range':[8,24]},
    {'name':"ALERT",       'range':[25,25]},
    {'name':"AUTONAV",     'range':[26,26]},
    {'name':"SUBFRAME ID", 'range':[27,28]},
    {'name':"SPARE",       'range':[29,29]},
    {'name':"MESSAGE ID",  'range':[30,35]},

    {'name':"A0utc",       'range':[36,51],   'signed':True, 'factor':2**-35, 'unit':utility.SECOND},
    {'name':"A1utc",       'range':[52,64],   'signed':True, 'factor':2**-51, 'unit':utility.SECOND_PER_SECOND},
    {'name':"A2utc",       'range':[65,71],   'signed':True, 'factor':2**-68, 'unit':utility.SECOND_PER_SECOND_SQUARED},
    {'name':"deltatLS",    'range':[72,79],   'signed':True,                  'unit':utility.SECOND},
    {'name':"toutc",       'range':[80,95],                   'factor':2**4,  'unit':utility.SECOND},
    {'name':"WNoutc",      'range':[96,105],                                  'unit':utility.WEEK},
    {'name':"WNLSF",       'range':[106,115],                                 'unit':utility.WEEK},
    {'name':"DN",          'range':[116,119],                                 'unit':utility.DAY},
    {'name':"deltatLSF",   'range':[120,127], 'signed':True,                  'unit':utility.SECOND},
    {'name':"A0",          'range':[128,143], 'signed':True, 'factor':2**-35, 'unit':utility.SECOND},
    {'name':"A1",          'range':[144,156], 'signed':True, 'factor':2**-51, 'unit':utility.SECOND_PER_SECOND},
    {'name':"A2",          'range':[157,163], 'signed':True, 'factor':2**-68, 'unit':utility.SECOND_PER_SECOND_SQUARED},
    {'name':"tot",         'range':[164,179],                'factor':2**4,   'unit':utility.SECOND},
    {'name':"WNot",        'range':[180,189],                                 'unit':utility.WEEK},
    {'name':"GNSSID",      'range':[190,192]},
    {'name':"Spare",       'range':[193,255]},

    {'name':"PRN ID",      'range':[256,261]},
    {'name':"CRC",         'range':[262,285]},
    {'name':"TAIL",        'range':[286,291]}]

"""
    Structure for NavIC L1
"""

NavICL1DictPage0 = [
    {'name':"TOI",            'range':[0,8]},

    
    {'name':"WN",             'range':[9,21]},
    {'name':"ITOW",           'range':[22,29]},
    {'name':"alert",          'range':[30,30]},
   
    {'name':"l1SpsHealth",    'range':[31,31]},
    {'name':"iodec",          'range':[32,35],    'signed':True},
    {'name':"urai",           'range':[36,40],    'signed':True},
    {'name':"toec",           'range':[41,51],    'signed':True, 'factor':300},
    {'name':"deltaA",         'range':[52,77],    'signed':True, 'factor':2**-9},
    {'name':"aDot",           'range':[78,103],   'signed':True, 'factor':2**-21},
    {'name':"deltaN0",        'range':[104,122],  'signed':True, 'factor':2**-44},
    {'name':"deltaNDot",      'range':[123,145],  'signed':True, 'factor':2**-57},
    {'name':"m0",             'range':[146,178],  'signed':True, 'factor':2**-32},
    {'name':"e",              'range':[179,211],                 'factor':2**-34},
    {'name':"omega",          'range':[212,244],  'signed':True, 'factor':2**-32},
    {'name':"bigOmega0",      'range':[245,277],  'signed':True, 'factor':2**-32},
    {'name':"bigOmegaDot",    'range':[278,302],  'signed':True, 'factor':2**-44},
    {'name':"i0",             'range':[303,335],  'signed':True, 'factor':2**-32},
    {'name':"iDot",           'range':[336,350],  'signed':True, 'factor':2**-44},
    {'name':"cis",            'range':[351,366],  'signed':True, 'factor':2**-30},
    {'name':"cic",            'range':[367,382],  'signed':True, 'factor':2**-30},
    {'name':"crs",            'range':[383,406],  'signed':True, 'factor':2**-8},
    {'name':"Crc",            'range':[407,430],  'signed':True, 'factor':2**-8},
    {'name':"cus",            'range':[431,451],  'signed':True, 'factor':2**-30},
    {'name':"cuc",            'range':[452,472],  'signed':True, 'factor':2**-30},
    {'name':"af0",            'range':[473,501],  'signed':True, 'factor':2**-35},
    {'name':"af1",            'range':[502,523],  'signed':True, 'factor':2**-50},
    {'name':"af2",            'range':[524,538],  'signed':True, 'factor':2**-66},
    {'name':"tgd",            'range':[539,550],  'signed':True, 'factor':2**-35},
    {'name':"iscL1POrS",      'range':[551,562],  'signed':True, 'factor':2**-35},
    {'name':"iscL1D",         'range':[563,574],  'signed':True, 'factor':2**-35},
    {'name':"rsf",            'range':[575,575]},
    {'name':"spare",          'range':[576,578]},
       
    {'name':"prnID",          'range':[580,584]},
    {'name':"crc",            'range':[585,608]},
    

    {'name':"msgID",          'range':[609, 614]},
    {'name':"invalidDataFlag",'range':[615, 615]},

    {'name':"data",           'range':[616,858]},

    {'name':"crc",            'range':[859,882]}
    ]

NavICL1DictPage5 = [
    {'name':"TOI",            'range':[0,8]},

    
    {'name':"WN",             'range':[9,21]},
    {'name':"ITOW",           'range':[22,29]},
    {'name':"alert",          'range':[30,30]},
   
    {'name':"l1SpsHealth",    'range':[31,31]},
    {'name':"iodec",          'range':[32,35],    'signed':True},
    {'name':"urai",           'range':[36,40],    'signed':True},
    {'name':"toec",           'range':[41,51],    'signed':True, 'factor':300},
    {'name':"deltaA",         'range':[52,77],    'signed':True, 'factor':2**-9},
    {'name':"aDot",           'range':[78,103],   'signed':True, 'factor':2**-21},
    {'name':"deltaN0",        'range':[104,122],  'signed':True, 'factor':2**-44},
    {'name':"deltaNDot",      'range':[123,145],  'signed':True, 'factor':2**-57},
    {'name':"m0",             'range':[146,178],  'signed':True, 'factor':2**-32},
    {'name':"e",              'range':[179,211],                 'factor':2**-34},
    {'name':"omega",          'range':[212,244],  'signed':True, 'factor':2**-32},
    {'name':"bigOmega0",      'range':[245,277],  'signed':True, 'factor':2**-32},
    {'name':"bigOmegaDot",    'range':[278,302],  'signed':True, 'factor':2**-44},
    {'name':"i0",             'range':[303,335],  'signed':True, 'factor':2**-32},
    {'name':"iDot",           'range':[336,350],  'signed':True, 'factor':2**-44},
    {'name':"cis",            'range':[351,366],  'signed':True, 'factor':2**-30},
    {'name':"cic",            'range':[367,382],  'signed':True, 'factor':2**-30},
    {'name':"crs",            'range':[383,406],  'signed':True, 'factor':2**-8},
    {'name':"Crc",            'range':[407,430],  'signed':True, 'factor':2**-8},
    {'name':"cus",            'range':[431,451],  'signed':True, 'factor':2**-30},
    {'name':"cuc",            'range':[452,472],  'signed':True, 'factor':2**-30},
    {'name':"af0",            'range':[473,501],  'signed':True, 'factor':2**-35},
    {'name':"af1",            'range':[502,523],  'signed':True, 'factor':2**-50},
    {'name':"af2",            'range':[524,538],  'signed':True, 'factor':2**-66},
    {'name':"tgd",            'range':[539,550],  'signed':True, 'factor':2**-35},
    {'name':"iscL1POrS",      'range':[551,562],  'signed':True, 'factor':2**-35},
    {'name':"iscL1D",         'range':[563,574],  'signed':True, 'factor':2**-35},
    {'name':"rsf",            'range':[575,575]},
    {'name':"spare",          'range':[576,578]},
       
    {'name':"prnID",          'range':[580,584]},
    {'name':"crc",            'range':[585,608]},


    {'name':"msgID",          'range':[609, 614]},
    {'name':"invalidDataFlag",'range':[615, 615]},

    {'name':"regionsMasked",  'range':[616,625]},
    {'name':"regionID",       'range':[626,629]},
    {'name':"givei1",         'range':[630,633]},
    {'name':"givd1",          'range':[634,642],   'factor':0.125},
    {'name':"givei2",         'range':[643,646]},
    {'name':"givd2",          'range':[647,655],   'factor':0.125},
    {'name':"givei3",         'range':[656,659]},
    {'name':"givd3",          'range':[660,668],   'factor':0.125},
    {'name':"givei4",         'range':[669,672]},
    {'name':"givd4",          'range':[673,681],   'factor':0.125},
    {'name':"givei5",         'range':[682,685]},
    {'name':"givd5",          'range':[686,694],   'factor':0.125},
    {'name':"givei6",         'range':[695,698]},
    {'name':"givd6",          'range':[699,707],   'factor':0.125},
    {'name':"givei7",         'range':[708,711]},
    {'name':"givd7",          'range':[712,720], 'factor':0.125},
    {'name':"givei8",         'range':[721,724]},
    {'name':"givd8",          'range':[725,733], 'factor':0.125},
    {'name':"givei9",         'range':[734,737]},
    {'name':"givd9",          'range':[738,746], 'factor':0.125},
    {'name':"givei10",        'range':[747,750]},
    {'name':"givd10",         'range':[751,759], 'factor':0.125},
    {'name':"givei11",        'range':[760,763]},
    {'name':"givd11",         'range':[764,772], 'factor':0.125},
    {'name':"givei12",        'range':[773,776]},
    {'name':"givd12",         'range':[777,785], 'factor':0.125},
    {'name':"givei13",        'range':[786,789]},
    {'name':"givd13",         'range':[790,798], 'factor':0.125},
    {'name':"givei14",        'range':[799,802]},
    {'name':"givd14",         'range':[803,811], 'factor':0.125},
    {'name':"givei15",        'range':[812,815]},
    {'name':"givd15",         'range':[816,824], 'factor':0.125},
    {'name':"iodi",           'range':[825,827]},
    {'name':"spare",          'range':[828,858]},

    {'name':"crc",            'range':[859,882]}
]

NavICL1DictPage6 = [
    {'name':"TOI",            'range':[0,8]},

    
    {'name':"WN",             'range':[9,21]},
    {'name':"ITOW",           'range':[22,29]},
    {'name':"alert",          'range':[30,30]},
   
    {'name':"l1SpsHealth",    'range':[31,31]},
    {'name':"iodec",          'range':[32,35],    'signed':True},
    {'name':"urai",           'range':[36,40],    'signed':True},
    {'name':"toec",           'range':[41,51],    'signed':True, 'factor':300},
    {'name':"deltaA",         'range':[52,77],    'signed':True, 'factor':2**-9},
    {'name':"aDot",           'range':[78,103],   'signed':True, 'factor':2**-21},
    {'name':"deltaN0",        'range':[104,122],  'signed':True, 'factor':2**-44},
    {'name':"deltaNDot",      'range':[123,145],  'signed':True, 'factor':2**-57},
    {'name':"m0",             'range':[146,178],  'signed':True, 'factor':2**-32},
    {'name':"e",              'range':[179,211],                 'factor':2**-34},
    {'name':"omega",          'range':[212,244],  'signed':True, 'factor':2**-32},
    {'name':"bigOmega0",      'range':[245,277],  'signed':True, 'factor':2**-32},
    {'name':"bigOmegaDot",    'range':[278,302],  'signed':True, 'factor':2**-44},
    {'name':"i0",             'range':[303,335],  'signed':True, 'factor':2**-32},
    {'name':"iDot",           'range':[336,350],  'signed':True, 'factor':2**-44},
    {'name':"cis",            'range':[351,366],  'signed':True, 'factor':2**-30},
    {'name':"cic",            'range':[367,382],  'signed':True, 'factor':2**-30},
    {'name':"crs",            'range':[383,406],  'signed':True, 'factor':2**-8},
    {'name':"Crc",            'range':[407,430],  'signed':True, 'factor':2**-8},
    {'name':"cus",            'range':[431,451],  'signed':True, 'factor':2**-30},
    {'name':"cuc",            'range':[452,472],  'signed':True, 'factor':2**-30},
    {'name':"af0",            'range':[473,501],  'signed':True, 'factor':2**-35},
    {'name':"af1",            'range':[502,523],  'signed':True, 'factor':2**-50},
    {'name':"af2",            'range':[524,538],  'signed':True, 'factor':2**-66},
    {'name':"tgd",            'range':[539,550],  'signed':True, 'factor':2**-35},
    {'name':"iscL1POrS",      'range':[551,562],  'signed':True, 'factor':2**-35},
    {'name':"iscL1D",         'range':[563,574],  'signed':True, 'factor':2**-35},
    {'name':"rsf",            'range':[575,575]},
    {'name':"spare",          'range':[576,578]},
       
    {'name':"prnID",          'range':[580,584]},
    {'name':"crc",            'range':[585,608]},


    {'name':"msgID",          'range':[609, 614]},
    {'name':"invalidDataFlag",'range':[615, 615]},

    {'name':"wna",            'range':[616, 628]},
    {'name':"e",              'range':[629, 648],                'factor':2**-21},
    {'name':"toa",            'range':[649, 664],                'factor':24},
    {'name':"i0",             'range':[665, 688], 'signed':True, 'factor':2**-23},
    {'name':"bigOmegaDot",    'range':[689, 707], 'signed':True, 'factor':2**-38},
    {'name':"sqrtA",          'range':[708, 731],                'factor':2**-11},
    {'name':"bigOmega0",      'range':[732, 755], 'signed':True, 'factor':2**-23},
    {'name':"omega",          'range':[756, 779], 'signed':True, 'factor':2**-23},
    {'name':"m0",             'range':[780, 803], 'signed':True, 'factor':2**-23},
    {'name':"af0",            'range':[804, 817], 'signed':True, 'factor':2**-20},
    {'name':"af1",            'range':[818, 828], 'signed':True, 'factor':2**-38},
    {'name':"prn",            'range':[829, 834]},
    {'name':"spare",          'range':[835, 858]},

    {'name':"crc",            'range':[859, 882]}
]

NavICL1DictPage8 = [
    {'name':"TOI",            'range':[0,8]},

    
    {'name':"WN",             'range':[9,21]},
    {'name':"ITOW",           'range':[22,29]},
    {'name':"alert",          'range':[30,30]},
   
    {'name':"l1SpsHealth",    'range':[31,31]},
    {'name':"iodec",          'range':[32,35],   'signed':True},
    {'name':"urai",           'range':[36,40],   'signed':True},
    {'name':"toec",           'range':[41,51],   'signed':True, 'factor':300},
    {'name':"deltaA",         'range':[52,77],   'signed':True, 'factor':2**-9},
    {'name':"aDot",           'range':[78,103],  'signed':True, 'factor':2**-21},
    {'name':"deltaN0",        'range':[104,122], 'signed':True, 'factor':2**-44},
    {'name':"deltaNDot",      'range':[123,145], 'signed':True, 'factor':2**-57},
    {'name':"m0",             'range':[146,178], 'signed':True, 'factor':2**-32},
    {'name':"e",              'range':[179,211],                'factor':2**-34},
    {'name':"omega",          'range':[212,244], 'signed':True, 'factor':2**-32},
    {'name':"bigOmega0",      'range':[245,277], 'signed':True, 'factor':2**-32},
    {'name':"bigOmegaDot",    'range':[278,302], 'signed':True, 'factor':2**-44},
    {'name':"i0",             'range':[303,335], 'signed':True, 'factor':2**-32},
    {'name':"iDot",           'range':[336,350], 'signed':True, 'factor':2**-44},
    {'name':"cis",            'range':[351,366], 'signed':True, 'factor':2**-30},
    {'name':"cic",            'range':[367,382], 'signed':True, 'factor':2**-30},
    {'name':"crs",            'range':[383,406], 'signed':True, 'factor':2**-8},
    {'name':"Crc",            'range':[407,430], 'signed':True, 'factor':2**-8},
    {'name':"cus",            'range':[431,451], 'signed':True, 'factor':2**-30},
    {'name':"cuc",            'range':[452,472], 'signed':True, 'factor':2**-30},
    {'name':"af0",            'range':[473,501], 'signed':True, 'factor':2**-35},
    {'name':"af1",            'range':[502,523], 'signed':True, 'factor':2**-50},
    {'name':"af2",            'range':[524,538], 'signed':True, 'factor':2**-66},
    {'name':"tgd",            'range':[539,550], 'signed':True, 'factor':2**-35},
    {'name':"iscL1POrS",      'range':[551,562], 'signed':True, 'factor':2**-35},
    {'name':"iscL1D",         'range':[563,574], 'signed':True, 'factor':2**-35},
    {'name':"rsf",            'range':[575,575]},
    {'name':"spare",          'range':[576,578]},
       
    {'name':"prnID",          'range':[580,584]},
    {'name':"crc",            'range':[585,608]},


    {'name':"msgID",          'range':[609,614]},
    {'name':"invalidDataFlag",'range':[615,615]},

    {'name':"modipMax1",      'range':[616,621], 'signed':True, 'factor':5},
    {'name':"modipMin1",      'range':[622,627], 'signed':True, 'factor':5},
    {'name':"mLonMax1",       'range':[628,634], 'signed':True, 'factor':5},
    {'name':"mLonMin1",       'range':[635,641], 'signed':True, 'factor':5},
    {'name':"a0_1",           'range':[642,652],                'factor':2**-2},
    {'name':"a1_1",           'range':[653,663], 'signed':True, 'factor':2**-8},
    {'name':"a2_1",           'range':[664,677], 'signed':True, 'factor':2**-15},
    {'name':"idf1",           'range':[678,678]},
    {'name':"modipMax2",      'range':[679,684], 'signed':True, 'factor':5},
    {'name':"modipMin2",      'range':[685,690], 'signed':True, 'factor':5},
    {'name':"mLonMax2",       'range':[691,697], 'signed':True, 'factor':5},
    {'name':"mLonMin2",       'range':[698,704], 'signed':True, 'factor':5},
    {'name':"a0_2",           'range':[705,715],                'factor':2**-2},
    {'name':"a1_2",           'range':[716,726], 'signed':True, 'factor':2**-8},
    {'name':"a2_2",           'range':[727,740], 'signed':True, 'factor':2**-15},
    {'name':"idf2",           'range':[741,741]},
    {'name':"modipMax3",      'range':[742,747], 'signed':True, 'factor':5},
    {'name':"modipMin3",      'range':[748,753], 'signed':True, 'factor':5},
    {'name':"mLonMax3",       'range':[754,760], 'signed':True, 'factor':5},
    {'name':"mLonMin3",       'range':[761,767], 'signed':True, 'factor':5},
    {'name':"a0_3",           'range':[768,778],                'factor':2**-2},
    {'name':"a1_3",           'range':[779,789], 'signed':True, 'factor':2**-8},
    {'name':"a2_3",           'range':[790,803], 'signed':True, 'factor':2**-15},
    {'name':"idf3",           'range':[804,804]},
    {'name':"iodn",           'range':[805,806]},
    {'name':"spare",          'range':[807,858]},

    {'name':"crc",            'range':[859,882]}
]

NavICL1DictPage10 = [
    {'name':"TOI",            'range':[0,8]},

    
    {'name':"WN",             'range':[9,21]},
    {'name':"ITOW",           'range':[22,29]},
    {'name':"alert",          'range':[30,30]},
   
    {'name':"l1SpsHealth",    'range':[31,31]},
    {'name':"iodec",          'range':[32,35],    'signed':True},
    {'name':"urai",           'range':[36,40],    'signed':True},
    {'name':"toec",           'range':[41,51],    'signed':True, 'factor':300},
    {'name':"deltaA",         'range':[52,77],    'signed':True, 'factor':2**-9},
    {'name':"aDot",           'range':[78,103],   'signed':True, 'factor':2**-21},
    {'name':"deltaN0",        'range':[104,122],  'signed':True, 'factor':2**-44},
    {'name':"deltaNDot",      'range':[123,145],  'signed':True, 'factor':2**-57},
    {'name':"m0",             'range':[146,178],  'signed':True, 'factor':2**-32},
    {'name':"e",              'range':[179,211],                 'factor':2**-34},
    {'name':"omega",          'range':[212,244],  'signed':True, 'factor':2**-32},
    {'name':"bigOmega0",      'range':[245,277],  'signed':True, 'factor':2**-32},
    {'name':"bigOmegaDot",    'range':[278,302],  'signed':True, 'factor':2**-44},
    {'name':"i0",             'range':[303,335],  'signed':True, 'factor':2**-32},
    {'name':"iDot",           'range':[336,350],  'signed':True, 'factor':2**-44},
    {'name':"cis",            'range':[351,366],  'signed':True, 'factor':2**-30},
    {'name':"cic",            'range':[367,382],  'signed':True, 'factor':2**-30},
    {'name':"crs",            'range':[383,406],  'signed':True, 'factor':2**-8},
    {'name':"Crc",            'range':[407,430],  'signed':True, 'factor':2**-8},
    {'name':"cus",            'range':[431,451],  'signed':True, 'factor':2**-30},
    {'name':"cuc",            'range':[452,472],  'signed':True, 'factor':2**-30},
    {'name':"af0",            'range':[473,501],  'signed':True, 'factor':2**-35},
    {'name':"af1",            'range':[502,523],  'signed':True, 'factor':2**-50},
    {'name':"af2",            'range':[524,538],  'signed':True, 'factor':2**-66},
    {'name':"tgd",            'range':[539,550],  'signed':True, 'factor':2**-35},
    {'name':"iscL1POrS",      'range':[551,562],  'signed':True, 'factor':2**-35},
    {'name':"iscL1D",         'range':[563,574],  'signed':True, 'factor':2**-35},
    {'name':"rsf",            'range':[575,575]},
    {'name':"spare",          'range':[576,578]},
       
    {'name':"prnID",          'range':[580,584]},
    {'name':"crc",            'range':[585,608]},


    {"name":"msgID",           'range':[609,614]},
    {"name":"invalidDataFlag", 'range':[615,615]},

    {"name":"teop",            'range':[616,631],                'factor':2**-2},
    {"name":"PM_X",            'range':[632,652], 'signed':True, 'factor':2**-8},
    {"name":"PM_XDot",         'range':[653,667], 'signed':True, 'factor':2**-8},
    {"name":"PM_Y",            'range':[668,688], 'signed':True, 'factor':2**-8},
    {"name":"PM_YDot",         'range':[689,703], 'signed':True, 'factor':2**-8},
    {"name":"deltaUT1",        'range':[704,734], 'signed':True, 'factor':2**-8},
    {"name":"deltaUTDot1",     'range':[735,753], 'signed':True, 'factor':2**-8},
    {"name":"alpha0",          'range':[754,761], 'signed':True, 'factor':2**-8},
    {"name":"alpha1",          'range':[762,769], 'signed':True, 'factor':2**-8},
    {"name":"alpha2",          'range':[770,779], 'signed':True, 'factor':2**-8},
    {"name":"alpha3",          'range':[780,791], 'signed':True, 'factor':2**-8},
    {"name":"beta0",           'range':[792,799], 'signed':True, 'factor':2**-8},
    {"name":"beta1",           'range':[800,807], 'signed':True, 'factor':2**-8},
    {"name":"beta2",           'range':[808,818], 'signed':True, 'factor':2**-8},
    {"name":"beta3",           'range':[819,832], 'signed':True, 'factor':2**-8},
    {"name":"lambdaKMax",      'range':[833,838], 'factor':2**-2},
    {"name":"lambdaKMin",      'range':[839,844], 'factor':2**-2},
    {"name":"phiKMax",         'range':[845,849], 'signed':True, 'factor':2**-8},
    {"name":"phiKMin",         'range':[850,854], 'signed':True, 'factor':2**-8},
    {"name":"iodk",            'range':[855,856]},
    {"name":"spare",           'range':[857,858]},

    {"name":"crc",             'range':[859,882]}
]

NavICL1DictPage17 = [
    {'name':"TOI",            'range':[0,8]},

    
    {'name':"WN",             'range':[9,21]},
    {'name':"ITOW",           'range':[22,29]},
    {'name':"alert",          'range':[30,30]},
   
    {'name':"l1SpsHealth",    'range':[31,31]},
    {'name':"iodec",          'range':[32,35],   'signed':True},
    {'name':"urai",           'range':[36,40],   'signed':True},
    {'name':"toec",           'range':[41,51],   'signed':True, 'factor':300},
    {'name':"deltaA",         'range':[52,77],   'signed':True, 'factor':2**-9},
    {'name':"aDot",           'range':[78,103],  'signed':True, 'factor':2**-21},
    {'name':"deltaN0",        'range':[104,122], 'signed':True, 'factor':2**-44},
    {'name':"deltaNDot",      'range':[123,145], 'signed':True, 'factor':2**-57},
    {'name':"m0",             'range':[146,178], 'signed':True, 'factor':2**-32},
    {'name':"e",              'range':[179,211],                'factor':2**-34},
    {'name':"omega",          'range':[212,244], 'signed':True, 'factor':2**-32},
    {'name':"bigOmega0",      'range':[245,277], 'signed':True, 'factor':2**-32},
    {'name':"bigOmegaDot",    'range':[278,302], 'signed':True, 'factor':2**-44},
    {'name':"i0",             'range':[303,335], 'signed':True, 'factor':2**-32},
    {'name':"iDot",           'range':[336,350], 'signed':True, 'factor':2**-44},
    {'name':"cis",            'range':[351,366], 'signed':True, 'factor':2**-30},
    {'name':"cic",            'range':[367,382], 'signed':True, 'factor':2**-30},
    {'name':"crs",            'range':[383,406], 'signed':True, 'factor':2**-8},
    {'name':"Crc",            'range':[407,430], 'signed':True, 'factor':2**-8},
    {'name':"cus",            'range':[431,451], 'signed':True, 'factor':2**-30},
    {'name':"cuc",            'range':[452,472], 'signed':True, 'factor':2**-30},
    {'name':"af0",            'range':[473,501], 'signed':True, 'factor':2**-35},
    {'name':"af1",            'range':[502,523], 'signed':True, 'factor':2**-50},
    {'name':"af2",            'range':[524,538], 'signed':True, 'factor':2**-66},
    {'name':"tgd",            'range':[539,550], 'signed':True, 'factor':2**-35},
    {'name':"iscL1POrS",      'range':[551,562], 'signed':True, 'factor':2**-35},
    {'name':"iscL1D",         'range':[563,574], 'signed':True, 'factor':2**-35},
    {'name':"rsf",            'range':[575,575]},
    {'name':"spare",          'range':[576,578]},
       
    {'name':"prnID",          'range':[580,584]},
    {'name':"crc",            'range':[585,608]},


    {'name':"msgID",          'range':[609,614]},
    {'name':"invalidDataFlag",'range':[615,615]},

    {'name':"iodt",           'range':[616,618]},
    {'name':"tug",            'range':[619,626],                'factor':2**-2},
    {'name':"wnUg",           'range':[627,639]},
    {'name':"deltaTls",       'range':[640,647], 'signed':True},
    {'name':"wnLsf",          'range':[648,660]},
    {'name':"dn",             'range':[661,664]},
    {'name':"deltaTlsf",      'range':[665,672], 'signed':True},
    {'name':"a0utc",          'range':[673,688], 'signed':True, 'factor':2**-2},
    {'name':"a1utc",          'range':[689,701], 'signed':True, 'factor':2**-2},
    {'name':"a2utc",          'range':[702,708], 'signed':True, 'factor':2**-2},
    {'name':"validFlagUtc",   'range':[709,709]},
    {'name':"a0npli",         'range':[710,725], 'signed':True, 'factor':2**-2},
    {'name':"a1npli",         'range':[726,738], 'signed':True, 'factor':2**-2},
    {'name':"a2npli",         'range':[739,745], 'signed':True, 'factor':2**-2},
    {'name':"gnssID1",        'range':[746,748]},
    {'name':"validFlagID1",   'range':[749,750]},
    {'name':"a0gnssID1",      'range':[750,765], 'signed':True, 'factor':2**-2},
    {"name":"a1gnssID1",      'range':[766,778], 'signed':True, 'factor':2**-2},
    {"name":"gnssID2",        'range':[779,781]},
    {"name":"validFlagID2",   'range':[782,782]},
    {"name":"a0GnssID2",      'range':[783,798], 'signed':True, 'factor':2**-2},
    {"name":"a1GnssID2",      'range':[799,811], 'signed':True, 'factor':2**-2},
    {"name":"gnssID3",        'range':[812,814]},
    {"name":"validFlagID3",   'range':[815,815]},
    {"name":"a0GnssID3",      'range':[816,831], 'signed':True, 'factor':2**-2},
    {"name":"a1GnssID3",      'range':[832,844], 'signed':True, 'factor':2**-2},
    {"name":"spare",          'range':[845,858]},

    {"name":"crc",            'range':[859,882]}
]

"""
    Main functions for decoding a NavIC downlink navigation message.
"""

def getDictNavICNAVNavigationMessage(message):
    dictToUse = {}
    binaryMessage = utility.convertToBinaryNavigationMessage(message, 320)
    subframe = int(binaryMessage[27:29], 2)

    if subframe == 0:
        dictToUse = NavICNAVDictSubframe1
    elif subframe == 1:
        dictToUse = NavICNAVDictSubframe2
    elif subframe == 2 or subframe == 3:
        messageType = int(binaryMessage[30:36], 2)
        
        if messageType == 5:
            dictToUse = NavICNAVDictMessage5
        elif messageType == 7:
            dictToUse = NavICNAVDictMessage7
        elif messageType == 9:
            dictToUse = NavICNAVDictMessage9
        elif messageType == 11:
            dictToUse = NavICNAVDictMessage11
        elif messageType == 14:
            dictToUse = NavICNAVDictMessage14
        elif messageType == 18:
            dictToUse = NavICNAVDictMessage18                                    
        elif messageType == 26:
            dictToUse = NavICNAVDictMessage26
        else:
            dictToUse = NavICNAVDictMessage0
    else:
        return dictToUse

    return utility.fillDict(binaryMessage, dictToUse)

def getDictNavICL1NavigationMessage(message):
    dictToUse = {}
    binaryMessage = utility.convertToBinaryNavigationMessage(message, 896)
    messageType = int(binaryMessage[609:615], 2)
   
    if messageType == 5:
        dictToUse = NavICL1DictPage5
    elif messageType == 6:
        dictToUse = NavICL1DictPage6
    elif messageType == 8:
        dictToUse = NavICL1DictPage8
    elif messageType == 10:
        dictToUse = NavICL1DictPage10
    elif messageType == 17:
        dictToUse = NavICL1DictPage17
    else:
        dictToUse = NavICL1DictPage0

    return utility.fillDict(binaryMessage, dictToUse)
