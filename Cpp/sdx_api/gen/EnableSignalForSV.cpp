
#include "gen/EnableSignalForSV.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of EnableSignalForSV
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const EnableSignalForSV::CmdName = "EnableSignalForSV";
    const char* const EnableSignalForSV::Documentation = "Enable (or disable) signal for specified satellite.";

    REGISTER_COMMAND_FACTORY(EnableSignalForSV);


    EnableSignalForSV::EnableSignalForSV()
      : CommandBase(CmdName)
    {}

    EnableSignalForSV::EnableSignalForSV(const std::string& signal, int svId, bool enabled)
      : CommandBase(CmdName)
    {

      setSignal(signal);
      setSvId(svId);
      setEnabled(enabled);
    }

    EnableSignalForSVPtr EnableSignalForSV::create(const std::string& signal, int svId, bool enabled)
    {
      return std::make_shared<EnableSignalForSV>(signal, svId, enabled);
    }

    EnableSignalForSVPtr EnableSignalForSV::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<EnableSignalForSV>(ptr);
    }

    bool EnableSignalForSV::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["Signal"])
          && parse_json<int>::is_valid(m_values["SvId"])
          && parse_json<bool>::is_valid(m_values["Enabled"])
        ;

    }

    std::string EnableSignalForSV::documentation() const { return Documentation; }


    int EnableSignalForSV::executePermission() const
    {
      return EXECUTE_IF_SIMULATING | EXECUTE_IF_IDLE;
    }


    std::string EnableSignalForSV::signal() const
    {
      return parse_json<std::string>::parse(m_values["Signal"]);
    }

    void EnableSignalForSV::setSignal(const std::string& signal)
    {
      m_values.AddMember("Signal", parse_json<std::string>::format(signal, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int EnableSignalForSV::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void EnableSignalForSV::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    bool EnableSignalForSV::enabled() const
    {
      return parse_json<bool>::parse(m_values["Enabled"]);
    }

    void EnableSignalForSV::setEnabled(bool enabled)
    {
      m_values.AddMember("Enabled", parse_json<bool>::format(enabled, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
