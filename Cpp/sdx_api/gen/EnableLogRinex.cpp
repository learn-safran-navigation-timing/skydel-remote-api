
#include "gen/EnableLogRinex.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of EnableLogRinex
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const EnableLogRinex::CmdName = "EnableLogRinex";
    const char* const EnableLogRinex::Documentation = "Enable (or disable) ephemeris data logging in RINEX v3.03 format";

    REGISTER_COMMAND_FACTORY(EnableLogRinex);


    EnableLogRinex::EnableLogRinex()
      : CommandBase(CmdName)
    {}

    EnableLogRinex::EnableLogRinex(bool enabled)
      : CommandBase(CmdName)
    {

      setEnabled(enabled);
    }

    EnableLogRinexPtr EnableLogRinex::create(bool enabled)
    {
      return std::make_shared<EnableLogRinex>(enabled);
    }

    EnableLogRinexPtr EnableLogRinex::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<EnableLogRinex>(ptr);
    }

    bool EnableLogRinex::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<bool>::is_valid(m_values["Enabled"])
        ;

    }

    std::string EnableLogRinex::documentation() const { return Documentation; }


    int EnableLogRinex::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    bool EnableLogRinex::enabled() const
    {
      return parse_json<bool>::parse(m_values["Enabled"]);
    }

    void EnableLogRinex::setEnabled(bool enabled)
    {
      m_values.AddMember("Enabled", parse_json<bool>::format(enabled, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
