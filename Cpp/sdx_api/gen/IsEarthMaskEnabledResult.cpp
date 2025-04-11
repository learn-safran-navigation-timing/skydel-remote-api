
#include "IsEarthMaskEnabledResult.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of IsEarthMaskEnabledResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const IsEarthMaskEnabledResult::CmdName = "IsEarthMaskEnabledResult";
    const char* const IsEarthMaskEnabledResult::Documentation = "Result of IsEarthMaskEnabled.\n"
      "\n"
      "Name    Type Description\n"
      "------- ---- ----------------------------------------------------------------------------------------------\n"
      "Enabled bool If disabled, all satellites will be visible, thereby eliminating the Earth's occlusion effect.";
    const char* const IsEarthMaskEnabledResult::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_IMPL(IsEarthMaskEnabledResult);


    IsEarthMaskEnabledResult::IsEarthMaskEnabledResult()
      : CommandResult(CmdName, TargetId)
    {}

    IsEarthMaskEnabledResult::IsEarthMaskEnabledResult(bool enabled)
      : CommandResult(CmdName, TargetId)
    {

      setEnabled(enabled);
    }

    IsEarthMaskEnabledResult::IsEarthMaskEnabledResult(CommandBasePtr relatedCommand, bool enabled)
      : CommandResult(CmdName, TargetId, relatedCommand)
    {

      setEnabled(enabled);
    }


    IsEarthMaskEnabledResultPtr IsEarthMaskEnabledResult::create(bool enabled)
    {
      return std::make_shared<IsEarthMaskEnabledResult>(enabled);
    }

    IsEarthMaskEnabledResultPtr IsEarthMaskEnabledResult::create(CommandBasePtr relatedCommand, bool enabled)
    {
      return std::make_shared<IsEarthMaskEnabledResult>(relatedCommand, enabled);
    }

    IsEarthMaskEnabledResultPtr IsEarthMaskEnabledResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<IsEarthMaskEnabledResult>(ptr);
    }

    bool IsEarthMaskEnabledResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<bool>::is_valid(m_values["Enabled"])
        ;

    }

    std::string IsEarthMaskEnabledResult::documentation() const { return Documentation; }

    const std::vector<std::string>& IsEarthMaskEnabledResult::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Enabled"}; 
      return names; 
    }


    bool IsEarthMaskEnabledResult::enabled() const
    {
      return parse_json<bool>::parse(m_values["Enabled"]);
    }

    void IsEarthMaskEnabledResult::setEnabled(bool enabled)
    {
      m_values.AddMember("Enabled", parse_json<bool>::format(enabled, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
