#pragma once

#include <memory>
#include "command_base.h"
#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Get GPS ephemeris boolean parameter value for all satellites
    ///
    /// Name      Type   Description
    /// --------- ------ ---------------------------------------------------
    /// ParamName string Refer to SetGpsEphBoolParamForSV for accepted names
    ///

    class GetGpsEphBoolParamForEachSV;
    typedef std::shared_ptr<GetGpsEphBoolParamForEachSV> GetGpsEphBoolParamForEachSVPtr;
    
    
    class GetGpsEphBoolParamForEachSV : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetGpsEphBoolParamForEachSV();

      GetGpsEphBoolParamForEachSV(const std::string& paramName);
  
      static GetGpsEphBoolParamForEachSVPtr create(const std::string& paramName);
      static GetGpsEphBoolParamForEachSVPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** paramName ****
      std::string paramName() const;
      void setParamName(const std::string& paramName);
    };
  }
}

