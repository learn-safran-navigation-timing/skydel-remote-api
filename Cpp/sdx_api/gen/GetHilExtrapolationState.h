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
      static const char* const TargetId;


      GetHilExtrapolationState();

      static GetHilExtrapolationStatePtr create();
      static GetHilExtrapolationStatePtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;

      virtual int executePermission() const override;
    };
    
  }
}

