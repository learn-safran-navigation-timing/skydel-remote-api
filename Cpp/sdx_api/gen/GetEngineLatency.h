#pragma once

#include <memory>
#include "command_base.h"



namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Get engine latency.
    ///
    /// 
    ///

    class GetEngineLatency;
    typedef std::shared_ptr<GetEngineLatency> GetEngineLatencyPtr;
    
    
    class GetEngineLatency : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetEngineLatency();

      static GetEngineLatencyPtr create();
      static GetEngineLatencyPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;
    };
    
  }
}

