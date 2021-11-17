#pragma once

#include <memory>
#include "command_result.h"
#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of GetGpsEphBoolParamForSV.
    ///
    /// Name      Type   Description
    /// --------- ------ --------------------------------------------------------------------
    /// SvId      int    Satellite SV ID 1..32, or use 0 to apply new value to all satellites
    /// ParamName string Parameter name (see table above for accepted names)
    /// Val       bool   Parameter value (see table above for unit)
    ///

    class GetGpsEphBoolParamForSVResult;
    typedef std::shared_ptr<GetGpsEphBoolParamForSVResult> GetGpsEphBoolParamForSVResultPtr;
    
    
    class GetGpsEphBoolParamForSVResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetGpsEphBoolParamForSVResult();

      GetGpsEphBoolParamForSVResult(CommandBasePtr relatedCommand, int svId, const std::string& paramName, bool val);
  
      static GetGpsEphBoolParamForSVResultPtr create(CommandBasePtr relatedCommand, int svId, const std::string& paramName, bool val);
      static GetGpsEphBoolParamForSVResultPtr dynamicCast(CommandBasePtr ptr);
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

