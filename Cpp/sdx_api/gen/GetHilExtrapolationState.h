#pragma once

#include <memory>
#include "command_base.h"



namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Get last Hardware in the loop extrapolation state. The states are defined as
    /// the following increasing priority levels: Deterministic, NonDeterministic and Snap.
    /// The state will stay on the highest level until polled. Polling the extrapolation state will reset it.
    /// Returns GetHilExtrapolationStateResult.
    ///
    /// 
    ///

    class GetHilExtrapolationState;
    typedef std::shared_ptr<GetHilExtrapolationState> GetHilExtrapolationStatePtr;
    
    
    class GetHilExtrapolationState : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetHilExtrapolationState();

      static GetHilExtrapolationStatePtr create();
      static GetHilExtrapolationStatePtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;
    };
    
  }
}

