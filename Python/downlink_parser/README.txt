SKYDEL - PYTHON DOWNLINK PARSER

This folder contains utility scripts for parsing downlink navigation messages.
In each constellation script, there are functions returning a dictionary containing keys with parameters names and their informations.

Dictionary keys :
	'name'    : Name of the paramater.
	'range'   : Index of the parameter.
	'binary'  : Binary value of the parameter.
	'decimal' : Decimal value of the parameter.
	'unit'    : Unit of the parameter.
		
These dictionaries can be used to convert the hexadecimal navigation message data to a readable format.
The script 'decode_downlink.py' allows to easily decode an entire downlink file for supported navigation messages.

If you want to decode the downlink of a Septentrio receiver you must :
	1) Add  ",,,,,,Navigation Message (Hex)," at the top of the file. "Navigation Message (Hex)" index correspond to the index of the navigation message.
	2) For L1C, use this command (python3 decode_downlink.py PARTIAL GPS_CNAV2 INPUTFILE)
	