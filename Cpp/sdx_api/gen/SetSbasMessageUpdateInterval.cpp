
#include "SetSbasMessageUpdateInterval.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetSbasMessageUpdateInterval
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetSbasMessageUpdateInterval::CmdName = "SetSbasMessageUpdateInterval";
    const char* const SetSbasMessageUpdateInterval::Documentation = "Set the SBAS message update interval.\n"
      "\n"
      "Name            Type            Description\n"
      "--------------- --------------- ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n"
      "Message         int             The message type.\n"
      "UpdateInterval  int             The message update interval in seconds. Accepted range is [1..300].\n"
      "ServiceProvider optional string The service provider. When not specified for a Setter command, the change is applied to all service providers. When not specified for a Getter command, the value for WAAS is returned.";
    const char* const SetSbasMessageUpdateInterval::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(SetSbasMessageUpdateInterval);
    REGISTER_COMMAND_TO_FACTORY_IMPL(SetSbasMessageUpdateInterval);


    SetSbasMessageUpdateInterval::SetSbasMessageUpdateInterval()
      : CommandBase(CmdName, TargetId)
    {}

    SetSbasMessageUpdateInterval::SetSbasMessageUpdateInterval(int message, int updateInterval, const std::optional<std::string>& serviceProvider)
      : CommandBase(CmdName, TargetId)
    {

      setMessage(message);
      setUpdateInterval(updateInterval);
      setServiceProvider(serviceProvider);
    }

    SetSbasMessageUpdateIntervalPtr SetSbasMessageUpdateInterval::create(int message, int updateInterval, const std::optional<std::string>& serviceProvider)
    {
      return std::make_shared<SetSbasMessageUpdateInterval>(message, updateInterval, serviceProvider);
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
          && parse_json<std::optional<std::string>>::is_valid(m_values["ServiceProvider"])
        ;

    }

    std::string SetSbasMessageUpdateInterval::documentation() const { return Documentation; }

    const std::vector<std::string>& SetSbasMessageUpdateInterval::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Message", "UpdateInterval", "ServiceProvider"}; 
      return names; 
    }


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



    std::optional<std::string> SetSbasMessageUpdateInterval::serviceProvider() const
    {
      return parse_json<std::optional<std::string>>::parse(m_values["ServiceProvider"]);
    }

    void SetSbasMessageUpdateInterval::setServiceProvider(const std::optional<std::string>& serviceProvider)
    {
      m_values.AddMember("ServiceProvider", parse_json<std::optional<std::string>>::format(serviceProvider, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
