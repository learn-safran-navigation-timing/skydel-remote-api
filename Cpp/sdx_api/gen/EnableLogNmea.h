#pragma once

#include <memory>
#include "command_base.h"

#include "sdx_optional.h"

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Set Logging of NMEA for the simulated position enable/disable.
    /// If a receiver is connected, that NMEA is saved as well.
    ///
    /// Name              Type          Description
    /// ----------------- ------------- -----------------------------------------------------------------------------
    /// Enabled           bool          If true, file(s) will be created during simulation
    /// SerialPortEnabled optional bool If true, the log is streamed to the serial port specified in the Preferences.
    ///

    class EnableLogNmea;
    typedef std::shared_ptr<EnableLogNmea> EnableLogNmeaPtr;
    
    
    class EnableLogNmea : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      EnableLogNmea();

      EnableLogNmea(bool enabled, const Sdx::optional<bool>& serialPortEnabled = {});

      static EnableLogNmeaPtr create(bool enabled, const Sdx::optional<bool>& serialPortEnabled = {});
      static EnableLogNmeaPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** enabled ****
      bool enabled() const;
      void setEnabled(bool enabled);


      // **** serialPortEnabled ****
      Sdx::optional<bool> serialPortEnabled() const;
      void setSerialPortEnabled(const Sdx::optional<bool>& serialPortEnabled);
    };
    
  }
}

