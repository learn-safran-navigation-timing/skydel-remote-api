
#include "GetSbasMessageUpdateIntervalResult.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetSbasMessageUpdateIntervalResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetSbasMessageUpdateIntervalResult::CmdName = "GetSbasMessageUpdateIntervalResult";
    const char* const GetSbasMessageUpdateIntervalResult::Documentation = "Result of GetSbasMessageUpdateInterval.\n"
      "\n"
      "Name            Type            Description\n"
      "--------------- --------------- ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n"
      "Message         int             The message type.\n"
      "UpdateInterval  int             The message update interval in seconds. Accepted range is [1..300].\n"
      "ServiceProvider optional string The service provider. When not specified for a Setter command, the change is applied to all service providers. When not specified for a Getter command, the value for WAAS is returned.";
    const char* const GetSbasMessageUpdateIntervalResult::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_IMPL(GetSbasMessageUpdateIntervalResult);


    GetSbasMessageUpdateIntervalResult::GetSbasMessageUpdateIntervalResult()
      : CommandResult(CmdName, TargetId)
    {}

    GetSbasMessageUpdateIntervalResult::GetSbasMessageUpdateIntervalResult(int message, int updateInterval, const std::optional<std::string>& serviceProvider)
      : CommandResult(CmdName, TargetId)
    {

      setMessage(message);
      setUpdateInterval(updateInterval);
      setServiceProvider(serviceProvider);
    }

    GetSbasMessageUpdateIntervalResult::GetSbasMessageUpdateIntervalResult(CommandBasePtr relatedCommand, int message, int updateInterval, const std::optional<std::string>& serviceProvider)
      : CommandResult(CmdName, TargetId, relatedCommand)
    {

      setMessage(message);
      setUpdateInterval(updateInterval);
      setServiceProvider(serviceProvider);
    }


    GetSbasMessageUpdateIntervalResultPtr GetSbasMessageUpdateIntervalResult::create(int message, int updateInterval, const std::optional<std::string>& serviceProvider)
    {
      return std::make_shared<GetSbasMessageUpdateIntervalResult>(message, updateInterval, serviceProvider);
    }

    GetSbasMessageUpdateIntervalResultPtr GetSbasMessageUpdateIntervalResult::create(CommandBasePtr relatedCommand, int message, int updateInterval, const std::optional<std::string>& serviceProvider)
    {
      return std::make_shared<GetSbasMessageUpdateIntervalResult>(relatedCommand, message, updateInterval, serviceProvider);
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
          && parse_json<std::optional<std::string>>::is_valid(m_values["ServiceProvider"])
        ;

    }

    std::string GetSbasMessageUpdateIntervalResult::documentation() const { return Documentation; }

    const std::vector<std::string>& GetSbasMessageUpdateIntervalResult::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Message", "UpdateInterval", "ServiceProvider"}; 
      return names; 
    }


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



    std::optional<std::string> GetSbasMessageUpdateIntervalResult::serviceProvider() const
    {
      return parse_json<std::optional<std::string>>::parse(m_values["ServiceProvider"]);
    }

    void GetSbasMessageUpdateIntervalResult::setServiceProvider(const std::optional<std::string>& serviceProvider)
    {
      m_values.AddMember("ServiceProvider", parse_json<std::optional<std::string>>::format(serviceProvider, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
