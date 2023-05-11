
#include "gen/GetStartTimeOffsetResult.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetStartTimeOffsetResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetStartTimeOffsetResult::CmdName = "GetStartTimeOffsetResult";
    const char* const GetStartTimeOffsetResult::Documentation = "Result of GetStartTimeOffset.";

    REGISTER_COMMAND_RESULT_TO_FACTORY_IMPL(GetStartTimeOffsetResult);


    GetStartTimeOffsetResult::GetStartTimeOffsetResult()
      : CommandResult(CmdName)
    {}

    GetStartTimeOffsetResult::GetStartTimeOffsetResult(int offset)
      : CommandResult(CmdName)
    {

      setOffset(offset);
    }

    GetStartTimeOffsetResult::GetStartTimeOffsetResult(CommandBasePtr relatedCommand, int offset)
      : CommandResult(CmdName, relatedCommand)
    {

      setOffset(offset);
    }


    GetStartTimeOffsetResultPtr GetStartTimeOffsetResult::create(int offset)
    {
      return std::make_shared<GetStartTimeOffsetResult>(offset);
    }

    GetStartTimeOffsetResultPtr GetStartTimeOffsetResult::create(CommandBasePtr relatedCommand, int offset)
    {
      return std::make_shared<GetStartTimeOffsetResult>(relatedCommand, offset);
    }

    GetStartTimeOffsetResultPtr GetStartTimeOffsetResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetStartTimeOffsetResult>(ptr);
    }

    bool GetStartTimeOffsetResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["Offset"])
        ;

    }

    std::string GetStartTimeOffsetResult::documentation() const { return Documentation; }


    int GetStartTimeOffsetResult::offset() const
    {
      return parse_json<int>::parse(m_values["Offset"]);
    }

    void GetStartTimeOffsetResult::setOffset(int offset)
    {
      m_values.AddMember("Offset", parse_json<int>::format(offset, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
