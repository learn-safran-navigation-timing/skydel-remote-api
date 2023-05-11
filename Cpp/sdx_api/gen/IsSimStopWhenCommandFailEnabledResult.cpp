
#include "gen/IsSimStopWhenCommandFailEnabledResult.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of IsSimStopWhenCommandFailEnabledResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const IsSimStopWhenCommandFailEnabledResult::CmdName = "IsSimStopWhenCommandFailEnabledResult";
    const char* const IsSimStopWhenCommandFailEnabledResult::Documentation = "Result of IsSimStopWhenCommandFailEnabled.";

    REGISTER_COMMAND_RESULT_TO_FACTORY_IMPL(IsSimStopWhenCommandFailEnabledResult);


    IsSimStopWhenCommandFailEnabledResult::IsSimStopWhenCommandFailEnabledResult()
      : CommandResult(CmdName)
    {}

    IsSimStopWhenCommandFailEnabledResult::IsSimStopWhenCommandFailEnabledResult(bool enabled)
      : CommandResult(CmdName)
    {

      setEnabled(enabled);
    }

    IsSimStopWhenCommandFailEnabledResult::IsSimStopWhenCommandFailEnabledResult(CommandBasePtr relatedCommand, bool enabled)
      : CommandResult(CmdName, relatedCommand)
    {

      setEnabled(enabled);
    }


    IsSimStopWhenCommandFailEnabledResultPtr IsSimStopWhenCommandFailEnabledResult::create(bool enabled)
    {
      return std::make_shared<IsSimStopWhenCommandFailEnabledResult>(enabled);
    }

    IsSimStopWhenCommandFailEnabledResultPtr IsSimStopWhenCommandFailEnabledResult::create(CommandBasePtr relatedCommand, bool enabled)
    {
      return std::make_shared<IsSimStopWhenCommandFailEnabledResult>(relatedCommand, enabled);
    }

    IsSimStopWhenCommandFailEnabledResultPtr IsSimStopWhenCommandFailEnabledResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<IsSimStopWhenCommandFailEnabledResult>(ptr);
    }

    bool IsSimStopWhenCommandFailEnabledResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<bool>::is_valid(m_values["Enabled"])
        ;

    }

    std::string IsSimStopWhenCommandFailEnabledResult::documentation() const { return Documentation; }


    bool IsSimStopWhenCommandFailEnabledResult::enabled() const
    {
      return parse_json<bool>::parse(m_values["Enabled"]);
    }

    void IsSimStopWhenCommandFailEnabledResult::setEnabled(bool enabled)
    {
      m_values.AddMember("Enabled", parse_json<bool>::format(enabled, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
