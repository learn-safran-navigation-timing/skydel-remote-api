
#include "IsLogRawEnabled.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of IsLogRawEnabled
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const IsLogRawEnabled::CmdName = "IsLogRawEnabled";
    const char* const IsLogRawEnabled::Documentation = "Tells if raw data logging is enabled.";
    const char* const IsLogRawEnabled::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(IsLogRawEnabled);
    REGISTER_COMMAND_TO_FACTORY_IMPL(IsLogRawEnabled);


    IsLogRawEnabled::IsLogRawEnabled()
      : CommandBase(CmdName, TargetId)
    {

    }

    IsLogRawEnabledPtr IsLogRawEnabled::create()
    {
      return std::make_shared<IsLogRawEnabled>();
    }

    IsLogRawEnabledPtr IsLogRawEnabled::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<IsLogRawEnabled>(ptr);
    }

    bool IsLogRawEnabled::isValid() const
    {
      
        return m_values.IsObject()
        ;

    }

    std::string IsLogRawEnabled::documentation() const { return Documentation; }

    const std::vector<std::string>& IsLogRawEnabled::fieldNames() const 
    { 
      static const std::vector<std::string> names {}; 
      return names; 
    }


    int IsLogRawEnabled::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }

  }
}
