#pragma once

#include <memory>
#include "command_base.h"

#include <map>
#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Execute the GPU benchmark and get the result score (will block Skydel's user interface).
    ///
    /// Name              Type            Description
    /// ----------------- --------------- ----------------------------------------------------------------------------
    /// DurationMs        int             Duration of execution in milliseconds.
    /// SystemSvCountDict dict string:int A dictionary of system svcount pairs.
    ///                                   Accepted keys are: "GPS", "GLONASS", "Galileo", "BeiDou", "SBAS", "QZSS" and
    ///                                                      "NavIC"
    /// EchoCount         int             Number of echos per signal.
    ///

    class ExecuteGpuBenchmark;
    typedef std::shared_ptr<ExecuteGpuBenchmark> ExecuteGpuBenchmarkPtr;
    
    
    class ExecuteGpuBenchmark : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      ExecuteGpuBenchmark();

      ExecuteGpuBenchmark(int durationMs, const std::map<std::string, int>& systemSvCountDict, int echoCount);

      static ExecuteGpuBenchmarkPtr create(int durationMs, const std::map<std::string, int>& systemSvCountDict, int echoCount);
      static ExecuteGpuBenchmarkPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

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
    };
    
  }
}

