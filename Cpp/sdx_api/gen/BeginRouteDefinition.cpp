
#include "BeginRouteDefinition.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of BeginRouteDefinition
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const BeginRouteDefinition::CmdName = "BeginRouteDefinition";
    const char* const BeginRouteDefinition::Documentation = "Begins a new route definition. Actual route remains unchanged until\n"
      "EndRouteDefinition command is sent and successful. After this command, the\n"
      "client must push time and position pairs to form a complete route. Once all the\n"
      "positions are sent, the client must send the command EndRouteDefinition.";
    const char* const BeginRouteDefinition::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(BeginRouteDefinition);
    REGISTER_COMMAND_TO_FACTORY_IMPL(BeginRouteDefinition);


    BeginRouteDefinition::BeginRouteDefinition()
      : CommandBase(CmdName, TargetId)
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

    const std::vector<std::string>& BeginRouteDefinition::fieldNames() const 
    { 
      static const std::vector<std::string> names {}; 
      return names; 
    }


    int BeginRouteDefinition::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }

  }
}
