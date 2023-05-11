
#include "gen/BeginIntTxTrackDefinition.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of BeginIntTxTrackDefinition
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const BeginIntTxTrackDefinition::CmdName = "BeginIntTxTrackDefinition";
    const char* const BeginIntTxTrackDefinition::Documentation = "Begins a new interference track definition. Actual track remains unchanged until\nEndIntTxTrackDefinition command is sent and successful. After this command, the\nclient must push time and position pairs to form a complete track. Once all the\npositions are sent, the client must send the command EndIntTxTrackDefinition.";

    REGISTER_COMMAND_FACTORY(BeginIntTxTrackDefinition);


    BeginIntTxTrackDefinition::BeginIntTxTrackDefinition()
      : CommandBase(CmdName)
    {}

    BeginIntTxTrackDefinition::BeginIntTxTrackDefinition(const std::string& id)
      : CommandBase(CmdName)
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
