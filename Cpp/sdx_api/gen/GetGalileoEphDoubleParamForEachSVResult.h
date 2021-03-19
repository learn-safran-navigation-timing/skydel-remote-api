#pragma once

#include <memory>
#include "command_result.h"
#include <string>
#include <vector>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of GetGalileoEphDoubleParamForEachSV
    ///
    /// Name      Type         Description
    /// --------- ------------ --------------------------------------------------------------------------------------------------
    /// ParamName string       Refer to SetGalileoEphDoubleParamForSV for accepted names
    /// Val       array double Parameter value for each satellite. Zero based index (index 0 => SV ID 1, index 1 => SV ID 2, etc)
    ///

    class GetGalileoEphDoubleParamForEachSVResult;
    typedef std::shared_ptr<GetGalileoEphDoubleParamForEachSVResult> GetGalileoEphDoubleParamForEachSVResultPtr;
    typedef GetGalileoEphDoubleParamForEachSVResult GetGalileoEphemerisDoubleParamsResult;
    typedef std::shared_ptr<GetGalileoEphemerisDoubleParamsResult> GetGalileoEphemerisDoubleParamsResultPtr;
    
    class GetGalileoEphDoubleParamForEachSVResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetGalileoEphDoubleParamForEachSVResult();

      GetGalileoEphDoubleParamForEachSVResult(CommandBasePtr relatedCommand, const std::string& paramName, const std::vector<double>& val);
  
      static GetGalileoEphDoubleParamForEachSVResultPtr create(CommandBasePtr relatedCommand, const std::string& paramName, const std::vector<double>& val);
      static GetGalileoEphDoubleParamForEachSVResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;


      // **** paramName ****
      std::string paramName() const;
      void setParamName(const std::string& paramName);


      // **** val ****
      std::vector<double> val() const;
      void setVal(const std::vector<double>& val);
    };
  }
}

