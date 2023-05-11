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
    /// Result of GetIntTxChirp.
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

    class GetIntTxChirpResult;
    typedef std::shared_ptr<GetIntTxChirpResult> GetIntTxChirpResultPtr;
    
    
    class GetIntTxChirpResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetIntTxChirpResult();

      GetIntTxChirpResult(bool enabled, double centralFreq, double power, double bandwidth, double sweepTime, const std::string& transmitterId, const std::string& signalId, const Sdx::optional<int>& group = {});

      GetIntTxChirpResult(CommandBasePtr relatedCommand, bool enabled, double centralFreq, double power, double bandwidth, double sweepTime, const std::string& transmitterId, const std::string& signalId, const Sdx::optional<int>& group = {});

      static GetIntTxChirpResultPtr create(bool enabled, double centralFreq, double power, double bandwidth, double sweepTime, const std::string& transmitterId, const std::string& signalId, const Sdx::optional<int>& group = {});

      static GetIntTxChirpResultPtr create(CommandBasePtr relatedCommand, bool enabled, double centralFreq, double power, double bandwidth, double sweepTime, const std::string& transmitterId, const std::string& signalId, const Sdx::optional<int>& group = {});
      static GetIntTxChirpResultPtr dynamicCast(CommandBasePtr ptr);
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
    REGISTER_COMMAND_RESULT_TO_FACTORY_DECL(GetIntTxChirpResult);
  }
}

