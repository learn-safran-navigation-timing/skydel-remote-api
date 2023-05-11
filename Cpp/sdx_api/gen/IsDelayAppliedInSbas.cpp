
#include "gen/IsDelayAppliedInSbas.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of IsDelayAppliedInSbas
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const IsDelayAppliedInSbas::CmdName = "IsDelayAppliedInSbas";
    const char* const IsDelayAppliedInSbas::Documentation = "Get whether the ionospheric offsets grid should be used for SBAS corrections in message 26";

    REGISTER_COMMAND_FACTORY(IsDelayAppliedInSbas);


    IsDelayAppliedInSbas::IsDelayAppliedInSbas()
      : CommandBase(CmdName)
    {

    }

    IsDelayAppliedInSbasPtr IsDelayAppliedInSbas::create()
    {
      return std::make_shared<IsDelayAppliedInSbas>();
    }

    IsDelayAppliedInSbasPtr IsDelayAppliedInSbas::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<IsDelayAppliedInSbas>(ptr);
    }

    bool IsDelayAppliedInSbas::isValid() const
    {
      
        return m_values.IsObject()
        ;

    }

    std::string IsDelayAppliedInSbas::documentation() const { return Documentation; }


    int IsDelayAppliedInSbas::executePermission() const
    {
      return EXECUTE_IF_IDLE | EXECUTE_IF_SIMULATING;
    }

  }
}
