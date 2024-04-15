#pragma once

#include <memory>
#include "command_base.h"



namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Get the delay of the NMEA serial port logging.
    ///
    /// 
    ///

    class GetNmeaLoggerSerialPortDelay;
    typedef std::shared_ptr<GetNmeaLoggerSerialPortDelay> GetNmeaLoggerSerialPortDelayPtr;
    
    
    class GetNmeaLoggerSerialPortDelay : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      GetNmeaLoggerSerialPortDelay();

      static GetNmeaLoggerSerialPortDelayPtr create();
      static GetNmeaLoggerSerialPortDelayPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;

      virtual int executePermission() const override;
    };
    
  }
}

