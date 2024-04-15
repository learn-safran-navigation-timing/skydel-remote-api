#pragma once

#include <memory>
#include "command_base.h"

#include "sdx_optional.h"
#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Please note the command SetNavICEphDoubleParamForSV is deprecated since 23.11. You may use SetConstellationParameterForSV.
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
    /// Name        Type            Description
    /// ----------- --------------- -------------------------------------------------------------------------------------------
    /// SvId        int             Satellite SV ID 1..14, or use 0 to apply new value to all satellites
    /// ParamName   string          Parameter name (see table above for accepted names)
    /// Val         double          Parameter value (see table above for unit)
    /// DataSetName optional string Optional name of the data set to use. If no value is provided, the active data set is used.
    ///

    class SetNavICEphDoubleParamForSV;
    typedef std::shared_ptr<SetNavICEphDoubleParamForSV> SetNavICEphDoubleParamForSVPtr;
    
    
    class SetNavICEphDoubleParamForSV : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;

      static const char* const Deprecated;


      SetNavICEphDoubleParamForSV();

      SetNavICEphDoubleParamForSV(int svId, const std::string& paramName, double val, const Sdx::optional<std::string>& dataSetName = {});

      static SetNavICEphDoubleParamForSVPtr create(int svId, const std::string& paramName, double val, const Sdx::optional<std::string>& dataSetName = {});
      static SetNavICEphDoubleParamForSVPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;

      virtual Sdx::optional<std::string> deprecated() const override;

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


      // **** dataSetName ****
      Sdx::optional<std::string> dataSetName() const;
      void setDataSetName(const Sdx::optional<std::string>& dataSetName);
    };
    
  }
}

