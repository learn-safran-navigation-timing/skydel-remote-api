from .qzss_clas_utils import *
from .orbit_message import handleOrbitMessagePerSat, orbitMessagePerSat
from .clock_message import handleClockMessagePerSat, clockMessagePerSat


def combinedMessagePerSys(msg, sys, multiplicity, orbitFlag, clockFlag):
    gnssID = int(msg[f"GNSS ID {sys}"]["decimal"])
    satellite_mask = msg[f"Satellite mask {sys}"]["binary"]
    sv_mask = msg["Network SV Mask Sys{0} {1} {2}".format(sys, 11, multiplicity)][
        "binary"
    ]

    phases_per_sat = []
    sv = 0
    svID = 1
    for sat in range(len(satellite_mask)):
        if int(satellite_mask[sat]) == 1:
            if int(sv_mask[sv]) == 1:
                if orbitFlag:
                    phases_per_sat.append(
                        orbitMessagePerSat(msg, sys, svID, 11, multiplicity, sat + 1)
                    )
                if clockFlag:
                    phases_per_sat.append(
                        clockMessagePerSat(msg, sys, svID, 11, multiplicity, sat + 1)
                    )
                svID += 1
            sv += 1

    return {
        "GNSS ID": GNSS_ID[gnssID],
        "Combined Correction per Satellite": phases_per_sat,
    }


def combinedMessage(msg, multiplicity):
    header = baseHeader(msg, 11, multiplicity)

    nsys = int(msg["No. of GNSS"]["decimal"])
    orbitFlag = int(msg[f"Orbit Existing Flag {multiplicity}"]["decimal"]) == 1
    clockFlag = int(msg[f"Clock Existing Flag {multiplicity}"]["decimal"]) == 1

    networkData = netWorkData(msg, 11, multiplicity, True)

    combined_per_sys = []
    for sys in range(nsys):
        combined_per_sys.append(
            combinedMessagePerSys(msg, sys, multiplicity, orbitFlag, clockFlag)
        )

    return {
        f"Combined Correction Message {multiplicity}": {
            **header,
            "Orbit Existing Flag": orbitFlag,
            "Clock Existing Flag": clockFlag,
            **networkData,
            "Combined Correction per System": combined_per_sys,
        }
    }


def handleCombinedMessage(gen, nsys, satCounts, multiplicity, gnssIDs):
    handleBaseHeader(gen, 11, multiplicity)
    orbitFlag = gen.getParameterValue(1)
    gen.addParametertoDict(f"Orbit Existing Flag {multiplicity}", 1)
    clockFlag = gen.getParameterValue(1)
    gen.addParametertoDict(f"Clock Existing Flag {multiplicity}", 1)
    localSatCounts = handleNetWork(gen, nsys, satCounts, 11, multiplicity, True)
    for sys in range(nsys):
        for sat in range(1, localSatCounts[sys] + 1):
            if orbitFlag == 1:
                handleOrbitMessagePerSat(gen, sys, sat, 11, multiplicity, gnssIDs)
            if clockFlag == 1:
                handleClockMessagePerSat(gen, sys, sat, 11, multiplicity)
