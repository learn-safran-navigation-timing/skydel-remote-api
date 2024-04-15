
#include "SetDefaultConfiguration.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetDefaultConfiguration
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetDefaultConfiguration::CmdName = "SetDefaultConfiguration";
    const char* const SetDefaultConfiguration::Documentation = "Set current configuration as default configuration.";
    const char* const SetDefaultConfiguration::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(SetDefaultConfiguration);
    REGISTER_COMMAND_TO_FACTORY_IMPL(SetDefaultConfiguration);


    SetDefaultConfiguration::SetDefaultConfiguration()
      : CommandBase(CmdName, TargetId)
    {

    }

    SetDefaultConfigurationPtr SetDefaultConfiguration::create()
    {
      return std::make_shared<SetDefaultConfiguration>();
    }

    SetDefaultConfigurationPtr SetDefaultConfiguration::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetDefaultConfiguration>(ptr);
    }

    bool SetDefaultConfiguration::isValid() const
    {
      
        return m_values.IsObject()
        ;

    }

    std::string SetDefaultConfiguration::documentation() const { return Documentation; }

    const std::vector<std::string>& SetDefaultConfiguration::fieldNames() const 
    { 
      static const std::vector<std::string> names {}; 
      return names; 
    }


    int SetDefaultConfiguration::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }

  }
}
