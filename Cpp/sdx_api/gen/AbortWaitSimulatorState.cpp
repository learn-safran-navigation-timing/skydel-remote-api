
#include "AbortWaitSimulatorState.h"

#include "command_factory.h"
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
    const char* const AbortWaitSimulatorState::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(AbortWaitSimulatorState);
    REGISTER_COMMAND_TO_FACTORY_IMPL(AbortWaitSimulatorState);


    AbortWaitSimulatorState::AbortWaitSimulatorState()
      : CommandBase(CmdName, TargetId)
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

    const std::vector<std::string>& AbortWaitSimulatorState::fieldNames() const 
    { 
      static const std::vector<std::string> names {}; 
      return names; 
    }


    int AbortWaitSimulatorState::executePermission() const
    {
      return EXECUTE_IF_NO_CONFIG | EXECUTE_IF_IDLE | EXECUTE_IF_SIMULATING;
    }

  }
}
