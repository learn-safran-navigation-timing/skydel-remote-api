#pragma once

#include <memory>
#include "command_base.h"

#include <map>
#include <optional>
#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Execute the GPU benchmark and get the result score (will block Skydel's user interface).
    ///
    /// Name                            Type                     Description
    /// ------------------------------- ------------------------ ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    /// DurationMs                      int                      Duration of execution in milliseconds.
    /// SystemSvCountDict               dict string:int          A dictionary of system svcount pairs.
    ///                                                          Accepted keys are: "GPS", "GLONASS", "Galileo", "BeiDou", "SBAS", "QZSS" and
    ///                                                                             "NavIC"
    /// EchoCount                       int                      Number of echos per signal.
    /// InterferenceSignalTypeCountDict optional dict string:int Optional dictionary defining the interference signals to benchmark. Keys are interference signal types ("CW", "Chirp", "Pulse", "BPSK", "BOC", "AWGN"), and values specify how many of each type to include.
    ///

    class ExecuteGpuBenchmark;
    typedef std::shared_ptr<ExecuteGpuBenchmark> ExecuteGpuBenchmarkPtr;
    
    
    class ExecuteGpuBenchmark : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      ExecuteGpuBenchmark();

      ExecuteGpuBenchmark(int durationMs, const std::map<std::string, int>& systemSvCountDict, int echoCount, const std::optional<std::map<std::string, int>>& interferenceSignalTypeCountDict = {});

      static ExecuteGpuBenchmarkPtr create(int durationMs, const std::map<std::string, int>& systemSvCountDict, int echoCount, const std::optional<std::map<std::string, int>>& interferenceSignalTypeCountDict = {});
      static ExecuteGpuBenchmarkPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;

      virtual int executePermission() const override;


      // **** durationMs ****
      int durationMs() const;
      void setDurationMs(int durationMs);


      // **** systemSvCountDict ****
      std::map<std::string, int> systemSvCountDict() const;
      void setSystemSvCountDict(const std::map<std::string, int>& systemSvCountDict);


      // **** echoCount ****
      int echoCount() const;
      void setEchoCount(int echoCount);


      // **** interferenceSignalTypeCountDict ****
      std::optional<std::map<std::string, int>> interferenceSignalTypeCountDict() const;
      void setInterferenceSignalTypeCountDict(const std::optional<std::map<std::string, int>>& interferenceSignalTypeCountDict);
    };
    
  }
}

