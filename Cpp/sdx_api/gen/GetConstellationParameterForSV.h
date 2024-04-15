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
    /// Get "GPS", "Galileo", "BeiDou", "QZSS", "NavIC" or "PULSAR" constellation parameter value.
    /// 
    /// General constellation parameters:
    /// 
    ///   Unit         Type     ParamName
    ///   sec          double   "ClockBias"
    ///   sec/sec      double   "ClockDrift"
    ///   sec/sec^2    double   "ClockDriftRate"
    ///   meter        double   "Crs", "Crc", "Accuracy"
    ///   meter/sec    double   "Adot"
    ///   rad          double   "Cis", "Cic", "Cus", "Cuc", "M0", "BigOmega", "I0", "LittleOmega"
    ///   rad/sec      double   "DeltaN", "BigOmegaDot", "Idot" 
    ///   rad/sec^2    double   "DeltaN0dot"
    ///   sqrt(meter)  double   "SqrtA"  
    ///   -            double   "Eccentricity"
    ///   -            integer  "Week Number", "Toe", "Transmission Time"
    /// 
    /// GPS:
    /// 
    ///   Unit         Type     ParamName
    ///   sec          double   "Tgd", "IscL1Ca", "IscL2C", "IscL5I5", "IscL5Q5", "IscL1CP", "IscL1CD", "IscL1ME", "IscL2ME", "IscL1MR", "IscL2MR"
    ///   sec          integer  "Fit interval"
    ///   -            integer  "IODE", "IODC", "UraIndex"
    ///   -            boolean  "IscL1CaAvailable", "IscL2CAvailable", "IscL5I5Available", "IscL5Q5Available", "IscL1CPAvailable", "IscL1CDAvailable", "IscL1MEAvailable", "IscL2MEAvailable", "IscL1MRAvailable", "IscL2MRAvailable"
    /// 
    /// Galileo:
    /// 
    ///   Unit         Type     ParamName
    ///   sec          double   "Tgd"
    ///   ns           double   "BgdE1E5a", "BgdE1E5b"
    ///   -            integer  "SisaE1E5a", "SisaE1E5b", "IODNAV" 
    /// 
    /// BeiDou:
    /// 
    ///   Unit         Type     ParamName
    ///   sec          double   "Tgd1", "Tgd2", "TgdB1Cp", "TgdB2Ap"
    ///   -            integer  "IODE", "IODC", "AODE", "AODC"
    ///   -            boolean  "IscB1CdAvailable", "IscB2adAvailable"
    /// 
    /// QZSS:
    /// 
    ///   Unit         Type     ParamName
    ///   sec          double   "Tgd", "IscL1Ca", "IscL2C", "IscL5I5", "IscL5Q5", "IscL1CP", "IscL1CD"
    ///   sec          integer  "Fit interval"
    ///   -            integer  "IODE", "IODC", "UraIndex"
    ///   -            boolean  "IscL1CaAvailable", "IscL2CAvailable", "IscL5I5Available", "IscL5Q5Available", "IscL1CPAvailable", "IscL1CDAvailable"
    /// 
    /// NavIC:
    /// 
    ///   Unit         Type     ParamName
    ///   sec          double   "Tgd"
    ///   -            integer  "IODEC", "UraIndex"
    ///
    /// Name        Type            Description
    /// ----------- --------------- -------------------------------------------------------------------------------------------
    /// System      string          "GPS", "Galileo", "BeiDou", "QZSS", "NavIC" or "PULSAR".
    /// SvId        int             The Satellite SV ID, or use 0 to apply new value to all satellites.
    /// ParamName   string          Parameter name (see table above for accepted names).
    /// DataSetName optional string Optional name of the data set to use. If no value is provided, the active data set is used.
    ///

    class GetConstellationParameterForSV;
    typedef std::shared_ptr<GetConstellationParameterForSV> GetConstellationParameterForSVPtr;
    
    
    class GetConstellationParameterForSV : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      GetConstellationParameterForSV();

      GetConstellationParameterForSV(const std::string& system, int svId, const std::string& paramName, const Sdx::optional<std::string>& dataSetName = {});

      static GetConstellationParameterForSVPtr create(const std::string& system, int svId, const std::string& paramName, const Sdx::optional<std::string>& dataSetName = {});
      static GetConstellationParameterForSVPtr dynamicCast(CommandBasePtr ptr);
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


      // **** paramName ****
      std::string paramName() const;
      void setParamName(const std::string& paramName);


      // **** dataSetName ****
      Sdx::optional<std::string> dataSetName() const;
      void setDataSetName(const Sdx::optional<std::string>& dataSetName);
    };
    
  }
}

