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
    /// Please note the command GetQzssEphemerisBoolParam is deprecated since 21.3. You may use GetQzssEphBoolParamForSV.
    /// 
    /// Please note the command GetQzssEphBoolParamForSV is deprecated since 23.11. You may use GetConstellationParameterForSV.
    /// 
    /// Get various boolean parameters in the QZSS ephemeris
    /// 
    ///   ParamName
    /// "IscL1CaAvailable"
    /// "IscL2CAvailable"
    /// "IscL5I5Available"
    /// "IscL5Q5Available"
    /// "IscL1CPAvailable"
    /// "IscL1CDAvailable"
    ///
    /// Name        Type            Description
    /// ----------- --------------- -------------------------------------------------------------------------------------------
    /// SvId        int             Satellite SV ID 1..10, or use 0 to apply new value to all satellites
    /// ParamName   string          Parameter name (see table above for accepted names)
    /// DataSetName optional string Optional name of the data set to use. If no value is provided, the active data set is used.
    ///

    class GetQzssEphemerisBoolParam;
    typedef std::shared_ptr<GetQzssEphemerisBoolParam> GetQzssEphemerisBoolParamPtr;
    
    
    class GetQzssEphemerisBoolParam : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;

      static const char* const Deprecated;


      GetQzssEphemerisBoolParam();

      GetQzssEphemerisBoolParam(int svId, const std::string& paramName, const Sdx::optional<std::string>& dataSetName = {});

      static GetQzssEphemerisBoolParamPtr create(int svId, const std::string& paramName, const Sdx::optional<std::string>& dataSetName = {});
      static GetQzssEphemerisBoolParamPtr dynamicCast(CommandBasePtr ptr);
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


      // **** dataSetName ****
      Sdx::optional<std::string> dataSetName() const;
      void setDataSetName(const Sdx::optional<std::string>& dataSetName);
    };
    
  }
}

