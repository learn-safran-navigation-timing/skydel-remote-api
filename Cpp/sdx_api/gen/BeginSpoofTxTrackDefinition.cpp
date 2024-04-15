
#include "BeginSpoofTxTrackDefinition.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of BeginSpoofTxTrackDefinition
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const BeginSpoofTxTrackDefinition::CmdName = "BeginSpoofTxTrackDefinition";
    const char* const BeginSpoofTxTrackDefinition::Documentation = "Begins a new spoofer transmitter track definition. Actual track remains unchanged until\n"
      "EndSpoofTxTrackDefinition command is sent and successful. After this command, the\n"
      "client must push time and position pairs to form a complete track. Once all the\n"
      "positions are sent, the client must send the command EndSpoofTxTrackDefinition.\n"
      "\n"
      "Name Type   Description\n"
      "---- ------ ------------------------------\n"
      "Id   string Transmitter unique identifier.";
    const char* const BeginSpoofTxTrackDefinition::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(BeginSpoofTxTrackDefinition);
    REGISTER_COMMAND_TO_FACTORY_IMPL(BeginSpoofTxTrackDefinition);


    BeginSpoofTxTrackDefinition::BeginSpoofTxTrackDefinition()
      : CommandBase(CmdName, TargetId)
    {}

    BeginSpoofTxTrackDefinition::BeginSpoofTxTrackDefinition(const std::string& id)
      : CommandBase(CmdName, TargetId)
    {

      setId(id);
    }

    BeginSpoofTxTrackDefinitionPtr BeginSpoofTxTrackDefinition::create(const std::string& id)
    {
      return std::make_shared<BeginSpoofTxTrackDefinition>(id);
    }

    BeginSpoofTxTrackDefinitionPtr BeginSpoofTxTrackDefinition::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<BeginSpoofTxTrackDefinition>(ptr);
    }

    bool BeginSpoofTxTrackDefinition::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["Id"])
        ;

    }

    std::string BeginSpoofTxTrackDefinition::documentation() const { return Documentation; }

    const std::vector<std::string>& BeginSpoofTxTrackDefinition::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Id"}; 
      return names; 
    }


    int BeginSpoofTxTrackDefinition::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string BeginSpoofTxTrackDefinition::id() const
    {
      return parse_json<std::string>::parse(m_values["Id"]);
    }

    void BeginSpoofTxTrackDefinition::setId(const std::string& id)
    {
      m_values.AddMember("Id", parse_json<std::string>::format(id, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
