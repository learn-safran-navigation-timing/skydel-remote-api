#pragma once

#include <memory>
#include "command_base.h"

#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Set Skips all authentication messages in the message sequence of the given signal.
    ///
    /// Name        Type   Description
    /// ----------- ------ -------------------------------------------------------------------
    /// Signal      string Signal key, accepted values : "PULSARX1" and "PULSARX5".
    /// SkipMessage bool   If True, skips the authentication messages in the message sequence.
    ///

    class SetSkipAuthenticationNavMessage;
    typedef std::shared_ptr<SetSkipAuthenticationNavMessage> SetSkipAuthenticationNavMessagePtr;
    
    
    class SetSkipAuthenticationNavMessage : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      SetSkipAuthenticationNavMessage();

      SetSkipAuthenticationNavMessage(const std::string& signal, bool skipMessage);

      static SetSkipAuthenticationNavMessagePtr create(const std::string& signal, bool skipMessage);
      static SetSkipAuthenticationNavMessagePtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;

      virtual int executePermission() const override;


      // **** signal ****
      std::string signal() const;
      void setSignal(const std::string& signal);


      // **** skipMessage ****
      bool skipMessage() const;
      void setSkipMessage(bool skipMessage);
    };
    
  }
}

