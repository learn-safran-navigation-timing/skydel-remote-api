#pragma once

#include <memory>
#include "command_base.h"

#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Add or update chirp signal interference.
    ///
    /// Name        Type   Description
    /// ----------- ------ -------------------------------------------------
    /// StartTime   int    Elapsed time in seconds since start of simulation
    /// StopTime    int    Elapsed time in seconds since start of simulation
    /// CentralFreq double Central frequency (Hz)
    /// Power       double Power (dB) relative to nominal power
    /// Bandwidth   double Bandwidth (Hz)
    /// SweepTime   double Sweep Time (us)
    /// Enabled     bool   Interference enable or not
    /// Id          string Unique identifier automatically set by simulator
    ///

    class SetInterferenceChirp;
    typedef std::shared_ptr<SetInterferenceChirp> SetInterferenceChirpPtr;
    
    
    class SetInterferenceChirp : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      SetInterferenceChirp();

      SetInterferenceChirp(int startTime, int stopTime, double centralFreq, double power, double bandwidth, double sweepTime, bool enabled, const std::string& id);

      static SetInterferenceChirpPtr create(int startTime, int stopTime, double centralFreq, double power, double bandwidth, double sweepTime, bool enabled, const std::string& id);
      static SetInterferenceChirpPtr dynamicCast(CommandBasePtr ptr);
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


      // **** bandwidth ****
      double bandwidth() const;
      void setBandwidth(double bandwidth);


      // **** sweepTime ****
      double sweepTime() const;
      void setSweepTime(double sweepTime);


      // **** enabled ****
      bool enabled() const;
      void setEnabled(bool enabled);


      // **** id ****
      std::string id() const;
      void setId(const std::string& id);
    };
    
  }
}

