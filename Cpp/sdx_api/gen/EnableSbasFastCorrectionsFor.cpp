
#include "EnableSbasFastCorrectionsFor.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of EnableSbasFastCorrectionsFor
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const EnableSbasFastCorrectionsFor::CmdName = "EnableSbasFastCorrectionsFor";
    const char* const EnableSbasFastCorrectionsFor::Documentation = "Set whether specific errors type for this constellation should be compensated in SBAS fast corrections\n"
      "\n"
      "Name      Type            Description\n"
      "--------- --------------- ----------------------------------------------------------------------------------------------------\n"
      "System    string          \"GPS\" or \"SBAS\"\n"
      "IsEnabled bool            True if corrections are enabled\n"
      "ErrorType optional string Comma separated error type to enable/disable. Accepted error types are \"PSR offset\" and \"PSR error\".\n"
      "                          Default value is \"PSR error\". Getter only accepts one error type.";
    const char* const EnableSbasFastCorrectionsFor::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(EnableSbasFastCorrectionsFor);
    REGISTER_COMMAND_TO_FACTORY_IMPL(EnableSbasFastCorrectionsFor);


    EnableSbasFastCorrectionsFor::EnableSbasFastCorrectionsFor()
      : CommandBase(CmdName, TargetId)
    {}

    EnableSbasFastCorrectionsFor::EnableSbasFastCorrectionsFor(const std::string& system, bool isEnabled, const std::optional<std::string>& errorType)
      : CommandBase(CmdName, TargetId)
    {

      setSystem(system);
      setIsEnabled(isEnabled);
      setErrorType(errorType);
    }

    EnableSbasFastCorrectionsForPtr EnableSbasFastCorrectionsFor::create(const std::string& system, bool isEnabled, const std::optional<std::string>& errorType)
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
          && parse_json<std::optional<std::string>>::is_valid(m_values["ErrorType"])
        ;

    }

    std::string EnableSbasFastCorrectionsFor::documentation() const { return Documentation; }

    const std::vector<std::string>& EnableSbasFastCorrectionsFor::fieldNames() const 
    { 
      static const std::vector<std::string> names {"System", "IsEnabled", "ErrorType"}; 
      return names; 
    }


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



    std::optional<std::string> EnableSbasFastCorrectionsFor::errorType() const
    {
      return parse_json<std::optional<std::string>>::parse(m_values["ErrorType"]);
    }

    void EnableSbasFastCorrectionsFor::setErrorType(const std::optional<std::string>& errorType)
    {
      m_values.AddMember("ErrorType", parse_json<std::optional<std::string>>::format(errorType, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
