
#include "gen/IsPropagationDelayEnabled.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of IsPropagationDelayEnabled
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const IsPropagationDelayEnabled::CmdName = "IsPropagationDelayEnabled";
    const char* const IsPropagationDelayEnabled::Documentation = "Tells if the propagation delay is enabled.";

    REGISTER_COMMAND_FACTORY(IsPropagationDelayEnabled);


    IsPropagationDelayEnabled::IsPropagationDelayEnabled()
      : CommandBase(CmdName)
    {}

    IsPropagationDelayEnabled::IsPropagationDelayEnabled(const std::string& system)
      : CommandBase(CmdName)
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
