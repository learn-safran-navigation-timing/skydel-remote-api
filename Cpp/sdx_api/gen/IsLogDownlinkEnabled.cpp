
#include "IsLogDownlinkEnabled.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of IsLogDownlinkEnabled
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const IsLogDownlinkEnabled::CmdName = "IsLogDownlinkEnabled";
    const char* const IsLogDownlinkEnabled::Documentation = "Tells if downlink data Logging is enabled";
    const char* const IsLogDownlinkEnabled::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(IsLogDownlinkEnabled);
    REGISTER_COMMAND_TO_FACTORY_IMPL(IsLogDownlinkEnabled);


    IsLogDownlinkEnabled::IsLogDownlinkEnabled()
      : CommandBase(CmdName, TargetId)
    {

    }

    IsLogDownlinkEnabledPtr IsLogDownlinkEnabled::create()
    {
      return std::make_shared<IsLogDownlinkEnabled>();
    }

    IsLogDownlinkEnabledPtr IsLogDownlinkEnabled::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<IsLogDownlinkEnabled>(ptr);
    }

    bool IsLogDownlinkEnabled::isValid() const
    {
      
        return m_values.IsObject()
        ;

    }

    std::string IsLogDownlinkEnabled::documentation() const { return Documentation; }

    const std::vector<std::string>& IsLogDownlinkEnabled::fieldNames() const 
    { 
      static const std::vector<std::string> names {}; 
      return names; 
    }


    int IsLogDownlinkEnabled::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }

  }
}
