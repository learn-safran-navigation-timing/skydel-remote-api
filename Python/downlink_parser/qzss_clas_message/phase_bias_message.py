from .qzss_clas_utils import *
import utility


def phaseBiasMessagePerSig(msg, sys, svID, sigID, stId, multiplicity, sig):
    gnssID = int(msg[f"GNSS ID {sys}"]["decimal"])
    return {
        "Sig": SIGNAL_MASK[gnssID][sig],
        "Phase Bias": float(
            msg[
                "Phase Bias Sys{0} Sat{1} Sig{2} {3} {4}".format(
                    sys, svID, sigID, stId, multiplicity
                )
            ]["decimal"]
        ),
        "Phase Discontinuity Indicator": int(
            msg[
                "Phase Discontinuity Indicator Sys{0} Sat{1} Sig{2} {3} {4}".format(
                    sys, svID, sigID, stId, multiplicity
                )
            ]["decimal"]
        ),
    }


def phaseBiasMessagePerSat(msg, sys, svID, stId, multiplicity, sat, cellID):
    signal_mask = msg[f"Signal mask {sys}"]["binary"]

    phases_per_sig = []
    sigID = 1
    for sig in range(len(signal_mask)):
        if int(signal_mask[sig]) == 1:
            cellMaskFlag = int(msg[f"Cell-mask Availability Flag {sys}"]["decimal"])
            if cellMaskFlag == 1:
                cellMask = int(
                    msg["Cell mask {0} Sat{1} Sig{2}".format(sys, cellID, sigID)][
                        "decimal"
                    ]
                )
                if cellMask == 0:
                    sigID += 1
                    continue

            phases_per_sig.append(
                phaseBiasMessagePerSig(msg, sys, svID, sigID, stId, multiplicity, sig)
            )
            sigID += 1

    return {"Sat": sat, "Phase Bias per Signal": phases_per_sig}


def phaseBiasMessagePerSys(msg, sys, multiplicity):
    gnssID = int(msg[f"GNSS ID {sys}"]["decimal"])
    satellite_mask = msg[f"Satellite mask {sys}"]["binary"]

    phases_per_sat = []
    svID = 1
    for sat in range(len(satellite_mask)):
        if int(satellite_mask[sat]) == 1:
            phases_per_sat.append(
                phaseBiasMessagePerSat(msg, sys, svID, 5, multiplicity, sat + 1, svID)
            )
            svID += 1

    return {
        f"Phase Bias Message {multiplicity}": {
            "GNSS ID": GNSS_ID[gnssID],
            "Phase Bias per Satellite": phases_per_sat,
        }
    }


def phaseBiasMessage(msg, multiplicity):
    header = baseHeader(msg, 5, multiplicity)

    nsys = int(msg["No. of GNSS"]["decimal"])
    phases_per_sys = []

    for sys in range(nsys):
        phases_per_sys.append(phaseBiasMessagePerSys(msg, sys, multiplicity))

    return {**header, "Phase Bias per System": phases_per_sys}


def handlePhaseBiasMessagePerSig(gen, sys, sat, sig, stId, multiplicity):
    gen.addParametertoDict(
        "Phase Bias Sys{0} Sat{1} Sig{2} {3} {4}".format(
            sys, sat, sig, stId, multiplicity
        ),
        15,
        True,
        0.001,
        utility.METER,
    )
    gen.addParametertoDict(
        "Phase Discontinuity Indicator Sys{0} Sat{1} Sig{2} {3} {4}".format(
            sys, sat, sig, stId, multiplicity
        ),
        2,
    )


def handlePhaseBiasMessage(gen, nsys, satCounts, sigCounts, cellMasks, multiplicity):
    handleBaseHeader(gen, 5, multiplicity)
    for sys in range(nsys):
        for sat in range(1, satCounts[sys] + 1):
            for sig in range(1, sigCounts[sys] + 1):
                if cellMasks[sys][(sat - 1) * sigCounts[sys] + sig - 1] == "1":
                    handlePhaseBiasMessagePerSig(gen, sys, sat, sig, 5, multiplicity)
