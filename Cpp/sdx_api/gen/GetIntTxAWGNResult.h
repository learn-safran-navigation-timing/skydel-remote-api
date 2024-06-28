#pragma once

#include <memory>
#include "command_result.h"
#include "command_factory.h"
#include <optional>
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
      static const char* const TargetId;


      GetIntTxAWGNResult();

      GetIntTxAWGNResult(bool enabled, double centralFreq, double power, double bandwidth, const std::string& transmitterId, const std::string& signalId, const std::optional<int>& seed = {}, const std::optional<int>& group = {});

      GetIntTxAWGNResult(CommandBasePtr relatedCommand, bool enabled, double centralFreq, double power, double bandwidth, const std::string& transmitterId, const std::string& signalId, const std::optional<int>& seed = {}, const std::optional<int>& group = {});

      static GetIntTxAWGNResultPtr create(bool enabled, double centralFreq, double power, double bandwidth, const std::string& transmitterId, const std::string& signalId, const std::optional<int>& seed = {}, const std::optional<int>& group = {});

      static GetIntTxAWGNResultPtr create(CommandBasePtr relatedCommand, bool enabled, double centralFreq, double power, double bandwidth, const std::string& transmitterId, const std::string& signalId, const std::optional<int>& seed = {}, const std::optional<int>& group = {});
      static GetIntTxAWGNResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;


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
      std::optional<int> seed() const;
      void setSeed(const std::optional<int>& seed);


      // **** group ****
      std::optional<int> group() const;
      void setGroup(const std::optional<int>& group);
    };
    REGISTER_COMMAND_TO_FACTORY_DECL(GetIntTxAWGNResult);
  }
}

