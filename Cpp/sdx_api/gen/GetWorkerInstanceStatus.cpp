
#include "gen/GetWorkerInstanceStatus.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetWorkerInstanceStatus
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetWorkerInstanceStatus::CmdName = "GetWorkerInstanceStatus";
    const char* const GetWorkerInstanceStatus::Documentation = "Request for the worker instance status, returns a GetWorkerInstanceStatusResult";

    REGISTER_COMMAND_FACTORY(GetWorkerInstanceStatus);


    GetWorkerInstanceStatus::GetWorkerInstanceStatus()
      : CommandBase(CmdName)
    {

    }

    GetWorkerInstanceStatusPtr GetWorkerInstanceStatus::create()
    {
      return std::make_shared<GetWorkerInstanceStatus>();
    }

    GetWorkerInstanceStatusPtr GetWorkerInstanceStatus::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetWorkerInstanceStatus>(ptr);
    }

    bool GetWorkerInstanceStatus::isValid() const
    {
      
        return m_values.IsObject()
        ;

    }

    std::string GetWorkerInstanceStatus::documentation() const { return Documentation; }


    int GetWorkerInstanceStatus::executePermission() const
    {
      return EXECUTE_IF_IDLE | EXECUTE_IF_SIMULATING;
    }

  }
}
