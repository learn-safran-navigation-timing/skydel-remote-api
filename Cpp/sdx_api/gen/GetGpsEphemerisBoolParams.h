#pragma once

#include <memory>
#include "command_base.h"
#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Please note the command GetGpsEphemerisBoolParams is deprecated since 21.3. You may use GetGpsEphBoolParamForEachSV.
    /// 
    /// Get GPS ephemeris boolean parameter value for all satellites
    ///
    /// Name      Type   Description
    /// --------- ------ ---------------------------------------------------
    /// ParamName string Refer to SetGpsEphBoolParamForSV for accepted names
    ///

    class GetGpsEphemerisBoolParams;
    typedef std::shared_ptr<GetGpsEphemerisBoolParams> GetGpsEphemerisBoolParamsPtr;
    
    
    class GetGpsEphemerisBoolParams : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetGpsEphemerisBoolParams();

      GetGpsEphemerisBoolParams(const std::string& paramName);
  
      static GetGpsEphemerisBoolParamsPtr create(const std::string& paramName);
      static GetGpsEphemerisBoolParamsPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** paramName ****
      std::string paramName() const;
      void setParamName(const std::string& paramName);
    };
  }
}

