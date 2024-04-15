#pragma once

#include <memory>
#include "command_base.h"

#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Set PRN pilot added to signal
    ///
    /// Name              Type   Description
    /// ----------------- ------ ---------------------------------------------------
    /// Enabled           bool   Enable (true) or disable (false) the signal
    /// OutputIdx         int    RF Output index (zero-based)
    /// CentralFreqOffset double Central frequency offset of the Pilot (Hz)
    /// Power             double Power (dB), relative to transmitter reference power
    /// Prn               int    The PRN to use
    /// Type              string The type of PRN to use (CA or Gold)
    /// PilotId           string CW Pilot unique identifier.
    ///

    class SetPilotPRN;
    typedef std::shared_ptr<SetPilotPRN> SetPilotPRNPtr;
    
    
    class SetPilotPRN : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      SetPilotPRN();

      SetPilotPRN(bool enabled, int outputIdx, double centralFreqOffset, double power, int prn, const std::string& type, const std::string& pilotId);

      static SetPilotPRNPtr create(bool enabled, int outputIdx, double centralFreqOffset, double power, int prn, const std::string& type, const std::string& pilotId);
      static SetPilotPRNPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;

      virtual int executePermission() const override;


      // **** enabled ****
      bool enabled() const;
      void setEnabled(bool enabled);


      // **** outputIdx ****
      int outputIdx() const;
      void setOutputIdx(int outputIdx);


      // **** centralFreqOffset ****
      double centralFreqOffset() const;
      void setCentralFreqOffset(double centralFreqOffset);


      // **** power ****
      double power() const;
      void setPower(double power);


      // **** prn ****
      int prn() const;
      void setPrn(int prn);


      // **** type ****
      std::string type() const;
      void setType(const std::string& type);


      // **** pilotId ****
      std::string pilotId() const;
      void setPilotId(const std::string& pilotId);
    };
    
  }
}

