
#include "gen/SetDefaultConfiguration.h"

#include "command_factory.h"
#include "command_result_factory.h"
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

    REGISTER_COMMAND_FACTORY(SetDefaultConfiguration);


    SetDefaultConfiguration::SetDefaultConfiguration()
      : CommandBase(CmdName)
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


    int SetDefaultConfiguration::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }

  }
}
