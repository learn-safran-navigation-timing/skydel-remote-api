
#include "IsSbasMixedCorrectionsMessageEnabled.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of IsSbasMixedCorrectionsMessageEnabled
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const IsSbasMixedCorrectionsMessageEnabled::CmdName = "IsSbasMixedCorrectionsMessageEnabled";
    const char* const IsSbasMixedCorrectionsMessageEnabled::Documentation = "Get whether SBAS message 24 should be used to replace a fast correction message (2-5) when applicable.\n"
      "\n"
      "Name            Type            Description\n"
      "--------------- --------------- ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n"
      "ServiceProvider optional string The service provider. When not specified for a Setter command, the change is applied to all service providers. When not specified for a Getter command, the value for WAAS is returned.";
    const char* const IsSbasMixedCorrectionsMessageEnabled::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(IsSbasMixedCorrectionsMessageEnabled);
    REGISTER_COMMAND_TO_FACTORY_IMPL(IsSbasMixedCorrectionsMessageEnabled);


    IsSbasMixedCorrectionsMessageEnabled::IsSbasMixedCorrectionsMessageEnabled(const std::optional<std::string>& serviceProvider)
      : CommandBase(CmdName, TargetId)
    {

      setServiceProvider(serviceProvider);
    }

    IsSbasMixedCorrectionsMessageEnabledPtr IsSbasMixedCorrectionsMessageEnabled::create(const std::optional<std::string>& serviceProvider)
    {
      return std::make_shared<IsSbasMixedCorrectionsMessageEnabled>(serviceProvider);
    }

    IsSbasMixedCorrectionsMessageEnabledPtr IsSbasMixedCorrectionsMessageEnabled::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<IsSbasMixedCorrectionsMessageEnabled>(ptr);
    }

    bool IsSbasMixedCorrectionsMessageEnabled::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::optional<std::string>>::is_valid(m_values["ServiceProvider"])
        ;

    }

    std::string IsSbasMixedCorrectionsMessageEnabled::documentation() const { return Documentation; }

    const std::vector<std::string>& IsSbasMixedCorrectionsMessageEnabled::fieldNames() const 
    { 
      static const std::vector<std::string> names {"ServiceProvider"}; 
      return names; 
    }


    int IsSbasMixedCorrectionsMessageEnabled::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::optional<std::string> IsSbasMixedCorrectionsMessageEnabled::serviceProvider() const
    {
      return parse_json<std::optional<std::string>>::parse(m_values["ServiceProvider"]);
    }

    void IsSbasMixedCorrectionsMessageEnabled::setServiceProvider(const std::optional<std::string>& serviceProvider)
    {
      m_values.AddMember("ServiceProvider", parse_json<std::optional<std::string>>::format(serviceProvider, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
