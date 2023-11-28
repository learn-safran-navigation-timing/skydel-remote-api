
#include "gen/IsStopMainInstanceWhenWorkerInstanceStopResult.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of IsStopMainInstanceWhenWorkerInstanceStopResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const IsStopMainInstanceWhenWorkerInstanceStopResult::CmdName = "IsStopMainInstanceWhenWorkerInstanceStopResult";
    const char* const IsStopMainInstanceWhenWorkerInstanceStopResult::Documentation = "Result of IsStopMainInstanceWhenWorkerInstanceStop.";

    REGISTER_COMMAND_RESULT_TO_FACTORY_IMPL(IsStopMainInstanceWhenWorkerInstanceStopResult);


    IsStopMainInstanceWhenWorkerInstanceStopResult::IsStopMainInstanceWhenWorkerInstanceStopResult()
      : CommandResult(CmdName)
    {}

    IsStopMainInstanceWhenWorkerInstanceStopResult::IsStopMainInstanceWhenWorkerInstanceStopResult(bool enabled)
      : CommandResult(CmdName)
    {

      setEnabled(enabled);
    }

    IsStopMainInstanceWhenWorkerInstanceStopResult::IsStopMainInstanceWhenWorkerInstanceStopResult(CommandBasePtr relatedCommand, bool enabled)
      : CommandResult(CmdName, relatedCommand)
    {

      setEnabled(enabled);
    }


    IsStopMainInstanceWhenWorkerInstanceStopResultPtr IsStopMainInstanceWhenWorkerInstanceStopResult::create(bool enabled)
    {
      return std::make_shared<IsStopMainInstanceWhenWorkerInstanceStopResult>(enabled);
    }

    IsStopMainInstanceWhenWorkerInstanceStopResultPtr IsStopMainInstanceWhenWorkerInstanceStopResult::create(CommandBasePtr relatedCommand, bool enabled)
    {
      return std::make_shared<IsStopMainInstanceWhenWorkerInstanceStopResult>(relatedCommand, enabled);
    }

    IsStopMainInstanceWhenWorkerInstanceStopResultPtr IsStopMainInstanceWhenWorkerInstanceStopResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<IsStopMainInstanceWhenWorkerInstanceStopResult>(ptr);
    }

    bool IsStopMainInstanceWhenWorkerInstanceStopResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<bool>::is_valid(m_values["Enabled"])
        ;

    }

    std::string IsStopMainInstanceWhenWorkerInstanceStopResult::documentation() const { return Documentation; }


    bool IsStopMainInstanceWhenWorkerInstanceStopResult::enabled() const
    {
      return parse_json<bool>::parse(m_values["Enabled"]);
    }

    void IsStopMainInstanceWhenWorkerInstanceStopResult::setEnabled(bool enabled)
    {
      m_values.AddMember("Enabled", parse_json<bool>::format(enabled, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
