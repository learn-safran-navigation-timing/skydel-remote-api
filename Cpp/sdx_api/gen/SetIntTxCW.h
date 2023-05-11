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
    /// Set continuous wave (CW) signal to interference transmitter. A transmitter can combine
    /// multiple signals of different types to create complex waveform. The CW id (SignalId) can be an empty
    /// string. In such case, Skydel will assign a unique ID. If the signal id is already in use for the
    /// specified transmitted, the existing signal is updated, ortherwise a new signal is added.
    ///
    /// Name               Type            Description
    /// ------------------ --------------- ---------------------------------------------------
    /// Enabled            bool            Enable (true) or disable (false) the signal
    /// CentralFreq        double          Central frequency (Hz)
    /// Power              double          Power (dB), relative to transmitter reference power
    /// TransmitterId      string          Transmitter unique identifier.
    /// SignalId           string          CW unique identifier.
    /// InitialPhaseOffset optional double Initial phase offset, in radians. Defaults to 0.
    /// Group              optional int    Group, if not using default group.
    ///

    class SetIntTxCW;
    typedef std::shared_ptr<SetIntTxCW> SetIntTxCWPtr;
    
    
    class SetIntTxCW : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      SetIntTxCW();

      SetIntTxCW(bool enabled, double centralFreq, double power, const std::string& transmitterId, const std::string& signalId, const Sdx::optional<double>& initialPhaseOffset = {}, const Sdx::optional<int>& group = {});

      static SetIntTxCWPtr create(bool enabled, double centralFreq, double power, const std::string& transmitterId, const std::string& signalId, const Sdx::optional<double>& initialPhaseOffset = {}, const Sdx::optional<int>& group = {});
      static SetIntTxCWPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

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


      // **** transmitterId ****
      std::string transmitterId() const;
      void setTransmitterId(const std::string& transmitterId);


      // **** signalId ****
      std::string signalId() const;
      void setSignalId(const std::string& signalId);


      // **** initialPhaseOffset ****
      Sdx::optional<double> initialPhaseOffset() const;
      void setInitialPhaseOffset(const Sdx::optional<double>& initialPhaseOffset);


      // **** group ****
      Sdx::optional<int> group() const;
      void setGroup(const Sdx::optional<int>& group);
    };
    
  }
}

