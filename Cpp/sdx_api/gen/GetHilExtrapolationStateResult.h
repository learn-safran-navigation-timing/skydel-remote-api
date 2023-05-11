#pragma once

#include <memory>
#include "command_result.h"
#include "command_result_factory.h"
#include "gen/HilExtrapolationState.h"

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of GetHilExtrapolationState.
    ///
    /// Name        Type                  Description
    /// ----------- --------------------- ---------------------------------------------------------
    /// State       HilExtrapolationState HIL Extrapolation State.
    /// ElapsedTime int                   Time in milliseconds of the returned extrapolation state.
    ///

    class GetHilExtrapolationStateResult;
    typedef std::shared_ptr<GetHilExtrapolationStateResult> GetHilExtrapolationStateResultPtr;
    
    
    class GetHilExtrapolationStateResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetHilExtrapolationStateResult();

      GetHilExtrapolationStateResult(const Sdx::HilExtrapolationState& state, int elapsedTime);

      GetHilExtrapolationStateResult(CommandBasePtr relatedCommand, const Sdx::HilExtrapolationState& state, int elapsedTime);

      static GetHilExtrapolationStateResultPtr create(const Sdx::HilExtrapolationState& state, int elapsedTime);

      static GetHilExtrapolationStateResultPtr create(CommandBasePtr relatedCommand, const Sdx::HilExtrapolationState& state, int elapsedTime);
      static GetHilExtrapolationStateResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;


      // **** state ****
      Sdx::HilExtrapolationState state() const;
      void setState(const Sdx::HilExtrapolationState& state);


      // **** elapsedTime ****
      int elapsedTime() const;
      void setElapsedTime(int elapsedTime);
    };
    REGISTER_COMMAND_RESULT_TO_FACTORY_DECL(GetHilExtrapolationStateResult);
  }
}

