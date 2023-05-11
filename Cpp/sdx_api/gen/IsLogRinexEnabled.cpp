
#include "gen/IsLogRinexEnabled.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of IsLogRinexEnabled
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const IsLogRinexEnabled::CmdName = "IsLogRinexEnabled";
    const char* const IsLogRinexEnabled::Documentation = "Tells if ephemeris data Logging is enabled";

    REGISTER_COMMAND_FACTORY(IsLogRinexEnabled);


    IsLogRinexEnabled::IsLogRinexEnabled()
      : CommandBase(CmdName)
    {

    }

    IsLogRinexEnabledPtr IsLogRinexEnabled::create()
    {
      return std::make_shared<IsLogRinexEnabled>();
    }

    IsLogRinexEnabledPtr IsLogRinexEnabled::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<IsLogRinexEnabled>(ptr);
    }

    bool IsLogRinexEnabled::isValid() const
    {
      
        return m_values.IsObject()
        ;

    }

    std::string IsLogRinexEnabled::documentation() const { return Documentation; }


    int IsLogRinexEnabled::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }

  }
}
