#pragma once

#include <memory>
#include "command_base.h"

#include "sdx_optional.h"
#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Set pulse signal interference.
    ///
    /// Name          Type         Description
    /// ------------- ------------ --------------------------------------------------------------
    /// Enabled       bool         Enable (true) or disable (false) the signal
    /// CentralFreq   double       Central frequency (Hz)
    /// Power         double       Power (dB), relative to transmitter reference power
    /// DutyCycle     double       Duty Cycle between 0.01 and 100, as a percentage of Pulse Rate
    /// PulseRate     int          Pulse rate (Hz), between 1 and 100000
    /// TransmitterId string       Transmitter unique identifier.
    /// SignalId      string       Pulse unique identifier.
    /// Group         optional int Group, if not using default group.
    ///

    class SetIntTxPulse;
    typedef std::shared_ptr<SetIntTxPulse> SetIntTxPulsePtr;
    
    
    class SetIntTxPulse : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      SetIntTxPulse();

      SetIntTxPulse(bool enabled, double centralFreq, double power, double dutyCycle, int pulseRate, const std::string& transmitterId, const std::string& signalId, const Sdx::optional<int>& group = {});

      static SetIntTxPulsePtr create(bool enabled, double centralFreq, double power, double dutyCycle, int pulseRate, const std::string& transmitterId, const std::string& signalId, const Sdx::optional<int>& group = {});
      static SetIntTxPulsePtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;

      virtual int executePermission() const override;


      // **** enabled ****
      bool enabled() const;
      void setEnabled(bool enabled);


      // **** centralFreq ****
      double centralFreq() const;
      void setCentralFreq(double centralFreq);


      // **** power ****
      double power() const;
      void setPower(double power);


      // **** dutyCycle ****
      double dutyCycle() const;
      void setDutyCycle(double dutyCycle);


      // **** pulseRate ****
      int pulseRate() const;
      void setPulseRate(int pulseRate);


      // **** transmitterId ****
      std::string transmitterId() const;
      void setTransmitterId(const std::string& transmitterId);


      // **** signalId ****
      std::string signalId() const;
      void setSignalId(const std::string& signalId);


      // **** group ****
      Sdx::optional<int> group() const;
      void setGroup(const Sdx::optional<int>& group);
    };
    
  }
}

