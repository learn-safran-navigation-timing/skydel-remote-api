
#include "gen/IsLogRawEnabledResult.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of IsLogRawEnabledResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const IsLogRawEnabledResult::CmdName = "IsLogRawEnabledResult";
    const char* const IsLogRawEnabledResult::Documentation = "Result of IsLogRawEnabled.";

    REGISTER_COMMAND_RESULT_TO_FACTORY_IMPL(IsLogRawEnabledResult);


    IsLogRawEnabledResult::IsLogRawEnabledResult()
      : CommandResult(CmdName)
    {}

    IsLogRawEnabledResult::IsLogRawEnabledResult(bool enabled)
      : CommandResult(CmdName)
    {

      setEnabled(enabled);
    }

    IsLogRawEnabledResult::IsLogRawEnabledResult(CommandBasePtr relatedCommand, bool enabled)
      : CommandResult(CmdName, relatedCommand)
    {

      setEnabled(enabled);
    }


    IsLogRawEnabledResultPtr IsLogRawEnabledResult::create(bool enabled)
    {
      return std::make_shared<IsLogRawEnabledResult>(enabled);
    }

    IsLogRawEnabledResultPtr IsLogRawEnabledResult::create(CommandBasePtr relatedCommand, bool enabled)
    {
      return std::make_shared<IsLogRawEnabledResult>(relatedCommand, enabled);
    }

    IsLogRawEnabledResultPtr IsLogRawEnabledResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<IsLogRawEnabledResult>(ptr);
    }

    bool IsLogRawEnabledResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<bool>::is_valid(m_values["Enabled"])
        ;

    }

    std::string IsLogRawEnabledResult::documentation() const { return Documentation; }


    bool IsLogRawEnabledResult::enabled() const
    {
      return parse_json<bool>::parse(m_values["Enabled"]);
    }

    void IsLogRawEnabledResult::setEnabled(bool enabled)
    {
      m_values.AddMember("Enabled", parse_json<bool>::format(enabled, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
