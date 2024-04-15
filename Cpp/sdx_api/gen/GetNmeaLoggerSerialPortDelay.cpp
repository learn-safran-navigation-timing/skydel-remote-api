
#include "GetNmeaLoggerSerialPortDelay.h"

#include "command_factory.h"
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
    const char* const GetNmeaLoggerSerialPortDelay::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(GetNmeaLoggerSerialPortDelay);
    REGISTER_COMMAND_TO_FACTORY_IMPL(GetNmeaLoggerSerialPortDelay);


    GetNmeaLoggerSerialPortDelay::GetNmeaLoggerSerialPortDelay()
      : CommandBase(CmdName, TargetId)
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

    const std::vector<std::string>& GetNmeaLoggerSerialPortDelay::fieldNames() const 
    { 
      static const std::vector<std::string> names {}; 
      return names; 
    }


    int GetNmeaLoggerSerialPortDelay::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }

  }
}
