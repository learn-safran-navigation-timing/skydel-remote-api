
#include "gen/EnableElevationMaskBelow.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of EnableElevationMaskBelow
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const EnableElevationMaskBelow::CmdName = "EnableElevationMaskBelow";
    const char* const EnableElevationMaskBelow::Documentation = "Set GNSS satellite mask based on elevation enabled or disabled (See SetElevationMaskBelow).";

    REGISTER_COMMAND_FACTORY(EnableElevationMaskBelow);


    EnableElevationMaskBelow::EnableElevationMaskBelow()
      : CommandBase(CmdName)
    {}

    EnableElevationMaskBelow::EnableElevationMaskBelow(bool enabled)
      : CommandBase(CmdName)
    {

      setEnabled(enabled);
    }

    EnableElevationMaskBelowPtr EnableElevationMaskBelow::create(bool enabled)
    {
      return std::make_shared<EnableElevationMaskBelow>(enabled);
    }

    EnableElevationMaskBelowPtr EnableElevationMaskBelow::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<EnableElevationMaskBelow>(ptr);
    }

    bool EnableElevationMaskBelow::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<bool>::is_valid(m_values["Enabled"])
        ;

    }

    std::string EnableElevationMaskBelow::documentation() const { return Documentation; }


    int EnableElevationMaskBelow::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    bool EnableElevationMaskBelow::enabled() const
    {
      return parse_json<bool>::parse(m_values["Enabled"]);
    }

    void EnableElevationMaskBelow::setEnabled(bool enabled)
    {
      m_values.AddMember("Enabled", parse_json<bool>::format(enabled, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
