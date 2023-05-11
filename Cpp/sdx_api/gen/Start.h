#pragma once

#include <memory>
#include "command_base.h"



namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Start the simulation. Simulation may or may not start depending on the current state of the simulator.
    ///
    /// 
    ///

    class Start;
    typedef std::shared_ptr<Start> StartPtr;
    
    
    class Start : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      Start();

      static StartPtr create();
      static StartPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;
    };
    
  }
}

