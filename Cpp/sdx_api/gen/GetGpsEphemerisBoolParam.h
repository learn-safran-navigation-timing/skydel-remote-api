#pragma once

#include <memory>
#include "command_base.h"
#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Please note the command GetGpsEphemerisBoolParam is deprecated since 21.3. You may use GetGpsEphBoolParamForSV.
    /// 
    /// Get various boolean parameters in the GPS ephemeris
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
    /// --------- ------ -------------------------------------------------------------------------
    /// Prn       int    Satellite PRN number 1..32, or use 0 to apply new value to all satellites
    /// ParamName string Parameter name (see table above for accepted names)
    ///

    class GetGpsEphemerisBoolParam;
    typedef std::shared_ptr<GetGpsEphemerisBoolParam> GetGpsEphemerisBoolParamPtr;
    
    
    class GetGpsEphemerisBoolParam : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetGpsEphemerisBoolParam();

      GetGpsEphemerisBoolParam(int prn, const std::string& paramName);
  
      static GetGpsEphemerisBoolParamPtr create(int prn, const std::string& paramName);
      static GetGpsEphemerisBoolParamPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** prn ****
      int prn() const;
      void setPrn(int prn);


      // **** paramName ****
      std::string paramName() const;
      void setParamName(const std::string& paramName);
    };
  }
}

