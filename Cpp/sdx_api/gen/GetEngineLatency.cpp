
#include "gen/GetEngineLatency.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetEngineLatency
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetEngineLatency::CmdName = "GetEngineLatency";
    const char* const GetEngineLatency::Documentation = "Get engine latency.";

    REGISTER_COMMAND_FACTORY(GetEngineLatency);


    GetEngineLatency::GetEngineLatency()
      : CommandBase(CmdName)
    {

    }

    GetEngineLatencyPtr GetEngineLatency::create()
    {
      return std::make_shared<GetEngineLatency>();
    }

    GetEngineLatencyPtr GetEngineLatency::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetEngineLatency>(ptr);
    }

    bool GetEngineLatency::isValid() const
    {
      
        return m_values.IsObject()
        ;

    }

    std::string GetEngineLatency::documentation() const { return Documentation; }


    int GetEngineLatency::executePermission() const
    {
      return EXECUTE_IF_NO_CONFIG | EXECUTE_IF_IDLE | EXECUTE_IF_SIMULATING;
    }

  }
}
