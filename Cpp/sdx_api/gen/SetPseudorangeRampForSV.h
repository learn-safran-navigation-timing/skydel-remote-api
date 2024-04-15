#pragma once

#include <memory>
#include "command_base.h"

#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Set PSR ramp event. This function lets user change the pseudorange of any satellite.
    /// If SV ID is set to 0, the change is applied to all satellites.
    /// 
    ///           Hold Start Time
    ///           |         Hold Stop Time
    ///           |         |
    ///           ...........
    ///          ..         ...
    ///         ..            ...
    ///   .......               .........> Time
    ///         |               |
    ///         Start Time      Stop Time
    /// 
    ///
    /// Name          Type   Description
    /// ------------- ------ ----------------------------------------------------------------------------------
    /// System        string "GPS", "GLONASS", "Galileo", "BeiDou", "SBAS", "QZSS", "NavIC" or "PULSAR"
    /// SvId          int    The satellite's SV ID.
    /// Offset        double Change to satellite pseudorange in meter when ramp is at maximum. Range -1e7..+1e7
    /// StartTime     int    Elapsed time in seconds since start of simulation.
    /// HoldStartTime int    Elapsed time in seconds since start of simulation. HoldStartTime >= StartTime
    /// HoldStopTime  int    Elapsed time in seconds since start of simulation. HoldStopTime >= HoldStartTime
    /// StopTime      int    Elapsed time in seconds since start of simulation. StopTime >= HoldStopTime
    /// Id            string Unique identifier automatically set by simulator if empty string.
    ///                      The IDs pool is common between all system.
    ///

    class SetPseudorangeRampForSV;
    typedef std::shared_ptr<SetPseudorangeRampForSV> SetPseudorangeRampForSVPtr;
    
    
    class SetPseudorangeRampForSV : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      SetPseudorangeRampForSV();

      SetPseudorangeRampForSV(const std::string& system, int svId, double offset, int startTime, int holdStartTime, int holdStopTime, int stopTime, const std::string& id);

      static SetPseudorangeRampForSVPtr create(const std::string& system, int svId, double offset, int startTime, int holdStartTime, int holdStopTime, int stopTime, const std::string& id);
      static SetPseudorangeRampForSVPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;

      virtual int executePermission() const override;


      // **** system ****
      std::string system() const;
      void setSystem(const std::string& system);


      // **** svId ****
      int svId() const;
      void setSvId(int svId);


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

