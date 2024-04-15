
#include "EndRouteDefinitionResult.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of EndRouteDefinitionResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const EndRouteDefinitionResult::CmdName = "EndRouteDefinitionResult";
    const char* const EndRouteDefinitionResult::Documentation = "EndRouteDefinition Result with created route informations.\n"
      "\n"
      "Name  Type Description\n"
      "----- ---- ----------------------------------------------------------------------------------------------------\n"
      "Count int  Number of nodes in the route. The client can compare this value with the number of positions pushed.";
    const char* const EndRouteDefinitionResult::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_IMPL(EndRouteDefinitionResult);


    EndRouteDefinitionResult::EndRouteDefinitionResult()
      : CommandResult(CmdName, TargetId)
    {}

    EndRouteDefinitionResult::EndRouteDefinitionResult(int count)
      : CommandResult(CmdName, TargetId)
    {

      setCount(count);
    }

    EndRouteDefinitionResult::EndRouteDefinitionResult(CommandBasePtr relatedCommand, int count)
      : CommandResult(CmdName, TargetId, relatedCommand)
    {

      setCount(count);
    }


    EndRouteDefinitionResultPtr EndRouteDefinitionResult::create(int count)
    {
      return std::make_shared<EndRouteDefinitionResult>(count);
    }

    EndRouteDefinitionResultPtr EndRouteDefinitionResult::create(CommandBasePtr relatedCommand, int count)
    {
      return std::make_shared<EndRouteDefinitionResult>(relatedCommand, count);
    }

    EndRouteDefinitionResultPtr EndRouteDefinitionResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<EndRouteDefinitionResult>(ptr);
    }

    bool EndRouteDefinitionResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["Count"])
        ;

    }

    std::string EndRouteDefinitionResult::documentation() const { return Documentation; }

    const std::vector<std::string>& EndRouteDefinitionResult::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Count"}; 
      return names; 
    }


    int EndRouteDefinitionResult::count() const
    {
      return parse_json<int>::parse(m_values["Count"]);
    }

    void EndRouteDefinitionResult::setCount(int count)
    {
      m_values.AddMember("Count", parse_json<int>::format(count, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
