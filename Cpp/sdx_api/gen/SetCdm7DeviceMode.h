#pragma once

#include <memory>
#include "command_base.h"

#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Set the device mode of the CDM-7 clock distribution and timing reference module.
    /// 
    /// Note: All connected CDM-7 modules operate in the same device mode.
    ///
    /// Name       Type   Description
    /// ---------- ------ --------------------------------------------------------------------------------------------------------------
    /// DeviceMode string CDM-7 device mode. Supported device modes are: "Internal", "Synchronous External" and "Asynchronous External".
    ///

    class SetCdm7DeviceMode;
    typedef std::shared_ptr<SetCdm7DeviceMode> SetCdm7DeviceModePtr;
    
    
    class SetCdm7DeviceMode : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      SetCdm7DeviceMode();

      SetCdm7DeviceMode(const std::string& deviceMode);

      static SetCdm7DeviceModePtr create(const std::string& deviceMode);
      static SetCdm7DeviceModePtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;

      virtual int executePermission() const override;


      // **** deviceMode ****
      std::string deviceMode() const;
      void setDeviceMode(const std::string& deviceMode);
    };
    
  }
}

