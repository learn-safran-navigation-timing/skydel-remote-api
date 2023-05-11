#pragma once

#include <memory>
#include "command_base.h"



namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Get GNSS satellite mask based on elevation enabled or disabled (See SetElevationMaskAbove).
    ///
    /// 
    ///

    class IsElevationMaskAboveEnabled;
    typedef std::shared_ptr<IsElevationMaskAboveEnabled> IsElevationMaskAboveEnabledPtr;
    
    
    class IsElevationMaskAboveEnabled : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      IsElevationMaskAboveEnabled();

      static IsElevationMaskAboveEnabledPtr create();
      static IsElevationMaskAboveEnabledPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;
    };
    
  }
}

