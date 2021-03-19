#pragma once

#include <memory>
#include "command_base.h"
#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Please note the command GetGalileoEphemerisDoubleParams is deprecated since 21.3. You may use GetGalileoEphDoubleParamForEachSV.
    /// 
    /// Get Galileo ephemeris parameter value for all satellites
    ///
    /// Name      Type   Description
    /// --------- ------ ---------------------------------------------------------
    /// ParamName string Refer to SetGalileoEphDoubleParamForSV for accepted names
    ///

    class GetGalileoEphemerisDoubleParams;
    typedef std::shared_ptr<GetGalileoEphemerisDoubleParams> GetGalileoEphemerisDoubleParamsPtr;
    
    
    class GetGalileoEphemerisDoubleParams : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetGalileoEphemerisDoubleParams();

      GetGalileoEphemerisDoubleParams(const std::string& paramName);
  
      static GetGalileoEphemerisDoubleParamsPtr create(const std::string& paramName);
      static GetGalileoEphemerisDoubleParamsPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** paramName ****
      std::string paramName() const;
      void setParamName(const std::string& paramName);
    };
  }
}

