from .qzss_clas_utils import *
import utility


def griddedMessagePerGrid(msg, sys, svID, grid, tropoType, multiplicity):
    dict = {"Grid": grid}

    if tropoType == 1:
        dict = {
            **dict,
            "Tropospheric Hydro-Static Vertical Delay": float(
                msg[
                    "Tropospheric Hydro-Static Vertical Delay Sys{0} Grid{1} {2}".format(
                        sys, grid, multiplicity
                    )
                ]["decimal"]
            ),
            "Tropospheric Wet Vertical Delay": float(
                msg[
                    "Tropospheric Wet Vertical Delay Sys{0} Grid{1} {2}".format(
                        sys, grid, multiplicity
                    )
                ]["decimal"]
            ),
            "STEC Residual Correction": float(
                msg[
                    "STEC Residual Correction Sys{0} Grid{1} Sat{2} {3} {4}".format(
                        sys, grid, svID, 9, multiplicity
                    ),
                ]["decimal"]
            ),
        }

    return dict


def griddedMessagePerSat(msg, sys, svID, tropoType, multiplicity, sat):
    ngrid = int(msg["No. of Grids {0} {1}".format(9, multiplicity)]["decimal"])

    gridded_per_grid = []
    for grid in range(ngrid):
        gridded_per_grid.append(
            griddedMessagePerGrid(msg, sys, svID, grid + 1, tropoType, multiplicity)
        )

    return {"Sat": sat, "Gridded Correction": gridded_per_grid}


def griddedMessagePerSys(msg, sys, tropoType, multiplicity):
    gnssID = int(msg[f"GNSS ID {sys}"]["decimal"])
    satellite_mask = msg[f"Satellite mask {sys}"]["binary"]
    sv_mask = msg["Network SV Mask Sys{0} {1} {2}".format(sys, 9, multiplicity)][
        "binary"
    ]

    gridded_per_sat = []
    sv = 0
    svID = 0
    for sat in range(len(satellite_mask)):
        if int(satellite_mask[sat]) == 1:
            if int(sv_mask[sv]) == 1:
                gridded_per_sat.append(
                    griddedMessagePerSat(
                        msg, sys, svID, tropoType, multiplicity, sat + 1
                    )
                )
                svID += 1
            sv += 1

    return {
        "GNSS ID": GNSS_ID[gnssID],
        "Gridded Correction per Satellite": gridded_per_sat,
    }


def griddedMessage(msg, multiplicity):
    header = baseHeader(msg, 9, multiplicity)

    nsys = int(msg["No. of GNSS"]["decimal"])
    tropoType = int(msg[f"Tropospheric Correction Type {multiplicity}"]["decimal"])
    networkData = netWorkData(msg, 9, multiplicity)

    gridded_per_sys = []
    for sys in range(nsys):
        gridded_per_sys.append(griddedMessagePerSys(msg, sys, tropoType, multiplicity))

    return {
        f"Gridded Correction Message {multiplicity}": {
            **header,
            "Tropospheric Correction Type": tropoType,
            "STEC Residual Correction Range": int(
                msg[f"STEC Residual Correction Range {multiplicity}"]["decimal"]
            ),
            **networkData,
            "Troposphere Quality Indicator": int(
                msg[f"Troposphere Quality Indicator {multiplicity}"]["decimal"]
            ),
            "No. of Grids": int(
                msg["No. of Grids {0} {1}".format(9, multiplicity)]["decimal"]
            ),
            "Gridded Correction per System": gridded_per_sys,
        }
    }


def handleGriddedMessagePerGrid(gen, sys, grid, satCounts, stecResType, multiplicity):
    stecResSize = 7 if stecResType == 0 else 16
    for sat in range(1, satCounts[sys] + 1):
        gen.addParametertoDict(
            "STEC Residual Correction Sys{0} Grid{1} Sat{2} {3} {4}".format(
                sys, grid, sat, 9, multiplicity
            ),
            stecResSize,
            True,
            0.04,
            utility.TEC_U,
        )


def handleGriddedMessage(gen, nsys, satCounts, multiplicity):
    handleBaseHeader(gen, 9, multiplicity)
    tropoType = gen.getParameterValue(2)
    gen.addParametertoDict(f"Tropospheric Correction Type {multiplicity}", 2)
    stecResType = gen.getParameterValue(1)
    gen.addParametertoDict(f"STEC Residual Correction Range {multiplicity}", 1)
    localSatCounts = handleNetWork(gen, nsys, satCounts, 9, multiplicity)
    gen.addParametertoDict(f"Troposphere Quality Indicator {multiplicity}", 6)
    ngrid = gen.getParameterValue(6)
    gen.addParametertoDict("No. of Grids {0} {1}".format(9, multiplicity), 6)
    for sys in range(nsys):
        for grid in range(1, ngrid + 1):
            if tropoType == 1:
                gen.addParametertoDict(
                    "Tropospheric Hydro-Static Vertical Delay Sys{0} Grid{1} {2}".format(
                        sys, grid, multiplicity
                    ),
                    9,
                    True,
                    0.004,
                    utility.METER,
                )
                gen.addParametertoDict(
                    "Tropospheric Wet Vertical Delay Sys{0} Grid{1} {2}".format(
                        sys, grid, multiplicity
                    ),
                    8,
                    True,
                    0.004,
                    utility.METER,
                )
            handleGriddedMessagePerGrid(
                gen, sys, grid, localSatCounts, stecResType, multiplicity
            )
