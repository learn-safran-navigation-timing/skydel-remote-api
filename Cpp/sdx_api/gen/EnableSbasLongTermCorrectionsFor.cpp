
#include "gen/EnableSbasLongTermCorrectionsFor.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of EnableSbasLongTermCorrectionsFor
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const EnableSbasLongTermCorrectionsFor::CmdName = "EnableSbasLongTermCorrectionsFor";
    const char* const EnableSbasLongTermCorrectionsFor::Documentation = "Set whether ephemeris errors for this constellation should be compensated in SBAS long term corrections.";

    REGISTER_COMMAND_FACTORY(EnableSbasLongTermCorrectionsFor);


    EnableSbasLongTermCorrectionsFor::EnableSbasLongTermCorrectionsFor()
      : CommandBase(CmdName)
    {}

    EnableSbasLongTermCorrectionsFor::EnableSbasLongTermCorrectionsFor(const std::string& system, bool isEnabled)
      : CommandBase(CmdName)
    {

      setSystem(system);
      setIsEnabled(isEnabled);
    }

    EnableSbasLongTermCorrectionsForPtr EnableSbasLongTermCorrectionsFor::create(const std::string& system, bool isEnabled)
    {
      return std::make_shared<EnableSbasLongTermCorrectionsFor>(system, isEnabled);
    }

    EnableSbasLongTermCorrectionsForPtr EnableSbasLongTermCorrectionsFor::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<EnableSbasLongTermCorrectionsFor>(ptr);
    }

    bool EnableSbasLongTermCorrectionsFor::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["System"])
          && parse_json<bool>::is_valid(m_values["IsEnabled"])
        ;

    }

    std::string EnableSbasLongTermCorrectionsFor::documentation() const { return Documentation; }


    int EnableSbasLongTermCorrectionsFor::executePermission() const
    {
      return EXECUTE_IF_IDLE | EXECUTE_IF_SIMULATING;
    }


    std::string EnableSbasLongTermCorrectionsFor::system() const
    {
      return parse_json<std::string>::parse(m_values["System"]);
    }

    void EnableSbasLongTermCorrectionsFor::setSystem(const std::string& system)
    {
      m_values.AddMember("System", parse_json<std::string>::format(system, m_values.GetAllocator()), m_values.GetAllocator());
    }



    bool EnableSbasLongTermCorrectionsFor::isEnabled() const
    {
      return parse_json<bool>::parse(m_values["IsEnabled"]);
    }

    void EnableSbasLongTermCorrectionsFor::setIsEnabled(bool isEnabled)
    {
      m_values.AddMember("IsEnabled", parse_json<bool>::format(isEnabled, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
