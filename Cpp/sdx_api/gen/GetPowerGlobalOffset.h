#pragma once

#include <memory>
#include "command_base.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Get global power offset default value for all signals and all systems
    ///
    /// 
    ///

    class GetPowerGlobalOffset;
    typedef std::shared_ptr<GetPowerGlobalOffset> GetPowerGlobalOffsetPtr;
    
    
    class GetPowerGlobalOffset : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetPowerGlobalOffset();
  
      static GetPowerGlobalOffsetPtr create();
      static GetPowerGlobalOffsetPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;
    };
  }
}

