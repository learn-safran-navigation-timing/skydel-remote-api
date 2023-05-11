
#include "gen/SetLeapSecondFuture.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetLeapSecondFuture
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetLeapSecondFuture::CmdName = "SetLeapSecondFuture";
    const char* const SetLeapSecondFuture::Documentation = "Set the next leap second event";

    REGISTER_COMMAND_FACTORY(SetLeapSecondFuture);


    SetLeapSecondFuture::SetLeapSecondFuture()
      : CommandBase(CmdName)
    {}

    SetLeapSecondFuture::SetLeapSecondFuture(bool enabled, int seconds, const Sdx::Date& date)
      : CommandBase(CmdName)
    {

      setEnabled(enabled);
      setSeconds(seconds);
      setDate(date);
    }

    SetLeapSecondFuturePtr SetLeapSecondFuture::create(bool enabled, int seconds, const Sdx::Date& date)
    {
      return std::make_shared<SetLeapSecondFuture>(enabled, seconds, date);
    }

    SetLeapSecondFuturePtr SetLeapSecondFuture::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetLeapSecondFuture>(ptr);
    }

    bool SetLeapSecondFuture::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<bool>::is_valid(m_values["Enabled"])
          && parse_json<int>::is_valid(m_values["Seconds"])
          && parse_json<Sdx::Date>::is_valid(m_values["Date"])
        ;

    }

    std::string SetLeapSecondFuture::documentation() const { return Documentation; }


    int SetLeapSecondFuture::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    bool SetLeapSecondFuture::enabled() const
    {
      return parse_json<bool>::parse(m_values["Enabled"]);
    }

    void SetLeapSecondFuture::setEnabled(bool enabled)
    {
      m_values.AddMember("Enabled", parse_json<bool>::format(enabled, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int SetLeapSecondFuture::seconds() const
    {
      return parse_json<int>::parse(m_values["Seconds"]);
    }

    void SetLeapSecondFuture::setSeconds(int seconds)
    {
      m_values.AddMember("Seconds", parse_json<int>::format(seconds, m_values.GetAllocator()), m_values.GetAllocator());
    }



    Sdx::Date SetLeapSecondFuture::date() const
    {
      return parse_json<Sdx::Date>::parse(m_values["Date"]);
    }

    void SetLeapSecondFuture::setDate(const Sdx::Date& date)
    {
      m_values.AddMember("Date", parse_json<Sdx::Date>::format(date, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
