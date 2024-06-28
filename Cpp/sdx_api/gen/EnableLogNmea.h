#pragma once

#include <memory>
#include "command_base.h"

#include <optional>

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
      static const char* const TargetId;


      EnableLogNmea();

      EnableLogNmea(bool enabled, const std::optional<bool>& serialPortEnabled = {});

      static EnableLogNmeaPtr create(bool enabled, const std::optional<bool>& serialPortEnabled = {});
      static EnableLogNmeaPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;

      virtual int executePermission() const override;


      // **** enabled ****
      bool enabled() const;
      void setEnabled(bool enabled);


      // **** serialPortEnabled ****
      std::optional<bool> serialPortEnabled() const;
      void setSerialPortEnabled(const std::optional<bool>& serialPortEnabled);
    };
    
  }
}

