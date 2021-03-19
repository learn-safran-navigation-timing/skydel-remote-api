#pragma once

#include <memory>
#include "command_base.h"
#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Please note the command GetQzssEphemerisDoubleParams is deprecated since 21.3. You may use GetQzssEphDoubleParamForEachSV.
    /// 
    /// Get QZSS ephemeris parameter value for all satellites
    ///
    /// Name      Type   Description
    /// --------- ------ ------------------------------------------------------
    /// ParamName string Refer to SetQzssEphDoubleParamForSV for accepted names
    ///

    class GetQzssEphemerisDoubleParams;
    typedef std::shared_ptr<GetQzssEphemerisDoubleParams> GetQzssEphemerisDoubleParamsPtr;
    
    
    class GetQzssEphemerisDoubleParams : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetQzssEphemerisDoubleParams();

      GetQzssEphemerisDoubleParams(const std::string& paramName);
  
      static GetQzssEphemerisDoubleParamsPtr create(const std::string& paramName);
      static GetQzssEphemerisDoubleParamsPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** paramName ****
      std::string paramName() const;
      void setParamName(const std::string& paramName);
    };
  }
}

