
#include "IsEachSVEnabledResult.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of IsEachSVEnabledResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const IsEachSVEnabledResult::CmdName = "IsEachSVEnabledResult";
    const char* const IsEachSVEnabledResult::Documentation = "Result of IsEachSVEnabled.\n"
      "\n"
      "Name    Type       Description\n"
      "------- ---------- ----------------------------------------------------------------------------------------------------------------\n"
      "System  string     The satellites' constellation. Can be \"GPS\", \"GLONASS\", \"Galileo\", \"BeiDou\", \"SBAS\", \"QZSS\", \"NavIC\" or \"PULSAR\"\n"
      "Enabled array bool Array of present/absent flags for the constellation";
    const char* const IsEachSVEnabledResult::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_IMPL(IsEachSVEnabledResult);


    IsEachSVEnabledResult::IsEachSVEnabledResult()
      : CommandResult(CmdName, TargetId)
    {}

    IsEachSVEnabledResult::IsEachSVEnabledResult(const std::string& system, const std::vector<bool>& enabled)
      : CommandResult(CmdName, TargetId)
    {

      setSystem(system);
      setEnabled(enabled);
    }

    IsEachSVEnabledResult::IsEachSVEnabledResult(CommandBasePtr relatedCommand, const std::string& system, const std::vector<bool>& enabled)
      : CommandResult(CmdName, TargetId, relatedCommand)
    {

      setSystem(system);
      setEnabled(enabled);
    }


    IsEachSVEnabledResultPtr IsEachSVEnabledResult::create(const std::string& system, const std::vector<bool>& enabled)
    {
      return std::make_shared<IsEachSVEnabledResult>(system, enabled);
    }

    IsEachSVEnabledResultPtr IsEachSVEnabledResult::create(CommandBasePtr relatedCommand, const std::string& system, const std::vector<bool>& enabled)
    {
      return std::make_shared<IsEachSVEnabledResult>(relatedCommand, system, enabled);
    }

    IsEachSVEnabledResultPtr IsEachSVEnabledResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<IsEachSVEnabledResult>(ptr);
    }

    bool IsEachSVEnabledResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["System"])
          && parse_json<std::vector<bool>>::is_valid(m_values["Enabled"])
        ;

    }

    std::string IsEachSVEnabledResult::documentation() const { return Documentation; }

    const std::vector<std::string>& IsEachSVEnabledResult::fieldNames() const 
    { 
      static const std::vector<std::string> names {"System", "Enabled"}; 
      return names; 
    }


    std::string IsEachSVEnabledResult::system() const
    {
      return parse_json<std::string>::parse(m_values["System"]);
    }

    void IsEachSVEnabledResult::setSystem(const std::string& system)
    {
      m_values.AddMember("System", parse_json<std::string>::format(system, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::vector<bool> IsEachSVEnabledResult::enabled() const
    {
      return parse_json<std::vector<bool>>::parse(m_values["Enabled"]);
    }

    void IsEachSVEnabledResult::setEnabled(const std::vector<bool>& enabled)
    {
      m_values.AddMember("Enabled", parse_json<std::vector<bool>>::format(enabled, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
