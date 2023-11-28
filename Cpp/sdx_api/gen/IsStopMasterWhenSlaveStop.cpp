
#include "gen/IsStopMasterWhenSlaveStop.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of IsStopMasterWhenSlaveStop
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const IsStopMasterWhenSlaveStop::CmdName = "IsStopMasterWhenSlaveStop";
    const char* const IsStopMasterWhenSlaveStop::Documentation = "Please note the command IsStopMasterWhenSlaveStop is deprecated since 23.11. You may use IsStopMainInstanceWhenWorkerInstanceStop.\n\nIf enabled, master and all the slaves will stop if a slave stop.";

    const char* const IsStopMasterWhenSlaveStop::Deprecated = "Please note the command IsStopMasterWhenSlaveStop is deprecated since 23.11. You may use IsStopMainInstanceWhenWorkerInstanceStop.";

    REGISTER_COMMAND_FACTORY(IsStopMasterWhenSlaveStop);


    IsStopMasterWhenSlaveStop::IsStopMasterWhenSlaveStop()
      : CommandBase(CmdName)
    {

    }

    IsStopMasterWhenSlaveStopPtr IsStopMasterWhenSlaveStop::create()
    {
      return std::make_shared<IsStopMasterWhenSlaveStop>();
    }

    IsStopMasterWhenSlaveStopPtr IsStopMasterWhenSlaveStop::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<IsStopMasterWhenSlaveStop>(ptr);
    }

    bool IsStopMasterWhenSlaveStop::isValid() const
    {
      
        return m_values.IsObject()
        ;

    }

    std::string IsStopMasterWhenSlaveStop::documentation() const { return Documentation; }

    Sdx::optional<std::string> IsStopMasterWhenSlaveStop::deprecated() const { return Sdx::optional<std::string>{Deprecated}; }


    int IsStopMasterWhenSlaveStop::executePermission() const
    {
      return EXECUTE_IF_IDLE | EXECUTE_IF_SIMULATING;
    }

  }
}
