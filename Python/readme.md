# Skydel Remote API Python Examples | Safran Trusted 4D Canada Inc.

This folder contains the Python module to interface with the Skydel GNSS simulator and some examples. You can find the remote API version and a list of all existing commands in the file Documentation.txt located in the API directory.

## Dependencies

### Ubuntu
```
sudo apt install python3 python3-distutils
```

### Windows
Download and install latest Python version from [here](https://www.python.org/downloads/). Make sure to add Python to the system PATH.

## Installation and Execution

1. Start Skydel and close the splash screen once the licence has been verified.
2. Install the remote API from a console opened in the current folder:
    - Ubuntu: `sudo python3 setup.py install`
    - Windows: `python setup.py install` 
3. Execute an example script:
    - Ubuntu: `python3 example_basic.py`
    - Windows: `python example_basic.py` 
