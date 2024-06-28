from .qzss_clas_utils import *
import utility


def satelliteMask(msg, sys):
    mask = []

    satellite_mask = msg[f"Satellite mask {sys}"]["binary"]
    for sat in range(len(satellite_mask)):
        if int(satellite_mask[sat]) == 1:
            mask.append(sat + 1)

    return mask


def signalMask(msg, sys, gnssID):
    mask = []

    signal_mask = msg[f"Signal mask {sys}"]["binary"]
    for sig in range(len(signal_mask)):
        if int(signal_mask[sig]) == 1:
            mask.append(SIGNAL_MASK[gnssID][sig])

    return mask


def cellMask(msg, sys, gnssID):
    mask = []

    satellite_mask = msg[f"Satellite mask {sys}"]["binary"]
    signal_mask = msg[f"Signal mask {sys}"]["binary"]

    for sat in range(len(satellite_mask)):
        if int(satellite_mask[sat]) == 1:
            for sig in range(len(signal_mask)):
                if int(signal_mask[sig]) == 1:
                    mask.append({"Sat": sat + 1, "Sig": SIGNAL_MASK[gnssID][sig]})

    return mask


def maskMessagePerSys(msg, sys):
    gnssID = int(msg[f"GNSS ID {sys}"]["decimal"])
    cellMaskFlag = int(msg[f"Cell-mask Availability Flag {sys}"]["decimal"]) == 1

    mask = {
        "GNSS ID": GNSS_ID[gnssID],
        "Satellite mask": satelliteMask(msg, sys),
        "Signal mask": signalMask(msg, sys, gnssID),
        "Cell-mask Availability Flag": cellMaskFlag,
    }

    if cellMaskFlag:
        _cellMask = {"Cell mask": cellMask(msg, sys, gnssID)}
        mask = {**mask, **_cellMask}

    return mask


def maskMessage(msg):
    nsys = int(msg["No. of GNSS"]["decimal"])
    mask_per_sys = []

    for sys in range(nsys):
        mask_per_sys.append(maskMessagePerSys(msg, sys))

    updateIntervalIndex = int(msg["Update Interval 1"]["decimal"])

    return {
        "Mask Message": {
            "Message Number": int(msg["Message Number 1"]["decimal"]),
            "Message Sub Type ID": int(msg["Message Sub Type ID 1"]["decimal"]),
            "GPS Epoch Time 1s": int(msg["GPS Epoch Time 1s"]["decimal"]),
            "Update Interval": updateIntervals[updateIntervalIndex],
            "Multiple Message Indicator": int(
                msg["Multiple Message Indicator 1"]["decimal"]
            )
            == 1,
            "IOD SSR": int(msg["IOD SSR 1"]["decimal"]),
            "No. of GNSS": nsys,
            "Mask per System": mask_per_sys,
        }
    }


def handleMaskMessage(gen):
    gen.addParametertoDict("Message Number 1", 12)
    gen.addParametertoDict("Message Sub Type ID 1", 4)
    gen.addParametertoDict("GPS Epoch Time 1s", 20, False, 1, utility.SECOND)
    gen.addParametertoDict("Update Interval 1", 4)
    gen.addParametertoDict("Multiple Message Indicator 1", 1)
    gen.addParametertoDict("IOD SSR 1", 4)
    nsys = gen.getParameterValue(4)
    gen.addParametertoDict("No. of GNSS", 4)
    satCounts = []
    sigCounts = []
    cellMasks = []
    gnssIDs = []
    for sys in range(nsys):
        gnssIDs.append(gen.getParameterValue(4))
        gen.addParametertoDict("GNSS ID {0}".format(sys), 4)
        satM = gen.getParameterValue(40)
        gen.addParametertoDict("Satellite mask {0}".format(sys), 40)
        sigM = gen.getParameterValue(16)
        gen.addParametertoDict("Signal mask {0}".format(sys), 16)
        cell_mask = gen.getParameterValue(1)
        gen.addParametertoDict("Cell-mask Availability Flag {0}".format(sys), 1)
        satCount = bin(satM).count("1")
        sigCount = bin(sigM).count("1")
        cellMask = ""
        if cell_mask == 1:
            for sat in range(satCount):
                for sig in range(sigCount):
                    cellMask += str(gen.getParameterValue(1))
                    gen.addParametertoDict(
                        "Cell mask {0} Sat{1} Sig{2}".format(sys, sat + 1, sig + 1), 1
                    )
        else:
            cellMask = cellMask.ljust(satCount * sigCount, "1")
        satCounts.append(satCount)
        sigCounts.append(sigCount)
        cellMasks.append(cellMask)

    return nsys, satCounts, sigCounts, cellMasks, gnssIDs
