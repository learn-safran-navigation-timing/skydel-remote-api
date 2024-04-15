
#include "SetPropagationDelay.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetPropagationDelay
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetPropagationDelay::CmdName = "SetPropagationDelay";
    const char* const SetPropagationDelay::Documentation = "Enable (or disable) the satellite signal propagation delay. If disabled, the signal is immediately received\n"
      "by the receiver. The delay should always be enabled, unless your are doing a PPS calibration for the simulator.\n"
      "\n"
      "Name    Type   Description\n"
      "------- ------ -------------------------------------------------------------------------------------------------\n"
      "System  string \"GPS\", \"GLONASS\", \"Galileo\", \"BeiDou\", \"SBAS\", \"QZSS\", \"NavIC\" or \"PULSAR\"\n"
      "Enabled bool   If false, the propagation delay between the GPS satellite and the receiver is forced to 0 second.";
    const char* const SetPropagationDelay::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(SetPropagationDelay);
    REGISTER_COMMAND_TO_FACTORY_IMPL(SetPropagationDelay);


    SetPropagationDelay::SetPropagationDelay()
      : CommandBase(CmdName, TargetId)
    {}

    SetPropagationDelay::SetPropagationDelay(const std::string& system, bool enabled)
      : CommandBase(CmdName, TargetId)
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

    const std::vector<std::string>& SetPropagationDelay::fieldNames() const 
    { 
      static const std::vector<std::string> names {"System", "Enabled"}; 
      return names; 
    }


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
