
#include "GetSbasMonitoredSystems.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetSbasMonitoredSystems
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetSbasMonitoredSystems::CmdName = "GetSbasMonitoredSystems";
    const char* const GetSbasMonitoredSystems::Documentation = "Get the systems monitored by SBAS.\n"
      "\n"
      "Name            Type            Description\n"
      "--------------- --------------- ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n"
      "ServiceProvider optional string The service provider. When not specified for a Setter command, the change is applied to all service providers. When not specified for a Getter command, the value for WAAS is returned.";
    const char* const GetSbasMonitoredSystems::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(GetSbasMonitoredSystems);
    REGISTER_COMMAND_TO_FACTORY_IMPL(GetSbasMonitoredSystems);


    GetSbasMonitoredSystems::GetSbasMonitoredSystems(const std::optional<std::string>& serviceProvider)
      : CommandBase(CmdName, TargetId)
    {

      setServiceProvider(serviceProvider);
    }

    GetSbasMonitoredSystemsPtr GetSbasMonitoredSystems::create(const std::optional<std::string>& serviceProvider)
    {
      return std::make_shared<GetSbasMonitoredSystems>(serviceProvider);
    }

    GetSbasMonitoredSystemsPtr GetSbasMonitoredSystems::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetSbasMonitoredSystems>(ptr);
    }

    bool GetSbasMonitoredSystems::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::optional<std::string>>::is_valid(m_values["ServiceProvider"])
        ;

    }

    std::string GetSbasMonitoredSystems::documentation() const { return Documentation; }

    const std::vector<std::string>& GetSbasMonitoredSystems::fieldNames() const 
    { 
      static const std::vector<std::string> names {"ServiceProvider"}; 
      return names; 
    }


    int GetSbasMonitoredSystems::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::optional<std::string> GetSbasMonitoredSystems::serviceProvider() const
    {
      return parse_json<std::optional<std::string>>::parse(m_values["ServiceProvider"]);
    }

    void GetSbasMonitoredSystems::setServiceProvider(const std::optional<std::string>& serviceProvider)
    {
      m_values.AddMember("ServiceProvider", parse_json<std::optional<std::string>>::format(serviceProvider, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
