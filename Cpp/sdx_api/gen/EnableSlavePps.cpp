
#include "EnableSlavePps.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of EnableSlavePps
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const EnableSlavePps::CmdName = "EnableSlavePps";
    const char* const EnableSlavePps::Documentation = "Please note the command EnableSlavePps is deprecated since 23.11. You may use EnableWorkerInstanceSync.\n"
      "\n"
      "Enable/Disable Time Synchronization on worker instance.\n"
      "The worker instance will wait for the main instance to synchronize the simulators.\n"
      "\n"
      "Name    Type Description\n"
      "------- ---- ----------------------------------------------------------------------------------\n"
      "Enabled bool If true, this simulator will wait for the main instance to synchronize simulators.";
    const char* const EnableSlavePps::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(EnableSlavePps);
    REGISTER_COMMAND_TO_FACTORY_IMPL(EnableSlavePps);


    EnableSlavePps::EnableSlavePps()
      : CommandBase(CmdName, TargetId)
    {}

    EnableSlavePps::EnableSlavePps(bool enabled)
      : CommandBase(CmdName, TargetId)
    {

      setEnabled(enabled);
    }

    EnableSlavePpsPtr EnableSlavePps::create(bool enabled)
    {
      return std::make_shared<EnableSlavePps>(enabled);
    }

    EnableSlavePpsPtr EnableSlavePps::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<EnableSlavePps>(ptr);
    }

    bool EnableSlavePps::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<bool>::is_valid(m_values["Enabled"])
        ;

    }

    std::string EnableSlavePps::documentation() const { return Documentation; }

    const std::vector<std::string>& EnableSlavePps::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Enabled"}; 
      return names; 
    }


    int EnableSlavePps::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    bool EnableSlavePps::enabled() const
    {
      return parse_json<bool>::parse(m_values["Enabled"]);
    }

    void EnableSlavePps::setEnabled(bool enabled)
    {
      m_values.AddMember("Enabled", parse_json<bool>::format(enabled, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
