
#include "GetNtpServer.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetNtpServer
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetNtpServer::CmdName = "GetNtpServer";
    const char* const GetNtpServer::Documentation = "Get the connection parameters for the NTP Server from which the simulator will get the simulation start time.";
    const char* const GetNtpServer::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(GetNtpServer);
    REGISTER_COMMAND_TO_FACTORY_IMPL(GetNtpServer);


    GetNtpServer::GetNtpServer()
      : CommandBase(CmdName, TargetId)
    {

    }

    GetNtpServerPtr GetNtpServer::create()
    {
      return std::make_shared<GetNtpServer>();
    }

    GetNtpServerPtr GetNtpServer::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetNtpServer>(ptr);
    }

    bool GetNtpServer::isValid() const
    {
      
        return m_values.IsObject()
        ;

    }

    std::string GetNtpServer::documentation() const { return Documentation; }

    const std::vector<std::string>& GetNtpServer::fieldNames() const 
    { 
      static const std::vector<std::string> names {}; 
      return names; 
    }


    int GetNtpServer::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }

  }
}
