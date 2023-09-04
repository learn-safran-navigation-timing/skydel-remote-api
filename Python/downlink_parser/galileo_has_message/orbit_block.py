import utility

GNSS_ID = {0: "GPS", 2: "GALILEO"}

def orbitBlock(msg, sys):
    gnssID = int(msg[f'gnss_id {sys}']['decimal'])
    satellite_mask = msg[f'satellite_mask {sys}']['binary']

    orbits_per_sat = []
    svID = 1
    for sat in range(len(satellite_mask)):
        if (int(satellite_mask[sat]) == 1):
            orbits_per_sat.append({ 
                'sat': svID,
                'iod': msg[f'iod sys{sys} sat{svID}']['decimal'],
                'delta_radial': msg[f'dr sys{sys} sat{svID}']['decimal'],
                'delta_intrack': msg[f'dit sys{sys} sat{svID}']['decimal'],
                'delta_crosstrack': msg[f'dct sys{sys} sat{svID}']['decimal']
             })
        svID = svID + 1

    return {'gnss_id': GNSS_ID[gnssID],
            'orbits_per_sat': orbits_per_sat
            }  

def orbit(msg):
    vi = int(msg['orbit_validity_interval_index']['decimal'])

    orbits_per_sys = []
    for sys in range(1, int(msg['n_sys']['decimal']) + 1):
        orbits_per_sys.append(orbitBlock(msg, sys))

    return {'orbit_corrections' : 
            {'validity_interval_index' : vi,
             'orbits_per_sys': orbits_per_sys
            }}

def getIODSize(nsys, sys):
    if nsys == 1 or sys == 2:
        return 10
    else:
        return 8

def handleOrbitBlock(gen, nsys, satCounts):
    gen.addParametertoDict('orbit_validity_interval_index', 4)
    for sys in range(1, nsys + 1):
        for sat in range(1, satCounts[sys - 1] + 1):
            gen.addParametertoDict("iod sys{0} sat{1}".format(sys, sat), getIODSize(nsys, sys))
            gen.addParametertoDict("dr sys{0} sat{1}".format(sys, sat), 13, True, 0.0025, utility.METER)
            gen.addParametertoDict("dit sys{0} sat{1}".format(sys, sat), 12, True, 0.0080, utility.METER)
            gen.addParametertoDict("dct sys{0} sat{1}".format(sys, sat), 12, True, 0.0080, utility.METER)
