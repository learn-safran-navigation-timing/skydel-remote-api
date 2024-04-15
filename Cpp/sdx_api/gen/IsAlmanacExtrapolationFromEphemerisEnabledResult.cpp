
#include "IsAlmanacExtrapolationFromEphemerisEnabledResult.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of IsAlmanacExtrapolationFromEphemerisEnabledResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const IsAlmanacExtrapolationFromEphemerisEnabledResult::CmdName = "IsAlmanacExtrapolationFromEphemerisEnabledResult";
    const char* const IsAlmanacExtrapolationFromEphemerisEnabledResult::Documentation = "Result of IsAlmanacExtrapolationFromEphemerisEnabled.\n"
      "\n"
      "Name    Type Description\n"
      "------- ---- -------------------------------\n"
      "Enabled bool State of almanac extrapolation.";
    const char* const IsAlmanacExtrapolationFromEphemerisEnabledResult::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_IMPL(IsAlmanacExtrapolationFromEphemerisEnabledResult);


    IsAlmanacExtrapolationFromEphemerisEnabledResult::IsAlmanacExtrapolationFromEphemerisEnabledResult()
      : CommandResult(CmdName, TargetId)
    {}

    IsAlmanacExtrapolationFromEphemerisEnabledResult::IsAlmanacExtrapolationFromEphemerisEnabledResult(bool enabled)
      : CommandResult(CmdName, TargetId)
    {

      setEnabled(enabled);
    }

    IsAlmanacExtrapolationFromEphemerisEnabledResult::IsAlmanacExtrapolationFromEphemerisEnabledResult(CommandBasePtr relatedCommand, bool enabled)
      : CommandResult(CmdName, TargetId, relatedCommand)
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

    const std::vector<std::string>& IsAlmanacExtrapolationFromEphemerisEnabledResult::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Enabled"}; 
      return names; 
    }


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
