#pragma once

#include <memory>
#include "command_base.h"
#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Please note the command SetNavICEphemerisDoubleParam is deprecated since 21.3. You may use SetNavICEphDoubleParamForSV.
    /// 
    /// Set various parameters in the NavIC ephemeris
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
    ///
    /// Name      Type   Description
    /// --------- ------ --------------------------------------------------------------------
    /// SvId      int    Satellite SV ID 1..14, or use 0 to apply new value to all satellites
    /// ParamName string Parameter name (see table above for accepted names)
    /// Val       double Parameter value (see table above for unit)
    ///

    class SetNavICEphemerisDoubleParam;
    typedef std::shared_ptr<SetNavICEphemerisDoubleParam> SetNavICEphemerisDoubleParamPtr;
    
    
    class SetNavICEphemerisDoubleParam : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      SetNavICEphemerisDoubleParam();

      SetNavICEphemerisDoubleParam(int svId, const std::string& paramName, double val);
  
      static SetNavICEphemerisDoubleParamPtr create(int svId, const std::string& paramName, double val);
      static SetNavICEphemerisDoubleParamPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** svId ****
      int svId() const;
      void setSvId(int svId);


      // **** paramName ****
      std::string paramName() const;
      void setParamName(const std::string& paramName);


      // **** val ****
      double val() const;
      void setVal(double val);
    };
  }
}

