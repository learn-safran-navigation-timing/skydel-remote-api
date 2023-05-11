
#include "gen/EnableLosForEachSV.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of EnableLosForEachSV
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const EnableLosForEachSV::CmdName = "EnableLosForEachSV";
    const char* const EnableLosForEachSV::Documentation = "Set Direct Line Of Sight signal from satellite disabled or enabled. Generally used when only multipaths signal is visible.";

    REGISTER_COMMAND_FACTORY(EnableLosForEachSV);


    EnableLosForEachSV::EnableLosForEachSV()
      : CommandBase(CmdName)
    {}

    EnableLosForEachSV::EnableLosForEachSV(const std::string& system, const std::vector<bool>& enabled)
      : CommandBase(CmdName)
    {

      setSystem(system);
      setEnabled(enabled);
    }

    EnableLosForEachSVPtr EnableLosForEachSV::create(const std::string& system, const std::vector<bool>& enabled)
    {
      return std::make_shared<EnableLosForEachSV>(system, enabled);
    }

    EnableLosForEachSVPtr EnableLosForEachSV::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<EnableLosForEachSV>(ptr);
    }

    bool EnableLosForEachSV::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["System"])
          && parse_json<std::vector<bool>>::is_valid(m_values["Enabled"])
        ;

    }

    std::string EnableLosForEachSV::documentation() const { return Documentation; }


    int EnableLosForEachSV::executePermission() const
    {
      return EXECUTE_IF_SIMULATING | EXECUTE_IF_IDLE;
    }


    std::string EnableLosForEachSV::system() const
    {
      return parse_json<std::string>::parse(m_values["System"]);
    }

    void EnableLosForEachSV::setSystem(const std::string& system)
    {
      m_values.AddMember("System", parse_json<std::string>::format(system, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::vector<bool> EnableLosForEachSV::enabled() const
    {
      return parse_json<std::vector<bool>>::parse(m_values["Enabled"]);
    }

    void EnableLosForEachSV::setEnabled(const std::vector<bool>& enabled)
    {
      m_values.AddMember("Enabled", parse_json<std::vector<bool>>::format(enabled, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
