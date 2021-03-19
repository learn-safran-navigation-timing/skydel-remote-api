#pragma once

#include <memory>
#include "command_result.h"
#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of GetBeiDouEphemerisBoolParam
    ///
    /// Name      Type   Description
    /// --------- ------ -------------------------------------------------------------------------
    /// Prn       int    Satellite PRN number 1..30, or use 0 to apply new value to all satellites
    /// ParamName string Parameter name (see table above for accepted names)
    /// Val       bool   Parameter value (see table above for unit)
    ///

    class GetBeiDouEphemerisBoolParamResult;
    typedef std::shared_ptr<GetBeiDouEphemerisBoolParamResult> GetBeiDouEphemerisBoolParamResultPtr;
    
    
    class GetBeiDouEphemerisBoolParamResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetBeiDouEphemerisBoolParamResult();

      GetBeiDouEphemerisBoolParamResult(CommandBasePtr relatedCommand, int prn, const std::string& paramName, bool val);
  
      static GetBeiDouEphemerisBoolParamResultPtr create(CommandBasePtr relatedCommand, int prn, const std::string& paramName, bool val);
      static GetBeiDouEphemerisBoolParamResultPtr dynamicCast(CommandBasePtr ptr);
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

