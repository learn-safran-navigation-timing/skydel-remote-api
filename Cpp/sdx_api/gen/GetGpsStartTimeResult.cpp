
#include "gen/GetGpsStartTimeResult.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetGpsStartTimeResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetGpsStartTimeResult::CmdName = "GetGpsStartTimeResult";
    const char* const GetGpsStartTimeResult::Documentation = "Result of GetGpsStartTime.";

    REGISTER_COMMAND_RESULT_TO_FACTORY_IMPL(GetGpsStartTimeResult);


    GetGpsStartTimeResult::GetGpsStartTimeResult()
      : CommandResult(CmdName)
    {}

    GetGpsStartTimeResult::GetGpsStartTimeResult(const Sdx::DateTime& startTime, int leapSecond)
      : CommandResult(CmdName)
    {

      setStartTime(startTime);
      setLeapSecond(leapSecond);
    }

    GetGpsStartTimeResult::GetGpsStartTimeResult(CommandBasePtr relatedCommand, const Sdx::DateTime& startTime, int leapSecond)
      : CommandResult(CmdName, relatedCommand)
    {

      setStartTime(startTime);
      setLeapSecond(leapSecond);
    }


    GetGpsStartTimeResultPtr GetGpsStartTimeResult::create(const Sdx::DateTime& startTime, int leapSecond)
    {
      return std::make_shared<GetGpsStartTimeResult>(startTime, leapSecond);
    }

    GetGpsStartTimeResultPtr GetGpsStartTimeResult::create(CommandBasePtr relatedCommand, const Sdx::DateTime& startTime, int leapSecond)
    {
      return std::make_shared<GetGpsStartTimeResult>(relatedCommand, startTime, leapSecond);
    }

    GetGpsStartTimeResultPtr GetGpsStartTimeResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetGpsStartTimeResult>(ptr);
    }

    bool GetGpsStartTimeResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<Sdx::DateTime>::is_valid(m_values["StartTime"])
          && parse_json<int>::is_valid(m_values["LeapSecond"])
        ;

    }

    std::string GetGpsStartTimeResult::documentation() const { return Documentation; }


    Sdx::DateTime GetGpsStartTimeResult::startTime() const
    {
      return parse_json<Sdx::DateTime>::parse(m_values["StartTime"]);
    }

    void GetGpsStartTimeResult::setStartTime(const Sdx::DateTime& startTime)
    {
      m_values.AddMember("StartTime", parse_json<Sdx::DateTime>::format(startTime, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int GetGpsStartTimeResult::leapSecond() const
    {
      return parse_json<int>::parse(m_values["LeapSecond"]);
    }

    void GetGpsStartTimeResult::setLeapSecond(int leapSecond)
    {
      m_values.AddMember("LeapSecond", parse_json<int>::format(leapSecond, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
