import utility
from .qzss_clas_utils import *
from .stec_message import (
    handleQualityIndicator,
    handleStecPoly,
    qualityIndicator,
    stecPoly,
)


def atmosphericTropoPart(msg, multiplicity, tropo, ngrid):
    tropoPart = {}
    if tropo != 0:
        tropoPart = {
            "Troposphere Quality Indicator": int(
                msg[f"Troposphere Quality Indicator {multiplicity}"]["decimal"]
            )
        }
        if tropo & 0x1:
            tropoType = int(
                msg[f"Tropospheric Correction Type {multiplicity}"]["decimal"]
            )
            tropoPart = {
                **tropoPart,
                "Troposphere Polynomial Coefficients T00": float(
                    msg[f"Troposphere Polynomial Coefficients T00 {multiplicity}"][
                        "decimal"
                    ]
                ),
            }
            if tropoType > 0:
                tropoPart = {
                    **tropoPart,
                    "Troposphere Polynomial Coefficients T01": float(
                        msg[f"Troposphere Polynomial Coefficients T01 {multiplicity}"][
                            "decimal"
                        ]
                    ),
                    "Troposphere Polynomial Coefficients T10": float(
                        msg[f"Troposphere Polynomial Coefficients T10 {multiplicity}"][
                            "decimal"
                        ]
                    ),
                }
            if tropoType > 1:
                tropoPart = {
                    **tropoPart,
                    "Troposphere Polynomial Coefficients T11": float(
                        msg[f"Troposphere Polynomial Coefficients T11 {multiplicity}"][
                            "decimal"
                        ]
                    ),
                }
        if tropo & 0x2:
            tropoPart = {
                **tropoPart,
                "Troposphere Residual Size": int(
                    msg[f"Troposphere Residual Size {multiplicity}"]["decimal"]
                ),
                "Troposphere Residual Offset": float(
                    msg[f"Troposphere Residual Offset {multiplicity}"]["decimal"]
                ),
            }

            tropo_per_grid = []
            for grid in range(1, ngrid + 1):
                tropo_per_grid.append(
                    {
                        "Grid": grid,
                        "Troposphere Residual": float(
                            msg[
                                "Troposphere Residual grid{0} {1}".format(
                                    grid, multiplicity
                                )
                            ]["decimal"]
                        ),
                    }
                )
            tropoPart = {**tropoPart, "Troposhperic Residual per Grid": tropo_per_grid}

    return tropoPart


def atmosphericStecPart(msg, sys, multiplicity, stec, ngrid):
    stecPart = {}
    if stec >= 1:
        gnssID = int(msg[f"GNSS ID {sys}"]["decimal"])
        satellite_mask = msg[f"Satellite mask {sys}"]["binary"]
        sv_mask = msg["Network SV Mask Sys{0} {1} {2}".format(sys, 12, multiplicity)][
            "binary"
        ]

        stec_per_sat = []
        sv = 0
        svID = 1
        for sat in range(len(satellite_mask)):
            if int(satellite_mask[sat]) == 1:
                if int(sv_mask[sv]) == 1:
                    qualIndic = qualityIndicator(msg, sys, svID, 12, multiplicity)
                    stecType = int(
                        msg[
                            "STEC Correction Type Sys{0} Sat{1} {2}".format(
                                sys, svID, multiplicity
                            )
                        ]["decimal"]
                    )
                    stecPol = stecPoly(msg, sys, svID, stecType, 12, multiplicity)

                    stec_res_per_grid = []
                    for grid in range(1, ngrid + 1):
                        stec_res_per_grid.append(
                            {
                                "Grid": grid,
                                "STEC Residual": float(
                                    msg[
                                        "STEC Residual Sys{0} Grid{1} Sat{2} {3} {4}".format(
                                            sys, grid, svID, 12, multiplicity
                                        )
                                    ]["decimal"]
                                ),
                            }
                        )

                    stec_per_sat.append(
                        {
                            "Sat": sat + 1,
                            **qualIndic,
                            "STEC Correction Type": stecType,
                            **stecPol,
                            "STEC Residual Size": int(
                                msg[
                                    "STEC Residual Size Sys{0} Sat{1} {2}".format(
                                        sys, svID, multiplicity
                                    )
                                ]["decimal"]
                            ),
                            "STEC Residual per Grid": stec_res_per_grid,
                        }
                    )

                    svID += 1
                sv += 1

        stecPart = {"GNSS ID": GNSS_ID[gnssID], "STEC Residual per Sat": stec_per_sat}

    return stecPart


def atmosphericMessage(msg, multiplicity):
    header = baseHeader(msg, 12, multiplicity)

    tropo = int(msg[f"Tropospheric Correction Availability {multiplicity}"]["decimal"])
    stec = int(msg[f"STEC Correction Availability {multiplicity}"]["decimal"])
    ngrid = int(msg["No. of Grids {0} {1}".format(12, multiplicity)]["decimal"])

    nsys = int(msg["No. of GNSS"]["decimal"])
    tropoPart = atmosphericTropoPart(msg, multiplicity, tropo, ngrid)

    netWorkMask = {}
    if stec > 0:
        netWorkMask = netWorkSvMask(msg, 12, multiplicity)

    stec_per_sys = []
    for sys in range(nsys):
        stec_part = atmosphericStecPart(msg, sys, multiplicity, stec, ngrid)
        if len(stec_part) > 0:
            stec_per_sys.append(stec_part)

    return {
        f"Atmospheric Correction Message {multiplicity}": {
            **header,
            "Tropospheric Correction Availability": tropo,
            "STEC Correction Availability": stec,
            "Compact Network ID": int(
                msg[f"Compact Network ID {multiplicity}"]["decimal"]
            ),
            "No. of Grids": ngrid,
            **tropoPart,
            **netWorkMask,
            "STEC Correction per System": stec_per_sys,
        }
    }


def handleTropoPart(gen, tropo, ngrid, multiplicity):
    if tropo != 0:
        gen.addParametertoDict(f"Troposphere Quality Indicator {multiplicity}", 6)
        if tropo & 0x1:
            tropoType = gen.getParameterValue(2)
            gen.addParametertoDict(f"Tropospheric Correction Type {multiplicity}", 2)
            gen.addParametertoDict(
                f"Troposphere Polynomial Coefficients T00 {multiplicity}",
                9,
                True,
                0.004,
                utility.METER,
            )
            if tropoType > 0:
                gen.addParametertoDict(
                    f"Troposphere Polynomial Coefficients T01 {multiplicity}",
                    7,
                    True,
                    0.002,
                    utility.METER_PER_DEGREE,
                )
                gen.addParametertoDict(
                    f"Troposphere Polynomial Coefficients T10 {multiplicity}",
                    7,
                    True,
                    0.002,
                    utility.METER_PER_DEGREE,
                )
            if tropoType > 1:
                gen.addParametertoDict(
                    f"Troposphere Polynomial Coefficients T11 {multiplicity}",
                    7,
                    True,
                    0.001,
                    utility.METER_PER_DEGREE_SQUARED,
                )
        if tropo & 0x2:
            tropoResSize = gen.getParameterValue(1)
            gen.addParametertoDict(f"Troposphere Residual Size {multiplicity}", 1)
            gen.addParametertoDict(
                f"Troposphere Residual Offset {multiplicity}",
                4,
                False,
                0.02,
                utility.METER,
            )
            size = 6 if tropoResSize == 0 else 8
            for grid in range(1, ngrid + 1):
                gen.addParametertoDict(
                    "Troposphere Residual grid{0} {1}".format(grid, multiplicity),
                    size,
                    True,
                    0.004,
                    utility.METER,
                )


def handleStecPart(gen, nsys, satCounts, stec, ngrid, multiplicity):
    if stec >= 1:
        localSatCounts = handleNetWorkSvMask(gen, nsys, satCounts, 12, multiplicity)
        for sys in range(nsys):
            for sat in range(1, localSatCounts[sys] + 1):
                handleQualityIndicator(gen, sys, sat, 12, multiplicity)
                stecType = gen.getParameterValue(2)
                gen.addParametertoDict(
                    "STEC Correction Type Sys{0} Sat{1} {2}".format(
                        sys, sat, multiplicity
                    ),
                    2,
                )
                handleStecPoly(gen, sys, sat, stecType, 12, multiplicity)
                stecResSize = gen.getParameterValue(2)
                gen.addParametertoDict(
                    "STEC Residual Size Sys{0} Sat{1} {2}".format(
                        sys, sat, multiplicity
                    ),
                    2,
                )
                size = 4
                lsb = 0.04
                if stecResSize == 1:
                    lsb = 0.12
                elif stecResSize == 2:
                    size = 5
                    lsb = 0.16
                elif stecResSize == 3:
                    size = 7
                    lsb = 0.24

                for grid in range(1, ngrid + 1):
                    gen.addParametertoDict(
                        "STEC Residual Sys{0} Grid{1} Sat{2} {3} {4}".format(
                            sys, grid, sat, 12, multiplicity
                        ),
                        size,
                        True,
                        lsb,
                        utility.TEC_U,
                    )


def handleAtmosphericMessage(gen, nsys, satCounts, multiplicity):
    handleBaseHeader(gen, 12, multiplicity)
    tropo = gen.getParameterValue(2)
    gen.addParametertoDict(f"Tropospheric Correction Availability {multiplicity}", 2)
    stec = gen.getParameterValue(2)
    gen.addParametertoDict(f"STEC Correction Availability {multiplicity}", 2)
    gen.addParametertoDict(f"Compact Network ID {multiplicity}", 5)
    ngrid = gen.getParameterValue(6)
    gen.addParametertoDict("No. of Grids {0} {1}".format(12, multiplicity), 6)
    handleTropoPart(gen, tropo, ngrid, multiplicity)
    handleStecPart(gen, nsys, satCounts, stec, ngrid, multiplicity)
