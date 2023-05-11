#pragma once

#include <memory>
#include "command_base.h"



namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Get elevation mask angle. See command EnableElevationMaskBelow
    ///
    /// 
    ///

    class GetElevationMaskBelow;
    typedef std::shared_ptr<GetElevationMaskBelow> GetElevationMaskBelowPtr;
    
    
    class GetElevationMaskBelow : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetElevationMaskBelow();

      static GetElevationMaskBelowPtr create();
      static GetElevationMaskBelowPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;
    };
    
  }
}

