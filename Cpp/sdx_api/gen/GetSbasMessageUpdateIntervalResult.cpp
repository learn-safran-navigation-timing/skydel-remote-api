
#include "gen/GetSbasMessageUpdateIntervalResult.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetSbasMessageUpdateIntervalResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetSbasMessageUpdateIntervalResult::CmdName = "GetSbasMessageUpdateIntervalResult";
    const char* const GetSbasMessageUpdateIntervalResult::Documentation = "Result of GetSbasMessageUpdateInterval.";

    REGISTER_COMMAND_RESULT_TO_FACTORY_IMPL(GetSbasMessageUpdateIntervalResult);


    GetSbasMessageUpdateIntervalResult::GetSbasMessageUpdateIntervalResult()
      : CommandResult(CmdName)
    {}

    GetSbasMessageUpdateIntervalResult::GetSbasMessageUpdateIntervalResult(int message, int updateInterval)
      : CommandResult(CmdName)
    {

      setMessage(message);
      setUpdateInterval(updateInterval);
    }

    GetSbasMessageUpdateIntervalResult::GetSbasMessageUpdateIntervalResult(CommandBasePtr relatedCommand, int message, int updateInterval)
      : CommandResult(CmdName, relatedCommand)
    {

      setMessage(message);
      setUpdateInterval(updateInterval);
    }


    GetSbasMessageUpdateIntervalResultPtr GetSbasMessageUpdateIntervalResult::create(int message, int updateInterval)
    {
      return std::make_shared<GetSbasMessageUpdateIntervalResult>(message, updateInterval);
    }

    GetSbasMessageUpdateIntervalResultPtr GetSbasMessageUpdateIntervalResult::create(CommandBasePtr relatedCommand, int message, int updateInterval)
    {
      return std::make_shared<GetSbasMessageUpdateIntervalResult>(relatedCommand, message, updateInterval);
    }

    GetSbasMessageUpdateIntervalResultPtr GetSbasMessageUpdateIntervalResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetSbasMessageUpdateIntervalResult>(ptr);
    }

    bool GetSbasMessageUpdateIntervalResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["Message"])
          && parse_json<int>::is_valid(m_values["UpdateInterval"])
        ;

    }

    std::string GetSbasMessageUpdateIntervalResult::documentation() const { return Documentation; }


    int GetSbasMessageUpdateIntervalResult::message() const
    {
      return parse_json<int>::parse(m_values["Message"]);
    }

    void GetSbasMessageUpdateIntervalResult::setMessage(int message)
    {
      m_values.AddMember("Message", parse_json<int>::format(message, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int GetSbasMessageUpdateIntervalResult::updateInterval() const
    {
      return parse_json<int>::parse(m_values["UpdateInterval"]);
    }

    void GetSbasMessageUpdateIntervalResult::setUpdateInterval(int updateInterval)
    {
      m_values.AddMember("UpdateInterval", parse_json<int>::format(updateInterval, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
