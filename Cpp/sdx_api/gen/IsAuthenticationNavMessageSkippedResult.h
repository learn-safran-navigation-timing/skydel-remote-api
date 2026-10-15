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
    /// Result of IsAuthenticationNavMessageSkipped.
    ///
    /// Name        Type   Description
    /// ----------- ------ -------------------------------------------------------------------
    /// Signal      string Signal key, accepted values : "PULSARX1" and "PULSARX5".
    /// SkipMessage bool   If True, skips the authentication messages in the message sequence.
    ///

    class IsAuthenticationNavMessageSkippedResult;
    typedef std::shared_ptr<IsAuthenticationNavMessageSkippedResult> IsAuthenticationNavMessageSkippedResultPtr;
    
    
    class IsAuthenticationNavMessageSkippedResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      IsAuthenticationNavMessageSkippedResult();

      IsAuthenticationNavMessageSkippedResult(const std::string& signal, bool skipMessage);

      IsAuthenticationNavMessageSkippedResult(CommandBasePtr relatedCommand, const std::string& signal, bool skipMessage);

      static IsAuthenticationNavMessageSkippedResultPtr create(const std::string& signal, bool skipMessage);

      static IsAuthenticationNavMessageSkippedResultPtr create(CommandBasePtr relatedCommand, const std::string& signal, bool skipMessage);
      static IsAuthenticationNavMessageSkippedResultPtr dynamicCast(CommandBasePtr ptr);
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
    REGISTER_COMMAND_TO_FACTORY_DECL(IsAuthenticationNavMessageSkippedResult);
  }
}

