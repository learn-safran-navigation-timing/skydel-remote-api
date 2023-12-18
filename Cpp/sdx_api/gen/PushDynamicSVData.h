#pragma once

#include <memory>
#include "command_base.h"

#include "date_time.h"
#include "sdx_optional.h"
#include <map>
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
    ///   "Crs"               meter
    ///   "Crc"               meter
    ///   "Cis"               rad
    ///   "Cic"               rad
    ///   "Cus"               rad
    ///   "Cuc"               rad
    ///   "DeltaN"            rad/sec
    ///   "M0"                rad
    ///   "Eccentricity"      -
    ///   "SqrtA"             sqrt(meter)
    ///   "BigOmega"          rad
    ///   "I0"                rad
    ///   "LittleOmega"       rad
    ///   "BigOmegaDot"       rad/sec
    ///   "Idot"              rad/sec
    ///   "Accuracy"          meter
    ///   "Adot"              meters/sec
    ///   "DeltaN0dot"        rad/sec^2
    /// 
    /// After a block is pushed for a SV, no other block can be pushed for that SV until the interpolation period is over.
    ///   Constellation   Interpolation period (sec)
    ///   GPS             3600
    ///   Galileo         300
    ///   BeiDou          1800
    ///   QZSS            1800
    ///   NavIC           2400
    /// 
    ///
    /// Name           Type                  Description
    /// -------------- --------------------- ---------------------------------------------------------------------------------------
    /// System         string                "GPS", "Galileo", "BeiDou", "QZSS" or "NavIC".
    /// SvId           int                   Satellite's SV ID.
    /// Toc            datetime              Time of Clock.
    /// ParametersDict dict string:double    A dictionary of parameters pairs.
    ///                                      Accepted keys are: "Time of ephemeris", "Week Number", "Transmission Time",
    ///                                                         "ClockBias", "ClockDrift", "ClockDriftRate", "Crs", "Crc",
    ///                                                         "Cis", "Cic", "Cus", "Cuc", "DeltaN", "M0", "Eccentricity",
    ///                                                         "SqrtA", "BigOmega", "I0", "LittleOmega", "BigOmegaDot",
    ///                                                         "Idot", "Adot", "DeltaN0dot", "UraIndex", "IODE", "IODNAV",
    ///                                                         "IODEC", "IODC", "Tgd", "IscL1CA", "IscL2C", "IscL5I5",
    ///                                                         "IscL5Q5", "IscL1CP", "IscL1CD", "BgdE1E5a", "BgdE1E5b",
    ///                                                         "Tgd1", "Tgd2", "TgdB1Cp", "TgdB2ap", "IscB1Cd", "IscB2ad",
    ///                                                         "SisaE1E5a" and "SisaE1E5b"
    /// DataSetTypes   optional array string Optional data set type array: "Ephemeris" or "Orbit". If not provided, applies to both.
    ///

    class PushDynamicSVData;
    typedef std::shared_ptr<PushDynamicSVData> PushDynamicSVDataPtr;
    
    
    class PushDynamicSVData : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      PushDynamicSVData();

      PushDynamicSVData(const std::string& system, int svId, const Sdx::DateTime& toc, const std::map<std::string, double>& parametersDict, const Sdx::optional<std::vector<std::string>>& dataSetTypes = {});

      static PushDynamicSVDataPtr create(const std::string& system, int svId, const Sdx::DateTime& toc, const std::map<std::string, double>& parametersDict, const Sdx::optional<std::vector<std::string>>& dataSetTypes = {});
      static PushDynamicSVDataPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** system ****
      std::string system() const;
      void setSystem(const std::string& system);


      // **** svId ****
      int svId() const;
      void setSvId(int svId);


      // **** toc ****
      Sdx::DateTime toc() const;
      void setToc(const Sdx::DateTime& toc);


      // **** parametersDict ****
      std::map<std::string, double> parametersDict() const;
      void setParametersDict(const std::map<std::string, double>& parametersDict);


      // **** dataSetTypes ****
      Sdx::optional<std::vector<std::string>> dataSetTypes() const;
      void setDataSetTypes(const Sdx::optional<std::vector<std::string>>& dataSetTypes);
    };
    
  }
}

