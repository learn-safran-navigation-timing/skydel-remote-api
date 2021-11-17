#pragma once

#include <memory>
#include "command_result.h"
#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of GetGalileoEphemerisDoubleParam.
    ///
    /// Name      Type   Description
    /// --------- ------ -------------------------------------------------------------------------
    /// Prn       int    Satellite PRN number 1..36, or use 0 to apply new value to all satellites
    /// ParamName string Parameter name (see table above for accepted names)
    /// Val       double Parameter value (see table above for unit)
    ///

    class GetGalileoEphemerisDoubleParamResult;
    typedef std::shared_ptr<GetGalileoEphemerisDoubleParamResult> GetGalileoEphemerisDoubleParamResultPtr;
    
    
    class GetGalileoEphemerisDoubleParamResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetGalileoEphemerisDoubleParamResult();

      GetGalileoEphemerisDoubleParamResult(CommandBasePtr relatedCommand, int prn, const std::string& paramName, double val);
  
      static GetGalileoEphemerisDoubleParamResultPtr create(CommandBasePtr relatedCommand, int prn, const std::string& paramName, double val);
      static GetGalileoEphemerisDoubleParamResultPtr dynamicCast(CommandBasePtr ptr);
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

