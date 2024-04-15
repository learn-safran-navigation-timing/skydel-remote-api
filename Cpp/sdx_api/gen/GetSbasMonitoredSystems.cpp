
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
    const char* const GetSbasMonitoredSystems::Documentation = "Get the systems monitored by SBAS.";
    const char* const GetSbasMonitoredSystems::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(GetSbasMonitoredSystems);
    REGISTER_COMMAND_TO_FACTORY_IMPL(GetSbasMonitoredSystems);


    GetSbasMonitoredSystems::GetSbasMonitoredSystems()
      : CommandBase(CmdName, TargetId)
    {

    }

    GetSbasMonitoredSystemsPtr GetSbasMonitoredSystems::create()
    {
      return std::make_shared<GetSbasMonitoredSystems>();
    }

    GetSbasMonitoredSystemsPtr GetSbasMonitoredSystems::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetSbasMonitoredSystems>(ptr);
    }

    bool GetSbasMonitoredSystems::isValid() const
    {
      
        return m_values.IsObject()
        ;

    }

    std::string GetSbasMonitoredSystems::documentation() const { return Documentation; }

    const std::vector<std::string>& GetSbasMonitoredSystems::fieldNames() const 
    { 
      static const std::vector<std::string> names {}; 
      return names; 
    }


    int GetSbasMonitoredSystems::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }

  }
}
