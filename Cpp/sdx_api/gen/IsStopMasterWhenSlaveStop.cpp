
#include "IsStopMasterWhenSlaveStop.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of IsStopMasterWhenSlaveStop
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const IsStopMasterWhenSlaveStop::CmdName = "IsStopMasterWhenSlaveStop";
    const char* const IsStopMasterWhenSlaveStop::Documentation = "Please note the command IsStopMasterWhenSlaveStop is deprecated since 23.11. You may use IsStopMainInstanceWhenWorkerInstanceStop.\n"
      "\n"
      "If enabled, master and all the slaves will stop if a slave stop.";
    const char* const IsStopMasterWhenSlaveStop::TargetId = "";

    const char* const IsStopMasterWhenSlaveStop::Deprecated = "Please note the command IsStopMasterWhenSlaveStop is deprecated since 23.11. You may use IsStopMainInstanceWhenWorkerInstanceStop.";

    REGISTER_COMMAND_TO_FACTORY_DECL(IsStopMasterWhenSlaveStop);
    REGISTER_COMMAND_TO_FACTORY_IMPL(IsStopMasterWhenSlaveStop);


    IsStopMasterWhenSlaveStop::IsStopMasterWhenSlaveStop()
      : CommandBase(CmdName, TargetId)
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

    const std::vector<std::string>& IsStopMasterWhenSlaveStop::fieldNames() const 
    { 
      static const std::vector<std::string> names {}; 
      return names; 
    }

    Sdx::optional<std::string> IsStopMasterWhenSlaveStop::deprecated() const { return Sdx::optional<std::string>{Deprecated}; }


    int IsStopMasterWhenSlaveStop::executePermission() const
    {
      return EXECUTE_IF_IDLE | EXECUTE_IF_SIMULATING;
    }

  }
}
