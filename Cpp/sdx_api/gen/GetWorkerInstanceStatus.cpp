
#include "GetWorkerInstanceStatus.h"

#include "command_factory.h"
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
    const char* const GetWorkerInstanceStatus::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(GetWorkerInstanceStatus);
    REGISTER_COMMAND_TO_FACTORY_IMPL(GetWorkerInstanceStatus);


    GetWorkerInstanceStatus::GetWorkerInstanceStatus()
      : CommandBase(CmdName, TargetId)
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

    const std::vector<std::string>& GetWorkerInstanceStatus::fieldNames() const 
    { 
      static const std::vector<std::string> names {}; 
      return names; 
    }


    int GetWorkerInstanceStatus::executePermission() const
    {
      return EXECUTE_IF_IDLE | EXECUTE_IF_SIMULATING;
    }

  }
}
