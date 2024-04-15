
#include "RawDataLoggingIntervalResult.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of RawDataLoggingIntervalResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const RawDataLoggingIntervalResult::CmdName = "RawDataLoggingIntervalResult";
    const char* const RawDataLoggingIntervalResult::Documentation = "Result of GetRawDataLoggingInterval.\n"
      "\n"
      "Name         Type Description\n"
      "------------ ---- -------------------------\n"
      "Days         int  Interval in days.\n"
      "Hours        int  Interval in hours.\n"
      "Minutes      int  Interval in minutes.\n"
      "Seconds      int  Interval in seconds.\n"
      "Milliseconds int  Interval in milliseconds.";
    const char* const RawDataLoggingIntervalResult::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_IMPL(RawDataLoggingIntervalResult);


    RawDataLoggingIntervalResult::RawDataLoggingIntervalResult()
      : CommandResult(CmdName, TargetId)
    {}

    RawDataLoggingIntervalResult::RawDataLoggingIntervalResult(int days, int hours, int minutes, int seconds, int milliseconds)
      : CommandResult(CmdName, TargetId)
    {

      setDays(days);
      setHours(hours);
      setMinutes(minutes);
      setSeconds(seconds);
      setMilliseconds(milliseconds);
    }

    RawDataLoggingIntervalResult::RawDataLoggingIntervalResult(CommandBasePtr relatedCommand, int days, int hours, int minutes, int seconds, int milliseconds)
      : CommandResult(CmdName, TargetId, relatedCommand)
    {

      setDays(days);
      setHours(hours);
      setMinutes(minutes);
      setSeconds(seconds);
      setMilliseconds(milliseconds);
    }


    RawDataLoggingIntervalResultPtr RawDataLoggingIntervalResult::create(int days, int hours, int minutes, int seconds, int milliseconds)
    {
      return std::make_shared<RawDataLoggingIntervalResult>(days, hours, minutes, seconds, milliseconds);
    }

    RawDataLoggingIntervalResultPtr RawDataLoggingIntervalResult::create(CommandBasePtr relatedCommand, int days, int hours, int minutes, int seconds, int milliseconds)
    {
      return std::make_shared<RawDataLoggingIntervalResult>(relatedCommand, days, hours, minutes, seconds, milliseconds);
    }

    RawDataLoggingIntervalResultPtr RawDataLoggingIntervalResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<RawDataLoggingIntervalResult>(ptr);
    }

    bool RawDataLoggingIntervalResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["Days"])
          && parse_json<int>::is_valid(m_values["Hours"])
          && parse_json<int>::is_valid(m_values["Minutes"])
          && parse_json<int>::is_valid(m_values["Seconds"])
          && parse_json<int>::is_valid(m_values["Milliseconds"])
        ;

    }

    std::string RawDataLoggingIntervalResult::documentation() const { return Documentation; }

    const std::vector<std::string>& RawDataLoggingIntervalResult::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Days", "Hours", "Minutes", "Seconds", "Milliseconds"}; 
      return names; 
    }


    int RawDataLoggingIntervalResult::days() const
    {
      return parse_json<int>::parse(m_values["Days"]);
    }

    void RawDataLoggingIntervalResult::setDays(int days)
    {
      m_values.AddMember("Days", parse_json<int>::format(days, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int RawDataLoggingIntervalResult::hours() const
    {
      return parse_json<int>::parse(m_values["Hours"]);
    }

    void RawDataLoggingIntervalResult::setHours(int hours)
    {
      m_values.AddMember("Hours", parse_json<int>::format(hours, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int RawDataLoggingIntervalResult::minutes() const
    {
      return parse_json<int>::parse(m_values["Minutes"]);
    }

    void RawDataLoggingIntervalResult::setMinutes(int minutes)
    {
      m_values.AddMember("Minutes", parse_json<int>::format(minutes, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int RawDataLoggingIntervalResult::seconds() const
    {
      return parse_json<int>::parse(m_values["Seconds"]);
    }

    void RawDataLoggingIntervalResult::setSeconds(int seconds)
    {
      m_values.AddMember("Seconds", parse_json<int>::format(seconds, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int RawDataLoggingIntervalResult::milliseconds() const
    {
      return parse_json<int>::parse(m_values["Milliseconds"]);
    }

    void RawDataLoggingIntervalResult::setMilliseconds(int milliseconds)
    {
      m_values.AddMember("Milliseconds", parse_json<int>::format(milliseconds, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
