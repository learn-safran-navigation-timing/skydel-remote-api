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
    /// Result of GetIntTxBOC.
    ///
    /// Name           Type         Description
    /// -------------- ------------ -------------------------------------------------------------------------
    /// Enabled        bool         Enable (true) or disable (false) the signal
    /// CentralFreq    double       Central frequency (Hz)
    /// Power          double       Power (dB), relative to transmitter reference power
    /// CodeRate       int          Code rate (Hz). Must be between 1000 and 60000000 and a multiple of 1KHz.
    /// CodeLengthMs   int          Code length (ms). Must be between 1 and 100.
    /// SubCarrierRate int          Code rate (Hz). Must be between 1000 and 60000000 and a multiple of 1KHz.
    /// CosinePhaseBoc bool         Use Cosine-Phase BOC instead of default Sine-Phase BOC.
    /// TransmitterId  string       Transmitter unique identifier.
    /// SignalId       string       BOC unique identifier.
    /// Group          optional int Group, if not using default group.
    ///

    class GetIntTxBOCResult;
    typedef std::shared_ptr<GetIntTxBOCResult> GetIntTxBOCResultPtr;
    
    
    class GetIntTxBOCResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      GetIntTxBOCResult();

      GetIntTxBOCResult(bool enabled, double centralFreq, double power, int codeRate, int codeLengthMs, int subCarrierRate, bool cosinePhaseBoc, const std::string& transmitterId, const std::string& signalId, const std::optional<int>& group = {});

      GetIntTxBOCResult(CommandBasePtr relatedCommand, bool enabled, double centralFreq, double power, int codeRate, int codeLengthMs, int subCarrierRate, bool cosinePhaseBoc, const std::string& transmitterId, const std::string& signalId, const std::optional<int>& group = {});

      static GetIntTxBOCResultPtr create(bool enabled, double centralFreq, double power, int codeRate, int codeLengthMs, int subCarrierRate, bool cosinePhaseBoc, const std::string& transmitterId, const std::string& signalId, const std::optional<int>& group = {});

      static GetIntTxBOCResultPtr create(CommandBasePtr relatedCommand, bool enabled, double centralFreq, double power, int codeRate, int codeLengthMs, int subCarrierRate, bool cosinePhaseBoc, const std::string& transmitterId, const std::string& signalId, const std::optional<int>& group = {});
      static GetIntTxBOCResultPtr dynamicCast(CommandBasePtr ptr);
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


      // **** codeRate ****
      int codeRate() const;
      void setCodeRate(int codeRate);


      // **** codeLengthMs ****
      int codeLengthMs() const;
      void setCodeLengthMs(int codeLengthMs);


      // **** subCarrierRate ****
      int subCarrierRate() const;
      void setSubCarrierRate(int subCarrierRate);


      // **** cosinePhaseBoc ****
      bool cosinePhaseBoc() const;
      void setCosinePhaseBoc(bool cosinePhaseBoc);


      // **** transmitterId ****
      std::string transmitterId() const;
      void setTransmitterId(const std::string& transmitterId);


      // **** signalId ****
      std::string signalId() const;
      void setSignalId(const std::string& signalId);


      // **** group ****
      std::optional<int> group() const;
      void setGroup(const std::optional<int>& group);
    };
    REGISTER_COMMAND_TO_FACTORY_DECL(GetIntTxBOCResult);
  }
}

