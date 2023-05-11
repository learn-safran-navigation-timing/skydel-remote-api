
#include "gen/IsIonoOffsetEnabled.h"

#include "command_factory.h"
#include "command_result_factory.h"
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

    REGISTER_COMMAND_FACTORY(IsIonoOffsetEnabled);


    IsIonoOffsetEnabled::IsIonoOffsetEnabled()
      : CommandBase(CmdName)
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


    int IsIonoOffsetEnabled::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }

  }
}
