
#include "SetEngineLatency.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetEngineLatency
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetEngineLatency::CmdName = "SetEngineLatency";
    const char* const SetEngineLatency::Documentation = "Set engine latency.\n"
      "\n"
      "Name    Type Description\n"
      "------- ---- ----------------------\n"
      "Latency int  Engine latency in msec";
    const char* const SetEngineLatency::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(SetEngineLatency);
    REGISTER_COMMAND_TO_FACTORY_IMPL(SetEngineLatency);


    SetEngineLatency::SetEngineLatency()
      : CommandBase(CmdName, TargetId)
    {}

    SetEngineLatency::SetEngineLatency(int latency)
      : CommandBase(CmdName, TargetId)
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

    const std::vector<std::string>& SetEngineLatency::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Latency"}; 
      return names; 
    }


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
