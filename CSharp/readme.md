# Skydel Remote API C# Examples | Safran Trusted 4D Canada Inc.

This folder contains the C# module to interface with the Skydel GNSS simulator and some examples. You can find the remote API version and a list of all existing commands in the file Documentation.txt located in the API directory.

> Note that the C# API is only supported on Windows.

## Dependencies

1. Download latest **Build Tools for Visual Studio 2019** online installer and install **.NET desktop build tools**. Make sure to only select **.NET Framework 4.6.1 developement tools**. You can find the online installer [here](https://learn.microsoft.com/en-us/visualstudio/releases/2019/release-notes).
2. Download NuGet from [here](https://dist.nuget.org/win-x86-commandline/latest/nuget.exe).
3. From this folder open a Windows PowerShell and execute:
    ```
    & $HOME\Downloads\nuget.exe sources add -Name "NuGet.org" -Source https://api.nuget.org/v3/index.json
    & $HOME\Downloads\nuget.exe install Newtonsoft.Json -Version 12.0.3 -OutputDirectory $PWD\packages
    ```

## Compilation and Execution
1. Start Skydel and close the splash screen once the licence has been verified.
2. From this folder open a Windows PowerShell and execute:
    ```
    & 'C:\Program Files (x86)\Microsoft Visual Studio\2019\BuildTools\MSBuild\Current\Bin\MSBuild.exe' .\SdxExamples.sln
    cd .\SdxExamples\bin\Debug\
    .\SdxExamples.exe
    ```
