
#include "gen/GetEphemerisUpdateInterval.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetEphemerisUpdateInterval
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetEphemerisUpdateInterval::CmdName = "GetEphemerisUpdateInterval";
    const char* const GetEphemerisUpdateInterval::Documentation = "Get the ephemeris update interval in seconds.";

    REGISTER_COMMAND_FACTORY(GetEphemerisUpdateInterval);


    GetEphemerisUpdateInterval::GetEphemerisUpdateInterval()
      : CommandBase(CmdName)
    {}

    GetEphemerisUpdateInterval::GetEphemerisUpdateInterval(const std::string& system)
      : CommandBase(CmdName)
    {

      setSystem(system);
    }

    GetEphemerisUpdateIntervalPtr GetEphemerisUpdateInterval::create(const std::string& system)
    {
      return std::make_shared<GetEphemerisUpdateInterval>(system);
    }

    GetEphemerisUpdateIntervalPtr GetEphemerisUpdateInterval::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetEphemerisUpdateInterval>(ptr);
    }

    bool GetEphemerisUpdateInterval::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["System"])
        ;

    }

    std::string GetEphemerisUpdateInterval::documentation() const { return Documentation; }


    int GetEphemerisUpdateInterval::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string GetEphemerisUpdateInterval::system() const
    {
      return parse_json<std::string>::parse(m_values["System"]);
    }

    void GetEphemerisUpdateInterval::setSystem(const std::string& system)
    {
      m_values.AddMember("System", parse_json<std::string>::format(system, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
