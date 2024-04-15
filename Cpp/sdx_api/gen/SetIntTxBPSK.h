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
    /// Set BPSK signal interference.
    ///
    /// Name          Type         Description
    /// ------------- ------------ -------------------------------------------------------------------------
    /// Enabled       bool         Enable (true) or disable (false) the signal
    /// CentralFreq   double       Central frequency (Hz).
    /// Power         double       Power (dB), relative to transmitter reference power.
    /// CodeRate      int          Code rate (Hz). Must be between 1000 and 60000000 and a multiple of 1KHz.
    /// CodeLengthMs  int          Code length (ms). Must be between 1 and 100.
    /// TransmitterId string       Transmitter unique identifier.
    /// SignalId      string       BPSK unique identifier.
    /// Group         optional int Group, if not using default group.
    /// Prn           optional int Prn code to use. If not specified, a random gode will be generated.
    ///

    class SetIntTxBPSK;
    typedef std::shared_ptr<SetIntTxBPSK> SetIntTxBPSKPtr;
    
    
    class SetIntTxBPSK : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      SetIntTxBPSK();

      SetIntTxBPSK(bool enabled, double centralFreq, double power, int codeRate, int codeLengthMs, const std::string& transmitterId, const std::string& signalId, const Sdx::optional<int>& group = {}, const Sdx::optional<int>& prn = {});

      static SetIntTxBPSKPtr create(bool enabled, double centralFreq, double power, int codeRate, int codeLengthMs, const std::string& transmitterId, const std::string& signalId, const Sdx::optional<int>& group = {}, const Sdx::optional<int>& prn = {});
      static SetIntTxBPSKPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;

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


      // **** codeRate ****
      int codeRate() const;
      void setCodeRate(int codeRate);


      // **** codeLengthMs ****
      int codeLengthMs() const;
      void setCodeLengthMs(int codeLengthMs);


      // **** transmitterId ****
      std::string transmitterId() const;
      void setTransmitterId(const std::string& transmitterId);


      // **** signalId ****
      std::string signalId() const;
      void setSignalId(const std::string& signalId);


      // **** group ****
      Sdx::optional<int> group() const;
      void setGroup(const Sdx::optional<int>& group);


      // **** prn ****
      Sdx::optional<int> prn() const;
      void setPrn(const Sdx::optional<int>& prn);
    };
    
  }
}

