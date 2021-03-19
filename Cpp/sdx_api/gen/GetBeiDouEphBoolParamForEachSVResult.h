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
    /// Result of GetBeiDouEphBoolParamForEachSV
    ///
    /// Name      Type       Description
    /// --------- ---------- --------------------------------------------------------------------------------------------------
    /// ParamName string     Refer to SetBeiDouEphBoolParamForSV for accepted names
    /// Val       array bool Parameter value for each satellite. Zero based index (index 0 => SV ID 1, index 1 => SV ID 2, etc)
    ///

    class GetBeiDouEphBoolParamForEachSVResult;
    typedef std::shared_ptr<GetBeiDouEphBoolParamForEachSVResult> GetBeiDouEphBoolParamForEachSVResultPtr;
    typedef GetBeiDouEphBoolParamForEachSVResult GetBeiDouEphemerisBoolParamsResult;
    typedef std::shared_ptr<GetBeiDouEphemerisBoolParamsResult> GetBeiDouEphemerisBoolParamsResultPtr;
    
    class GetBeiDouEphBoolParamForEachSVResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetBeiDouEphBoolParamForEachSVResult();

      GetBeiDouEphBoolParamForEachSVResult(CommandBasePtr relatedCommand, const std::string& paramName, const std::vector<bool>& val);
  
      static GetBeiDouEphBoolParamForEachSVResultPtr create(CommandBasePtr relatedCommand, const std::string& paramName, const std::vector<bool>& val);
      static GetBeiDouEphBoolParamForEachSVResultPtr dynamicCast(CommandBasePtr ptr);
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

