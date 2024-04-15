
#include "IsElevationMaskAboveEnabled.h"

#include "command_factory.h"
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
    const char* const IsElevationMaskAboveEnabled::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(IsElevationMaskAboveEnabled);
    REGISTER_COMMAND_TO_FACTORY_IMPL(IsElevationMaskAboveEnabled);


    IsElevationMaskAboveEnabled::IsElevationMaskAboveEnabled()
      : CommandBase(CmdName, TargetId)
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

    const std::vector<std::string>& IsElevationMaskAboveEnabled::fieldNames() const 
    { 
      static const std::vector<std::string> names {}; 
      return names; 
    }


    int IsElevationMaskAboveEnabled::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }

  }
}
