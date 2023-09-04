#!/usr/bin/env python3
"""
    Messages supported :
        BeiDou B1
        BeiDou CNAV1
"""

import utility

"""
    Informations for decoding BeiDou D1 navigation messages.
"""
D1DictEphemeris1 = [
    {'name':"Pre",    'range':[0,10]},
    {'name':"Rev",    'range':[11,14]},
    {'name':"FraID",  'range':[15,17]},
    {'name':"SOW",    'range':[[18,25],[30,41]],                                     'unit':utility.SECOND},
    {'name':"P1",     'range':[26,29]},
    #        SOW              [30,41]
    {'name':"SatH1",  'range':[42,42]},
    {'name':"AODC",   'range':[43,47]},
    {'name':"URAI",   'range':[48,51]},
    {'name':"P2",     'range':[52,59]},
    {'name':"WN",     'range':[60,72],                                               'unit':utility.WEEK},
    {'name':"toc",    'range':[[73,81],[90,97]],                    'factor':2**3,   'unit':utility.SECOND},
    {'name':"P3",     'range':[82,89]},
    #        toc              [90,97]
    {'name':"TGD1",   'range':[98,107],              'signed':True, 'factor':10**-1, 'unit':utility.NANO_SECOND},
    {'name':"TGD2",   'range':[[108,111],[120,125]], 'signed':True, 'factor':10**-1, 'unit':utility.NANO_SECOND},
    {'name':"P4",     'range':[112,119]},
    #        TGD2             [120,125]
    {'name':"Alpha0", 'range':[126,133],             'signed':True, 'factor':2**-30, 'unit':utility.SECOND},
    {'name':"Alpha1", 'range':[134,141],             'signed':True, 'factor':2**-27, 'unit':utility.SECOND_PER_SEMICIRCLE},
    {'name':"P5",     'range':[142,149]},
    {'name':"Alpha2", 'range':[150,157],             'signed':True, 'factor':2**-24, 'unit':utility.SECOND_PER_SEMICIRCLE_SQUARED},
    {'name':"Alpha3", 'range':[158,165],             'signed':True, 'factor':2**-24, 'unit':utility.SECOND_PER_SEMICIRCLE_CUBE},
    {'name':"Beta0",  'range':[[166,171],[180,181]], 'signed':True, 'factor':2**11,  'unit':utility.SECOND},
    {'name':"P6",     'range':[172,179]},
    #        Beta0            [180,181]
    {'name':"Beta1",  'range':[182,189],             'signed':True, 'factor':2**14,  'unit':utility.SECOND_PER_SEMICIRCLE},
    {'name':"Beta2",  'range':[190,197],             'signed':True, 'factor':2**16,  'unit':utility.SECOND_PER_SEMICIRCLE_SQUARED},
    {'name':"Beta3",  'range':[[198,201],[210,213]], 'signed':True, 'factor':2**16,  'unit':utility.SECOND_PER_SEMICIRCLE_CUBE},
    {'name':"P7",     'range':[202,209]},
    #        Beta3            [210,213]
    {'name':"a2",     'range':[214,224],             'signed':True, 'factor':2**-66, 'unit':utility.SECOND_PER_SECOND_SQUARED},
    {'name':"a0",     'range':[[225,231],[240,256]], 'signed':True, 'factor':2**-33, 'unit':utility.SECOND},
    {'name':"P8",     'range':[232,239]},
    #        a0               [240,256]
    {'name':"a1",     'range':[[257,261],[270,286]], 'signed':True, 'factor':2**-50, 'unit':utility.SECOND_PER_SECOND},
    {'name':"P9",     'range':[262,269]},
    #        a1               [270,286]
    {'name':"AODE",   'range':[287,291]},
    {'name':"P10",    'range':[292,299]}]

D1DictEphemeris2 = [
    {'name':"Pre",    'range':[0,10]},
    {'name':"Rev",    'range':[11,14]},
    {'name':"FraID",  'range':[15,17]},
    {'name':"SOW",    'range':[[18,25],[30,41]],                                     'unit':utility.SECOND},
    {'name':"P1",     'range':[26,29]},
    #        SOW              [30,41]
    {'name':"DeltaN", 'range':[[42,51],[60,65]],     'signed':True, 'factor':2**-43, 'unit':utility.SEMICIRCLE_PER_SECOND},
    {'name':"P2",     'range':[52,59]},
    #        DeltaN           [60,65]
    {'name':"Cuc",    'range':[[66,81],[90,91]],     'signed':True, 'factor':2**-31, 'unit':utility.RADIAN},
    {'name':"P3",     'range':[82,89]},
    #        Cuc              [90,91]
    {'name':"M0",     'range':[[92,111],[120,131]],  'signed':True, 'factor':2**-31, 'unit':utility.SEMICIRCLE},
    {'name':"P4",     'range':[112,119]},
    #        M0               [120,131]
    {'name':"e",      'range':[[132,141],[150,171]],                'factor':2**-33},
    {'name':"P5",     'range':[142,149]},
    #        e                [150,171]
    {'name':"P6",     'range':[172,179]},
    {'name':"Cus",    'range':[180,197],             'signed':True, 'factor':2**-31, 'unit':utility.RADIAN},
    {'name':"Crc",    'range':[[198,201],[210,223]], 'signed':True, 'factor':2**-6,  'unit':utility.METER},
    {'name':"P7",     'range':[202,209]},
    #        Crc              [210,223]
    {'name':"Crs",    'range':[[224,231],[240,249]], 'signed':True, 'factor':2**-6,  'unit':utility.METER},
    {'name':"P8",     'range':[232,239]},
    #        Crs              [240,249]
    {'name':"SqrtA",  'range':[[250,261],[270,289]],                'factor':2**-19, 'unit':utility.METER_SQUARE_ROOT},
    {'name':"P9",     'range':[262,269]},
    #        SqrtA            [270,289]
    {'name':"toe",    'range':[290,291],                            'factor':2**18,   'unit':utility.SECOND},
    {'name':"P10",    'range':[292,299]}]

D1DictEphemeris3 = [
    {'name':"Pre",        'range':[0,10]},
    {'name':"Rev",        'range':[11,14]},
    {'name':"FraID",      'range':[15,17]},
    {'name':"SOW",        'range':[[18,25],[30,41]],                                     'unit':utility.SECOND},
    {'name':"P1",         'range':[26,29]},
    #        SOW                  [30,41]
    {'name':"toe",        'range':[[42,51],[60,64]],                    'factor':2**3,   'unit':utility.SECOND},
    {'name':"P2",         'range':[52,59]},
    #        toe                  [60,64]
    {'name':"i0",         'range':[[65,81],[90,104]],    'signed':True, 'factor':2**-31, 'unit':utility.SEMICIRCLE},
    {'name':"P3",         'range':[82,89]},
    #        i0                   [90,104]
    {'name':"Cic",        'range':[[105,111],[120,130]], 'signed':True, 'factor':2**-31, 'unit':utility.RADIAN},
    {'name':"P4",         'range':[112,119]},
    #        Cic                  [120,130]
    {'name':"OmegaDot",   'range':[[131,141],[150,162]], 'signed':True, 'factor':2**-43, 'unit':utility.SEMICIRCLE_PER_SECOND},
    {'name':"P5",         'range':[142,149]},
    #        OmegaDot             [150,162]
    {'name':"Cis",        'range':[[163,171],[180,188]], 'signed':True, 'factor':2**-31, 'unit':utility.RADIAN},
    {'name':"P6",         'range':[172,179]},
    #        Cis                  [180,188]
    {'name':"IDOT",       'range':[[189,201],[210,210]], 'signed':True, 'factor':2**-43, 'unit':utility.SEMICIRCLE_PER_SECOND},
    {'name':"P7",         'range':[202,209]},
    #        IDOT                 [210,210]
    {'name':"Omega0",     'range':[[211,231],[240,250]], 'signed':True, 'factor':2**-31, 'unit':utility.SEMICIRCLE},
    {'name':"P8",         'range':[232,239]},
    #        Omega0             [240,250]
    {'name':"Omega",      'range':[[251,261],[270,290]], 'signed':True, 'factor':2**-31, 'unit':utility.SEMICIRCLE},
    {'name':"P9",         'range':[262,269]},
    #        Omega                [270,290]
    {'name':"Rev2",       'range':[291,291]},
    {'name':"P10",        'range':[292,299]}]

D1DictAlmanac = [
    {'name':"Pre",      'range':[0,10]},
    {'name':"Rev",      'range':[11,14]},
    {'name':"FraID",    'range':[15,17]},
    {'name':"SOW",      'range':[[18,25],[30,41]],                                     'unit':utility.SECOND},
    {'name':"P1",       'range':[26,29]},
    #        SOW                [30,41]
    {'name':"Rev2",     'range':[42,42]},
    {'name':"Pnum",     'range':[43,49]},
    {'name':"SqrtA",    'range':[[50,51],[60,81]],                    'factor':2**-11, 'unit':utility.METER_SQUARE_ROOT},
    {'name':"P2",       'range':[52,59]},
    #        SqrtA              [60,81]
    {'name':"P3",       'range':[82,89]},
    {'name':"a1",       'range':[90,100],              'signed':True, 'factor':2**-38, 'unit':utility.SECOND_PER_SECOND},
    {'name':"a0",       'range':[101, 111],            'signed':True, 'factor':2**-20, 'unit':utility.SECOND},
    {'name':"P4",       'range':[112,119]},
    {'name':"Omega0",   'range':[[120,141],[150,151]], 'signed':True, 'factor':2**-23, 'unit':utility.SEMICIRCLE},
    {'name':"P5",       'range':[142,149]},
    #        Omega0             [150,151]
    {'name':"e",        'range':[152,168],                            'factor':2**-21},
    {'name':"Delta-i",  'range':[[169,171],[180,192]], 'signed':True, 'factor':2**-19, 'unit':utility.SEMICIRCLE},
    {'name':"P6",       'range':[172,179]},
    #        Deltai             [180,192]
    {'name':"toa",      'range':[193,200],                            'factor':2**12,  'unit':utility.SECOND},
    {'name':"OmegaDot", 'range':[[201,201],[210,225]], 'signed':True, 'factor':2**-38, 'unit':utility.SEMICIRCLE_PER_SECOND},
    {'name':"P7",       'range':[202,209]},
    #        OmegaDot           [210,225]
    {'name':"Omega",    'range':[[226,231],[240,257]], 'signed':True, 'factor':2**-23, 'unit':utility.SEMICIRCLE},
    {'name':"P8",       'range':[232,239]},
    #        Omega              [240,257]
    {'name':"M0",       'range':[[258,261],[270,289]], 'signed':True, 'factor':2**-23, 'unit':utility.SEMICIRCLE},
    {'name':"P9",       'range':[262,269]},
    #        M0                 [270,289]
    {'name':"AmEpID",   'range':[290,291]},
    {'name':"P10",      'range':[292,299]}]

D1DictHealthA = [
    {'name':"Pre",   'range':[0,10]},
    {'name':"Rev",   'range':[11,14]},
    {'name':"FraID", 'range':[15,17]},
    {'name':"SOW",   'range':[[18,25],[30,41]], 'unit':utility.SECOND},
    {'name':"P1",    'range':[26,29]},
    #        SOW             [30,41]
    {'name':"Rev2",  'range':[42,42]},
    {'name':"Pnum",  'range':[43,49]},
    {'name':"Hea1",  'range':[[50,51],[60,66]]},
    {'name':"P2",    'range':[52,59]},
    #        Hea1            [60,66]
    {'name':"Hea2",  'range':[67,75]},
    {'name':"Hea3",  'range':[[76,81],[90,92]]},
    {'name':"P3",    'range':[82,89]},
    #        Hea3            [90,92]
    {'name':"Hea4",  'range':[93,101]},
    {'name':"Hea5",  'range':[102,110]},
    {'name':"Hea6",  'range':[[111,111],[120,127]]},
    {'name':"P4",    'range':[112,119]},
    #        Hea6            [120,127]
    {'name':"Hea7",  'range':[128,136]},
    {'name':"Hea8",  'range':[[137,141],[150,153]]},
    {'name':"P5",    'range':[142,149]},
    #        Hea8            [150,153]
    {'name':"Hea9",  'range':[154,162]},
    {'name':"Hea10", 'range':[163,171]},
    {'name':"P6",    'range':[172,179]},
    {'name':"Hea11", 'range':[180,188]},
    {'name':"Hea12", 'range':[189,197]},
    {'name':"Hea13", 'range':[[198,201],[210,214]]},
    {'name':"P7",    'range':[202,209]},
    #        Hea13           [210,214]
    {'name':"Hea14", 'range':[215,223]},
    {'name':"Hea15", 'range':[[224,231],[240,240]]},
    {'name':"P8",    'range':[232,239]},
    #        Hea15           [240,240]
    {'name':"Hea16", 'range':[241,249]},
    {'name':"Hea17", 'range':[250,258]},
    {'name':"Hea18", 'range':[[259,261],[270,275]]},
    {'name':"P9",    'range':[262,269]},
    #       Hea18            [270,275]
    {'name':"Hea19", 'range':[276,284]},
    {'name':"Rev3",  'range':[285,291]},
    {'name':"P10",   'range':[292,299]}]

D1DictHealthB = [
    {'name':"Pre",   'range':[0,10]},
    {'name':"Rev",   'range':[11,14]},
    {'name':"FraID", 'range':[15,17]},
    {'name':"SOW",   'range':[[18,25],[30,41]],                     'unit':utility.SECOND},
    {'name':"P1",    'range':[26,29]},
    #        SOW             [30,41]
    {'name':"Rev2",  'range':[42,42]},
    {'name':"Pnum",  'range':[43,49]},
    {'name':"Hea20", 'range':[[50,51],[60,66]]},
    {'name':"P2",    'range':[52,59]},
    #        Hea20           [60,66]
    {'name':"Hea21", 'range':[67,75]},
    {'name':"Hea22", 'range':[[76,81],[90,92]]},
    {'name':"P3",    'range':[82,89]},
    #        Hea22           [90,92]
    {'name':"Hea23", 'range':[93,101]},
    {'name':"Hea24", 'range':[102,110]},
    {'name':"Hea25", 'range':[[111,111],[120,127]]},
    {'name':"P4",    'range':[112,119]},
    #        Hea25           [120,127]
    {'name':"Hea26", 'range':[128,136]},
    {'name':"Hea27", 'range':[[137,141],[150,153]]},
    {'name':"P5",    'range':[142,149]},
    #        Hea27            [150,153]
    {'name':"Hea28", 'range':[154,162]},
    {'name':"Hea29", 'range':[163,171]},
    {'name':"P6",    'range':[172,179]},
    {'name':"Hea30", 'range':[180,188]},
    {'name':"WNa",   'range':[189,196],                             'unit':utility.WEEK},
    {'name':"toa",   'range':[[197,201],[210,212]], 'factor':2**12, 'unit':utility.SECOND},
    {'name':"P7",    'range':[202,209]},
    #        toa             [210,212]
    {'name':"Rev3",  'range':[213,275]},
    {'name':"P8",    'range':[276,299]}]

D1DictHealthC = [
    {'name':"Pre",   'range':[0,10]},
    {'name':"Rev",   'range':[11,14]},
    {'name':"FraID", 'range':[15,17]},
    {'name':"SOW",   'range':[[18,25],[30,41]], 'unit':utility.SECOND},
    {'name':"P1",    'range':[26,29]},
    #        SOW             [30,41]
    {'name':"Rev2",  'range':[42,42]},
    {'name':"Pnum",  'range':[43,49]},
    {'name':"Hea31", 'range':[[50,51],[60,66]]},
    {'name':"P2",    'range':[52,59]},
    #        Hea31            [60,66]
    {'name':"Hea32", 'range':[67,75]},
    {'name':"Hea33", 'range':[[76,81],[90,92]]},
    {'name':"P3",    'range':[82,89]},
    #        Hea33           [90,92]
    {'name':"Hea34", 'range':[93,101]},
    {'name':"Hea35", 'range':[102,110]},
    {'name':"Hea36", 'range':[[111,111],[120,127]]},
    {'name':"P4",    'range':[112,119]},
    #        Hea36           [120,127]
    {'name':"Hea37", 'range':[128,136]},
    {'name':"Hea38", 'range':[[137,141],[150,153]]},
    {'name':"P5",    'range':[142,149]},
    #        Hea38           [150,153]
    {'name':"Hea39", 'range':[154,162]},
    {'name':"Hea40", 'range':[163,171]},
    {'name':"P6",    'range':[172,179]},
    {'name':"Hea41", 'range':[180,188]},
    {'name':"Hea42", 'range':[189,197]},
    {'name':"Hea43", 'range':[[198,201],[210,214]]},
    {'name':"P7",    'range':[202,209]},
    #        Hea43           [210,214]
    {'name':"AmID",  'range':[215,216]},
    {'name':"Rev4",  'range':[217,231]},
    {'name':"P8",    'range':[232,239]},
    {'name':"Rev5",  'range':[240,261]},
    {'name':"P9",    'range':[262,269]},
    {'name':"Rev6",  'range':[270,291]},
    {'name':"P10",   'range':[292,299]}]

D1DictGNSSTime = [
    {'name':"Pre",   'range':[0,10]},
    {'name':"Rev",   'range':[11,14]},
    {'name':"FraID", 'range':[15,17]},
    {'name':"SOW",   'range':[[18,25],[30,41]],                                  'unit':utility.SECOND},
    {'name':"P1",    'range':[26,29]},
    #        SOW             [30,41]
    {'name':"Rev2",  'range':[42,42]},
    {'name':"Pnum",  'range':[43,49]},
    {'name':"Rev3",  'range':[50,51]},
    {'name':"P2",    'range':[52,59]},
    {'name':"Rev4",  'range':[60,81]},
    {'name':"P3",    'range':[82,89]},
    {'name':"Rev5",  'range':[90,95]},
    {'name':"A0GPS", 'range':[96,109],              'signed':True, 'factor':0.1, 'unit':utility.NANO_SECOND},
    {'name':"A1GPS", 'range':[[110,111],[120,133]], 'signed':True, 'factor':0.1, 'unit':utility.NANO_SECOND_PER_SECOND},
    {'name':"P4",    'range':[112,119]},
    #        A1GPS           [120,133]
    {'name':"A0Gal", 'range':[[134,141],[150,155]], 'signed':True, 'factor':0.1, 'unit':utility.NANO_SECOND},
    {'name':"P5",    'range':[142,149]},
    #        A0Gal           [150,155]
    {'name':"A1Gal", 'range':[156,171],             'signed':True, 'factor':0.1, 'unit':utility.NANO_SECOND_PER_SECOND},
    {'name':"P6",    'range':[172,179]},
    {'name':"A0GLO", 'range':[180,193],             'signed':True, 'factor':0.1, 'unit':utility.NANO_SECOND},
    {'name':"A1GLO", 'range':[[194,201],[210,217]], 'signed':True, 'factor':0.1, 'unit':utility.NANO_SECOND_PER_SECOND},
    {'name':"P7",    'range':[202,209]},
    #        A1GLO           [210,217]
    {'name':"Rev6",  'range':[218,275]},
    {'name':"P8",    'range':[276,299]}]

D1DictUTCTime = [
    {'name':"Pre",        'range':[0,10]},
    {'name':"Rev",        'range':[11,14]},
    {'name':"FraID",      'range':[15,17]},
    {'name':"SOW",        'range':[[18,25],[30,41]],                                     'unit':utility.SECOND},
    {'name':"P1",         'range':[26,29]},
    #        SOW                  [30,41]
    {'name':"Rev2",       'range':[42,42]},
    {'name':"Pnum",       'range':[43,49]},
    {'name':"Delta-tLS",  'range':[[50,51],[60,65]],     'signed':True,                  'unit':utility.SECOND},
    {'name':"P2",         'range':[52,59]},
    #        DeltatLS             [60,65]
    {'name':"Delta-tLSF", 'range':[66,73],               'signed':True,                  'unit':utility.SECOND},
    {'name':"WNLSF",      'range':[74,81],                                               'unit':utility.WEEK},
    {'name':"P3",         'range':[82,89]},
    {'name':"A0UTC",      'range':[[90,111],[120,129]],  'signed':True, 'factor':2**-30, 'unit':utility.SECOND},
    {'name':"P4",         'range':[112,119]},
    #        A0UTC                [120,129]
    {'name':"A1UTC",      'range':[[130,141],[150,161]], 'signed':True, 'factor':2**-50, 'unit':utility.SECOND_PER_SECOND},
    {'name':"P5",         'range':[142,149]},
    #        A1UTC                [150,161]
    {'name':"DN",         'range':[162,169],                                             'unit':utility.DAY},
    {'name':"Rev3",       'range':[170,259]},
    {'name':"P8",         'range':[260,299]}]

D1DictAlmanacSF5 = [
    {'name':"Pre",      'range':[0,10]},
    {'name':"Rev",      'range':[11,14]},
    {'name':"FraID",    'range':[15,17]},
    {'name':"SOW",      'range':[[18,25],[30,41]],                                     'unit':utility.SECOND},
    {'name':"P1",       'range':[26,29]},
    #        SOW                [30,41]
    {'name':"Rev2",     'range':[42,42]},
    {'name':"Pnum",     'range':[43,49]},
    {'name':"SqrtA",    'range':[[50,51],[60,81]],                    'factor':2**-11, 'unit':utility.METER_SQUARE_ROOT},
    {'name':"P2",       'range':[52,59]},
    #        SqrtA              [60,81]
    {'name':"P3",       'range':[82,89]},
    {'name':"a1",       'range':[90,100],              'signed':True, 'factor':2**-38, 'unit':utility.SECOND_PER_SECOND},
    {'name':"a0",       'range':[101, 111],            'signed':True, 'factor':2**-20, 'unit':utility.SECOND},
    {'name':"P4",       'range':[112,119]},
    {'name':"Omega0",   'range':[[120,141],[150,151]], 'signed':True, 'factor':2**-23, 'unit':utility.SEMICIRCLE},
    {'name':"P5",       'range':[142,149]},
    #        Omega0             [150,151]
    {'name':"e",        'range':[152,168],                            'factor':2**-21},
    {'name':"Delta-i",  'range':[[169,171],[180,192]], 'signed':True, 'factor':2**-19, 'unit':utility.SEMICIRCLE},
    {'name':"P6",       'range':[172,179]},
    #        Deltai             [180,192]
    {'name':"toa",      'range':[193,200],                            'factor':2**12,  'unit':utility.SECOND},
    {'name':"OmegaDot", 'range':[[201,201],[210,225]], 'signed':True, 'factor':2**-38, 'unit':utility.SEMICIRCLE_PER_SECOND},
    {'name':"P7",       'range':[202,209]},
    #        OmegaDot           [210,225]
    {'name':"Omega",    'range':[[226,231],[240,257]], 'signed':True, 'factor':2**-23, 'unit':utility.SEMICIRCLE},
    {'name':"P8",       'range':[232,239]},
    #        Omega              [240,257]
    {'name':"M0",       'range':[[258,261],[270,289]], 'signed':True, 'factor':2**-23, 'unit':utility.SEMICIRCLE},
    {'name':"P9",       'range':[262,269]},
    #        M0                 [270,289]
    {'name':"AmID",     'range':[290,291]},
    {'name':"P10",      'range':[292,299]}]

D1DictPlaceholder = [
    {'name':"Pre",   'range':[0,10]},
    {'name':"Rev",   'range':[11,14]},
    {'name':"FraID", 'range':[15,17]},
    {'name':"SOW",   'range':[[18,25],[30,41]], 'unit':utility.SECOND},
    {'name':"P1",    'range':[26,29]},
    #        SOW             [30,41]
    {'name':"Rev2",  'range':[42,42]},
    {'name':"Pnum",  'range':[43,49]},
    {'name':"Rev3",  'range':[50,227]},
    {'name':"P8",    'range':[228,299]}]

D1DictEphemeris = {1:D1DictEphemeris1, 2:D1DictEphemeris2, 3:D1DictEphemeris3, 4:D1DictAlmanac}

"""
    Information for decoding BeiDou D2 navigation messages.
"""

D2DictSf1Page1 = [
    {'name':"Pre",   'range':[0,10]},
    {'name':"Rev",   'range':[11,14]},
    {'name':"FraID", 'range':[15,17]},
    {'name':"SOW",   'range':[[18,25],[30,41]],                                       'unit':utility.SECOND},
    {'name':"P1",    'range':[26,29]},
    #        SOW             [30,41]
    {'name':"Pnum1", 'range':[42,45]},
    {'name':"SatH1", 'range':[46,46]},
    {'name':"AODC",  'range':[47,51]},
    {'name':"P2",    'range':[52,59]},
    {'name':"URAI",  'range':[60,63]},
    {'name':"WN",    'range':[64,76]},
    {'name':"toc",   'range':[[77,81], [90,101]],                   'factor':2**3,   'unit':utility.SECOND},
    {'name':"P3",    'range':[82,89]},
    #        toc             [90,101]
    {'name':"TGD1",  'range':[102,111],              'signed':True, 'factor':10**-1, 'unit':utility.NANO_SECOND},
    {'name':"P4",    'range':[112,119]},
    {'name':"TGD2",  'range':[120,129],              'signed':True, 'factor':10**-1, 'unit':utility.NANO_SECOND},
    {'name':"Rev2",  'range':[130,141]},
    {'name':"P5",    'range':[142,149]}
]

D2DictSf1Page2 = [
    {'name':"Pre",   'range':[0,10]},
    {'name':"Rev",   'range':[11,14]},
    {'name':"FraID", 'range':[15,17]},
    {'name':"SOW",   'range':[[18,25],[30,41]],                                       'unit':utility.SECOND},
    {'name':"P1",    'range':[26,29]},
    #        SOW             [30,41]
    {'name':"Pnum1", 'range':[42,45]},
    {'name':"Alpha0",'range':[[46,51], [60,61]],      'signed':True, 'factor':2**-30, 'unit':utility.SECOND},
    {'name':"P2",    'range':[52,59]},
    #        Alpha0          [60,61]
    {'name':"Alpha1",'range':[62,69],                 'signed':True, 'factor':2**-27, 'unit':utility.SECOND_PER_SEMICIRCLE},
    {'name':"Alpha2",'range':[70,77],                 'signed':True, 'factor':2**-24, 'unit':utility.SECOND_PER_SEMICIRCLE_SQUARED},
    {'name':"Alpha3",'range':[[78,81], [90,93]],      'signed':True, 'factor':2**-24, 'unit':utility.SECOND_PER_SEMICIRCLE_CUBE},
    {'name':"P3",    'range':[82,89]},
    #        Alpha3          [90,93]
    {'name':"Beta0", 'range':[94,101],                'signed':True, 'factor':2**11,  'unit':utility.SECOND},
    {'name':"Beta1", 'range':[102,109],               'signed':True, 'factor':2**14,  'unit':utility.SECOND_PER_SEMICIRCLE},
    {'name':"Beta2", 'range':[[110,111], [120,125]],  'signed':True, 'factor':2**16,  'unit':utility.SECOND_PER_SEMICIRCLE_SQUARED},
    {'name':"P4",    'range':[112,119]},
    #        Beta2           [120,125]
    {'name':"Beta3", 'range':[126,133],               'signed':True, 'factor':2**16,  'unit':utility.SECOND_PER_SEMICIRCLE_CUBE},
    {'name':"Rev2",  'range':[134,141]},
    {'name':"P5",    'range':[142,149]}
]

D2DictSf1Page3 = [
    {'name':"Pre",   'range':[0,10]},
    {'name':"Rev",   'range':[11,14]},
    {'name':"FraID", 'range':[15,17]},
    {'name':"SOW",   'range':[[18,25],[30,41]],                                       'unit':utility.SECOND},
    {'name':"P1",    'range':[26,29]},
    #        SOW             [30,41]
    {'name':"Pnum1", 'range':[42,45]},
    {'name':"Rev2",  'range':[[46,51], [60,81], [90,99]]},
    {'name':"P2",    'range':[52,59]},
    #        Rev2            [60,81]
    {'name':"P3",    'range':[82,89]},
    #        Alpha3          [90,99]
    {'name':"a0",    'range':[[100,111], [120,131]],  'signed':True, 'factor':2**-33, 'unit':utility.SECOND},
    {'name':"P4",    'range':[112,119]},
    #        a0              [120,131]
    {'name':"a1",    'range':[132,135],               'signed':True, 'factor':2**-50, 'unit':utility.SECOND_PER_SECOND},
    {'name':"Rev3",  'range':[136,141]},
    {'name':"P5",    'range':[142,149]}
]

D2DictSf1Page4 = [
    {'name':"Pre",   'range':[0,10]},
    {'name':"Rev",   'range':[11,14]},
    {'name':"FraID", 'range':[15,17]},
    {'name':"SOW",   'range':[[18,25], [30,41]],                                    'unit':utility.SECOND},
    {'name':"P1",    'range':[26,29]},
    #        SOW             [30,41]
    {'name':"Pnum1", 'range':[42,45]},
    {'name':"a1",    'range':[[46,51],  [60,71]],   'signed':True, 'factor':2**-50, 'unit':utility.SECOND_PER_SECOND},
    {'name':"P2",    'range':[52,59]},
    #        a1              [60,71]
    {'name':"a2",    'range':[[72,81],  [90,90]],   'signed':True, 'factor':2**-66, 'unit':utility.SECOND_PER_SECOND_SQUARED},
    {'name':"P3",    'range':[82,89]},
    #        a2              [90,90]
    {'name':"AODE",  'range':[91,95]},
    {'name':"DeltaN",'range':[96,111]},
    {'name':"P4",    'range':[112,119]},
    {'name':"Cuc",   'range':[120,133],             'signed':True, 'factor':2**-31, 'unit':utility.RADIAN},      
    {'name':"Rev2",  'range':[134,141]},
    {'name':"P5",    'range':[142,149]}
]

D2DictSf1Page5 = [
    {'name':"Pre",   'range':[0,10]},
    {'name':"Rev",   'range':[11,14]},
    {'name':"FraID", 'range':[15,17]},
    {'name':"SOW",   'range':[[18,25], [30,41]],                                           'unit':utility.SECOND},
    {'name':"P1",    'range':[26,29]},
    #        SOW             [30,41]
    {'name':"Pnum1", 'range':[42,45]},
    {'name':"Cuc",   'range':[46,49],                      'signed':True, 'factor':2**-31, 'unit':utility.RADIAN}, 
    {'name':"M0",    'range':[[50,51], [60,81], [90,97]],  'signed':True, 'factor':2**-31, 'unit':utility.SEMICIRCLE},   
    {'name':"P2",    'range':[52,59]},
    #        M0              [60,81]
    {'name':"P3",    'range':[82,89]},
    #        M0              [90,97]
    {'name':"Cus",   'range':[[98,111], [120,123]],        'signed':True, 'factor':2**-31, 'unit':utility.RADIAN},
    {'name':"P4",    'range':[112,119]},
    #        Cus             [120,123]
    {'name':"e",     'range':[124,133],                                   'factor':2**-33},
    {'name':"Rev2",  'range':[134,141]},
    {'name':"P5",    'range':[142,149]}
]

D2DictSf1Page6 = [
    {'name':"Pre",   'range':[0,10]},
    {'name':"Rev",   'range':[11,14]},
    {'name':"FraID", 'range':[15,17]},
    {'name':"SOW",   'range':[[18,25], [30,41]],                                               'unit':utility.SECOND},
    {'name':"P1",    'range':[26,29]},
    #        SOW             [30,41]
    {'name':"Pnum1", 'range':[42,45]},
    {'name':"e",     'range':[[46,51], [60,75]],                             'factor':2**-33},
    {'name':"P2",    'range':[52,59]},
    #        e               [60,75]
    {'name':"SqrtA", 'range':[[76,81], [90,111], [120,123]],                 'factor':2**-19,  'unit':utility.METER_SQUARE_ROOT},
    {'name':"P3",    'range':[82,89]},
    #        SqrtA           [90,111]
    {'name':"P4",    'range':[112,119]},
    #        SqrtA           [120,123]
    {'name':"Cic",   'range':[124,133],                      'signed':True,  'factor':2**-31,  'unit':utility.RADIAN},
    {'name':"Rev2",  'range':[134,141]},
    {'name':"P5",    'range':[142,149]}
]

D2DictSf1Page7 = [
    {'name':"Pre",   'range':[0,10]},
    {'name':"Rev",   'range':[11,14]},
    {'name':"FraID", 'range':[15,17]},
    {'name':"SOW",   'range':[[18,25], [30,41]],                                               'unit':utility.SECOND},
    {'name':"P1",    'range':[26,29]},
    #        SOW             [30,41]
    {'name':"Pnum1", 'range':[42,45]},
    {'name':"Cic",   'range':[[46,51], [60,61]],             'signed':True,  'factor':2**-31,  'unit':utility.RADIAN},
    {'name':"P2",    'range':[52,59]},
    #        Cic             [60,61]
    {'name':"Cis",   'range':[62,79],                        'signed':True,  'factor':2**-31,  'unit':utility.RADIAN},
    {'name':"toe",   'range':[[80,81], [90,104]],                            'factor':2**3,    'unit':utility.SECOND},
    {'name':"P3",    'range':[82,89]},
    #        toe             [90,104]
    {'name':"i0",    'range':[[105,111], [120,133]],         'signed':True, 'factor':2**-31,   'unit':utility.SEMICIRCLE},
    {'name':"P4",    'range':[112,119]},
    #        i0              [120,133]
    {'name':"Rev2",  'range':[134,141]},
    {'name':"P5",    'range':[142,149]}
]

D2DictSf1Page8 = [
    {'name':"Pre",         'range':[0,10]},
    {'name':"Rev",         'range':[11,14]},
    {'name':"FraID",       'range':[15,17]},
    {'name':"SOW",         'range':[[18,25], [30,41]],                                       'unit':utility.SECOND},
    {'name':"P1",          'range':[26,29]},
    #        SOW                   [30,41]
    {'name':"Pnum1",       'range':[42,45]},
    {'name':"i0",          'range':[[46,51], [60,64]],       'signed':True, 'factor':2**-31, 'unit':utility.SEMICIRCLE},
    {'name':"P2",          'range':[52,59]},
    #        i0                    [60,64]
    {'name':"Crc",         'range':[[65,81], [90,90]],       'signed':True, 'factor':2**-6,  'unit':utility.METER},
    {'name':"P3",          'range':[82,89]},
    #        toe                   [90,90]
    {'name':"Crs",         'range':[91,108],                 'signed':True, 'factor':2**-6,  'unit':utility.METER},
    {'name':"BigOmegaDot", 'range':[[109,111], [120,135]],   'signed':True, 'factor':2**-43, 'unit':utility.SEMICIRCLE_PER_SECOND},
    {'name':"P4",          'range':[112,119]},
    #        BigOmegaDot           [120,135]
    {'name':"Rev2",        'range':[136,141]},
    {'name':"P5",          'range':[142,149]}
]

D2DictSf1Page9 = [
    {'name':"Pre",         'range':[0,10]},
    {'name':"Rev",         'range':[11,14]},
    {'name':"FraID",       'range':[15,17]},
    {'name':"SOW",         'range':[[18,25], [30,41]],                                           'unit':utility.SECOND},
    {'name':"P1",          'range':[26,29]},
    #        SOW                   [30,41]
    {'name':"Pnum1",       'range':[42,45]},
    {'name':"BigOmegaDot", 'range':[46,50],                      'signed':True, 'factor':2**-43, 'unit':utility.SEMICIRCLE_PER_SECOND},
    {'name':"BigOmega",    'range':[[51,51], [60,81], [90,98]],  'signed':True, 'factor':2**-31, 'unit':utility.SEMICIRCLE},
    {'name':"P2",          'range':[52,59]},
    #        BigOmega              [60,81]
    {'name':"P3",          'range':[82,89]},
    #        BigOmega              [90,98]
    {'name':"LittleOmega", 'range':[[99,111], [120,133]],        'signed':True, 'factor':2**-31, 'unit':utility.SEMICIRCLE},
    {'name':"P4",          'range':[112,119]},
    #        LittleOmega           [120,133]
    {'name':"Rev2",        'range':[134,141]},
    {'name':"P5",          'range':[142,149]}
]

D2DictSf1Page10 = [
    {'name':"Pre",         'range':[0,10]},
    {'name':"Rev",         'range':[11,14]},
    {'name':"FraID",       'range':[15,17]},
    {'name':"SOW",         'range':[[18,25], [30,41]],                                             'unit':utility.SECOND},
    {'name':"P1",          'range':[26,29]},
    #        SOW                   [30,41]
    {'name':"Pnum1",       'range':[42,45]},
    {'name':"LittleOmega", 'range':[46,50],                        'signed':True, 'factor':2**-31, 'unit':utility.SEMICIRCLE},
    {'name':"IDOT",        'range':[[51,51], [60,72]],             'signed':True, 'factor':2**-43, 'unit':utility.SEMICIRCLE_PER_SECOND},
    {'name':"P2",          'range':[52,59]},
    #        IDOT                  [60,72]
    {'name':"Rev2",        'range':[[73,81], [90,111], [120,141]]},
    {'name':"P3",          'range':[82,89]},
    #        Rev2                  [90,111]
    {'name':"P4",          'range':[112,119]},
    #        Rev2                  [120, 141]
    {'name':"P5",          'range':[142,149]}
]

D2DictSf2 = [
    {'name':"Pre",         'range':[0,10]},
    {'name':"Rev",         'range':[11,14]},
    {'name':"FraID",       'range':[15,17]},
    {'name':"SOW",         'range':[[18,25], [30,41]],                                     'unit':utility.SECOND},
    {'name':"P1",          'range':[26,29]},
    #        SOW                   [30,41]
    {'name':"Rev2",        'range':[42,42]},
    {'name':"Pnum2",       'range':[43,46]},
    {'name':"SatH2",       'range':[47,48]},
    {'name':"BDID",        'range':[[49,51], [60,81], [90,94]]},
    {'name':"P2",          'range':[52,59]},
    #        BDID                  [60,81]
    {'name':"P3",          'range':[82,89]},
    #        BDID                  [90,94]
    {'name':"Rev3",        'range':[[95,111], [120,141], [150,170]]},
    {'name':"P4",          'range':[112,119]},
    #        Rev2                  [120, 141]
    {'name':"P5",          'range':[142,149]},
    #        Rev2                  [150,170]
    {'name':"UDREI1",      'range':[[171,171], [180,182]]},
    {'name':"P6",          'range':[172,179]},
    #        UDREI1                [180, 182]
    {'name':"UDREI2",      'range':[183,186]},
    {'name':"UDREI3",      'range':[187,190]},
    {'name':"UDREI4",      'range':[191,194]},
    {'name':"UDREI5",      'range':[195,198]},
    {'name':"UDREI6",      'range':[[199,201], [210,210]]},
    {'name':"P7",          'range':[202,209]},
    #        UDREI6                [210, 210]
    {'name':"UDREI7",      'range':[211,214]},
    {'name':"UDREI8",      'range':[215,218]},
    {'name':"UDREI9",      'range':[219,222]},
    {'name':"UDREI10",     'range':[223,226]},
    {'name':"UDREI11",     'range':[227,230]},
    {'name':"UDREI12",     'range':[[231,231], [240,242]]},
    {'name':"P8",          'range':[232,239]},
    #        UDREI12               [240,242]
    {'name':"UDREI13",     'range':[243,246]},
    {'name':"UDREI14",     'range':[247,250]},
    {'name':"UDREI15",     'range':[251,254]},
    {'name':"UDREI16",     'range':[255,258]},
    {'name':"UDREI17",     'range':[[259,261], [270,270]]},
    {'name':"P9",          'range':[262,269]},
    #        UDREI17               [270,270]
    {'name':"UDREI18",     'range':[271,274]},
    {'name':"RUREII1",     'range':[275,278]},
    {'name':"DeltaTi1",    'range':[279,291],                  'signed':True, 'factor':10**-1, 'unit':utility.METER},
    {'name':"P10",         'range':[292,299]}
]

D2DictSf3 = [
    {'name':"Pre",         'range':[0,10]},
    {'name':"Rev",         'range':[11,14]},
    {'name':"FraID",       'range':[15,17]},
    {'name':"SOW",         'range':[[18,25], [30,41]],                                                          'unit':utility.SECOND},
    {'name':"P1",          'range':[26,29]},
    #        SOW                   [30,41]
    {'name':"Rev2",        'range':[42,42]},
    {'name':"RUREII2",     'range':[43,46]},
    {'name':"DeltaTi2",    'range':[[47,51], [60,67]],                          'signed':True, 'factor':10**-1, 'unit':utility.METER},
    {'name':"P2",          'range':[52,59]},
    #        DeltaTi2              [60,67]
    {'name':"RUREII3",     'range':[68,71]},
    {'name':"DeltaTi3",    'range':[[72,81], [90,92]],                          'signed':True, 'factor':10**-1, 'unit':utility.METER},
    {'name':"P3",          'range':[82,89]},
    #        DeltaTi3              [90,92]
    {'name':"Rev3",        'range':[[93,111], [120,141], [150,171], [180,180]]},
    {'name':"P4",          'range':[112,119]},
    #        Rev3                  [120, 141]
    {'name':"P5",          'range':[142,149]},
    #        Rev3                  [150,171]
    {'name':"P6",          'range':[172,179]},
    #        Rev3                  [180,180]
    {'name':"Rev4",        'range':[[181,201], [210,231], [240,260]]},
    {'name':"P7",          'range':[202,209]},
    #        Rev4                  [210, 231]
    {'name':"P8",          'range':[232,239]},
    #        Rev4                  [240,260]
    {'name':"Rev5",        'range':[[261,261], [270,291]]},
    {'name':"P9",          'range':[262,269]},
    #        Rev5                  [270,291]
    {'name':"P10",         'range':[292,299]}
]

D2DictSf4 = [
    {'name':"Pre",      'range':[0,10]},
    {'name':"Rev",      'range':[11,14]},
    {'name':"FraID",    'range':[15,17]},
    {'name':"SOW",      'range':[[18,25],[30,41]],                             'unit':utility.SECOND},
    {'name':"P1",       'range':[26,29]},
    #        SOW                [30,41]
    {'name':"Rev2",     'range':[42,42]},
    {'name':"Rev3",     'range':[43, 106]},
    {'name':"Rev4",     'range':[107, 167]},
    {'name':"BDEpID",   'range':[168, 169]},
    {'name':"BDID31",   'range':[170,170]},
    {'name':"BDID32",   'range':[171,171]},
    {'name':"P6",       'range':[172,179]},
    {'name':"BDID33",   'range':[180,180]},
    {'name':"BDID34",   'range':[181,181]},
    {'name':"BDID35",   'range':[182,182]},
    {'name':"BDID36",   'range':[183,183]},
    {'name':"BDID37",   'range':[184,184]},
    {'name':"BDID38",   'range':[185,185]},
    {'name':"BDID39",   'range':[186,186]},
    {'name':"BDID40",   'range':[187,187]},
    {'name':"BDID41",   'range':[188,188]},
    {'name':"BDID42",   'range':[189,189]},
    {'name':"BDID43",   'range':[190,190]},
    {'name':"BDID44",   'range':[191,191]},
    {'name':"BDID45",   'range':[192,192]},
    {'name':"BDID46",   'range':[193,193]},
    {'name':"BDID47",   'range':[194,194]},
    {'name':"BDID48",   'range':[195,195]},
    {'name':"BDID49",   'range':[196,196]},
    {'name':"BDID50",   'range':[197,197]},
    {'name':"BDID51",   'range':[198,198]},
    {'name':"BDID52",   'range':[199,199]},
    {'name':"BDID53",   'range':[200,200]},
    {'name':"BDID54",   'range':[201,201]},
    {'name':"P7",       'range':[202,209]},
    {'name':"BDID55",   'range':[210,210]},
    {'name':"BDID56",   'range':[211,211]},
    {'name':"BDID57",   'range':[212,212]},
    {'name':"BDID58",   'range':[213,213]},
    {'name':"BDID59",   'range':[214,214]},
    {'name':"BDID60",   'range':[215,215]},
    {'name':"BDID61",   'range':[216,216]},
    {'name':"BDID62",   'range':[217,217]},
    {'name':"BDID63",   'range':[218,218]},
    {'name':"UDREI19",  'range':[219,222]},
    {'name':"UDREI20",  'range':[223,226]},
    {'name':"UDREI21",  'range':[227,230]},
    {'name':"UDREI22",  'range':[[231,231], [240,242]]},
    {'name':"P8",       'range':[232,239]},
    #       "UDREI22",          [240,242]
    {'name':"UDREI23",  'range':[243,246]},
    {'name':"UDREI24",  'range':[247,250]},
    {'name':"RURAIi4",  'range':[251,254]},
    {'name':"deltaTi4", 'range':[[255,261], [270,275]],   'signed':True, 'factor':10**-1, 'unit':utility.METER},
    {'name':"P9",       'range':[262,269]},
    #       "deltaTi4",         [270,275]
    {'name':"rev5",     'range':[276,291]},
    {'name':"P10",      'range':[292,299]}
]

D2DictSf5IonoGridA  = [
    {'name':"Pre",         'range':[0,10]},
    {'name':"Rev",         'range':[11,14]},
    {'name':"FraID",       'range':[15,17]},
    {'name':"SOW",         'range':[[18,25], [30,41]],                         'unit':utility.SECOND},
    {'name':"P1",          'range':[26,29]},
    #        SOW                   [30,41]
    {'name':"Rev2",        'range':[42,42]},
    {'name':"Pnum",        'range':[43,49]},
    {'name':"IonoA",       'range':[[50,51], [60,70]]},
    {'name':"P2",          'range':[52,59]},
    #        IonoA                 [60,70]
    {'name':"IonoB",       'range':[[71,81], [90,91]]},
    {'name':"P3",          'range':[82,89]},
    #        IonoB                [90,91]
    {'name':"IonoC",       'range':[92,104]},
    {'name':"IonoD",       'range':[[105,111], [120,125]]},
    {'name':"P4",          'range':[112,119]},
    #        IonoD                 [120, 125]
    {'name':"IonoE",       'range':[126,138]},
    {'name':"IonoF",       'range':[[139,141], [150,159]]},
    {'name':"P5",          'range':[142,149]},
    #        IonoF                 [150,159]
    {'name':"IonoG",       'range':[[160,171], [180,180]]},
    {'name':"P6",          'range':[172,179]},
    #        IonoG                 [180,180]
    {'name':"IonoH",       'range':[181,193]},
    {'name':"IonoI",       'range':[[194,201], [210,214]]},
    {'name':"P7",          'range':[202,209]},
    #        IonoI                 [210, 214]
    {'name':"IonoJ",       'range':[215,227]},
    {'name':"IonoK",       'range':[[228,231], [240,248]]},
    {'name':"P8",          'range':[232,239]},
    #        IonoK                 [240,248]
    {'name':"IonoL",       'range':[249,261]},
    {'name':"P9",          'range':[262,269]},
    {'name':"IonoM",       'range':[270,282]},
    {'name':"Rev3",        'range':[283,291]},
    {'name':"P10",         'range':[292,299]}
]

D2DictSf5IonoGridB  = [
    {'name':"Pre",         'range':[0,10]},
    {'name':"Rev",         'range':[11,14]},
    {'name':"FraID",       'range':[15,17]},
    {'name':"SOW",         'range':[[18,25], [30,41]],                         'unit':utility.SECOND},
    {'name':"P1",          'range':[26,29]},
    #        SOW                   [30,41]
    {'name':"Rev2",        'range':[42,42]},
    {'name':"Pnum",        'range':[43,49]},
    {'name':"IonoA",       'range':[[50,51], [60,70]]},
    {'name':"P2",          'range':[52,59]},
    #        IonoA                 [60,70]
    {'name':"IonoB",       'range':[[71,81], [90,91]]},
    {'name':"P3",          'range':[82,89]},
    #        IonoB                [90,91]
    {'name':"IonoC",       'range':[92,104]},
    {'name':"IonoD",       'range':[[105,111], [120,125]]},
    {'name':"P4",          'range':[112,119]},
    #        IonoD                 [120, 125]
    {'name':"Rev3",        'range':[[126,141], [150,171], [180,201], [210,213]]},
    {'name':"P5",          'range':[142,149]},
    #        Rev3                  [150,171]
    {'name':"P6",          'range':[172,179]},
    #        Rev3                  [180,201]
    {'name':"P7",          'range':[202,209]},
    #        Rev3                  [210, 213]
    {'name':"Rev4",        'range':[[214,231], [240,261], [270,291]]},
    {'name':"P8",          'range':[232,239]},
    #        Rev4                  [240,261]
    {'name':"P9",          'range':[262,269]},
    #        Rev4                  [270,291]
    {'name':"P10",         'range':[292,299]}
]

D2DictSf5Almanac  = D1DictAlmanac
D2DictSf5HealthA  = D1DictHealthA
D2DictSf5HealthB  = D1DictHealthB
D2DictSf5HealthC  = D1DictHealthC
D2DictSf5GNSSTime = D1DictGNSSTime
D2DictSf5UTCTime  = D1DictUTCTime
D2DictSf5Almanac2 = D1DictAlmanacSF5
D2DictSf5Reserved = D1DictPlaceholder

"""
    Informations for decoding BeiDou CNAV1 navigation messages.
"""

BeiDouCNAV1DictType1 = [
    # Subframe 1
    {'name':"Prn",           'range':[0,5]},
    {'name':"SOH",           'range':[6,13],                   'factor':18,     'unit':utility.SECOND},
    
    # Subframe 2
    {'name':"WN",            'range':[14,26],                                    'unit':utility.WEEK},
    {'name':"HOW",           'range':[27,34],                                   'unit':utility.HOUR},
    {'name':"IODC",          'range':[35,44]},
    {'name':"IODE",          'range':[45,52]},
    # Ephemeris 1
    {'name':"toeSF2",        'range':[53,63],                  'factor':300,    'unit':utility.SECOND},
    {'name':"SatTypeSF2",    'range':[64,65]},
    {'name':"deltaASF2",     'range':[66,91],   'signed':True, 'factor':2**-9,  'unit':utility.METER},
    {'name':"AdotSF2",       'range':[92,116],  'signed':True, 'factor':2**-21, 'unit':utility.METER_PER_SECOND},
    {'name':"deltan0SF2",    'range':[117,133], 'signed':True, 'factor':2**-44, 'unit':utility.PI_PER_SECOND},
    {'name':"deltandot0SF2", 'range':[134,156], 'signed':True, 'factor':2**-57, 'unit':utility.PI_PER_SECOND_SQUARED},
    {'name':"M0SF2",         'range':[157,189], 'signed':True, 'factor':2**-32, 'unit':utility.PI},
    {'name':"eSF2",          'range':[190,222],                'factor':2**-34},
    {'name':"omegaSF2",      'range':[223,255], 'signed':True, 'factor':2**-32, 'unit':utility.PI},
    # Ephemeris 2
    {'name':"omega0SF2",     'range':[256,288], 'signed':True, 'factor':2**-32, 'unit':utility.PI},
    {'name':"i0",            'range':[289,321], 'signed':True, 'factor':2**-32, 'unit':utility.PI},
    {'name':"omegaDotSF2",   'range':[322,340], 'signed':True, 'factor':2**-44, 'unit':utility.PI_PER_SECOND},
    {'name':"idot0",         'range':[341,355], 'signed':True, 'factor':2**-44, 'unit':utility.PI_PER_SECOND},
    {'name':"Cis",           'range':[356,371], 'signed':True, 'factor':2**-30, 'unit':utility.RADIAN},
    {'name':"Cic",           'range':[372,387], 'signed':True, 'factor':2**-30, 'unit':utility.RADIAN},
    {'name':"Crs",           'range':[388,411], 'signed':True, 'factor':2**-8,  'unit':utility.METER},
    {'name':"Crc",           'range':[412,435], 'signed':True, 'factor':2**-8,  'unit':utility.METER},
    {'name':"Cus",           'range':[436,456], 'signed':True, 'factor':2**-30, 'unit':utility.RADIAN},
    {'name':"Cuc",           'range':[457,477], 'signed':True, 'factor':2**-30, 'unit':utility.RADIAN},
    # Clock correction  
    {'name':"toc",           'range':[478,488],                'factor':300,    'unit':utility.SECOND},
    {'name':"a0",            'range':[489,513], 'signed':True, 'factor':2**-34, 'unit':utility.SECOND},
    {'name':"a1",            'range':[514,535], 'signed':True, 'factor':2**-50, 'unit':utility.SECOND_PER_SECOND},
    {'name':"a2",            'range':[536,546], 'signed':True, 'factor':2**-66, 'unit':utility.SECOND_PER_SECOND_SQUARED},
  
    {'name':"TGDB2ap",       'range':[547,558], 'signed':True, 'factor':2**-34, 'unit':utility.SECOND},
    {'name':"ISCB1Cd",       'range':[559,570], 'signed':True, 'factor':2**-34, 'unit':utility.SECOND},
    {'name':"TGDB1Cp",       'range':[571,582], 'signed':True, 'factor':2**-34, 'unit':utility.SECOND},
    {'name':"RevSF2",        'range':[583,589]},
    {'name':"CRCSF2",        'range':[590,613]},

    # Subframe 3
    {'name':"PageID",   'range':[614,619]},
    {'name':"HS",       'range':[620,621]},
    {'name':"DIF",      'range':[622,622]},
    {'name':"SIF",      'range':[623,623]},
    {'name':"AIF",      'range':[624,624]},
    {'name':"SISMAI",   'range':[625,628]},
    {'name':"SISAIoe",  'range':[629,633]},
    
    # SISAIOC
    {'name':"top",       'range':[634,644]},
    {'name':"SISAIocb",  'range':[645,649]},
    {'name':"SISAIoc1",  'range':[650,652]},
    {'name':"SISAIoc2",  'range':[653,655]},
    # Iono delay
    {'name':"alpha1",    'range':[656,665],                'factor':2**-3,  'unit':utility.TEC_U},
    {'name':"alpha2",    'range':[666,673], 'signed':True, 'factor':2**-3,  'unit':utility.TEC_U},
    {'name':"alpha3",    'range':[674,681],                'factor':2**-3,  'unit':utility.TEC_U},
    {'name':"alpha4",    'range':[682,689],                'factor':2**-3,  'unit':utility.TEC_U},
    {'name':"alpha5",    'range':[690,697],                'factor':-2**-3, 'unit':utility.TEC_U},
    {'name':"alpha6",    'range':[698,705], 'signed':True, 'factor':2**-3,  'unit':utility.TEC_U},
    {'name':"alpha7",    'range':[706,713], 'signed':True, 'factor':2**-3,  'unit':utility.TEC_U},
    {'name':"alpha8",    'range':[714,721], 'signed':True, 'factor':2**-3,  'unit':utility.TEC_U},
    {'name':"alpha9",    'range':[722,729], 'signed':True, 'factor':2**-3,  'unit':utility.TEC_U},
    # BDT   
    {'name':"A0UTC",     'range':[730,745], 'signed':True, 'factor':2**-35, 'unit':utility.SECOND},
    {'name':"A1UTC",     'range':[746,758], 'signed':True, 'factor':2**-51, 'unit':utility.SECOND_PER_SECOND},
    {'name':"A2UTC",     'range':[759,765], 'signed':True, 'factor':2**-68, 'unit':utility.SECOND_PER_SECOND_SQUARED},
    {'name':"deltatLS",  'range':[766,773], 'signed':True,                  'unit':utility.SECOND},
    {'name':"tot",       'range':[774,789],                'factor':2**4,   'unit':utility.SECOND},
    {'name':"WNot",      'range':[790,802],                                 'unit':utility.WEEK},
    {'name':"WNLSF",     'range':[803,815],                                 'unit':utility.WEEK},
    {'name':"DN",        'range':[816,818],                                 'unit':utility.DAY},
    {'name':"deltatLSF", 'range':[819,826], 'signed':True,                  'unit':utility.SECOND},

    {'name':"Rev",       'range':[827,853]},
    {'name':"CRC",       'range':[854,877]}]

BeiDouCNAV1DictType2 = [
    # Subframe 1
    {'name':"Prn",           'range':[0,5]},
    {'name':"SOH",           'range':[6,13],                   'factor':18,     'unit':utility.SECOND},
    
    # Subframe 2
    {'name':"WN",            'range':[14,26],                                    'unit':utility.WEEK},
    {'name':"HOW",           'range':[27,34],                                   'unit':utility.HOUR},
    {'name':"IODC",          'range':[35,44]},
    {'name':"IODE",          'range':[45,52]},
    # Ephemeris 1
    {'name':"toeSF2",        'range':[53,63],                  'factor':300,    'unit':utility.SECOND},
    {'name':"SatTypeSF2",    'range':[64,65]},
    {'name':"deltaASF2",     'range':[66,91],   'signed':True, 'factor':2**-9,  'unit':utility.METER},
    {'name':"AdotSF2",       'range':[92,116],  'signed':True, 'factor':2**-21, 'unit':utility.METER_PER_SECOND},
    {'name':"deltan0SF2",    'range':[117,133], 'signed':True, 'factor':2**-44, 'unit':utility.PI_PER_SECOND},
    {'name':"deltandot0SF2", 'range':[134,156], 'signed':True, 'factor':2**-57, 'unit':utility.PI_PER_SECOND_SQUARED},
    {'name':"M0SF2",         'range':[157,189], 'signed':True, 'factor':2**-32, 'unit':utility.PI},
    {'name':"eSF2",          'range':[190,222],                'factor':2**-34},
    {'name':"omegaSF2",      'range':[223,255], 'signed':True, 'factor':2**-32, 'unit':utility.PI},
    # Ephemeris 2
    {'name':"omega0SF2",     'range':[256,288], 'signed':True, 'factor':2**-32, 'unit':utility.PI},
    {'name':"i0",            'range':[289,321], 'signed':True, 'factor':2**-32, 'unit':utility.PI},
    {'name':"omegaDotSF2",   'range':[322,340], 'signed':True, 'factor':2**-44, 'unit':utility.PI_PER_SECOND},
    {'name':"idot0",         'range':[341,355], 'signed':True, 'factor':2**-44, 'unit':utility.PI_PER_SECOND},
    {'name':"Cis",           'range':[356,371], 'signed':True, 'factor':2**-30, 'unit':utility.RADIAN},
    {'name':"Cic",           'range':[372,387], 'signed':True, 'factor':2**-30, 'unit':utility.RADIAN},
    {'name':"Crs",           'range':[388,411], 'signed':True, 'factor':2**-8,  'unit':utility.METER},
    {'name':"Crc",           'range':[412,435], 'signed':True, 'factor':2**-8,  'unit':utility.METER},
    {'name':"Cus",           'range':[436,456], 'signed':True, 'factor':2**-30, 'unit':utility.RADIAN},
    {'name':"Cuc",           'range':[457,477], 'signed':True, 'factor':2**-30, 'unit':utility.RADIAN},
    # Clock correction  
    {'name':"toc",           'range':[478,488],                'factor':300,    'unit':utility.SECOND},
    {'name':"a0",            'range':[489,513], 'signed':True, 'factor':2**-34, 'unit':utility.SECOND},
    {'name':"a1",            'range':[514,535], 'signed':True, 'factor':2**-50, 'unit':utility.SECOND_PER_SECOND},
    {'name':"a2",            'range':[536,546], 'signed':True, 'factor':2**-66, 'unit':utility.SECOND_PER_SECOND_SQUARED},
  
    {'name':"TGDB2ap",       'range':[547,558], 'signed':True, 'factor':2**-34, 'unit':utility.SECOND},
    {'name':"ISCB1Cd",       'range':[559,570], 'signed':True, 'factor':2**-34, 'unit':utility.SECOND},
    {'name':"TGDB1Cp",       'range':[571,582], 'signed':True, 'factor':2**-34, 'unit':utility.SECOND},
    {'name':"RevSF2",        'range':[583,589]},
    {'name':"CRCSF2",        'range':[590,613]},

    # Subframe 3
    {'name':"PageID",   'range':[614,619]},
    {'name':"HS",       'range':[620,621]},
    {'name':"DIF",      'range':[622,622]},
    {'name':"SIF",      'range':[623,623]},
    {'name':"AIF",      'range':[624,624]},
    {'name':"SISMAI",   'range':[625,628]},
    # SISAIOC
    {'name':"top",      'range':[629,639]},
    {'name':"SISAIocb", 'range':[640,644]},
    {'name':"SISAIoc1", 'range':[645,647]},
    {'name':"SISAIoc2", 'range':[648,650]},

    {'name':"WNa",      'range':[651,663],                                'unit':utility.WEEK},
    {'name':"toa",      'range':[664,671],                'factor':2**12, 'unit':utility.SECOND},
    # reduced almanac 1
    {'name':"PRNa1",    'range':[672,677]},
    {'name':"SatType1", 'range':[678,679]},
    {'name':"deltaA1",  'range':[680,687], 'signed':True, 'factor':2**9, 'unit':utility.METER},
    {'name':"omega01",  'range':[688,694], 'signed':True, 'factor':2**-6, 'unit':utility.PI},
    {'name':"phi01",    'range':[695,701], 'signed':True, 'factor':2**-6, 'unit':utility.PI},
    {'name':"Health1",  'range':[702,709]},
    # reduced almanac 2
    {'name':"PRNa2",    'range':[710,715]},
    {'name':"SatType2", 'range':[716,717]},
    {'name':"deltaA2",  'range':[718,725], 'signed':True, 'factor':2**9, 'unit':utility.METER},
    {'name':"omega02",  'range':[726,732], 'signed':True, 'factor':2**-6, 'unit':utility.PI},
    {'name':"phi02",    'range':[733,739], 'signed':True, 'factor':2**-6, 'unit':utility.PI},
    {'name':"Health2",  'range':[740,747]},
    # reduced almanac 3
    {'name':"PRNa3",    'range':[748,753]},
    {'name':"SatType3", 'range':[754,755]},
    {'name':"deltaA3",  'range':[756,763], 'signed':True, 'factor':2**9, 'unit':utility.METER},
    {'name':"omega03",  'range':[764,770], 'signed':True, 'factor':2**-6, 'unit':utility.PI},
    {'name':"phi03",    'range':[771,777], 'signed':True, 'factor':2**-6, 'unit':utility.PI},
    {'name':"Health3",  'range':[778,785]},
    # reduced almanac 4
    {'name':"PRNa4",    'range':[786,791]},
    {'name':"SatType4", 'range':[792,793]},
    {'name':"deltaA4",  'range':[794,801], 'signed':True, 'factor':2**9, 'unit':utility.METER},
    {'name':"omega04",  'range':[802,808], 'signed':True, 'factor':2**-6, 'unit':utility.PI},
    {'name':"phi04",    'range':[809,815], 'signed':True, 'factor':2**-6, 'unit':utility.PI},
    {'name':"Health4",  'range':[816,823]},

    {'name':"Rev", 'range':[824,853]},
    {'name':"CRC", 'range':[854,877]}]

BeiDouCNAV1DictType3 = [
    # Subframe 1
    {'name':"Prn",           'range':[0,5]},
    {'name':"SOH",           'range':[6,13],                   'factor':18,     'unit':utility.SECOND},
    
    # Subframe 2
    {'name':"WN",            'range':[14,26],                                    'unit':utility.WEEK},
    {'name':"HOW",           'range':[27,34],                                   'unit':utility.HOUR},
    {'name':"IODC",          'range':[35,44]},
    {'name':"IODE",          'range':[45,52]},
    # Ephemeris 1
    {'name':"toeSF2",        'range':[53,63],                  'factor':300,    'unit':utility.SECOND},
    {'name':"SatTypeSF2",    'range':[64,65]},
    {'name':"deltaASF2",     'range':[66,91],   'signed':True, 'factor':2**-9,  'unit':utility.METER},
    {'name':"AdotSF2",       'range':[92,116],  'signed':True, 'factor':2**-21, 'unit':utility.METER_PER_SECOND},
    {'name':"deltan0SF2",    'range':[117,133], 'signed':True, 'factor':2**-44, 'unit':utility.PI_PER_SECOND},
    {'name':"deltandot0SF2", 'range':[134,156], 'signed':True, 'factor':2**-57, 'unit':utility.PI_PER_SECOND_SQUARED},
    {'name':"M0SF2",         'range':[157,189], 'signed':True, 'factor':2**-32, 'unit':utility.PI},
    {'name':"eSF2",          'range':[190,222],                'factor':2**-34},
    {'name':"omegaSF2",      'range':[223,255], 'signed':True, 'factor':2**-32, 'unit':utility.PI},
    # Ephemeris 2
    {'name':"omega0SF2",     'range':[256,288], 'signed':True, 'factor':2**-32, 'unit':utility.PI},
    {'name':"i0",            'range':[289,321], 'signed':True, 'factor':2**-32, 'unit':utility.PI},
    {'name':"omegaDotSF2",   'range':[322,340], 'signed':True, 'factor':2**-44, 'unit':utility.PI_PER_SECOND},
    {'name':"idot0",         'range':[341,355], 'signed':True, 'factor':2**-44, 'unit':utility.PI_PER_SECOND},
    {'name':"Cis",           'range':[356,371], 'signed':True, 'factor':2**-30, 'unit':utility.RADIAN},
    {'name':"Cic",           'range':[372,387], 'signed':True, 'factor':2**-30, 'unit':utility.RADIAN},
    {'name':"Crs",           'range':[388,411], 'signed':True, 'factor':2**-8,  'unit':utility.METER},
    {'name':"Crc",           'range':[412,435], 'signed':True, 'factor':2**-8,  'unit':utility.METER},
    {'name':"Cus",           'range':[436,456], 'signed':True, 'factor':2**-30, 'unit':utility.RADIAN},
    {'name':"Cuc",           'range':[457,477], 'signed':True, 'factor':2**-30, 'unit':utility.RADIAN},
    # Clock correction  
    {'name':"toc",           'range':[478,488],                'factor':300,    'unit':utility.SECOND},
    {'name':"a0",            'range':[489,513], 'signed':True, 'factor':2**-34, 'unit':utility.SECOND},
    {'name':"a1",            'range':[514,535], 'signed':True, 'factor':2**-50, 'unit':utility.SECOND_PER_SECOND},
    {'name':"a2",            'range':[536,546], 'signed':True, 'factor':2**-66, 'unit':utility.SECOND_PER_SECOND_SQUARED},
  
    {'name':"TGDB2ap",       'range':[547,558], 'signed':True, 'factor':2**-34, 'unit':utility.SECOND},
    {'name':"ISCB1Cd",       'range':[559,570], 'signed':True, 'factor':2**-34, 'unit':utility.SECOND},
    {'name':"TGDB1Cp",       'range':[571,582], 'signed':True, 'factor':2**-34, 'unit':utility.SECOND},
    {'name':"RevSF2",        'range':[583,589]},
    {'name':"CRCSF2",        'range':[590,613]},

    # Subframe 3
    {'name':"PageID",      'range':[614,619]},
    {'name':"HS",          'range':[620,621]},
    {'name':"DIF",         'range':[622,622]},
    {'name':"SIF",         'range':[623,623]},
    {'name':"AIF",         'range':[624,624]},
    {'name':"SISMAI",      'range':[625,628]},
    {'name':"SISAIoe",     'range':[629,633]},
    # EOP
    {'name':"teop",        'range':[634,649],                  'factor':2**4,   'unit':utility.SECOND},
    {'name':"PX_X",        'range':[650,670],   'signed':True, 'factor':2**-20, 'unit':utility.ARC_SECOND},
    {'name':"PM_Xdot",     'range':[671,685],   'signed':True, 'factor':2**-21, 'unit':utility.ARC_SECOND_PER_DAY},
    {'name':"PM_Y",        'range':[686,706],   'signed':True, 'factor':2**-20, 'unit':utility.ARC_SECOND},
    {'name':"PM_Ydot",     'range':[707,721],  'signed':True, 'factor':2**-21, 'unit':utility.ARC_SECOND_PER_DAY},
    {'name':"deltaUT1",    'range':[722,752], 'signed':True, 'factor':2**-24, 'unit':utility.SECOND},
    {'name':"deltaUT1dot", 'range':[753,771], 'signed':True, 'factor':2**-25, 'unit':utility.SECOND_PER_DAY},
    # BGTO
    {'name':"GNSS ID",     'range':[772,774]},
    {'name':"WN0BGTO",     'range':[775,787],                                 'unit':utility.WEEK},
    {'name':"t0BGTO",      'range':[788,803],                'factor':2**4,   'unit':utility.SECOND},
    {'name':"A0BGTO",      'range':[804,819], 'signed':True, 'factor':2**-35, 'unit':utility.SECOND},
    {'name':"A1BGTO",      'range':[820,832], 'signed':True, 'factor':2**-51, 'unit':utility.SECOND_PER_SECOND},
    {'name':"A2BGTO",      'range':[833,839], 'signed':True, 'factor':2**-68, 'unit':utility.SECOND_PER_SECOND_SQUARED},

    {'name':"Rev",         'range':[840,853]},
    {'name':"CRC",         'range':[854,877]}]

BeiDouCNAV1DictType4 = [
    # Subframe 1
    {'name':"Prn",           'range':[0,5]},
    {'name':"SOH",           'range':[6,13],                   'factor':18,     'unit':utility.SECOND},
    
    # Subframe 2
    {'name':"WN",            'range':[14,26],                                    'unit':utility.WEEK},
    {'name':"HOW",           'range':[27,34],                                   'unit':utility.HOUR},
    {'name':"IODC",          'range':[35,44]},
    {'name':"IODE",          'range':[45,52]},
    # Ephemeris 1
    {'name':"toeSF2",        'range':[53,63],                  'factor':300,    'unit':utility.SECOND},
    {'name':"SatTypeSF2",    'range':[64,65]},
    {'name':"deltaASF2",     'range':[66,91],   'signed':True, 'factor':2**-9,  'unit':utility.METER},
    {'name':"AdotSF2",       'range':[92,116],  'signed':True, 'factor':2**-21, 'unit':utility.METER_PER_SECOND},
    {'name':"deltan0SF2",    'range':[117,133], 'signed':True, 'factor':2**-44, 'unit':utility.PI_PER_SECOND},
    {'name':"deltandot0SF2", 'range':[134,156], 'signed':True, 'factor':2**-57, 'unit':utility.PI_PER_SECOND_SQUARED},
    {'name':"M0SF2",         'range':[157,189], 'signed':True, 'factor':2**-32, 'unit':utility.PI},
    {'name':"eSF2",          'range':[190,222],                'factor':2**-34},
    {'name':"omegaSF2",      'range':[223,255], 'signed':True, 'factor':2**-32, 'unit':utility.PI},
    # Ephemeris 2
    {'name':"omega0SF2",     'range':[256,288], 'signed':True, 'factor':2**-32, 'unit':utility.PI},
    {'name':"i0",            'range':[289,321], 'signed':True, 'factor':2**-32, 'unit':utility.PI},
    {'name':"omegaDotSF2",   'range':[322,340], 'signed':True, 'factor':2**-44, 'unit':utility.PI_PER_SECOND},
    {'name':"idot0",         'range':[341,355], 'signed':True, 'factor':2**-44, 'unit':utility.PI_PER_SECOND},
    {'name':"Cis",           'range':[356,371], 'signed':True, 'factor':2**-30, 'unit':utility.RADIAN},
    {'name':"Cic",           'range':[372,387], 'signed':True, 'factor':2**-30, 'unit':utility.RADIAN},
    {'name':"Crs",           'range':[388,411], 'signed':True, 'factor':2**-8,  'unit':utility.METER},
    {'name':"Crc",           'range':[412,435], 'signed':True, 'factor':2**-8,  'unit':utility.METER},
    {'name':"Cus",           'range':[436,456], 'signed':True, 'factor':2**-30, 'unit':utility.RADIAN},
    {'name':"Cuc",           'range':[457,477], 'signed':True, 'factor':2**-30, 'unit':utility.RADIAN},
    # Clock correction  
    {'name':"toc",           'range':[478,488],                'factor':300,    'unit':utility.SECOND},
    {'name':"a0",            'range':[489,513], 'signed':True, 'factor':2**-34, 'unit':utility.SECOND},
    {'name':"a1",            'range':[514,535], 'signed':True, 'factor':2**-50, 'unit':utility.SECOND_PER_SECOND},
    {'name':"a2",            'range':[536,546], 'signed':True, 'factor':2**-66, 'unit':utility.SECOND_PER_SECOND_SQUARED},
  
    {'name':"TGDB2ap",       'range':[547,558], 'signed':True, 'factor':2**-34, 'unit':utility.SECOND},
    {'name':"ISCB1Cd",       'range':[559,570], 'signed':True, 'factor':2**-34, 'unit':utility.SECOND},
    {'name':"TGDB1Cp",       'range':[571,582], 'signed':True, 'factor':2**-34, 'unit':utility.SECOND},
    {'name':"RevSF2",        'range':[583,589]},
    {'name':"CRCSF2",        'range':[590,613]},

    # Subframe 3
    {'name':"PageID",   'range':[614,619]},
    {'name':"HS",       'range':[620,621]},
    {'name':"DIF",      'range':[622,622]},
    {'name':"SIF",      'range':[623,623]},
    {'name':"AIF",      'range':[624,624]},
    {'name':"SISMAI",   'range':[625,628]},
    # SISAIOC
    {'name':"top",      'range':[629,639]},
    {'name':"SISAIocb", 'range':[640,644]},
    {'name':"SISAIoc1", 'range':[645,647]},
    {'name':"SISAIoc2", 'range':[648,650]},
    # Midi almanac
    {'name':"PRNa",     'range':[651,656]},
    {'name':"SatType",  'range':[657,658]},
    {'name':"WNa",      'range':[659,671],                                    'unit':utility.WEEK},
    {'name':"toa",      'range':[672,679],                  'factor':2**12,   'unit':utility.SECOND},
    {'name':"e",        'range':[680,690],                  'factor':2**-16}, 
    {'name':"deltai",   'range':[691,701],   'signed':True, 'factor':2**-14,  'unit':utility.PI},
    {'name':"sqrtA",    'range':[702,718],                 'factor':2**-4,   'unit':utility.METER_SQUARE_ROOT},
    {'name':"omega0",   'range':[719,733], 'signed':True, 'factor':2**-15,  'unit':utility.PI},
    {'name':"omegaDot", 'range':[734,745], 'signed':True, 'factor':2**-33,  'unit':utility.PI_PER_SECOND},
    {'name':"omega",    'range':[746,761], 'signed':True, 'factor':2**-15,  'unit':utility.PI},
    {'name':"M0",       'range':[762,777], 'signed':True, 'factor':2**-15,  'unit':utility.PI},
    {'name':"af0",      'range':[778,788], 'signed':True, 'factor':2**-20,  'unit':utility.SECOND},
    {'name':"af1",      'range':[789,798], 'signed':True, 'factor':2**-37,  'unit':utility.SECOND_PER_SECOND},
    {'name':"health",   'range':[799,806]},

    {'name':"Rev",      'range':[807,853]},
    {'name':"CRC",      'range':[854,877]}]

BeiDouCNAV1Subframe3Types = {1:BeiDouCNAV1DictType1, 2:BeiDouCNAV1DictType2, 3:BeiDouCNAV1DictType3, 4:BeiDouCNAV1DictType4}

BeiDouCNAV2DictType10 = [
    {'name':"PRN",      'range':[0,5]},
    {'name':"MesType",  'range':[6,11]},
    {'name':"SOW",      'range':[12,29],                  'factor':3,       'unit':utility.SECOND},
    {'name':"WN",       'range':[30,42],                                    'unit':utility.WEEK},
    {'name':"DIF(B2a)", 'range':[43,43]},
    {'name':"SIF(B2a)", 'range':[44,44]},
    {'name':"AIF(B2a)", 'range':[45,45]},
    {'name':"SISMAI",   'range':[46,49]},
    {'name':"DIF(B1C)", 'range':[50,50]},
    {'name':"SIF(B1C)", 'range':[51,51]},
    {'name':"AIF(B1C)", 'range':[52,52]},
    {'name':"IODE",     'range':[53,60]},
    #Start of Ephemeris 1
    {'name':"toe",      'range':[61,71],                  'factor':300,     'unit':utility.SECOND},
    {'name':"SatType",  'range':[72,73],},
    {'name':"DeltaA",   'range':[74,99],   'signed':True, 'factor':2**-9,   'unit':utility.METER},
    {'name':"ADot",     'range':[100,124], 'signed':True, 'factor':2**-21,  'unit':utility.METER_PER_SECOND},
    {'name':"Deltan0",  'range':[125,141], 'signed':True, 'factor':2**-44,  'unit':utility.PI_PER_SECOND},
    {'name':"Deltan0Dot",'range':[142,164],'signed':True, 'factor':2**-57,  'unit':utility.PI_PER_SECOND_SQUARED},
    {'name':"M0",       'range':[165,197], 'signed':True, 'factor':2**-32,  'unit':utility.PI},
    {'name':"e",        'range':[198,230],                'factor':2**-34},
    {'name':"omega",    'range':[231,263], 'signed':True, 'factor':2**-32,  'unit':utility.PI},
    #End of Ephemeris 1
    {'name':"CRC",      'range':[264,287]}]

BeiDouCNAV2DictType11 = [
    {'name':"PRN",      'range':[0,5]},
    {'name':"MesType",  'range':[6,11]},
    {'name':"SOW",      'range':[12,29],                  'factor':3,       'unit':utility.SECOND},
    {'name':"HS",       'range':[30,31]},
    {'name':"DIF(B2a)", 'range':[32,32]},
    {'name':"SIF(B2a)", 'range':[33,33]},
    {'name':"AIF(B2a)", 'range':[34,34]},
    {'name':"SISMAI",   'range':[35,38]},
    {'name':"DIF(B1C)", 'range':[39,39]},
    {'name':"SIF(B1C)", 'range':[40,40]},
    {'name':"AIF(B1C)", 'range':[41,41]},
    #Start of Ephemeris 2
    {'name':"Omega0",   'range':[42,74],   'signed':True, 'factor':2**-32,  'unit':utility.PI},
    {'name':"i0",       'range':[75,107],  'signed':True, 'factor':2**-32,  'unit':utility.PI},
    {'name':"OmegaDot", 'range':[108,126], 'signed':True, 'factor':2**-44,  'unit':utility.PI_PER_SECOND},
    {'name':"i0Dot",    'range':[127,141], 'signed':True, 'factor':2**-44,  'unit':utility.PI_PER_SECOND},
    {'name':"Cis",      'range':[142,157], 'signed':True, 'factor':2**-30,  'unit':utility.RADIAN},
    {'name':"Cic",      'range':[158,173], 'signed':True, 'factor':2**-30,  'unit':utility.RADIAN},
    {'name':"Crs",      'range':[174,197], 'signed':True, 'factor':2**-8,   'unit':utility.METER},
    {'name':"Crc",      'range':[198,221], 'signed':True, 'factor':2**-8,   'unit':utility.METER},
    {'name':"Cus",      'range':[222,242], 'signed':True, 'factor':2**-30,  'unit':utility.RADIAN},
    {'name':"Cuc",      'range':[243,263], 'signed':True, 'factor':2**-30,  'unit':utility.RADIAN},
    #End of Ephemeris 2
    {'name':"CRC",      'range':[264,287]}]

BeiDouCNAV2DictType30 = [
    {'name':"PRN",      'range':[0,5]},
    {'name':"MesType",  'range':[6,11]},
    {'name':"SOW",      'range':[12,29],                  'factor':3,       'unit':utility.SECOND},
    {'name':"HS",       'range':[30,31]},
    {'name':"DIF(B2a)", 'range':[32,32]},
    {'name':"SIF(B2a)", 'range':[33,33]},
    {'name':"AIF(B2a)", 'range':[34,34]},
    {'name':"SISMAI",   'range':[35,38]},
    {'name':"DIF(B1C)", 'range':[39,39]},
    {'name':"SIF(B1C)", 'range':[40,40]},
    {'name':"AIF(B1C)", 'range':[41,41]},
    #Start of clock correction params
    {'name':"toc",      'range':[42,52],                  'factor':300,     'unit':utility.SECOND},
    {'name':"a0",       'range':[53,77],   'signed':True, 'factor':2**-34,  'unit':utility.SECOND},
    {'name':"a1",       'range':[78,99],   'signed':True, 'factor':2**-50,  'unit':utility.SECOND_PER_SECOND},
    {'name':"a2",       'range':[100,110], 'signed':True, 'factor':2**-66,  'unit':utility.SECOND_PER_SECOND_SQUARED},
    #End of clock correction params
    {'name':"IODC",     'range':[111,120]},
    {'name':"T-GDB2ap", 'range':[121,132], 'signed':True, 'factor':2**-34,  'unit':utility.SECOND},
    {'name':"ISC-B2ad", 'range':[133,144], 'signed':True, 'factor':2**-34,  'unit':utility.SECOND},
    #Start of Ionospheric delay correction model params
    {'name':"alpha1",   'range':[145,154], 'signed':True, 'factor':2**-3,   'unit':utility.TEC_U},
    {'name':"alpha2",   'range':[155,162], 'signed':True, 'factor':2**-3,   'unit':utility.TEC_U},
    {'name':"alpha3",   'range':[163,170], 'signed':True, 'factor':2**-3,   'unit':utility.TEC_U},
    {'name':"alpha4",   'range':[171,178], 'signed':True, 'factor':2**-3,   'unit':utility.TEC_U},
    {'name':"alpha5",   'range':[179,186], 'signed':True, 'factor':2**-3,   'unit':utility.TEC_U},
    {'name':"alpha6",   'range':[187,194], 'signed':True, 'factor':2**-3,   'unit':utility.TEC_U},
    {'name':"alpha7",   'range':[195,202], 'signed':True, 'factor':2**-3,   'unit':utility.TEC_U},
    {'name':"alpha8",   'range':[203,210], 'signed':True, 'factor':2**-3,   'unit':utility.TEC_U},
    {'name':"alpha9",   'range':[211,218], 'signed':True, 'factor':2**-3,   'unit':utility.TEC_U},
    #End of Ionospheric delay correction model params
    {'name':"T-GDB1Cp", 'range':[219,230], 'signed':True, 'factor':2**-34,  'unit':utility.SECOND},
    {'name':"Rev",      'range':[231,263]},
    {'name':"CRC",      'range':[264,287]}]

BeiDouCNAV2DictType31 = [
    {'name':"PRN",      'range':[0,5]},
    {'name':"MesType",  'range':[6,11]},
    {'name':"SOW",      'range':[12,29],                  'factor':3,       'unit':utility.SECOND},
    {'name':"HS",       'range':[30,31]},
    {'name':"DIF(B2a)", 'range':[32,32]},
    {'name':"SIF(B2a)", 'range':[33,33]},
    {'name':"AIF(B2a)", 'range':[34,34]},
    {'name':"SISMAI",   'range':[35,38]},
    {'name':"DIF(B1C)", 'range':[39,39]},
    {'name':"SIF(B1C)", 'range':[40,40]},
    {'name':"AIF(B1C)", 'range':[41,41]},
    #Start of clock correction params
    {'name':"toc",      'range':[42,52],                  'factor':300,     'unit':utility.SECOND},
    {'name':"a0",       'range':[53,77],   'signed':True, 'factor':2**-34,  'unit':utility.SECOND},
    {'name':"a1",       'range':[78,99],   'signed':True, 'factor':2**-50,  'unit':utility.SECOND_PER_SECOND},
    {'name':"a2",       'range':[100,110], 'signed':True, 'factor':2**-66,  'unit':utility.SECOND_PER_SECOND_SQUARED},
    #End of clock correction params
    {'name':"IODC",     'range':[111,120]},
    {'name':"WNa",      'range':[121,133],                                  'unit':utility.WEEK},
    {'name':"toa",      'range':[134,141],                'factor':2**12,   'unit':utility.SECOND},
    #Start of Reduced almanac 1
    {'name':"PRNA1",     'range':[142,147]},
    {'name':"SatType1",  'range':[148,149]},
    {'name':"deltaA1",   'range':[150,157], 'signed':True, 'factor':2**9,    'unit':utility.METER},
    {'name':"Omega01",   'range':[158,164], 'signed':True, 'factor':2**-6,   'unit':utility.PI},
    {'name':"Phi01",     'range':[165,171], 'signed':True, 'factor':2**-6,   'unit':utility.PI},
    {'name':"Health1",   'range':[172,179]},
    #End of Reduced alamnac 1
    #Start of Reduced almanac 2
    {'name':"PRNA",     'range':[180,185]},
    {'name':"SatType",  'range':[186,187]},
    {'name':"deltaA",   'range':[188,195], 'signed':True, 'factor':2**9,    'unit':utility.METER},
    {'name':"Omega0",   'range':[196,202], 'signed':True, 'factor':2**-6,   'unit':utility.PI},
    {'name':"Phi0",     'range':[203,209], 'signed':True, 'factor':2**-6,   'unit':utility.PI},
    {'name':"Health",   'range':[210,217]},
    #End of Reduced alamnac 2
    #Start of Reduced almanac 3
    {'name':"PRNA",     'range':[218,223]},
    {'name':"SatType",  'range':[224,225]},
    {'name':"deltaA",   'range':[226,233], 'signed':True, 'factor':2**9,    'unit':utility.METER},
    {'name':"Omega0",   'range':[234,240], 'signed':True, 'factor':2**-6,   'unit':utility.PI},
    {'name':"Phi0",     'range':[241,247], 'signed':True, 'factor':2**-6,   'unit':utility.PI},
    {'name':"Health",   'range':[248,255]},
    #End of Reduced alamnac 3
    {'name':"Rev",      'range':[256,263]},
    {'name':"CRC",      'range':[264,287]}]

BeiDouCNAV2DictType32 = [
    {'name':"PRN",      'range':[0,5]},
    {'name':"MesType",  'range':[6,11]},
    {'name':"SOW",      'range':[12,29],                  'factor':3,       'unit':utility.SECOND},
    {'name':"HS",       'range':[30,31]},
    {'name':"DIF(B2a)", 'range':[32,32]},
    {'name':"SIF(B2a)", 'range':[33,33]},
    {'name':"AIF(B2a)", 'range':[34,34]},
    {'name':"SISMAI",   'range':[35,38]},
    {'name':"DIF(B1C)", 'range':[39,39]},
    {'name':"SIF(B1C)", 'range':[40,40]},
    {'name':"AIF(B1C)", 'range':[41,41]},
    #Start of clock correction params
    {'name':"toc",      'range':[42,52],                  'factor':300,     'unit':utility.SECOND},
    {'name':"a0",       'range':[53,77],   'signed':True, 'factor':2**-34,  'unit':utility.SECOND},
    {'name':"a1",       'range':[78,99],   'signed':True, 'factor':2**-50,  'unit':utility.SECOND_PER_SECOND},
    {'name':"a2",       'range':[100,110], 'signed':True, 'factor':2**-66,  'unit':utility.SECOND_PER_SECOND_SQUARED},
    #End of clock correction params
    {'name':"IODC",     'range':[111,120]},
    #Start of EOP params
    {'name':"tEOP",     'range':[121,136],                'factor':2**4,    'unit':utility.SECOND},
    {'name':"PM_X",     'range':[137,157], 'signed':True, 'factor':2**-20,  'unit':utility.ARC_SECOND},
    {'name':"PM_XDot",  'range':[158,172], 'signed':True, 'factor':2**-21,  'unit':utility.ARC_SECOND_PER_DAY},
    {'name':"PM_Y",     'range':[173,193], 'signed':True, 'factor':2**-20,  'unit':utility.ARC_SECOND},
    {'name':"PM_YDot",  'range':[194,208], 'signed':True, 'factor':2**-21,  'unit':utility.ARC_SECOND_PER_DAY},
    {'name':"DeltaUT1", 'range':[210,239], 'signed':True, 'factor':2**-24,  'unit':utility.SECOND},
    {'name':"DeltaUT1Dot", 'range':[240,258], 'signed':True, 'factor':2**-25,   'unit':utility.SECOND_PER_DAY},
    #End of EOP params
    {'name':"Rev",      'range':[259,263]},
    {'name':"CRC",      'range':[264,287]}]

BeiDouCNAV2DictType33 = [
    {'name':"PRN",      'range':[0,5]},
    {'name':"MesType",  'range':[6,11]},
    {'name':"SOW",      'range':[12,29],                  'factor':3,       'unit':utility.SECOND},
    {'name':"HS",       'range':[30,31]},
    {'name':"DIF(B2a)", 'range':[32,32]},
    {'name':"SIF(B2a)", 'range':[33,33]},
    {'name':"AIF(B2a)", 'range':[34,34]},
    {'name':"SISMAI",   'range':[35,38]},
    {'name':"DIF(B1C)", 'range':[39,39]},
    {'name':"SIF(B1C)", 'range':[40,40]},
    {'name':"AIF(B1C)", 'range':[41,41]},
    #Start of clock correction params
    {'name':"toc",      'range':[42,52],                  'factor':300,     'unit':utility.SECOND},
    {'name':"a0",       'range':[53,77],   'signed':True, 'factor':2**-34,  'unit':utility.SECOND},
    {'name':"a1",       'range':[78,99],   'signed':True, 'factor':2**-50,  'unit':utility.SECOND_PER_SECOND},
    {'name':"a2",       'range':[100,110], 'signed':True, 'factor':2**-66,  'unit':utility.SECOND_PER_SECOND_SQUARED},
    #End of clock correction params
    #Start of BGTO params
    {'name':"GNSS ID",  'range':[111,113]},
    {'name':"WN0BGTO",  'range':[114,126],                                  'unit':utility.WEEK},
    {'name':"t0BGTO",   'range':[127,142],                'factor':2**4,    'unit':utility.SECOND},
    {'name':"A0BGTO",   'range':[143,158], 'signed':True, 'factor':2**-35,  'unit':utility.SECOND},
    {'name':"A1BGTO",   'range':[159,171], 'signed':True, 'factor':2**-51,  'unit':utility.SECOND_PER_SECOND},
    {'name':"A2BGTO",   'range':[172,178], 'signed':True, 'factor':2**-68,  'unit':utility.SECOND_PER_SECOND_SQUARED},
    #End of BGTO params
    #Start of Reduced Almanac
    {'name':"PRNA",     'range':[179,184]},
    {'name':"SatType",  'range':[185,186]},
    {'name':"deltaA",   'range':[187,194], 'signed':True, 'factor':2**9,    'unit':utility.METER},
    {'name':"Omega0",   'range':[195,201], 'signed':True, 'factor':2**-6,   'unit':utility.PI},
    {'name':"Phi0",     'range':[202,208], 'signed':True, 'factor':2**-6,   'unit':utility.PI},
    {'name':"Health",   'range':[209,216]},
    #End of Reduced alamnac 2
    {'name':"IODC",     'range':[217,226]}, 
    {'name':"WNa",      'range':[227,239],                                  'unit':utility.WEEK},
    {'name':"toa",      'range':[240,247],                 'factor':2**12,  'unit':utility.SECOND},
    {'name':"Rev",      'range':[248,263]},
    {'name':"CRC",      'range':[264,287]}]

BeiDouCNAV2DictType34 = [
    {'name':"PRN",      'range':[0,5]},
    {'name':"MesType",  'range':[6,11]},
    {'name':"SOW",      'range':[12,29],                  'factor':3,       'unit':utility.SECOND},
    {'name':"HS",       'range':[30,31]},
    {'name':"DIF(B2a)", 'range':[32,32]},
    {'name':"SIF(B2a)", 'range':[33,33]},
    {'name':"AIF(B2a)", 'range':[34,34]},
    {'name':"SISMAI",   'range':[35,38]},
    {'name':"DIF(B1C)", 'range':[39,39]},
    {'name':"SIF(B1C)", 'range':[40,40]},
    {'name':"AIF(B1C)", 'range':[41,41]},
    #Start of SISAIoc
    {'name':"top",      'range':[42,52]},
    {'name':"SISAIocb", 'range':[53,57]},
    {'name':"SISAIoc1", 'range':[58,60]},
    {'name':"SISAIoc2", 'range':[61,63]},
    #End of SISAIoc
    #Start of Clock correction params
    {'name':"toc",      'range':[64,74],                  'factor':300,     'unit':utility.SECOND},
    {'name':"a0",       'range':[75,99],   'signed':True, 'factor':2**-34,  'unit':utility.SECOND},
    {'name':"a1",       'range':[100,121], 'signed':True, 'factor':2**-50,  'unit':utility.SECOND_PER_SECOND},
    {'name':"a2",       'range':[122,132], 'signed':True, 'factor':2**-66,  'unit':utility.SECOND_PER_SECOND_SQUARED},
    #End of Clock correction params
    {'name':"IODC",     'range':[133,142]}, 
    #Start of BDT-UTC time offset parameters
    {'name':"A0UTC",    'range':[143,158], 'signed':True, 'factor':2**-35,  'unit':utility.SECOND},
    {'name':"A1UTC",    'range':[159,171], 'signed':True, 'factor':2**-51,  'unit':utility.SECOND_PER_SECOND},
    {'name':"A2UTC",    'range':[172,178], 'signed':True, 'factor':2**-68,  'unit':utility.SECOND_PER_SECOND_SQUARED},
    {'name':"DeltatLS", 'range':[179,186], 'signed':True,                   'unit':utility.SECOND},
    {'name':"tot",      'range':[187,202],                'factor':2**4,    'unit':utility.SECOND},
    {'name':"WNot",     'range':[203,215],                                  'unit':utility.WEEK},
    {'name':"WNLSF",    'range':[216,228],                                  'unit':utility.WEEK},
    {'name':"DN",       'range':[229,231],                                  'unit':utility.DAY},
    {'name':"DeltatLSF",'range':[232,239], 'signed':True,                   'unit':utility.SECOND},
    #End of BDT-UTC time offset parameters
    {'name':"Rev",      'range':[240,263]},
    {'name':"CRC",      'range':[264,287]}]

BeiDouCNAV2DictType40 = [
    {'name':"PRN",      'range':[0,5]},
    {'name':"MesType",  'range':[6,11]},
    {'name':"SOW",      'range':[12,29],                  'factor':3,       'unit':utility.SECOND},
    {'name':"HS",       'range':[30,31]},
    {'name':"DIF(B2a)", 'range':[32,32]},
    {'name':"SIF(B2a)", 'range':[33,33]},
    {'name':"AIF(B2a)", 'range':[34,34]},
    {'name':"SISMAI",   'range':[35,38]},
    {'name':"DIF(B1C)", 'range':[39,39]},
    {'name':"SIF(B1C)", 'range':[40,40]},
    {'name':"AIF(B1C)", 'range':[41,41]},
    {'name':"SISAIoe",  'range':[42,46]},
    #Start of SISAIoc
    {'name':"top",      'range':[47,57]},
    {'name':"SISAIocb", 'range':[58,62]},
    {'name':"SISAIoc1", 'range':[63,65]},
    {'name':"SISAIoc2", 'range':[66,68]},
    #End of SISAIoc
    #Start of Midi almanac
    {'name':"PRNa",     'range':[69,74]},
    {'name':"SatType",  'range':[75,76]},
    {'name':"WNa",      'range':[77,89],                                    'unit':utility.WEEK},
    {'name':"toa",      'range':[90,97],                  'factor':2**12,   'unit':utility.SECOND},
    {'name':"e",        'range':[99,108],                 'factor':2**-16},
    {'name':"deltai",   'range':[109,119], 'signed':True, 'factor':2**-14,  'unit':utility.PI},
    {'name':"sqrtA",    'range':[120,136],                'factor':2**-4,   'unit':utility.METER_SQUARE_ROOT},
    {'name':"Omega0",   'range':[137,152], 'signed':True, 'factor':2**-15,  'unit':utility.PI},
    {'name':"OmdegaDot",'range':[153,163], 'signed':True, 'factor':2**-33,  'unit':utility.PI_PER_SECOND},
    {'name':"omega",    'range':[164,179], 'signed':True, 'factor':2**-15,  'unit':utility.PI},
    {'name':"M0",       'range':[180,195], 'signed':True, 'factor':2**-15,  'unit':utility.PI},
    {'name':"af0",      'range':[196,206], 'signed':True, 'factor':2**-20,  'unit':utility.SECOND},
    {'name':"af1",      'range':[207,216], 'signed':True, 'factor':2**-37,  'unit':utility.SECOND_PER_SECOND},
    {'name':"Health",   'range':[217,224],                                  'unit':utility.SECOND},
    #End of Midi almanac
    {'name':"Rev",      'range':[225,263]},
    {'name':"CRC",      'range':[264,287]}]

BeiDouCNAV2DictTypes = {10:BeiDouCNAV2DictType10, 11:BeiDouCNAV2DictType11, 30:BeiDouCNAV2DictType30, 31:BeiDouCNAV2DictType31, 32:BeiDouCNAV2DictType32, 33:BeiDouCNAV2DictType33, 34:BeiDouCNAV2DictType34, 40:BeiDouCNAV2DictType40}


"""
    Main functions for decoding a BeiDou downlink navigation message.
"""

def decodeBeiDouNavigationMessageInBinary(message):
    words = message.split(" ")
    decodedMessage = bin(int(words[0], 16))[2:].zfill(utility.WORD_SIZE)[2:]
    for word in words[1:]:
        word    = bin(int(word, 16))[2:].zfill(utility.WORD_SIZE)
        decodedMessage = decodedMessage + word[2:23:2] + word[3:24:2] + word[24:31:2] +  word[25:32:2]
    return decodedMessage

def getBeiDouNavigationMessageInBinary(message):
    words = message.split(" ")
    decodedMessage = ''
    for word in words[0:]:
        word = bin(int(word, 16))[2:].zfill(utility.WORD_SIZE)
        decodedMessage = decodedMessage + word[2:] # Remove padding at the start of the word
    return decodedMessage

def decodeBeiDouCNAV1NavigationMessageInBinary(message):
    # Total message length : 1800 bits
    # Closest multiple of 32 : 1824
    binaryMessage = utility.convertToBinaryNavigationMessage(message, 1824)
    
    # Build subframe 1
    subframe1 = binaryMessage[0:14]
    # We don't need the parity bits
    subframe2And3 = binaryMessage[72:1800]

    # Revert interleaving
    subframe2 = ""
    subframe3 = ""
    for row in range(36):
        tmpRow = ""
        for column in range(48):
            tmpRow = tmpRow + subframe2And3[row + column * 36]
        
        # Build subframe 2 and 3
        if row >= 33 or row % 3 != 2:
            subframe2 = subframe2 + tmpRow
        else:
            subframe3 = subframe3 + tmpRow

    # Build frame
    return subframe1 + subframe2[0:600] + subframe3[0:264]

def decodeBeiDouCNAV2NavigationMessageInBinary(message):
    print("converting to binary")
    #Septenrio messages are only 576 bits long: they don't include the preamble: probbably will need to change this function for other sources
    binaryMessage = utility.convertToBinaryNavigationMessage(message, 576)
    print("Complete binary message: " + str(binaryMessage))
    # Get preamble
    #preamble = binaryMessage[8:32]
    # We don't need the parity bits
    LDPCmsg = binaryMessage[0:288]
    LDPCcheck = binaryMessage[288:576]
    #Do proper decode using check bits here if needed
    # if hex(int(preamble,2)) == '0xE24DE8':
    #     return LDPCmsg
    return LDPCmsg

def getDictBeiDouB1D1NavigationMessage(binaryMessage):
    dictToUse = {}
    sfID = int(binaryMessage[15:18], 2)
    if sfID in D1DictEphemeris:
        dictToUse = D1DictEphemeris[sfID]
    elif sfID == 5:
        pageID = int(binaryMessage[43:50], 2)
        if 1 <= pageID <= 6:
            dictToUse = D1DictAlmanac
        elif pageID == 7:
            dictToUse = D1DictHealthA
        elif pageID == 8:
            dictToUse = D1DictHealthB
        elif pageID == 9:
            dictToUse = D1DictGNSSTime
        elif pageID == 10:
            dictToUse =  D1DictUTCTime
        elif 11 <= pageID <= 23:
            dictToUse = D1DictAlmanacSF5
        elif pageID == 24:
            dictToUse = D1DictHealthC
        else:
            dictToUse = D1DictPlaceholder
    else:
        return dictToUse

    return utility.fillDict(binaryMessage, dictToUse)

def getDictBeiDouB1D2NavigationMessage(binaryMessage):
    dictToUse = {}
    sfID = int(binaryMessage[15:18], 2)
    if sfID == 1:
        pageID = int(binaryMessage[42:46], 2)
        if pageID == 1:
            dictToUse = D2DictSf1Page1
        elif pageID == 2:
            dictToUse = D2DictSf1Page2
        elif pageID == 3:
            dictToUse = D2DictSf1Page3
        elif pageID == 4:
            dictToUse = D2DictSf1Page4
        elif pageID == 5:
            dictToUse = D2DictSf1Page5
        elif pageID == 6:
            dictToUse = D2DictSf1Page6
        elif pageID == 7:
            dictToUse = D2DictSf1Page7
        elif pageID == 8:
            dictToUse = D2DictSf1Page8
        elif pageID == 9:
            dictToUse = D2DictSf1Page9
        elif pageID == 10:
            dictToUse = D2DictSf1Page10
    elif sfID == 2:
        dictToUse = D2DictSf2
    elif sfID == 3:
        dictToUse = D2DictSf3
    elif sfID == 4:
        dictToUse = D2DictSf4
    elif sfID == 5:
        pageID = int(binaryMessage[43:50], 2)
        if pageID in range(1, 13) or pageID in range(61, 73):
            dictToUse = D2DictSf5IonoGridA
        elif pageID in [13, 73]:
            dictToUse = D2DictSf5IonoGridB
        elif pageID in range(37, 61) or pageID in range(95, 101):
            dictToUse = D2DictSf5Almanac
        elif pageID == 35:
            dictToUse = D2DictSf5HealthA
        elif pageID == 36:
            dictToUse = D2DictSf5HealthB
        elif pageID == 101:
            dictToUse = D2DictSf5GNSSTime
        elif pageID == 102:
            dictToUse = D2DictSf5UTCTime
        elif 103 <= pageID <= 115:
            dictToUse = D2DictSf5Almanac2
        elif pageID == 116:
            dictToUse = D2DictSf5HealthC
        elif pageID in range(14, 35) or pageID in range(74, 95) or pageID in range(103, 121):
            dictToUse = D2DictSf5Reserved
    else:
        return dictToUse

    return utility.fillDict(binaryMessage, dictToUse)

def getDictBeiDouB1D1EncodedNavigationMessage(message):
    binaryMessage = decodeBeiDouNavigationMessageInBinary(message)
    return getDictBeiDouB1D1NavigationMessage(binaryMessage)

def getDictBeiDouB1D1DecodedNavigationMessage(message):
    binaryMessage = getBeiDouNavigationMessageInBinary(message)
    return getDictBeiDouB1D1NavigationMessage(binaryMessage)

def getDictBeiDouB1D2EncodedNavigationMessage(message):
    binaryMessage = decodeBeiDouNavigationMessageInBinary(message)
    return getDictBeiDouB1D2NavigationMessage(binaryMessage)

def getDictBeiDouB1D2DecodedNavigationMessage(message):
    binaryMessage = getBeiDouNavigationMessageInBinary(message)
    return getDictBeiDouB1D2NavigationMessage(binaryMessage)

def getDictBeiDouCNAV1DecodedNavigationMessage(message):
    msg = utility.convertToBinaryNavigationMessage(message, 896)
    return getDictBeiDouCNAV1NavigationMessage(msg)

def getDictBeiDouCNAV1EncodedNavigationMessage(message):
    msg = decodeBeiDouCNAV1NavigationMessageInBinary(message)
    return getDictBeiDouCNAV1NavigationMessage(msg)

def getDictBeiDouCNAV1PartialNavigationMessage(message):
    tmp = utility.convertToBinaryNavigationMessage(message, 1824)
    msg = tmp[0:6] + tmp[21:29] + tmp[72:672] + tmp[1272:1536]
    return getDictBeiDouCNAV1NavigationMessage(msg)

def getDictBeiDouCNAV2DecodedNavigationMessage(message):
    msg = utility.convertToBinaryNavigationMessage(message, 288)
    return getDictBeiDouCNAV2NavigationMessage(msg)

def getDictBeiDouCNAV2EncodedNavigationMessage(message):
    msg = decodeBeiDouCNAV2NavigationMessageInBinary(message)
    return getDictBeiDouCNAV2NavigationMessage(msg)

def getDictBeiDouCNAV1NavigationMessage(message):
    dictToUse = {}

    pageId = int(message[614:620], 2)
    if pageId > 0 and pageId <= 4:
        dictToUse = BeiDouCNAV1Subframe3Types[pageId]
    return utility.fillDict(message, dictToUse)

def getDictBeiDouCNAV2NavigationMessage(message):
    print("Starting message read")
    dictToUse = {}

    MesType = int(message[6:12],2)

    if MesType in [10,11,30,31,32,33,34,40]:
        print("message type recognized: " + str(MesType))
        dictToUse = BeiDouCNAV2DictTypes[MesType]
    return utility.fillDict(message, dictToUse)
