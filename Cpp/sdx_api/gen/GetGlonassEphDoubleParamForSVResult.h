#pragma once

#include <memory>
#include "command_result.h"
#include "command_result_factory.h"
#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of GetGlonassEphDoubleParamForSV.
    ///
    /// Name      Type   Description
    /// --------- ------ --------------------------------------------------------------------
    /// SvId      int    Satellite SV ID 1..24, or use 0 to apply new value to all satellites
    /// ParamName string Parameter name (see table above for accepted names)
    /// Val       double Parameter value (see table above for unit)
    ///

    class GetGlonassEphDoubleParamForSVResult;
    typedef std::shared_ptr<GetGlonassEphDoubleParamForSVResult> GetGlonassEphDoubleParamForSVResultPtr;
    
    
    class GetGlonassEphDoubleParamForSVResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetGlonassEphDoubleParamForSVResult();

      GetGlonassEphDoubleParamForSVResult(int svId, const std::string& paramName, double val);

      GetGlonassEphDoubleParamForSVResult(CommandBasePtr relatedCommand, int svId, const std::string& paramName, double val);

      static GetGlonassEphDoubleParamForSVResultPtr create(int svId, const std::string& paramName, double val);

      static GetGlonassEphDoubleParamForSVResultPtr create(CommandBasePtr relatedCommand, int svId, const std::string& paramName, double val);
      static GetGlonassEphDoubleParamForSVResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;


      // **** svId ****
      int svId() const;
      void setSvId(int svId);


      // **** paramName ****
      std::string paramName() const;
      void setParamName(const std::string& paramName);


      // **** val ****
      double val() const;
      void setVal(double val);
    };
    REGISTER_COMMAND_RESULT_TO_FACTORY_DECL(GetGlonassEphDoubleParamForSVResult);
  }
}

