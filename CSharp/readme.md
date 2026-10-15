# Skydel Remote API C# Examples | Safran Trusted 4D Canada Inc.

This folder contains the C# module to interface with the Skydel GNSS simulator and some examples. You can find the remote API version and a list of all existing commands in the file Documentation.txt located in the API directory.

> Note that the C# API is only supported on Windows.

## Dependencies

1. Download latest **Build Tools for Visual Studio 2022** online installer and install **.NET desktop build tools**. Make sure to only select **.NET Framework 4.8 developement tools**. You can find the online installer [here](https://learn.microsoft.com/en-us/visualstudio/releases/2022/release-history#release-dates-and-build-numbers).
2. The `Newtonsoft.Json` NuGet package is already included in the `packages` folder in this repository, so no additional NuGet setup is required for examples.

## Compilation and Execution

1. Start Skydel and close the splash screen once the licence has been verified.
2. From this folder open a Windows PowerShell and execute:
```
    & 'C:\Program Files (x86)\Microsoft Visual Studio\2022\BuildTools\MSBuild\Current\Bin\MSBuild.exe' .\SdxExamples.sln
    cd .\SdxExamples\bin\Debug\
    .\SdxExamples.exe
```
