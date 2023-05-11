
#include "gen/EnableRFOutputForEachSV.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of EnableRFOutputForEachSV
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const EnableRFOutputForEachSV::CmdName = "EnableRFOutputForEachSV";
    const char* const EnableRFOutputForEachSV::Documentation = "Enable (or disable) RF output for each satellite individually.";

    REGISTER_COMMAND_FACTORY(EnableRFOutputForEachSV);


    EnableRFOutputForEachSV::EnableRFOutputForEachSV()
      : CommandBase(CmdName)
    {}

    EnableRFOutputForEachSV::EnableRFOutputForEachSV(const std::string& system, const std::vector<bool>& enabled)
      : CommandBase(CmdName)
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
