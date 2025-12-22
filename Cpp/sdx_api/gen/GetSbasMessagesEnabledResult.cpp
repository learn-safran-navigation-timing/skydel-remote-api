
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
      "Name            Type            Description\n"
      "--------------- --------------- ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n"
      "Messages        array int       The enabled messages\n"
      "ServiceProvider optional string The service provider. When not specified for a Setter command, the change is applied to all service providers. When not specified for a Getter command, the value for WAAS is returned.";
    const char* const GetSbasMessagesEnabledResult::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_IMPL(GetSbasMessagesEnabledResult);


    GetSbasMessagesEnabledResult::GetSbasMessagesEnabledResult()
      : CommandResult(CmdName, TargetId)
    {}

    GetSbasMessagesEnabledResult::GetSbasMessagesEnabledResult(const std::vector<int>& messages, const std::optional<std::string>& serviceProvider)
      : CommandResult(CmdName, TargetId)
    {

      setMessages(messages);
      setServiceProvider(serviceProvider);
    }

    GetSbasMessagesEnabledResult::GetSbasMessagesEnabledResult(CommandBasePtr relatedCommand, const std::vector<int>& messages, const std::optional<std::string>& serviceProvider)
      : CommandResult(CmdName, TargetId, relatedCommand)
    {

      setMessages(messages);
      setServiceProvider(serviceProvider);
    }


    GetSbasMessagesEnabledResultPtr GetSbasMessagesEnabledResult::create(const std::vector<int>& messages, const std::optional<std::string>& serviceProvider)
    {
      return std::make_shared<GetSbasMessagesEnabledResult>(messages, serviceProvider);
    }

    GetSbasMessagesEnabledResultPtr GetSbasMessagesEnabledResult::create(CommandBasePtr relatedCommand, const std::vector<int>& messages, const std::optional<std::string>& serviceProvider)
    {
      return std::make_shared<GetSbasMessagesEnabledResult>(relatedCommand, messages, serviceProvider);
    }

    GetSbasMessagesEnabledResultPtr GetSbasMessagesEnabledResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetSbasMessagesEnabledResult>(ptr);
    }

    bool GetSbasMessagesEnabledResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::vector<int>>::is_valid(m_values["Messages"])
          && parse_json<std::optional<std::string>>::is_valid(m_values["ServiceProvider"])
        ;

    }

    std::string GetSbasMessagesEnabledResult::documentation() const { return Documentation; }

    const std::vector<std::string>& GetSbasMessagesEnabledResult::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Messages", "ServiceProvider"}; 
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



    std::optional<std::string> GetSbasMessagesEnabledResult::serviceProvider() const
    {
      return parse_json<std::optional<std::string>>::parse(m_values["ServiceProvider"]);
    }

    void GetSbasMessagesEnabledResult::setServiceProvider(const std::optional<std::string>& serviceProvider)
    {
      m_values.AddMember("ServiceProvider", parse_json<std::optional<std::string>>::format(serviceProvider, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
