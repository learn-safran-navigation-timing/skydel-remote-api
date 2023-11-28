
#include "gen/StopMasterWhenSlaveStop.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of StopMasterWhenSlaveStop
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const StopMasterWhenSlaveStop::CmdName = "StopMasterWhenSlaveStop";
    const char* const StopMasterWhenSlaveStop::Documentation = "Please note the command StopMasterWhenSlaveStop is deprecated since 23.11. You may use StopMainInstanceWhenWorkerInstanceStop.\n\nIf enabled, master and all the slaves will stop if a slave stop.";

    const char* const StopMasterWhenSlaveStop::Deprecated = "Please note the command StopMasterWhenSlaveStop is deprecated since 23.11. You may use StopMainInstanceWhenWorkerInstanceStop.";

    REGISTER_COMMAND_FACTORY(StopMasterWhenSlaveStop);


    StopMasterWhenSlaveStop::StopMasterWhenSlaveStop()
      : CommandBase(CmdName)
    {}

    StopMasterWhenSlaveStop::StopMasterWhenSlaveStop(bool enabled)
      : CommandBase(CmdName)
    {

      setEnabled(enabled);
    }

    StopMasterWhenSlaveStopPtr StopMasterWhenSlaveStop::create(bool enabled)
    {
      return std::make_shared<StopMasterWhenSlaveStop>(enabled);
    }

    StopMasterWhenSlaveStopPtr StopMasterWhenSlaveStop::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<StopMasterWhenSlaveStop>(ptr);
    }

    bool StopMasterWhenSlaveStop::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<bool>::is_valid(m_values["Enabled"])
        ;

    }

    std::string StopMasterWhenSlaveStop::documentation() const { return Documentation; }

    Sdx::optional<std::string> StopMasterWhenSlaveStop::deprecated() const { return Sdx::optional<std::string>{Deprecated}; }


    int StopMasterWhenSlaveStop::executePermission() const
    {
      return EXECUTE_IF_NO_CONFIG | EXECUTE_IF_IDLE | EXECUTE_IF_SIMULATING;
    }


    bool StopMasterWhenSlaveStop::enabled() const
    {
      return parse_json<bool>::parse(m_values["Enabled"]);
    }

    void StopMasterWhenSlaveStop::setEnabled(bool enabled)
    {
      m_values.AddMember("Enabled", parse_json<bool>::format(enabled, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
