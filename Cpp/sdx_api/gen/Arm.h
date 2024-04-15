#pragma once

#include <memory>
#include "command_base.h"



namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Arm the simulation. Simulation may or may not arm depending on the current state of the simulator.
    ///
    /// 
    ///

    class Arm;
    typedef std::shared_ptr<Arm> ArmPtr;
    
    
    class Arm : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      Arm();

      static ArmPtr create();
      static ArmPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;

      virtual int executePermission() const override;
    };
    
  }
}

