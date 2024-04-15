# Skydel Remote API Python Examples | Safran Trusted 4D Canada Inc.

This folder contains the Python module to interface with the Skydel GNSS simulator and some examples. You can find the remote API version and a list of all existing commands in the file Documentation.txt located in the API directory.

> The minimum required Python version is 3.6.9.

## Dependencies

### Ubuntu
```
sudo apt install python3 python3-setuptools
```

### Windows
Download and install latest Python version from [here](https://www.python.org/downloads/). Make sure to add Python to the system PATH.

## Installation and Execution

1. Start Skydel and close the splash screen once the licence has been verified.
2. Install the remote API from a console opened in the current folder:
    - Ubuntu: `python3 -m pip install .`
    - Windows: `python -m pip install .` 
3. Execute an example script:
    - Ubuntu: `python3 example_basic.py`
    - Windows: `python example_basic.py` 

### Handling errors

If the installation fails, it might be because a previous installation can't be overriden.
To fix the issue, run the command:
- Ubuntu: `pip3 show skydel-sdx`
- Windows: `pip show skydel-sdx` 

Go to the **Location** folder found in the above command's result and delete the **skydelsdx** folder. Also make sure to delete all the files starting with **Skydel** and finishing with the **.egg-info** extension found within the **Location** folder. Then try to reinstall the remote API as explained above. 