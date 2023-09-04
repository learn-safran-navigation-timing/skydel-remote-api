
#include "gen/ExecuteGpuBenchmarkResult.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of ExecuteGpuBenchmarkResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const ExecuteGpuBenchmarkResult::CmdName = "ExecuteGpuBenchmarkResult";
    const char* const ExecuteGpuBenchmarkResult::Documentation = "Result of the GPU benchmark execution.";

    REGISTER_COMMAND_RESULT_TO_FACTORY_IMPL(ExecuteGpuBenchmarkResult);


    ExecuteGpuBenchmarkResult::ExecuteGpuBenchmarkResult()
      : CommandResult(CmdName)
    {}

    ExecuteGpuBenchmarkResult::ExecuteGpuBenchmarkResult(double score)
      : CommandResult(CmdName)
    {

      setScore(score);
    }

    ExecuteGpuBenchmarkResult::ExecuteGpuBenchmarkResult(CommandBasePtr relatedCommand, double score)
      : CommandResult(CmdName, relatedCommand)
    {

      setScore(score);
    }


    ExecuteGpuBenchmarkResultPtr ExecuteGpuBenchmarkResult::create(double score)
    {
      return std::make_shared<ExecuteGpuBenchmarkResult>(score);
    }

    ExecuteGpuBenchmarkResultPtr ExecuteGpuBenchmarkResult::create(CommandBasePtr relatedCommand, double score)
    {
      return std::make_shared<ExecuteGpuBenchmarkResult>(relatedCommand, score);
    }

    ExecuteGpuBenchmarkResultPtr ExecuteGpuBenchmarkResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<ExecuteGpuBenchmarkResult>(ptr);
    }

    bool ExecuteGpuBenchmarkResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<double>::is_valid(m_values["Score"])
        ;

    }

    std::string ExecuteGpuBenchmarkResult::documentation() const { return Documentation; }


    double ExecuteGpuBenchmarkResult::score() const
    {
      return parse_json<double>::parse(m_values["Score"]);
    }

    void ExecuteGpuBenchmarkResult::setScore(double score)
    {
      m_values.AddMember("Score", parse_json<double>::format(score, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
