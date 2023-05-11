
#include "gen/EnableSbasMessages.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of EnableSbasMessages
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const EnableSbasMessages::CmdName = "EnableSbasMessages";
    const char* const EnableSbasMessages::Documentation = "Set the enabled SBAS messages. Message 63 is always enabled";

    REGISTER_COMMAND_FACTORY(EnableSbasMessages);


    EnableSbasMessages::EnableSbasMessages()
      : CommandBase(CmdName)
    {}

    EnableSbasMessages::EnableSbasMessages(const std::vector<int>& messages)
      : CommandBase(CmdName)
    {

      setMessages(messages);
    }

    EnableSbasMessagesPtr EnableSbasMessages::create(const std::vector<int>& messages)
    {
      return std::make_shared<EnableSbasMessages>(messages);
    }

    EnableSbasMessagesPtr EnableSbasMessages::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<EnableSbasMessages>(ptr);
    }

    bool EnableSbasMessages::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::vector<int>>::is_valid(m_values["Messages"])
        ;

    }

    std::string EnableSbasMessages::documentation() const { return Documentation; }


    int EnableSbasMessages::executePermission() const
    {
      return EXECUTE_IF_IDLE | EXECUTE_IF_SIMULATING;
    }


    std::vector<int> EnableSbasMessages::messages() const
    {
      return parse_json<std::vector<int>>::parse(m_values["Messages"]);
    }

    void EnableSbasMessages::setMessages(const std::vector<int>& messages)
    {
      m_values.AddMember("Messages", parse_json<std::vector<int>>::format(messages, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
