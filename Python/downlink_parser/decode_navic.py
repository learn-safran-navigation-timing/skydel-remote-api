#!/usr/bin/python
"""
    Messages supported :
        NavIC L5
"""

import utility

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
