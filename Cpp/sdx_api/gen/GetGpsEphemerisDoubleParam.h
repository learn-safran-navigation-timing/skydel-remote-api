#pragma once

#include <memory>
#include "command_base.h"
#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Please note the command GpsEphemerisDoubleParam is deprecated since 21.3. You may use GpsEphDoubleParamForSV.
    /// 
    /// Get various parameters in the GPS ephemeris
    /// 
    ///   ParamName         Unit
    ///   "ClockBias"       sec
    ///   "ClockDrift"      sec/sec
    ///   "ClockDriftRate"  sec/sec^2
    ///   "Crs"             meter
    ///   "Crc"             meter
    ///   "Cis"             rad
    ///   "Cic"             rad
    ///   "Cus"             rad
    ///   "Cuc"             rad
    ///   "DeltaN"          rad/sec
    ///   "M0"              rad
    ///   "Eccentricity"    -
    ///   "SqrtA"           sqrt(meter)
    ///   "BigOmega"        rad
    ///   "I0"              rad
    ///   "LittleOmega"     rad
    ///   "BigOmegaDot"     rad/sec
    ///   "Idot"            rad/sec
    ///   "Accuracy"        meter
    ///   "Adot"            meters/sec
    ///   "DeltaN0dot"      rad/sec^2
    ///   "Tgd"             sec
    ///   "IscL1Ca"         sec
    ///   "IscL2C"          sec
    ///   "IscL5I5"         sec
    ///   "IscL5Q5"         sec
    ///   "IscL1CP"         sec
    ///   "IscL1CD"         sec
    ///
    /// Name      Type   Description
    /// --------- ------ -------------------------------------------------------------------------
    /// Prn       int    Satellite PRN number 1..32, or use 0 to apply new value to all satellites
    /// ParamName string Parameter name (see table above for accepted names)
    ///

    class GetGpsEphemerisDoubleParam;
    typedef std::shared_ptr<GetGpsEphemerisDoubleParam> GetGpsEphemerisDoubleParamPtr;
    
    
    class GetGpsEphemerisDoubleParam : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetGpsEphemerisDoubleParam();

      GetGpsEphemerisDoubleParam(int prn, const std::string& paramName);
  
      static GetGpsEphemerisDoubleParamPtr create(int prn, const std::string& paramName);
      static GetGpsEphemerisDoubleParamPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** prn ****
      int prn() const;
      void setPrn(int prn);


      // **** paramName ****
      std::string paramName() const;
      void setParamName(const std::string& paramName);
    };
  }
}

