#!/usr/bin/python

import argparse
import collections
import os
import sys

import decode_gps
import decode_galileo
import decode_beidou
import decode_glonass
import decode_sbas
import decode_qzss
import decode_navic

def writeDecodedDownlinkMessage(output, msgDict, fromat, line):
    output.write(format + line + "\n")
    for key in msgDict.keys():
        output.write( key + "," + str( msgDict[ key ][ 'range' ] ) + "," + msgDict[ key ][ 'binary' ] + "," + msgDict[ key ][ 'decimal' ] + "," + msgDict[ key ][ 'unit' ] + "\n")
    output.write("\n")

if __name__ == "__main__":
    # Note: Septentrio output is decoded
    decoderDict = collections.OrderedDict({'L1CA-encoded':decode_gps.getDictGPSL1CAEncodedNavigationMessage,
                                           'L1CA-decoded':decode_gps.getDictGPSL1CADecodedNavigationMessage,
                                           'L1C-encoded':decode_gps.getDictGPSL1CEncodedNavigationMessage,
                                           'L1C-decoded':decode_gps.getDictGPSL1CDecodedNavigationMessage,
                                           'L1C-partial':decode_gps.getDictGPSL1CPartialNavigationMessage,
                                           'L5':decode_gps.getDictGPSL5NavigationMessage,
                                           'G1':decode_glonass.getDictGLONASSNavigationMessage,
                                           'G2':decode_glonass.getDictGLONASSNavigationMessage,
                                           'E1':decode_galileo.getDictGalileoINavigationMessage,
                                           'E5a':decode_galileo.getDictGalileoFNavigationMessage,
                                           'E5b':decode_galileo.getDictGalileoINavigationMessage,
                                           'B1-D1-encoded':decode_beidou.getDictBeiDouB1D1EncodedNavigationMessage,
                                           'B1-D2-encoded':decode_beidou.getDictBeiDouB1D2EncodedNavigationMessage,
                                           'B1-D1-decoded':decode_beidou.getDictBeiDouB1D1DecodedNavigationMessage,
                                           'B1-D2-decoded':decode_beidou.getDictBeiDouB1D2DecodedNavigationMessage,
                                           'BCNAV1-encoded':decode_beidou.getDictBeiDouCNAV1EncodedNavigationMessage,
                                           'BCNAV1-decoded':decode_beidou.getDictBeiDouCNAV1DecodedNavigationMessage,
                                           'BCNAV1-partial':decode_beidou.getDictBeiDouCNAV1PartialNavigationMessage,
                                           'BCNAV2-encoded':decode_beidou.getDictBeiDouCNAV2EncodedNavigationMessage,
                                           'BCNAV2-decoded':decode_beidou.getDictBeiDouCNAV2DecodedNavigationMessage,
                                           'SBASL1':decode_sbas.getDictSBASL1NavigationMessage,
                                           'L1CA-Q-encoded':decode_qzss.getDictQZSSL1CAEncodedNavigationMessage,
                                           'L1CA-Q-decoded':decode_qzss.getDictQZSSL1CADecodedNavigationMessage,
                                           'L1S-Q-decoded':decode_qzss.getDictQZSSL1SDecodedNavigationMessage,
                                           'NNAV-decoded':decode_navic.getDictNavICNAVNavigationMessage}) 

    parser = argparse.ArgumentParser(description = '''Decode a downlink file.''')
    parser.add_argument('signal', type = str, help = 'Available signals :%s' % (sorted(decoderDict.keys())))
    parser.add_argument('inputFile', type = str, help = 'Downlink file to decode.')
    parser.add_argument('--outputFile', type = str,  help = 'Write decoded downlink in specified file. If empty, writes in console.')
    args = parser.parse_args()

    # Get the iterator of the downlinkfile.
    with open(os.path.join(vars(args)['inputFile']), "r") as f:
        lines = f.readlines()
        lineItr = iter(lines)

    # Get the appropriate decoder depending on the 'signal' argument.
    signal = vars(args)['signal']
    decoder = decoderDict.get(signal)
    if decoder == None:
        print("%s is not a valid signal key." % (vars(args)['signal']))
        sys.exit()

    # Get the output file where the decoded downlink will be dumped.
    if vars(args)['outputFile'] == None:
        output = sys.stdout
    else:
        output = open(vars(args)['outputFile'], "w")

    # Decode every line of the downlink.
    format = next(lineItr)
    navMsgIdx = format.split(',').index('Navigation Message (Hex)')
    if signal in ['G1', 'G2']:
        frameIdx = format.split(',').index('Subframe')
        for line in lineItr:
            msgDict = decoder(line.split(',')[navMsgIdx], int(line.split(',')[frameIdx]))
            writeDecodedDownlinkMessage(output, msgDict, format, line)
    else:
        for line in lineItr:
            msgDict = decoder(line.split(',')[navMsgIdx])
            writeDecodedDownlinkMessage(output, msgDict, format, line)
