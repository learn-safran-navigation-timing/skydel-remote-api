from .qzss_clas_utils import *
from .code_bias_message import handleCodeBiasMessagePerSig, codeBiasMessagePerSat
from .phase_bias_message import handlePhaseBiasMessagePerSig, phaseBiasMessagePerSat


def codePhaseBiasMessagePerSys(msg, sys, multiplicity, codeFlag, phaseFlag):
    gnssID = int(msg[f"GNSS ID {sys}"]["decimal"])
    satellite_mask = msg[f"Satellite mask {sys}"]["binary"]
    sv_mask = msg["Network SV Mask Sys{0} {1} {2}".format(sys, 6, multiplicity)][
        "binary"
    ]

    phases_per_sat = []
    sv = 0
    svID = 1
    for sat in range(len(satellite_mask)):
        if int(satellite_mask[sat]) == 1:
            if int(sv_mask[sv]) == 1:
                if codeFlag:
                    phases_per_sat.append(
                        codeBiasMessagePerSat(
                            msg, sys, svID, 6, multiplicity, sat + 1, sv + 1
                        )
                    )
                if phaseFlag:
                    phases_per_sat.append(
                        phaseBiasMessagePerSat(
                            msg, sys, svID, 6, multiplicity, sat + 1, sv + 1
                        )
                    )
                svID += 1
            sv += 1

    return {"GNSS ID": GNSS_ID[gnssID], "Code Phase Bias per Satellite": phases_per_sat}


def codePhaseBiasMessage(msg, multiplicity):
    header = baseHeader(msg, 6, multiplicity)

    nsys = int(msg["No. of GNSS"]["decimal"])
    codeFlag = int(msg[f"Code Bias Existing Flag {multiplicity}"]["decimal"]) == 1
    phaseFlag = int(msg[f"Phase Bias Existing Flag {multiplicity}"]["decimal"]) == 1

    networkData = netWorkData(msg, 6, multiplicity, True)

    phases_per_sys = []
    for sys in range(nsys):
        phases_per_sys.append(
            codePhaseBiasMessagePerSys(msg, sys, multiplicity, codeFlag, phaseFlag)
        )

    return {
        f"Code Phase Bias Message {multiplicity}": {
            **header,
            "Code Bias Existing Flag": codeFlag,
            "Phase Bias Existing Flag": phaseFlag,
            **networkData,
            "Code Phase Bias per System": phases_per_sys,
        }
    }


def handleCodePhaseBiasMessage(
    gen, nsys, satCounts, sigCounts, cellMasks, multiplicity
):
    handleBaseHeader(gen, 6, multiplicity)
    code_bias = gen.getParameterValue(1)
    gen.addParametertoDict(f"Code Bias Existing Flag {multiplicity}", 1)
    phase_bias = gen.getParameterValue(1)
    gen.addParametertoDict(f"Phase Bias Existing Flag {multiplicity}", 1)

    network = gen.getParameterValue(1)
    gen.addParametertoDict(f"Network Bias Correction 6 {multiplicity}", 1)

    localSatMasks = []
    if network == 1:
        gen.addParametertoDict(f"Network ID 6 {multiplicity}", 5)

        for sys in range(nsys):
            satM = gen.getParameterValue(satCounts[sys])
            gen.addParametertoDict(
                "Network SV Mask Sys{0} {1} {2}".format(sys, 6, multiplicity),
                satCounts[sys],
            )
            localSatMasks.append(bin(satM)[2:].zfill(satCounts[sys]))
    else:
        for sys in range(nsys):
            localSatMasks.append("".ljust(satCounts[sys], "1"))

    for sys in range(nsys):
        localSat = 1
        for sat in range(1, satCounts[sys] + 1):
            if localSatMasks[sys][(sat - 1)] == "1":
                for sig in range(1, sigCounts[sys] + 1):
                    if cellMasks[sys][(sat - 1) * sigCounts[sys] + sig - 1] == "1":
                        if code_bias == 1:
                            handleCodeBiasMessagePerSig(
                                gen, sys, localSat, sig, 6, multiplicity
                            )
                        if phase_bias == 1:
                            handlePhaseBiasMessagePerSig(
                                gen, sys, localSat, sig, 6, multiplicity
                            )
                localSat += 1
