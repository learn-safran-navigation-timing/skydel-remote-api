
#include "SetSyncClient.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetSyncClient
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetSyncClient::CmdName = "SetSyncClient";
    const char* const SetSyncClient::Documentation = "Set host and port to connect to sync time server.\n"
      "\n"
      "Name Type   Description\n"
      "---- ------ ----------------\n"
      "Host string Host address\n"
      "Port int    Host port number";
    const char* const SetSyncClient::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(SetSyncClient);
    REGISTER_COMMAND_TO_FACTORY_IMPL(SetSyncClient);


    SetSyncClient::SetSyncClient()
      : CommandBase(CmdName, TargetId)
    {}

    SetSyncClient::SetSyncClient(const std::string& host, int port)
      : CommandBase(CmdName, TargetId)
    {

      setHost(host);
      setPort(port);
    }

    SetSyncClientPtr SetSyncClient::create(const std::string& host, int port)
    {
      return std::make_shared<SetSyncClient>(host, port);
    }

    SetSyncClientPtr SetSyncClient::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetSyncClient>(ptr);
    }

    bool SetSyncClient::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["Host"])
          && parse_json<int>::is_valid(m_values["Port"])
        ;

    }

    std::string SetSyncClient::documentation() const { return Documentation; }

    const std::vector<std::string>& SetSyncClient::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Host", "Port"}; 
      return names; 
    }


    int SetSyncClient::executePermission() const
    {
      return EXECUTE_IF_NO_CONFIG | EXECUTE_IF_IDLE;
    }


    std::string SetSyncClient::host() const
    {
      return parse_json<std::string>::parse(m_values["Host"]);
    }

    void SetSyncClient::setHost(const std::string& host)
    {
      m_values.AddMember("Host", parse_json<std::string>::format(host, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int SetSyncClient::port() const
    {
      return parse_json<int>::parse(m_values["Port"]);
    }

    void SetSyncClient::setPort(int port)
    {
      m_values.AddMember("Port", parse_json<int>::format(port, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
