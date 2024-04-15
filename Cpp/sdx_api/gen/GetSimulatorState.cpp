
#include "GetSimulatorState.h"

#include "command_factory.h"
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
    const char* const GetSimulatorState::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(GetSimulatorState);
    REGISTER_COMMAND_TO_FACTORY_IMPL(GetSimulatorState);


    GetSimulatorState::GetSimulatorState()
      : CommandBase(CmdName, TargetId)
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

    const std::vector<std::string>& GetSimulatorState::fieldNames() const 
    { 
      static const std::vector<std::string> names {}; 
      return names; 
    }


    int GetSimulatorState::executePermission() const
    {
      return EXECUTE_IF_NO_CONFIG | EXECUTE_IF_IDLE | EXECUTE_IF_SIMULATING;
    }

  }
}
