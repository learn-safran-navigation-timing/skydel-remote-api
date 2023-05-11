
#include "gen/GetLastLeapSecondDateResult.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetLastLeapSecondDateResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetLastLeapSecondDateResult::CmdName = "GetLastLeapSecondDateResult";
    const char* const GetLastLeapSecondDateResult::Documentation = "Result of GetLastLeapSecondDate.";

    REGISTER_COMMAND_RESULT_TO_FACTORY_IMPL(GetLastLeapSecondDateResult);


    GetLastLeapSecondDateResult::GetLastLeapSecondDateResult()
      : CommandResult(CmdName)
    {}

    GetLastLeapSecondDateResult::GetLastLeapSecondDateResult(const Sdx::Date& date)
      : CommandResult(CmdName)
    {

      setDate(date);
    }

    GetLastLeapSecondDateResult::GetLastLeapSecondDateResult(CommandBasePtr relatedCommand, const Sdx::Date& date)
      : CommandResult(CmdName, relatedCommand)
    {

      setDate(date);
    }


    GetLastLeapSecondDateResultPtr GetLastLeapSecondDateResult::create(const Sdx::Date& date)
    {
      return std::make_shared<GetLastLeapSecondDateResult>(date);
    }

    GetLastLeapSecondDateResultPtr GetLastLeapSecondDateResult::create(CommandBasePtr relatedCommand, const Sdx::Date& date)
    {
      return std::make_shared<GetLastLeapSecondDateResult>(relatedCommand, date);
    }

    GetLastLeapSecondDateResultPtr GetLastLeapSecondDateResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetLastLeapSecondDateResult>(ptr);
    }

    bool GetLastLeapSecondDateResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<Sdx::Date>::is_valid(m_values["Date"])
        ;

    }

    std::string GetLastLeapSecondDateResult::documentation() const { return Documentation; }


    Sdx::Date GetLastLeapSecondDateResult::date() const
    {
      return parse_json<Sdx::Date>::parse(m_values["Date"]);
    }

    void GetLastLeapSecondDateResult::setDate(const Sdx::Date& date)
    {
      m_values.AddMember("Date", parse_json<Sdx::Date>::format(date, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
