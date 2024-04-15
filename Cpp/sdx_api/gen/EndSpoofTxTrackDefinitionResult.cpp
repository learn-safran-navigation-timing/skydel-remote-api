
#include "EndSpoofTxTrackDefinitionResult.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of EndSpoofTxTrackDefinitionResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const EndSpoofTxTrackDefinitionResult::CmdName = "EndSpoofTxTrackDefinitionResult";
    const char* const EndSpoofTxTrackDefinitionResult::Documentation = "EndSpoofTxTrackDefinition Result with created track informations.\n"
      "\n"
      "Name  Type   Description\n"
      "----- ------ ----------------------------------------------------------------------------------------------------\n"
      "Count int    Number of nodes in the track. The client can compare this value with the number of positions pushed.\n"
      "Id    string Transmitter unique identifier.";
    const char* const EndSpoofTxTrackDefinitionResult::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_IMPL(EndSpoofTxTrackDefinitionResult);


    EndSpoofTxTrackDefinitionResult::EndSpoofTxTrackDefinitionResult()
      : CommandResult(CmdName, TargetId)
    {}

    EndSpoofTxTrackDefinitionResult::EndSpoofTxTrackDefinitionResult(int count, const std::string& id)
      : CommandResult(CmdName, TargetId)
    {

      setCount(count);
      setId(id);
    }

    EndSpoofTxTrackDefinitionResult::EndSpoofTxTrackDefinitionResult(CommandBasePtr relatedCommand, int count, const std::string& id)
      : CommandResult(CmdName, TargetId, relatedCommand)
    {

      setCount(count);
      setId(id);
    }


    EndSpoofTxTrackDefinitionResultPtr EndSpoofTxTrackDefinitionResult::create(int count, const std::string& id)
    {
      return std::make_shared<EndSpoofTxTrackDefinitionResult>(count, id);
    }

    EndSpoofTxTrackDefinitionResultPtr EndSpoofTxTrackDefinitionResult::create(CommandBasePtr relatedCommand, int count, const std::string& id)
    {
      return std::make_shared<EndSpoofTxTrackDefinitionResult>(relatedCommand, count, id);
    }

    EndSpoofTxTrackDefinitionResultPtr EndSpoofTxTrackDefinitionResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<EndSpoofTxTrackDefinitionResult>(ptr);
    }

    bool EndSpoofTxTrackDefinitionResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["Count"])
          && parse_json<std::string>::is_valid(m_values["Id"])
        ;

    }

    std::string EndSpoofTxTrackDefinitionResult::documentation() const { return Documentation; }

    const std::vector<std::string>& EndSpoofTxTrackDefinitionResult::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Count", "Id"}; 
      return names; 
    }


    int EndSpoofTxTrackDefinitionResult::count() const
    {
      return parse_json<int>::parse(m_values["Count"]);
    }

    void EndSpoofTxTrackDefinitionResult::setCount(int count)
    {
      m_values.AddMember("Count", parse_json<int>::format(count, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string EndSpoofTxTrackDefinitionResult::id() const
    {
      return parse_json<std::string>::parse(m_values["Id"]);
    }

    void EndSpoofTxTrackDefinitionResult::setId(const std::string& id)
    {
      m_values.AddMember("Id", parse_json<std::string>::format(id, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
