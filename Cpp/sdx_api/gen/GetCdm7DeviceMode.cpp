
#include "GetCdm7DeviceMode.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetCdm7DeviceMode
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetCdm7DeviceMode::CmdName = "GetCdm7DeviceMode";
    const char* const GetCdm7DeviceMode::Documentation = "Get the device mode of the CDM-7 clock distribution and timing reference module.\n"
      "\n"
      "Note: All connected CDM-7 modules operate in the same device mode.";
    const char* const GetCdm7DeviceMode::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(GetCdm7DeviceMode);
    REGISTER_COMMAND_TO_FACTORY_IMPL(GetCdm7DeviceMode);


    GetCdm7DeviceMode::GetCdm7DeviceMode()
      : CommandBase(CmdName, TargetId)
    {

    }

    GetCdm7DeviceModePtr GetCdm7DeviceMode::create()
    {
      return std::make_shared<GetCdm7DeviceMode>();
    }

    GetCdm7DeviceModePtr GetCdm7DeviceMode::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetCdm7DeviceMode>(ptr);
    }

    bool GetCdm7DeviceMode::isValid() const
    {
      
        return m_values.IsObject()
        ;

    }

    std::string GetCdm7DeviceMode::documentation() const { return Documentation; }

    const std::vector<std::string>& GetCdm7DeviceMode::fieldNames() const 
    { 
      static const std::vector<std::string> names {}; 
      return names; 
    }


    int GetCdm7DeviceMode::executePermission() const
    {
      return EXECUTE_IF_NO_CONFIG | EXECUTE_IF_IDLE;
    }

  }
}
