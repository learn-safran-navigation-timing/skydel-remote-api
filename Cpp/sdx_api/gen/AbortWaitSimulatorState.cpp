
#include "gen/AbortWaitSimulatorState.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of AbortWaitSimulatorState
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const AbortWaitSimulatorState::CmdName = "AbortWaitSimulatorState";
    const char* const AbortWaitSimulatorState::Documentation = "Abort the current WaitSimulatorState if any.";

    REGISTER_COMMAND_FACTORY(AbortWaitSimulatorState);


    AbortWaitSimulatorState::AbortWaitSimulatorState()
      : CommandBase(CmdName)
    {

    }

    AbortWaitSimulatorStatePtr AbortWaitSimulatorState::create()
    {
      return std::make_shared<AbortWaitSimulatorState>();
    }

    AbortWaitSimulatorStatePtr AbortWaitSimulatorState::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<AbortWaitSimulatorState>(ptr);
    }

    bool AbortWaitSimulatorState::isValid() const
    {
      
        return m_values.IsObject()
        ;

    }

    std::string AbortWaitSimulatorState::documentation() const { return Documentation; }


    int AbortWaitSimulatorState::executePermission() const
    {
      return EXECUTE_IF_NO_CONFIG | EXECUTE_IF_IDLE | EXECUTE_IF_SIMULATING;
    }

  }
}
