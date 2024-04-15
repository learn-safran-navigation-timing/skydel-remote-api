
#include "GetHilExtrapolationState.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetHilExtrapolationState
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetHilExtrapolationState::CmdName = "GetHilExtrapolationState";
    const char* const GetHilExtrapolationState::Documentation = "Get last Hardware in the loop extrapolation state. The states are defined as\n"
      "the following increasing priority levels: Deterministic, NonDeterministic and Snap.\n"
      "The state will stay on the highest level until polled. Polling the extrapolation state will reset it.\n"
      "Returns GetHilExtrapolationStateResult.";
    const char* const GetHilExtrapolationState::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(GetHilExtrapolationState);
    REGISTER_COMMAND_TO_FACTORY_IMPL(GetHilExtrapolationState);


    GetHilExtrapolationState::GetHilExtrapolationState()
      : CommandBase(CmdName, TargetId)
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

    const std::vector<std::string>& GetHilExtrapolationState::fieldNames() const 
    { 
      static const std::vector<std::string> names {}; 
      return names; 
    }


    int GetHilExtrapolationState::executePermission() const
    {
      return EXECUTE_IF_SIMULATING;
    }

  }
}
