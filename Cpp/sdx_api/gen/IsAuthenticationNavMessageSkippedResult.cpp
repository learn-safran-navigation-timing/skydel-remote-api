
#include "IsAuthenticationNavMessageSkippedResult.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of IsAuthenticationNavMessageSkippedResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const IsAuthenticationNavMessageSkippedResult::CmdName = "IsAuthenticationNavMessageSkippedResult";
    const char* const IsAuthenticationNavMessageSkippedResult::Documentation = "Result of IsAuthenticationNavMessageSkipped.\n"
      "\n"
      "Name        Type   Description\n"
      "----------- ------ -------------------------------------------------------------------\n"
      "Signal      string Signal key, accepted values : \"PULSARX1\" and \"PULSARX5\".\n"
      "SkipMessage bool   If True, skips the authentication messages in the message sequence.";
    const char* const IsAuthenticationNavMessageSkippedResult::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_IMPL(IsAuthenticationNavMessageSkippedResult);


    IsAuthenticationNavMessageSkippedResult::IsAuthenticationNavMessageSkippedResult()
      : CommandResult(CmdName, TargetId)
    {}

    IsAuthenticationNavMessageSkippedResult::IsAuthenticationNavMessageSkippedResult(const std::string& signal, bool skipMessage)
      : CommandResult(CmdName, TargetId)
    {

      setSignal(signal);
      setSkipMessage(skipMessage);
    }

    IsAuthenticationNavMessageSkippedResult::IsAuthenticationNavMessageSkippedResult(CommandBasePtr relatedCommand, const std::string& signal, bool skipMessage)
      : CommandResult(CmdName, TargetId, relatedCommand)
    {

      setSignal(signal);
      setSkipMessage(skipMessage);
    }


    IsAuthenticationNavMessageSkippedResultPtr IsAuthenticationNavMessageSkippedResult::create(const std::string& signal, bool skipMessage)
    {
      return std::make_shared<IsAuthenticationNavMessageSkippedResult>(signal, skipMessage);
    }

    IsAuthenticationNavMessageSkippedResultPtr IsAuthenticationNavMessageSkippedResult::create(CommandBasePtr relatedCommand, const std::string& signal, bool skipMessage)
    {
      return std::make_shared<IsAuthenticationNavMessageSkippedResult>(relatedCommand, signal, skipMessage);
    }

    IsAuthenticationNavMessageSkippedResultPtr IsAuthenticationNavMessageSkippedResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<IsAuthenticationNavMessageSkippedResult>(ptr);
    }

    bool IsAuthenticationNavMessageSkippedResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["Signal"])
          && parse_json<bool>::is_valid(m_values["SkipMessage"])
        ;

    }

    std::string IsAuthenticationNavMessageSkippedResult::documentation() const { return Documentation; }

    const std::vector<std::string>& IsAuthenticationNavMessageSkippedResult::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Signal", "SkipMessage"}; 
      return names; 
    }


    std::string IsAuthenticationNavMessageSkippedResult::signal() const
    {
      return parse_json<std::string>::parse(m_values["Signal"]);
    }

    void IsAuthenticationNavMessageSkippedResult::setSignal(const std::string& signal)
    {
      setValue("Signal", parse_json<std::string>::format(signal, m_values.GetAllocator()));
    }



    bool IsAuthenticationNavMessageSkippedResult::skipMessage() const
    {
      return parse_json<bool>::parse(m_values["SkipMessage"]);
    }

    void IsAuthenticationNavMessageSkippedResult::setSkipMessage(bool skipMessage)
    {
      setValue("SkipMessage", parse_json<bool>::format(skipMessage, m_values.GetAllocator()));
    }


  }
}
