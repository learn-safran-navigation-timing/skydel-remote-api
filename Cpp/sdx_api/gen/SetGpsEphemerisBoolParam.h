#pragma once

#include <memory>
#include "command_base.h"
#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Please note the command GpsEphemerisBoolParam is deprecated since 21.3. You may use GpsEphBoolParamForSV.
    /// 
    /// Set various boolean parameters in the GPS ephemeris
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
    /// Val       bool   Parameter value (see table above for unit)
    ///

    class SetGpsEphemerisBoolParam;
    typedef std::shared_ptr<SetGpsEphemerisBoolParam> SetGpsEphemerisBoolParamPtr;
    
    
    class SetGpsEphemerisBoolParam : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      SetGpsEphemerisBoolParam();

      SetGpsEphemerisBoolParam(int prn, const std::string& paramName, bool val);
  
      static SetGpsEphemerisBoolParamPtr create(int prn, const std::string& paramName, bool val);
      static SetGpsEphemerisBoolParamPtr dynamicCast(CommandBasePtr ptr);
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

