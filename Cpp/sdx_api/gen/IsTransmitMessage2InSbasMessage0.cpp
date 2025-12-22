
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
    const char* const IsTransmitMessage2InSbasMessage0::Documentation = "Get whether SBAS should transmit message 2 instead of message 0.\n"
      "\n"
      "Name            Type            Description\n"
      "--------------- --------------- ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n"
      "ServiceProvider optional string The service provider. When not specified for a Setter command, the change is applied to all service providers. When not specified for a Getter command, the value for WAAS is returned.";
    const char* const IsTransmitMessage2InSbasMessage0::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(IsTransmitMessage2InSbasMessage0);
    REGISTER_COMMAND_TO_FACTORY_IMPL(IsTransmitMessage2InSbasMessage0);


    IsTransmitMessage2InSbasMessage0::IsTransmitMessage2InSbasMessage0(const std::optional<std::string>& serviceProvider)
      : CommandBase(CmdName, TargetId)
    {

      setServiceProvider(serviceProvider);
    }

    IsTransmitMessage2InSbasMessage0Ptr IsTransmitMessage2InSbasMessage0::create(const std::optional<std::string>& serviceProvider)
    {
      return std::make_shared<IsTransmitMessage2InSbasMessage0>(serviceProvider);
    }

    IsTransmitMessage2InSbasMessage0Ptr IsTransmitMessage2InSbasMessage0::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<IsTransmitMessage2InSbasMessage0>(ptr);
    }

    bool IsTransmitMessage2InSbasMessage0::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::optional<std::string>>::is_valid(m_values["ServiceProvider"])
        ;

    }

    std::string IsTransmitMessage2InSbasMessage0::documentation() const { return Documentation; }

    const std::vector<std::string>& IsTransmitMessage2InSbasMessage0::fieldNames() const 
    { 
      static const std::vector<std::string> names {"ServiceProvider"}; 
      return names; 
    }


    int IsTransmitMessage2InSbasMessage0::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::optional<std::string> IsTransmitMessage2InSbasMessage0::serviceProvider() const
    {
      return parse_json<std::optional<std::string>>::parse(m_values["ServiceProvider"]);
    }

    void IsTransmitMessage2InSbasMessage0::setServiceProvider(const std::optional<std::string>& serviceProvider)
    {
      m_values.AddMember("ServiceProvider", parse_json<std::optional<std::string>>::format(serviceProvider, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
