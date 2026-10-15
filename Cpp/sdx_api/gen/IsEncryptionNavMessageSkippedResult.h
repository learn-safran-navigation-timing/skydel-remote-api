#pragma once

#include <memory>
#include "command_result.h"
#include "command_factory.h"
#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of IsEncryptionNavMessageSkipped.
    ///
    /// Name        Type   Description
    /// ----------- ------ ---------------------------------------------------------------
    /// Signal      string Signal key, accepted values : "PULSARX1" and "PULSARX5".
    /// SkipMessage bool   If True, skips the encryption messages in the message sequence.
    ///

    class IsEncryptionNavMessageSkippedResult;
    typedef std::shared_ptr<IsEncryptionNavMessageSkippedResult> IsEncryptionNavMessageSkippedResultPtr;
    
    
    class IsEncryptionNavMessageSkippedResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      IsEncryptionNavMessageSkippedResult();

      IsEncryptionNavMessageSkippedResult(const std::string& signal, bool skipMessage);

      IsEncryptionNavMessageSkippedResult(CommandBasePtr relatedCommand, const std::string& signal, bool skipMessage);

      static IsEncryptionNavMessageSkippedResultPtr create(const std::string& signal, bool skipMessage);

      static IsEncryptionNavMessageSkippedResultPtr create(CommandBasePtr relatedCommand, const std::string& signal, bool skipMessage);
      static IsEncryptionNavMessageSkippedResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;


      // **** signal ****
      std::string signal() const;
      void setSignal(const std::string& signal);


      // **** skipMessage ****
      bool skipMessage() const;
      void setSkipMessage(bool skipMessage);
    };
    REGISTER_COMMAND_TO_FACTORY_DECL(IsEncryptionNavMessageSkippedResult);
  }
}

