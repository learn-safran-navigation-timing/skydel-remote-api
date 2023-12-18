
#include "gen/SetEphemerisUpdateInterval.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetEphemerisUpdateInterval
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetEphemerisUpdateInterval::CmdName = "SetEphemerisUpdateInterval";
    const char* const SetEphemerisUpdateInterval::Documentation = "Set the ephemeris update interval in seconds.";

    REGISTER_COMMAND_FACTORY(SetEphemerisUpdateInterval);


    SetEphemerisUpdateInterval::SetEphemerisUpdateInterval()
      : CommandBase(CmdName)
    {}

    SetEphemerisUpdateInterval::SetEphemerisUpdateInterval(const std::string& system, int interval)
      : CommandBase(CmdName)
    {

      setSystem(system);
      setInterval(interval);
    }

    SetEphemerisUpdateIntervalPtr SetEphemerisUpdateInterval::create(const std::string& system, int interval)
    {
      return std::make_shared<SetEphemerisUpdateInterval>(system, interval);
    }

    SetEphemerisUpdateIntervalPtr SetEphemerisUpdateInterval::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetEphemerisUpdateInterval>(ptr);
    }

    bool SetEphemerisUpdateInterval::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["System"])
          && parse_json<int>::is_valid(m_values["Interval"])
        ;

    }

    std::string SetEphemerisUpdateInterval::documentation() const { return Documentation; }


    int SetEphemerisUpdateInterval::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string SetEphemerisUpdateInterval::system() const
    {
      return parse_json<std::string>::parse(m_values["System"]);
    }

    void SetEphemerisUpdateInterval::setSystem(const std::string& system)
    {
      m_values.AddMember("System", parse_json<std::string>::format(system, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int SetEphemerisUpdateInterval::interval() const
    {
      return parse_json<int>::parse(m_values["Interval"]);
    }

    void SetEphemerisUpdateInterval::setInterval(int interval)
    {
      m_values.AddMember("Interval", parse_json<int>::format(interval, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
