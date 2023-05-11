#pragma once

#include <memory>
#include "command_result.h"
#include "command_result_factory.h"
#include <string>
#include <vector>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of GetGlonassEphDoubleParamForEachSV.
    ///
    /// Name      Type         Description
    /// --------- ------------ --------------------------------------------------------------------------------------------------
    /// ParamName string       Refer to SetGlonassEphDoubleParamForSV for accepted names
    /// Val       array double Parameter value for each satellite. Zero based index (index 0 => SV ID 1, index 1 => SV ID 2, etc)
    ///

    class GetGlonassEphDoubleParamForEachSVResult;
    typedef std::shared_ptr<GetGlonassEphDoubleParamForEachSVResult> GetGlonassEphDoubleParamForEachSVResultPtr;
    typedef GetGlonassEphDoubleParamForEachSVResult GetGlonassDoubleParamsResult;
    typedef std::shared_ptr<GetGlonassDoubleParamsResult> GetGlonassDoubleParamsResultPtr;
    
    class GetGlonassEphDoubleParamForEachSVResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetGlonassEphDoubleParamForEachSVResult();

      GetGlonassEphDoubleParamForEachSVResult(const std::string& paramName, const std::vector<double>& val);

      GetGlonassEphDoubleParamForEachSVResult(CommandBasePtr relatedCommand, const std::string& paramName, const std::vector<double>& val);

      static GetGlonassEphDoubleParamForEachSVResultPtr create(const std::string& paramName, const std::vector<double>& val);

      static GetGlonassEphDoubleParamForEachSVResultPtr create(CommandBasePtr relatedCommand, const std::string& paramName, const std::vector<double>& val);
      static GetGlonassEphDoubleParamForEachSVResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;


      // **** paramName ****
      std::string paramName() const;
      void setParamName(const std::string& paramName);


      // **** val ****
      std::vector<double> val() const;
      void setVal(const std::vector<double>& val);
    };
    REGISTER_COMMAND_RESULT_TO_FACTORY_DECL(GetGlonassEphDoubleParamForEachSVResult);
  }
}

