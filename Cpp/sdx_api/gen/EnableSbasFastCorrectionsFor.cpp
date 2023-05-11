
#include "gen/EnableSbasFastCorrectionsFor.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of EnableSbasFastCorrectionsFor
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const EnableSbasFastCorrectionsFor::CmdName = "EnableSbasFastCorrectionsFor";
    const char* const EnableSbasFastCorrectionsFor::Documentation = "Set whether specific errors type for this constellation should be compensated in SBAS fast corrections";

    REGISTER_COMMAND_FACTORY(EnableSbasFastCorrectionsFor);


    EnableSbasFastCorrectionsFor::EnableSbasFastCorrectionsFor()
      : CommandBase(CmdName)
    {}

    EnableSbasFastCorrectionsFor::EnableSbasFastCorrectionsFor(const std::string& system, bool isEnabled, const Sdx::optional<std::string>& errorType)
      : CommandBase(CmdName)
    {

      setSystem(system);
      setIsEnabled(isEnabled);
      setErrorType(errorType);
    }

    EnableSbasFastCorrectionsForPtr EnableSbasFastCorrectionsFor::create(const std::string& system, bool isEnabled, const Sdx::optional<std::string>& errorType)
    {
      return std::make_shared<EnableSbasFastCorrectionsFor>(system, isEnabled, errorType);
    }

    EnableSbasFastCorrectionsForPtr EnableSbasFastCorrectionsFor::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<EnableSbasFastCorrectionsFor>(ptr);
    }

    bool EnableSbasFastCorrectionsFor::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["System"])
          && parse_json<bool>::is_valid(m_values["IsEnabled"])
          && parse_json<Sdx::optional<std::string>>::is_valid(m_values["ErrorType"])
        ;

    }

    std::string EnableSbasFastCorrectionsFor::documentation() const { return Documentation; }


    int EnableSbasFastCorrectionsFor::executePermission() const
    {
      return EXECUTE_IF_IDLE | EXECUTE_IF_SIMULATING;
    }


    std::string EnableSbasFastCorrectionsFor::system() const
    {
      return parse_json<std::string>::parse(m_values["System"]);
    }

    void EnableSbasFastCorrectionsFor::setSystem(const std::string& system)
    {
      m_values.AddMember("System", parse_json<std::string>::format(system, m_values.GetAllocator()), m_values.GetAllocator());
    }



    bool EnableSbasFastCorrectionsFor::isEnabled() const
    {
      return parse_json<bool>::parse(m_values["IsEnabled"]);
    }

    void EnableSbasFastCorrectionsFor::setIsEnabled(bool isEnabled)
    {
      m_values.AddMember("IsEnabled", parse_json<bool>::format(isEnabled, m_values.GetAllocator()), m_values.GetAllocator());
    }



    Sdx::optional<std::string> EnableSbasFastCorrectionsFor::errorType() const
    {
      return parse_json<Sdx::optional<std::string>>::parse(m_values["ErrorType"]);
    }

    void EnableSbasFastCorrectionsFor::setErrorType(const Sdx::optional<std::string>& errorType)
    {
      m_values.AddMember("ErrorType", parse_json<Sdx::optional<std::string>>::format(errorType, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
