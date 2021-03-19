#pragma once

#include <memory>
#include "command_base.h"
#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Please note the command GetQzssEphemerisBoolParam is deprecated since 21.3. You may use GetQzssEphBoolParamForSV.
    /// 
    /// Get various boolean parameters in the QZSS ephemeris
    /// 
    ///   ParamName
    /// "IscL1CaAvailable"
    /// "IscL2CAvailable"
    /// "IscL5I5Available"
    /// "IscL5Q5Available"
    /// "IscL1CPAvailable"
    /// "IscL1CDAvailable"
    ///
    /// Name      Type   Description
    /// --------- ------ --------------------------------------------------------------------
    /// SvId      int    Satellite SV ID 1..10, or use 0 to apply new value to all satellites
    /// ParamName string Parameter name (see table above for accepted names)
    ///

    class GetQzssEphemerisBoolParam;
    typedef std::shared_ptr<GetQzssEphemerisBoolParam> GetQzssEphemerisBoolParamPtr;
    
    
    class GetQzssEphemerisBoolParam : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetQzssEphemerisBoolParam();

      GetQzssEphemerisBoolParam(int svId, const std::string& paramName);
  
      static GetQzssEphemerisBoolParamPtr create(int svId, const std::string& paramName);
      static GetQzssEphemerisBoolParamPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** svId ****
      int svId() const;
      void setSvId(int svId);


      // **** paramName ****
      std::string paramName() const;
      void setParamName(const std::string& paramName);
    };
  }
}

