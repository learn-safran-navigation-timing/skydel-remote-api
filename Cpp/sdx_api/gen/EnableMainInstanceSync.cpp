
#include "EnableMainInstanceSync.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of EnableMainInstanceSync
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const EnableMainInstanceSync::CmdName = "EnableMainInstanceSync";
    const char* const EnableMainInstanceSync::Documentation = "Enable/Disable Time Synchronization on main instance.\n"
      "The main instance will control other Skydel simulators with main instance PPS Enabled.\n"
      "\n"
      "Name    Type Description\n"
      "------- ---- ----------------------------------------------------------------------------\n"
      "Enabled bool If true, this simulator will be the main instance to synchronize simulators.";
    const char* const EnableMainInstanceSync::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(EnableMainInstanceSync);
    REGISTER_COMMAND_TO_FACTORY_IMPL(EnableMainInstanceSync);


    EnableMainInstanceSync::EnableMainInstanceSync()
      : CommandBase(CmdName, TargetId)
    {}

    EnableMainInstanceSync::EnableMainInstanceSync(bool enabled)
      : CommandBase(CmdName, TargetId)
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

    const std::vector<std::string>& EnableMainInstanceSync::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Enabled"}; 
      return names; 
    }


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
