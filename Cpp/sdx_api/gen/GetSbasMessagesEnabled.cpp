
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
    const char* const GetSbasMessagesEnabled::Documentation = "Get the enabled SBAS messages. Message 63 is always enabled\n"
      "\n"
      "Name            Type            Description\n"
      "--------------- --------------- ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n"
      "ServiceProvider optional string The service provider. When not specified for a Setter command, the change is applied to all service providers. When not specified for a Getter command, the value for WAAS is returned.";
    const char* const GetSbasMessagesEnabled::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(GetSbasMessagesEnabled);
    REGISTER_COMMAND_TO_FACTORY_IMPL(GetSbasMessagesEnabled);


    GetSbasMessagesEnabled::GetSbasMessagesEnabled(const std::optional<std::string>& serviceProvider)
      : CommandBase(CmdName, TargetId)
    {

      setServiceProvider(serviceProvider);
    }

    GetSbasMessagesEnabledPtr GetSbasMessagesEnabled::create(const std::optional<std::string>& serviceProvider)
    {
      return std::make_shared<GetSbasMessagesEnabled>(serviceProvider);
    }

    GetSbasMessagesEnabledPtr GetSbasMessagesEnabled::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetSbasMessagesEnabled>(ptr);
    }

    bool GetSbasMessagesEnabled::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::optional<std::string>>::is_valid(m_values["ServiceProvider"])
        ;

    }

    std::string GetSbasMessagesEnabled::documentation() const { return Documentation; }

    const std::vector<std::string>& GetSbasMessagesEnabled::fieldNames() const 
    { 
      static const std::vector<std::string> names {"ServiceProvider"}; 
      return names; 
    }


    int GetSbasMessagesEnabled::executePermission() const
    {
      return EXECUTE_IF_IDLE | EXECUTE_IF_SIMULATING;
    }


    std::optional<std::string> GetSbasMessagesEnabled::serviceProvider() const
    {
      return parse_json<std::optional<std::string>>::parse(m_values["ServiceProvider"]);
    }

    void GetSbasMessagesEnabled::setServiceProvider(const std::optional<std::string>& serviceProvider)
    {
      m_values.AddMember("ServiceProvider", parse_json<std::optional<std::string>>::format(serviceProvider, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
