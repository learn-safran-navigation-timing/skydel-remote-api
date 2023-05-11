
#include "gen/GetEngineLatencyResult.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetEngineLatencyResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetEngineLatencyResult::CmdName = "GetEngineLatencyResult";
    const char* const GetEngineLatencyResult::Documentation = "Result of GetEngineLatency.";

    REGISTER_COMMAND_RESULT_TO_FACTORY_IMPL(GetEngineLatencyResult);


    GetEngineLatencyResult::GetEngineLatencyResult()
      : CommandResult(CmdName)
    {}

    GetEngineLatencyResult::GetEngineLatencyResult(int latency)
      : CommandResult(CmdName)
    {

      setLatency(latency);
    }

    GetEngineLatencyResult::GetEngineLatencyResult(CommandBasePtr relatedCommand, int latency)
      : CommandResult(CmdName, relatedCommand)
    {

      setLatency(latency);
    }


    GetEngineLatencyResultPtr GetEngineLatencyResult::create(int latency)
    {
      return std::make_shared<GetEngineLatencyResult>(latency);
    }

    GetEngineLatencyResultPtr GetEngineLatencyResult::create(CommandBasePtr relatedCommand, int latency)
    {
      return std::make_shared<GetEngineLatencyResult>(relatedCommand, latency);
    }

    GetEngineLatencyResultPtr GetEngineLatencyResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetEngineLatencyResult>(ptr);
    }

    bool GetEngineLatencyResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["Latency"])
        ;

    }

    std::string GetEngineLatencyResult::documentation() const { return Documentation; }


    int GetEngineLatencyResult::latency() const
    {
      return parse_json<int>::parse(m_values["Latency"]);
    }

    void GetEngineLatencyResult::setLatency(int latency)
    {
      m_values.AddMember("Latency", parse_json<int>::format(latency, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
