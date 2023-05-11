
#include "gen/EnableLogNmea.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of EnableLogNmea
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const EnableLogNmea::CmdName = "EnableLogNmea";
    const char* const EnableLogNmea::Documentation = "Set Logging of NMEA for the simulated position enable/disable.\nIf a receiver is connected, that NMEA is saved as well.";

    REGISTER_COMMAND_FACTORY(EnableLogNmea);


    EnableLogNmea::EnableLogNmea()
      : CommandBase(CmdName)
    {}

    EnableLogNmea::EnableLogNmea(bool enabled)
      : CommandBase(CmdName)
    {

      setEnabled(enabled);
    }

    EnableLogNmeaPtr EnableLogNmea::create(bool enabled)
    {
      return std::make_shared<EnableLogNmea>(enabled);
    }

    EnableLogNmeaPtr EnableLogNmea::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<EnableLogNmea>(ptr);
    }

    bool EnableLogNmea::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<bool>::is_valid(m_values["Enabled"])
        ;

    }

    std::string EnableLogNmea::documentation() const { return Documentation; }


    int EnableLogNmea::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    bool EnableLogNmea::enabled() const
    {
      return parse_json<bool>::parse(m_values["Enabled"]);
    }

    void EnableLogNmea::setEnabled(bool enabled)
    {
      m_values.AddMember("Enabled", parse_json<bool>::format(enabled, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
