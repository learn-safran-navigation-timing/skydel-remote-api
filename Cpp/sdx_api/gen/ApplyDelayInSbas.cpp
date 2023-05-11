
#include "gen/ApplyDelayInSbas.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of ApplyDelayInSbas
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const ApplyDelayInSbas::CmdName = "ApplyDelayInSbas";
    const char* const ApplyDelayInSbas::Documentation = "Set whether the ionospheric offsets grid should be used for SBAS corrections in message 26";

    REGISTER_COMMAND_FACTORY(ApplyDelayInSbas);


    ApplyDelayInSbas::ApplyDelayInSbas()
      : CommandBase(CmdName)
    {}

    ApplyDelayInSbas::ApplyDelayInSbas(bool isEnabled)
      : CommandBase(CmdName)
    {

      setIsEnabled(isEnabled);
    }

    ApplyDelayInSbasPtr ApplyDelayInSbas::create(bool isEnabled)
    {
      return std::make_shared<ApplyDelayInSbas>(isEnabled);
    }

    ApplyDelayInSbasPtr ApplyDelayInSbas::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<ApplyDelayInSbas>(ptr);
    }

    bool ApplyDelayInSbas::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<bool>::is_valid(m_values["IsEnabled"])
        ;

    }

    std::string ApplyDelayInSbas::documentation() const { return Documentation; }


    int ApplyDelayInSbas::executePermission() const
    {
      return EXECUTE_IF_IDLE | EXECUTE_IF_SIMULATING;
    }


    bool ApplyDelayInSbas::isEnabled() const
    {
      return parse_json<bool>::parse(m_values["IsEnabled"]);
    }

    void ApplyDelayInSbas::setIsEnabled(bool isEnabled)
    {
      m_values.AddMember("IsEnabled", parse_json<bool>::format(isEnabled, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
