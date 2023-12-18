#pragma once

#include <memory>
#include "command_base.h"



namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Set the delay of the NMEA serial port logging.
    ///
    /// Name  Type Description
    /// ----- ---- ---------------------------------
    /// Delay int  Delay from 0 to 100 milliseconds.
    ///

    class SetNmeaLoggerSerialPortDelay;
    typedef std::shared_ptr<SetNmeaLoggerSerialPortDelay> SetNmeaLoggerSerialPortDelayPtr;
    
    
    class SetNmeaLoggerSerialPortDelay : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      SetNmeaLoggerSerialPortDelay();

      SetNmeaLoggerSerialPortDelay(int delay);

      static SetNmeaLoggerSerialPortDelayPtr create(int delay);
      static SetNmeaLoggerSerialPortDelayPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** delay ****
      int delay() const;
      void setDelay(int delay);
    };
    
  }
}

