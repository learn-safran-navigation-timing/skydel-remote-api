
#include "SetEphemerisUpdateInterval.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetEphemerisUpdateInterval
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetEphemerisUpdateInterval::CmdName = "SetEphemerisUpdateInterval";
    const char* const SetEphemerisUpdateInterval::Documentation = "Set the ephemeris update interval in seconds.\n"
      "\n"
      "Name     Type   Description\n"
      "-------- ------ -----------------------------------------------------------------------------------------------------------------------\n"
      "System   string \"GPS\", \"Galileo\", \"BeiDou\", \"QZSS\", \"NavIC\" or \"PULSAR\"\n"
      "Interval int    Interval duration in sec. Accepted range is [1..604800]. Must be a divider of the number of seconds in a week (604800).";
    const char* const SetEphemerisUpdateInterval::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(SetEphemerisUpdateInterval);
    REGISTER_COMMAND_TO_FACTORY_IMPL(SetEphemerisUpdateInterval);


    SetEphemerisUpdateInterval::SetEphemerisUpdateInterval()
      : CommandBase(CmdName, TargetId)
    {}

    SetEphemerisUpdateInterval::SetEphemerisUpdateInterval(const std::string& system, int interval)
      : CommandBase(CmdName, TargetId)
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

    const std::vector<std::string>& SetEphemerisUpdateInterval::fieldNames() const 
    { 
      static const std::vector<std::string> names {"System", "Interval"}; 
      return names; 
    }


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
