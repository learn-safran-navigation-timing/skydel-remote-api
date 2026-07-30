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


def signal_key_to_nav_msg_family_mapping(is_geo=False):
    return {
        'L1CA': 'GPS_LNAV',
        'L1P': 'GPS_LNAV',
        'L2P': 'GPS_LNAV',
        'L2C': 'GPS_CNAV',
        'L5': 'GPS_CNAV',
        'L1C': 'GPS_CNAV2',
        'G1': 'GLONASS_NAV',
        'G2': 'GLONASS_NAV',
        'E1': 'GALILEO_INAV',
        'E5b': 'GALILEO_INAV',
        'E5a': 'GALILEO_FNAV',
        'E6BC': 'GALILEO_CNAV',
        'B1': 'BEIDOU_D2_NAV' if is_geo else 'BEIDOU_D1_NAV',
        'B2': 'BEIDOU_D2_NAV' if is_geo else 'BEIDOU_D1_NAV',
        'B1C': 'BEIDOU_CNAV1',
        'B2a': 'BEIDOU_CNAV2',
        'B2b': 'BEIDOU_CNAV3',
        'QZSSL1CA': 'QZSS_LNAV',
        'QZSSL1CB': 'QZSS_LNAV',
        'QZSSL2C': 'QZSS_CNAV',
        'QZSSL5': 'QZSS_CNAV',
        'QZSSL1C': 'QZSS_CNAV2',
        'QZSSL6': 'QZSS_CLAS',
        'NAVICL5': 'NAVIC_NAV',
        'NAVICS': 'NAVIC_NAV',
        'NAVICL1': 'NAVIC_L1',
        'SBASL1': 'SBAS_NAV',
        'SBASL5': 'SBAS_NAV',
    }


# Utility to convert signal to navigation message family
def signal_nav_msg_family(signal, is_geo=False):
    mapping = signal_key_to_nav_msg_family_mapping(is_geo)
    if signal in mapping.keys():
        return mapping[signal]


def get_signal_keys():
    return list(signal_key_to_nav_msg_family_mapping().keys())


def get_input_content(input_path):
    with open(input_path, "r") as downlink:
        return downlink.readlines()


def write_decoded_downlink_message(output, msg_dict, format, line, write_original_line):
    if write_original_line:
        output.write(f"{format}{line}\n")
    for key, value in msg_dict.items():
        output.write(
            f"{key},{value['range']},{value['binary']},{value['decimal']},{value['unit']}\n"
        )
    output.write("\n")


def write_decoded_downlink(
    input_path,
    output,
    decoders,
    downlink_type,
    nav_msg_family,
    write_original_line=True,
    output_format="file",
):
    content = get_input_content(input_path)
    input_iterator = iter(content)

    # Decode every line of the downlink.
    decoder = decoders[downlink_type][nav_msg_family]
    format = next(input_iterator)
    formatArray = format.strip().split(",")
    navMsgIdx = format.strip().split(",").index("Navigation Message (Hex)")

    if nav_msg_family == "GLONASS_NAV":
        frameIdx = format.split(",").index("Subframe")
        line_decoder = lambda line: decoder(
            line.split(",")[navMsgIdx], int(line.split(",")[frameIdx])
        )
    else:
        line_decoder = lambda line: decoder(line.split(",")[navMsgIdx])

    if output_format == "file":
        for line in input_iterator:
            msg_dict = line_decoder(line)
            write_decoded_downlink_message(
                output, msg_dict, format, line, write_original_line
            )
    elif output_format == "dict":
        messages = []
        for line in input_iterator:
            msg_dict = {}
            lineArray = line.split(",")
            for index, key in enumerate(formatArray):
                if index == navMsgIdx:
                    msg_dict[key] = line_decoder(line)
                else:
                    msg_dict[key] = lineArray[index]
            messages.append(msg_dict)
        return messages
    else:
        print(f"Invalid output type '{output_format}'")


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
                        'BEIDOU_CNAV3': decode_beidou.getDictBeiDouCNAV3DecodedNavigationMessage,
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
                        'BEIDOU_CNAV3': decode_beidou.getDictBeiDouCNAV3EncodedNavigationMessage,
                        'QZSS_LNAV': decode_qzss.getDictQZSSL1CAEncodedNavigationMessage}

    partial_decoders = {'GPS_CNAV2': decode_gps.getDictGPSL1CPartialNavigationMessage}

    return {'DECODED': decoded_decoders,
            'ENCODED': encoded_decoders,
            'PARTIAL': partial_decoders}


def get_parser(decoders):
    nav_msg_families = list(
        dict.fromkeys([key for values in decoders.values() for key in values.keys()])
    )
    signal_keys = get_signal_keys()
    decoder_types = [key for key in decoders.keys()]
    parser = argparse.ArgumentParser(
        description="Decode a downlink file",
        formatter_class=argparse.RawTextHelpFormatter,
    )
    parser.add_argument("decoder", type=str, help=f"Type of decoder {decoder_types}")
    parser.add_argument(
        "nav_msg_family_or_signal_key",
        metavar="nav-msg-family-or-signal-key",
        type=str,
        help=f"Navigation message families : {nav_msg_families} \n OR \nSignal keys : {signal_keys}",
    )
    parser.add_argument("input", type=str, help="Downlink file to decode")
    parser.add_argument(
        "-o",
        "--output",
        type=str,
        help="Write decoded downlink in specified file, otherwise write to console",
    )
    return parser


def validate_args(args, decoders):
    if args.decoder not in decoders:
        print(
            f"Invalid decoder type '{args.decoder}', valid decoder types are {list(decoders.keys())}"
        )
        sys.exit()

    nav_msg_family_from_signal_key = signal_nav_msg_family(
        args.nav_msg_family_or_signal_key
    )
    if nav_msg_family_from_signal_key is not None:
        args.nav_msg_family_or_signal_key = nav_msg_family_from_signal_key

    if args.nav_msg_family_or_signal_key not in decoders[args.decoder]:
        print(
            f"Invalid navigation message family or signal key '{args.nav_msg_family_or_signal_key}' for decoder type '{args.decoder}', valid navigation message families are {list(decoders[args.decoder].keys())}, and valid signal keys are '{get_signal_keys()}'"
        )
        sys.exit()


def get_output(output_path):
    if output_path == None:
        return sys.stdout
    else:
        return open(args.output, "w")


if __name__ == "__main__":
    decoders = get_decoders()
    args = get_parser(decoders).parse_args()
    validate_args(args, decoders)
    output = get_output(args.output)

    print(f"Decoding downlink file: {args.input}")
    write_decoded_downlink(
        args.input, output, decoders, args.decoder, args.nav_msg_family_or_signal_key
    )
    if args.output:
        output.close()
    print(
        f"Decoding finished successfully.{' Result saved to: ' + args.output if args.output else ''}"
    )
