
#include "gen/IsAlmanacExtrapolationFromEphemerisEnabledResult.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of IsAlmanacExtrapolationFromEphemerisEnabledResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const IsAlmanacExtrapolationFromEphemerisEnabledResult::CmdName = "IsAlmanacExtrapolationFromEphemerisEnabledResult";
    const char* const IsAlmanacExtrapolationFromEphemerisEnabledResult::Documentation = "Result of IsAlmanacExtrapolationFromEphemerisEnabled.";

    REGISTER_COMMAND_RESULT_TO_FACTORY_IMPL(IsAlmanacExtrapolationFromEphemerisEnabledResult);


    IsAlmanacExtrapolationFromEphemerisEnabledResult::IsAlmanacExtrapolationFromEphemerisEnabledResult()
      : CommandResult(CmdName)
    {}

    IsAlmanacExtrapolationFromEphemerisEnabledResult::IsAlmanacExtrapolationFromEphemerisEnabledResult(bool enabled)
      : CommandResult(CmdName)
    {

      setEnabled(enabled);
    }

    IsAlmanacExtrapolationFromEphemerisEnabledResult::IsAlmanacExtrapolationFromEphemerisEnabledResult(CommandBasePtr relatedCommand, bool enabled)
      : CommandResult(CmdName, relatedCommand)
    {

      setEnabled(enabled);
    }


    IsAlmanacExtrapolationFromEphemerisEnabledResultPtr IsAlmanacExtrapolationFromEphemerisEnabledResult::create(bool enabled)
    {
      return std::make_shared<IsAlmanacExtrapolationFromEphemerisEnabledResult>(enabled);
    }

    IsAlmanacExtrapolationFromEphemerisEnabledResultPtr IsAlmanacExtrapolationFromEphemerisEnabledResult::create(CommandBasePtr relatedCommand, bool enabled)
    {
      return std::make_shared<IsAlmanacExtrapolationFromEphemerisEnabledResult>(relatedCommand, enabled);
    }

    IsAlmanacExtrapolationFromEphemerisEnabledResultPtr IsAlmanacExtrapolationFromEphemerisEnabledResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<IsAlmanacExtrapolationFromEphemerisEnabledResult>(ptr);
    }

    bool IsAlmanacExtrapolationFromEphemerisEnabledResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<bool>::is_valid(m_values["Enabled"])
        ;

    }

    std::string IsAlmanacExtrapolationFromEphemerisEnabledResult::documentation() const { return Documentation; }


    bool IsAlmanacExtrapolationFromEphemerisEnabledResult::enabled() const
    {
      return parse_json<bool>::parse(m_values["Enabled"]);
    }

    void IsAlmanacExtrapolationFromEphemerisEnabledResult::setEnabled(bool enabled)
    {
      m_values.AddMember("Enabled", parse_json<bool>::format(enabled, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
