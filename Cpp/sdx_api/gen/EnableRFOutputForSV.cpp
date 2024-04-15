
#include "EnableRFOutputForSV.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of EnableRFOutputForSV
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const EnableRFOutputForSV::CmdName = "EnableRFOutputForSV";
    const char* const EnableRFOutputForSV::Documentation = "Enable (or disable) RF output for specified satellite. Use SV ID 0 to enabled/disable all satellites.\n"
      "\n"
      "Name    Type   Description\n"
      "------- ------ --------------------------------------------------------------------------\n"
      "System  string \"GPS\", \"GLONASS\", \"Galileo\", \"BeiDou\", \"SBAS\", \"QZSS\", \"NavIC\" or \"PULSAR\"\n"
      "SvId    int    The satellite's SV ID\n"
      "Enabled bool   RF is enabled when value is True";
    const char* const EnableRFOutputForSV::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(EnableRFOutputForSV);
    REGISTER_COMMAND_TO_FACTORY_IMPL(EnableRFOutputForSV);


    EnableRFOutputForSV::EnableRFOutputForSV()
      : CommandBase(CmdName, TargetId)
    {}

    EnableRFOutputForSV::EnableRFOutputForSV(const std::string& system, int svId, bool enabled)
      : CommandBase(CmdName, TargetId)
    {

      setSystem(system);
      setSvId(svId);
      setEnabled(enabled);
    }

    EnableRFOutputForSVPtr EnableRFOutputForSV::create(const std::string& system, int svId, bool enabled)
    {
      return std::make_shared<EnableRFOutputForSV>(system, svId, enabled);
    }

    EnableRFOutputForSVPtr EnableRFOutputForSV::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<EnableRFOutputForSV>(ptr);
    }

    bool EnableRFOutputForSV::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["System"])
          && parse_json<int>::is_valid(m_values["SvId"])
          && parse_json<bool>::is_valid(m_values["Enabled"])
        ;

    }

    std::string EnableRFOutputForSV::documentation() const { return Documentation; }

    const std::vector<std::string>& EnableRFOutputForSV::fieldNames() const 
    { 
      static const std::vector<std::string> names {"System", "SvId", "Enabled"}; 
      return names; 
    }


    int EnableRFOutputForSV::executePermission() const
    {
      return EXECUTE_IF_SIMULATING | EXECUTE_IF_IDLE;
    }


    std::string EnableRFOutputForSV::system() const
    {
      return parse_json<std::string>::parse(m_values["System"]);
    }

    void EnableRFOutputForSV::setSystem(const std::string& system)
    {
      m_values.AddMember("System", parse_json<std::string>::format(system, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int EnableRFOutputForSV::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void EnableRFOutputForSV::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    bool EnableRFOutputForSV::enabled() const
    {
      return parse_json<bool>::parse(m_values["Enabled"]);
    }

    void EnableRFOutputForSV::setEnabled(bool enabled)
    {
      m_values.AddMember("Enabled", parse_json<bool>::format(enabled, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
