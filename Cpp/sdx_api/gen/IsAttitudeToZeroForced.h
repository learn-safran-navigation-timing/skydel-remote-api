#pragma once

#include <memory>
#include "command_base.h"



namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Get force vehicle yaw, pitch and roll to zero enabled or disabled
    ///
    /// 
    ///

    class IsAttitudeToZeroForced;
    typedef std::shared_ptr<IsAttitudeToZeroForced> IsAttitudeToZeroForcedPtr;
    
    
    class IsAttitudeToZeroForced : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      IsAttitudeToZeroForced();

      static IsAttitudeToZeroForcedPtr create();
      static IsAttitudeToZeroForcedPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;

      virtual int executePermission() const override;
    };
    
  }
}

