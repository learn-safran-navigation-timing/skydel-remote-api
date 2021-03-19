#pragma once

#include <memory>
#include "command_result.h"
#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of GetGpsEphemerisBoolParam
    ///
    /// Name      Type   Description
    /// --------- ------ -------------------------------------------------------------------------
    /// Prn       int    Satellite PRN number 1..32, or use 0 to apply new value to all satellites
    /// ParamName string Parameter name (see table above for accepted names)
    /// Val       bool   Parameter value (see table above for unit)
    ///

    class GetGpsEphemerisBoolParamResult;
    typedef std::shared_ptr<GetGpsEphemerisBoolParamResult> GetGpsEphemerisBoolParamResultPtr;
    
    
    class GetGpsEphemerisBoolParamResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetGpsEphemerisBoolParamResult();

      GetGpsEphemerisBoolParamResult(CommandBasePtr relatedCommand, int prn, const std::string& paramName, bool val);
  
      static GetGpsEphemerisBoolParamResultPtr create(CommandBasePtr relatedCommand, int prn, const std::string& paramName, bool val);
      static GetGpsEphemerisBoolParamResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;


      // **** prn ****
      int prn() const;
      void setPrn(int prn);


      // **** paramName ****
      std::string paramName() const;
      void setParamName(const std::string& paramName);


      // **** val ****
      bool val() const;
      void setVal(bool val);
    };
  }
}

