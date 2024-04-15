
#include "EndTrackDefinitionResult.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of EndTrackDefinitionResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const EndTrackDefinitionResult::CmdName = "EndTrackDefinitionResult";
    const char* const EndTrackDefinitionResult::Documentation = "EndTrackDefinition Result with created track informations.\n"
      "\n"
      "Name  Type Description\n"
      "----- ---- ----------------------------------------------------------------------------------------------------\n"
      "Count int  Number of nodes in the track. The client can compare this value with the number of positions pushed.";
    const char* const EndTrackDefinitionResult::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_IMPL(EndTrackDefinitionResult);


    EndTrackDefinitionResult::EndTrackDefinitionResult()
      : CommandResult(CmdName, TargetId)
    {}

    EndTrackDefinitionResult::EndTrackDefinitionResult(int count)
      : CommandResult(CmdName, TargetId)
    {

      setCount(count);
    }

    EndTrackDefinitionResult::EndTrackDefinitionResult(CommandBasePtr relatedCommand, int count)
      : CommandResult(CmdName, TargetId, relatedCommand)
    {

      setCount(count);
    }


    EndTrackDefinitionResultPtr EndTrackDefinitionResult::create(int count)
    {
      return std::make_shared<EndTrackDefinitionResult>(count);
    }

    EndTrackDefinitionResultPtr EndTrackDefinitionResult::create(CommandBasePtr relatedCommand, int count)
    {
      return std::make_shared<EndTrackDefinitionResult>(relatedCommand, count);
    }

    EndTrackDefinitionResultPtr EndTrackDefinitionResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<EndTrackDefinitionResult>(ptr);
    }

    bool EndTrackDefinitionResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["Count"])
        ;

    }

    std::string EndTrackDefinitionResult::documentation() const { return Documentation; }

    const std::vector<std::string>& EndTrackDefinitionResult::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Count"}; 
      return names; 
    }


    int EndTrackDefinitionResult::count() const
    {
      return parse_json<int>::parse(m_values["Count"]);
    }

    void EndTrackDefinitionResult::setCount(int count)
    {
      m_values.AddMember("Count", parse_json<int>::format(count, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
