#pragma once

#include <memory>
#include "command_base.h"



namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Get whether the ionospheric offsets grid should be applied to the ionosphere
    ///
    /// 
    ///

    class IsIonoOffsetEnabled;
    typedef std::shared_ptr<IsIonoOffsetEnabled> IsIonoOffsetEnabledPtr;
    
    
    class IsIonoOffsetEnabled : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      IsIonoOffsetEnabled();

      static IsIonoOffsetEnabledPtr create();
      static IsIonoOffsetEnabledPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;

      virtual int executePermission() const override;
    };
    
  }
}

