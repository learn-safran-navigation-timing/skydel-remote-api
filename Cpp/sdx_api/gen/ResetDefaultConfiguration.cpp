
#include "gen/ResetDefaultConfiguration.h"

#include "command_factory.h"
#include "command_result_factory.h"
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

    REGISTER_COMMAND_FACTORY(ResetDefaultConfiguration);


    ResetDefaultConfiguration::ResetDefaultConfiguration()
      : CommandBase(CmdName)
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


    int ResetDefaultConfiguration::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }

  }
}
