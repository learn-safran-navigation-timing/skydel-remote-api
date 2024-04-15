
#include "IsOsnmaEnabledForEachSVResult.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of IsOsnmaEnabledForEachSVResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const IsOsnmaEnabledForEachSVResult::CmdName = "IsOsnmaEnabledForEachSVResult";
    const char* const IsOsnmaEnabledForEachSVResult::Documentation = "Result of IsOsnmaEnabledForEachSV.\n"
      "\n"
      "Name    Type       Description\n"
      "------- ---------- -------------------------------------------------------------------------------------------------------------\n"
      "Enabled array bool OSNMA is enabled when value is True. Zero based index (index 0 => first SV ID, index 1 => second SV ID, etc).";
    const char* const IsOsnmaEnabledForEachSVResult::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_IMPL(IsOsnmaEnabledForEachSVResult);


    IsOsnmaEnabledForEachSVResult::IsOsnmaEnabledForEachSVResult()
      : CommandResult(CmdName, TargetId)
    {}

    IsOsnmaEnabledForEachSVResult::IsOsnmaEnabledForEachSVResult(const std::vector<bool>& enabled)
      : CommandResult(CmdName, TargetId)
    {

      setEnabled(enabled);
    }

    IsOsnmaEnabledForEachSVResult::IsOsnmaEnabledForEachSVResult(CommandBasePtr relatedCommand, const std::vector<bool>& enabled)
      : CommandResult(CmdName, TargetId, relatedCommand)
    {

      setEnabled(enabled);
    }


    IsOsnmaEnabledForEachSVResultPtr IsOsnmaEnabledForEachSVResult::create(const std::vector<bool>& enabled)
    {
      return std::make_shared<IsOsnmaEnabledForEachSVResult>(enabled);
    }

    IsOsnmaEnabledForEachSVResultPtr IsOsnmaEnabledForEachSVResult::create(CommandBasePtr relatedCommand, const std::vector<bool>& enabled)
    {
      return std::make_shared<IsOsnmaEnabledForEachSVResult>(relatedCommand, enabled);
    }

    IsOsnmaEnabledForEachSVResultPtr IsOsnmaEnabledForEachSVResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<IsOsnmaEnabledForEachSVResult>(ptr);
    }

    bool IsOsnmaEnabledForEachSVResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::vector<bool>>::is_valid(m_values["Enabled"])
        ;

    }

    std::string IsOsnmaEnabledForEachSVResult::documentation() const { return Documentation; }

    const std::vector<std::string>& IsOsnmaEnabledForEachSVResult::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Enabled"}; 
      return names; 
    }


    std::vector<bool> IsOsnmaEnabledForEachSVResult::enabled() const
    {
      return parse_json<std::vector<bool>>::parse(m_values["Enabled"]);
    }

    void IsOsnmaEnabledForEachSVResult::setEnabled(const std::vector<bool>& enabled)
    {
      m_values.AddMember("Enabled", parse_json<std::vector<bool>>::format(enabled, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
