
#include "BeginIntTxTrackDefinition.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of BeginIntTxTrackDefinition
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const BeginIntTxTrackDefinition::CmdName = "BeginIntTxTrackDefinition";
    const char* const BeginIntTxTrackDefinition::Documentation = "Begins a new interference track definition. Actual track remains unchanged until\n"
      "EndIntTxTrackDefinition command is sent and successful. After this command, the\n"
      "client must push time and position pairs to form a complete track. Once all the\n"
      "positions are sent, the client must send the command EndIntTxTrackDefinition.\n"
      "\n"
      "Name Type   Description\n"
      "---- ------ ------------------------------\n"
      "Id   string Transmitter unique identifier.";
    const char* const BeginIntTxTrackDefinition::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(BeginIntTxTrackDefinition);
    REGISTER_COMMAND_TO_FACTORY_IMPL(BeginIntTxTrackDefinition);


    BeginIntTxTrackDefinition::BeginIntTxTrackDefinition()
      : CommandBase(CmdName, TargetId)
    {}

    BeginIntTxTrackDefinition::BeginIntTxTrackDefinition(const std::string& id)
      : CommandBase(CmdName, TargetId)
    {

      setId(id);
    }

    BeginIntTxTrackDefinitionPtr BeginIntTxTrackDefinition::create(const std::string& id)
    {
      return std::make_shared<BeginIntTxTrackDefinition>(id);
    }

    BeginIntTxTrackDefinitionPtr BeginIntTxTrackDefinition::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<BeginIntTxTrackDefinition>(ptr);
    }

    bool BeginIntTxTrackDefinition::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["Id"])
        ;

    }

    std::string BeginIntTxTrackDefinition::documentation() const { return Documentation; }

    const std::vector<std::string>& BeginIntTxTrackDefinition::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Id"}; 
      return names; 
    }


    int BeginIntTxTrackDefinition::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string BeginIntTxTrackDefinition::id() const
    {
      return parse_json<std::string>::parse(m_values["Id"]);
    }

    void BeginIntTxTrackDefinition::setId(const std::string& id)
    {
      m_values.AddMember("Id", parse_json<std::string>::format(id, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
