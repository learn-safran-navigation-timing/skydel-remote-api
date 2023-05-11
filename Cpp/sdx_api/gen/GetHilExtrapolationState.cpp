
#include "gen/GetHilExtrapolationState.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetHilExtrapolationState
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetHilExtrapolationState::CmdName = "GetHilExtrapolationState";
    const char* const GetHilExtrapolationState::Documentation = "Get last Hardware in the loop extrapolation state. The states are defined as\nthe following increasing priority levels: Deterministic, NonDeterministic and Snap.\nThe state will stay on the highest level until polled. Polling the extrapolation state will reset it.\nReturns GetHilExtrapolationStateResult.";

    REGISTER_COMMAND_FACTORY(GetHilExtrapolationState);


    GetHilExtrapolationState::GetHilExtrapolationState()
      : CommandBase(CmdName)
    {

    }

    GetHilExtrapolationStatePtr GetHilExtrapolationState::create()
    {
      return std::make_shared<GetHilExtrapolationState>();
    }

    GetHilExtrapolationStatePtr GetHilExtrapolationState::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetHilExtrapolationState>(ptr);
    }

    bool GetHilExtrapolationState::isValid() const
    {
      
        return m_values.IsObject()
        ;

    }

    std::string GetHilExtrapolationState::documentation() const { return Documentation; }


    int GetHilExtrapolationState::executePermission() const
    {
      return EXECUTE_IF_SIMULATING;
    }

  }
}
