#pragma once

#include <memory>
#include "command_base.h"

#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Set CW pilot added to signal
    ///
    /// Name              Type   Description
    /// ----------------- ------ ---------------------------------------------------
    /// Enabled           bool   Enable (true) or disable (false) the signal
    /// OutputIdx         int    RF Output index (zero-based)
    /// CentralFreqOffset double Central frequency offset of the Pilot (Hz)
    /// Power             double Power (dB), relative to transmitter reference power
    /// PilotId           string CW Pilot unique identifier.
    ///

    class SetPilotCW;
    typedef std::shared_ptr<SetPilotCW> SetPilotCWPtr;
    
    
    class SetPilotCW : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      SetPilotCW();

      SetPilotCW(bool enabled, int outputIdx, double centralFreqOffset, double power, const std::string& pilotId);

      static SetPilotCWPtr create(bool enabled, int outputIdx, double centralFreqOffset, double power, const std::string& pilotId);
      static SetPilotCWPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

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


      // **** pilotId ****
      std::string pilotId() const;
      void setPilotId(const std::string& pilotId);
    };
    
  }
}

