
#include "gen/IsLogNmeaEnabledResult.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of IsLogNmeaEnabledResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const IsLogNmeaEnabledResult::CmdName = "IsLogNmeaEnabledResult";
    const char* const IsLogNmeaEnabledResult::Documentation = "Result of IsLogNmeaEnabled.";

    REGISTER_COMMAND_RESULT_TO_FACTORY_IMPL(IsLogNmeaEnabledResult);


    IsLogNmeaEnabledResult::IsLogNmeaEnabledResult()
      : CommandResult(CmdName)
    {}

    IsLogNmeaEnabledResult::IsLogNmeaEnabledResult(bool enabled)
      : CommandResult(CmdName)
    {

      setEnabled(enabled);
    }

    IsLogNmeaEnabledResult::IsLogNmeaEnabledResult(CommandBasePtr relatedCommand, bool enabled)
      : CommandResult(CmdName, relatedCommand)
    {

      setEnabled(enabled);
    }


    IsLogNmeaEnabledResultPtr IsLogNmeaEnabledResult::create(bool enabled)
    {
      return std::make_shared<IsLogNmeaEnabledResult>(enabled);
    }

    IsLogNmeaEnabledResultPtr IsLogNmeaEnabledResult::create(CommandBasePtr relatedCommand, bool enabled)
    {
      return std::make_shared<IsLogNmeaEnabledResult>(relatedCommand, enabled);
    }

    IsLogNmeaEnabledResultPtr IsLogNmeaEnabledResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<IsLogNmeaEnabledResult>(ptr);
    }

    bool IsLogNmeaEnabledResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<bool>::is_valid(m_values["Enabled"])
        ;

    }

    std::string IsLogNmeaEnabledResult::documentation() const { return Documentation; }


    bool IsLogNmeaEnabledResult::enabled() const
    {
      return parse_json<bool>::parse(m_values["Enabled"]);
    }

    void IsLogNmeaEnabledResult::setEnabled(bool enabled)
    {
      m_values.AddMember("Enabled", parse_json<bool>::format(enabled, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
