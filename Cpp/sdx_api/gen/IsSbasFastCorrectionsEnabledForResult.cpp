
#include "IsSbasFastCorrectionsEnabledForResult.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of IsSbasFastCorrectionsEnabledForResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const IsSbasFastCorrectionsEnabledForResult::CmdName = "IsSbasFastCorrectionsEnabledForResult";
    const char* const IsSbasFastCorrectionsEnabledForResult::Documentation = "Result of IsSbasFastCorrectionsEnabledFor.\n"
      "\n"
      "Name      Type            Description\n"
      "--------- --------------- ----------------------------------------------------------------------------------------------------\n"
      "System    string          \"GPS\" or \"SBAS\"\n"
      "IsEnabled bool            True if corrections are enabled\n"
      "ErrorType optional string Comma separated error type to enable/disable. Accepted error types are \"PSR offset\" and \"PSR error\".\n"
      "                          Default value is \"PSR error\". Getter only accepts one error type.";
    const char* const IsSbasFastCorrectionsEnabledForResult::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_IMPL(IsSbasFastCorrectionsEnabledForResult);


    IsSbasFastCorrectionsEnabledForResult::IsSbasFastCorrectionsEnabledForResult()
      : CommandResult(CmdName, TargetId)
    {}

    IsSbasFastCorrectionsEnabledForResult::IsSbasFastCorrectionsEnabledForResult(const std::string& system, bool isEnabled, const std::optional<std::string>& errorType)
      : CommandResult(CmdName, TargetId)
    {

      setSystem(system);
      setIsEnabled(isEnabled);
      setErrorType(errorType);
    }

    IsSbasFastCorrectionsEnabledForResult::IsSbasFastCorrectionsEnabledForResult(CommandBasePtr relatedCommand, const std::string& system, bool isEnabled, const std::optional<std::string>& errorType)
      : CommandResult(CmdName, TargetId, relatedCommand)
    {

      setSystem(system);
      setIsEnabled(isEnabled);
      setErrorType(errorType);
    }


    IsSbasFastCorrectionsEnabledForResultPtr IsSbasFastCorrectionsEnabledForResult::create(const std::string& system, bool isEnabled, const std::optional<std::string>& errorType)
    {
      return std::make_shared<IsSbasFastCorrectionsEnabledForResult>(system, isEnabled, errorType);
    }

    IsSbasFastCorrectionsEnabledForResultPtr IsSbasFastCorrectionsEnabledForResult::create(CommandBasePtr relatedCommand, const std::string& system, bool isEnabled, const std::optional<std::string>& errorType)
    {
      return std::make_shared<IsSbasFastCorrectionsEnabledForResult>(relatedCommand, system, isEnabled, errorType);
    }

    IsSbasFastCorrectionsEnabledForResultPtr IsSbasFastCorrectionsEnabledForResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<IsSbasFastCorrectionsEnabledForResult>(ptr);
    }

    bool IsSbasFastCorrectionsEnabledForResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["System"])
          && parse_json<bool>::is_valid(m_values["IsEnabled"])
          && parse_json<std::optional<std::string>>::is_valid(m_values["ErrorType"])
        ;

    }

    std::string IsSbasFastCorrectionsEnabledForResult::documentation() const { return Documentation; }

    const std::vector<std::string>& IsSbasFastCorrectionsEnabledForResult::fieldNames() const 
    { 
      static const std::vector<std::string> names {"System", "IsEnabled", "ErrorType"}; 
      return names; 
    }


    std::string IsSbasFastCorrectionsEnabledForResult::system() const
    {
      return parse_json<std::string>::parse(m_values["System"]);
    }

    void IsSbasFastCorrectionsEnabledForResult::setSystem(const std::string& system)
    {
      m_values.AddMember("System", parse_json<std::string>::format(system, m_values.GetAllocator()), m_values.GetAllocator());
    }



    bool IsSbasFastCorrectionsEnabledForResult::isEnabled() const
    {
      return parse_json<bool>::parse(m_values["IsEnabled"]);
    }

    void IsSbasFastCorrectionsEnabledForResult::setIsEnabled(bool isEnabled)
    {
      m_values.AddMember("IsEnabled", parse_json<bool>::format(isEnabled, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::optional<std::string> IsSbasFastCorrectionsEnabledForResult::errorType() const
    {
      return parse_json<std::optional<std::string>>::parse(m_values["ErrorType"]);
    }

    void IsSbasFastCorrectionsEnabledForResult::setErrorType(const std::optional<std::string>& errorType)
    {
      m_values.AddMember("ErrorType", parse_json<std::optional<std::string>>::format(errorType, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
