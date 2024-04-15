
#include "IsIonoOffsetEnabled.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of IsIonoOffsetEnabled
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const IsIonoOffsetEnabled::CmdName = "IsIonoOffsetEnabled";
    const char* const IsIonoOffsetEnabled::Documentation = "Get whether the ionospheric offsets grid should be applied to the ionosphere";
    const char* const IsIonoOffsetEnabled::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(IsIonoOffsetEnabled);
    REGISTER_COMMAND_TO_FACTORY_IMPL(IsIonoOffsetEnabled);


    IsIonoOffsetEnabled::IsIonoOffsetEnabled()
      : CommandBase(CmdName, TargetId)
    {

    }

    IsIonoOffsetEnabledPtr IsIonoOffsetEnabled::create()
    {
      return std::make_shared<IsIonoOffsetEnabled>();
    }

    IsIonoOffsetEnabledPtr IsIonoOffsetEnabled::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<IsIonoOffsetEnabled>(ptr);
    }

    bool IsIonoOffsetEnabled::isValid() const
    {
      
        return m_values.IsObject()
        ;

    }

    std::string IsIonoOffsetEnabled::documentation() const { return Documentation; }

    const std::vector<std::string>& IsIonoOffsetEnabled::fieldNames() const 
    { 
      static const std::vector<std::string> names {}; 
      return names; 
    }


    int IsIonoOffsetEnabled::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }

  }
}
