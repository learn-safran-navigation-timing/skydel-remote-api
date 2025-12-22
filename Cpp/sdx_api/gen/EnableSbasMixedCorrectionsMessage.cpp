
#include "EnableSbasMixedCorrectionsMessage.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of EnableSbasMixedCorrectionsMessage
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const EnableSbasMixedCorrectionsMessage::CmdName = "EnableSbasMixedCorrectionsMessage";
    const char* const EnableSbasMixedCorrectionsMessage::Documentation = "Set whether SBAS message 24 should be used to replace a fast correction message (2-5) when applicable.\n"
      "\n"
      "Name            Type            Description\n"
      "--------------- --------------- --------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n"
      "Enabled         bool            If enabled (true, default), Skydel will attempt to insert message 24 as a replacement for a message 2-5 when applicable. If disabled (false), Skydel will not attempt to include message 24 in the message sequence.\n"
      "ServiceProvider optional string The service provider. When not specified for a Setter command, the change is applied to all service providers. When not specified for a Getter command, the value for WAAS is returned.";
    const char* const EnableSbasMixedCorrectionsMessage::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(EnableSbasMixedCorrectionsMessage);
    REGISTER_COMMAND_TO_FACTORY_IMPL(EnableSbasMixedCorrectionsMessage);


    EnableSbasMixedCorrectionsMessage::EnableSbasMixedCorrectionsMessage()
      : CommandBase(CmdName, TargetId)
    {}

    EnableSbasMixedCorrectionsMessage::EnableSbasMixedCorrectionsMessage(bool enabled, const std::optional<std::string>& serviceProvider)
      : CommandBase(CmdName, TargetId)
    {

      setEnabled(enabled);
      setServiceProvider(serviceProvider);
    }

    EnableSbasMixedCorrectionsMessagePtr EnableSbasMixedCorrectionsMessage::create(bool enabled, const std::optional<std::string>& serviceProvider)
    {
      return std::make_shared<EnableSbasMixedCorrectionsMessage>(enabled, serviceProvider);
    }

    EnableSbasMixedCorrectionsMessagePtr EnableSbasMixedCorrectionsMessage::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<EnableSbasMixedCorrectionsMessage>(ptr);
    }

    bool EnableSbasMixedCorrectionsMessage::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<bool>::is_valid(m_values["Enabled"])
          && parse_json<std::optional<std::string>>::is_valid(m_values["ServiceProvider"])
        ;

    }

    std::string EnableSbasMixedCorrectionsMessage::documentation() const { return Documentation; }

    const std::vector<std::string>& EnableSbasMixedCorrectionsMessage::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Enabled", "ServiceProvider"}; 
      return names; 
    }


    int EnableSbasMixedCorrectionsMessage::executePermission() const
    {
      return EXECUTE_IF_IDLE | EXECUTE_IF_SIMULATING;
    }


    bool EnableSbasMixedCorrectionsMessage::enabled() const
    {
      return parse_json<bool>::parse(m_values["Enabled"]);
    }

    void EnableSbasMixedCorrectionsMessage::setEnabled(bool enabled)
    {
      m_values.AddMember("Enabled", parse_json<bool>::format(enabled, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::optional<std::string> EnableSbasMixedCorrectionsMessage::serviceProvider() const
    {
      return parse_json<std::optional<std::string>>::parse(m_values["ServiceProvider"]);
    }

    void EnableSbasMixedCorrectionsMessage::setServiceProvider(const std::optional<std::string>& serviceProvider)
    {
      m_values.AddMember("ServiceProvider", parse_json<std::optional<std::string>>::format(serviceProvider, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
