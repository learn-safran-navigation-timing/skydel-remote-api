
#include "EnableSignalForSV.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of EnableSignalForSV
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const EnableSignalForSV::CmdName = "EnableSignalForSV";
    const char* const EnableSignalForSV::Documentation = "Enable (or disable) signal for specified satellite.\n"
      "\n"
      "Name    Type   Description\n"
      "------- ------ -------------------------------------------------------------------------------------------------------------\n"
      "Signal  string Accepted signal keys: \"L1CA\", \"L1C\", \"L1P\", \"L1ME\", \"L1MR\", \"L2C\", \"L2P\", \"L2ME\", \"L2MR\", \"L5\",\n"
      "                                     \"G1\", \"G2\", \"E1\", \"E1PRS\", \"E5a\", \"E5b\", \"E6BC\", \"E6PRS\",\n"
      "                                     \"B1\", \"B2\", \"B1C\", \"B2a\", \"B3I\", \"SBASL1\", \"SBASL5\", \"QZSSL1CA\", \"QZSSL1CB\", \"QZSSL1C\",\n"
      "                                     \"QZSSL2C\", \"QZSSL5\", \"QZSSL1S\", \"QZSSL5S\", \"QZSSL6\", \"NAVICL1\", \"NAVICL5\", \"NAVICS\",\n"
      "                                     \"PULSARXL\", \"PULSARX1\"\n"
      "SvId    int    The satellite's SV ID (use 0 for all constellation's satellites)\n"
      "Enabled bool   Signal is enabled when value is True";
    const char* const EnableSignalForSV::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(EnableSignalForSV);
    REGISTER_COMMAND_TO_FACTORY_IMPL(EnableSignalForSV);


    EnableSignalForSV::EnableSignalForSV()
      : CommandBase(CmdName, TargetId)
    {}

    EnableSignalForSV::EnableSignalForSV(const std::string& signal, int svId, bool enabled)
      : CommandBase(CmdName, TargetId)
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

    const std::vector<std::string>& EnableSignalForSV::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Signal", "SvId", "Enabled"}; 
      return names; 
    }


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
