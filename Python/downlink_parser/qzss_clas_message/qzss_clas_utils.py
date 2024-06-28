import utility

GNSS_ID = {0: "GPS", 1: "GLONASS", 2: "GALILEO", 3: "BEIDOU", 4: "QZSS", 5: "SBAS"}

SIGNAL_MASK = {
    0: [
        "L1 C/A",
        "L1 P",
        "L1 Z-tracking",
        "L1 L1C(D)",
        "L1 L1C(P)",
        "L1 L1C(D+P)",
        "L2 L2C(M)",
        "L2 L2C(L)",
        "L2 L2C(M+L)",
        "L2 P",
        "L2 Z-tracking",
        "L5 I",
        "L5 Q",
        "L5 I+Q",
        "Reserved",
        "Reserved",
    ],
    1: [
        "G1 C/A",
        "G1 P",
        "G2 C/A",
        "G2 P",
        "G1a(D)",
        "G1a(P)",
        "G1a(D+P)",
        "G2a(D)",
        "G2a(P)",
        "G2a(D+P)",
        "G3 I",
        "G3 Q",
        "G3 I+Q",
        "Reserved",
        "Reserved",
        "Reserved",
    ],
    2: [
        "E1 B I/NAV OS/CS/SoL",
        "E1 C no data",
        "E1 B+C",
        "E5a I F/NAV OS",
        "E5a Q no data",
        "E5a I+Q",
        "E5b I I/NAV OS/CS/SoL",
        "E5b Q no data",
        "E5b I+Q",
        "E5 I",
        "E5 Q",
        "E5 I+Q",
        "Service specific 1",
        "Service specific 2",
        "Service specific 3",
        "Reserved",
    ],
    3: [
        "B1 I",
        "B1 Q",
        "B1 I+Q",
        "B3 I",
        "B3 Q",
        "B3 I+Q",
        "B2 I",
        "B2 Q",
        "B2 I+Q",
        "Reserved",
        "Reserved",
        "Reserved",
        "Reserved",
        "Reserved",
        "Reserved",
    ],
    4: [
        "L1 C/A",
        "L1 L1C(D)",
        "L1 L1C(P)",
        "L1 L1C(D+P)",
        "L2 L2C(M)",
        "L2 L2C(L)",
        "L2 L2C(M+L)",
        "L5 I",
        "L5 Q",
        "L5 I+Q",
        "Reserved",
        "Reserved",
        "Reserved",
        "Reserved",
        "Reserved",
        "Reserved",
    ],
    5: [
        "L1 C/A",
        "L5 I",
        "L5 Q",
        "L5 I+Q",
        "Reserved",
        "Reserved",
        "Reserved",
        "Reserved",
        "Reserved",
        "Reserved",
        "Reserved",
        "Reserved",
        "Reserved",
        "Reserved",
        "Reserved",
    ],
}

updateIntervals = [
    1,
    2,
    5,
    10,
    15,
    30,
    60,
    120,
    240,
    300,
    600,
    900,
    1800,
    3600,
    7200,
    10800,
]

MessageNumber = 4073


def netWorkSvMaskPerSys(msg, sys, stId, multiplicity):
    mask = []
    gnssID = int(msg[f"GNSS ID {sys}"]["decimal"])

    satellite_mask = msg[f"Satellite mask {sys}"]["binary"]
    sv_mask = msg["Network SV Mask Sys{0} {1} {2}".format(sys, stId, multiplicity)][
        "binary"
    ]

    sv = 0
    for sat in range(len(satellite_mask)):
        if int(satellite_mask[sat]) == 1:
            if int(sv_mask[sv]) == 1:
                mask.append(sat + 1)
            sv += 1

    return {"GNSS ID": GNSS_ID[gnssID], "Local Satellite Mask": mask}


def netWorkSvMask(msg, stId, multiplicity):
    nsys = int(msg["No. of GNSS"]["decimal"])
    sv_mask_per_sys = []

    for sys in range(nsys):
        sv_mask_per_sys.append(netWorkSvMaskPerSys(msg, sys, stId, multiplicity))

    return {"Network SV Mask": sv_mask_per_sys}


def netWorkId(msg, stId, multiplicity):
    return {"Network ID": int(msg[f"Network ID {stId} {multiplicity}"]["decimal"])}


def netWorkData(msg, stId, multiplicity, hasBiasCorr=False):
    if hasBiasCorr:
        biasCorr = (
            int(msg[f"Network Bias Correction {stId} {multiplicity}"]["decimal"]) == 1
        )
        network = {"Network Bias Correction": biasCorr}
        if biasCorr:
            networkId = netWorkId(msg, stId, multiplicity)
            networkMask = netWorkSvMask(msg, stId, multiplicity)
            return {**network, **networkId, **networkMask}
        else:
            return network
    else:
        networkId = netWorkId(msg, stId, multiplicity)
        networkMask = netWorkSvMask(msg, stId, multiplicity)
        return {**networkId, **networkMask}


def baseHeader(msg, stId, multiplicity):
    updateIntervalIndex = int(
        msg["Update Interval {0} {1}".format(stId, multiplicity)]["decimal"]
    )

    return {
        "Message Number": int(
            msg["Message Number {0} {1}".format(stId, multiplicity)]["decimal"]
        ),
        "Message Sub Type ID": int(
            msg["Message Sub Type ID {0} {1}".format(stId, multiplicity)]["decimal"]
        ),
        "GNSS Hourly Epoch Time 1s": int(
            msg["GNSS Hourly Epoch Time 1s {0} {1}".format(stId, multiplicity)][
                "decimal"
            ]
        ),
        "Update Interval": updateIntervals[updateIntervalIndex],
        "Multiple Message Indicator": int(
            msg["Multiple Message Indicator {0} {1}".format(stId, multiplicity)][
                "decimal"
            ]
        )
        == 1,
        "IOD SSR": int(msg["IOD SSR {0} {1}".format(stId, multiplicity)]["decimal"]),
    }


def getIODSize(sys):
    return 10 if sys == 2 else 8


def handleNetWorkSvMask(gen, nsys, satCounts, stId, multiplicity):
    localSatCounts = []
    for sys in range(nsys):
        satM = gen.getParameterValue(satCounts[sys])
        gen.addParametertoDict(
            "Network SV Mask Sys{0} {1} {2}".format(sys, stId, multiplicity),
            satCounts[sys],
        )
        localSatCount = bin(satM).count("1")
        localSatCounts.append(localSatCount)

    return localSatCounts


def handleNetWork(gen, nsys, satCounts, stId, multiplicity, hasBiasCorr=False):
    network = 0
    if hasBiasCorr:
        network = gen.getParameterValue(1)
        gen.addParametertoDict(f"Network Bias Correction {stId} {multiplicity}", 1)
    localSatCounts = satCounts
    if (not hasBiasCorr) or network == 1:
        gen.addParametertoDict(f"Network ID {stId} {multiplicity}", 5)
        localSatCounts = handleNetWorkSvMask(gen, nsys, satCounts, stId, multiplicity)

    return localSatCounts


def handleBaseHeader(gen, stId, multiplicity):
    gen.addParametertoDict(f"Message Number {stId} {multiplicity}", 12)
    gen.addParametertoDict(f"Message Sub Type ID {stId} {multiplicity}", 4)
    gen.addParametertoDict(
        f"GNSS Hourly Epoch Time 1s {stId} {multiplicity}", 12, False, 1, utility.SECOND
    )
    gen.addParametertoDict(f"Update Interval {stId} {multiplicity}", 4)
    gen.addParametertoDict(f"Multiple Message Indicator {stId} {multiplicity}", 1)
    gen.addParametertoDict(f"IOD SSR {stId} {multiplicity}", 4)
