
#include "gen/GetSbasMonitoredSystemsResult.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetSbasMonitoredSystemsResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetSbasMonitoredSystemsResult::CmdName = "GetSbasMonitoredSystemsResult";
    const char* const GetSbasMonitoredSystemsResult::Documentation = "Result of GetSbasMonitoredSystems.";

    REGISTER_COMMAND_RESULT_TO_FACTORY_IMPL(GetSbasMonitoredSystemsResult);


    GetSbasMonitoredSystemsResult::GetSbasMonitoredSystemsResult()
      : CommandResult(CmdName)
    {}

    GetSbasMonitoredSystemsResult::GetSbasMonitoredSystemsResult(const std::vector<std::string>& systems)
      : CommandResult(CmdName)
    {

      setSystems(systems);
    }

    GetSbasMonitoredSystemsResult::GetSbasMonitoredSystemsResult(CommandBasePtr relatedCommand, const std::vector<std::string>& systems)
      : CommandResult(CmdName, relatedCommand)
    {

      setSystems(systems);
    }


    GetSbasMonitoredSystemsResultPtr GetSbasMonitoredSystemsResult::create(const std::vector<std::string>& systems)
    {
      return std::make_shared<GetSbasMonitoredSystemsResult>(systems);
    }

    GetSbasMonitoredSystemsResultPtr GetSbasMonitoredSystemsResult::create(CommandBasePtr relatedCommand, const std::vector<std::string>& systems)
    {
      return std::make_shared<GetSbasMonitoredSystemsResult>(relatedCommand, systems);
    }

    GetSbasMonitoredSystemsResultPtr GetSbasMonitoredSystemsResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetSbasMonitoredSystemsResult>(ptr);
    }

    bool GetSbasMonitoredSystemsResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::vector<std::string>>::is_valid(m_values["Systems"])
        ;

    }

    std::string GetSbasMonitoredSystemsResult::documentation() const { return Documentation; }


    std::vector<std::string> GetSbasMonitoredSystemsResult::systems() const
    {
      return parse_json<std::vector<std::string>>::parse(m_values["Systems"]);
    }

    void GetSbasMonitoredSystemsResult::setSystems(const std::vector<std::string>& systems)
    {
      m_values.AddMember("Systems", parse_json<std::vector<std::string>>::format(systems, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
