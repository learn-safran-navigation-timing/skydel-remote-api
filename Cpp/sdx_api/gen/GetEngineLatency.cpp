
#include "GetEngineLatency.h"

#include "command_factory.h"
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
    const char* const GetEngineLatency::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(GetEngineLatency);
    REGISTER_COMMAND_TO_FACTORY_IMPL(GetEngineLatency);


    GetEngineLatency::GetEngineLatency()
      : CommandBase(CmdName, TargetId)
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

    const std::vector<std::string>& GetEngineLatency::fieldNames() const 
    { 
      static const std::vector<std::string> names {}; 
      return names; 
    }


    int GetEngineLatency::executePermission() const
    {
      return EXECUTE_IF_NO_CONFIG | EXECUTE_IF_IDLE | EXECUTE_IF_SIMULATING;
    }

  }
}
