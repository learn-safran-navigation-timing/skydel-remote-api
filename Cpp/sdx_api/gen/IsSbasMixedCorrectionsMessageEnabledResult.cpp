
#include "IsSbasMixedCorrectionsMessageEnabledResult.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of IsSbasMixedCorrectionsMessageEnabledResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const IsSbasMixedCorrectionsMessageEnabledResult::CmdName = "IsSbasMixedCorrectionsMessageEnabledResult";
    const char* const IsSbasMixedCorrectionsMessageEnabledResult::Documentation = "Result of IsSbasMixedCorrectionsMessageEnabled.\n"
      "\n"
      "Name            Type            Description\n"
      "--------------- --------------- --------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n"
      "Enabled         bool            If enabled (true, default), Skydel will attempt to insert message 24 as a replacement for a message 2-5 when applicable. If disabled (false), Skydel will not attempt to include message 24 in the message sequence.\n"
      "ServiceProvider optional string The service provider. When not specified for a Setter command, the change is applied to all service providers. When not specified for a Getter command, the value for WAAS is returned.";
    const char* const IsSbasMixedCorrectionsMessageEnabledResult::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_IMPL(IsSbasMixedCorrectionsMessageEnabledResult);


    IsSbasMixedCorrectionsMessageEnabledResult::IsSbasMixedCorrectionsMessageEnabledResult()
      : CommandResult(CmdName, TargetId)
    {}

    IsSbasMixedCorrectionsMessageEnabledResult::IsSbasMixedCorrectionsMessageEnabledResult(bool enabled, const std::optional<std::string>& serviceProvider)
      : CommandResult(CmdName, TargetId)
    {

      setEnabled(enabled);
      setServiceProvider(serviceProvider);
    }

    IsSbasMixedCorrectionsMessageEnabledResult::IsSbasMixedCorrectionsMessageEnabledResult(CommandBasePtr relatedCommand, bool enabled, const std::optional<std::string>& serviceProvider)
      : CommandResult(CmdName, TargetId, relatedCommand)
    {

      setEnabled(enabled);
      setServiceProvider(serviceProvider);
    }


    IsSbasMixedCorrectionsMessageEnabledResultPtr IsSbasMixedCorrectionsMessageEnabledResult::create(bool enabled, const std::optional<std::string>& serviceProvider)
    {
      return std::make_shared<IsSbasMixedCorrectionsMessageEnabledResult>(enabled, serviceProvider);
    }

    IsSbasMixedCorrectionsMessageEnabledResultPtr IsSbasMixedCorrectionsMessageEnabledResult::create(CommandBasePtr relatedCommand, bool enabled, const std::optional<std::string>& serviceProvider)
    {
      return std::make_shared<IsSbasMixedCorrectionsMessageEnabledResult>(relatedCommand, enabled, serviceProvider);
    }

    IsSbasMixedCorrectionsMessageEnabledResultPtr IsSbasMixedCorrectionsMessageEnabledResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<IsSbasMixedCorrectionsMessageEnabledResult>(ptr);
    }

    bool IsSbasMixedCorrectionsMessageEnabledResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<bool>::is_valid(m_values["Enabled"])
          && parse_json<std::optional<std::string>>::is_valid(m_values["ServiceProvider"])
        ;

    }

    std::string IsSbasMixedCorrectionsMessageEnabledResult::documentation() const { return Documentation; }

    const std::vector<std::string>& IsSbasMixedCorrectionsMessageEnabledResult::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Enabled", "ServiceProvider"}; 
      return names; 
    }


    bool IsSbasMixedCorrectionsMessageEnabledResult::enabled() const
    {
      return parse_json<bool>::parse(m_values["Enabled"]);
    }

    void IsSbasMixedCorrectionsMessageEnabledResult::setEnabled(bool enabled)
    {
      m_values.AddMember("Enabled", parse_json<bool>::format(enabled, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::optional<std::string> IsSbasMixedCorrectionsMessageEnabledResult::serviceProvider() const
    {
      return parse_json<std::optional<std::string>>::parse(m_values["ServiceProvider"]);
    }

    void IsSbasMixedCorrectionsMessageEnabledResult::setServiceProvider(const std::optional<std::string>& serviceProvider)
    {
      m_values.AddMember("ServiceProvider", parse_json<std::optional<std::string>>::format(serviceProvider, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
