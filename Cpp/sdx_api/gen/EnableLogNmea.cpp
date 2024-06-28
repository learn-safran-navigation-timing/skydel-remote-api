
#include "EnableLogNmea.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of EnableLogNmea
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const EnableLogNmea::CmdName = "EnableLogNmea";
    const char* const EnableLogNmea::Documentation = "Set Logging of NMEA for the simulated position enable/disable.\n"
      "If a receiver is connected, that NMEA is saved as well.\n"
      "\n"
      "Name              Type          Description\n"
      "----------------- ------------- -----------------------------------------------------------------------------\n"
      "Enabled           bool          If true, file(s) will be created during simulation\n"
      "SerialPortEnabled optional bool If true, the log is streamed to the serial port specified in the Preferences.";
    const char* const EnableLogNmea::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(EnableLogNmea);
    REGISTER_COMMAND_TO_FACTORY_IMPL(EnableLogNmea);


    EnableLogNmea::EnableLogNmea()
      : CommandBase(CmdName, TargetId)
    {}

    EnableLogNmea::EnableLogNmea(bool enabled, const std::optional<bool>& serialPortEnabled)
      : CommandBase(CmdName, TargetId)
    {

      setEnabled(enabled);
      setSerialPortEnabled(serialPortEnabled);
    }

    EnableLogNmeaPtr EnableLogNmea::create(bool enabled, const std::optional<bool>& serialPortEnabled)
    {
      return std::make_shared<EnableLogNmea>(enabled, serialPortEnabled);
    }

    EnableLogNmeaPtr EnableLogNmea::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<EnableLogNmea>(ptr);
    }

    bool EnableLogNmea::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<bool>::is_valid(m_values["Enabled"])
          && parse_json<std::optional<bool>>::is_valid(m_values["SerialPortEnabled"])
        ;

    }

    std::string EnableLogNmea::documentation() const { return Documentation; }

    const std::vector<std::string>& EnableLogNmea::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Enabled", "SerialPortEnabled"}; 
      return names; 
    }


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



    std::optional<bool> EnableLogNmea::serialPortEnabled() const
    {
      return parse_json<std::optional<bool>>::parse(m_values["SerialPortEnabled"]);
    }

    void EnableLogNmea::setSerialPortEnabled(const std::optional<bool>& serialPortEnabled)
    {
      m_values.AddMember("SerialPortEnabled", parse_json<std::optional<bool>>::format(serialPortEnabled, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
