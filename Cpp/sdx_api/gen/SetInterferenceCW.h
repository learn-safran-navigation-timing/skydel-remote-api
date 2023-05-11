#pragma once

#include <memory>
#include "command_base.h"

#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Add or update continuous wave interference.
    ///
    /// Name        Type   Description
    /// ----------- ------ -------------------------------------------------
    /// StartTime   int    Elapsed time in seconds since start of simulation
    /// StopTime    int    Elapsed time in seconds since start of simulation
    /// CentralFreq double Central frequency (Hz)
    /// Power       double Power (dB) relative to nominal power
    /// Enabled     bool   Interference enable or not
    /// Id          string Unique identifier automatically set by simulator
    ///

    class SetInterferenceCW;
    typedef std::shared_ptr<SetInterferenceCW> SetInterferenceCWPtr;
    
    
    class SetInterferenceCW : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      SetInterferenceCW();

      SetInterferenceCW(int startTime, int stopTime, double centralFreq, double power, bool enabled, const std::string& id);

      static SetInterferenceCWPtr create(int startTime, int stopTime, double centralFreq, double power, bool enabled, const std::string& id);
      static SetInterferenceCWPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

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


      // **** enabled ****
      bool enabled() const;
      void setEnabled(bool enabled);


      // **** id ****
      std::string id() const;
      void setId(const std::string& id);
    };
    
  }
}

