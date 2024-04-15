
#include "EnableSbasMessages.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of EnableSbasMessages
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const EnableSbasMessages::CmdName = "EnableSbasMessages";
    const char* const EnableSbasMessages::Documentation = "Set the enabled SBAS messages. Message 63 is always enabled\n"
      "\n"
      "Name     Type      Description\n"
      "-------- --------- --------------------\n"
      "Messages array int The enabled messages";
    const char* const EnableSbasMessages::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(EnableSbasMessages);
    REGISTER_COMMAND_TO_FACTORY_IMPL(EnableSbasMessages);


    EnableSbasMessages::EnableSbasMessages()
      : CommandBase(CmdName, TargetId)
    {}

    EnableSbasMessages::EnableSbasMessages(const std::vector<int>& messages)
      : CommandBase(CmdName, TargetId)
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

    const std::vector<std::string>& EnableSbasMessages::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Messages"}; 
      return names; 
    }


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
