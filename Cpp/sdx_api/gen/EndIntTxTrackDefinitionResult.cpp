
#include "gen/EndIntTxTrackDefinitionResult.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of EndIntTxTrackDefinitionResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const EndIntTxTrackDefinitionResult::CmdName = "EndIntTxTrackDefinitionResult";
    const char* const EndIntTxTrackDefinitionResult::Documentation = "EndIntTxTrackDefinition Result with created track informations.";

    REGISTER_COMMAND_RESULT_TO_FACTORY_IMPL(EndIntTxTrackDefinitionResult);


    EndIntTxTrackDefinitionResult::EndIntTxTrackDefinitionResult()
      : CommandResult(CmdName)
    {}

    EndIntTxTrackDefinitionResult::EndIntTxTrackDefinitionResult(int count, const std::string& id)
      : CommandResult(CmdName)
    {

      setCount(count);
      setId(id);
    }

    EndIntTxTrackDefinitionResult::EndIntTxTrackDefinitionResult(CommandBasePtr relatedCommand, int count, const std::string& id)
      : CommandResult(CmdName, relatedCommand)
    {

      setCount(count);
      setId(id);
    }


    EndIntTxTrackDefinitionResultPtr EndIntTxTrackDefinitionResult::create(int count, const std::string& id)
    {
      return std::make_shared<EndIntTxTrackDefinitionResult>(count, id);
    }

    EndIntTxTrackDefinitionResultPtr EndIntTxTrackDefinitionResult::create(CommandBasePtr relatedCommand, int count, const std::string& id)
    {
      return std::make_shared<EndIntTxTrackDefinitionResult>(relatedCommand, count, id);
    }

    EndIntTxTrackDefinitionResultPtr EndIntTxTrackDefinitionResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<EndIntTxTrackDefinitionResult>(ptr);
    }

    bool EndIntTxTrackDefinitionResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["Count"])
          && parse_json<std::string>::is_valid(m_values["Id"])
        ;

    }

    std::string EndIntTxTrackDefinitionResult::documentation() const { return Documentation; }


    int EndIntTxTrackDefinitionResult::count() const
    {
      return parse_json<int>::parse(m_values["Count"]);
    }

    void EndIntTxTrackDefinitionResult::setCount(int count)
    {
      m_values.AddMember("Count", parse_json<int>::format(count, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string EndIntTxTrackDefinitionResult::id() const
    {
      return parse_json<std::string>::parse(m_values["Id"]);
    }

    void EndIntTxTrackDefinitionResult::setId(const std::string& id)
    {
      m_values.AddMember("Id", parse_json<std::string>::format(id, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
