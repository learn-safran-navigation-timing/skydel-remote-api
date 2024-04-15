
#include "StopMainInstanceWhenWorkerInstanceStop.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of StopMainInstanceWhenWorkerInstanceStop
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const StopMainInstanceWhenWorkerInstanceStop::CmdName = "StopMainInstanceWhenWorkerInstanceStop";
    const char* const StopMainInstanceWhenWorkerInstanceStop::Documentation = "If enabled, main instance and all the worker instances will stop if a worker instance stops.\n"
      "\n"
      "Name    Type Description\n"
      "------- ---- ---------------------------------------------------------\n"
      "Enabled bool Enable main instance stop when worker instance stops flag";
    const char* const StopMainInstanceWhenWorkerInstanceStop::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(StopMainInstanceWhenWorkerInstanceStop);
    REGISTER_COMMAND_TO_FACTORY_IMPL(StopMainInstanceWhenWorkerInstanceStop);


    StopMainInstanceWhenWorkerInstanceStop::StopMainInstanceWhenWorkerInstanceStop()
      : CommandBase(CmdName, TargetId)
    {}

    StopMainInstanceWhenWorkerInstanceStop::StopMainInstanceWhenWorkerInstanceStop(bool enabled)
      : CommandBase(CmdName, TargetId)
    {

      setEnabled(enabled);
    }

    StopMainInstanceWhenWorkerInstanceStopPtr StopMainInstanceWhenWorkerInstanceStop::create(bool enabled)
    {
      return std::make_shared<StopMainInstanceWhenWorkerInstanceStop>(enabled);
    }

    StopMainInstanceWhenWorkerInstanceStopPtr StopMainInstanceWhenWorkerInstanceStop::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<StopMainInstanceWhenWorkerInstanceStop>(ptr);
    }

    bool StopMainInstanceWhenWorkerInstanceStop::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<bool>::is_valid(m_values["Enabled"])
        ;

    }

    std::string StopMainInstanceWhenWorkerInstanceStop::documentation() const { return Documentation; }

    const std::vector<std::string>& StopMainInstanceWhenWorkerInstanceStop::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Enabled"}; 
      return names; 
    }


    int StopMainInstanceWhenWorkerInstanceStop::executePermission() const
    {
      return EXECUTE_IF_NO_CONFIG | EXECUTE_IF_IDLE | EXECUTE_IF_SIMULATING;
    }


    bool StopMainInstanceWhenWorkerInstanceStop::enabled() const
    {
      return parse_json<bool>::parse(m_values["Enabled"]);
    }

    void StopMainInstanceWhenWorkerInstanceStop::setEnabled(bool enabled)
    {
      m_values.AddMember("Enabled", parse_json<bool>::format(enabled, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
