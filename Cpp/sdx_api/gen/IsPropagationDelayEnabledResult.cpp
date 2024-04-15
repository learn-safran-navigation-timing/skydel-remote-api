
#include "IsPropagationDelayEnabledResult.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of IsPropagationDelayEnabledResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const IsPropagationDelayEnabledResult::CmdName = "IsPropagationDelayEnabledResult";
    const char* const IsPropagationDelayEnabledResult::Documentation = "Result of IsPropagationDelayEnabled.\n"
      "\n"
      "Name    Type   Description\n"
      "------- ------ -------------------------------------------------------------------------------------------------\n"
      "System  string \"GPS\", \"GLONASS\", \"Galileo\", \"BeiDou\", \"SBAS\", \"QZSS\", \"NavIC\" or \"PULSAR\"\n"
      "Enabled bool   If false, the propagation delay between the GPS satellite and the receiver is forced to 0 second.";
    const char* const IsPropagationDelayEnabledResult::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_IMPL(IsPropagationDelayEnabledResult);


    IsPropagationDelayEnabledResult::IsPropagationDelayEnabledResult()
      : CommandResult(CmdName, TargetId)
    {}

    IsPropagationDelayEnabledResult::IsPropagationDelayEnabledResult(const std::string& system, bool enabled)
      : CommandResult(CmdName, TargetId)
    {

      setSystem(system);
      setEnabled(enabled);
    }

    IsPropagationDelayEnabledResult::IsPropagationDelayEnabledResult(CommandBasePtr relatedCommand, const std::string& system, bool enabled)
      : CommandResult(CmdName, TargetId, relatedCommand)
    {

      setSystem(system);
      setEnabled(enabled);
    }


    IsPropagationDelayEnabledResultPtr IsPropagationDelayEnabledResult::create(const std::string& system, bool enabled)
    {
      return std::make_shared<IsPropagationDelayEnabledResult>(system, enabled);
    }

    IsPropagationDelayEnabledResultPtr IsPropagationDelayEnabledResult::create(CommandBasePtr relatedCommand, const std::string& system, bool enabled)
    {
      return std::make_shared<IsPropagationDelayEnabledResult>(relatedCommand, system, enabled);
    }

    IsPropagationDelayEnabledResultPtr IsPropagationDelayEnabledResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<IsPropagationDelayEnabledResult>(ptr);
    }

    bool IsPropagationDelayEnabledResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["System"])
          && parse_json<bool>::is_valid(m_values["Enabled"])
        ;

    }

    std::string IsPropagationDelayEnabledResult::documentation() const { return Documentation; }

    const std::vector<std::string>& IsPropagationDelayEnabledResult::fieldNames() const 
    { 
      static const std::vector<std::string> names {"System", "Enabled"}; 
      return names; 
    }


    std::string IsPropagationDelayEnabledResult::system() const
    {
      return parse_json<std::string>::parse(m_values["System"]);
    }

    void IsPropagationDelayEnabledResult::setSystem(const std::string& system)
    {
      m_values.AddMember("System", parse_json<std::string>::format(system, m_values.GetAllocator()), m_values.GetAllocator());
    }



    bool IsPropagationDelayEnabledResult::enabled() const
    {
      return parse_json<bool>::parse(m_values["Enabled"]);
    }

    void IsPropagationDelayEnabledResult::setEnabled(bool enabled)
    {
      m_values.AddMember("Enabled", parse_json<bool>::format(enabled, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
