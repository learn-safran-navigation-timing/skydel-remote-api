
#include "gen/GetOfficialLeapSecondResult.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetOfficialLeapSecondResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetOfficialLeapSecondResult::CmdName = "GetOfficialLeapSecondResult";
    const char* const GetOfficialLeapSecondResult::Documentation = "Result of GetOfficialLeapSecond";

    REGISTER_COMMAND_RESULT_TO_FACTORY_IMPL(GetOfficialLeapSecondResult);


    GetOfficialLeapSecondResult::GetOfficialLeapSecondResult()
      : CommandResult(CmdName)
    {}

    GetOfficialLeapSecondResult::GetOfficialLeapSecondResult(int leapSecond)
      : CommandResult(CmdName)
    {

      setLeapSecond(leapSecond);
    }

    GetOfficialLeapSecondResult::GetOfficialLeapSecondResult(CommandBasePtr relatedCommand, int leapSecond)
      : CommandResult(CmdName, relatedCommand)
    {

      setLeapSecond(leapSecond);
    }


    GetOfficialLeapSecondResultPtr GetOfficialLeapSecondResult::create(int leapSecond)
    {
      return std::make_shared<GetOfficialLeapSecondResult>(leapSecond);
    }

    GetOfficialLeapSecondResultPtr GetOfficialLeapSecondResult::create(CommandBasePtr relatedCommand, int leapSecond)
    {
      return std::make_shared<GetOfficialLeapSecondResult>(relatedCommand, leapSecond);
    }

    GetOfficialLeapSecondResultPtr GetOfficialLeapSecondResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetOfficialLeapSecondResult>(ptr);
    }

    bool GetOfficialLeapSecondResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["LeapSecond"])
        ;

    }

    std::string GetOfficialLeapSecondResult::documentation() const { return Documentation; }


    int GetOfficialLeapSecondResult::leapSecond() const
    {
      return parse_json<int>::parse(m_values["LeapSecond"]);
    }

    void GetOfficialLeapSecondResult::setLeapSecond(int leapSecond)
    {
      m_values.AddMember("LeapSecond", parse_json<int>::format(leapSecond, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
