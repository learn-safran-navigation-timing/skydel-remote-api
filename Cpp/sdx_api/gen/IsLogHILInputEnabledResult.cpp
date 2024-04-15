
#include "IsLogHILInputEnabledResult.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of IsLogHILInputEnabledResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const IsLogHILInputEnabledResult::CmdName = "IsLogHILInputEnabledResult";
    const char* const IsLogHILInputEnabledResult::Documentation = "Result of IsLogHILInputEnabled.\n"
      "\n"
      "Name    Type Description\n"
      "------- ---- ------------------------------------------------\n"
      "Enabled bool If true, files will be created during simulation";
    const char* const IsLogHILInputEnabledResult::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_IMPL(IsLogHILInputEnabledResult);


    IsLogHILInputEnabledResult::IsLogHILInputEnabledResult()
      : CommandResult(CmdName, TargetId)
    {}

    IsLogHILInputEnabledResult::IsLogHILInputEnabledResult(bool enabled)
      : CommandResult(CmdName, TargetId)
    {

      setEnabled(enabled);
    }

    IsLogHILInputEnabledResult::IsLogHILInputEnabledResult(CommandBasePtr relatedCommand, bool enabled)
      : CommandResult(CmdName, TargetId, relatedCommand)
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

    const std::vector<std::string>& IsLogHILInputEnabledResult::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Enabled"}; 
      return names; 
    }


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
