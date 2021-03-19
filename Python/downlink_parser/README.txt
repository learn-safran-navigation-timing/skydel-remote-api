SKYDEL - PYTHON DOWNLINK PARSER

This folder contains utility scripts for parsing downlink navigation messages.
Available functions are returning a dictionary containing keys with parameters names and their informations.

Dictionary keys :
	'name' : Name of the paramater.
		'range'   : Index of the parameter.
		'binary'  : Binary value of the parameter.
		'decimal' : Decimal value of the parameter.
		'unit'    : Unit of the parameter.

Available functions :
	[GPS]
		- getDictGPSL1CAEncodedNavigationMessage(navigationMessage)
		- getDictGPSL1CADecodedNavigationMessage(navigationMessage)
		- getDictGPSL1CEncodedNavigationMessage(nagivationMessage)
		- getDictGPSL1CDecodedNavigationMessage(nagivationMessage)
		- getDictGPSL1CPartialNavigationMessage(nagivationMessage)
		- getDictGPSL5NavigationMessage(navigationMessage)
	[GLONASS]
		- getDictGLONASSNavigationMessage(nagivationMessage)
	[GALILEO]
		- getDictGalileoFNavigationMessage(navigationMessage)
		- getDictGalileoINavigationMessage(navigationMessage)
	[BeiDou]
		- getDictBeiDouB1NavigationMessage(navigationMessage)
		- getDictBeiDouCNAV1EncodedNavigationMessage(navigationMessage)
		- getDictBeiDouCNAV1DecodedNavigationMessage(navigationMessage)
		- getDictBeiDouCNAV1PartialNavigationMessage(navigationMessage)
		- getDictBeiDouCNAV2EncodedNavigationMessage(navigationMessage)
		- getDictBeiDouCNAV2DecodedNavigationMessage(nagivationMessage)
	[SBAS]
		- getDictSBASL1NavigationMessage(navigationMessage)
	[QZSS]
		- getDictQZSSL1CAEncodedNavigationMessage(navigationMessage)
		- getDictQZSSL1CADecodedNavigationMessage(navigationMessage)
		
See 'decode_downlink_example.py' for an exemple of a script that decode an entire downlink file.

If you want to decode the downlink of a Septentrio receiver you must :
	1) Add  ",,,,,,Navigation Message (Hex)," at the top of the file. "Navigation Message (Hex)" index correspond to the index of the navigation message.
	2) For L1C, use decoder type L1C-partial. (python .\decode_downlink_example.py L1C-partial INPUTFILE)
	