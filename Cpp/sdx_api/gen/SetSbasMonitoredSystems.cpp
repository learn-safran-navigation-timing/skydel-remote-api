
#include "gen/SetSbasMonitoredSystems.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetSbasMonitoredSystems
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetSbasMonitoredSystems::CmdName = "SetSbasMonitoredSystems";
    const char* const SetSbasMonitoredSystems::Documentation = "Set the systems monitored by SBAS.";

    REGISTER_COMMAND_FACTORY(SetSbasMonitoredSystems);


    SetSbasMonitoredSystems::SetSbasMonitoredSystems()
      : CommandBase(CmdName)
    {}

    SetSbasMonitoredSystems::SetSbasMonitoredSystems(const std::vector<std::string>& systems)
      : CommandBase(CmdName)
    {

      setSystems(systems);
    }

    SetSbasMonitoredSystemsPtr SetSbasMonitoredSystems::create(const std::vector<std::string>& systems)
    {
      return std::make_shared<SetSbasMonitoredSystems>(systems);
    }

    SetSbasMonitoredSystemsPtr SetSbasMonitoredSystems::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetSbasMonitoredSystems>(ptr);
    }

    bool SetSbasMonitoredSystems::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::vector<std::string>>::is_valid(m_values["Systems"])
        ;

    }

    std::string SetSbasMonitoredSystems::documentation() const { return Documentation; }


    int SetSbasMonitoredSystems::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::vector<std::string> SetSbasMonitoredSystems::systems() const
    {
      return parse_json<std::vector<std::string>>::parse(m_values["Systems"]);
    }

    void SetSbasMonitoredSystems::setSystems(const std::vector<std::string>& systems)
    {
      m_values.AddMember("Systems", parse_json<std::vector<std::string>>::format(systems, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
