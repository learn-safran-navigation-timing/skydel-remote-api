#pragma once

#include <memory>
#include "command_base.h"

#include <optional>
#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Please note the command GetQzssEphemerisBoolParams is deprecated since 21.3. You may use GetQzssEphBoolParamForEachSV.
    /// 
    /// Please note the command GetQzssEphBoolParamForEachSV is deprecated since 23.11. You may use GetConstellationParameterForSV.
    /// 
    /// Get QZSS ephemeris boolean parameter value for all satellites
    ///
    /// Name        Type            Description
    /// ----------- --------------- -------------------------------------------------------------------------------------------
    /// ParamName   string          Refer to SetQzssEphemerisBoolParam for accepted names
    /// DataSetName optional string Optional name of the data set to use. If no value is provided, the active data set is used.
    ///

    class GetQzssEphemerisBoolParams;
    typedef std::shared_ptr<GetQzssEphemerisBoolParams> GetQzssEphemerisBoolParamsPtr;
    
    
    class GetQzssEphemerisBoolParams : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;

      static const char* const Deprecated;


      GetQzssEphemerisBoolParams();

      GetQzssEphemerisBoolParams(const std::string& paramName, const std::optional<std::string>& dataSetName = {});

      static GetQzssEphemerisBoolParamsPtr create(const std::string& paramName, const std::optional<std::string>& dataSetName = {});
      static GetQzssEphemerisBoolParamsPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;

      virtual std::optional<std::string> deprecated() const override;

      virtual int executePermission() const override;


      // **** paramName ****
      std::string paramName() const;
      void setParamName(const std::string& paramName);


      // **** dataSetName ****
      std::optional<std::string> dataSetName() const;
      void setDataSetName(const std::optional<std::string>& dataSetName);
    };
    
  }
}

