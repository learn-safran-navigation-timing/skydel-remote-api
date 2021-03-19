#pragma once

#include <memory>
#include "command_base.h"
#include <string>

namespace Sdx
{
  namespace Cmd
  {
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
    /// --------- ------ --------------------------------------------------------------------
    /// SvId      int    Satellite SV ID 1..32, or use 0 to apply new value to all satellites
    /// ParamName string Parameter name (see table above for accepted names)
    /// Val       bool   Parameter value (see table above for unit)
    ///

    class SetGpsEphBoolParamForSV;
    typedef std::shared_ptr<SetGpsEphBoolParamForSV> SetGpsEphBoolParamForSVPtr;
    
    
    class SetGpsEphBoolParamForSV : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      SetGpsEphBoolParamForSV();

      SetGpsEphBoolParamForSV(int svId, const std::string& paramName, bool val);
  
      static SetGpsEphBoolParamForSVPtr create(int svId, const std::string& paramName, bool val);
      static SetGpsEphBoolParamForSVPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** svId ****
      int svId() const;
      void setSvId(int svId);


      // **** paramName ****
      std::string paramName() const;
      void setParamName(const std::string& paramName);


      // **** val ****
      bool val() const;
      void setVal(bool val);
    };
  }
}

