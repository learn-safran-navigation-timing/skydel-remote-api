#pragma once

#include <memory>
#include "command_base.h"

#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Set Skips all encryption messages in the message sequence of the given signal.
    ///
    /// Name        Type   Description
    /// ----------- ------ ---------------------------------------------------------------
    /// Signal      string Signal key, accepted values : "PULSARX1" and "PULSARX5".
    /// SkipMessage bool   If True, skips the encryption messages in the message sequence.
    ///

    class SetSkipEncryptionNavMessage;
    typedef std::shared_ptr<SetSkipEncryptionNavMessage> SetSkipEncryptionNavMessagePtr;
    
    
    class SetSkipEncryptionNavMessage : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      SetSkipEncryptionNavMessage();

      SetSkipEncryptionNavMessage(const std::string& signal, bool skipMessage);

      static SetSkipEncryptionNavMessagePtr create(const std::string& signal, bool skipMessage);
      static SetSkipEncryptionNavMessagePtr dynamicCast(CommandBasePtr ptr);
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

