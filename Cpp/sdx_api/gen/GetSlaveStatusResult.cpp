
#include "gen/GetSlaveStatusResult.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetSlaveStatusResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetSlaveStatusResult::CmdName = "GetSlaveStatusResult";
    const char* const GetSlaveStatusResult::Documentation = "Result of GetSlaveStatus.";

    REGISTER_COMMAND_RESULT_TO_FACTORY_IMPL(GetSlaveStatusResult);


    GetSlaveStatusResult::GetSlaveStatusResult()
      : CommandResult(CmdName)
    {}

    GetSlaveStatusResult::GetSlaveStatusResult(bool isSlave, bool isConnected, const std::string& hostName, int hostPort)
      : CommandResult(CmdName)
    {

      setIsSlave(isSlave);
      setIsConnected(isConnected);
      setHostName(hostName);
      setHostPort(hostPort);
    }

    GetSlaveStatusResult::GetSlaveStatusResult(CommandBasePtr relatedCommand, bool isSlave, bool isConnected, const std::string& hostName, int hostPort)
      : CommandResult(CmdName, relatedCommand)
    {

      setIsSlave(isSlave);
      setIsConnected(isConnected);
      setHostName(hostName);
      setHostPort(hostPort);
    }


    GetSlaveStatusResultPtr GetSlaveStatusResult::create(bool isSlave, bool isConnected, const std::string& hostName, int hostPort)
    {
      return std::make_shared<GetSlaveStatusResult>(isSlave, isConnected, hostName, hostPort);
    }

    GetSlaveStatusResultPtr GetSlaveStatusResult::create(CommandBasePtr relatedCommand, bool isSlave, bool isConnected, const std::string& hostName, int hostPort)
    {
      return std::make_shared<GetSlaveStatusResult>(relatedCommand, isSlave, isConnected, hostName, hostPort);
    }

    GetSlaveStatusResultPtr GetSlaveStatusResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetSlaveStatusResult>(ptr);
    }

    bool GetSlaveStatusResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<bool>::is_valid(m_values["IsSlave"])
          && parse_json<bool>::is_valid(m_values["IsConnected"])
          && parse_json<std::string>::is_valid(m_values["HostName"])
          && parse_json<int>::is_valid(m_values["HostPort"])
        ;

    }

    std::string GetSlaveStatusResult::documentation() const { return Documentation; }


    bool GetSlaveStatusResult::isSlave() const
    {
      return parse_json<bool>::parse(m_values["IsSlave"]);
    }

    void GetSlaveStatusResult::setIsSlave(bool isSlave)
    {
      m_values.AddMember("IsSlave", parse_json<bool>::format(isSlave, m_values.GetAllocator()), m_values.GetAllocator());
    }



    bool GetSlaveStatusResult::isConnected() const
    {
      return parse_json<bool>::parse(m_values["IsConnected"]);
    }

    void GetSlaveStatusResult::setIsConnected(bool isConnected)
    {
      m_values.AddMember("IsConnected", parse_json<bool>::format(isConnected, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string GetSlaveStatusResult::hostName() const
    {
      return parse_json<std::string>::parse(m_values["HostName"]);
    }

    void GetSlaveStatusResult::setHostName(const std::string& hostName)
    {
      m_values.AddMember("HostName", parse_json<std::string>::format(hostName, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int GetSlaveStatusResult::hostPort() const
    {
      return parse_json<int>::parse(m_values["HostPort"]);
    }

    void GetSlaveStatusResult::setHostPort(int hostPort)
    {
      m_values.AddMember("HostPort", parse_json<int>::format(hostPort, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
