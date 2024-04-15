
#include "EndIntTxTrackDefinition.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of EndIntTxTrackDefinition
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const EndIntTxTrackDefinition::CmdName = "EndIntTxTrackDefinition";
    const char* const EndIntTxTrackDefinition::Documentation = "This command completes the track started with BeginIntTxTrackDefinition command. If\n"
      "the track is accepted, the current track in the configuration is replaced with\n"
      "this new track. If the track is not accepted, the current track in the config\n"
      "remains unchanged.\n"
      "\n"
      "Name Type   Description\n"
      "---- ------ ------------------------------\n"
      "Id   string Transmitter unique identifier.";
    const char* const EndIntTxTrackDefinition::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(EndIntTxTrackDefinition);
    REGISTER_COMMAND_TO_FACTORY_IMPL(EndIntTxTrackDefinition);


    EndIntTxTrackDefinition::EndIntTxTrackDefinition()
      : CommandBase(CmdName, TargetId)
    {}

    EndIntTxTrackDefinition::EndIntTxTrackDefinition(const std::string& id)
      : CommandBase(CmdName, TargetId)
    {

      setId(id);
    }

    EndIntTxTrackDefinitionPtr EndIntTxTrackDefinition::create(const std::string& id)
    {
      return std::make_shared<EndIntTxTrackDefinition>(id);
    }

    EndIntTxTrackDefinitionPtr EndIntTxTrackDefinition::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<EndIntTxTrackDefinition>(ptr);
    }

    bool EndIntTxTrackDefinition::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["Id"])
        ;

    }

    std::string EndIntTxTrackDefinition::documentation() const { return Documentation; }

    const std::vector<std::string>& EndIntTxTrackDefinition::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Id"}; 
      return names; 
    }


    int EndIntTxTrackDefinition::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string EndIntTxTrackDefinition::id() const
    {
      return parse_json<std::string>::parse(m_values["Id"]);
    }

    void EndIntTxTrackDefinition::setId(const std::string& id)
    {
      m_values.AddMember("Id", parse_json<std::string>::format(id, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
