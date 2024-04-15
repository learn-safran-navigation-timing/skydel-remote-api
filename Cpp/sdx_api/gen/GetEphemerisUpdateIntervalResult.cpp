
#include "GetEphemerisUpdateIntervalResult.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetEphemerisUpdateIntervalResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetEphemerisUpdateIntervalResult::CmdName = "GetEphemerisUpdateIntervalResult";
    const char* const GetEphemerisUpdateIntervalResult::Documentation = "Result of GetEphemerisUpdateInterval.\n"
      "\n"
      "Name     Type   Description\n"
      "-------- ------ -----------------------------------------------------------------------------------------------------------------------\n"
      "System   string \"GPS\", \"Galileo\", \"BeiDou\", \"QZSS\", \"NavIC\" or \"PULSAR\"\n"
      "Interval int    Interval duration in sec. Accepted range is [1..604800]. Must be a divider of the number of seconds in a week (604800).";
    const char* const GetEphemerisUpdateIntervalResult::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_IMPL(GetEphemerisUpdateIntervalResult);


    GetEphemerisUpdateIntervalResult::GetEphemerisUpdateIntervalResult()
      : CommandResult(CmdName, TargetId)
    {}

    GetEphemerisUpdateIntervalResult::GetEphemerisUpdateIntervalResult(const std::string& system, int interval)
      : CommandResult(CmdName, TargetId)
    {

      setSystem(system);
      setInterval(interval);
    }

    GetEphemerisUpdateIntervalResult::GetEphemerisUpdateIntervalResult(CommandBasePtr relatedCommand, const std::string& system, int interval)
      : CommandResult(CmdName, TargetId, relatedCommand)
    {

      setSystem(system);
      setInterval(interval);
    }


    GetEphemerisUpdateIntervalResultPtr GetEphemerisUpdateIntervalResult::create(const std::string& system, int interval)
    {
      return std::make_shared<GetEphemerisUpdateIntervalResult>(system, interval);
    }

    GetEphemerisUpdateIntervalResultPtr GetEphemerisUpdateIntervalResult::create(CommandBasePtr relatedCommand, const std::string& system, int interval)
    {
      return std::make_shared<GetEphemerisUpdateIntervalResult>(relatedCommand, system, interval);
    }

    GetEphemerisUpdateIntervalResultPtr GetEphemerisUpdateIntervalResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetEphemerisUpdateIntervalResult>(ptr);
    }

    bool GetEphemerisUpdateIntervalResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["System"])
          && parse_json<int>::is_valid(m_values["Interval"])
        ;

    }

    std::string GetEphemerisUpdateIntervalResult::documentation() const { return Documentation; }

    const std::vector<std::string>& GetEphemerisUpdateIntervalResult::fieldNames() const 
    { 
      static const std::vector<std::string> names {"System", "Interval"}; 
      return names; 
    }


    std::string GetEphemerisUpdateIntervalResult::system() const
    {
      return parse_json<std::string>::parse(m_values["System"]);
    }

    void GetEphemerisUpdateIntervalResult::setSystem(const std::string& system)
    {
      m_values.AddMember("System", parse_json<std::string>::format(system, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int GetEphemerisUpdateIntervalResult::interval() const
    {
      return parse_json<int>::parse(m_values["Interval"]);
    }

    void GetEphemerisUpdateIntervalResult::setInterval(int interval)
    {
      m_values.AddMember("Interval", parse_json<int>::format(interval, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
