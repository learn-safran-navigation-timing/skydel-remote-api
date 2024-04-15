
#include "IsElevationMaskAboveEnabledResult.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of IsElevationMaskAboveEnabledResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const IsElevationMaskAboveEnabledResult::CmdName = "IsElevationMaskAboveEnabledResult";
    const char* const IsElevationMaskAboveEnabledResult::Documentation = "Result of IsElevationMaskAboveEnabled.\n"
      "\n"
      "Name    Type Description\n"
      "------- ---- ------------------------------------------------------------------\n"
      "Enabled bool If true, mask satellites with elevation angle above masking angle.";
    const char* const IsElevationMaskAboveEnabledResult::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_IMPL(IsElevationMaskAboveEnabledResult);


    IsElevationMaskAboveEnabledResult::IsElevationMaskAboveEnabledResult()
      : CommandResult(CmdName, TargetId)
    {}

    IsElevationMaskAboveEnabledResult::IsElevationMaskAboveEnabledResult(bool enabled)
      : CommandResult(CmdName, TargetId)
    {

      setEnabled(enabled);
    }

    IsElevationMaskAboveEnabledResult::IsElevationMaskAboveEnabledResult(CommandBasePtr relatedCommand, bool enabled)
      : CommandResult(CmdName, TargetId, relatedCommand)
    {

      setEnabled(enabled);
    }


    IsElevationMaskAboveEnabledResultPtr IsElevationMaskAboveEnabledResult::create(bool enabled)
    {
      return std::make_shared<IsElevationMaskAboveEnabledResult>(enabled);
    }

    IsElevationMaskAboveEnabledResultPtr IsElevationMaskAboveEnabledResult::create(CommandBasePtr relatedCommand, bool enabled)
    {
      return std::make_shared<IsElevationMaskAboveEnabledResult>(relatedCommand, enabled);
    }

    IsElevationMaskAboveEnabledResultPtr IsElevationMaskAboveEnabledResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<IsElevationMaskAboveEnabledResult>(ptr);
    }

    bool IsElevationMaskAboveEnabledResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<bool>::is_valid(m_values["Enabled"])
        ;

    }

    std::string IsElevationMaskAboveEnabledResult::documentation() const { return Documentation; }

    const std::vector<std::string>& IsElevationMaskAboveEnabledResult::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Enabled"}; 
      return names; 
    }


    bool IsElevationMaskAboveEnabledResult::enabled() const
    {
      return parse_json<bool>::parse(m_values["Enabled"]);
    }

    void IsElevationMaskAboveEnabledResult::setEnabled(bool enabled)
    {
      m_values.AddMember("Enabled", parse_json<bool>::format(enabled, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
