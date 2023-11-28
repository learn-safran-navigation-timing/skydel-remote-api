
#include "gen/EnableMainInstanceSync.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of EnableMainInstanceSync
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const EnableMainInstanceSync::CmdName = "EnableMainInstanceSync";
    const char* const EnableMainInstanceSync::Documentation = "Enable/Disable Time Synchronization on main instance.\nThe main instance will control other Skydel simulators with main instance PPS Enabled.";

    REGISTER_COMMAND_FACTORY(EnableMainInstanceSync);


    EnableMainInstanceSync::EnableMainInstanceSync()
      : CommandBase(CmdName)
    {}

    EnableMainInstanceSync::EnableMainInstanceSync(bool enabled)
      : CommandBase(CmdName)
    {

      setEnabled(enabled);
    }

    EnableMainInstanceSyncPtr EnableMainInstanceSync::create(bool enabled)
    {
      return std::make_shared<EnableMainInstanceSync>(enabled);
    }

    EnableMainInstanceSyncPtr EnableMainInstanceSync::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<EnableMainInstanceSync>(ptr);
    }

    bool EnableMainInstanceSync::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<bool>::is_valid(m_values["Enabled"])
        ;

    }

    std::string EnableMainInstanceSync::documentation() const { return Documentation; }


    int EnableMainInstanceSync::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    bool EnableMainInstanceSync::enabled() const
    {
      return parse_json<bool>::parse(m_values["Enabled"]);
    }

    void EnableMainInstanceSync::setEnabled(bool enabled)
    {
      m_values.AddMember("Enabled", parse_json<bool>::format(enabled, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
