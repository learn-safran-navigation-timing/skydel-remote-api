from .qzss_clas_utils import *
import utility


def orbitMessagePerSat(msg, sys, svID, stId, multiplicity, sat):
    return {
        "Sat": sat,
        "GNSS IODE": int(
            msg[
                "GNSS IODE Sys{0} Sat{1} {2} {3}".format(sys, svID, stId, multiplicity)
            ]["decimal"]
        ),
        "Delta Radial": float(
            msg[
                "Delta Radial Sys{0} Sat{1} {2} {3}".format(
                    sys, svID, stId, multiplicity
                )
            ]["decimal"]
        ),
        "Delta Along-Track": float(
            msg[
                "Delta Along-Track Sys{0} Sat{1} {2} {3}".format(
                    sys, svID, stId, multiplicity
                )
            ]["decimal"]
        ),
        "Delta Cross-Track": float(
            msg[
                "Delta Cross-Track Sys{0} Sat{1} {2} {3}".format(
                    sys, svID, stId, multiplicity
                )
            ]["decimal"]
        ),
    }


def orbitMessagePerSys(msg, sys, multiplicity):
    gnssID = int(msg[f"GNSS ID {sys}"]["decimal"])
    satellite_mask = msg[f"Satellite mask {sys}"]["binary"]

    orbits_per_sat = []
    svID = 1
    for sat in range(len(satellite_mask)):
        if int(satellite_mask[sat]) == 1:
            orbits_per_sat.append(
                orbitMessagePerSat(msg, sys, svID, 2, multiplicity, sat + 1)
            )
            svID += 1

    return {"GNSS ID": GNSS_ID[gnssID], "Orbits per Satellite": orbits_per_sat}


def orbitMessage(msg, multiplicity):
    header = baseHeader(msg, 2, multiplicity)

    nsys = int(msg["No. of GNSS"]["decimal"])
    orbit_per_sys = []

    for sys in range(nsys):
        orbit_per_sys.append(orbitMessagePerSys(msg, sys, multiplicity))

    return {
        f"Orbit Message {multiplicity}": {**header, "Orbits per System": orbit_per_sys}
    }


def handleOrbitMessagePerSat(gen, sys, sat, stNb, multiplicity, gnssIDs):
    gen.addParametertoDict(
        "GNSS IODE Sys{0} Sat{1} {2} {3}".format(sys, sat, stNb, multiplicity),
        getIODSize(gnssIDs[sys]),
    )
    gen.addParametertoDict(
        "Delta Radial Sys{0} Sat{1} {2} {3}".format(sys, sat, stNb, multiplicity),
        15,
        True,
        0.0016,
        utility.METER,
    )
    gen.addParametertoDict(
        "Delta Along-Track Sys{0} Sat{1} {2} {3}".format(sys, sat, stNb, multiplicity),
        13,
        True,
        0.0064,
        utility.METER,
    )
    gen.addParametertoDict(
        "Delta Cross-Track Sys{0} Sat{1} {2} {3}".format(sys, sat, stNb, multiplicity),
        13,
        True,
        0.0064,
        utility.METER,
    )


def handleOrbitMessage(gen, nsys, satCounts, multiplicity, gnssIDs):
    handleBaseHeader(gen, 2, multiplicity)
    for sys in range(nsys):
        for sat in range(1, satCounts[sys] + 1):
            handleOrbitMessagePerSat(gen, sys, sat, 2, multiplicity, gnssIDs)
