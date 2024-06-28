from .qzss_clas_utils import *
import utility


def qualityIndicator(msg, sys, svID, stId, multiplicity):
    return {
        "STEC Quality Indicator": int(
            msg[
                "STEC Quality Indicator Sys{0} Sat{1} {2} {3}".format(
                    sys, svID, stId, multiplicity
                )
            ]["decimal"]
        )
    }


def stecPoly(msg, sys, svID, stecType, stId, multiplicity):
    c00 = {
        "STEC Polynomial Coefficients C00": float(
            msg[
                "STEC Polynomial Coefficients C00 Sys{0} Sat{1} {2} {3}".format(
                    sys, svID, stId, multiplicity
                )
            ]["decimal"]
        )
    }
    if stecType > 0:
        c01 = {
            "STEC Polynomial Coefficients C01": float(
                msg[
                    "STEC Polynomial Coefficients C01 Sys{0} Sat{1} {2} {3}".format(
                        sys, svID, stId, multiplicity
                    )
                ]["decimal"]
            )
        }
        c10 = {
            "STEC Polynomial Coefficients C10": float(
                msg[
                    "STEC Polynomial Coefficients C10 Sys{0} Sat{1} {2} {3}".format(
                        sys, svID, stId, multiplicity
                    )
                ]["decimal"]
            )
        }
        if stecType > 1:
            c11 = {
                "STEC Polynomial Coefficients C11": float(
                    msg[
                        "STEC Polynomial Coefficients C11 Sys{0} Sat{1} {2} {3}".format(
                            sys, svID, stId, multiplicity
                        )
                    ]["decimal"]
                )
            }
            if stecType > 2:
                c02 = {
                    "STEC Polynomial Coefficients C02": float(
                        msg[
                            "STEC Polynomial Coefficients C02 Sys{0} Sat{1} {2} {3}".format(
                                sys, svID, stId, multiplicity
                            )
                        ]["decimal"]
                    )
                }
                c20 = {
                    "STEC Polynomial Coefficients C20": float(
                        msg[
                            "STEC Polynomial Coefficients C20 Sys{0} Sat{1} {2} {3}".format(
                                sys, svID, stId, multiplicity
                            )
                        ]["decimal"]
                    )
                }
                return {**c00, **c01, **c10, **c11, **c02, **c20}
            return {**c00, **c01, **c10, **c11}
        return {**c00, **c01, **c10}
    return {**c00}


def stecMessagePerSat(msg, sys, svID, stecType, multiplicity, sat):
    qualityIndic = qualityIndicator(msg, sys, svID, 8, multiplicity)
    poly = stecPoly(msg, sys, svID, stecType, 8, multiplicity)
    return {"Sat": sat, **qualityIndic, **poly}


def stecMessagePerSys(msg, sys, stecType, multiplicity):
    gnssID = int(msg[f"GNSS ID {sys}"]["decimal"])
    satellite_mask = msg[f"Satellite mask {sys}"]["binary"]
    sv_mask = msg["Network SV Mask Sys{0} {1} {2}".format(sys, 8, multiplicity)][
        "binary"
    ]

    stec_per_sat = []
    sv = 0
    svID = 0
    for sat in range(len(satellite_mask)):
        if int(satellite_mask[sat]) == 1:
            if int(sv_mask[sv]) == 1:
                stec_per_sat.append(
                    stecMessagePerSat(msg, sys, svID, stecType, multiplicity, sat + 1)
                )
                svID += 1
            sv += 1

    return {"GNSS ID": GNSS_ID[gnssID], "STEC Correction per Satellite": stec_per_sat}


def stecMessage(msg, multiplicity):
    header = baseHeader(msg, 8, multiplicity)

    nsys = int(msg["No. of GNSS"]["decimal"])
    stecType = int(msg[f"STEC Correction Type {multiplicity}"]["decimal"])
    networkData = netWorkData(msg, 8, multiplicity)

    stec_per_sys = []
    for sys in range(nsys):
        stec_per_sys.append(stecMessagePerSys(msg, sys, stecType, multiplicity))

    return {
        f"STEC Correction Message {multiplicity}": {
            **header,
            "STEC Correction Type": stecType,
            **networkData,
            "STEC Correction per System": stec_per_sys,
        }
    }


def handleQualityIndicator(gen, sys, sat, stId, multiplicity):
    gen.addParametertoDict(
        "STEC Quality Indicator Sys{0} Sat{1} {2} {3}".format(
            sys, sat, stId, multiplicity
        ),
        6,
    )


def handleStecPoly(gen, sys, sat, stecType, stId, multiplicity):
    gen.addParametertoDict(
        "STEC Polynomial Coefficients C00 Sys{0} Sat{1} {2} {3}".format(
            sys, sat, stId, multiplicity
        ),
        14,
        True,
        0.05,
        utility.TEC_U,
    )
    if stecType > 0:
        gen.addParametertoDict(
            "STEC Polynomial Coefficients C01 Sys{0} Sat{1} {2} {3}".format(
                sys, sat, stId, multiplicity
            ),
            12,
            True,
            0.02,
            utility.TEC_U_PER_DEGREE,
        )
        gen.addParametertoDict(
            "STEC Polynomial Coefficients C10 Sys{0} Sat{1} {2} {3}".format(
                sys, sat, stId, multiplicity
            ),
            12,
            True,
            0.02,
            utility.TEC_U_PER_DEGREE,
        )
    if stecType > 1:
        gen.addParametertoDict(
            "STEC Polynomial Coefficients C11 Sys{0} Sat{1} {2} {3}".format(
                sys, sat, stId, multiplicity
            ),
            10,
            True,
            0.02,
            utility.TEC_U_PER_DEGREE_SQUARED,
        )
    if stecType > 2:
        gen.addParametertoDict(
            "STEC Polynomial Coefficients C02 Sys{0} Sat{1} {2} {3}".format(
                sys, sat, stId, multiplicity
            ),
            8,
            True,
            0.005,
            utility.TEC_U_PER_DEGREE_SQUARED,
        )
        gen.addParametertoDict(
            "STEC Polynomial Coefficients C20 Sys{0} Sat{1} {2} {3}".format(
                sys, sat, stId, multiplicity
            ),
            8,
            True,
            0.005,
            utility.TEC_U_PER_DEGREE_SQUARED,
        )


def handleStecMessagePerSat(gen, sys, sat, stecType, multiplicity):
    handleQualityIndicator(gen, sys, sat, 8, multiplicity)
    handleStecPoly(gen, sys, sat, stecType, 8, multiplicity)


def handleStecMessage(gen, nsys, satCounts, multiplicity):
    handleBaseHeader(gen, 8, multiplicity)
    stecType = gen.getParameterValue(2)
    gen.addParametertoDict(f"STEC Correction Type {multiplicity}", 2)
    localSatCounts = handleNetWork(gen, nsys, satCounts, 8, multiplicity)
    for sys in range(nsys):
        for sat in range(1, localSatCounts[sys] + 1):
            handleStecMessagePerSat(gen, sys, sat, stecType, multiplicity)
