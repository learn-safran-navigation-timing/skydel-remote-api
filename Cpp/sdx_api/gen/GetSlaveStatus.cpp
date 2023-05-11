
#include "gen/GetSlaveStatus.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetSlaveStatus
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetSlaveStatus::CmdName = "GetSlaveStatus";
    const char* const GetSlaveStatus::Documentation = "Request for the slave status, returns a GetSlaveStatusResult";

    REGISTER_COMMAND_FACTORY(GetSlaveStatus);


    GetSlaveStatus::GetSlaveStatus()
      : CommandBase(CmdName)
    {

    }

    GetSlaveStatusPtr GetSlaveStatus::create()
    {
      return std::make_shared<GetSlaveStatus>();
    }

    GetSlaveStatusPtr GetSlaveStatus::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetSlaveStatus>(ptr);
    }

    bool GetSlaveStatus::isValid() const
    {
      
        return m_values.IsObject()
        ;

    }

    std::string GetSlaveStatus::documentation() const { return Documentation; }


    int GetSlaveStatus::executePermission() const
    {
      return EXECUTE_IF_IDLE | EXECUTE_IF_SIMULATING;
    }

  }
}
