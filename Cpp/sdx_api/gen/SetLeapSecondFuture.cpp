
#include "SetLeapSecondFuture.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetLeapSecondFuture
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetLeapSecondFuture::CmdName = "SetLeapSecondFuture";
    const char* const SetLeapSecondFuture::Documentation = "Set the next leap second event\n"
      "\n"
      "Name    Type Description\n"
      "------- ---- ----------------------------------------------------------------------\n"
      "Enabled bool If true, the future leap second event is set in the navigation message\n"
      "Seconds int  The future leap seconds value\n"
      "Date    date The event date";
    const char* const SetLeapSecondFuture::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(SetLeapSecondFuture);
    REGISTER_COMMAND_TO_FACTORY_IMPL(SetLeapSecondFuture);


    SetLeapSecondFuture::SetLeapSecondFuture()
      : CommandBase(CmdName, TargetId)
    {}

    SetLeapSecondFuture::SetLeapSecondFuture(bool enabled, int seconds, const Sdx::Date& date)
      : CommandBase(CmdName, TargetId)
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

    const std::vector<std::string>& SetLeapSecondFuture::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Enabled", "Seconds", "Date"}; 
      return names; 
    }


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
