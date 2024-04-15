
#include "IsLogRinexEnabled.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of IsLogRinexEnabled
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const IsLogRinexEnabled::CmdName = "IsLogRinexEnabled";
    const char* const IsLogRinexEnabled::Documentation = "Tells if ephemeris data Logging is enabled";
    const char* const IsLogRinexEnabled::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(IsLogRinexEnabled);
    REGISTER_COMMAND_TO_FACTORY_IMPL(IsLogRinexEnabled);


    IsLogRinexEnabled::IsLogRinexEnabled()
      : CommandBase(CmdName, TargetId)
    {

    }

    IsLogRinexEnabledPtr IsLogRinexEnabled::create()
    {
      return std::make_shared<IsLogRinexEnabled>();
    }

    IsLogRinexEnabledPtr IsLogRinexEnabled::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<IsLogRinexEnabled>(ptr);
    }

    bool IsLogRinexEnabled::isValid() const
    {
      
        return m_values.IsObject()
        ;

    }

    std::string IsLogRinexEnabled::documentation() const { return Documentation; }

    const std::vector<std::string>& IsLogRinexEnabled::fieldNames() const 
    { 
      static const std::vector<std::string> names {}; 
      return names; 
    }


    int IsLogRinexEnabled::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }

  }
}
