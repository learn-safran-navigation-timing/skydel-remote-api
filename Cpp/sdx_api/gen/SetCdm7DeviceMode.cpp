
#include "SetCdm7DeviceMode.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetCdm7DeviceMode
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetCdm7DeviceMode::CmdName = "SetCdm7DeviceMode";
    const char* const SetCdm7DeviceMode::Documentation = "Set the device mode of the CDM-7 clock distribution and timing reference module.\n"
      "\n"
      "Note: All connected CDM-7 modules operate in the same device mode.\n"
      "\n"
      "Name       Type   Description\n"
      "---------- ------ --------------------------------------------------------------------------------------------------------------\n"
      "DeviceMode string CDM-7 device mode. Supported device modes are: \"Internal\", \"Synchronous External\" and \"Asynchronous External\".";
    const char* const SetCdm7DeviceMode::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(SetCdm7DeviceMode);
    REGISTER_COMMAND_TO_FACTORY_IMPL(SetCdm7DeviceMode);


    SetCdm7DeviceMode::SetCdm7DeviceMode()
      : CommandBase(CmdName, TargetId)
    {}

    SetCdm7DeviceMode::SetCdm7DeviceMode(const std::string& deviceMode)
      : CommandBase(CmdName, TargetId)
    {

      setDeviceMode(deviceMode);
    }

    SetCdm7DeviceModePtr SetCdm7DeviceMode::create(const std::string& deviceMode)
    {
      return std::make_shared<SetCdm7DeviceMode>(deviceMode);
    }

    SetCdm7DeviceModePtr SetCdm7DeviceMode::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetCdm7DeviceMode>(ptr);
    }

    bool SetCdm7DeviceMode::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["DeviceMode"])
        ;

    }

    std::string SetCdm7DeviceMode::documentation() const { return Documentation; }

    const std::vector<std::string>& SetCdm7DeviceMode::fieldNames() const 
    { 
      static const std::vector<std::string> names {"DeviceMode"}; 
      return names; 
    }


    int SetCdm7DeviceMode::executePermission() const
    {
      return EXECUTE_IF_NO_CONFIG | EXECUTE_IF_IDLE;
    }


    std::string SetCdm7DeviceMode::deviceMode() const
    {
      return parse_json<std::string>::parse(m_values["DeviceMode"]);
    }

    void SetCdm7DeviceMode::setDeviceMode(const std::string& deviceMode)
    {
      m_values.AddMember("DeviceMode", parse_json<std::string>::format(deviceMode, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
