#!/usr/bin/env python3
"""
    Messages supported :
        GLONASS G1/G2
"""

import utility

"""
    Informations for decoding GLONASS navigation messages.
"""
GLONASSNavDictType1 = [
    {'name':"IdleChip", 'range':[0,0]},
    {'name':"m",        'range':[1,4]},
    {'name':"Rsv",      'range':[5,6]},
    {'name':"P1",       'range':[7,8]},
    {'name':"tk-h",     'range':[9,13],                                  'unit':utility.HOUR},
    {'name':"tk-m",     'range':[14,19],                                 'unit':utility.MINUTE},
    {'name':"tk-s",     'range':[20,20],                'factor':30,     'unit':utility.SECOND},
    {'name':"xn'(tb)",  'range':[21,44], 'signed':True, 'factor':2**-20, 'unit':utility.KILOMETER_PER_SECOND},
    {'name':"xn''(tb)", 'range':[45,49], 'signed':True, 'factor':2**-30, 'unit':utility.KILOMETER_PER_SECOND_SQUARED},
    {'name':"xn(tb)",   'range':[50,76], 'signed':True, 'factor':2**-11, 'unit':utility.KILOMETER},
    {'name':"KX",       'range':[77,84]}]

GLONASSNavDictType2 = [
    {'name':"IdleChip", 'range':[0,0]},
    {'name':"m",        'range':[1,4]},
    {'name':"Bn",       'range':[5,7]},
    {'name':"P2",       'range':[8,8]},
    {'name':"tb",       'range':[9,15],                 'factor':15,     'unit':utility.MINUTE},
    {'name':"Rsv",      'range':[16,20]},
    {'name':"yn'(tb)",  'range':[21,44], 'signed':True, 'factor':2**-20, 'unit':utility.KILOMETER_PER_SECOND},
    {'name':"yn''(tb)", 'range':[45,49], 'signed':True, 'factor':2**-30, 'unit':utility.KILOMETER_PER_SECOND_SQUARED},
    {'name':"yn(tb)",   'range':[50,76], 'signed':True, 'factor':2**-11, 'unit':utility.KILOMETER},
    {'name':"KX",       'range':[77,84]}]

GLONASSNavDictType3 = [
    {'name':"IdleChip",    'range':[0,0]},
    {'name':"m",           'range':[1,4]},
    {'name':"P3",          'range':[5,5]},
    {'name':"Gamma-n(tb)", 'range':[6,16],  'signed':True, 'factor':2**-40},
    {'name':"Rsv",         'range':[17,17]},
    {'name':"P",           'range':[18,19]},
    {'name':"ln",          'range':[20,20]},
    {'name':"zn'(tb)",     'range':[21,44], 'signed':True, 'factor':2**-20, 'unit':utility.KILOMETER_PER_SECOND},
    {'name':"zn''(tb)",    'range':[45,49], 'signed':True, 'factor':2**-30, 'unit':utility.KILOMETER_PER_SECOND_SQUARED},
    {'name':"zn(tb)",      'range':[50,76], 'signed':True, 'factor':2**-11, 'unit':utility.KILOMETER},
    {'name':"KX",          'range':[77,84]}]

GLONASSNavDictType4 = [
    {'name':"IdleChip",   'range':[0,0]},
    {'name':"m",          'range':[1,4]},
    {'name':"Tau-n(tb)",  'range':[5,26],  'signed':True, 'factor':2**-30, 'unit':utility.SECOND},
    {'name':"DeltaTau-n", 'range':[27,31],                'factor':2**-30, 'unit':utility.SECOND},
    {'name':"En",         'range':[32,36],                                 'unit':utility.DAY},
    {'name':"Rsv2",       'range':[37,50]},
    {'name':"P4",         'range':[51,51]},
    {'name':"FT",         'range':[52,55]},
    {'name':"Rsv3",       'range':[56,58]},
    {'name':"NT",         'range':[59,69],                                 'unit':utility.DAY},
    {'name':"n",          'range':[70,74]},
    {'name':"M",          'range':[75,76]},
    {'name':"KX",         'range':[77,84]}]

GLONASSNavDictType5 = [
    {'name':"IdleChip", 'range':[0,0]},
    {'name':"m",        'range':[1,4]},
    {'name':"NA",       'range':[5,15],                                  'unit':utility.DAY},
    {'name':"Tau-c",    'range':[16,47], 'signed':True, 'factor':2**-31, 'unit':utility.SECOND},
    {'name':"Rsv",      'range':[48,48]},
    {'name':"N4",       'range':[49,53],                                 'unit':utility.FOUR_YEAR_INTERVAL},
    {'name':"TauGPS",   'range':[54,75], 'signed':True, 'factor':2**-30, 'unit':utility.DAY},
    {'name':"ln",       'range':[76,76]},
    {'name':"KX",       'range':[77,84]}]

GLONASSNavDictAlmanacP1 = [
    {'name':"IdleChip",  'range':[0,0]},
    {'name':"m",         'range':[1,4]},
    {'name':"Cn",        'range':[5,5]},
    {'name':"Mna",       'range':[6,7]},
    {'name':"nA",        'range':[8,12]},
    {'name':"TauAn",     'range':[13,22],                'factor':2**-18, 'unit':utility.SECOND},
    {'name':"LambdaAn",  'range':[23,43], 'signed':True, 'factor':2**-20, 'unit':utility.SEMICIRCLE},
    {'name':"Delta-iAn", 'range':[44,61], 'signed':True, 'factor':2**-20, 'unit':utility.SEMICIRCLE},
    {'name':"eAn",       'range':[62,76],                'factor':2**-20},
    {'name':"KX",        'range':[77,84]}]

GLONASSNavDictAlmanacP2 = [
    {'name':"IdleChip",   'range':[0,0]},
    {'name':"m",          'range':[1,4]},
    {'name':"OmegaAn",    'range':[5,20],  'signed':True, 'factor':2**-15, 'unit':utility.SEMICIRCLE},
    {'name':"tALambda-n", 'range':[21,41],                'factor':2**-5,  'unit':utility.SEMICIRCLE},
    {'name':"DeltaTAn",   'range':[42,63], 'signed':True, 'factor':2**-9,  'unit':utility.SECOND_PER_ORBITAL},
    {'name':"DeltaT'An",  'range':[64,70], 'signed':True, 'factor':2**-14, 'unit':utility.SECOND_PER_ORBITAL_SQUARED},
    {'name':"HAn",        'range':[71,75]},
    {'name':"ln",         'range':[76,76]},
    {'name':"KX",         'range':[77,84]}]

GLONASSNavDictF5String14 = [
    {'name':"IdleChip", 'range':[0,0]},
    {'name':"m",        'range':[1,4]},
    {'name':"B1",       'range':[5,15],  'signed':True, 'factor':2**-10, 'unit':utility.SECOND},
    {'name':"B2",       'range':[16,25], 'signed':True, 'factor':2**-16, 'unit':utility.SECOND_PER_MSD},
    {'name':"KP",       'range':[26,27]},
    {'name':"Rsv",      'range':[28,76]},
    {'name':"KX",       'range':[77,84]}]

GLONASSNavDictF5String15 = [
    {'name':"IdleChip", 'range':[0,0]},
    {'name':"m",        'range':[1,4]},
    {'name':"Rsv",      'range':[5,75]},
    {'name':"ln",       'range':[76,76]},
    {'name':"KX",       'range':[77,84]}]

GLONASSNavDictAll = {1:GLONASSNavDictType1, 2:GLONASSNavDictType2, 3:GLONASSNavDictType3, 4:GLONASSNavDictType4, 5:GLONASSNavDictType5}

"""
    Main functions for decoding a GLONASS downlink navigation message.
"""
def getDictGLONASSNavigationMessage(message, frameId):
    binaryMessage = utility.convertToBinaryNavigationMessage(message, 96)
    stringID = int(binaryMessage[1:5], 2)
    dictToUse = {}
    if stringID in GLONASSNavDictAll:
        dictToUse = GLONASSNavDictAll[stringID]
    elif stringID == 14 and frameId == 5:
        dictToUse = GLONASSNavDictF5String14
    elif stringID == 15 and frameId == 5:
        dictToUse = GLONASSNavDictF5String15
    elif stringID in [6, 8, 10, 12, 14]:
        dictToUse = GLONASSNavDictAlmanacP1
    elif stringID in [7, 9, 11, 13, 15]:
        dictToUse = GLONASSNavDictAlmanacP2
    else:
        return dictToUse

    return utility.fillDict(binaryMessage, dictToUse)
