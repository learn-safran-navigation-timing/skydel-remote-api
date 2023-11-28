#pragma once

#include <memory>
#include "command_base.h"



namespace Sdx
{
  namespace Cmd
  {
    ///
    /// If enabled, main instance and all the worker instances will stop if a worker instance stops.
    ///
    /// Name    Type Description
    /// ------- ---- ---------------------------------------------------------
    /// Enabled bool Enable main instance stop when worker instance stops flag
    ///

    class StopMainInstanceWhenWorkerInstanceStop;
    typedef std::shared_ptr<StopMainInstanceWhenWorkerInstanceStop> StopMainInstanceWhenWorkerInstanceStopPtr;
    
    
    class StopMainInstanceWhenWorkerInstanceStop : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      StopMainInstanceWhenWorkerInstanceStop();

      StopMainInstanceWhenWorkerInstanceStop(bool enabled);

      static StopMainInstanceWhenWorkerInstanceStopPtr create(bool enabled);
      static StopMainInstanceWhenWorkerInstanceStopPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** enabled ****
      bool enabled() const;
      void setEnabled(bool enabled);
    };
    
  }
}

