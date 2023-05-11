
#include "gen/GetSbasMessagesEnabled.h"

#include "command_factory.h"
#include "command_result_factory.h"
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

    REGISTER_COMMAND_FACTORY(GetSbasMessagesEnabled);


    GetSbasMessagesEnabled::GetSbasMessagesEnabled()
      : CommandBase(CmdName)
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


    int GetSbasMessagesEnabled::executePermission() const
    {
      return EXECUTE_IF_IDLE | EXECUTE_IF_SIMULATING;
    }

  }
}
