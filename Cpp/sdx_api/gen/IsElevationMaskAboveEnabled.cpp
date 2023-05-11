
#include "gen/IsElevationMaskAboveEnabled.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of IsElevationMaskAboveEnabled
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const IsElevationMaskAboveEnabled::CmdName = "IsElevationMaskAboveEnabled";
    const char* const IsElevationMaskAboveEnabled::Documentation = "Get GNSS satellite mask based on elevation enabled or disabled (See SetElevationMaskAbove).";

    REGISTER_COMMAND_FACTORY(IsElevationMaskAboveEnabled);


    IsElevationMaskAboveEnabled::IsElevationMaskAboveEnabled()
      : CommandBase(CmdName)
    {

    }

    IsElevationMaskAboveEnabledPtr IsElevationMaskAboveEnabled::create()
    {
      return std::make_shared<IsElevationMaskAboveEnabled>();
    }

    IsElevationMaskAboveEnabledPtr IsElevationMaskAboveEnabled::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<IsElevationMaskAboveEnabled>(ptr);
    }

    bool IsElevationMaskAboveEnabled::isValid() const
    {
      
        return m_values.IsObject()
        ;

    }

    std::string IsElevationMaskAboveEnabled::documentation() const { return Documentation; }


    int IsElevationMaskAboveEnabled::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }

  }
}
