from .qzss_clas_utils import *


def uraMessagePerSat(msg, sys, svID, multiplicity, sat):
    return {
        "Sat": sat,
        "URA Index": int(
            msg["URA Sys{0} Sat{1} {2}".format(sys, svID, multiplicity)]["decimal"]
        ),
    }


def uraMessagePerSys(msg, sys, multiplicity):
    gnssID = int(msg[f"GNSS ID {sys}"]["decimal"])
    satellite_mask = msg[f"Satellite mask {sys}"]["binary"]

    ura_per_sat = []
    svID = 1
    for sat in range(len(satellite_mask)):
        if int(satellite_mask[sat]) == 1:
            ura_per_sat.append(uraMessagePerSat(msg, sys, svID, multiplicity, sat + 1))
            svID += 1

    return {"GNSS ID": GNSS_ID[gnssID], "URA per Satellite": ura_per_sat}


def uraMessage(msg, multiplicity):
    header = baseHeader(msg, 7, multiplicity)

    nsys = int(msg["No. of GNSS"]["decimal"])
    ura_per_sys = []

    for sys in range(nsys):
        ura_per_sys.append(uraMessagePerSys(msg, sys, multiplicity))

    return {f"URA Message {multiplicity}": {**header, "URA per System": ura_per_sys}}


def handleUraMessage(gen, nsys, satCounts, multiplicity):
    handleBaseHeader(gen, 7, multiplicity)
    for sys in range(nsys):
        for sat in range(1, satCounts[sys] + 1):
            gen.addParametertoDict(
                "URA Sys{0} Sat{1} {2}".format(sys, sat, multiplicity), 6
            )
