
#include "IsStopMainInstanceWhenWorkerInstanceStop.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of IsStopMainInstanceWhenWorkerInstanceStop
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const IsStopMainInstanceWhenWorkerInstanceStop::CmdName = "IsStopMainInstanceWhenWorkerInstanceStop";
    const char* const IsStopMainInstanceWhenWorkerInstanceStop::Documentation = "If enabled, main instance and all the worker instances will stop if a worker instance stops.";
    const char* const IsStopMainInstanceWhenWorkerInstanceStop::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(IsStopMainInstanceWhenWorkerInstanceStop);
    REGISTER_COMMAND_TO_FACTORY_IMPL(IsStopMainInstanceWhenWorkerInstanceStop);


    IsStopMainInstanceWhenWorkerInstanceStop::IsStopMainInstanceWhenWorkerInstanceStop()
      : CommandBase(CmdName, TargetId)
    {

    }

    IsStopMainInstanceWhenWorkerInstanceStopPtr IsStopMainInstanceWhenWorkerInstanceStop::create()
    {
      return std::make_shared<IsStopMainInstanceWhenWorkerInstanceStop>();
    }

    IsStopMainInstanceWhenWorkerInstanceStopPtr IsStopMainInstanceWhenWorkerInstanceStop::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<IsStopMainInstanceWhenWorkerInstanceStop>(ptr);
    }

    bool IsStopMainInstanceWhenWorkerInstanceStop::isValid() const
    {
      
        return m_values.IsObject()
        ;

    }

    std::string IsStopMainInstanceWhenWorkerInstanceStop::documentation() const { return Documentation; }

    const std::vector<std::string>& IsStopMainInstanceWhenWorkerInstanceStop::fieldNames() const 
    { 
      static const std::vector<std::string> names {}; 
      return names; 
    }


    int IsStopMainInstanceWhenWorkerInstanceStop::executePermission() const
    {
      return EXECUTE_IF_IDLE | EXECUTE_IF_SIMULATING;
    }

  }
}
