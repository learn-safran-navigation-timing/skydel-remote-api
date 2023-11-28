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
    /// 
    ///

    class IsStopMainInstanceWhenWorkerInstanceStop;
    typedef std::shared_ptr<IsStopMainInstanceWhenWorkerInstanceStop> IsStopMainInstanceWhenWorkerInstanceStopPtr;
    
    
    class IsStopMainInstanceWhenWorkerInstanceStop : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      IsStopMainInstanceWhenWorkerInstanceStop();

      static IsStopMainInstanceWhenWorkerInstanceStopPtr create();
      static IsStopMainInstanceWhenWorkerInstanceStopPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;
    };
    
  }
}

