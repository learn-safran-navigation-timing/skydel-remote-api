
#include "IsTransmitMessage2InSbasMessage0.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of IsTransmitMessage2InSbasMessage0
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const IsTransmitMessage2InSbasMessage0::CmdName = "IsTransmitMessage2InSbasMessage0";
    const char* const IsTransmitMessage2InSbasMessage0::Documentation = "Get whether SBAS should transmit message 2 instead of message 0.";
    const char* const IsTransmitMessage2InSbasMessage0::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(IsTransmitMessage2InSbasMessage0);
    REGISTER_COMMAND_TO_FACTORY_IMPL(IsTransmitMessage2InSbasMessage0);


    IsTransmitMessage2InSbasMessage0::IsTransmitMessage2InSbasMessage0()
      : CommandBase(CmdName, TargetId)
    {

    }

    IsTransmitMessage2InSbasMessage0Ptr IsTransmitMessage2InSbasMessage0::create()
    {
      return std::make_shared<IsTransmitMessage2InSbasMessage0>();
    }

    IsTransmitMessage2InSbasMessage0Ptr IsTransmitMessage2InSbasMessage0::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<IsTransmitMessage2InSbasMessage0>(ptr);
    }

    bool IsTransmitMessage2InSbasMessage0::isValid() const
    {
      
        return m_values.IsObject()
        ;

    }

    std::string IsTransmitMessage2InSbasMessage0::documentation() const { return Documentation; }

    const std::vector<std::string>& IsTransmitMessage2InSbasMessage0::fieldNames() const 
    { 
      static const std::vector<std::string> names {}; 
      return names; 
    }


    int IsTransmitMessage2InSbasMessage0::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }

  }
}
