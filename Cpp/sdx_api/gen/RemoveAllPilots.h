#pragma once

#include <memory>
#include "command_base.h"



namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Remove all pilots on all outputs
    ///
    /// 
    ///

    class RemoveAllPilots;
    typedef std::shared_ptr<RemoveAllPilots> RemoveAllPilotsPtr;
    
    
    class RemoveAllPilots : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      RemoveAllPilots();

      static RemoveAllPilotsPtr create();
      static RemoveAllPilotsPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;
    };
    
  }
}

