#pragma once

#include <memory>
#include "command_base.h"
#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Please note the command GetBeiDouEphemerisBoolParams is deprecated since 21.3. You may use GetBeiDouEphBoolParamForEachSV.
    /// 
    /// Get BeiDou ephemeris boolean parameter value for all satellites
    ///
    /// Name      Type   Description
    /// --------- ------ ------------------------------------------------------
    /// ParamName string Refer to SetBeiDouEphBoolParamForSV for accepted names
    ///

    class GetBeiDouEphemerisBoolParams;
    typedef std::shared_ptr<GetBeiDouEphemerisBoolParams> GetBeiDouEphemerisBoolParamsPtr;
    
    
    class GetBeiDouEphemerisBoolParams : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetBeiDouEphemerisBoolParams();

      GetBeiDouEphemerisBoolParams(const std::string& paramName);
  
      static GetBeiDouEphemerisBoolParamsPtr create(const std::string& paramName);
      static GetBeiDouEphemerisBoolParamsPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** paramName ****
      std::string paramName() const;
      void setParamName(const std::string& paramName);
    };
  }
}

