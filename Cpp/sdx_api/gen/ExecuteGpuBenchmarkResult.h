#pragma once

#include <memory>
#include "command_result.h"
#include "command_factory.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of the GPU benchmark execution.
    ///
    /// Name  Type   Description
    /// ----- ------ -------------------------------------------------------------------------------------------------
    /// Score double Score of the GPU benchmark execution, a result over 1.15 is recommended for real-time simulation.
    ///

    class ExecuteGpuBenchmarkResult;
    typedef std::shared_ptr<ExecuteGpuBenchmarkResult> ExecuteGpuBenchmarkResultPtr;
    
    
    class ExecuteGpuBenchmarkResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      ExecuteGpuBenchmarkResult();

      ExecuteGpuBenchmarkResult(double score);

      ExecuteGpuBenchmarkResult(CommandBasePtr relatedCommand, double score);

      static ExecuteGpuBenchmarkResultPtr create(double score);

      static ExecuteGpuBenchmarkResultPtr create(CommandBasePtr relatedCommand, double score);
      static ExecuteGpuBenchmarkResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;


      // **** score ****
      double score() const;
      void setScore(double score);
    };
    REGISTER_COMMAND_TO_FACTORY_DECL(ExecuteGpuBenchmarkResult);
  }
}

