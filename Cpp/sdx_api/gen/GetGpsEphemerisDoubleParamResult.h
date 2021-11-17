#pragma once

#include <memory>
#include "command_result.h"
#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of GetGpsEphemerisDoubleParam.
    ///
    /// Name      Type   Description
    /// --------- ------ -------------------------------------------------------------------------
    /// Prn       int    Satellite PRN number 1..32, or use 0 to apply new value to all satellites
    /// ParamName string Parameter name (see table above for accepted names)
    /// Val       double Parameter value (see table above for unit)
    ///

    class GetGpsEphemerisDoubleParamResult;
    typedef std::shared_ptr<GetGpsEphemerisDoubleParamResult> GetGpsEphemerisDoubleParamResultPtr;
    
    
    class GetGpsEphemerisDoubleParamResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetGpsEphemerisDoubleParamResult();

      GetGpsEphemerisDoubleParamResult(CommandBasePtr relatedCommand, int prn, const std::string& paramName, double val);
  
      static GetGpsEphemerisDoubleParamResultPtr create(CommandBasePtr relatedCommand, int prn, const std::string& paramName, double val);
      static GetGpsEphemerisDoubleParamResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;


      // **** prn ****
      int prn() const;
      void setPrn(int prn);


      // **** paramName ****
      std::string paramName() const;
      void setParamName(const std::string& paramName);


      // **** val ****
      double val() const;
      void setVal(double val);
    };
  }
}

