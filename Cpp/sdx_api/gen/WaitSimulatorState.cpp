
#include "WaitSimulatorState.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of WaitSimulatorState
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const WaitSimulatorState::CmdName = "WaitSimulatorState";
    const char* const WaitSimulatorState::Documentation = "Wait until simulator has reached the specified substate unless simulator goes to error state or specified failure substate. Will return a SimulatorStateResult.\n"
      "Possible substates are :\n"
      "-None\n"
      "-Incomplete\n"
      "-Ready\n"
      "-Initializing\n"
      "-Armed\n"
      "-Streaming RF\n"
      "-Sync Worker Instance\n"
      "-WF Init (Worker)\n"
      "-WF Init (Main)\n"
      "-HIL Sync\n"
      "-Sync Init\n"
      "-Sync PPS Reset\n"
      "-Sync Start Time\n"
      "-Sync Start\n"
      "-Error\n"
      "\n"
      "Name         Type   Description\n"
      "------------ ------ ----------------------------------------------------------\n"
      "State        string Simulator sub state string.\n"
      "FailureState string Abort waiting if simulator goes to this sub state instead.";
    const char* const WaitSimulatorState::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(WaitSimulatorState);
    REGISTER_COMMAND_TO_FACTORY_IMPL(WaitSimulatorState);


    WaitSimulatorState::WaitSimulatorState()
      : CommandBase(CmdName, TargetId)
    {}

    WaitSimulatorState::WaitSimulatorState(const std::string& state, const std::string& failureState)
      : CommandBase(CmdName, TargetId)
    {

      setState(state);
      setFailureState(failureState);
    }

    WaitSimulatorStatePtr WaitSimulatorState::create(const std::string& state, const std::string& failureState)
    {
      return std::make_shared<WaitSimulatorState>(state, failureState);
    }

    WaitSimulatorStatePtr WaitSimulatorState::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<WaitSimulatorState>(ptr);
    }

    bool WaitSimulatorState::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["State"])
          && parse_json<std::string>::is_valid(m_values["FailureState"])
        ;

    }

    std::string WaitSimulatorState::documentation() const { return Documentation; }

    const std::vector<std::string>& WaitSimulatorState::fieldNames() const 
    { 
      static const std::vector<std::string> names {"State", "FailureState"}; 
      return names; 
    }


    int WaitSimulatorState::executePermission() const
    {
      return EXECUTE_IF_NO_CONFIG | EXECUTE_IF_IDLE | EXECUTE_IF_SIMULATING;
    }


    std::string WaitSimulatorState::state() const
    {
      return parse_json<std::string>::parse(m_values["State"]);
    }

    void WaitSimulatorState::setState(const std::string& state)
    {
      m_values.AddMember("State", parse_json<std::string>::format(state, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string WaitSimulatorState::failureState() const
    {
      return parse_json<std::string>::parse(m_values["FailureState"]);
    }

    void WaitSimulatorState::setFailureState(const std::string& failureState)
    {
      m_values.AddMember("FailureState", parse_json<std::string>::format(failureState, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
