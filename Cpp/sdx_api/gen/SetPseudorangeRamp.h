#pragma once

#include <memory>
#include "command_base.h"
#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Please note the command SetPseudorangeRamp is deprecated since 21.3. You may use SetPseudorangeRampForSV.
    /// 
    /// Set PSR ramp event. This function lets user change the pseudorange of any satellite.
    /// If PRN is set to 0, the change is applied to all satellites.
    /// 
    ///          Hold Start Time
    ///          |     Hold Stop Time
    ///          |     |
    ///          ...........
    ///        ..       ...
    ///        ..        ...
    ///   .......           .........> Time
    ///       |           |
    ///       Start Time      Stop Time
    /// 
    ///
    /// Name          Type   Description
    /// ------------- ------ ----------------------------------------------------------------------------------------------------------
    /// System        string "GPS", "GLONASS", "Galileo", "BeiDou", "SBAS", "QZSS" or "NavIC"
    /// Prn           int    Satellite PRN number for GPS, Galileo, BeiDou and SBAS. Slot number for GLONASS. SV ID for QZSS and NavIC.
    /// Offset        double Change to satellite pseudorange in meter when ramp is at maximum. Range -1e7..+1e7
    /// StartTime     int    Elapsed time in seconds since start of simulation.
    /// HoldStartTime int    Elapsed time in seconds since start of simulation. HoldStartTime >= StartTime
    /// HoldStopTime  int    Elapsed time in seconds since start of simulation. HoldStopTime >= HoldStartTime
    /// StopTime      int    Elapsed time in seconds since start of simulation. StopTime >= HoldStopTime
    /// Id            string Unique identifier automatically set by simulator.
    ///

    class SetPseudorangeRamp;
    typedef std::shared_ptr<SetPseudorangeRamp> SetPseudorangeRampPtr;
    
    
    class SetPseudorangeRamp : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      SetPseudorangeRamp();

      SetPseudorangeRamp(const std::string& system, int prn, double offset, int startTime, int holdStartTime, int holdStopTime, int stopTime, const std::string& id);
  
      static SetPseudorangeRampPtr create(const std::string& system, int prn, double offset, int startTime, int holdStartTime, int holdStopTime, int stopTime, const std::string& id);
      static SetPseudorangeRampPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** system ****
      std::string system() const;
      void setSystem(const std::string& system);


      // **** prn ****
      int prn() const;
      void setPrn(int prn);


      // **** offset ****
      double offset() const;
      void setOffset(double offset);


      // **** startTime ****
      int startTime() const;
      void setStartTime(int startTime);


      // **** holdStartTime ****
      int holdStartTime() const;
      void setHoldStartTime(int holdStartTime);


      // **** holdStopTime ****
      int holdStopTime() const;
      void setHoldStopTime(int holdStopTime);


      // **** stopTime ****
      int stopTime() const;
      void setStopTime(int stopTime);


      // **** id ****
      std::string id() const;
      void setId(const std::string& id);
    };
  }
}

