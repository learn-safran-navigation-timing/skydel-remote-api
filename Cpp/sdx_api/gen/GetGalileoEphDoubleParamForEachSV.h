#pragma once

#include <memory>
#include "command_base.h"
#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Get Galileo ephemeris parameter value for all satellites
    ///
    /// Name      Type   Description
    /// --------- ------ ---------------------------------------------------------
    /// ParamName string Refer to SetGalileoEphDoubleParamForSV for accepted names
    ///

    class GetGalileoEphDoubleParamForEachSV;
    typedef std::shared_ptr<GetGalileoEphDoubleParamForEachSV> GetGalileoEphDoubleParamForEachSVPtr;
    
    
    class GetGalileoEphDoubleParamForEachSV : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetGalileoEphDoubleParamForEachSV();

      GetGalileoEphDoubleParamForEachSV(const std::string& paramName);
  
      static GetGalileoEphDoubleParamForEachSVPtr create(const std::string& paramName);
      static GetGalileoEphDoubleParamForEachSVPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** paramName ****
      std::string paramName() const;
      void setParamName(const std::string& paramName);
    };
  }
}

