#pragma once

#include <memory>
#include "command_result.h"
#include "command_factory.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of IsStopMainInstanceWhenWorkerInstanceStop.
    ///
    /// Name    Type Description
    /// ------- ---- ---------------------------------------------------------
    /// Enabled bool Enable main instance stop when worker instance stops flag
    ///

    class IsStopMainInstanceWhenWorkerInstanceStopResult;
    typedef std::shared_ptr<IsStopMainInstanceWhenWorkerInstanceStopResult> IsStopMainInstanceWhenWorkerInstanceStopResultPtr;
    
    
    class IsStopMainInstanceWhenWorkerInstanceStopResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      IsStopMainInstanceWhenWorkerInstanceStopResult();

      IsStopMainInstanceWhenWorkerInstanceStopResult(bool enabled);

      IsStopMainInstanceWhenWorkerInstanceStopResult(CommandBasePtr relatedCommand, bool enabled);

      static IsStopMainInstanceWhenWorkerInstanceStopResultPtr create(bool enabled);

      static IsStopMainInstanceWhenWorkerInstanceStopResultPtr create(CommandBasePtr relatedCommand, bool enabled);
      static IsStopMainInstanceWhenWorkerInstanceStopResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;


      // **** enabled ****
      bool enabled() const;
      void setEnabled(bool enabled);
    };
    REGISTER_COMMAND_TO_FACTORY_DECL(IsStopMainInstanceWhenWorkerInstanceStopResult);
  }
}

