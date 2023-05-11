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
    /// Set AWGN signal interference.
    ///
    /// Name          Type         Description
    /// ------------- ------------ ------------------------------------------------------------------------------------------
    /// Enabled       bool         Enable (true) or disable (false) the signal
    /// CentralFreq   double       Central frequency (Hz)
    /// Power         double       Power (dB), relative to transmitter reference power
    /// Bandwidth     double       Bandwidth (Hz)
    /// TransmitterId string       Transmitter unique identifier.
    /// SignalId      string       AWGN unique identifier.
    /// Seed          optional int Seed for the random number generator. Signals with the same seed will have the same shape.
    /// Group         optional int Group, if not using default group.
    ///

    class SetIntTxAWGN;
    typedef std::shared_ptr<SetIntTxAWGN> SetIntTxAWGNPtr;
    
    
    class SetIntTxAWGN : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      SetIntTxAWGN();

      SetIntTxAWGN(bool enabled, double centralFreq, double power, double bandwidth, const std::string& transmitterId, const std::string& signalId, const Sdx::optional<int>& seed = {}, const Sdx::optional<int>& group = {});

      static SetIntTxAWGNPtr create(bool enabled, double centralFreq, double power, double bandwidth, const std::string& transmitterId, const std::string& signalId, const Sdx::optional<int>& seed = {}, const Sdx::optional<int>& group = {});
      static SetIntTxAWGNPtr dynamicCast(CommandBasePtr ptr);
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


      // **** transmitterId ****
      std::string transmitterId() const;
      void setTransmitterId(const std::string& transmitterId);


      // **** signalId ****
      std::string signalId() const;
      void setSignalId(const std::string& signalId);


      // **** seed ****
      Sdx::optional<int> seed() const;
      void setSeed(const Sdx::optional<int>& seed);


      // **** group ****
      Sdx::optional<int> group() const;
      void setGroup(const Sdx::optional<int>& group);
    };
    
  }
}

