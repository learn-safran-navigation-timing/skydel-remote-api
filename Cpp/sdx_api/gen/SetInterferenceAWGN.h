#pragma once

#include <memory>
#include "command_base.h"

#include <optional>
#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Add or update an AWGN interference signal.
    ///
    /// Name        Type         Description
    /// ----------- ------------ --------------------------------------------------------------------------------------------------------------------------------------------
    /// StartTime   int          Elapsed time at which the signal is enabled (s). Minimum = 0 s, Maximum = 86399 s (23 hours, 59 minutes and 59 seconds).
    /// StopTime    int          Elapsed time at which the signal is disabled (s). Minimum = 0 s, Maximum = 86399 s (23 hours, 59 minutes and 59 seconds).
    /// CentralFreq double       Central frequency (Hz). Minimum = 100000000 Hz (100 MHz), Maximum = 6000000000 Hz (6 GHz).
    /// Power       double       Power (dB) relative to nominal power. Minimum = -40 dB, Maximum = 43 dB.
    /// Bandwidth   double       Bandwidth (Hz). Minimum = 1000 Hz (1 kHz), Maximum = 40000000 Hz (40 MHz).
    /// Enabled     bool         Enables or disables the interference signal.
    /// Id          string       Interference signal unique identifier.
    /// Seed        optional int Seed used to initialize the random number generator. Signals with the same seed will have the same shape. Minimum = 0, Maximum = 4294967295.
    ///

    class SetInterferenceAWGN;
    typedef std::shared_ptr<SetInterferenceAWGN> SetInterferenceAWGNPtr;
    
    
    class SetInterferenceAWGN : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      SetInterferenceAWGN();

      SetInterferenceAWGN(int startTime, int stopTime, double centralFreq, double power, double bandwidth, bool enabled, const std::string& id, const std::optional<int>& seed = {});

      static SetInterferenceAWGNPtr create(int startTime, int stopTime, double centralFreq, double power, double bandwidth, bool enabled, const std::string& id, const std::optional<int>& seed = {});
      static SetInterferenceAWGNPtr dynamicCast(CommandBasePtr ptr);
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


      // **** bandwidth ****
      double bandwidth() const;
      void setBandwidth(double bandwidth);


      // **** enabled ****
      bool enabled() const;
      void setEnabled(bool enabled);


      // **** id ****
      std::string id() const;
      void setId(const std::string& id);


      // **** seed ****
      std::optional<int> seed() const;
      void setSeed(const std::optional<int>& seed);
    };
    
  }
}

