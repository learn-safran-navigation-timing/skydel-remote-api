
#include "SetSkipEncryptionNavMessage.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetSkipEncryptionNavMessage
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetSkipEncryptionNavMessage::CmdName = "SetSkipEncryptionNavMessage";
    const char* const SetSkipEncryptionNavMessage::Documentation = "Set Skips all encryption messages in the message sequence of the given signal.\n"
      "\n"
      "Name        Type   Description\n"
      "----------- ------ ---------------------------------------------------------------\n"
      "Signal      string Signal key, accepted values : \"PULSARX1\" and \"PULSARX5\".\n"
      "SkipMessage bool   If True, skips the encryption messages in the message sequence.";
    const char* const SetSkipEncryptionNavMessage::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(SetSkipEncryptionNavMessage);
    REGISTER_COMMAND_TO_FACTORY_IMPL(SetSkipEncryptionNavMessage);


    SetSkipEncryptionNavMessage::SetSkipEncryptionNavMessage()
      : CommandBase(CmdName, TargetId)
    {}

    SetSkipEncryptionNavMessage::SetSkipEncryptionNavMessage(const std::string& signal, bool skipMessage)
      : CommandBase(CmdName, TargetId)
    {

      setSignal(signal);
      setSkipMessage(skipMessage);
    }

    SetSkipEncryptionNavMessagePtr SetSkipEncryptionNavMessage::create(const std::string& signal, bool skipMessage)
    {
      return std::make_shared<SetSkipEncryptionNavMessage>(signal, skipMessage);
    }

    SetSkipEncryptionNavMessagePtr SetSkipEncryptionNavMessage::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetSkipEncryptionNavMessage>(ptr);
    }

    bool SetSkipEncryptionNavMessage::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["Signal"])
          && parse_json<bool>::is_valid(m_values["SkipMessage"])
        ;

    }

    std::string SetSkipEncryptionNavMessage::documentation() const { return Documentation; }

    const std::vector<std::string>& SetSkipEncryptionNavMessage::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Signal", "SkipMessage"}; 
      return names; 
    }


    int SetSkipEncryptionNavMessage::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string SetSkipEncryptionNavMessage::signal() const
    {
      return parse_json<std::string>::parse(m_values["Signal"]);
    }

    void SetSkipEncryptionNavMessage::setSignal(const std::string& signal)
    {
      setValue("Signal", parse_json<std::string>::format(signal, m_values.GetAllocator()));
    }



    bool SetSkipEncryptionNavMessage::skipMessage() const
    {
      return parse_json<bool>::parse(m_values["SkipMessage"]);
    }

    void SetSkipEncryptionNavMessage::setSkipMessage(bool skipMessage)
    {
      setValue("SkipMessage", parse_json<bool>::format(skipMessage, m_values.GetAllocator()));
    }


  }
}
