
#include "IsElevationMaskBelowEnabled.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of IsElevationMaskBelowEnabled
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const IsElevationMaskBelowEnabled::CmdName = "IsElevationMaskBelowEnabled";
    const char* const IsElevationMaskBelowEnabled::Documentation = "Get GNSS satellite mask based on elevation enabled or disabled (See SetElevationMaskBelow).";
    const char* const IsElevationMaskBelowEnabled::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(IsElevationMaskBelowEnabled);
    REGISTER_COMMAND_TO_FACTORY_IMPL(IsElevationMaskBelowEnabled);


    IsElevationMaskBelowEnabled::IsElevationMaskBelowEnabled()
      : CommandBase(CmdName, TargetId)
    {

    }

    IsElevationMaskBelowEnabledPtr IsElevationMaskBelowEnabled::create()
    {
      return std::make_shared<IsElevationMaskBelowEnabled>();
    }

    IsElevationMaskBelowEnabledPtr IsElevationMaskBelowEnabled::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<IsElevationMaskBelowEnabled>(ptr);
    }

    bool IsElevationMaskBelowEnabled::isValid() const
    {
      
        return m_values.IsObject()
        ;

    }

    std::string IsElevationMaskBelowEnabled::documentation() const { return Documentation; }

    const std::vector<std::string>& IsElevationMaskBelowEnabled::fieldNames() const 
    { 
      static const std::vector<std::string> names {}; 
      return names; 
    }


    int IsElevationMaskBelowEnabled::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }

  }
}
