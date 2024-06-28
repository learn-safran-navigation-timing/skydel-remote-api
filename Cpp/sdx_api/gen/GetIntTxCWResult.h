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
    /// Result of GetIntTxCW.
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

    class GetIntTxCWResult;
    typedef std::shared_ptr<GetIntTxCWResult> GetIntTxCWResultPtr;
    
    
    class GetIntTxCWResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      GetIntTxCWResult();

      GetIntTxCWResult(bool enabled, double centralFreq, double power, const std::string& transmitterId, const std::string& signalId, const std::optional<double>& initialPhaseOffset = {}, const std::optional<int>& group = {});

      GetIntTxCWResult(CommandBasePtr relatedCommand, bool enabled, double centralFreq, double power, const std::string& transmitterId, const std::string& signalId, const std::optional<double>& initialPhaseOffset = {}, const std::optional<int>& group = {});

      static GetIntTxCWResultPtr create(bool enabled, double centralFreq, double power, const std::string& transmitterId, const std::string& signalId, const std::optional<double>& initialPhaseOffset = {}, const std::optional<int>& group = {});

      static GetIntTxCWResultPtr create(CommandBasePtr relatedCommand, bool enabled, double centralFreq, double power, const std::string& transmitterId, const std::string& signalId, const std::optional<double>& initialPhaseOffset = {}, const std::optional<int>& group = {});
      static GetIntTxCWResultPtr dynamicCast(CommandBasePtr ptr);
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


      // **** transmitterId ****
      std::string transmitterId() const;
      void setTransmitterId(const std::string& transmitterId);


      // **** signalId ****
      std::string signalId() const;
      void setSignalId(const std::string& signalId);


      // **** initialPhaseOffset ****
      std::optional<double> initialPhaseOffset() const;
      void setInitialPhaseOffset(const std::optional<double>& initialPhaseOffset);


      // **** group ****
      std::optional<int> group() const;
      void setGroup(const std::optional<int>& group);
    };
    REGISTER_COMMAND_TO_FACTORY_DECL(GetIntTxCWResult);
  }
}

