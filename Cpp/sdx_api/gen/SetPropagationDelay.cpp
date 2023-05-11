
#include "gen/SetPropagationDelay.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetPropagationDelay
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetPropagationDelay::CmdName = "SetPropagationDelay";
    const char* const SetPropagationDelay::Documentation = "Enable (or disable) the satellite signal propagation delay. If disabled, the signal is immediately received\nby the receiver. The delay should always be enabled, unless your are doing a PPS calibration for the simulator.";

    REGISTER_COMMAND_FACTORY(SetPropagationDelay);


    SetPropagationDelay::SetPropagationDelay()
      : CommandBase(CmdName)
    {}

    SetPropagationDelay::SetPropagationDelay(const std::string& system, bool enabled)
      : CommandBase(CmdName)
    {

      setSystem(system);
      setEnabled(enabled);
    }

    SetPropagationDelayPtr SetPropagationDelay::create(const std::string& system, bool enabled)
    {
      return std::make_shared<SetPropagationDelay>(system, enabled);
    }

    SetPropagationDelayPtr SetPropagationDelay::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetPropagationDelay>(ptr);
    }

    bool SetPropagationDelay::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["System"])
          && parse_json<bool>::is_valid(m_values["Enabled"])
        ;

    }

    std::string SetPropagationDelay::documentation() const { return Documentation; }


    int SetPropagationDelay::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string SetPropagationDelay::system() const
    {
      return parse_json<std::string>::parse(m_values["System"]);
    }

    void SetPropagationDelay::setSystem(const std::string& system)
    {
      m_values.AddMember("System", parse_json<std::string>::format(system, m_values.GetAllocator()), m_values.GetAllocator());
    }



    bool SetPropagationDelay::enabled() const
    {
      return parse_json<bool>::parse(m_values["Enabled"]);
    }

    void SetPropagationDelay::setEnabled(bool enabled)
    {
      m_values.AddMember("Enabled", parse_json<bool>::format(enabled, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
