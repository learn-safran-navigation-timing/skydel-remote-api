
#include "IsStopMainInstanceWhenWorkerInstanceStopResult.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of IsStopMainInstanceWhenWorkerInstanceStopResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const IsStopMainInstanceWhenWorkerInstanceStopResult::CmdName = "IsStopMainInstanceWhenWorkerInstanceStopResult";
    const char* const IsStopMainInstanceWhenWorkerInstanceStopResult::Documentation = "Result of IsStopMainInstanceWhenWorkerInstanceStop.\n"
      "\n"
      "Name    Type Description\n"
      "------- ---- ---------------------------------------------------------\n"
      "Enabled bool Enable main instance stop when worker instance stops flag";
    const char* const IsStopMainInstanceWhenWorkerInstanceStopResult::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_IMPL(IsStopMainInstanceWhenWorkerInstanceStopResult);


    IsStopMainInstanceWhenWorkerInstanceStopResult::IsStopMainInstanceWhenWorkerInstanceStopResult()
      : CommandResult(CmdName, TargetId)
    {}

    IsStopMainInstanceWhenWorkerInstanceStopResult::IsStopMainInstanceWhenWorkerInstanceStopResult(bool enabled)
      : CommandResult(CmdName, TargetId)
    {

      setEnabled(enabled);
    }

    IsStopMainInstanceWhenWorkerInstanceStopResult::IsStopMainInstanceWhenWorkerInstanceStopResult(CommandBasePtr relatedCommand, bool enabled)
      : CommandResult(CmdName, TargetId, relatedCommand)
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

    const std::vector<std::string>& IsStopMainInstanceWhenWorkerInstanceStopResult::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Enabled"}; 
      return names; 
    }


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
