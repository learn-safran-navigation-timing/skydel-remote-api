
#include "IsUsingVelocityInSbasMessage25.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of IsUsingVelocityInSbasMessage25
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const IsUsingVelocityInSbasMessage25::CmdName = "IsUsingVelocityInSbasMessage25";
    const char* const IsUsingVelocityInSbasMessage25::Documentation = "Get whether SBAS message 25 should send velocity corrections\n"
      "\n"
      "Name            Type            Description\n"
      "--------------- --------------- ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n"
      "ServiceProvider optional string The service provider. When not specified for a Setter command, the change is applied to all service providers. When not specified for a Getter command, the value for WAAS is returned.";
    const char* const IsUsingVelocityInSbasMessage25::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(IsUsingVelocityInSbasMessage25);
    REGISTER_COMMAND_TO_FACTORY_IMPL(IsUsingVelocityInSbasMessage25);


    IsUsingVelocityInSbasMessage25::IsUsingVelocityInSbasMessage25(const std::optional<std::string>& serviceProvider)
      : CommandBase(CmdName, TargetId)
    {

      setServiceProvider(serviceProvider);
    }

    IsUsingVelocityInSbasMessage25Ptr IsUsingVelocityInSbasMessage25::create(const std::optional<std::string>& serviceProvider)
    {
      return std::make_shared<IsUsingVelocityInSbasMessage25>(serviceProvider);
    }

    IsUsingVelocityInSbasMessage25Ptr IsUsingVelocityInSbasMessage25::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<IsUsingVelocityInSbasMessage25>(ptr);
    }

    bool IsUsingVelocityInSbasMessage25::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::optional<std::string>>::is_valid(m_values["ServiceProvider"])
        ;

    }

    std::string IsUsingVelocityInSbasMessage25::documentation() const { return Documentation; }

    const std::vector<std::string>& IsUsingVelocityInSbasMessage25::fieldNames() const 
    { 
      static const std::vector<std::string> names {"ServiceProvider"}; 
      return names; 
    }


    int IsUsingVelocityInSbasMessage25::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::optional<std::string> IsUsingVelocityInSbasMessage25::serviceProvider() const
    {
      return parse_json<std::optional<std::string>>::parse(m_values["ServiceProvider"]);
    }

    void IsUsingVelocityInSbasMessage25::setServiceProvider(const std::optional<std::string>& serviceProvider)
    {
      m_values.AddMember("ServiceProvider", parse_json<std::optional<std::string>>::format(serviceProvider, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
