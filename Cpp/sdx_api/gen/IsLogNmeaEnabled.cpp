
#include "IsLogNmeaEnabled.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of IsLogNmeaEnabled
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const IsLogNmeaEnabled::CmdName = "IsLogNmeaEnabled";
    const char* const IsLogNmeaEnabled::Documentation = "Get Logging of NMEA for the simulated position enable/disable.\n"
      "If a receiver is connected, that NMEA is saved as well.";
    const char* const IsLogNmeaEnabled::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(IsLogNmeaEnabled);
    REGISTER_COMMAND_TO_FACTORY_IMPL(IsLogNmeaEnabled);


    IsLogNmeaEnabled::IsLogNmeaEnabled()
      : CommandBase(CmdName, TargetId)
    {

    }

    IsLogNmeaEnabledPtr IsLogNmeaEnabled::create()
    {
      return std::make_shared<IsLogNmeaEnabled>();
    }

    IsLogNmeaEnabledPtr IsLogNmeaEnabled::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<IsLogNmeaEnabled>(ptr);
    }

    bool IsLogNmeaEnabled::isValid() const
    {
      
        return m_values.IsObject()
        ;

    }

    std::string IsLogNmeaEnabled::documentation() const { return Documentation; }

    const std::vector<std::string>& IsLogNmeaEnabled::fieldNames() const 
    { 
      static const std::vector<std::string> names {}; 
      return names; 
    }


    int IsLogNmeaEnabled::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }

  }
}
