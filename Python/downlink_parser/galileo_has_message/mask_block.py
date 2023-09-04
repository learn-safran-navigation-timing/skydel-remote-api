GNSS_ID = {0: "GPS", 2: "GALILEO"}

SIGNAL_MASK = {0:["L1C/A", "Reserved", "Reserved", "L1C(D)", "L1C(P)", "L1C(D+P)", "L2 CM", "L2 CL", "L2 CM+CL", "L2 P", "Reserved", "L5 I", "L5 Q", "L5 I + L5 Q", "Reserved", "Reserved"],
               2:["E1-B I/NAV OS","E1-C","E1-B + E1-C","E5a-I F/NAV OS","E5a-Q","E5a-I+E5a-Q","E5b-I I/NAV OS","E5b-Q","E5b-I+E5b-Q","E5-I","E5-Q","E5-I + E5-Q", "E6-B C/NAV HAS", "E6-C", "E6-B + E6-C" , "Reserved"]
              }

def satelliteMask(msg, sys):
    mask = []
    svID = 1
    satellite_mask = msg[f'satellite_mask {sys}']['binary']
    for index in range(len(satellite_mask)):
        if (int(satellite_mask[index]) == 1):
            mask.append(svID)
        svID = svID + 1

    return mask

def signalMask(msg, sys, gnssID):
    mask = []
    signal = 1
    signal_mask = msg[f'signal_mask {sys}']['binary']
    for index in range(len(signal_mask)):
        if (int(signal_mask[index]) == 1):
            mask.append(SIGNAL_MASK[gnssID][signal - 1])
        signal = signal + 1

    return mask

def cellMask(msg, sys, gnssID):
    mask = []

    satellite_mask = msg[f'satellite_mask {sys}']['binary']
    signal_mask = msg[f'signal_mask {sys}']['binary']

    svID = 1
    for sat in range(len(satellite_mask)):
        if (int(satellite_mask[sat]) == 1):
            signal = 1
            for sig in range(len(signal_mask)):
                if (int(signal_mask[sig]) == 1):
                    mask.append({'sat': svID, 'sig': SIGNAL_MASK[gnssID][signal - 1]})
                signal = signal + 1
        svID = svID + 1

    return mask

def maskBlock(msg, sys):
    gnssID = int(msg[f'gnss_id {sys}']['decimal'])
    return {'gnss_id': GNSS_ID[gnssID],
            'satellite_mask': satelliteMask(msg, sys),
            'signal_mask': signalMask(msg, sys, gnssID),
            'cell_mask': cellMask(msg, sys, gnssID),
            'nav_message': msg[f'nav message {sys}']['decimal']
            }       

def mask(msg):
    n_sys = int(msg['n_sys']['decimal'])
    mask_per_sys = []

    for sys in range(1, n_sys + 1):
        mask_per_sys.append(maskBlock(msg, sys))

    return {'mask' : 
            {'n_sys' : n_sys,
             'mask_per_sys' : mask_per_sys,
             'reserved': msg['mask block reserved']['decimal']
            }}

def handleMaskBlock(gen):
    nsys = gen.getParameterValue(4)
    gen.addParametertoDict('n_sys', 4)
    satCounts = []
    sigCounts = []
    for sys in range(1, nsys + 1):
        gen.addParametertoDict('gnss_id {0}'.format(sys), 4)
        satM = gen.getParameterValue(40)
        gen.addParametertoDict('satellite_mask {0}'.format(sys), 40)
        sigM = gen.getParameterValue(16)
        gen.addParametertoDict('signal_mask {0}'.format(sys), 16)
        gen.addParametertoDict('cell_mask {0}'.format(sys), 1)
        satCount = bin(satM).count('1')
        sigCount = bin(sigM).count('1')
        for sat in range(1, satCount + 1):
            for sig in range(1, sigCount + 1):
                gen.addParametertoDict('cell_mask {0} sat{1} sig{2}'.format(sys, sat, sig), 1)
        gen.addParametertoDict('nav message {0}'.format(sys), 3)
        satCounts.append(satCount)
        sigCounts.append(sigCount)
    gen.addParametertoDict('mask block reserved', 6)

    return nsys, satCounts, sigCounts
