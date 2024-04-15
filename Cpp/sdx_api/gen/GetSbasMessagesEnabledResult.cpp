
#include "GetSbasMessagesEnabledResult.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetSbasMessagesEnabledResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetSbasMessagesEnabledResult::CmdName = "GetSbasMessagesEnabledResult";
    const char* const GetSbasMessagesEnabledResult::Documentation = "Result of GetSbasMessagesEnabled.\n"
      "\n"
      "Name     Type      Description\n"
      "-------- --------- --------------------\n"
      "Messages array int The enabled messages";
    const char* const GetSbasMessagesEnabledResult::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_IMPL(GetSbasMessagesEnabledResult);


    GetSbasMessagesEnabledResult::GetSbasMessagesEnabledResult()
      : CommandResult(CmdName, TargetId)
    {}

    GetSbasMessagesEnabledResult::GetSbasMessagesEnabledResult(const std::vector<int>& messages)
      : CommandResult(CmdName, TargetId)
    {

      setMessages(messages);
    }

    GetSbasMessagesEnabledResult::GetSbasMessagesEnabledResult(CommandBasePtr relatedCommand, const std::vector<int>& messages)
      : CommandResult(CmdName, TargetId, relatedCommand)
    {

      setMessages(messages);
    }


    GetSbasMessagesEnabledResultPtr GetSbasMessagesEnabledResult::create(const std::vector<int>& messages)
    {
      return std::make_shared<GetSbasMessagesEnabledResult>(messages);
    }

    GetSbasMessagesEnabledResultPtr GetSbasMessagesEnabledResult::create(CommandBasePtr relatedCommand, const std::vector<int>& messages)
    {
      return std::make_shared<GetSbasMessagesEnabledResult>(relatedCommand, messages);
    }

    GetSbasMessagesEnabledResultPtr GetSbasMessagesEnabledResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetSbasMessagesEnabledResult>(ptr);
    }

    bool GetSbasMessagesEnabledResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::vector<int>>::is_valid(m_values["Messages"])
        ;

    }

    std::string GetSbasMessagesEnabledResult::documentation() const { return Documentation; }

    const std::vector<std::string>& GetSbasMessagesEnabledResult::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Messages"}; 
      return names; 
    }


    std::vector<int> GetSbasMessagesEnabledResult::messages() const
    {
      return parse_json<std::vector<int>>::parse(m_values["Messages"]);
    }

    void GetSbasMessagesEnabledResult::setMessages(const std::vector<int>& messages)
    {
      m_values.AddMember("Messages", parse_json<std::vector<int>>::format(messages, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
