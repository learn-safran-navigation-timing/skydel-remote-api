
#include "IsAlmanacExtrapolationFromEphemerisEnabled.h"

#include "command_factory.h"
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
    const char* const IsAlmanacExtrapolationFromEphemerisEnabled::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(IsAlmanacExtrapolationFromEphemerisEnabled);
    REGISTER_COMMAND_TO_FACTORY_IMPL(IsAlmanacExtrapolationFromEphemerisEnabled);


    IsAlmanacExtrapolationFromEphemerisEnabled::IsAlmanacExtrapolationFromEphemerisEnabled()
      : CommandBase(CmdName, TargetId)
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

    const std::vector<std::string>& IsAlmanacExtrapolationFromEphemerisEnabled::fieldNames() const 
    { 
      static const std::vector<std::string> names {}; 
      return names; 
    }


    int IsAlmanacExtrapolationFromEphemerisEnabled::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }

  }
}
