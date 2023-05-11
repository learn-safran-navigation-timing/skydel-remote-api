#pragma once

#include <memory>
#include "command_result.h"
#include "command_result_factory.h"
#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of GetPseudorangeRampForSV.
    ///
    /// Name          Type   Description
    /// ------------- ------ ----------------------------------------------------------------------------------
    /// System        string "GPS", "GLONASS", "Galileo", "BeiDou", "SBAS", "QZSS" or "NavIC"
    /// SvId          int    The satellite's SV ID.
    /// Offset        double Change to satellite pseudorange in meter when ramp is at maximum. Range -1e7..+1e7
    /// StartTime     int    Elapsed time in seconds since start of simulation.
    /// HoldStartTime int    Elapsed time in seconds since start of simulation. HoldStartTime >= StartTime
    /// HoldStopTime  int    Elapsed time in seconds since start of simulation. HoldStopTime >= HoldStartTime
    /// StopTime      int    Elapsed time in seconds since start of simulation. StopTime >= HoldStopTime
    /// Id            string Unique identifier automatically set by simulator if empty string.
    ///                      The IDs pool is common between all system.
    ///

    class GetPseudorangeRampForSVResult;
    typedef std::shared_ptr<GetPseudorangeRampForSVResult> GetPseudorangeRampForSVResultPtr;
    
    
    class GetPseudorangeRampForSVResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetPseudorangeRampForSVResult();

      GetPseudorangeRampForSVResult(const std::string& system, int svId, double offset, int startTime, int holdStartTime, int holdStopTime, int stopTime, const std::string& id);

      GetPseudorangeRampForSVResult(CommandBasePtr relatedCommand, const std::string& system, int svId, double offset, int startTime, int holdStartTime, int holdStopTime, int stopTime, const std::string& id);

      static GetPseudorangeRampForSVResultPtr create(const std::string& system, int svId, double offset, int startTime, int holdStartTime, int holdStopTime, int stopTime, const std::string& id);

      static GetPseudorangeRampForSVResultPtr create(CommandBasePtr relatedCommand, const std::string& system, int svId, double offset, int startTime, int holdStartTime, int holdStopTime, int stopTime, const std::string& id);
      static GetPseudorangeRampForSVResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;


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
    REGISTER_COMMAND_RESULT_TO_FACTORY_DECL(GetPseudorangeRampForSVResult);
  }
}

