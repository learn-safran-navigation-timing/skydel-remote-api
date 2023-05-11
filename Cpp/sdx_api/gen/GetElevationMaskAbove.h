#pragma once

#include <memory>
#include "command_base.h"



namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Get elevation mask angle. See command EnableElevationMaskAbove
    ///
    /// 
    ///

    class GetElevationMaskAbove;
    typedef std::shared_ptr<GetElevationMaskAbove> GetElevationMaskAbovePtr;
    
    
    class GetElevationMaskAbove : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetElevationMaskAbove();

      static GetElevationMaskAbovePtr create();
      static GetElevationMaskAbovePtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;
    };
    
  }
}

