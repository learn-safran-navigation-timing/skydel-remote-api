
#include "gen/EnableSignalForEachSV.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of EnableSignalForEachSV
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const EnableSignalForEachSV::CmdName = "EnableSignalForEachSV";
    const char* const EnableSignalForEachSV::Documentation = "Enable (or disable) signal for each satellite individually.";

    REGISTER_COMMAND_FACTORY(EnableSignalForEachSV);


    EnableSignalForEachSV::EnableSignalForEachSV()
      : CommandBase(CmdName)
    {}

    EnableSignalForEachSV::EnableSignalForEachSV(const std::string& signal, const std::vector<bool>& enabled)
      : CommandBase(CmdName)
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
