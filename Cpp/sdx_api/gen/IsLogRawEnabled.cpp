
#include "gen/IsLogRawEnabled.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of IsLogRawEnabled
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const IsLogRawEnabled::CmdName = "IsLogRawEnabled";
    const char* const IsLogRawEnabled::Documentation = "Tells if raw data logging is enabled.";

    REGISTER_COMMAND_FACTORY(IsLogRawEnabled);


    IsLogRawEnabled::IsLogRawEnabled()
      : CommandBase(CmdName)
    {

    }

    IsLogRawEnabledPtr IsLogRawEnabled::create()
    {
      return std::make_shared<IsLogRawEnabled>();
    }

    IsLogRawEnabledPtr IsLogRawEnabled::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<IsLogRawEnabled>(ptr);
    }

    bool IsLogRawEnabled::isValid() const
    {
      
        return m_values.IsObject()
        ;

    }

    std::string IsLogRawEnabled::documentation() const { return Documentation; }


    int IsLogRawEnabled::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }

  }
}
