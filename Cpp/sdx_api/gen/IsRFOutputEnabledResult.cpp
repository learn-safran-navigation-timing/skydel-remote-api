
#include "IsRFOutputEnabledResult.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of IsRFOutputEnabledResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const IsRFOutputEnabledResult::CmdName = "IsRFOutputEnabledResult";
    const char* const IsRFOutputEnabledResult::Documentation = "Result of IsRFOutputEnabled.\n"
      "\n"
      "Name    Type   Description\n"
      "------- ------ --------------------------------------------------------------------------\n"
      "System  string \"GPS\", \"GLONASS\", \"Galileo\", \"BeiDou\", \"SBAS\", \"QZSS\", \"NavIC\" or \"PULSAR\"\n"
      "SvId    int    The satellite's SV ID\n"
      "Enabled bool   RF is enabled when value is True";
    const char* const IsRFOutputEnabledResult::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_IMPL(IsRFOutputEnabledResult);


    IsRFOutputEnabledResult::IsRFOutputEnabledResult()
      : CommandResult(CmdName, TargetId)
    {}

    IsRFOutputEnabledResult::IsRFOutputEnabledResult(const std::string& system, int svId, bool enabled)
      : CommandResult(CmdName, TargetId)
    {

      setSystem(system);
      setSvId(svId);
      setEnabled(enabled);
    }

    IsRFOutputEnabledResult::IsRFOutputEnabledResult(CommandBasePtr relatedCommand, const std::string& system, int svId, bool enabled)
      : CommandResult(CmdName, TargetId, relatedCommand)
    {

      setSystem(system);
      setSvId(svId);
      setEnabled(enabled);
    }


    IsRFOutputEnabledResultPtr IsRFOutputEnabledResult::create(const std::string& system, int svId, bool enabled)
    {
      return std::make_shared<IsRFOutputEnabledResult>(system, svId, enabled);
    }

    IsRFOutputEnabledResultPtr IsRFOutputEnabledResult::create(CommandBasePtr relatedCommand, const std::string& system, int svId, bool enabled)
    {
      return std::make_shared<IsRFOutputEnabledResult>(relatedCommand, system, svId, enabled);
    }

    IsRFOutputEnabledResultPtr IsRFOutputEnabledResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<IsRFOutputEnabledResult>(ptr);
    }

    bool IsRFOutputEnabledResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["System"])
          && parse_json<int>::is_valid(m_values["SvId"])
          && parse_json<bool>::is_valid(m_values["Enabled"])
        ;

    }

    std::string IsRFOutputEnabledResult::documentation() const { return Documentation; }

    const std::vector<std::string>& IsRFOutputEnabledResult::fieldNames() const 
    { 
      static const std::vector<std::string> names {"System", "SvId", "Enabled"}; 
      return names; 
    }


    std::string IsRFOutputEnabledResult::system() const
    {
      return parse_json<std::string>::parse(m_values["System"]);
    }

    void IsRFOutputEnabledResult::setSystem(const std::string& system)
    {
      m_values.AddMember("System", parse_json<std::string>::format(system, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int IsRFOutputEnabledResult::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void IsRFOutputEnabledResult::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    bool IsRFOutputEnabledResult::enabled() const
    {
      return parse_json<bool>::parse(m_values["Enabled"]);
    }

    void IsRFOutputEnabledResult::setEnabled(bool enabled)
    {
      m_values.AddMember("Enabled", parse_json<bool>::format(enabled, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
