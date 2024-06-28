
#include "SetNtpServer.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetNtpServer
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetNtpServer::CmdName = "SetNtpServer";
    const char* const SetNtpServer::Documentation = "Set the connection parameters for the NTP Server from which the simulator will get the simulation start time.\n"
      "\n"
      "Name    Type         Description\n"
      "------- ------------ --------------------------------------------------------------------------------------\n"
      "Address string       IP Address of the NTP server.\n"
      "Port    optional int Port at the specified address to reach the NTP server (optional), default port is 123.";
    const char* const SetNtpServer::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(SetNtpServer);
    REGISTER_COMMAND_TO_FACTORY_IMPL(SetNtpServer);


    SetNtpServer::SetNtpServer()
      : CommandBase(CmdName, TargetId)
    {}

    SetNtpServer::SetNtpServer(const std::string& address, const std::optional<int>& port)
      : CommandBase(CmdName, TargetId)
    {

      setAddress(address);
      setPort(port);
    }

    SetNtpServerPtr SetNtpServer::create(const std::string& address, const std::optional<int>& port)
    {
      return std::make_shared<SetNtpServer>(address, port);
    }

    SetNtpServerPtr SetNtpServer::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetNtpServer>(ptr);
    }

    bool SetNtpServer::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["Address"])
          && parse_json<std::optional<int>>::is_valid(m_values["Port"])
        ;

    }

    std::string SetNtpServer::documentation() const { return Documentation; }

    const std::vector<std::string>& SetNtpServer::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Address", "Port"}; 
      return names; 
    }


    int SetNtpServer::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string SetNtpServer::address() const
    {
      return parse_json<std::string>::parse(m_values["Address"]);
    }

    void SetNtpServer::setAddress(const std::string& address)
    {
      m_values.AddMember("Address", parse_json<std::string>::format(address, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::optional<int> SetNtpServer::port() const
    {
      return parse_json<std::optional<int>>::parse(m_values["Port"]);
    }

    void SetNtpServer::setPort(const std::optional<int>& port)
    {
      m_values.AddMember("Port", parse_json<std::optional<int>>::format(port, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
