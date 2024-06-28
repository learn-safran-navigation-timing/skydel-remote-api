from .qzss_clas_utils import *
import utility


def clockMessagePerSat(msg, sys, svID, stId, multiplicity, sat):
    return {
        "Sat": sat,
        "Delta Clock C0": float(
            msg[
                "Delta Clock C0 Sys{0} Sat{1} {2} {3}".format(
                    sys, svID, stId, multiplicity
                )
            ]["decimal"]
        ),
    }


def clockMessagePerSys(msg, sys, multiplicity):
    gnssID = int(msg[f"GNSS ID {sys}"]["decimal"])
    satellite_mask = msg[f"Satellite mask {sys}"]["binary"]

    clocks_per_sat = []

    svID = 1
    for sat in range(len(satellite_mask)):
        if int(satellite_mask[sat]) == 1:
            clocks_per_sat.append(
                clockMessagePerSat(msg, sys, svID, 3, multiplicity, sat + 1)
            )
            svID += 1

    return {"GNSS ID": GNSS_ID[gnssID], "Clocks per Satellite": clocks_per_sat}


def clockMessage(msg, multiplicity):
    header = baseHeader(msg, 3, multiplicity)

    nsys = int(msg["No. of GNSS"]["decimal"])
    clocks_per_sys = []

    for sys in range(nsys):
        clocks_per_sys.append(clockMessagePerSys(msg, sys, multiplicity))

    return {
        f"Clock message {multiplicity}": {**header, "Clocks per System": clocks_per_sys}
    }


def handleClockMessagePerSat(gen, sys, sat, stId, multiplicity):
    gen.addParametertoDict(
        "Delta Clock C0 Sys{0} Sat{1} {2} {3}".format(sys, sat, stId, multiplicity),
        15,
        True,
        0.0016,
        utility.METER,
    )


def handleClockMessage(gen, nsys, satCounts, multiplicity):
    handleBaseHeader(gen, 3, multiplicity)
    for sys in range(nsys):
        for sat in range(1, satCounts[sys] + 1):
            handleClockMessagePerSat(gen, sys, sat, 3, multiplicity)
