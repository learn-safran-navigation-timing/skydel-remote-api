
#include "EndTrackDefinition.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of EndTrackDefinition
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const EndTrackDefinition::CmdName = "EndTrackDefinition";
    const char* const EndTrackDefinition::Documentation = "This command completes the track started with BeginTrackDefinition command. If\n"
      "the track is accepted, the current track in the configuration is replaced with\n"
      "this new track. If the track is not accepted, the current track in the config\n"
      "remains unchanged.";
    const char* const EndTrackDefinition::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(EndTrackDefinition);
    REGISTER_COMMAND_TO_FACTORY_IMPL(EndTrackDefinition);


    EndTrackDefinition::EndTrackDefinition()
      : CommandBase(CmdName, TargetId)
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

    const std::vector<std::string>& EndTrackDefinition::fieldNames() const 
    { 
      static const std::vector<std::string> names {}; 
      return names; 
    }


    int EndTrackDefinition::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }

  }
}
