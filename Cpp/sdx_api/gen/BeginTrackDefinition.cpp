
#include "BeginTrackDefinition.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of BeginTrackDefinition
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const BeginTrackDefinition::CmdName = "BeginTrackDefinition";
    const char* const BeginTrackDefinition::Documentation = "Begins a new track definition. Actual track remains unchanged until\n"
      "EndTrackDefinition command is sent and successful. After this command, the\n"
      "client must push time and position pairs to form a complete track. Once all the\n"
      "positions are sent, the client must send the command EndTrackDefinition.";
    const char* const BeginTrackDefinition::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(BeginTrackDefinition);
    REGISTER_COMMAND_TO_FACTORY_IMPL(BeginTrackDefinition);


    BeginTrackDefinition::BeginTrackDefinition()
      : CommandBase(CmdName, TargetId)
    {

    }

    BeginTrackDefinitionPtr BeginTrackDefinition::create()
    {
      return std::make_shared<BeginTrackDefinition>();
    }

    BeginTrackDefinitionPtr BeginTrackDefinition::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<BeginTrackDefinition>(ptr);
    }

    bool BeginTrackDefinition::isValid() const
    {
      
        return m_values.IsObject()
        ;

    }

    std::string BeginTrackDefinition::documentation() const { return Documentation; }

    const std::vector<std::string>& BeginTrackDefinition::fieldNames() const 
    { 
      static const std::vector<std::string> names {}; 
      return names; 
    }


    int BeginTrackDefinition::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }

  }
}
