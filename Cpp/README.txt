////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Orolia Canada Inc.
// Skydel - Software-Defined GNSS Simulator
// Remote API C++ Examples
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

This folder contains example of C++ projects to remotely control the Skydel GNSS simulator.
You can find a list of all existing commands in the Python Remote API directory: see file "Documentation.txt"

* WINDOWS *
All C++ examples for remote commands and HIL are in the visual Studio 2013 solution "sdx_examples.sln"


* LINUX *
All C++ examples for remote commands and HIL are in the code::blocks workspace "sdx_examples.workspace"
You can also use the root "makefile" to compile everything with "make" command in this directory.
IMPORTANT for Linux:
The SdxApi project depends on libuuid.
Command to install on Ubuntu : sudo apt-get install uuid-dev


* HOW TO RUN EXAMPLES *
1- Compile the example for your platform
2- Start Skydel and close the splash screen once the licence has been verified.
3- Start the example executable

