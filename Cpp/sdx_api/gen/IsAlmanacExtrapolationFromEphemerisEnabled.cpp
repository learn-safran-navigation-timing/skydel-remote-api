
#include "gen/IsAlmanacExtrapolationFromEphemerisEnabled.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of IsAlmanacExtrapolationFromEphemerisEnabled
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const IsAlmanacExtrapolationFromEphemerisEnabled::CmdName = "IsAlmanacExtrapolationFromEphemerisEnabled";
    const char* const IsAlmanacExtrapolationFromEphemerisEnabled::Documentation = "Get state of almanac extrapolation from ephemeris in Dynamic SV data.";

    REGISTER_COMMAND_FACTORY(IsAlmanacExtrapolationFromEphemerisEnabled);


    IsAlmanacExtrapolationFromEphemerisEnabled::IsAlmanacExtrapolationFromEphemerisEnabled()
      : CommandBase(CmdName)
    {

    }

    IsAlmanacExtrapolationFromEphemerisEnabledPtr IsAlmanacExtrapolationFromEphemerisEnabled::create()
    {
      return std::make_shared<IsAlmanacExtrapolationFromEphemerisEnabled>();
    }

    IsAlmanacExtrapolationFromEphemerisEnabledPtr IsAlmanacExtrapolationFromEphemerisEnabled::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<IsAlmanacExtrapolationFromEphemerisEnabled>(ptr);
    }

    bool IsAlmanacExtrapolationFromEphemerisEnabled::isValid() const
    {
      
        return m_values.IsObject()
        ;

    }

    std::string IsAlmanacExtrapolationFromEphemerisEnabled::documentation() const { return Documentation; }


    int IsAlmanacExtrapolationFromEphemerisEnabled::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }

  }
}
