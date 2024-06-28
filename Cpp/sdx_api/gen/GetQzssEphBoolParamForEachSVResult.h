#pragma once

#include <memory>
#include "command_result.h"
#include "command_factory.h"
#include <optional>
#include <string>
#include <vector>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of GetQzssEphBoolParamForEachSV.
    ///
    /// Name        Type            Description
    /// ----------- --------------- --------------------------------------------------------------------------------------------------
    /// ParamName   string          Refer to SetQzssEphemerisBoolParam for accepted names
    /// Val         array bool      Parameter value for each satellite. Zero based index (index 0 => SV ID 1, index 1 => SV ID 2, etc)
    /// DataSetName optional string Optional name of the data set to use. If no value is provided, the active data set is used.
    ///

    class GetQzssEphBoolParamForEachSVResult;
    typedef std::shared_ptr<GetQzssEphBoolParamForEachSVResult> GetQzssEphBoolParamForEachSVResultPtr;
    typedef GetQzssEphBoolParamForEachSVResult GetQzssEphemerisBoolParamsResult;
    typedef std::shared_ptr<GetQzssEphemerisBoolParamsResult> GetQzssEphemerisBoolParamsResultPtr;
    
    class GetQzssEphBoolParamForEachSVResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      GetQzssEphBoolParamForEachSVResult();

      GetQzssEphBoolParamForEachSVResult(const std::string& paramName, const std::vector<bool>& val, const std::optional<std::string>& dataSetName = {});

      GetQzssEphBoolParamForEachSVResult(CommandBasePtr relatedCommand, const std::string& paramName, const std::vector<bool>& val, const std::optional<std::string>& dataSetName = {});

      static GetQzssEphBoolParamForEachSVResultPtr create(const std::string& paramName, const std::vector<bool>& val, const std::optional<std::string>& dataSetName = {});

      static GetQzssEphBoolParamForEachSVResultPtr create(CommandBasePtr relatedCommand, const std::string& paramName, const std::vector<bool>& val, const std::optional<std::string>& dataSetName = {});
      static GetQzssEphBoolParamForEachSVResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;


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
    REGISTER_COMMAND_TO_FACTORY_DECL(GetQzssEphBoolParamForEachSVResult);
  }
}

