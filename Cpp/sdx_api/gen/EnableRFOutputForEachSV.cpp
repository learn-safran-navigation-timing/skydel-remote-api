
#include "EnableRFOutputForEachSV.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of EnableRFOutputForEachSV
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const EnableRFOutputForEachSV::CmdName = "EnableRFOutputForEachSV";
    const char* const EnableRFOutputForEachSV::Documentation = "Enable (or disable) RF output for each satellite individually.\n"
      "\n"
      "Name    Type       Description\n"
      "------- ---------- -------------------------------------------------------------------------------------------------\n"
      "System  string     \"GPS\", \"GLONASS\", \"Galileo\", \"BeiDou\", \"SBAS\", \"QZSS\", \"NavIC\" or \"PULSAR\"\n"
      "Enabled array bool RF is enabled when value is True. Zero based index (index 0 => SV ID 1, index 1 => SV ID 2, etc).";
    const char* const EnableRFOutputForEachSV::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(EnableRFOutputForEachSV);
    REGISTER_COMMAND_TO_FACTORY_IMPL(EnableRFOutputForEachSV);


    EnableRFOutputForEachSV::EnableRFOutputForEachSV()
      : CommandBase(CmdName, TargetId)
    {}

    EnableRFOutputForEachSV::EnableRFOutputForEachSV(const std::string& system, const std::vector<bool>& enabled)
      : CommandBase(CmdName, TargetId)
    {

      setSystem(system);
      setEnabled(enabled);
    }

    EnableRFOutputForEachSVPtr EnableRFOutputForEachSV::create(const std::string& system, const std::vector<bool>& enabled)
    {
      return std::make_shared<EnableRFOutputForEachSV>(system, enabled);
    }

    EnableRFOutputForEachSVPtr EnableRFOutputForEachSV::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<EnableRFOutputForEachSV>(ptr);
    }

    bool EnableRFOutputForEachSV::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["System"])
          && parse_json<std::vector<bool>>::is_valid(m_values["Enabled"])
        ;

    }

    std::string EnableRFOutputForEachSV::documentation() const { return Documentation; }

    const std::vector<std::string>& EnableRFOutputForEachSV::fieldNames() const 
    { 
      static const std::vector<std::string> names {"System", "Enabled"}; 
      return names; 
    }


    int EnableRFOutputForEachSV::executePermission() const
    {
      return EXECUTE_IF_SIMULATING | EXECUTE_IF_IDLE;
    }


    std::string EnableRFOutputForEachSV::system() const
    {
      return parse_json<std::string>::parse(m_values["System"]);
    }

    void EnableRFOutputForEachSV::setSystem(const std::string& system)
    {
      m_values.AddMember("System", parse_json<std::string>::format(system, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::vector<bool> EnableRFOutputForEachSV::enabled() const
    {
      return parse_json<std::vector<bool>>::parse(m_values["Enabled"]);
    }

    void EnableRFOutputForEachSV::setEnabled(const std::vector<bool>& enabled)
    {
      m_values.AddMember("Enabled", parse_json<std::vector<bool>>::format(enabled, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
