
#include "GetSbasMessagesEnabled.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetSbasMessagesEnabled
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetSbasMessagesEnabled::CmdName = "GetSbasMessagesEnabled";
    const char* const GetSbasMessagesEnabled::Documentation = "Get the enabled SBAS messages. Message 63 is always enabled";
    const char* const GetSbasMessagesEnabled::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(GetSbasMessagesEnabled);
    REGISTER_COMMAND_TO_FACTORY_IMPL(GetSbasMessagesEnabled);


    GetSbasMessagesEnabled::GetSbasMessagesEnabled()
      : CommandBase(CmdName, TargetId)
    {

    }

    GetSbasMessagesEnabledPtr GetSbasMessagesEnabled::create()
    {
      return std::make_shared<GetSbasMessagesEnabled>();
    }

    GetSbasMessagesEnabledPtr GetSbasMessagesEnabled::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetSbasMessagesEnabled>(ptr);
    }

    bool GetSbasMessagesEnabled::isValid() const
    {
      
        return m_values.IsObject()
        ;

    }

    std::string GetSbasMessagesEnabled::documentation() const { return Documentation; }

    const std::vector<std::string>& GetSbasMessagesEnabled::fieldNames() const 
    { 
      static const std::vector<std::string> names {}; 
      return names; 
    }


    int GetSbasMessagesEnabled::executePermission() const
    {
      return EXECUTE_IF_IDLE | EXECUTE_IF_SIMULATING;
    }

  }
}
