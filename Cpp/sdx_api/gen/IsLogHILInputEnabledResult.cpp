
#include "gen/IsLogHILInputEnabledResult.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of IsLogHILInputEnabledResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const IsLogHILInputEnabledResult::CmdName = "IsLogHILInputEnabledResult";
    const char* const IsLogHILInputEnabledResult::Documentation = "Result of IsLogHILInputEnabled.";

    REGISTER_COMMAND_RESULT_TO_FACTORY_IMPL(IsLogHILInputEnabledResult);


    IsLogHILInputEnabledResult::IsLogHILInputEnabledResult()
      : CommandResult(CmdName)
    {}

    IsLogHILInputEnabledResult::IsLogHILInputEnabledResult(bool enabled)
      : CommandResult(CmdName)
    {

      setEnabled(enabled);
    }

    IsLogHILInputEnabledResult::IsLogHILInputEnabledResult(CommandBasePtr relatedCommand, bool enabled)
      : CommandResult(CmdName, relatedCommand)
    {

      setEnabled(enabled);
    }


    IsLogHILInputEnabledResultPtr IsLogHILInputEnabledResult::create(bool enabled)
    {
      return std::make_shared<IsLogHILInputEnabledResult>(enabled);
    }

    IsLogHILInputEnabledResultPtr IsLogHILInputEnabledResult::create(CommandBasePtr relatedCommand, bool enabled)
    {
      return std::make_shared<IsLogHILInputEnabledResult>(relatedCommand, enabled);
    }

    IsLogHILInputEnabledResultPtr IsLogHILInputEnabledResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<IsLogHILInputEnabledResult>(ptr);
    }

    bool IsLogHILInputEnabledResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<bool>::is_valid(m_values["Enabled"])
        ;

    }

    std::string IsLogHILInputEnabledResult::documentation() const { return Documentation; }


    bool IsLogHILInputEnabledResult::enabled() const
    {
      return parse_json<bool>::parse(m_values["Enabled"]);
    }

    void IsLogHILInputEnabledResult::setEnabled(bool enabled)
    {
      m_values.AddMember("Enabled", parse_json<bool>::format(enabled, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
