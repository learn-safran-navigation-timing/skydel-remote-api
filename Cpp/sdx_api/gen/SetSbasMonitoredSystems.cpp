
#include "SetSbasMonitoredSystems.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetSbasMonitoredSystems
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetSbasMonitoredSystems::CmdName = "SetSbasMonitoredSystems";
    const char* const SetSbasMonitoredSystems::Documentation = "Set the systems monitored by SBAS.\n"
      "\n"
      "Name    Type         Description\n"
      "------- ------------ ------------------------------------------------------------------------------------\n"
      "Systems array string A list containing the name of monitored systems, only \"GPS\" and \"SBAS\" are supported";
    const char* const SetSbasMonitoredSystems::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(SetSbasMonitoredSystems);
    REGISTER_COMMAND_TO_FACTORY_IMPL(SetSbasMonitoredSystems);


    SetSbasMonitoredSystems::SetSbasMonitoredSystems()
      : CommandBase(CmdName, TargetId)
    {}

    SetSbasMonitoredSystems::SetSbasMonitoredSystems(const std::vector<std::string>& systems)
      : CommandBase(CmdName, TargetId)
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

    const std::vector<std::string>& SetSbasMonitoredSystems::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Systems"}; 
      return names; 
    }


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
