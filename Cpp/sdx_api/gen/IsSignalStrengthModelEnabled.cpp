
#include "IsSignalStrengthModelEnabled.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of IsSignalStrengthModelEnabled
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const IsSignalStrengthModelEnabled::CmdName = "IsSignalStrengthModelEnabled";
    const char* const IsSignalStrengthModelEnabled::Documentation = "Get signal strength model Enable/Disable which affect satellite transmission strength based on their elevation angle";
    const char* const IsSignalStrengthModelEnabled::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(IsSignalStrengthModelEnabled);
    REGISTER_COMMAND_TO_FACTORY_IMPL(IsSignalStrengthModelEnabled);


    IsSignalStrengthModelEnabled::IsSignalStrengthModelEnabled()
      : CommandBase(CmdName, TargetId)
    {

    }

    IsSignalStrengthModelEnabledPtr IsSignalStrengthModelEnabled::create()
    {
      return std::make_shared<IsSignalStrengthModelEnabled>();
    }

    IsSignalStrengthModelEnabledPtr IsSignalStrengthModelEnabled::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<IsSignalStrengthModelEnabled>(ptr);
    }

    bool IsSignalStrengthModelEnabled::isValid() const
    {
      
        return m_values.IsObject()
        ;

    }

    std::string IsSignalStrengthModelEnabled::documentation() const { return Documentation; }

    const std::vector<std::string>& IsSignalStrengthModelEnabled::fieldNames() const 
    { 
      static const std::vector<std::string> names {}; 
      return names; 
    }


    int IsSignalStrengthModelEnabled::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }

  }
}
