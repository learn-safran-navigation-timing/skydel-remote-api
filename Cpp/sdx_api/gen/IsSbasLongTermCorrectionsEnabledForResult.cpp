
#include "gen/IsSbasLongTermCorrectionsEnabledForResult.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of IsSbasLongTermCorrectionsEnabledForResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const IsSbasLongTermCorrectionsEnabledForResult::CmdName = "IsSbasLongTermCorrectionsEnabledForResult";
    const char* const IsSbasLongTermCorrectionsEnabledForResult::Documentation = "Result of IsSbasLongTermCorrectionsEnabledFor.";

    REGISTER_COMMAND_RESULT_TO_FACTORY_IMPL(IsSbasLongTermCorrectionsEnabledForResult);


    IsSbasLongTermCorrectionsEnabledForResult::IsSbasLongTermCorrectionsEnabledForResult()
      : CommandResult(CmdName)
    {}

    IsSbasLongTermCorrectionsEnabledForResult::IsSbasLongTermCorrectionsEnabledForResult(const std::string& system, bool isEnabled)
      : CommandResult(CmdName)
    {

      setSystem(system);
      setIsEnabled(isEnabled);
    }

    IsSbasLongTermCorrectionsEnabledForResult::IsSbasLongTermCorrectionsEnabledForResult(CommandBasePtr relatedCommand, const std::string& system, bool isEnabled)
      : CommandResult(CmdName, relatedCommand)
    {

      setSystem(system);
      setIsEnabled(isEnabled);
    }


    IsSbasLongTermCorrectionsEnabledForResultPtr IsSbasLongTermCorrectionsEnabledForResult::create(const std::string& system, bool isEnabled)
    {
      return std::make_shared<IsSbasLongTermCorrectionsEnabledForResult>(system, isEnabled);
    }

    IsSbasLongTermCorrectionsEnabledForResultPtr IsSbasLongTermCorrectionsEnabledForResult::create(CommandBasePtr relatedCommand, const std::string& system, bool isEnabled)
    {
      return std::make_shared<IsSbasLongTermCorrectionsEnabledForResult>(relatedCommand, system, isEnabled);
    }

    IsSbasLongTermCorrectionsEnabledForResultPtr IsSbasLongTermCorrectionsEnabledForResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<IsSbasLongTermCorrectionsEnabledForResult>(ptr);
    }

    bool IsSbasLongTermCorrectionsEnabledForResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["System"])
          && parse_json<bool>::is_valid(m_values["IsEnabled"])
        ;

    }

    std::string IsSbasLongTermCorrectionsEnabledForResult::documentation() const { return Documentation; }


    std::string IsSbasLongTermCorrectionsEnabledForResult::system() const
    {
      return parse_json<std::string>::parse(m_values["System"]);
    }

    void IsSbasLongTermCorrectionsEnabledForResult::setSystem(const std::string& system)
    {
      m_values.AddMember("System", parse_json<std::string>::format(system, m_values.GetAllocator()), m_values.GetAllocator());
    }



    bool IsSbasLongTermCorrectionsEnabledForResult::isEnabled() const
    {
      return parse_json<bool>::parse(m_values["IsEnabled"]);
    }

    void IsSbasLongTermCorrectionsEnabledForResult::setIsEnabled(bool isEnabled)
    {
      m_values.AddMember("IsEnabled", parse_json<bool>::format(isEnabled, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
