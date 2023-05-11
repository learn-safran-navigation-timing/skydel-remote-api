
#include "gen/GetSimulatorState.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetSimulatorState
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetSimulatorState::CmdName = "GetSimulatorState";
    const char* const GetSimulatorState::Documentation = "Ask current simulator state. Will return a SimulatorStateResult.";

    REGISTER_COMMAND_FACTORY(GetSimulatorState);


    GetSimulatorState::GetSimulatorState()
      : CommandBase(CmdName)
    {

    }

    GetSimulatorStatePtr GetSimulatorState::create()
    {
      return std::make_shared<GetSimulatorState>();
    }

    GetSimulatorStatePtr GetSimulatorState::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetSimulatorState>(ptr);
    }

    bool GetSimulatorState::isValid() const
    {
      
        return m_values.IsObject()
        ;

    }

    std::string GetSimulatorState::documentation() const { return Documentation; }


    int GetSimulatorState::executePermission() const
    {
      return EXECUTE_IF_NO_CONFIG | EXECUTE_IF_IDLE | EXECUTE_IF_SIMULATING;
    }

  }
}
