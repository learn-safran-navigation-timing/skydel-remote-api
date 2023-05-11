
#include "gen/IsSimStopWhenCommandFailEnabled.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of IsSimStopWhenCommandFailEnabled
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const IsSimStopWhenCommandFailEnabled::CmdName = "IsSimStopWhenCommandFailEnabled";
    const char* const IsSimStopWhenCommandFailEnabled::Documentation = "If enabled, simulation stops when a command result fail.";

    REGISTER_COMMAND_FACTORY(IsSimStopWhenCommandFailEnabled);


    IsSimStopWhenCommandFailEnabled::IsSimStopWhenCommandFailEnabled()
      : CommandBase(CmdName)
    {

    }

    IsSimStopWhenCommandFailEnabledPtr IsSimStopWhenCommandFailEnabled::create()
    {
      return std::make_shared<IsSimStopWhenCommandFailEnabled>();
    }

    IsSimStopWhenCommandFailEnabledPtr IsSimStopWhenCommandFailEnabled::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<IsSimStopWhenCommandFailEnabled>(ptr);
    }

    bool IsSimStopWhenCommandFailEnabled::isValid() const
    {
      
        return m_values.IsObject()
        ;

    }

    std::string IsSimStopWhenCommandFailEnabled::documentation() const { return Documentation; }


    int IsSimStopWhenCommandFailEnabled::executePermission() const
    {
      return EXECUTE_IF_IDLE | EXECUTE_IF_SIMULATING;
    }

  }
}
