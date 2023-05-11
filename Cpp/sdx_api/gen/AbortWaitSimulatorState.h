#pragma once

#include <memory>
#include "command_base.h"



namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Abort the current WaitSimulatorState if any.
    ///
    /// 
    ///

    class AbortWaitSimulatorState;
    typedef std::shared_ptr<AbortWaitSimulatorState> AbortWaitSimulatorStatePtr;
    
    
    class AbortWaitSimulatorState : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      AbortWaitSimulatorState();

      static AbortWaitSimulatorStatePtr create();
      static AbortWaitSimulatorStatePtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;
    };
    
  }
}

