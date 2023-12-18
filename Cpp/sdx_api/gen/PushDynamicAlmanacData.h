#pragma once

#include <memory>
#include "command_base.h"

#include "date_time.h"
#include "gen/AlmanacSVData.h"
#include <string>
#include <vector>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Push a block of data defining the orbit, clock, and other parameters for one SV.
    ///   ParamName           Unit
    ///   "Time of ephemeris" sec (of GPS week)
    ///   "Week Number"       week
    ///   "Transmission Time" sec (of GPS week)
    ///   "ClockBias"         sec
    ///   "ClockDrift"        sec/sec
    ///   "ClockDriftRate"    sec/sec^2
    ///   "DeltaN"            rad/sec
    ///   "M0"                rad
    ///   "Eccentricity"      -
    ///   "SqrtA"             sqrt(meter)
    ///   "BigOmega"          rad
    ///   "I0"                rad
    ///   "LittleOmega"       rad
    ///   "BigOmegaDot"       rad/sec
    ///   "Idot"              rad/sec
    ///
    /// Name    Type                Description
    /// ------- ------------------- ----------------------------------------------
    /// System  string              "GPS", "Galileo", "BeiDou", "QZSS" or "NavIC".
    /// Toa     datetime            Time of applicability.
    /// Almanac array AlmanacSVData Array of almanac data for SVs.
    ///

    class PushDynamicAlmanacData;
    typedef std::shared_ptr<PushDynamicAlmanacData> PushDynamicAlmanacDataPtr;
    
    
    class PushDynamicAlmanacData : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      PushDynamicAlmanacData();

      PushDynamicAlmanacData(const std::string& system, const Sdx::DateTime& toa, const std::vector<Sdx::AlmanacSVData>& almanac);

      static PushDynamicAlmanacDataPtr create(const std::string& system, const Sdx::DateTime& toa, const std::vector<Sdx::AlmanacSVData>& almanac);
      static PushDynamicAlmanacDataPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** system ****
      std::string system() const;
      void setSystem(const std::string& system);


      // **** toa ****
      Sdx::DateTime toa() const;
      void setToa(const Sdx::DateTime& toa);


      // **** almanac ****
      std::vector<Sdx::AlmanacSVData> almanac() const;
      void setAlmanac(const std::vector<Sdx::AlmanacSVData>& almanac);
    };
    
  }
}

