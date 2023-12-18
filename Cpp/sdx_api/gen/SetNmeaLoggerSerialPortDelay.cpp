
#include "gen/SetNmeaLoggerSerialPortDelay.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetNmeaLoggerSerialPortDelay
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetNmeaLoggerSerialPortDelay::CmdName = "SetNmeaLoggerSerialPortDelay";
    const char* const SetNmeaLoggerSerialPortDelay::Documentation = "Set the delay of the NMEA serial port logging.";

    REGISTER_COMMAND_FACTORY(SetNmeaLoggerSerialPortDelay);


    SetNmeaLoggerSerialPortDelay::SetNmeaLoggerSerialPortDelay()
      : CommandBase(CmdName)
    {}

    SetNmeaLoggerSerialPortDelay::SetNmeaLoggerSerialPortDelay(int delay)
      : CommandBase(CmdName)
    {

      setDelay(delay);
    }

    SetNmeaLoggerSerialPortDelayPtr SetNmeaLoggerSerialPortDelay::create(int delay)
    {
      return std::make_shared<SetNmeaLoggerSerialPortDelay>(delay);
    }

    SetNmeaLoggerSerialPortDelayPtr SetNmeaLoggerSerialPortDelay::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetNmeaLoggerSerialPortDelay>(ptr);
    }

    bool SetNmeaLoggerSerialPortDelay::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["Delay"])
        ;

    }

    std::string SetNmeaLoggerSerialPortDelay::documentation() const { return Documentation; }


    int SetNmeaLoggerSerialPortDelay::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    int SetNmeaLoggerSerialPortDelay::delay() const
    {
      return parse_json<int>::parse(m_values["Delay"]);
    }

    void SetNmeaLoggerSerialPortDelay::setDelay(int delay)
    {
      m_values.AddMember("Delay", parse_json<int>::format(delay, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
