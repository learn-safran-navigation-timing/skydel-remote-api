
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
    const char* const IsStopMasterWhenSlaveStop::Documentation = "If enabled, master and all the slaves will stop if a slave stop.";

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


    int IsStopMasterWhenSlaveStop::executePermission() const
    {
      return EXECUTE_IF_IDLE | EXECUTE_IF_SIMULATING;
    }

  }
}
