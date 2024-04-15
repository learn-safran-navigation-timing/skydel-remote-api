
#include "ResetDefaultConfiguration.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of ResetDefaultConfiguration
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const ResetDefaultConfiguration::CmdName = "ResetDefaultConfiguration";
    const char* const ResetDefaultConfiguration::Documentation = "Reset the default configuration.";
    const char* const ResetDefaultConfiguration::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(ResetDefaultConfiguration);
    REGISTER_COMMAND_TO_FACTORY_IMPL(ResetDefaultConfiguration);


    ResetDefaultConfiguration::ResetDefaultConfiguration()
      : CommandBase(CmdName, TargetId)
    {

    }

    ResetDefaultConfigurationPtr ResetDefaultConfiguration::create()
    {
      return std::make_shared<ResetDefaultConfiguration>();
    }

    ResetDefaultConfigurationPtr ResetDefaultConfiguration::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<ResetDefaultConfiguration>(ptr);
    }

    bool ResetDefaultConfiguration::isValid() const
    {
      
        return m_values.IsObject()
        ;

    }

    std::string ResetDefaultConfiguration::documentation() const { return Documentation; }

    const std::vector<std::string>& ResetDefaultConfiguration::fieldNames() const 
    { 
      static const std::vector<std::string> names {}; 
      return names; 
    }


    int ResetDefaultConfiguration::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }

  }
}
