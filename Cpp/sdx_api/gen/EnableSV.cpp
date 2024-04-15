
#include "EnableSV.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of EnableSV
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const EnableSV::CmdName = "EnableSV";
    const char* const EnableSV::Documentation = "Enable or disable a satellite for this constellation.\n"
      "\n"
      "Name    Type   Description\n"
      "------- ------ ----------------------------------------------------------------------------------------------------------------\n"
      "System  string The satellite's constellation. Can be \"GPS\", \"GLONASS\", \"Galileo\", \"BeiDou\", \"SBAS\", \"QZSS\", \"NavIC\" or \"PULSAR\"\n"
      "SvId    int    The satellite's SV ID (use 0 for all SVs).\n"
      "Enabled bool   The satellite will be present/absent from the constellation";
    const char* const EnableSV::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(EnableSV);
    REGISTER_COMMAND_TO_FACTORY_IMPL(EnableSV);


    EnableSV::EnableSV()
      : CommandBase(CmdName, TargetId)
    {}

    EnableSV::EnableSV(const std::string& system, int svId, bool enabled)
      : CommandBase(CmdName, TargetId)
    {

      setSystem(system);
      setSvId(svId);
      setEnabled(enabled);
    }

    EnableSVPtr EnableSV::create(const std::string& system, int svId, bool enabled)
    {
      return std::make_shared<EnableSV>(system, svId, enabled);
    }

    EnableSVPtr EnableSV::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<EnableSV>(ptr);
    }

    bool EnableSV::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["System"])
          && parse_json<int>::is_valid(m_values["SvId"])
          && parse_json<bool>::is_valid(m_values["Enabled"])
        ;

    }

    std::string EnableSV::documentation() const { return Documentation; }

    const std::vector<std::string>& EnableSV::fieldNames() const 
    { 
      static const std::vector<std::string> names {"System", "SvId", "Enabled"}; 
      return names; 
    }


    int EnableSV::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string EnableSV::system() const
    {
      return parse_json<std::string>::parse(m_values["System"]);
    }

    void EnableSV::setSystem(const std::string& system)
    {
      m_values.AddMember("System", parse_json<std::string>::format(system, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int EnableSV::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void EnableSV::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    bool EnableSV::enabled() const
    {
      return parse_json<bool>::parse(m_values["Enabled"]);
    }

    void EnableSV::setEnabled(bool enabled)
    {
      m_values.AddMember("Enabled", parse_json<bool>::format(enabled, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
