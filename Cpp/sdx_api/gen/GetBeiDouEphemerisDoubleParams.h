#pragma once

#include <memory>
#include "command_base.h"
#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Please note the command GetBeiDouEphemerisDoubleParams is deprecated since 21.3. You may use GetBeiDouEphDoubleParamForEachSV.
    /// 
    /// Get BeiDou ephemeris parameter value for all satellites
    ///
    /// Name      Type   Description
    /// --------- ------ --------------------------------------------------------
    /// ParamName string Refer to SetBeiDouEphDoubleParamForSV for accepted names
    ///

    class GetBeiDouEphemerisDoubleParams;
    typedef std::shared_ptr<GetBeiDouEphemerisDoubleParams> GetBeiDouEphemerisDoubleParamsPtr;
    
    
    class GetBeiDouEphemerisDoubleParams : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetBeiDouEphemerisDoubleParams();

      GetBeiDouEphemerisDoubleParams(const std::string& paramName);
  
      static GetBeiDouEphemerisDoubleParamsPtr create(const std::string& paramName);
      static GetBeiDouEphemerisDoubleParamsPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** paramName ****
      std::string paramName() const;
      void setParamName(const std::string& paramName);
    };
  }
}

