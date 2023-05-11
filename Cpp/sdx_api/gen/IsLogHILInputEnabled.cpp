
#include "gen/IsLogHILInputEnabled.h"

#include "command_factory.h"
#include "command_result_factory.h"
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

    REGISTER_COMMAND_FACTORY(IsLogHILInputEnabled);


    IsLogHILInputEnabled::IsLogHILInputEnabled()
      : CommandBase(CmdName)
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


    int IsLogHILInputEnabled::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }

  }
}
