#pragma once

#include <memory>
#include "command_base.h"
#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Please note the command GetQzssEphemerisBoolParams is deprecated since 21.3. You may use GetQzssEphBoolParamForEachSV.
    /// 
    /// Get QZSS ephemeris boolean parameter value for all satellites
    ///
    /// Name      Type   Description
    /// --------- ------ -----------------------------------------------------
    /// ParamName string Refer to SetQzssEphemerisBoolParam for accepted names
    ///

    class GetQzssEphemerisBoolParams;
    typedef std::shared_ptr<GetQzssEphemerisBoolParams> GetQzssEphemerisBoolParamsPtr;
    
    
    class GetQzssEphemerisBoolParams : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetQzssEphemerisBoolParams();

      GetQzssEphemerisBoolParams(const std::string& paramName);
  
      static GetQzssEphemerisBoolParamsPtr create(const std::string& paramName);
      static GetQzssEphemerisBoolParamsPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** paramName ****
      std::string paramName() const;
      void setParamName(const std::string& paramName);
    };
  }
}

