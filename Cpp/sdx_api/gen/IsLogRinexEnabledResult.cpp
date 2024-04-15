
#include "IsLogRinexEnabledResult.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of IsLogRinexEnabledResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const IsLogRinexEnabledResult::CmdName = "IsLogRinexEnabledResult";
    const char* const IsLogRinexEnabledResult::Documentation = "Result of IsLogRinexEnabled.\n"
      "\n"
      "Name    Type Description\n"
      "------- ---- ------------------------------------------------\n"
      "Enabled bool If true, files will be created during simulation";
    const char* const IsLogRinexEnabledResult::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_IMPL(IsLogRinexEnabledResult);


    IsLogRinexEnabledResult::IsLogRinexEnabledResult()
      : CommandResult(CmdName, TargetId)
    {}

    IsLogRinexEnabledResult::IsLogRinexEnabledResult(bool enabled)
      : CommandResult(CmdName, TargetId)
    {

      setEnabled(enabled);
    }

    IsLogRinexEnabledResult::IsLogRinexEnabledResult(CommandBasePtr relatedCommand, bool enabled)
      : CommandResult(CmdName, TargetId, relatedCommand)
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

    const std::vector<std::string>& IsLogRinexEnabledResult::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Enabled"}; 
      return names; 
    }


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
