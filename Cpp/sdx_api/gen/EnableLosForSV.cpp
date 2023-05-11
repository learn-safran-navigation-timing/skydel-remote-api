
#include "gen/EnableLosForSV.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of EnableLosForSV
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const EnableLosForSV::CmdName = "EnableLosForSV";
    const char* const EnableLosForSV::Documentation = "Set Direct Line Of Sight signal from satellite enabled or disabled. Generally used when only multipaths signal is visible.";

    REGISTER_COMMAND_FACTORY(EnableLosForSV);


    EnableLosForSV::EnableLosForSV()
      : CommandBase(CmdName)
    {}

    EnableLosForSV::EnableLosForSV(const std::string& system, int svId, bool enabled)
      : CommandBase(CmdName)
    {

      setSystem(system);
      setSvId(svId);
      setEnabled(enabled);
    }

    EnableLosForSVPtr EnableLosForSV::create(const std::string& system, int svId, bool enabled)
    {
      return std::make_shared<EnableLosForSV>(system, svId, enabled);
    }

    EnableLosForSVPtr EnableLosForSV::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<EnableLosForSV>(ptr);
    }

    bool EnableLosForSV::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["System"])
          && parse_json<int>::is_valid(m_values["SvId"])
          && parse_json<bool>::is_valid(m_values["Enabled"])
        ;

    }

    std::string EnableLosForSV::documentation() const { return Documentation; }


    int EnableLosForSV::executePermission() const
    {
      return EXECUTE_IF_SIMULATING | EXECUTE_IF_IDLE;
    }


    std::string EnableLosForSV::system() const
    {
      return parse_json<std::string>::parse(m_values["System"]);
    }

    void EnableLosForSV::setSystem(const std::string& system)
    {
      m_values.AddMember("System", parse_json<std::string>::format(system, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int EnableLosForSV::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void EnableLosForSV::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    bool EnableLosForSV::enabled() const
    {
      return parse_json<bool>::parse(m_values["Enabled"]);
    }

    void EnableLosForSV::setEnabled(bool enabled)
    {
      m_values.AddMember("Enabled", parse_json<bool>::format(enabled, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
