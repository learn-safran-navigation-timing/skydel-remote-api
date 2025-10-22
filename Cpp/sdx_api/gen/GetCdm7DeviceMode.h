#pragma once

#include <memory>
#include "command_base.h"



namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Get the device mode of the CDM-7 clock distribution and timing reference module.
    /// 
    /// Note: All connected CDM-7 modules operate in the same device mode.
    ///
    /// 
    ///

    class GetCdm7DeviceMode;
    typedef std::shared_ptr<GetCdm7DeviceMode> GetCdm7DeviceModePtr;
    
    
    class GetCdm7DeviceMode : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      GetCdm7DeviceMode();

      static GetCdm7DeviceModePtr create();
      static GetCdm7DeviceModePtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;

      virtual int executePermission() const override;
    };
    
  }
}

