
#include "IsTransmitMessage2InSbasMessage0Result.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of IsTransmitMessage2InSbasMessage0Result
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const IsTransmitMessage2InSbasMessage0Result::CmdName = "IsTransmitMessage2InSbasMessage0Result";
    const char* const IsTransmitMessage2InSbasMessage0Result::Documentation = "Result of IsTransmitMessage2InSbasMessage0.\n"
      "\n"
      "Name             Type            Description\n"
      "---------------- --------------- ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n"
      "TransmitMessage2 bool            Whether SBAS should transmit message type 2 instead of 0.\n"
      "ServiceProvider  optional string The service provider. When not specified for a Setter command, the change is applied to all service providers. When not specified for a Getter command, the value for WAAS is returned.";
    const char* const IsTransmitMessage2InSbasMessage0Result::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_IMPL(IsTransmitMessage2InSbasMessage0Result);


    IsTransmitMessage2InSbasMessage0Result::IsTransmitMessage2InSbasMessage0Result()
      : CommandResult(CmdName, TargetId)
    {}

    IsTransmitMessage2InSbasMessage0Result::IsTransmitMessage2InSbasMessage0Result(bool transmitMessage2, const std::optional<std::string>& serviceProvider)
      : CommandResult(CmdName, TargetId)
    {

      setTransmitMessage2(transmitMessage2);
      setServiceProvider(serviceProvider);
    }

    IsTransmitMessage2InSbasMessage0Result::IsTransmitMessage2InSbasMessage0Result(CommandBasePtr relatedCommand, bool transmitMessage2, const std::optional<std::string>& serviceProvider)
      : CommandResult(CmdName, TargetId, relatedCommand)
    {

      setTransmitMessage2(transmitMessage2);
      setServiceProvider(serviceProvider);
    }


    IsTransmitMessage2InSbasMessage0ResultPtr IsTransmitMessage2InSbasMessage0Result::create(bool transmitMessage2, const std::optional<std::string>& serviceProvider)
    {
      return std::make_shared<IsTransmitMessage2InSbasMessage0Result>(transmitMessage2, serviceProvider);
    }

    IsTransmitMessage2InSbasMessage0ResultPtr IsTransmitMessage2InSbasMessage0Result::create(CommandBasePtr relatedCommand, bool transmitMessage2, const std::optional<std::string>& serviceProvider)
    {
      return std::make_shared<IsTransmitMessage2InSbasMessage0Result>(relatedCommand, transmitMessage2, serviceProvider);
    }

    IsTransmitMessage2InSbasMessage0ResultPtr IsTransmitMessage2InSbasMessage0Result::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<IsTransmitMessage2InSbasMessage0Result>(ptr);
    }

    bool IsTransmitMessage2InSbasMessage0Result::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<bool>::is_valid(m_values["TransmitMessage2"])
          && parse_json<std::optional<std::string>>::is_valid(m_values["ServiceProvider"])
        ;

    }

    std::string IsTransmitMessage2InSbasMessage0Result::documentation() const { return Documentation; }

    const std::vector<std::string>& IsTransmitMessage2InSbasMessage0Result::fieldNames() const 
    { 
      static const std::vector<std::string> names {"TransmitMessage2", "ServiceProvider"}; 
      return names; 
    }


    bool IsTransmitMessage2InSbasMessage0Result::transmitMessage2() const
    {
      return parse_json<bool>::parse(m_values["TransmitMessage2"]);
    }

    void IsTransmitMessage2InSbasMessage0Result::setTransmitMessage2(bool transmitMessage2)
    {
      m_values.AddMember("TransmitMessage2", parse_json<bool>::format(transmitMessage2, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::optional<std::string> IsTransmitMessage2InSbasMessage0Result::serviceProvider() const
    {
      return parse_json<std::optional<std::string>>::parse(m_values["ServiceProvider"]);
    }

    void IsTransmitMessage2InSbasMessage0Result::setServiceProvider(const std::optional<std::string>& serviceProvider)
    {
      m_values.AddMember("ServiceProvider", parse_json<std::optional<std::string>>::format(serviceProvider, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
