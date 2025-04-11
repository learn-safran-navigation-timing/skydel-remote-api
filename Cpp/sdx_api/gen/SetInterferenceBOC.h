#pragma once

#include <memory>
#include "command_base.h"

#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Add or update a BOC interference signal.
    ///
    /// Name           Type   Description
    /// -------------- ------ -------------------------------------------------------------------------------------------------------------------------------------
    /// StartTime      int    Elapsed time at which the signal is enabled (s). Minimum = 0 s, Maximum = 86399 s (23 hours, 59 minutes and 59 seconds).
    /// StopTime       int    Elapsed time at which the signal is disabled (s). Minimum = 0 s, Maximum = 86399 s (23 hours, 59 minutes and 59 seconds).
    /// CentralFreq    double Central frequency (Hz). Minimum = 100000000 Hz (100 MHz), Maximum = 6000000000 Hz (6 GHz).
    /// Power          double Power (dB) relative to nominal power. Minimum = -40 dB, Maximum = 43 dB.
    /// CodeRate       int    Code rate (Chips/s). Must be a multiple of 1 kChips/s. Minimum = 1000 Chips/s (1 kChips/s), Maximum = 60000000 Chips/s (60 MChips/s).
    /// CodeLengthMs   int    Code length (ms). Minimum = 1 ms, Maximum = 100 ms.
    /// SubCarrierRate int    Sub-carrier rate (Hz). Must be a multiple of 1 kHz. Minimum = 1000 Hz (1 kHz), Maximum = 60000000 (60 MHz).
    /// CosinePhaseBoc bool   Use Cosine-Phase BOC instead of default Sine-Phase BOC.
    /// Enabled        bool   Enables or disables the interference signal.
    /// Id             string Interference signal unique identifier.
    ///

    class SetInterferenceBOC;
    typedef std::shared_ptr<SetInterferenceBOC> SetInterferenceBOCPtr;
    
    
    class SetInterferenceBOC : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      SetInterferenceBOC();

      SetInterferenceBOC(int startTime, int stopTime, double centralFreq, double power, int codeRate, int codeLengthMs, int subCarrierRate, bool cosinePhaseBoc, bool enabled, const std::string& id);

      static SetInterferenceBOCPtr create(int startTime, int stopTime, double centralFreq, double power, int codeRate, int codeLengthMs, int subCarrierRate, bool cosinePhaseBoc, bool enabled, const std::string& id);
      static SetInterferenceBOCPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;

      virtual int executePermission() const override;


      // **** startTime ****
      int startTime() const;
      void setStartTime(int startTime);


      // **** stopTime ****
      int stopTime() const;
      void setStopTime(int stopTime);


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


      // **** enabled ****
      bool enabled() const;
      void setEnabled(bool enabled);


      // **** id ****
      std::string id() const;
      void setId(const std::string& id);
    };
    
  }
}

