import utility

GNSS_ID = {0: "GPS", 2: "GALILEO"}

def clockBlock(msg, sys):
    gnssID = int(msg[f'gnss_id {sys}']['decimal'])
    satellite_mask = msg[f'satellite_mask {sys}']['binary']

    clocks_per_sat = []
    svID = 1
    for sat in range(len(satellite_mask)):
        if (int(satellite_mask[sat]) == 1):
            clocks_per_sat.append({ 
                'sat': svID,
                'delta_clock_c0': msg[f'delta_clock_c0 sys{sys} sat{svID}']['decimal']
             })
        svID = svID + 1

    return {'gnss_id': GNSS_ID[gnssID],
            'delta_clock_c0_multiplier': int(msg[f'delta_clock_c0_multiplier {sys}']['decimal']) + 1,
            'clocks_per_sat': clocks_per_sat
            } 

def clock(msg):
    vi = int(msg['clock_validity_interval_index']['decimal'])

    clocks_per_sys = []
    for sys in range(1, int(msg['n_sys']['decimal']) + 1):
        clocks_per_sys.append(clockBlock(msg, sys))

    return {'clock_fullset_corrections' : 
            {'validity_interval_index' : vi,
                'clocks_per_sys': clocks_per_sys
            }}

def handleClockBlock(gen, nsys, satCounts):
    gen.addParametertoDict('clock_validity_interval_index', 4)
    for sys in range(1, nsys + 1):
        gen.addParametertoDict("delta_clock_c0_multiplier {0}".format(sys), 2)
    for sys in range(1, nsys + 1):
        for sat in range(1, satCounts[sys - 1] + 1):
            gen.addParametertoDict("delta_clock_c0 sys{0} sat{1}".format(sys, sat), 13, True, 0.0025, utility.METER)
