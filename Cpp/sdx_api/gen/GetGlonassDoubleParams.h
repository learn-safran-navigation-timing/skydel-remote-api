#pragma once

#include <memory>
#include "command_base.h"

#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Please note the command GetGlonassDoubleParams is deprecated since 21.3. You may use GetGlonassEphDoubleParamForEachSV.
    /// 
    /// Get GLONASS parameter value for all satellites
    ///
    /// Name      Type   Description
    /// --------- ------ ---------------------------------------------------------
    /// ParamName string Refer to SetGlonassEphDoubleParamForSV for accepted names
    ///

    class GetGlonassDoubleParams;
    typedef std::shared_ptr<GetGlonassDoubleParams> GetGlonassDoubleParamsPtr;
    
    
    class GetGlonassDoubleParams : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetGlonassDoubleParams();

      GetGlonassDoubleParams(const std::string& paramName);

      static GetGlonassDoubleParamsPtr create(const std::string& paramName);
      static GetGlonassDoubleParamsPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** paramName ****
      std::string paramName() const;
      void setParamName(const std::string& paramName);
    };
    
  }
}

