#pragma once

#include <memory>
#include "command_base.h"
#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Please note the command GetBeiDouEphemerisBoolParam is deprecated since 21.3. You may use GetBeiDouEphBoolParamForSV.
    /// 
    /// Get various boolean parameters in the BeiDou ephemeris
    /// 
    ///   ParamName
    /// "IscB1CdAvailable"
    /// "IscB2adAvailable"
    ///
    /// Name      Type   Description
    /// --------- ------ -------------------------------------------------------------------------
    /// Prn       int    Satellite PRN number 1..30, or use 0 to apply new value to all satellites
    /// ParamName string Parameter name (see table above for accepted names)
    ///

    class GetBeiDouEphemerisBoolParam;
    typedef std::shared_ptr<GetBeiDouEphemerisBoolParam> GetBeiDouEphemerisBoolParamPtr;
    
    
    class GetBeiDouEphemerisBoolParam : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetBeiDouEphemerisBoolParam();

      GetBeiDouEphemerisBoolParam(int prn, const std::string& paramName);
  
      static GetBeiDouEphemerisBoolParamPtr create(int prn, const std::string& paramName);
      static GetBeiDouEphemerisBoolParamPtr dynamicCast(CommandBasePtr ptr);
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

