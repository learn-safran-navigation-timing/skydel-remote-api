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


      GetIntTxCWResult();

      GetIntTxCWResult(bool enabled, double centralFreq, double power, const std::string& transmitterId, const std::string& signalId, const Sdx::optional<double>& initialPhaseOffset = {}, const Sdx::optional<int>& group = {});

      GetIntTxCWResult(CommandBasePtr relatedCommand, bool enabled, double centralFreq, double power, const std::string& transmitterId, const std::string& signalId, const Sdx::optional<double>& initialPhaseOffset = {}, const Sdx::optional<int>& group = {});

      static GetIntTxCWResultPtr create(bool enabled, double centralFreq, double power, const std::string& transmitterId, const std::string& signalId, const Sdx::optional<double>& initialPhaseOffset = {}, const Sdx::optional<int>& group = {});

      static GetIntTxCWResultPtr create(CommandBasePtr relatedCommand, bool enabled, double centralFreq, double power, const std::string& transmitterId, const std::string& signalId, const Sdx::optional<double>& initialPhaseOffset = {}, const Sdx::optional<int>& group = {});
      static GetIntTxCWResultPtr dynamicCast(CommandBasePtr ptr);
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
    REGISTER_COMMAND_RESULT_TO_FACTORY_DECL(GetIntTxCWResult);
  }
}

