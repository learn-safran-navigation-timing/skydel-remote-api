
#include "gen/SimulatorStateResult.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of SimulatorStateResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SimulatorStateResult::CmdName = "SimulatorStateResult";
    const char* const SimulatorStateResult::Documentation = "Simulator State Result.\nPossible substates are :\n-None\n-Incomplete\n-Ready\n-Initializing\n-Armed\n-Streaming RF\n-Sync Worker\n-WF Init (Worker)\n-WF Init (Main)\n-HIL Sync\n-Sync Init\n-Sync PPS Reset\n-Sync Start Time\n-Sync Start\n-Error";

    REGISTER_COMMAND_RESULT_TO_FACTORY_IMPL(SimulatorStateResult);


    SimulatorStateResult::SimulatorStateResult()
      : CommandResult(CmdName)
    {}

    SimulatorStateResult::SimulatorStateResult(const std::string& state, const std::string& error, const Sdx::SimulatorState& stateId, const Sdx::SimulatorSubState& subStateId)
      : CommandResult(CmdName)
    {

      setState(state);
      setError(error);
      setStateId(stateId);
      setSubStateId(subStateId);
    }

    SimulatorStateResult::SimulatorStateResult(CommandBasePtr relatedCommand, const std::string& state, const std::string& error, const Sdx::SimulatorState& stateId, const Sdx::SimulatorSubState& subStateId)
      : CommandResult(CmdName, relatedCommand)
    {

      setState(state);
      setError(error);
      setStateId(stateId);
      setSubStateId(subStateId);
    }


    SimulatorStateResultPtr SimulatorStateResult::create(const std::string& state, const std::string& error, const Sdx::SimulatorState& stateId, const Sdx::SimulatorSubState& subStateId)
    {
      return std::make_shared<SimulatorStateResult>(state, error, stateId, subStateId);
    }

    SimulatorStateResultPtr SimulatorStateResult::create(CommandBasePtr relatedCommand, const std::string& state, const std::string& error, const Sdx::SimulatorState& stateId, const Sdx::SimulatorSubState& subStateId)
    {
      return std::make_shared<SimulatorStateResult>(relatedCommand, state, error, stateId, subStateId);
    }

    SimulatorStateResultPtr SimulatorStateResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SimulatorStateResult>(ptr);
    }

    bool SimulatorStateResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["State"])
          && parse_json<std::string>::is_valid(m_values["Error"])
          && parse_json<Sdx::SimulatorState>::is_valid(m_values["StateId"])
          && parse_json<Sdx::SimulatorSubState>::is_valid(m_values["SubStateId"])
        ;

    }

    std::string SimulatorStateResult::documentation() const { return Documentation; }


    std::string SimulatorStateResult::state() const
    {
      return parse_json<std::string>::parse(m_values["State"]);
    }

    void SimulatorStateResult::setState(const std::string& state)
    {
      m_values.AddMember("State", parse_json<std::string>::format(state, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string SimulatorStateResult::error() const
    {
      return parse_json<std::string>::parse(m_values["Error"]);
    }

    void SimulatorStateResult::setError(const std::string& error)
    {
      m_values.AddMember("Error", parse_json<std::string>::format(error, m_values.GetAllocator()), m_values.GetAllocator());
    }



    Sdx::SimulatorState SimulatorStateResult::stateId() const
    {
      return parse_json<Sdx::SimulatorState>::parse(m_values["StateId"]);
    }

    void SimulatorStateResult::setStateId(const Sdx::SimulatorState& stateId)
    {
      m_values.AddMember("StateId", parse_json<Sdx::SimulatorState>::format(stateId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    Sdx::SimulatorSubState SimulatorStateResult::subStateId() const
    {
      return parse_json<Sdx::SimulatorSubState>::parse(m_values["SubStateId"]);
    }

    void SimulatorStateResult::setSubStateId(const Sdx::SimulatorSubState& subStateId)
    {
      m_values.AddMember("SubStateId", parse_json<Sdx::SimulatorSubState>::format(subStateId, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
