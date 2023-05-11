
#include "gen/SetSbasMessageUpdateInterval.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetSbasMessageUpdateInterval
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetSbasMessageUpdateInterval::CmdName = "SetSbasMessageUpdateInterval";
    const char* const SetSbasMessageUpdateInterval::Documentation = "Set the SBAS message update interval.";

    REGISTER_COMMAND_FACTORY(SetSbasMessageUpdateInterval);


    SetSbasMessageUpdateInterval::SetSbasMessageUpdateInterval()
      : CommandBase(CmdName)
    {}

    SetSbasMessageUpdateInterval::SetSbasMessageUpdateInterval(int message, int updateInterval)
      : CommandBase(CmdName)
    {

      setMessage(message);
      setUpdateInterval(updateInterval);
    }

    SetSbasMessageUpdateIntervalPtr SetSbasMessageUpdateInterval::create(int message, int updateInterval)
    {
      return std::make_shared<SetSbasMessageUpdateInterval>(message, updateInterval);
    }

    SetSbasMessageUpdateIntervalPtr SetSbasMessageUpdateInterval::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetSbasMessageUpdateInterval>(ptr);
    }

    bool SetSbasMessageUpdateInterval::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["Message"])
          && parse_json<int>::is_valid(m_values["UpdateInterval"])
        ;

    }

    std::string SetSbasMessageUpdateInterval::documentation() const { return Documentation; }


    int SetSbasMessageUpdateInterval::executePermission() const
    {
      return EXECUTE_IF_IDLE | EXECUTE_IF_SIMULATING;
    }


    int SetSbasMessageUpdateInterval::message() const
    {
      return parse_json<int>::parse(m_values["Message"]);
    }

    void SetSbasMessageUpdateInterval::setMessage(int message)
    {
      m_values.AddMember("Message", parse_json<int>::format(message, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int SetSbasMessageUpdateInterval::updateInterval() const
    {
      return parse_json<int>::parse(m_values["UpdateInterval"]);
    }

    void SetSbasMessageUpdateInterval::setUpdateInterval(int updateInterval)
    {
      m_values.AddMember("UpdateInterval", parse_json<int>::format(updateInterval, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
