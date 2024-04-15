
#include "IsSbasFastCorrectionsEnabledFor.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of IsSbasFastCorrectionsEnabledFor
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const IsSbasFastCorrectionsEnabledFor::CmdName = "IsSbasFastCorrectionsEnabledFor";
    const char* const IsSbasFastCorrectionsEnabledFor::Documentation = "Get whether specific errors type for this constellation should be compensated in SBAS fast corrections\n"
      "\n"
      "Name      Type            Description\n"
      "--------- --------------- ----------------------------------------------------------------------------------------------------\n"
      "System    string          \"GPS\" or \"SBAS\"\n"
      "ErrorType optional string Comma separated error type to enable/disable. Accepted error types are \"PSR offset\" and \"PSR error\".\n"
      "                          Default value is \"PSR error\". Getter only accepts one error type.";
    const char* const IsSbasFastCorrectionsEnabledFor::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(IsSbasFastCorrectionsEnabledFor);
    REGISTER_COMMAND_TO_FACTORY_IMPL(IsSbasFastCorrectionsEnabledFor);


    IsSbasFastCorrectionsEnabledFor::IsSbasFastCorrectionsEnabledFor()
      : CommandBase(CmdName, TargetId)
    {}

    IsSbasFastCorrectionsEnabledFor::IsSbasFastCorrectionsEnabledFor(const std::string& system, const Sdx::optional<std::string>& errorType)
      : CommandBase(CmdName, TargetId)
    {

      setSystem(system);
      setErrorType(errorType);
    }

    IsSbasFastCorrectionsEnabledForPtr IsSbasFastCorrectionsEnabledFor::create(const std::string& system, const Sdx::optional<std::string>& errorType)
    {
      return std::make_shared<IsSbasFastCorrectionsEnabledFor>(system, errorType);
    }

    IsSbasFastCorrectionsEnabledForPtr IsSbasFastCorrectionsEnabledFor::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<IsSbasFastCorrectionsEnabledFor>(ptr);
    }

    bool IsSbasFastCorrectionsEnabledFor::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["System"])
          && parse_json<Sdx::optional<std::string>>::is_valid(m_values["ErrorType"])
        ;

    }

    std::string IsSbasFastCorrectionsEnabledFor::documentation() const { return Documentation; }

    const std::vector<std::string>& IsSbasFastCorrectionsEnabledFor::fieldNames() const 
    { 
      static const std::vector<std::string> names {"System", "ErrorType"}; 
      return names; 
    }


    int IsSbasFastCorrectionsEnabledFor::executePermission() const
    {
      return EXECUTE_IF_IDLE | EXECUTE_IF_SIMULATING;
    }


    std::string IsSbasFastCorrectionsEnabledFor::system() const
    {
      return parse_json<std::string>::parse(m_values["System"]);
    }

    void IsSbasFastCorrectionsEnabledFor::setSystem(const std::string& system)
    {
      m_values.AddMember("System", parse_json<std::string>::format(system, m_values.GetAllocator()), m_values.GetAllocator());
    }



    Sdx::optional<std::string> IsSbasFastCorrectionsEnabledFor::errorType() const
    {
      return parse_json<Sdx::optional<std::string>>::parse(m_values["ErrorType"]);
    }

    void IsSbasFastCorrectionsEnabledFor::setErrorType(const Sdx::optional<std::string>& errorType)
    {
      m_values.AddMember("ErrorType", parse_json<Sdx::optional<std::string>>::format(errorType, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
