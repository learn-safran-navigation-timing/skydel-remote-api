
#include "gen/IsLogNmeaEnabled.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of IsLogNmeaEnabled
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const IsLogNmeaEnabled::CmdName = "IsLogNmeaEnabled";
    const char* const IsLogNmeaEnabled::Documentation = "Get Logging of NMEA for the simulated position enable/disable.\nIf a receiver is connected, that NMEA is saved as well.";

    REGISTER_COMMAND_FACTORY(IsLogNmeaEnabled);


    IsLogNmeaEnabled::IsLogNmeaEnabled()
      : CommandBase(CmdName)
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


    int IsLogNmeaEnabled::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }

  }
}
