
#include "gen/GetNmeaLoggerSerialPortDelay.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetNmeaLoggerSerialPortDelay
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetNmeaLoggerSerialPortDelay::CmdName = "GetNmeaLoggerSerialPortDelay";
    const char* const GetNmeaLoggerSerialPortDelay::Documentation = "Get the delay of the NMEA serial port logging.";

    REGISTER_COMMAND_FACTORY(GetNmeaLoggerSerialPortDelay);


    GetNmeaLoggerSerialPortDelay::GetNmeaLoggerSerialPortDelay()
      : CommandBase(CmdName)
    {

    }

    GetNmeaLoggerSerialPortDelayPtr GetNmeaLoggerSerialPortDelay::create()
    {
      return std::make_shared<GetNmeaLoggerSerialPortDelay>();
    }

    GetNmeaLoggerSerialPortDelayPtr GetNmeaLoggerSerialPortDelay::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetNmeaLoggerSerialPortDelay>(ptr);
    }

    bool GetNmeaLoggerSerialPortDelay::isValid() const
    {
      
        return m_values.IsObject()
        ;

    }

    std::string GetNmeaLoggerSerialPortDelay::documentation() const { return Documentation; }


    int GetNmeaLoggerSerialPortDelay::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }

  }
}
