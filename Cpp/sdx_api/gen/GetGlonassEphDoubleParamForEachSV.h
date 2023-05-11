#pragma once

#include <memory>
#include "command_base.h"

#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Get GLONASS parameter value for all satellites
    ///
    /// Name      Type   Description
    /// --------- ------ ---------------------------------------------------------
    /// ParamName string Refer to SetGlonassEphDoubleParamForSV for accepted names
    ///

    class GetGlonassEphDoubleParamForEachSV;
    typedef std::shared_ptr<GetGlonassEphDoubleParamForEachSV> GetGlonassEphDoubleParamForEachSVPtr;
    
    
    class GetGlonassEphDoubleParamForEachSV : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetGlonassEphDoubleParamForEachSV();

      GetGlonassEphDoubleParamForEachSV(const std::string& paramName);

      static GetGlonassEphDoubleParamForEachSVPtr create(const std::string& paramName);
      static GetGlonassEphDoubleParamForEachSVPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** paramName ****
      std::string paramName() const;
      void setParamName(const std::string& paramName);
    };
    
  }
}

