#pragma once

#include <memory>
#include "command_base.h"



namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Ask current simulator state. Will return a SimulatorStateResult.
    ///
    /// 
    ///

    class GetSimulatorState;
    typedef std::shared_ptr<GetSimulatorState> GetSimulatorStatePtr;
    
    
    class GetSimulatorState : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      GetSimulatorState();

      static GetSimulatorStatePtr create();
      static GetSimulatorStatePtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;

      virtual int executePermission() const override;
    };
    
  }
}

