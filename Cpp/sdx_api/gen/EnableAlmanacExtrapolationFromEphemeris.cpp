
#include "gen/EnableAlmanacExtrapolationFromEphemeris.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of EnableAlmanacExtrapolationFromEphemeris
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const EnableAlmanacExtrapolationFromEphemeris::CmdName = "EnableAlmanacExtrapolationFromEphemeris";
    const char* const EnableAlmanacExtrapolationFromEphemeris::Documentation = "Enable (or disable) extrapolation of the almanac from the ephemeris in Dynamic SV Data mode.\nWhen disabled, use PushDynamicAlmanacData to push the almanac data";

    REGISTER_COMMAND_FACTORY(EnableAlmanacExtrapolationFromEphemeris);


    EnableAlmanacExtrapolationFromEphemeris::EnableAlmanacExtrapolationFromEphemeris()
      : CommandBase(CmdName)
    {}

    EnableAlmanacExtrapolationFromEphemeris::EnableAlmanacExtrapolationFromEphemeris(bool enabled)
      : CommandBase(CmdName)
    {

      setEnabled(enabled);
    }

    EnableAlmanacExtrapolationFromEphemerisPtr EnableAlmanacExtrapolationFromEphemeris::create(bool enabled)
    {
      return std::make_shared<EnableAlmanacExtrapolationFromEphemeris>(enabled);
    }

    EnableAlmanacExtrapolationFromEphemerisPtr EnableAlmanacExtrapolationFromEphemeris::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<EnableAlmanacExtrapolationFromEphemeris>(ptr);
    }

    bool EnableAlmanacExtrapolationFromEphemeris::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<bool>::is_valid(m_values["Enabled"])
        ;

    }

    std::string EnableAlmanacExtrapolationFromEphemeris::documentation() const { return Documentation; }


    int EnableAlmanacExtrapolationFromEphemeris::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    bool EnableAlmanacExtrapolationFromEphemeris::enabled() const
    {
      return parse_json<bool>::parse(m_values["Enabled"]);
    }

    void EnableAlmanacExtrapolationFromEphemeris::setEnabled(bool enabled)
    {
      m_values.AddMember("Enabled", parse_json<bool>::format(enabled, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
