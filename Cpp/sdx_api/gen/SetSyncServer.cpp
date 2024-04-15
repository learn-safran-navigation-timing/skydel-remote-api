
#include "SetSyncServer.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetSyncServer
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetSyncServer::CmdName = "SetSyncServer";
    const char* const SetSyncServer::Documentation = "Set listening port for sync time server.\n"
      "\n"
      "Name Type Description\n"
      "---- ---- ---------------------\n"
      "Port int  Listening port number";
    const char* const SetSyncServer::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(SetSyncServer);
    REGISTER_COMMAND_TO_FACTORY_IMPL(SetSyncServer);


    SetSyncServer::SetSyncServer()
      : CommandBase(CmdName, TargetId)
    {}

    SetSyncServer::SetSyncServer(int port)
      : CommandBase(CmdName, TargetId)
    {

      setPort(port);
    }

    SetSyncServerPtr SetSyncServer::create(int port)
    {
      return std::make_shared<SetSyncServer>(port);
    }

    SetSyncServerPtr SetSyncServer::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetSyncServer>(ptr);
    }

    bool SetSyncServer::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["Port"])
        ;

    }

    std::string SetSyncServer::documentation() const { return Documentation; }

    const std::vector<std::string>& SetSyncServer::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Port"}; 
      return names; 
    }


    int SetSyncServer::executePermission() const
    {
      return EXECUTE_IF_NO_CONFIG | EXECUTE_IF_IDLE;
    }


    int SetSyncServer::port() const
    {
      return parse_json<int>::parse(m_values["Port"]);
    }

    void SetSyncServer::setPort(int port)
    {
      m_values.AddMember("Port", parse_json<int>::format(port, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
