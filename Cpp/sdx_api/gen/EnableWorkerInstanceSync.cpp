
#include "EnableWorkerInstanceSync.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of EnableWorkerInstanceSync
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const EnableWorkerInstanceSync::CmdName = "EnableWorkerInstanceSync";
    const char* const EnableWorkerInstanceSync::Documentation = "Enable/Disable Time Synchronization on worker instance.\n"
      "The worker instance will wait for the main instance to synchronize the simulators.\n"
      "\n"
      "Name    Type Description\n"
      "------- ---- ----------------------------------------------------------------------------------\n"
      "Enabled bool If true, this simulator will wait for the main instance to synchronize simulators.";
    const char* const EnableWorkerInstanceSync::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(EnableWorkerInstanceSync);
    REGISTER_COMMAND_TO_FACTORY_IMPL(EnableWorkerInstanceSync);


    EnableWorkerInstanceSync::EnableWorkerInstanceSync()
      : CommandBase(CmdName, TargetId)
    {}

    EnableWorkerInstanceSync::EnableWorkerInstanceSync(bool enabled)
      : CommandBase(CmdName, TargetId)
    {

      setEnabled(enabled);
    }

    EnableWorkerInstanceSyncPtr EnableWorkerInstanceSync::create(bool enabled)
    {
      return std::make_shared<EnableWorkerInstanceSync>(enabled);
    }

    EnableWorkerInstanceSyncPtr EnableWorkerInstanceSync::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<EnableWorkerInstanceSync>(ptr);
    }

    bool EnableWorkerInstanceSync::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<bool>::is_valid(m_values["Enabled"])
        ;

    }

    std::string EnableWorkerInstanceSync::documentation() const { return Documentation; }

    const std::vector<std::string>& EnableWorkerInstanceSync::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Enabled"}; 
      return names; 
    }


    int EnableWorkerInstanceSync::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    bool EnableWorkerInstanceSync::enabled() const
    {
      return parse_json<bool>::parse(m_values["Enabled"]);
    }

    void EnableWorkerInstanceSync::setEnabled(bool enabled)
    {
      m_values.AddMember("Enabled", parse_json<bool>::format(enabled, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
