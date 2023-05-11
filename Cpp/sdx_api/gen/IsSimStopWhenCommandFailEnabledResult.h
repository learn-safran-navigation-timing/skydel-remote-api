#pragma once

#include <memory>
#include "command_result.h"
#include "command_result_factory.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of IsSimStopWhenCommandFailEnabled.
    ///
    /// Name    Type Description
    /// ------- ---- ----------------------------------
    /// Enabled bool Enable stop when command fail flag
    ///

    class IsSimStopWhenCommandFailEnabledResult;
    typedef std::shared_ptr<IsSimStopWhenCommandFailEnabledResult> IsSimStopWhenCommandFailEnabledResultPtr;
    
    
    class IsSimStopWhenCommandFailEnabledResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      IsSimStopWhenCommandFailEnabledResult();

      IsSimStopWhenCommandFailEnabledResult(bool enabled);

      IsSimStopWhenCommandFailEnabledResult(CommandBasePtr relatedCommand, bool enabled);

      static IsSimStopWhenCommandFailEnabledResultPtr create(bool enabled);

      static IsSimStopWhenCommandFailEnabledResultPtr create(CommandBasePtr relatedCommand, bool enabled);
      static IsSimStopWhenCommandFailEnabledResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;


      // **** enabled ****
      bool enabled() const;
      void setEnabled(bool enabled);
    };
    REGISTER_COMMAND_RESULT_TO_FACTORY_DECL(IsSimStopWhenCommandFailEnabledResult);
  }
}

