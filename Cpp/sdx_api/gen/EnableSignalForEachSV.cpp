
#include "EnableSignalForEachSV.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of EnableSignalForEachSV
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const EnableSignalForEachSV::CmdName = "EnableSignalForEachSV";
    const char* const EnableSignalForEachSV::Documentation = "Enable (or disable) signal for each satellite individually.\n"
      "\n"
      "Name    Type       Description\n"
      "------- ---------- --------------------------------------------------------------------------------------------------------------\n"
      "Signal  string     Accepted signal keys: \"L1CA\", \"L1C\", \"L1P\", \"L1ME\", \"L1MR\", \"L2C\", \"L2P\", \"L2ME\", \"L2MR\", \"L5\",\n"
      "                                         \"G1\", \"G2\", \"E1\", \"E1PRS\", \"E5a\", \"E5b\", \"E6BC\", \"E6PRS\",\n"
      "                                         \"B1\", \"B2\", \"B1C\", \"B2a\", \"B3I\", \"SBASL1\", \"SBASL5\", \"QZSSL1CA\",\n"
      "                                         \"QZSSL1CB\", \"QZSSL1C\", \"QZSSL2C\", \"QZSSL5\", \"QZSSL1S\", \"QZSSL5S\", \"NAVICL5\", \"PULSARXL\"\n"
      "Enabled array bool Signal is enabled when value is True. Zero based index (index 0 => first SV ID, index 1 => second SV ID, etc).";
    const char* const EnableSignalForEachSV::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(EnableSignalForEachSV);
    REGISTER_COMMAND_TO_FACTORY_IMPL(EnableSignalForEachSV);


    EnableSignalForEachSV::EnableSignalForEachSV()
      : CommandBase(CmdName, TargetId)
    {}

    EnableSignalForEachSV::EnableSignalForEachSV(const std::string& signal, const std::vector<bool>& enabled)
      : CommandBase(CmdName, TargetId)
    {

      setSignal(signal);
      setEnabled(enabled);
    }

    EnableSignalForEachSVPtr EnableSignalForEachSV::create(const std::string& signal, const std::vector<bool>& enabled)
    {
      return std::make_shared<EnableSignalForEachSV>(signal, enabled);
    }

    EnableSignalForEachSVPtr EnableSignalForEachSV::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<EnableSignalForEachSV>(ptr);
    }

    bool EnableSignalForEachSV::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["Signal"])
          && parse_json<std::vector<bool>>::is_valid(m_values["Enabled"])
        ;

    }

    std::string EnableSignalForEachSV::documentation() const { return Documentation; }

    const std::vector<std::string>& EnableSignalForEachSV::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Signal", "Enabled"}; 
      return names; 
    }


    int EnableSignalForEachSV::executePermission() const
    {
      return EXECUTE_IF_SIMULATING | EXECUTE_IF_IDLE;
    }


    std::string EnableSignalForEachSV::signal() const
    {
      return parse_json<std::string>::parse(m_values["Signal"]);
    }

    void EnableSignalForEachSV::setSignal(const std::string& signal)
    {
      m_values.AddMember("Signal", parse_json<std::string>::format(signal, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::vector<bool> EnableSignalForEachSV::enabled() const
    {
      return parse_json<std::vector<bool>>::parse(m_values["Enabled"]);
    }

    void EnableSignalForEachSV::setEnabled(const std::vector<bool>& enabled)
    {
      m_values.AddMember("Enabled", parse_json<std::vector<bool>>::format(enabled, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
