#pragma once

#include <memory>
#include "command_base.h"

#include <optional>
#include <string>
#include <vector>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Please note the command SetQzssEphemerisBoolParams is deprecated since 21.3. You may use SetQzssEphBoolParamForEachSV.
    /// 
    /// Please note the command SetQzssEphBoolParamForEachSV is deprecated since 23.11. You may use SetConstellationParameterForSV.
    /// 
    /// Set QZSS ephemeris boolean parameter value for all satellites
    ///
    /// Name        Type            Description
    /// ----------- --------------- --------------------------------------------------------------------------------------------------
    /// ParamName   string          Refer to SetQzssEphemerisBoolParam for accepted names
    /// Val         array bool      Parameter value for each satellite. Zero based index (index 0 => SV ID 1, index 1 => SV ID 2, etc)
    /// DataSetName optional string Optional name of the data set to use. If no value is provided, the active data set is used.
    ///

    class SetQzssEphemerisBoolParams;
    typedef std::shared_ptr<SetQzssEphemerisBoolParams> SetQzssEphemerisBoolParamsPtr;
    
    
    class SetQzssEphemerisBoolParams : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;

      static const char* const Deprecated;


      SetQzssEphemerisBoolParams();

      SetQzssEphemerisBoolParams(const std::string& paramName, const std::vector<bool>& val, const std::optional<std::string>& dataSetName = {});

      static SetQzssEphemerisBoolParamsPtr create(const std::string& paramName, const std::vector<bool>& val, const std::optional<std::string>& dataSetName = {});
      static SetQzssEphemerisBoolParamsPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;

      virtual std::optional<std::string> deprecated() const override;

      virtual int executePermission() const override;


      // **** paramName ****
      std::string paramName() const;
      void setParamName(const std::string& paramName);


      // **** val ****
      std::vector<bool> val() const;
      void setVal(const std::vector<bool>& val);


      // **** dataSetName ****
      std::optional<std::string> dataSetName() const;
      void setDataSetName(const std::optional<std::string>& dataSetName);
    };
    
  }
}

