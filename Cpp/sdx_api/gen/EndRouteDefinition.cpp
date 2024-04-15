
#include "EndRouteDefinition.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of EndRouteDefinition
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const EndRouteDefinition::CmdName = "EndRouteDefinition";
    const char* const EndRouteDefinition::Documentation = "This command completes the route started with BeginRouteDefinition command. If\n"
      "the route is accepted, the current route in the configuration is replaced with\n"
      "this new route. If the route is not accepted, the current route in the config\n"
      "remains unchanged.";
    const char* const EndRouteDefinition::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(EndRouteDefinition);
    REGISTER_COMMAND_TO_FACTORY_IMPL(EndRouteDefinition);


    EndRouteDefinition::EndRouteDefinition()
      : CommandBase(CmdName, TargetId)
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

    const std::vector<std::string>& EndRouteDefinition::fieldNames() const 
    { 
      static const std::vector<std::string> names {}; 
      return names; 
    }


    int EndRouteDefinition::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }

  }
}
