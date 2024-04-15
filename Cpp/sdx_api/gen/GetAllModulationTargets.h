#pragma once

#include <memory>
#include "command_base.h"



namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Get all the modulation targets IDs
    ///
    /// 
    ///

    class GetAllModulationTargets;
    typedef std::shared_ptr<GetAllModulationTargets> GetAllModulationTargetsPtr;
    
    
    class GetAllModulationTargets : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      GetAllModulationTargets();

      static GetAllModulationTargetsPtr create();
      static GetAllModulationTargetsPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;

      virtual int executePermission() const override;
    };
    
  }
}

