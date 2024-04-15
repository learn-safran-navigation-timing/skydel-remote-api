
#include "GetEngineLatencyResult.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetEngineLatencyResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetEngineLatencyResult::CmdName = "GetEngineLatencyResult";
    const char* const GetEngineLatencyResult::Documentation = "Result of GetEngineLatency.\n"
      "\n"
      "Name    Type Description\n"
      "------- ---- ----------------------\n"
      "Latency int  Engine latency in msec";
    const char* const GetEngineLatencyResult::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_IMPL(GetEngineLatencyResult);


    GetEngineLatencyResult::GetEngineLatencyResult()
      : CommandResult(CmdName, TargetId)
    {}

    GetEngineLatencyResult::GetEngineLatencyResult(int latency)
      : CommandResult(CmdName, TargetId)
    {

      setLatency(latency);
    }

    GetEngineLatencyResult::GetEngineLatencyResult(CommandBasePtr relatedCommand, int latency)
      : CommandResult(CmdName, TargetId, relatedCommand)
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

    const std::vector<std::string>& GetEngineLatencyResult::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Latency"}; 
      return names; 
    }


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
