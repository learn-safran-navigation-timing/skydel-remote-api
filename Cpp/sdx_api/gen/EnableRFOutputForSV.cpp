
#include "gen/EnableRFOutputForSV.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of EnableRFOutputForSV
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const EnableRFOutputForSV::CmdName = "EnableRFOutputForSV";
    const char* const EnableRFOutputForSV::Documentation = "Enable (or disable) RF output for specified satellite. Use SV ID 0 to enabled/disable all satellites.";

    REGISTER_COMMAND_FACTORY(EnableRFOutputForSV);


    EnableRFOutputForSV::EnableRFOutputForSV()
      : CommandBase(CmdName)
    {}

    EnableRFOutputForSV::EnableRFOutputForSV(const std::string& system, int svId, bool enabled)
      : CommandBase(CmdName)
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
