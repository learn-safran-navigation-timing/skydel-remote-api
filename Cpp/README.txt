////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Orolia Canada Inc.
// Skydel - Software-Defined GNSS Simulator
// Remote API C++ Examples
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

This folder contains example of C++ projects to remotely control the Skydel GNSS simulator.
You can find a list of all existing commands in the Python Remote API directory: see file "Documentation.txt"

* ALL PLATFORMS *
All C++ examples for remote commands and HIL use CMake build system.
Run the folling commands to build the examples :
    $ mkdir build
    $ cd build
    $ cmake ..
    $ cmake --build
For more informations about CMake : https://cmake.org/documentation

* LINUX *
The Sdx API project depends on libuuid.
Command to install on Ubuntu : sudo apt install uuid-dev


* HOW TO RUN EXAMPLES *
1- Compile the example for your platform
2- Start Skydel and close the splash screen once the licence has been verified.
3- Start the example executable
