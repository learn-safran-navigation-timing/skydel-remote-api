
#include "gen/EnableSlavePps.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of EnableSlavePps
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const EnableSlavePps::CmdName = "EnableSlavePps";
    const char* const EnableSlavePps::Documentation = "Enable/Disable Time Synchronization Slave.\nThe Slave will wait for the Master to synchronize the simulators.";

    REGISTER_COMMAND_FACTORY(EnableSlavePps);


    EnableSlavePps::EnableSlavePps()
      : CommandBase(CmdName)
    {}

    EnableSlavePps::EnableSlavePps(bool enabled)
      : CommandBase(CmdName)
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
