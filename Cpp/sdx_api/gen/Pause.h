#pragma once

#include <memory>
#include "command_base.h"



namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Pause vehicle motion during simulation.
    ///
    /// 
    ///

    class Pause;
    typedef std::shared_ptr<Pause> PausePtr;
    
    
    class Pause : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      Pause();

      static PausePtr create();
      static PausePtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;
    };
    
  }
}

