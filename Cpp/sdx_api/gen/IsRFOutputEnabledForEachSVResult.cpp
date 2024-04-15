
#include "IsRFOutputEnabledForEachSVResult.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of IsRFOutputEnabledForEachSVResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const IsRFOutputEnabledForEachSVResult::CmdName = "IsRFOutputEnabledForEachSVResult";
    const char* const IsRFOutputEnabledForEachSVResult::Documentation = "Result of IsRFOutputEnabledForEachSV.\n"
      "\n"
      "Name    Type       Description\n"
      "------- ---------- -------------------------------------------------------------------------------------------------\n"
      "System  string     \"GPS\", \"GLONASS\", \"Galileo\", \"BeiDou\", \"SBAS\", \"QZSS\", \"NavIC\" or \"PULSAR\"\n"
      "Enabled array bool RF is enabled when value is True. Zero based index (index 0 => SV ID 1, index 1 => SV ID 2, etc).";
    const char* const IsRFOutputEnabledForEachSVResult::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_IMPL(IsRFOutputEnabledForEachSVResult);


    IsRFOutputEnabledForEachSVResult::IsRFOutputEnabledForEachSVResult()
      : CommandResult(CmdName, TargetId)
    {}

    IsRFOutputEnabledForEachSVResult::IsRFOutputEnabledForEachSVResult(const std::string& system, const std::vector<bool>& enabled)
      : CommandResult(CmdName, TargetId)
    {

      setSystem(system);
      setEnabled(enabled);
    }

    IsRFOutputEnabledForEachSVResult::IsRFOutputEnabledForEachSVResult(CommandBasePtr relatedCommand, const std::string& system, const std::vector<bool>& enabled)
      : CommandResult(CmdName, TargetId, relatedCommand)
    {

      setSystem(system);
      setEnabled(enabled);
    }


    IsRFOutputEnabledForEachSVResultPtr IsRFOutputEnabledForEachSVResult::create(const std::string& system, const std::vector<bool>& enabled)
    {
      return std::make_shared<IsRFOutputEnabledForEachSVResult>(system, enabled);
    }

    IsRFOutputEnabledForEachSVResultPtr IsRFOutputEnabledForEachSVResult::create(CommandBasePtr relatedCommand, const std::string& system, const std::vector<bool>& enabled)
    {
      return std::make_shared<IsRFOutputEnabledForEachSVResult>(relatedCommand, system, enabled);
    }

    IsRFOutputEnabledForEachSVResultPtr IsRFOutputEnabledForEachSVResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<IsRFOutputEnabledForEachSVResult>(ptr);
    }

    bool IsRFOutputEnabledForEachSVResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["System"])
          && parse_json<std::vector<bool>>::is_valid(m_values["Enabled"])
        ;

    }

    std::string IsRFOutputEnabledForEachSVResult::documentation() const { return Documentation; }

    const std::vector<std::string>& IsRFOutputEnabledForEachSVResult::fieldNames() const 
    { 
      static const std::vector<std::string> names {"System", "Enabled"}; 
      return names; 
    }


    std::string IsRFOutputEnabledForEachSVResult::system() const
    {
      return parse_json<std::string>::parse(m_values["System"]);
    }

    void IsRFOutputEnabledForEachSVResult::setSystem(const std::string& system)
    {
      m_values.AddMember("System", parse_json<std::string>::format(system, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::vector<bool> IsRFOutputEnabledForEachSVResult::enabled() const
    {
      return parse_json<std::vector<bool>>::parse(m_values["Enabled"]);
    }

    void IsRFOutputEnabledForEachSVResult::setEnabled(const std::vector<bool>& enabled)
    {
      m_values.AddMember("Enabled", parse_json<std::vector<bool>>::format(enabled, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
