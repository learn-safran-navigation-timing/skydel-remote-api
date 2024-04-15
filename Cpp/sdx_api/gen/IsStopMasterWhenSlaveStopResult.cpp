
#include "IsStopMasterWhenSlaveStopResult.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of IsStopMasterWhenSlaveStopResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const IsStopMasterWhenSlaveStopResult::CmdName = "IsStopMasterWhenSlaveStopResult";
    const char* const IsStopMasterWhenSlaveStopResult::Documentation = "Result of IsStopMasterWhenSlaveStop.\n"
      "\n"
      "Name    Type Description\n"
      "------- ---- ---------------------------------------\n"
      "Enabled bool Enable master stop when slave fail flag";
    const char* const IsStopMasterWhenSlaveStopResult::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_IMPL(IsStopMasterWhenSlaveStopResult);


    IsStopMasterWhenSlaveStopResult::IsStopMasterWhenSlaveStopResult()
      : CommandResult(CmdName, TargetId)
    {}

    IsStopMasterWhenSlaveStopResult::IsStopMasterWhenSlaveStopResult(bool enabled)
      : CommandResult(CmdName, TargetId)
    {

      setEnabled(enabled);
    }

    IsStopMasterWhenSlaveStopResult::IsStopMasterWhenSlaveStopResult(CommandBasePtr relatedCommand, bool enabled)
      : CommandResult(CmdName, TargetId, relatedCommand)
    {

      setEnabled(enabled);
    }


    IsStopMasterWhenSlaveStopResultPtr IsStopMasterWhenSlaveStopResult::create(bool enabled)
    {
      return std::make_shared<IsStopMasterWhenSlaveStopResult>(enabled);
    }

    IsStopMasterWhenSlaveStopResultPtr IsStopMasterWhenSlaveStopResult::create(CommandBasePtr relatedCommand, bool enabled)
    {
      return std::make_shared<IsStopMasterWhenSlaveStopResult>(relatedCommand, enabled);
    }

    IsStopMasterWhenSlaveStopResultPtr IsStopMasterWhenSlaveStopResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<IsStopMasterWhenSlaveStopResult>(ptr);
    }

    bool IsStopMasterWhenSlaveStopResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<bool>::is_valid(m_values["Enabled"])
        ;

    }

    std::string IsStopMasterWhenSlaveStopResult::documentation() const { return Documentation; }

    const std::vector<std::string>& IsStopMasterWhenSlaveStopResult::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Enabled"}; 
      return names; 
    }


    bool IsStopMasterWhenSlaveStopResult::enabled() const
    {
      return parse_json<bool>::parse(m_values["Enabled"]);
    }

    void IsStopMasterWhenSlaveStopResult::setEnabled(bool enabled)
    {
      m_values.AddMember("Enabled", parse_json<bool>::format(enabled, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
