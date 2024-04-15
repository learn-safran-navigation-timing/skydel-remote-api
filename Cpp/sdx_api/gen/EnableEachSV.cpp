
#include "EnableEachSV.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of EnableEachSV
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const EnableEachSV::CmdName = "EnableEachSV";
    const char* const EnableEachSV::Documentation = "Enable or disable each satellite for this constellation.\n"
      "\n"
      "Name    Type       Description\n"
      "------- ---------- ----------------------------------------------------------------------------------------------------------------\n"
      "System  string     The satellites' constellation. Can be \"GPS\", \"GLONASS\", \"Galileo\", \"BeiDou\", \"SBAS\", \"QZSS\", \"NavIC\" or \"PULSAR\"\n"
      "Enabled array bool Array of present/absent flags for the constellation";
    const char* const EnableEachSV::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(EnableEachSV);
    REGISTER_COMMAND_TO_FACTORY_IMPL(EnableEachSV);


    EnableEachSV::EnableEachSV()
      : CommandBase(CmdName, TargetId)
    {}

    EnableEachSV::EnableEachSV(const std::string& system, const std::vector<bool>& enabled)
      : CommandBase(CmdName, TargetId)
    {

      setSystem(system);
      setEnabled(enabled);
    }

    EnableEachSVPtr EnableEachSV::create(const std::string& system, const std::vector<bool>& enabled)
    {
      return std::make_shared<EnableEachSV>(system, enabled);
    }

    EnableEachSVPtr EnableEachSV::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<EnableEachSV>(ptr);
    }

    bool EnableEachSV::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["System"])
          && parse_json<std::vector<bool>>::is_valid(m_values["Enabled"])
        ;

    }

    std::string EnableEachSV::documentation() const { return Documentation; }

    const std::vector<std::string>& EnableEachSV::fieldNames() const 
    { 
      static const std::vector<std::string> names {"System", "Enabled"}; 
      return names; 
    }


    int EnableEachSV::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string EnableEachSV::system() const
    {
      return parse_json<std::string>::parse(m_values["System"]);
    }

    void EnableEachSV::setSystem(const std::string& system)
    {
      m_values.AddMember("System", parse_json<std::string>::format(system, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::vector<bool> EnableEachSV::enabled() const
    {
      return parse_json<std::vector<bool>>::parse(m_values["Enabled"]);
    }

    void EnableEachSV::setEnabled(const std::vector<bool>& enabled)
    {
      m_values.AddMember("Enabled", parse_json<std::vector<bool>>::format(enabled, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
