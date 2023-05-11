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
    /// Result of GetIntTxAWGN.
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

    class GetIntTxAWGNResult;
    typedef std::shared_ptr<GetIntTxAWGNResult> GetIntTxAWGNResultPtr;
    
    
    class GetIntTxAWGNResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetIntTxAWGNResult();

      GetIntTxAWGNResult(bool enabled, double centralFreq, double power, double bandwidth, const std::string& transmitterId, const std::string& signalId, const Sdx::optional<int>& seed = {}, const Sdx::optional<int>& group = {});

      GetIntTxAWGNResult(CommandBasePtr relatedCommand, bool enabled, double centralFreq, double power, double bandwidth, const std::string& transmitterId, const std::string& signalId, const Sdx::optional<int>& seed = {}, const Sdx::optional<int>& group = {});

      static GetIntTxAWGNResultPtr create(bool enabled, double centralFreq, double power, double bandwidth, const std::string& transmitterId, const std::string& signalId, const Sdx::optional<int>& seed = {}, const Sdx::optional<int>& group = {});

      static GetIntTxAWGNResultPtr create(CommandBasePtr relatedCommand, bool enabled, double centralFreq, double power, double bandwidth, const std::string& transmitterId, const std::string& signalId, const Sdx::optional<int>& seed = {}, const Sdx::optional<int>& group = {});
      static GetIntTxAWGNResultPtr dynamicCast(CommandBasePtr ptr);
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
    REGISTER_COMMAND_RESULT_TO_FACTORY_DECL(GetIntTxAWGNResult);
  }
}

