
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
      "Name            Type            Description\n"
      "--------------- --------------- ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n"
      "Systems         array string    A list containing the name of monitored systems, only \"GPS\" and \"SBAS\" are supported\n"
      "ServiceProvider optional string The service provider. When not specified for a Setter command, the change is applied to all service providers. When not specified for a Getter command, the value for WAAS is returned.";
    const char* const SetSbasMonitoredSystems::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(SetSbasMonitoredSystems);
    REGISTER_COMMAND_TO_FACTORY_IMPL(SetSbasMonitoredSystems);


    SetSbasMonitoredSystems::SetSbasMonitoredSystems()
      : CommandBase(CmdName, TargetId)
    {}

    SetSbasMonitoredSystems::SetSbasMonitoredSystems(const std::vector<std::string>& systems, const std::optional<std::string>& serviceProvider)
      : CommandBase(CmdName, TargetId)
    {

      setSystems(systems);
      setServiceProvider(serviceProvider);
    }

    SetSbasMonitoredSystemsPtr SetSbasMonitoredSystems::create(const std::vector<std::string>& systems, const std::optional<std::string>& serviceProvider)
    {
      return std::make_shared<SetSbasMonitoredSystems>(systems, serviceProvider);
    }

    SetSbasMonitoredSystemsPtr SetSbasMonitoredSystems::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetSbasMonitoredSystems>(ptr);
    }

    bool SetSbasMonitoredSystems::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::vector<std::string>>::is_valid(m_values["Systems"])
          && parse_json<std::optional<std::string>>::is_valid(m_values["ServiceProvider"])
        ;

    }

    std::string SetSbasMonitoredSystems::documentation() const { return Documentation; }

    const std::vector<std::string>& SetSbasMonitoredSystems::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Systems", "ServiceProvider"}; 
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



    std::optional<std::string> SetSbasMonitoredSystems::serviceProvider() const
    {
      return parse_json<std::optional<std::string>>::parse(m_values["ServiceProvider"]);
    }

    void SetSbasMonitoredSystems::setServiceProvider(const std::optional<std::string>& serviceProvider)
    {
      m_values.AddMember("ServiceProvider", parse_json<std::optional<std::string>>::format(serviceProvider, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
