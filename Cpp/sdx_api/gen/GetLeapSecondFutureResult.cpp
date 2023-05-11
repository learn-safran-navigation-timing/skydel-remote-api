
#include "gen/GetLeapSecondFutureResult.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetLeapSecondFutureResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetLeapSecondFutureResult::CmdName = "GetLeapSecondFutureResult";
    const char* const GetLeapSecondFutureResult::Documentation = "Result of GetLeapSecondFuture.";

    REGISTER_COMMAND_RESULT_TO_FACTORY_IMPL(GetLeapSecondFutureResult);


    GetLeapSecondFutureResult::GetLeapSecondFutureResult()
      : CommandResult(CmdName)
    {}

    GetLeapSecondFutureResult::GetLeapSecondFutureResult(bool enabled, int seconds, const Sdx::Date& date)
      : CommandResult(CmdName)
    {

      setEnabled(enabled);
      setSeconds(seconds);
      setDate(date);
    }

    GetLeapSecondFutureResult::GetLeapSecondFutureResult(CommandBasePtr relatedCommand, bool enabled, int seconds, const Sdx::Date& date)
      : CommandResult(CmdName, relatedCommand)
    {

      setEnabled(enabled);
      setSeconds(seconds);
      setDate(date);
    }


    GetLeapSecondFutureResultPtr GetLeapSecondFutureResult::create(bool enabled, int seconds, const Sdx::Date& date)
    {
      return std::make_shared<GetLeapSecondFutureResult>(enabled, seconds, date);
    }

    GetLeapSecondFutureResultPtr GetLeapSecondFutureResult::create(CommandBasePtr relatedCommand, bool enabled, int seconds, const Sdx::Date& date)
    {
      return std::make_shared<GetLeapSecondFutureResult>(relatedCommand, enabled, seconds, date);
    }

    GetLeapSecondFutureResultPtr GetLeapSecondFutureResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetLeapSecondFutureResult>(ptr);
    }

    bool GetLeapSecondFutureResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<bool>::is_valid(m_values["Enabled"])
          && parse_json<int>::is_valid(m_values["Seconds"])
          && parse_json<Sdx::Date>::is_valid(m_values["Date"])
        ;

    }

    std::string GetLeapSecondFutureResult::documentation() const { return Documentation; }


    bool GetLeapSecondFutureResult::enabled() const
    {
      return parse_json<bool>::parse(m_values["Enabled"]);
    }

    void GetLeapSecondFutureResult::setEnabled(bool enabled)
    {
      m_values.AddMember("Enabled", parse_json<bool>::format(enabled, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int GetLeapSecondFutureResult::seconds() const
    {
      return parse_json<int>::parse(m_values["Seconds"]);
    }

    void GetLeapSecondFutureResult::setSeconds(int seconds)
    {
      m_values.AddMember("Seconds", parse_json<int>::format(seconds, m_values.GetAllocator()), m_values.GetAllocator());
    }



    Sdx::Date GetLeapSecondFutureResult::date() const
    {
      return parse_json<Sdx::Date>::parse(m_values["Date"]);
    }

    void GetLeapSecondFutureResult::setDate(const Sdx::Date& date)
    {
      m_values.AddMember("Date", parse_json<Sdx::Date>::format(date, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
