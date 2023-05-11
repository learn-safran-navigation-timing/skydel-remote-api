
#include "gen/EnableElevationMaskAbove.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of EnableElevationMaskAbove
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const EnableElevationMaskAbove::CmdName = "EnableElevationMaskAbove";
    const char* const EnableElevationMaskAbove::Documentation = "Set GNSS satellite mask based on elevation enabled or disabled (See SetElevationMaskAbove).";

    REGISTER_COMMAND_FACTORY(EnableElevationMaskAbove);


    EnableElevationMaskAbove::EnableElevationMaskAbove()
      : CommandBase(CmdName)
    {}

    EnableElevationMaskAbove::EnableElevationMaskAbove(bool enabled)
      : CommandBase(CmdName)
    {

      setEnabled(enabled);
    }

    EnableElevationMaskAbovePtr EnableElevationMaskAbove::create(bool enabled)
    {
      return std::make_shared<EnableElevationMaskAbove>(enabled);
    }

    EnableElevationMaskAbovePtr EnableElevationMaskAbove::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<EnableElevationMaskAbove>(ptr);
    }

    bool EnableElevationMaskAbove::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<bool>::is_valid(m_values["Enabled"])
        ;

    }

    std::string EnableElevationMaskAbove::documentation() const { return Documentation; }


    int EnableElevationMaskAbove::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    bool EnableElevationMaskAbove::enabled() const
    {
      return parse_json<bool>::parse(m_values["Enabled"]);
    }

    void EnableElevationMaskAbove::setEnabled(bool enabled)
    {
      m_values.AddMember("Enabled", parse_json<bool>::format(enabled, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
