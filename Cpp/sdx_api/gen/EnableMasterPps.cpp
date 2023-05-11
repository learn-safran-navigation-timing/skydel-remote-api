
#include "gen/EnableMasterPps.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of EnableMasterPps
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const EnableMasterPps::CmdName = "EnableMasterPps";
    const char* const EnableMasterPps::Documentation = "Enable/Disable Time Synchronization Master.\nThe Master will control other Skydel simulators with Slave PPS Enabled.";

    REGISTER_COMMAND_FACTORY(EnableMasterPps);


    EnableMasterPps::EnableMasterPps()
      : CommandBase(CmdName)
    {}

    EnableMasterPps::EnableMasterPps(bool enabled)
      : CommandBase(CmdName)
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
