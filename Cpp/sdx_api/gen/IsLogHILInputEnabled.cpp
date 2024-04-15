
#include "IsLogHILInputEnabled.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of IsLogHILInputEnabled
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const IsLogHILInputEnabled::CmdName = "IsLogHILInputEnabled";
    const char* const IsLogHILInputEnabled::Documentation = "Tells if data received on the HIL API logging is enabled";
    const char* const IsLogHILInputEnabled::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(IsLogHILInputEnabled);
    REGISTER_COMMAND_TO_FACTORY_IMPL(IsLogHILInputEnabled);


    IsLogHILInputEnabled::IsLogHILInputEnabled()
      : CommandBase(CmdName, TargetId)
    {

    }

    IsLogHILInputEnabledPtr IsLogHILInputEnabled::create()
    {
      return std::make_shared<IsLogHILInputEnabled>();
    }

    IsLogHILInputEnabledPtr IsLogHILInputEnabled::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<IsLogHILInputEnabled>(ptr);
    }

    bool IsLogHILInputEnabled::isValid() const
    {
      
        return m_values.IsObject()
        ;

    }

    std::string IsLogHILInputEnabled::documentation() const { return Documentation; }

    const std::vector<std::string>& IsLogHILInputEnabled::fieldNames() const 
    { 
      static const std::vector<std::string> names {}; 
      return names; 
    }


    int IsLogHILInputEnabled::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }

  }
}
