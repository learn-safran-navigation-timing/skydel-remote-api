#pragma once

#include <memory>
#include "command_result.h"
#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of GetQzssEphBoolParamForSV
    ///
    /// Name      Type   Description
    /// --------- ------ --------------------------------------------------------------------
    /// SvId      int    Satellite SV ID 1..10, or use 0 to apply new value to all satellites
    /// ParamName string Parameter name (see table above for accepted names)
    /// Val       bool   Parameter value (see table above for unit)
    ///

    class GetQzssEphBoolParamForSVResult;
    typedef std::shared_ptr<GetQzssEphBoolParamForSVResult> GetQzssEphBoolParamForSVResultPtr;
    typedef GetQzssEphBoolParamForSVResult GetQzssEphemerisBoolParamResult;
    typedef std::shared_ptr<GetQzssEphemerisBoolParamResult> GetQzssEphemerisBoolParamResultPtr;
    
    class GetQzssEphBoolParamForSVResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetQzssEphBoolParamForSVResult();

      GetQzssEphBoolParamForSVResult(CommandBasePtr relatedCommand, int svId, const std::string& paramName, bool val);
  
      static GetQzssEphBoolParamForSVResultPtr create(CommandBasePtr relatedCommand, int svId, const std::string& paramName, bool val);
      static GetQzssEphBoolParamForSVResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;


      // **** svId ****
      int svId() const;
      void setSvId(int svId);


      // **** paramName ****
      std::string paramName() const;
      void setParamName(const std::string& paramName);


      // **** val ****
      bool val() const;
      void setVal(bool val);
    };
  }
}

