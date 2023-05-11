#pragma once

#include <memory>
#include "command_base.h"



namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Remove all modulation targets.
    ///
    /// 
    ///

    class RemoveAllModulationTargets;
    typedef std::shared_ptr<RemoveAllModulationTargets> RemoveAllModulationTargetsPtr;
    
    
    class RemoveAllModulationTargets : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      RemoveAllModulationTargets();

      static RemoveAllModulationTargetsPtr create();
      static RemoveAllModulationTargetsPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;
    };
    
  }
}

