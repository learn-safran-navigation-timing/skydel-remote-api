from galileo_has_message import mask_block, orbit_block, clock_block, code_block, phase_block, header
import utility
import json

class GalileoCNavHasDictGenerator:
    binaryMessage = 0
    dictToUse = header.HEADER
    currentBitIndex = 32
    data = {}

    def __init__(self, pages):
        self.binaryMessage = utility.convertToBinaryNavigationMessage(pages[0], 424)
        pageIndex = 1
        while pageIndex < len(pages):
            self.binaryMessage = self.binaryMessage + utility.convertToBinaryNavigationMessage(pages[pageIndex], 424)
            pageIndex += 1

    def addParametertoDict(self, name, size, signed = False, factor = 1, unit = ''):
        self.dictToUse.append({'name':name, 'range':[self.currentBitIndex, self.currentBitIndex + size - 1], 'signed':signed, 'factor':factor, 'unit':unit})
        self.currentBitIndex += size

    def getParameterValue(self, size):
        return int(self.binaryMessage[self.currentBitIndex:self.currentBitIndex + size], 2)

if __name__ == '__main__':
    # Put your HAS message here
    message = ''

    pages = str(message).split(' ')

    gen = GalileoCNavHasDictGenerator(pages)

    nsys, satCounts, sigCounts = mask_block.handleMaskBlock(gen)
    orbit_block.handleOrbitBlock(gen, nsys, satCounts)
    clock_block.handleClockBlock(gen, nsys, satCounts)
    code_block.handleCodeBlock(gen, nsys, satCounts, sigCounts)
    phase_block.handlePhaseBlock(gen, nsys, satCounts, sigCounts)

    dictToUse = utility.fillDict(gen.binaryMessage, gen.dictToUse)

    header = header.header(dictToUse)
    mask = mask_block.mask(dictToUse)
    orbit = orbit_block.orbit(dictToUse)
    clock = clock_block.clock(dictToUse)
    code = code_block.code(dictToUse)
    phase = phase_block.phase(dictToUse)

    data = {**header, **mask, **orbit, **clock, **code, **phase}
    json_data = json.dumps(data)
    print(json_data)
