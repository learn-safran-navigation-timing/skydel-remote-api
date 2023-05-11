
#include "gen/EndRouteDefinition.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of EndRouteDefinition
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const EndRouteDefinition::CmdName = "EndRouteDefinition";
    const char* const EndRouteDefinition::Documentation = "This command completes the route started with BeginRouteDefinition command. If\nthe route is accepted, the current route in the configuration is replaced with\nthis new route. If the route is not accepted, the current route in the config\nremains unchanged.";

    REGISTER_COMMAND_FACTORY(EndRouteDefinition);


    EndRouteDefinition::EndRouteDefinition()
      : CommandBase(CmdName)
    {

    }

    EndRouteDefinitionPtr EndRouteDefinition::create()
    {
      return std::make_shared<EndRouteDefinition>();
    }

    EndRouteDefinitionPtr EndRouteDefinition::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<EndRouteDefinition>(ptr);
    }

    bool EndRouteDefinition::isValid() const
    {
      
        return m_values.IsObject()
        ;

    }

    std::string EndRouteDefinition::documentation() const { return Documentation; }


    int EndRouteDefinition::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }

  }
}
