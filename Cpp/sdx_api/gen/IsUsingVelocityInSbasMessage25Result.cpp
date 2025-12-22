
#include "IsUsingVelocityInSbasMessage25Result.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of IsUsingVelocityInSbasMessage25Result
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const IsUsingVelocityInSbasMessage25Result::CmdName = "IsUsingVelocityInSbasMessage25Result";
    const char* const IsUsingVelocityInSbasMessage25Result::Documentation = "Result of IsUsingVelocityInSbasMessage25.\n"
      "\n"
      "Name            Type            Description\n"
      "--------------- --------------- ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n"
      "UseVelocity     bool            Whether SBAS message 25 should send velocity corrections\n"
      "ServiceProvider optional string The service provider. When not specified for a Setter command, the change is applied to all service providers. When not specified for a Getter command, the value for WAAS is returned.";
    const char* const IsUsingVelocityInSbasMessage25Result::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_IMPL(IsUsingVelocityInSbasMessage25Result);


    IsUsingVelocityInSbasMessage25Result::IsUsingVelocityInSbasMessage25Result()
      : CommandResult(CmdName, TargetId)
    {}

    IsUsingVelocityInSbasMessage25Result::IsUsingVelocityInSbasMessage25Result(bool useVelocity, const std::optional<std::string>& serviceProvider)
      : CommandResult(CmdName, TargetId)
    {

      setUseVelocity(useVelocity);
      setServiceProvider(serviceProvider);
    }

    IsUsingVelocityInSbasMessage25Result::IsUsingVelocityInSbasMessage25Result(CommandBasePtr relatedCommand, bool useVelocity, const std::optional<std::string>& serviceProvider)
      : CommandResult(CmdName, TargetId, relatedCommand)
    {

      setUseVelocity(useVelocity);
      setServiceProvider(serviceProvider);
    }


    IsUsingVelocityInSbasMessage25ResultPtr IsUsingVelocityInSbasMessage25Result::create(bool useVelocity, const std::optional<std::string>& serviceProvider)
    {
      return std::make_shared<IsUsingVelocityInSbasMessage25Result>(useVelocity, serviceProvider);
    }

    IsUsingVelocityInSbasMessage25ResultPtr IsUsingVelocityInSbasMessage25Result::create(CommandBasePtr relatedCommand, bool useVelocity, const std::optional<std::string>& serviceProvider)
    {
      return std::make_shared<IsUsingVelocityInSbasMessage25Result>(relatedCommand, useVelocity, serviceProvider);
    }

    IsUsingVelocityInSbasMessage25ResultPtr IsUsingVelocityInSbasMessage25Result::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<IsUsingVelocityInSbasMessage25Result>(ptr);
    }

    bool IsUsingVelocityInSbasMessage25Result::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<bool>::is_valid(m_values["UseVelocity"])
          && parse_json<std::optional<std::string>>::is_valid(m_values["ServiceProvider"])
        ;

    }

    std::string IsUsingVelocityInSbasMessage25Result::documentation() const { return Documentation; }

    const std::vector<std::string>& IsUsingVelocityInSbasMessage25Result::fieldNames() const 
    { 
      static const std::vector<std::string> names {"UseVelocity", "ServiceProvider"}; 
      return names; 
    }


    bool IsUsingVelocityInSbasMessage25Result::useVelocity() const
    {
      return parse_json<bool>::parse(m_values["UseVelocity"]);
    }

    void IsUsingVelocityInSbasMessage25Result::setUseVelocity(bool useVelocity)
    {
      m_values.AddMember("UseVelocity", parse_json<bool>::format(useVelocity, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::optional<std::string> IsUsingVelocityInSbasMessage25Result::serviceProvider() const
    {
      return parse_json<std::optional<std::string>>::parse(m_values["ServiceProvider"]);
    }

    void IsUsingVelocityInSbasMessage25Result::setServiceProvider(const std::optional<std::string>& serviceProvider)
    {
      m_values.AddMember("ServiceProvider", parse_json<std::optional<std::string>>::format(serviceProvider, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
