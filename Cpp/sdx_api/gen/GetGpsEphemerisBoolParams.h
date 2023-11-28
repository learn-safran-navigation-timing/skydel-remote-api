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
    /// Please note the command GetGpsEphemerisBoolParams is deprecated since 21.3. You may use GetGpsEphBoolParamForEachSV.
    /// 
    /// Please note the command GetGpsEphBoolParamForEachSV is deprecated since 23.11. You may use GetConstellationParameterForSV.
    /// 
    /// Get GPS ephemeris boolean parameter value for all satellites
    ///
    /// Name        Type            Description
    /// ----------- --------------- -------------------------------------------------------------------------------------------
    /// ParamName   string          Refer to SetGpsEphBoolParamForSV for accepted names
    /// DataSetName optional string Optional name of the data set to use. If no value is provided, the active data set is used.
    ///

    class GetGpsEphemerisBoolParams;
    typedef std::shared_ptr<GetGpsEphemerisBoolParams> GetGpsEphemerisBoolParamsPtr;
    
    
    class GetGpsEphemerisBoolParams : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;

      static const char* const Deprecated;


      GetGpsEphemerisBoolParams();

      GetGpsEphemerisBoolParams(const std::string& paramName, const Sdx::optional<std::string>& dataSetName = {});

      static GetGpsEphemerisBoolParamsPtr create(const std::string& paramName, const Sdx::optional<std::string>& dataSetName = {});
      static GetGpsEphemerisBoolParamsPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual Sdx::optional<std::string> deprecated() const override;

      virtual int executePermission() const override;


      // **** paramName ****
      std::string paramName() const;
      void setParamName(const std::string& paramName);


      // **** dataSetName ****
      Sdx::optional<std::string> dataSetName() const;
      void setDataSetName(const Sdx::optional<std::string>& dataSetName);
    };
    
  }
}

