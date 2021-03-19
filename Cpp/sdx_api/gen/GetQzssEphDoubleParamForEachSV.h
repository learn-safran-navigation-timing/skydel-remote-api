#pragma once

#include <memory>
#include "command_base.h"
#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Get QZSS ephemeris parameter value for all satellites
    ///
    /// Name      Type   Description
    /// --------- ------ ------------------------------------------------------
    /// ParamName string Refer to SetQzssEphDoubleParamForSV for accepted names
    ///

    class GetQzssEphDoubleParamForEachSV;
    typedef std::shared_ptr<GetQzssEphDoubleParamForEachSV> GetQzssEphDoubleParamForEachSVPtr;
    
    
    class GetQzssEphDoubleParamForEachSV : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetQzssEphDoubleParamForEachSV();

      GetQzssEphDoubleParamForEachSV(const std::string& paramName);
  
      static GetQzssEphDoubleParamForEachSVPtr create(const std::string& paramName);
      static GetQzssEphDoubleParamForEachSVPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** paramName ****
      std::string paramName() const;
      void setParamName(const std::string& paramName);
    };
  }
}

