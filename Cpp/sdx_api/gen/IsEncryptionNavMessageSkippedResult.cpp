
#include "IsEncryptionNavMessageSkippedResult.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of IsEncryptionNavMessageSkippedResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const IsEncryptionNavMessageSkippedResult::CmdName = "IsEncryptionNavMessageSkippedResult";
    const char* const IsEncryptionNavMessageSkippedResult::Documentation = "Result of IsEncryptionNavMessageSkipped.\n"
      "\n"
      "Name        Type   Description\n"
      "----------- ------ ---------------------------------------------------------------\n"
      "Signal      string Signal key, accepted values : \"PULSARX1\" and \"PULSARX5\".\n"
      "SkipMessage bool   If True, skips the encryption messages in the message sequence.";
    const char* const IsEncryptionNavMessageSkippedResult::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_IMPL(IsEncryptionNavMessageSkippedResult);


    IsEncryptionNavMessageSkippedResult::IsEncryptionNavMessageSkippedResult()
      : CommandResult(CmdName, TargetId)
    {}

    IsEncryptionNavMessageSkippedResult::IsEncryptionNavMessageSkippedResult(const std::string& signal, bool skipMessage)
      : CommandResult(CmdName, TargetId)
    {

      setSignal(signal);
      setSkipMessage(skipMessage);
    }

    IsEncryptionNavMessageSkippedResult::IsEncryptionNavMessageSkippedResult(CommandBasePtr relatedCommand, const std::string& signal, bool skipMessage)
      : CommandResult(CmdName, TargetId, relatedCommand)
    {

      setSignal(signal);
      setSkipMessage(skipMessage);
    }


    IsEncryptionNavMessageSkippedResultPtr IsEncryptionNavMessageSkippedResult::create(const std::string& signal, bool skipMessage)
    {
      return std::make_shared<IsEncryptionNavMessageSkippedResult>(signal, skipMessage);
    }

    IsEncryptionNavMessageSkippedResultPtr IsEncryptionNavMessageSkippedResult::create(CommandBasePtr relatedCommand, const std::string& signal, bool skipMessage)
    {
      return std::make_shared<IsEncryptionNavMessageSkippedResult>(relatedCommand, signal, skipMessage);
    }

    IsEncryptionNavMessageSkippedResultPtr IsEncryptionNavMessageSkippedResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<IsEncryptionNavMessageSkippedResult>(ptr);
    }

    bool IsEncryptionNavMessageSkippedResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["Signal"])
          && parse_json<bool>::is_valid(m_values["SkipMessage"])
        ;

    }

    std::string IsEncryptionNavMessageSkippedResult::documentation() const { return Documentation; }

    const std::vector<std::string>& IsEncryptionNavMessageSkippedResult::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Signal", "SkipMessage"}; 
      return names; 
    }


    std::string IsEncryptionNavMessageSkippedResult::signal() const
    {
      return parse_json<std::string>::parse(m_values["Signal"]);
    }

    void IsEncryptionNavMessageSkippedResult::setSignal(const std::string& signal)
    {
      setValue("Signal", parse_json<std::string>::format(signal, m_values.GetAllocator()));
    }



    bool IsEncryptionNavMessageSkippedResult::skipMessage() const
    {
      return parse_json<bool>::parse(m_values["SkipMessage"]);
    }

    void IsEncryptionNavMessageSkippedResult::setSkipMessage(bool skipMessage)
    {
      setValue("SkipMessage", parse_json<bool>::format(skipMessage, m_values.GetAllocator()));
    }


  }
}
