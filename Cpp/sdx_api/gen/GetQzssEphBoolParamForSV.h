#pragma once

#include <memory>
#include "command_base.h"
#include <string>

namespace Sdx
{
  namespace Cmd
  {
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

    class GetQzssEphBoolParamForSV;
    typedef std::shared_ptr<GetQzssEphBoolParamForSV> GetQzssEphBoolParamForSVPtr;
    
    
    class GetQzssEphBoolParamForSV : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetQzssEphBoolParamForSV();

      GetQzssEphBoolParamForSV(int svId, const std::string& paramName);
  
      static GetQzssEphBoolParamForSVPtr create(int svId, const std::string& paramName);
      static GetQzssEphBoolParamForSVPtr dynamicCast(CommandBasePtr ptr);
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

