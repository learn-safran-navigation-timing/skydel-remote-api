
#include "gen/BeginRouteDefinition.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of BeginRouteDefinition
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const BeginRouteDefinition::CmdName = "BeginRouteDefinition";
    const char* const BeginRouteDefinition::Documentation = "Begins a new route definition. Actual route remains unchanged until\nEndRouteDefinition command is sent and successful. After this command, the\nclient must push time and position pairs to form a complete route. Once all the\npositions are sent, the client must send the command EndRouteDefinition.";

    REGISTER_COMMAND_FACTORY(BeginRouteDefinition);


    BeginRouteDefinition::BeginRouteDefinition()
      : CommandBase(CmdName)
    {

    }

    BeginRouteDefinitionPtr BeginRouteDefinition::create()
    {
      return std::make_shared<BeginRouteDefinition>();
    }

    BeginRouteDefinitionPtr BeginRouteDefinition::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<BeginRouteDefinition>(ptr);
    }

    bool BeginRouteDefinition::isValid() const
    {
      
        return m_values.IsObject()
        ;

    }

    std::string BeginRouteDefinition::documentation() const { return Documentation; }


    int BeginRouteDefinition::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }

  }
}
