#!/usr/bin/env python3

import argparse
import sys

import decode_gps
import decode_galileo
import decode_beidou
import decode_glonass
import decode_sbas
import decode_qzss
import decode_navic


# Utility to convert signal to navigation message family
def signal_nav_msg_family(signal, is_geo = False):
    if signal in ['L1CA', 'L1P', 'L2P']:
        return 'GPS_LNAV'
    if signal in ['L2C', 'L5']:
        return 'GPS_CNAV'
    if signal in ['L1C']:
        return 'GPS_CNAV2'
    if signal in ['G1', 'G2']:
        return 'GLONASS_NAV'
    if signal in ['E1', 'E5b']:
        return 'GALILEO_INAV'
    if signal in ['E5a']:
        return 'GALILEO_FNAV'
    if signal in ['E6']:
        return 'GALILEO_CNAV'
    if signal in ['B1', 'B2']:
        return 'BEIDOU_D2_NAV' if is_geo else 'BEIDOU_D1_NAV'
    if signal in ['B1C']:
        return 'BEIDOU_CNAV1'
    if signal in ['B2a']:
        return 'BEIDOU_CNAV2'
    if signal in ['QZSSL1CA', 'QZSSL1CB']:
        return 'QZSS_LNAV'
    if signal in ['QZSSL2C', 'QZSSL5']:
        return 'QZSS_CNAV'
    if signal in ['QZSSL1C']:
        return 'QZSS_CNAV2'
    if signal in ['QZSSL6']:
        return 'QZSS_CLAS'
    if signal in ['NAVICL5', 'NAVICS']:
        return 'NAVIC_NAV'
    if signal in ['NAVICL1']:
        return 'NAVIC_L1'
    if signal in ['SBASL1', 'SBASL5']:
        return 'SBAS_NAV'


def get_input_content(input_path):
    with open(input_path, 'r') as downlink:
        return downlink.readlines()


def write_decoded_downlink_message(output, msg_dict, format, line, write_original_line):
    if write_original_line:
        output.write(f"{format}{line}\n")
    for key, value in msg_dict.items():
        output.write(f"{key},{value['range']},{value['binary']},{value['decimal']},{value['unit']}\n")
    output.write("\n")
        

def write_decoded_downlink(input_path, output, decoders, downlink_type, nav_msg_family, write_original_line = True):
    content = get_input_content(input_path)
    input_iterator = iter(content)

    # Decode every line of the downlink.
    decoder = decoders[downlink_type][nav_msg_family]
    format = next(input_iterator)
    navMsgIdx = format.strip().split(',').index('Navigation Message (Hex)')

    if nav_msg_family == 'GLONASS_NAV':
        frameIdx = format.split(',').index('Subframe')
        line_decoder = lambda line: decoder(line.split(',')[navMsgIdx], int(line.split(',')[frameIdx]))
    else:
        line_decoder = lambda line: decoder(line.split(',')[navMsgIdx])

    for line in input_iterator:
        msg_dict = line_decoder(line)
        write_decoded_downlink_message(output, msg_dict, format, line, write_original_line)


def get_decoders():
    decoded_decoders = {'GPS_LNAV': decode_gps.getDictGPSL1CADecodedNavigationMessage,
                        'GPS_CNAV2': decode_gps.getDictGPSL1CDecodedNavigationMessage,
                        'GPS_CNAV': decode_gps.getDictGPSL5NavigationMessage,
                        'GLONASS_NAV': decode_glonass.getDictGLONASSNavigationMessage,
                        'GALILEO_INAV': decode_galileo.getDictGalileoINavigationMessage,
                        'GALILEO_FNAV': decode_galileo.getDictGalileoFNavigationMessage,
                        'GALILEO_CNAV': decode_galileo.getDictGalileoCNavigationMessage,
                        'BEIDOU_D1_NAV': decode_beidou.getDictBeiDouB1D1DecodedNavigationMessage,
                        'BEIDOU_D2_NAV': decode_beidou.getDictBeiDouB1D2DecodedNavigationMessage,
                        'BEIDOU_CNAV1': decode_beidou.getDictBeiDouCNAV1DecodedNavigationMessage,
                        'BEIDOU_CNAV2': decode_beidou.getDictBeiDouCNAV2DecodedNavigationMessage,
                        'SBAS_NAV': decode_sbas.getDictSBASL1NavigationMessage,
                        'QZSS_LNAV': decode_qzss.getDictQZSSL1CADecodedNavigationMessage,
                        'QZSS_SLAS': decode_qzss.getDictQZSSL1SDecodedNavigationMessage,
                        'QZSS_CLAS': decode_qzss.getDictQZSSL6DecodedNavigationMessage,
                        'NAVIC_NAV': decode_navic.getDictNavICNAVNavigationMessage,
                        'NAVIC_L1': decode_navic.getDictNavICL1NavigationMessage}

    encoded_decoders = {'GPS_LNAV': decode_gps.getDictGPSL1CAEncodedNavigationMessage,
                        'GPS_CNAV2': decode_gps.getDictGPSL1CEncodedNavigationMessage,
                        'BEIDOU_D1_NAV': decode_beidou.getDictBeiDouB1D1EncodedNavigationMessage,
                        'BEIDOU_D2_NAV': decode_beidou.getDictBeiDouB1D2EncodedNavigationMessage,
                        'BEIDOU_CNAV1': decode_beidou.getDictBeiDouCNAV1DecodedNavigationMessage,
                        'BEIDOU_CNAV2': decode_beidou.getDictBeiDouCNAV2EncodedNavigationMessage,
                        'QZSS_LNAV': decode_qzss.getDictQZSSL1CAEncodedNavigationMessage}

    partial_decoders = {'GPS_CNAV2': decode_gps.getDictGPSL1CPartialNavigationMessage}

    return {'DECODED': decoded_decoders,
            'ENCODED': encoded_decoders,
            'PARTIAL': partial_decoders}


def get_parser(decoders):
    nav_msg_families = list(dict.fromkeys([key for values in decoders.values() for key in values.keys()]))
    decoder_types = [key for key in decoders.keys()]
    parser = argparse.ArgumentParser(description="Decode a downlink file")
    parser.add_argument('decoder', type=str, help=f"Type of decoder {decoder_types}")
    parser.add_argument('nav_msg_family', metavar='nav-msg-family', type=str, help=f"Navigation message family {nav_msg_families}")
    parser.add_argument('input', type=str, help="Downlink file to decode")
    parser.add_argument('-o', '--output', type=str, help="Write decoded downlink in specified file, otherwise write to console")
    return parser


def validate_args(args, decoders):
    if args.decoder not in decoders:
        print(f"Invalid decoder type '{args.decoder}', valid decoder types are {list(decoders.keys())}")
        sys.exit()

    if args.nav_msg_family not in decoders[args.decoder]:
        print(f"Invalid NAV msg family '{args.nav_msg_family}' for decoder type '{args.decoder}', valid NAV msg family are {list(decoders[args.decoder].keys())}'")
        sys.exit()


def get_output(output_path):
    if output_path == None:
        return sys.stdout
    else:
        return open(args.output, 'w')


if __name__ == "__main__":
    decoders = get_decoders()
    args = get_parser(decoders).parse_args()
    validate_args(args, decoders)
    output = get_output(args.output)
    write_decoded_downlink(args.input, output, decoders, args.decoder, args.nav_msg_family)
    output.close()
