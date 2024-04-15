#pragma once

#include <memory>
#include "command_result.h"
#include "command_factory.h"
#include "sdx_optional.h"
#include <string>
#include <vector>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of GetGpsEphBoolParamForEachSV.
    ///
    /// Name        Type            Description
    /// ----------- --------------- --------------------------------------------------------------------------------------------------
    /// ParamName   string          Refer to SetGpsEphBoolParamForSV for accepted names
    /// Val         array bool      Parameter value for each satellite. Zero based index (index 0 => SV ID 1, index 1 => SV ID 2, etc)
    /// DataSetName optional string Optional name of the data set to use. If no value is provided, the active data set is used.
    ///

    class GetGpsEphBoolParamForEachSVResult;
    typedef std::shared_ptr<GetGpsEphBoolParamForEachSVResult> GetGpsEphBoolParamForEachSVResultPtr;
    typedef GetGpsEphBoolParamForEachSVResult GetGpsEphemerisBoolParamsResult;
    typedef std::shared_ptr<GetGpsEphemerisBoolParamsResult> GetGpsEphemerisBoolParamsResultPtr;
    
    class GetGpsEphBoolParamForEachSVResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      GetGpsEphBoolParamForEachSVResult();

      GetGpsEphBoolParamForEachSVResult(const std::string& paramName, const std::vector<bool>& val, const Sdx::optional<std::string>& dataSetName = {});

      GetGpsEphBoolParamForEachSVResult(CommandBasePtr relatedCommand, const std::string& paramName, const std::vector<bool>& val, const Sdx::optional<std::string>& dataSetName = {});

      static GetGpsEphBoolParamForEachSVResultPtr create(const std::string& paramName, const std::vector<bool>& val, const Sdx::optional<std::string>& dataSetName = {});

      static GetGpsEphBoolParamForEachSVResultPtr create(CommandBasePtr relatedCommand, const std::string& paramName, const std::vector<bool>& val, const Sdx::optional<std::string>& dataSetName = {});
      static GetGpsEphBoolParamForEachSVResultPtr dynamicCast(CommandBasePtr ptr);
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
      Sdx::optional<std::string> dataSetName() const;
      void setDataSetName(const Sdx::optional<std::string>& dataSetName);
    };
    REGISTER_COMMAND_TO_FACTORY_DECL(GetGpsEphBoolParamForEachSVResult);
  }
}

