
#include "gen/GetMasterStatus.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetMasterStatus
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetMasterStatus::CmdName = "GetMasterStatus";
    const char* const GetMasterStatus::Documentation = "Please note the command GetMasterStatus is deprecated since 23.11. You may use GetMainInstanceStatus.\n\nRequest for the master status, returns a GetMasterStatusResult";

    const char* const GetMasterStatus::Deprecated = "Please note the command GetMasterStatus is deprecated since 23.11. You may use GetMainInstanceStatus.";

    REGISTER_COMMAND_FACTORY(GetMasterStatus);


    GetMasterStatus::GetMasterStatus()
      : CommandBase(CmdName)
    {

    }

    GetMasterStatusPtr GetMasterStatus::create()
    {
      return std::make_shared<GetMasterStatus>();
    }

    GetMasterStatusPtr GetMasterStatus::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetMasterStatus>(ptr);
    }

    bool GetMasterStatus::isValid() const
    {
      
        return m_values.IsObject()
        ;

    }

    std::string GetMasterStatus::documentation() const { return Documentation; }

    Sdx::optional<std::string> GetMasterStatus::deprecated() const { return Sdx::optional<std::string>{Deprecated}; }


    int GetMasterStatus::executePermission() const
    {
      return EXECUTE_IF_IDLE | EXECUTE_IF_SIMULATING;
    }

  }
}
