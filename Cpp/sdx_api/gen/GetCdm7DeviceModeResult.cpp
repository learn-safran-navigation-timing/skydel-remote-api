
#include "GetCdm7DeviceModeResult.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetCdm7DeviceModeResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetCdm7DeviceModeResult::CmdName = "GetCdm7DeviceModeResult";
    const char* const GetCdm7DeviceModeResult::Documentation = "Result of GetCdm7DeviceMode.\n"
      "\n"
      "Name       Type   Description\n"
      "---------- ------ --------------------------------------------------------------------------------------------------------------\n"
      "DeviceMode string CDM-7 device mode. Supported device modes are: \"Internal\", \"Synchronous External\" and \"Asynchronous External\".";
    const char* const GetCdm7DeviceModeResult::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_IMPL(GetCdm7DeviceModeResult);


    GetCdm7DeviceModeResult::GetCdm7DeviceModeResult()
      : CommandResult(CmdName, TargetId)
    {}

    GetCdm7DeviceModeResult::GetCdm7DeviceModeResult(const std::string& deviceMode)
      : CommandResult(CmdName, TargetId)
    {

      setDeviceMode(deviceMode);
    }

    GetCdm7DeviceModeResult::GetCdm7DeviceModeResult(CommandBasePtr relatedCommand, const std::string& deviceMode)
      : CommandResult(CmdName, TargetId, relatedCommand)
    {

      setDeviceMode(deviceMode);
    }


    GetCdm7DeviceModeResultPtr GetCdm7DeviceModeResult::create(const std::string& deviceMode)
    {
      return std::make_shared<GetCdm7DeviceModeResult>(deviceMode);
    }

    GetCdm7DeviceModeResultPtr GetCdm7DeviceModeResult::create(CommandBasePtr relatedCommand, const std::string& deviceMode)
    {
      return std::make_shared<GetCdm7DeviceModeResult>(relatedCommand, deviceMode);
    }

    GetCdm7DeviceModeResultPtr GetCdm7DeviceModeResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetCdm7DeviceModeResult>(ptr);
    }

    bool GetCdm7DeviceModeResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["DeviceMode"])
        ;

    }

    std::string GetCdm7DeviceModeResult::documentation() const { return Documentation; }

    const std::vector<std::string>& GetCdm7DeviceModeResult::fieldNames() const 
    { 
      static const std::vector<std::string> names {"DeviceMode"}; 
      return names; 
    }


    std::string GetCdm7DeviceModeResult::deviceMode() const
    {
      return parse_json<std::string>::parse(m_values["DeviceMode"]);
    }

    void GetCdm7DeviceModeResult::setDeviceMode(const std::string& deviceMode)
    {
      m_values.AddMember("DeviceMode", parse_json<std::string>::format(deviceMode, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
