from .qzss_clas_utils import *
import utility


def codeBiasMessagePerSig(msg, sys, svID, sigID, stId, multiplicity, sig):
    gnssID = int(msg[f"GNSS ID {sys}"]["decimal"])
    return {
        "Sig": SIGNAL_MASK[gnssID][sig],
        "Code Bias": float(
            msg[
                "Code Bias Sys{0} Sat{1} Sig{2} {3} {4}".format(
                    sys, svID, sigID, stId, multiplicity
                )
            ]["decimal"]
        ),
    }


def codeBiasMessagePerSat(msg, sys, svID, stId, multiplicity, sat, cellID):
    signal_mask = msg[f"Signal mask {sys}"]["binary"]

    codes_per_sig = []
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

            codes_per_sig.append(
                codeBiasMessagePerSig(msg, sys, svID, sigID, stId, multiplicity, sig)
            )
            sigID += 1

    return {"Sat": sat, "Code Bias per Signal": codes_per_sig}


def codeBiasMessagePerSys(msg, sys, multiplicity):
    gnssID = int(msg[f"GNSS ID {sys}"]["decimal"])
    satellite_mask = msg[f"Satellite mask {sys}"]["binary"]

    codes_per_sat = []
    svID = 1
    for sat in range(len(satellite_mask)):
        if int(satellite_mask[sat]) == 1:
            codes_per_sat.append(
                codeBiasMessagePerSat(msg, sys, svID, 4, multiplicity, sat + 1, svID)
            )
            svID += 1

    return {"GNSS ID": GNSS_ID[gnssID], "Code Bias per Satellite": codes_per_sat}


def codeBiasMessage(msg, multiplicity):
    header = baseHeader(msg, 4, multiplicity)

    nsys = int(msg["No. of GNSS"]["decimal"])
    codes_per_sys = []

    for sys in range(nsys):
        codes_per_sys.append(codeBiasMessagePerSys(msg, sys, multiplicity))

    return {
        f"Code Bias Message {multiplicity}": {
            **header,
            "Code Bias per System": codes_per_sys,
        }
    }


def handleCodeBiasMessagePerSig(gen, sys, sat, sig, stId, multiplicity):
    gen.addParametertoDict(
        "Code Bias Sys{0} Sat{1} Sig{2} {3} {4}".format(
            sys, sat, sig, stId, multiplicity
        ),
        11,
        True,
        0.02,
        utility.METER,
    )


def handleCodeBiasMessage(gen, nsys, satCounts, sigCounts, cellMasks, multiplicity):
    handleBaseHeader(gen, 4, multiplicity)
    for sys in range(nsys):
        for sat in range(1, satCounts[sys] + 1):
            for sig in range(1, sigCounts[sys] + 1):
                if cellMasks[sys][(sat - 1) * sigCounts[sys] + sig - 1] == "1":
                    handleCodeBiasMessagePerSig(gen, sys, sat, sig, 4, multiplicity)
