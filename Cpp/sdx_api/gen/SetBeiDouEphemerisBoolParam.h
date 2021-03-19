#pragma once

#include <memory>
#include "command_base.h"
#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Please note the command BeiDouEphemerisBoolParam is deprecated since 21.3. You may use BeiDouEphBoolParamForSV.
    /// 
    /// Set various boolean parameters in the BeiDou ephemeris
    /// 
    ///   ParamName
    /// "IscB1CdAvailable"
    /// "IscB2adAvailable"
    ///
    /// Name      Type   Description
    /// --------- ------ -------------------------------------------------------------------------
    /// Prn       int    Satellite PRN number 1..30, or use 0 to apply new value to all satellites
    /// ParamName string Parameter name (see table above for accepted names)
    /// Val       bool   Parameter value (see table above for unit)
    ///

    class SetBeiDouEphemerisBoolParam;
    typedef std::shared_ptr<SetBeiDouEphemerisBoolParam> SetBeiDouEphemerisBoolParamPtr;
    
    
    class SetBeiDouEphemerisBoolParam : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      SetBeiDouEphemerisBoolParam();

      SetBeiDouEphemerisBoolParam(int prn, const std::string& paramName, bool val);
  
      static SetBeiDouEphemerisBoolParamPtr create(int prn, const std::string& paramName, bool val);
      static SetBeiDouEphemerisBoolParamPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** prn ****
      int prn() const;
      void setPrn(int prn);


      // **** paramName ****
      std::string paramName() const;
      void setParamName(const std::string& paramName);


      // **** val ****
      bool val() const;
      void setVal(bool val);
    };
  }
}

