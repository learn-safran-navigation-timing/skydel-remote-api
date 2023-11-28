
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
    const char* const GetSlaveStatus::Documentation = "Please note the command GetSlaveStatus is deprecated since 23.11. You may use GetWorkerInstanceStatus.\n\nRequest for the slave status, returns a GetSlaveStatusResult";

    const char* const GetSlaveStatus::Deprecated = "Please note the command GetSlaveStatus is deprecated since 23.11. You may use GetWorkerInstanceStatus.";

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

    Sdx::optional<std::string> GetSlaveStatus::deprecated() const { return Sdx::optional<std::string>{Deprecated}; }


    int GetSlaveStatus::executePermission() const
    {
      return EXECUTE_IF_IDLE | EXECUTE_IF_SIMULATING;
    }

  }
}
