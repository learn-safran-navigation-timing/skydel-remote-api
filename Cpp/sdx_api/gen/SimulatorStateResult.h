#pragma once

#include <memory>
#include "command_result.h"
#include "command_result_factory.h"
#include "gen/SimulatorState.h"
#include "gen/SimulatorSubState.h"
#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Simulator State Result.
    /// Possible substates are :
    /// -None
    /// -Incomplete
    /// -Ready
    /// -Initializing
    /// -Armed
    /// -Streaming RF
    /// -Sync Worker
    /// -WF Init (Worker)
    /// -WF Init (Main)
    /// -HIL Sync
    /// -Sync Init
    /// -Sync PPS Reset
    /// -Sync Start Time
    /// -Sync Start
    /// -Error
    ///
    /// Name       Type              Description
    /// ---------- ----------------- ------------------------------------
    /// State      string            Simulator substate.
    /// Error      string            Error Message if state is Error.
    /// StateId    SimulatorState    Simulator State value as an enum.
    /// SubStateId SimulatorSubState Simulator SubState value as an enum.
    ///

    class SimulatorStateResult;
    typedef std::shared_ptr<SimulatorStateResult> SimulatorStateResultPtr;
    
    
    class SimulatorStateResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      SimulatorStateResult();

      SimulatorStateResult(const std::string& state, const std::string& error, const Sdx::SimulatorState& stateId, const Sdx::SimulatorSubState& subStateId);

      SimulatorStateResult(CommandBasePtr relatedCommand, const std::string& state, const std::string& error, const Sdx::SimulatorState& stateId, const Sdx::SimulatorSubState& subStateId);

      static SimulatorStateResultPtr create(const std::string& state, const std::string& error, const Sdx::SimulatorState& stateId, const Sdx::SimulatorSubState& subStateId);

      static SimulatorStateResultPtr create(CommandBasePtr relatedCommand, const std::string& state, const std::string& error, const Sdx::SimulatorState& stateId, const Sdx::SimulatorSubState& subStateId);
      static SimulatorStateResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;


      // **** state ****
      std::string state() const;
      void setState(const std::string& state);


      // **** error ****
      std::string error() const;
      void setError(const std::string& error);


      // **** stateId ****
      Sdx::SimulatorState stateId() const;
      void setStateId(const Sdx::SimulatorState& stateId);


      // **** subStateId ****
      Sdx::SimulatorSubState subStateId() const;
      void setSubStateId(const Sdx::SimulatorSubState& subStateId);
    };
    REGISTER_COMMAND_RESULT_TO_FACTORY_DECL(SimulatorStateResult);
  }
}

