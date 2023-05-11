
#include "gen/IsLogRinexEnabledResult.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of IsLogRinexEnabledResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const IsLogRinexEnabledResult::CmdName = "IsLogRinexEnabledResult";
    const char* const IsLogRinexEnabledResult::Documentation = "Result of IsLogRinexEnabled.";

    REGISTER_COMMAND_RESULT_TO_FACTORY_IMPL(IsLogRinexEnabledResult);


    IsLogRinexEnabledResult::IsLogRinexEnabledResult()
      : CommandResult(CmdName)
    {}

    IsLogRinexEnabledResult::IsLogRinexEnabledResult(bool enabled)
      : CommandResult(CmdName)
    {

      setEnabled(enabled);
    }

    IsLogRinexEnabledResult::IsLogRinexEnabledResult(CommandBasePtr relatedCommand, bool enabled)
      : CommandResult(CmdName, relatedCommand)
    {

      setEnabled(enabled);
    }


    IsLogRinexEnabledResultPtr IsLogRinexEnabledResult::create(bool enabled)
    {
      return std::make_shared<IsLogRinexEnabledResult>(enabled);
    }

    IsLogRinexEnabledResultPtr IsLogRinexEnabledResult::create(CommandBasePtr relatedCommand, bool enabled)
    {
      return std::make_shared<IsLogRinexEnabledResult>(relatedCommand, enabled);
    }

    IsLogRinexEnabledResultPtr IsLogRinexEnabledResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<IsLogRinexEnabledResult>(ptr);
    }

    bool IsLogRinexEnabledResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<bool>::is_valid(m_values["Enabled"])
        ;

    }

    std::string IsLogRinexEnabledResult::documentation() const { return Documentation; }


    bool IsLogRinexEnabledResult::enabled() const
    {
      return parse_json<bool>::parse(m_values["Enabled"]);
    }

    void IsLogRinexEnabledResult::setEnabled(bool enabled)
    {
      m_values.AddMember("Enabled", parse_json<bool>::format(enabled, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
