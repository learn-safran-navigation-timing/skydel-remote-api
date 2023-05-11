#pragma once

#include <memory>
#include "command_result.h"
#include "command_result_factory.h"
#include "sdx_optional.h"
#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of GetIntTxPulse.
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

    class GetIntTxPulseResult;
    typedef std::shared_ptr<GetIntTxPulseResult> GetIntTxPulseResultPtr;
    
    
    class GetIntTxPulseResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetIntTxPulseResult();

      GetIntTxPulseResult(bool enabled, double centralFreq, double power, double dutyCycle, int pulseRate, const std::string& transmitterId, const std::string& signalId, const Sdx::optional<int>& group = {});

      GetIntTxPulseResult(CommandBasePtr relatedCommand, bool enabled, double centralFreq, double power, double dutyCycle, int pulseRate, const std::string& transmitterId, const std::string& signalId, const Sdx::optional<int>& group = {});

      static GetIntTxPulseResultPtr create(bool enabled, double centralFreq, double power, double dutyCycle, int pulseRate, const std::string& transmitterId, const std::string& signalId, const Sdx::optional<int>& group = {});

      static GetIntTxPulseResultPtr create(CommandBasePtr relatedCommand, bool enabled, double centralFreq, double power, double dutyCycle, int pulseRate, const std::string& transmitterId, const std::string& signalId, const Sdx::optional<int>& group = {});
      static GetIntTxPulseResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;


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
    REGISTER_COMMAND_RESULT_TO_FACTORY_DECL(GetIntTxPulseResult);
  }
}

