
#include "gen/SetEngineLatency.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetEngineLatency
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetEngineLatency::CmdName = "SetEngineLatency";
    const char* const SetEngineLatency::Documentation = "Set engine latency.";

    REGISTER_COMMAND_FACTORY(SetEngineLatency);


    SetEngineLatency::SetEngineLatency()
      : CommandBase(CmdName)
    {}

    SetEngineLatency::SetEngineLatency(int latency)
      : CommandBase(CmdName)
    {

      setLatency(latency);
    }

    SetEngineLatencyPtr SetEngineLatency::create(int latency)
    {
      return std::make_shared<SetEngineLatency>(latency);
    }

    SetEngineLatencyPtr SetEngineLatency::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetEngineLatency>(ptr);
    }

    bool SetEngineLatency::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["Latency"])
        ;

    }

    std::string SetEngineLatency::documentation() const { return Documentation; }


    int SetEngineLatency::executePermission() const
    {
      return EXECUTE_IF_NO_CONFIG | EXECUTE_IF_IDLE;
    }


    int SetEngineLatency::latency() const
    {
      return parse_json<int>::parse(m_values["Latency"]);
    }

    void SetEngineLatency::setLatency(int latency)
    {
      m_values.AddMember("Latency", parse_json<int>::format(latency, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
