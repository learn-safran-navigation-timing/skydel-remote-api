
#include "EnableMasterPps.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of EnableMasterPps
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const EnableMasterPps::CmdName = "EnableMasterPps";
    const char* const EnableMasterPps::Documentation = "Please note the command EnableMasterPps is deprecated since 23.11. You may use EnableMainInstanceSync.\n"
      "\n"
      "Enable/Disable Time Synchronization on main instance.\n"
      "The main instance will control other Skydel simulators with main instance PPS Enabled.\n"
      "\n"
      "Name    Type Description\n"
      "------- ---- ----------------------------------------------------------------------------\n"
      "Enabled bool If true, this simulator will be the main instance to synchronize simulators.";
    const char* const EnableMasterPps::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(EnableMasterPps);
    REGISTER_COMMAND_TO_FACTORY_IMPL(EnableMasterPps);


    EnableMasterPps::EnableMasterPps()
      : CommandBase(CmdName, TargetId)
    {}

    EnableMasterPps::EnableMasterPps(bool enabled)
      : CommandBase(CmdName, TargetId)
    {

      setEnabled(enabled);
    }

    EnableMasterPpsPtr EnableMasterPps::create(bool enabled)
    {
      return std::make_shared<EnableMasterPps>(enabled);
    }

    EnableMasterPpsPtr EnableMasterPps::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<EnableMasterPps>(ptr);
    }

    bool EnableMasterPps::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<bool>::is_valid(m_values["Enabled"])
        ;

    }

    std::string EnableMasterPps::documentation() const { return Documentation; }

    const std::vector<std::string>& EnableMasterPps::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Enabled"}; 
      return names; 
    }


    int EnableMasterPps::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    bool EnableMasterPps::enabled() const
    {
      return parse_json<bool>::parse(m_values["Enabled"]);
    }

    void EnableMasterPps::setEnabled(bool enabled)
    {
      m_values.AddMember("Enabled", parse_json<bool>::format(enabled, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
