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
    /// Set Chirp signal to interference transmitter. A transmitter can combine
    /// multiple signals of different types to create complex waveform. The signal id (SignalId) can be an empty
    /// string. In such case, Skydel will assign a unique ID. If the signal id is already in use for the
    /// specified transmitted, the existing signal is updated, ortherwise a new signal is added.
    ///
    /// Name          Type         Description
    /// ------------- ------------ ---------------------------------------------------
    /// Enabled       bool         Enable (true) or disable (false) the signal
    /// CentralFreq   double       Central frequency (Hz)
    /// Power         double       Power (dB), relative to transmitter reference power
    /// Bandwidth     double       Bandwidth (Hz)
    /// SweepTime     double       sweep Time (us)
    /// TransmitterId string       Transmitter unique identifier.
    /// SignalId      string       Chirp unique identifier.
    /// Group         optional int Group, if not using default group.
    ///

    class SetIntTxChirp;
    typedef std::shared_ptr<SetIntTxChirp> SetIntTxChirpPtr;
    
    
    class SetIntTxChirp : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      SetIntTxChirp();

      SetIntTxChirp(bool enabled, double centralFreq, double power, double bandwidth, double sweepTime, const std::string& transmitterId, const std::string& signalId, const Sdx::optional<int>& group = {});

      static SetIntTxChirpPtr create(bool enabled, double centralFreq, double power, double bandwidth, double sweepTime, const std::string& transmitterId, const std::string& signalId, const Sdx::optional<int>& group = {});
      static SetIntTxChirpPtr dynamicCast(CommandBasePtr ptr);
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


      // **** bandwidth ****
      double bandwidth() const;
      void setBandwidth(double bandwidth);


      // **** sweepTime ****
      double sweepTime() const;
      void setSweepTime(double sweepTime);


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

