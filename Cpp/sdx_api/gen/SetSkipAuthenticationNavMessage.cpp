
#include "SetSkipAuthenticationNavMessage.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetSkipAuthenticationNavMessage
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetSkipAuthenticationNavMessage::CmdName = "SetSkipAuthenticationNavMessage";
    const char* const SetSkipAuthenticationNavMessage::Documentation = "Set Skips all authentication messages in the message sequence of the given signal.\n"
      "\n"
      "Name        Type   Description\n"
      "----------- ------ -------------------------------------------------------------------\n"
      "Signal      string Signal key, accepted values : \"PULSARX1\" and \"PULSARX5\".\n"
      "SkipMessage bool   If True, skips the authentication messages in the message sequence.";
    const char* const SetSkipAuthenticationNavMessage::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(SetSkipAuthenticationNavMessage);
    REGISTER_COMMAND_TO_FACTORY_IMPL(SetSkipAuthenticationNavMessage);


    SetSkipAuthenticationNavMessage::SetSkipAuthenticationNavMessage()
      : CommandBase(CmdName, TargetId)
    {}

    SetSkipAuthenticationNavMessage::SetSkipAuthenticationNavMessage(const std::string& signal, bool skipMessage)
      : CommandBase(CmdName, TargetId)
    {

      setSignal(signal);
      setSkipMessage(skipMessage);
    }

    SetSkipAuthenticationNavMessagePtr SetSkipAuthenticationNavMessage::create(const std::string& signal, bool skipMessage)
    {
      return std::make_shared<SetSkipAuthenticationNavMessage>(signal, skipMessage);
    }

    SetSkipAuthenticationNavMessagePtr SetSkipAuthenticationNavMessage::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetSkipAuthenticationNavMessage>(ptr);
    }

    bool SetSkipAuthenticationNavMessage::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["Signal"])
          && parse_json<bool>::is_valid(m_values["SkipMessage"])
        ;

    }

    std::string SetSkipAuthenticationNavMessage::documentation() const { return Documentation; }

    const std::vector<std::string>& SetSkipAuthenticationNavMessage::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Signal", "SkipMessage"}; 
      return names; 
    }


    int SetSkipAuthenticationNavMessage::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string SetSkipAuthenticationNavMessage::signal() const
    {
      return parse_json<std::string>::parse(m_values["Signal"]);
    }

    void SetSkipAuthenticationNavMessage::setSignal(const std::string& signal)
    {
      setValue("Signal", parse_json<std::string>::format(signal, m_values.GetAllocator()));
    }



    bool SetSkipAuthenticationNavMessage::skipMessage() const
    {
      return parse_json<bool>::parse(m_values["SkipMessage"]);
    }

    void SetSkipAuthenticationNavMessage::setSkipMessage(bool skipMessage)
    {
      setValue("SkipMessage", parse_json<bool>::format(skipMessage, m_values.GetAllocator()));
    }


  }
}
