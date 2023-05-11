
#include "gen/EnableEachSV.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of EnableEachSV
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const EnableEachSV::CmdName = "EnableEachSV";
    const char* const EnableEachSV::Documentation = "Enable or disable each satellite for this constellation.";

    REGISTER_COMMAND_FACTORY(EnableEachSV);


    EnableEachSV::EnableEachSV()
      : CommandBase(CmdName)
    {}

    EnableEachSV::EnableEachSV(const std::string& system, const std::vector<bool>& enabled)
      : CommandBase(CmdName)
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
