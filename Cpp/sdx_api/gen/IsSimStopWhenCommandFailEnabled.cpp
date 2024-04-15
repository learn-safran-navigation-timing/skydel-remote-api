
#include "IsSimStopWhenCommandFailEnabled.h"

#include "command_factory.h"
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
    const char* const IsSimStopWhenCommandFailEnabled::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(IsSimStopWhenCommandFailEnabled);
    REGISTER_COMMAND_TO_FACTORY_IMPL(IsSimStopWhenCommandFailEnabled);


    IsSimStopWhenCommandFailEnabled::IsSimStopWhenCommandFailEnabled()
      : CommandBase(CmdName, TargetId)
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

    const std::vector<std::string>& IsSimStopWhenCommandFailEnabled::fieldNames() const 
    { 
      static const std::vector<std::string> names {}; 
      return names; 
    }


    int IsSimStopWhenCommandFailEnabled::executePermission() const
    {
      return EXECUTE_IF_IDLE | EXECUTE_IF_SIMULATING;
    }

  }
}
