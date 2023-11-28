
#include "gen/GetMainInstanceStatus.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetMainInstanceStatus
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetMainInstanceStatus::CmdName = "GetMainInstanceStatus";
    const char* const GetMainInstanceStatus::Documentation = "Request for the main instance status, returns a GetMainInstanceStatusResult";

    REGISTER_COMMAND_FACTORY(GetMainInstanceStatus);


    GetMainInstanceStatus::GetMainInstanceStatus()
      : CommandBase(CmdName)
    {

    }

    GetMainInstanceStatusPtr GetMainInstanceStatus::create()
    {
      return std::make_shared<GetMainInstanceStatus>();
    }

    GetMainInstanceStatusPtr GetMainInstanceStatus::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetMainInstanceStatus>(ptr);
    }

    bool GetMainInstanceStatus::isValid() const
    {
      
        return m_values.IsObject()
        ;

    }

    std::string GetMainInstanceStatus::documentation() const { return Documentation; }


    int GetMainInstanceStatus::executePermission() const
    {
      return EXECUTE_IF_IDLE | EXECUTE_IF_SIMULATING;
    }

  }
}
