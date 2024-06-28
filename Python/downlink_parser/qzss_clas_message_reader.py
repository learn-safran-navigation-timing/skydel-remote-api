#!/usr/bin/env python3

from qzss_clas_message import (
    mask_message,
    orbit_message,
    clock_message,
    code_bias_message,
    phase_bias_message,
    code_phase_bias_message,
    ura_message,
    stec_message,
    gridded_message,
    service_information_message,
    combined_message,
    atmospheric_message,
)
from qzss_clas_message import qzss_clas_utils
import utility
import json


class QzssCLASDictGenerator:
    binaryMessage = 0
    dictToUse = []
    currentBitIndex = 0
    currentDataPartIndex = 0
    dataPartNumber = 0
    data = {}
    frameSubTypeSequence = []
    subTypeMultiplicity = [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0]

    def __init__(self, pages):
        self.clear()
        while pages[0] == "":
            pages.pop(0)
        if len(pages) > 0:
            self.binaryMessage = utility.convertToBinaryNavigationMessage(
                pages[0], 1696
            )[:1695]
            self.dataPartNumber = len(pages)
            for pageIndex in range(1, len(pages)):
                if (pages[pageIndex] != "") and (pages[pageIndex] != "\n"):
                    self.binaryMessage = (
                        self.binaryMessage
                        + utility.convertToBinaryNavigationMessage(
                            pages[pageIndex], 1696
                        )[:1695]
                    )
                else:
                    self.dataPartNumber -= 1

    def clear(self):
        self.binaryMessage = 0
        self.dictToUse = []
        self.currentBitIndex = 0
        self.currentDataPartIndex = 0
        self.dataPartNumber = 0
        self.data = {}
        self.frameSubTypeSequence = []
        self.subTypeMultiplicity = [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0]

    def addParametertoDict(self, name, size, signed=False, factor=1, unit=""):
        self.dictToUse.append(
            {
                "name": name,
                "range": [self.currentBitIndex, self.currentBitIndex + size - 1],
                "signed": signed,
                "factor": factor,
                "unit": unit,
            }
        )
        self.currentBitIndex += size
        self.currentDataPartIndex = int((self.currentBitIndex + 1) / 1695)

    def getParameterValue(self, size):
        return int(
            self.binaryMessage[self.currentBitIndex : self.currentBitIndex + size], 2
        )

    def hasEnoughtBitsRemaining(self, nbBits):
        return not (
            (self.currentDataPartIndex == 29)
            and ((1695 - (self.currentBitIndex + 1) % 1695) > nbBits)
        )

    def addEndOfSubFrameToDict(self):
        while self.currentDataPartIndex % 5 != 0:
            self.currentBitIndex += 1695 - ((self.currentBitIndex + 1) % 1695)
            self.currentDataPartIndex = int((self.currentBitIndex + 1) / 1695)
        self.currentBitIndex += 1

    def isEndOfFrame(self):
        return (self.currentDataPartIndex == self.dataPartNumber) or (
            self.binaryMessage[self.currentBitIndex : self.currentBitIndex + 1] == ""
        )

    def addSubTypeInSequence(self, stId):
        self.frameSubTypeSequence.append(stId)
        self.subTypeMultiplicity[stId - 1] += 1
        return self.subTypeMultiplicity[stId - 1]


def handleSubType(gen, nsys, satCounts, sigCounts, cellMasks, gnssIDs):
    if not gen.hasEnoughtBitsRemaining(16):
        gen.addEndOfSubFrameToDict()
    else:
        val = gen.getParameterValue(16)
        number = (val & 0xFFF0) >> 4

        if number == qzss_clas_utils.MessageNumber:
            subType = val & 0x000F

            multiplicity = 0
            if (subType > 1) and (subType <= 12):
                multiplicity = gen.addSubTypeInSequence(subType)

            if subType == 2:
                orbit_message.handleOrbitMessage(
                    gen, nsys, satCounts, multiplicity, gnssIDs
                )
            elif subType == 3:
                clock_message.handleClockMessage(gen, nsys, satCounts, multiplicity)
            elif subType == 4:
                code_bias_message.handleCodeBiasMessage(
                    gen, nsys, satCounts, sigCounts, cellMasks, multiplicity
                )
            elif subType == 5:
                phase_bias_message.handlePhaseBiasMessage(
                    gen, nsys, satCounts, sigCounts, cellMasks, multiplicity
                )
            elif subType == 6:
                code_phase_bias_message.handleCodePhaseBiasMessage(
                    gen, nsys, satCounts, sigCounts, cellMasks, multiplicity
                )
            elif subType == 7:
                ura_message.handleUraMessage(gen, nsys, satCounts, multiplicity)
            elif subType == 8:
                stec_message.handleStecMessage(gen, nsys, satCounts, multiplicity)
            elif subType == 9:
                gridded_message.handleGriddedMessage(gen, nsys, satCounts, multiplicity)
            elif subType == 10:
                service_information_message.handleServiceInformationMessage(
                    gen, nsys, satCounts, multiplicity
                )
            elif subType == 11:
                combined_message.handleCombinedMessage(
                    gen, nsys, satCounts, multiplicity, gnssIDs
                )
            elif subType == 12:
                atmospheric_message.handleAtmosphericMessage(
                    gen, nsys, satCounts, multiplicity
                )
        elif number == 0:
            gen.addEndOfSubFrameToDict()
        else:
            raise Exception(
                "Cannot handle a message number of "
                + str(number)
                + " ( "
                + bin(number)[2:].zfill(12)
                + " ). Bit index in the frame : "
                + str(gen.currentBitIndex)
                + "."
            )


def getDictQzssCLASDecodedFrame(message):
    pages = str(message).split(" ")

    gen = QzssCLASDictGenerator(pages)

    nsys, satCounts, sigCounts, cellMasks, gnssIDs = mask_message.handleMaskMessage(gen)
    gen.addSubTypeInSequence(1)

    while not gen.isEndOfFrame():
        handleSubType(gen, nsys, satCounts, sigCounts, cellMasks, gnssIDs)

    dictToUse = utility.fillDict(gen.binaryMessage, gen.dictToUse)

    return dictToUse, gen.frameSubTypeSequence


def generateJsonRepresentationQzssCLAS(msg, frameSubTypeSequence):
    subTypeMultiplicity = [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0]

    data = {}

    for stId in frameSubTypeSequence:
        subTypeMultiplicity[stId - 1] += 1
        multiplicity = subTypeMultiplicity[stId - 1]

        if stId == 1:
            data = {**data, **mask_message.maskMessage(msg)}
        elif stId == 2:
            data = {**data, **orbit_message.orbitMessage(msg, multiplicity)}
        elif stId == 3:
            data = {**data, **clock_message.clockMessage(msg, multiplicity)}
        elif stId == 4:
            data = {**data, **code_bias_message.codeBiasMessage(msg, multiplicity)}
        elif stId == 5:
            data = {**data, **phase_bias_message.phaseBiasMessage(msg, multiplicity)}
        elif stId == 6:
            data = {
                **data,
                **code_phase_bias_message.codePhaseBiasMessage(msg, multiplicity),
            }
        elif stId == 7:
            data = {**data, **ura_message.uraMessage(msg, multiplicity)}
        elif stId == 8:
            data = {**data, **stec_message.stecMessage(msg, multiplicity)}
        elif stId == 9:
            data = {**data, **gridded_message.griddedMessage(msg, multiplicity)}
        elif stId == 10:
            data = {
                **data,
                **service_information_message.serviceInformationMessage(
                    msg, multiplicity
                ),
            }
        elif stId == 11:
            data = {**data, **combined_message.combinedMessage(msg, multiplicity)}
        elif stId == 12:
            data = {**data, **atmospheric_message.atmosphericMessage(msg, multiplicity)}

    return data


if __name__ == "__main__":
    # Put your CLAS message here
    message = ""

    dictToUse, frameSubTypeSequence = getDictQzssCLASDecodedFrame(message)

    data = generateJsonRepresentationQzssCLAS(dictToUse, frameSubTypeSequence)

    json_data = json.dumps(data, indent=2)
    # print(json_data)

    with open("QZSS_CLAS_frame.json", "w") as outfile:
        outfile.write(json_data)
