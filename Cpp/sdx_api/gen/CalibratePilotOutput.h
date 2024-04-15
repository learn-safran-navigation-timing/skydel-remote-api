#pragma once

#include <memory>
#include "command_base.h"



namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Calibrate a pilot output
    ///
    /// Name         Type   Description
    /// ------------ ------ ---------------------------------------------------
    /// OutputIdx    int    RF Output index (zero-based)
    /// Power        double Power (dB), relative to transmitter reference power
    /// Time         double Code time offset in second
    /// CarrierPhase double Carrier phase offset in radians
    ///

    class CalibratePilotOutput;
    typedef std::shared_ptr<CalibratePilotOutput> CalibratePilotOutputPtr;
    
    
    class CalibratePilotOutput : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      CalibratePilotOutput();

      CalibratePilotOutput(int outputIdx, double power, double time, double carrierPhase);

      static CalibratePilotOutputPtr create(int outputIdx, double power, double time, double carrierPhase);
      static CalibratePilotOutputPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;

      virtual int executePermission() const override;


      // **** outputIdx ****
      int outputIdx() const;
      void setOutputIdx(int outputIdx);


      // **** power ****
      double power() const;
      void setPower(double power);


      // **** time ****
      double time() const;
      void setTime(double time);


      // **** carrierPhase ****
      double carrierPhase() const;
      void setCarrierPhase(double carrierPhase);
    };
    
  }
}

