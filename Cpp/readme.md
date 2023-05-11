# Skydel Remote API C++ Examples | Safran Trusted 4D Canada Inc.

This folder contains the C++ module to interface with the Skydel GNSS simulator and some examples. You can find the remote API version and a list of all existing commands in the file Documentation.txt located in the API directory.

## Dependencies

### Ubuntu
```
sudo apt install cmake build-essential uuid-dev
```

### Windows
1. Download latest **Build Tools for Visual Studio 2019** online installer and install **Desktop development with C++**. Make sure to only select latest **MSVCv142** and **Windows 10 SDK**. You can find the online installer [here](https://learn.microsoft.com/en-us/visualstudio/releases/2019/release-notes).
2. Download and install CMake from [here](https://github.com/Kitware/CMake/releases/download/v3.22.1/cmake-3.22.1-windows-x86_64.msi). Make sure to add CMake to the system PATH.

## Compilation and Execution
1. Start Skydel and close the splash screen once the licence has been verified.

### Ubuntu
2. Open a Terminal in the current folder and execute the following:
    ```
    mkdir build
    cd build
    cmake ..
    cmake --build .
    ./sdx_examples/sdx_examples
    ```

### Windows
2. Open a Command Prompt in the current folder and execute the following:
    ```
    mkdir build
    cd build
    call "C:\Program Files (x86)\Microsoft Visual Studio\2019\BuildTools\VC\Auxiliary\Build\vcvars64.bat"
    cmake -G"NMake Makefiles" -DCMAKE_BUILD_TYPE=Release ..
    cmake --build .
    cd sdx_examples
    sdx_examples.exe
    ```
