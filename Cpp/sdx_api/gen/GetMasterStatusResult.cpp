
#include "GetMasterStatusResult.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetMasterStatusResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetMasterStatusResult::CmdName = "GetMasterStatusResult";
    const char* const GetMasterStatusResult::Documentation = "Result of GetMasterStatus.\n"
      "\n"
      "Name           Type Description\n"
      "-------------- ---- -------------------------------------\n"
      "IsMaster       bool True if Skydel is in master mode\n"
      "SlaveConnected int  The number of connected slaves\n"
      "Port           int  The listening port, 0 if not a master";
    const char* const GetMasterStatusResult::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_IMPL(GetMasterStatusResult);


    GetMasterStatusResult::GetMasterStatusResult()
      : CommandResult(CmdName, TargetId)
    {}

    GetMasterStatusResult::GetMasterStatusResult(bool isMaster, int slaveConnected, int port)
      : CommandResult(CmdName, TargetId)
    {

      setIsMaster(isMaster);
      setSlaveConnected(slaveConnected);
      setPort(port);
    }

    GetMasterStatusResult::GetMasterStatusResult(CommandBasePtr relatedCommand, bool isMaster, int slaveConnected, int port)
      : CommandResult(CmdName, TargetId, relatedCommand)
    {

      setIsMaster(isMaster);
      setSlaveConnected(slaveConnected);
      setPort(port);
    }


    GetMasterStatusResultPtr GetMasterStatusResult::create(bool isMaster, int slaveConnected, int port)
    {
      return std::make_shared<GetMasterStatusResult>(isMaster, slaveConnected, port);
    }

    GetMasterStatusResultPtr GetMasterStatusResult::create(CommandBasePtr relatedCommand, bool isMaster, int slaveConnected, int port)
    {
      return std::make_shared<GetMasterStatusResult>(relatedCommand, isMaster, slaveConnected, port);
    }

    GetMasterStatusResultPtr GetMasterStatusResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetMasterStatusResult>(ptr);
    }

    bool GetMasterStatusResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<bool>::is_valid(m_values["IsMaster"])
          && parse_json<int>::is_valid(m_values["SlaveConnected"])
          && parse_json<int>::is_valid(m_values["Port"])
        ;

    }

    std::string GetMasterStatusResult::documentation() const { return Documentation; }

    const std::vector<std::string>& GetMasterStatusResult::fieldNames() const 
    { 
      static const std::vector<std::string> names {"IsMaster", "SlaveConnected", "Port"}; 
      return names; 
    }


    bool GetMasterStatusResult::isMaster() const
    {
      return parse_json<bool>::parse(m_values["IsMaster"]);
    }

    void GetMasterStatusResult::setIsMaster(bool isMaster)
    {
      m_values.AddMember("IsMaster", parse_json<bool>::format(isMaster, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int GetMasterStatusResult::slaveConnected() const
    {
      return parse_json<int>::parse(m_values["SlaveConnected"]);
    }

    void GetMasterStatusResult::setSlaveConnected(int slaveConnected)
    {
      m_values.AddMember("SlaveConnected", parse_json<int>::format(slaveConnected, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int GetMasterStatusResult::port() const
    {
      return parse_json<int>::parse(m_values["Port"]);
    }

    void GetMasterStatusResult::setPort(int port)
    {
      m_values.AddMember("Port", parse_json<int>::format(port, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
