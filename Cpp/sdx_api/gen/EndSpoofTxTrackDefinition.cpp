
#include "EndSpoofTxTrackDefinition.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of EndSpoofTxTrackDefinition
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const EndSpoofTxTrackDefinition::CmdName = "EndSpoofTxTrackDefinition";
    const char* const EndSpoofTxTrackDefinition::Documentation = "This command completes the track started with the BeginSpoofTxTrackDefinition command. If\n"
      "the track is accepted, the current track in the configuration is replaced with\n"
      "this new track. If the track is not accepted, the current track in the config\n"
      "remains unchanged.\n"
      "\n"
      "Name Type   Description\n"
      "---- ------ ------------------------------\n"
      "Id   string Transmitter unique identifier.";
    const char* const EndSpoofTxTrackDefinition::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(EndSpoofTxTrackDefinition);
    REGISTER_COMMAND_TO_FACTORY_IMPL(EndSpoofTxTrackDefinition);


    EndSpoofTxTrackDefinition::EndSpoofTxTrackDefinition()
      : CommandBase(CmdName, TargetId)
    {}

    EndSpoofTxTrackDefinition::EndSpoofTxTrackDefinition(const std::string& id)
      : CommandBase(CmdName, TargetId)
    {

      setId(id);
    }

    EndSpoofTxTrackDefinitionPtr EndSpoofTxTrackDefinition::create(const std::string& id)
    {
      return std::make_shared<EndSpoofTxTrackDefinition>(id);
    }

    EndSpoofTxTrackDefinitionPtr EndSpoofTxTrackDefinition::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<EndSpoofTxTrackDefinition>(ptr);
    }

    bool EndSpoofTxTrackDefinition::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["Id"])
        ;

    }

    std::string EndSpoofTxTrackDefinition::documentation() const { return Documentation; }

    const std::vector<std::string>& EndSpoofTxTrackDefinition::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Id"}; 
      return names; 
    }


    int EndSpoofTxTrackDefinition::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string EndSpoofTxTrackDefinition::id() const
    {
      return parse_json<std::string>::parse(m_values["Id"]);
    }

    void EndSpoofTxTrackDefinition::setId(const std::string& id)
    {
      m_values.AddMember("Id", parse_json<std::string>::format(id, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
