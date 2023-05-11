
#include "gen/EndTrackDefinition.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of EndTrackDefinition
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const EndTrackDefinition::CmdName = "EndTrackDefinition";
    const char* const EndTrackDefinition::Documentation = "This command completes the track started with BeginTrackDefinition command. If\nthe track is accepted, the current track in the configuration is replaced with\nthis new track. If the track is not accepted, the current track in the config\nremains unchanged.";

    REGISTER_COMMAND_FACTORY(EndTrackDefinition);


    EndTrackDefinition::EndTrackDefinition()
      : CommandBase(CmdName)
    {

    }

    EndTrackDefinitionPtr EndTrackDefinition::create()
    {
      return std::make_shared<EndTrackDefinition>();
    }

    EndTrackDefinitionPtr EndTrackDefinition::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<EndTrackDefinition>(ptr);
    }

    bool EndTrackDefinition::isValid() const
    {
      
        return m_values.IsObject()
        ;

    }

    std::string EndTrackDefinition::documentation() const { return Documentation; }


    int EndTrackDefinition::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }

  }
}
