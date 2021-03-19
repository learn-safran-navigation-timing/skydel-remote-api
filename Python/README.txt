SKYDEL - PYTHON REMOTE API

This folder contains the python module to interface with the Skydel GNSS
simulator.

Please read Documentation.txt for more information on available commands and the
current API version.

You can run your python script from this folder. 

If you want to run it from another folder, you may need to install the python
library. 

===============
===== On Linux:
===============
The library is automatically installed in the system during Skydel installation 
for the default "python" command.
If you want to use the librairy with an alternate python version (ex: python3),
you must manually call the setup.py script with this alternate version.
Ex: python3 setup.py install

Note: you must execute this command each time the library API version changes
(see Documentation.txt to identify the version)


=================
===== On Windows:
=================
To install the library, you must manually run this command each time the library
API version changes (see Documentation.txt to identify the version):

python setup.py install


