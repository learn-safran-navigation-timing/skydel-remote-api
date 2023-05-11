
#include "gen/GetSbasMessageUpdateInterval.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetSbasMessageUpdateInterval
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetSbasMessageUpdateInterval::CmdName = "GetSbasMessageUpdateInterval";
    const char* const GetSbasMessageUpdateInterval::Documentation = "Get the SBAS message update interval.";

    REGISTER_COMMAND_FACTORY(GetSbasMessageUpdateInterval);


    GetSbasMessageUpdateInterval::GetSbasMessageUpdateInterval()
      : CommandBase(CmdName)
    {}

    GetSbasMessageUpdateInterval::GetSbasMessageUpdateInterval(int message)
      : CommandBase(CmdName)
    {

      setMessage(message);
    }

    GetSbasMessageUpdateIntervalPtr GetSbasMessageUpdateInterval::create(int message)
    {
      return std::make_shared<GetSbasMessageUpdateInterval>(message);
    }

    GetSbasMessageUpdateIntervalPtr GetSbasMessageUpdateInterval::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetSbasMessageUpdateInterval>(ptr);
    }

    bool GetSbasMessageUpdateInterval::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["Message"])
        ;

    }

    std::string GetSbasMessageUpdateInterval::documentation() const { return Documentation; }


    int GetSbasMessageUpdateInterval::executePermission() const
    {
      return EXECUTE_IF_IDLE | EXECUTE_IF_SIMULATING;
    }


    int GetSbasMessageUpdateInterval::message() const
    {
      return parse_json<int>::parse(m_values["Message"]);
    }

    void GetSbasMessageUpdateInterval::setMessage(int message)
    {
      m_values.AddMember("Message", parse_json<int>::format(message, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
