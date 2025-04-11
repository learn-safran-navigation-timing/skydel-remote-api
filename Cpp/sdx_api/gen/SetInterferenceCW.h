#pragma once

#include <memory>
#include "command_base.h"

#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Add or update continuous wave interference signal.
    ///
    /// Name        Type   Description
    /// ----------- ------ -------------------------------------------------------------------------------------------------------------------------
    /// StartTime   int    Elapsed time at which the signal is enabled (s). Minimum = 0 s, Maximum = 86399 s (23 hours, 59 minutes and 59 seconds).
    /// StopTime    int    Elapsed time at which the signal is disabled (s). Minimum = 0 s, Maximum = 86399 s (23 hours, 59 minutes and 59 seconds).
    /// CentralFreq double Central frequency (Hz). Minimum = 100000000 Hz (100 MHz), Maximum = 6000000000 Hz (6 GHz).
    /// Power       double Power (dB) relative to nominal power. Minimum = -40 dB, Maximum = 43 dB.
    /// Enabled     bool   Enables or disables the interference signal.
    /// Id          string Interference signal unique identifier.
    ///

    class SetInterferenceCW;
    typedef std::shared_ptr<SetInterferenceCW> SetInterferenceCWPtr;
    
    
    class SetInterferenceCW : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      SetInterferenceCW();

      SetInterferenceCW(int startTime, int stopTime, double centralFreq, double power, bool enabled, const std::string& id);

      static SetInterferenceCWPtr create(int startTime, int stopTime, double centralFreq, double power, bool enabled, const std::string& id);
      static SetInterferenceCWPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;

      virtual int executePermission() const override;


      // **** startTime ****
      int startTime() const;
      void setStartTime(int startTime);


      // **** stopTime ****
      int stopTime() const;
      void setStopTime(int stopTime);


      // **** centralFreq ****
      double centralFreq() const;
      void setCentralFreq(double centralFreq);


      // **** power ****
      double power() const;
      void setPower(double power);


      // **** enabled ****
      bool enabled() const;
      void setEnabled(bool enabled);


      // **** id ****
      std::string id() const;
      void setId(const std::string& id);
    };
    
  }
}

