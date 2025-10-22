#pragma once

#include <memory>
#include "command_result.h"
#include "command_factory.h"
#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of GetCdm7DeviceMode.
    ///
    /// Name       Type   Description
    /// ---------- ------ --------------------------------------------------------------------------------------------------------------
    /// DeviceMode string CDM-7 device mode. Supported device modes are: "Internal", "Synchronous External" and "Asynchronous External".
    ///

    class GetCdm7DeviceModeResult;
    typedef std::shared_ptr<GetCdm7DeviceModeResult> GetCdm7DeviceModeResultPtr;
    
    
    class GetCdm7DeviceModeResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      GetCdm7DeviceModeResult();

      GetCdm7DeviceModeResult(const std::string& deviceMode);

      GetCdm7DeviceModeResult(CommandBasePtr relatedCommand, const std::string& deviceMode);

      static GetCdm7DeviceModeResultPtr create(const std::string& deviceMode);

      static GetCdm7DeviceModeResultPtr create(CommandBasePtr relatedCommand, const std::string& deviceMode);
      static GetCdm7DeviceModeResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;


      // **** deviceMode ****
      std::string deviceMode() const;
      void setDeviceMode(const std::string& deviceMode);
    };
    REGISTER_COMMAND_TO_FACTORY_DECL(GetCdm7DeviceModeResult);
  }
}

