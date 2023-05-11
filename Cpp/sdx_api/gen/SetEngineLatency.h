#pragma once

#include <memory>
#include "command_base.h"



namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Set engine latency.
    ///
    /// Name    Type Description
    /// ------- ---- ----------------------
    /// Latency int  Engine latency in msec
    ///

    class SetEngineLatency;
    typedef std::shared_ptr<SetEngineLatency> SetEngineLatencyPtr;
    
    
    class SetEngineLatency : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      SetEngineLatency();

      SetEngineLatency(int latency);

      static SetEngineLatencyPtr create(int latency);
      static SetEngineLatencyPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** latency ****
      int latency() const;
      void setLatency(int latency);
    };
    
  }
}

