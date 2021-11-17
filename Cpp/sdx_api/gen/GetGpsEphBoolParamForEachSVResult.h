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
    /// Result of GetGpsEphBoolParamForEachSV.
    ///
    /// Name      Type       Description
    /// --------- ---------- --------------------------------------------------------------------------------------------------
    /// ParamName string     Refer to SetGpsEphBoolParamForSV for accepted names
    /// Val       array bool Parameter value for each satellite. Zero based index (index 0 => SV ID 1, index 1 => SV ID 2, etc)
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


      GetGpsEphBoolParamForEachSVResult();

      GetGpsEphBoolParamForEachSVResult(CommandBasePtr relatedCommand, const std::string& paramName, const std::vector<bool>& val);
  
      static GetGpsEphBoolParamForEachSVResultPtr create(CommandBasePtr relatedCommand, const std::string& paramName, const std::vector<bool>& val);
      static GetGpsEphBoolParamForEachSVResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;


      // **** paramName ****
      std::string paramName() const;
      void setParamName(const std::string& paramName);


      // **** val ****
      std::vector<bool> val() const;
      void setVal(const std::vector<bool>& val);
    };
  }
}

