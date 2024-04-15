
#include "IsPropagationDelayEnabled.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of IsPropagationDelayEnabled
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const IsPropagationDelayEnabled::CmdName = "IsPropagationDelayEnabled";
    const char* const IsPropagationDelayEnabled::Documentation = "Tells if the propagation delay is enabled.\n"
      "\n"
      "Name   Type   Description\n"
      "------ ------ --------------------------------------------------------------------------\n"
      "System string \"GPS\", \"GLONASS\", \"Galileo\", \"BeiDou\", \"SBAS\", \"QZSS\", \"NavIC\" or \"PULSAR\"";
    const char* const IsPropagationDelayEnabled::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(IsPropagationDelayEnabled);
    REGISTER_COMMAND_TO_FACTORY_IMPL(IsPropagationDelayEnabled);


    IsPropagationDelayEnabled::IsPropagationDelayEnabled()
      : CommandBase(CmdName, TargetId)
    {}

    IsPropagationDelayEnabled::IsPropagationDelayEnabled(const std::string& system)
      : CommandBase(CmdName, TargetId)
    {

      setSystem(system);
    }

    IsPropagationDelayEnabledPtr IsPropagationDelayEnabled::create(const std::string& system)
    {
      return std::make_shared<IsPropagationDelayEnabled>(system);
    }

    IsPropagationDelayEnabledPtr IsPropagationDelayEnabled::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<IsPropagationDelayEnabled>(ptr);
    }

    bool IsPropagationDelayEnabled::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["System"])
        ;

    }

    std::string IsPropagationDelayEnabled::documentation() const { return Documentation; }

    const std::vector<std::string>& IsPropagationDelayEnabled::fieldNames() const 
    { 
      static const std::vector<std::string> names {"System"}; 
      return names; 
    }


    int IsPropagationDelayEnabled::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string IsPropagationDelayEnabled::system() const
    {
      return parse_json<std::string>::parse(m_values["System"]);
    }

    void IsPropagationDelayEnabled::setSystem(const std::string& system)
    {
      m_values.AddMember("System", parse_json<std::string>::format(system, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
