
#include "gen/BeginTrackDefinition.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of BeginTrackDefinition
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const BeginTrackDefinition::CmdName = "BeginTrackDefinition";
    const char* const BeginTrackDefinition::Documentation = "Begins a new track definition. Actual track remains unchanged until\nEndTrackDefinition command is sent and successful. After this command, the\nclient must push time and position pairs to form a complete track. Once all the\npositions are sent, the client must send the command EndTrackDefinition.";

    REGISTER_COMMAND_FACTORY(BeginTrackDefinition);


    BeginTrackDefinition::BeginTrackDefinition()
      : CommandBase(CmdName)
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


    int BeginTrackDefinition::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }

  }
}
