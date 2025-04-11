
#include "IsEarthMaskEnabled.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of IsEarthMaskEnabled
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const IsEarthMaskEnabled::CmdName = "IsEarthMaskEnabled";
    const char* const IsEarthMaskEnabled::Documentation = "Indicates if the Earth mask is enabled.";
    const char* const IsEarthMaskEnabled::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(IsEarthMaskEnabled);
    REGISTER_COMMAND_TO_FACTORY_IMPL(IsEarthMaskEnabled);


    IsEarthMaskEnabled::IsEarthMaskEnabled()
      : CommandBase(CmdName, TargetId)
    {

    }

    IsEarthMaskEnabledPtr IsEarthMaskEnabled::create()
    {
      return std::make_shared<IsEarthMaskEnabled>();
    }

    IsEarthMaskEnabledPtr IsEarthMaskEnabled::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<IsEarthMaskEnabled>(ptr);
    }

    bool IsEarthMaskEnabled::isValid() const
    {
      
        return m_values.IsObject()
        ;

    }

    std::string IsEarthMaskEnabled::documentation() const { return Documentation; }

    const std::vector<std::string>& IsEarthMaskEnabled::fieldNames() const 
    { 
      static const std::vector<std::string> names {}; 
      return names; 
    }


    int IsEarthMaskEnabled::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }

  }
}
