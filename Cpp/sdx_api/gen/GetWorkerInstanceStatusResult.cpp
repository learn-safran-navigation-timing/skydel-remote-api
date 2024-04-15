
#include "GetWorkerInstanceStatusResult.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetWorkerInstanceStatusResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetWorkerInstanceStatusResult::CmdName = "GetWorkerInstanceStatusResult";
    const char* const GetWorkerInstanceStatusResult::Documentation = "Result of GetWorkerInstanceStatus.\n"
      "\n"
      "Name             Type   Description\n"
      "---------------- ------ ----------------------------------------------\n"
      "IsWorkerInstance bool   True if Skydel is in worker instance mode\n"
      "IsConnected      bool   True if Skydel is connected to a main instance\n"
      "HostName         string The host name, empty if not a worker instance\n"
      "HostPort         int    The host port, 0 if not a worker instance";
    const char* const GetWorkerInstanceStatusResult::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_IMPL(GetWorkerInstanceStatusResult);


    GetWorkerInstanceStatusResult::GetWorkerInstanceStatusResult()
      : CommandResult(CmdName, TargetId)
    {}

    GetWorkerInstanceStatusResult::GetWorkerInstanceStatusResult(bool isWorkerInstance, bool isConnected, const std::string& hostName, int hostPort)
      : CommandResult(CmdName, TargetId)
    {

      setIsWorkerInstance(isWorkerInstance);
      setIsConnected(isConnected);
      setHostName(hostName);
      setHostPort(hostPort);
    }

    GetWorkerInstanceStatusResult::GetWorkerInstanceStatusResult(CommandBasePtr relatedCommand, bool isWorkerInstance, bool isConnected, const std::string& hostName, int hostPort)
      : CommandResult(CmdName, TargetId, relatedCommand)
    {

      setIsWorkerInstance(isWorkerInstance);
      setIsConnected(isConnected);
      setHostName(hostName);
      setHostPort(hostPort);
    }


    GetWorkerInstanceStatusResultPtr GetWorkerInstanceStatusResult::create(bool isWorkerInstance, bool isConnected, const std::string& hostName, int hostPort)
    {
      return std::make_shared<GetWorkerInstanceStatusResult>(isWorkerInstance, isConnected, hostName, hostPort);
    }

    GetWorkerInstanceStatusResultPtr GetWorkerInstanceStatusResult::create(CommandBasePtr relatedCommand, bool isWorkerInstance, bool isConnected, const std::string& hostName, int hostPort)
    {
      return std::make_shared<GetWorkerInstanceStatusResult>(relatedCommand, isWorkerInstance, isConnected, hostName, hostPort);
    }

    GetWorkerInstanceStatusResultPtr GetWorkerInstanceStatusResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetWorkerInstanceStatusResult>(ptr);
    }

    bool GetWorkerInstanceStatusResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<bool>::is_valid(m_values["IsWorkerInstance"])
          && parse_json<bool>::is_valid(m_values["IsConnected"])
          && parse_json<std::string>::is_valid(m_values["HostName"])
          && parse_json<int>::is_valid(m_values["HostPort"])
        ;

    }

    std::string GetWorkerInstanceStatusResult::documentation() const { return Documentation; }

    const std::vector<std::string>& GetWorkerInstanceStatusResult::fieldNames() const 
    { 
      static const std::vector<std::string> names {"IsWorkerInstance", "IsConnected", "HostName", "HostPort"}; 
      return names; 
    }


    bool GetWorkerInstanceStatusResult::isWorkerInstance() const
    {
      return parse_json<bool>::parse(m_values["IsWorkerInstance"]);
    }

    void GetWorkerInstanceStatusResult::setIsWorkerInstance(bool isWorkerInstance)
    {
      m_values.AddMember("IsWorkerInstance", parse_json<bool>::format(isWorkerInstance, m_values.GetAllocator()), m_values.GetAllocator());
    }



    bool GetWorkerInstanceStatusResult::isConnected() const
    {
      return parse_json<bool>::parse(m_values["IsConnected"]);
    }

    void GetWorkerInstanceStatusResult::setIsConnected(bool isConnected)
    {
      m_values.AddMember("IsConnected", parse_json<bool>::format(isConnected, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string GetWorkerInstanceStatusResult::hostName() const
    {
      return parse_json<std::string>::parse(m_values["HostName"]);
    }

    void GetWorkerInstanceStatusResult::setHostName(const std::string& hostName)
    {
      m_values.AddMember("HostName", parse_json<std::string>::format(hostName, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int GetWorkerInstanceStatusResult::hostPort() const
    {
      return parse_json<int>::parse(m_values["HostPort"]);
    }

    void GetWorkerInstanceStatusResult::setHostPort(int hostPort)
    {
      m_values.AddMember("HostPort", parse_json<int>::format(hostPort, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
