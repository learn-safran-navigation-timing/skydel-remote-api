
#include "SetRawDataLoggingInterval.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetRawDataLoggingInterval
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetRawDataLoggingInterval::CmdName = "SetRawDataLoggingInterval";
    const char* const SetRawDataLoggingInterval::Documentation = "Set the time interval of the Raw Data logging.\n"
      "\n"
      "Name         Type Description\n"
      "------------ ---- -------------------------\n"
      "Days         int  Interval in days.\n"
      "Hours        int  Interval in hours.\n"
      "Minutes      int  Interval in minutes.\n"
      "Seconds      int  Interval in seconds.\n"
      "Milliseconds int  Interval in milliseconds.";
    const char* const SetRawDataLoggingInterval::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(SetRawDataLoggingInterval);
    REGISTER_COMMAND_TO_FACTORY_IMPL(SetRawDataLoggingInterval);


    SetRawDataLoggingInterval::SetRawDataLoggingInterval()
      : CommandBase(CmdName, TargetId)
    {}

    SetRawDataLoggingInterval::SetRawDataLoggingInterval(int days, int hours, int minutes, int seconds, int milliseconds)
      : CommandBase(CmdName, TargetId)
    {

      setDays(days);
      setHours(hours);
      setMinutes(minutes);
      setSeconds(seconds);
      setMilliseconds(milliseconds);
    }

    SetRawDataLoggingIntervalPtr SetRawDataLoggingInterval::create(int days, int hours, int minutes, int seconds, int milliseconds)
    {
      return std::make_shared<SetRawDataLoggingInterval>(days, hours, minutes, seconds, milliseconds);
    }

    SetRawDataLoggingIntervalPtr SetRawDataLoggingInterval::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetRawDataLoggingInterval>(ptr);
    }

    bool SetRawDataLoggingInterval::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["Days"])
          && parse_json<int>::is_valid(m_values["Hours"])
          && parse_json<int>::is_valid(m_values["Minutes"])
          && parse_json<int>::is_valid(m_values["Seconds"])
          && parse_json<int>::is_valid(m_values["Milliseconds"])
        ;

    }

    std::string SetRawDataLoggingInterval::documentation() const { return Documentation; }

    const std::vector<std::string>& SetRawDataLoggingInterval::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Days", "Hours", "Minutes", "Seconds", "Milliseconds"}; 
      return names; 
    }


    int SetRawDataLoggingInterval::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    int SetRawDataLoggingInterval::days() const
    {
      return parse_json<int>::parse(m_values["Days"]);
    }

    void SetRawDataLoggingInterval::setDays(int days)
    {
      m_values.AddMember("Days", parse_json<int>::format(days, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int SetRawDataLoggingInterval::hours() const
    {
      return parse_json<int>::parse(m_values["Hours"]);
    }

    void SetRawDataLoggingInterval::setHours(int hours)
    {
      m_values.AddMember("Hours", parse_json<int>::format(hours, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int SetRawDataLoggingInterval::minutes() const
    {
      return parse_json<int>::parse(m_values["Minutes"]);
    }

    void SetRawDataLoggingInterval::setMinutes(int minutes)
    {
      m_values.AddMember("Minutes", parse_json<int>::format(minutes, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int SetRawDataLoggingInterval::seconds() const
    {
      return parse_json<int>::parse(m_values["Seconds"]);
    }

    void SetRawDataLoggingInterval::setSeconds(int seconds)
    {
      m_values.AddMember("Seconds", parse_json<int>::format(seconds, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int SetRawDataLoggingInterval::milliseconds() const
    {
      return parse_json<int>::parse(m_values["Milliseconds"]);
    }

    void SetRawDataLoggingInterval::setMilliseconds(int milliseconds)
    {
      m_values.AddMember("Milliseconds", parse_json<int>::format(milliseconds, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
