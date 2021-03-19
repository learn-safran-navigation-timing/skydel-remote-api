#pragma once

#include <memory>
#include "command_base.h"
#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Get BeiDou ephemeris boolean parameter value for all satellites
    ///
    /// Name      Type   Description
    /// --------- ------ ------------------------------------------------------
    /// ParamName string Refer to SetBeiDouEphBoolParamForSV for accepted names
    ///

    class GetBeiDouEphBoolParamForEachSV;
    typedef std::shared_ptr<GetBeiDouEphBoolParamForEachSV> GetBeiDouEphBoolParamForEachSVPtr;
    
    
    class GetBeiDouEphBoolParamForEachSV : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetBeiDouEphBoolParamForEachSV();

      GetBeiDouEphBoolParamForEachSV(const std::string& paramName);
  
      static GetBeiDouEphBoolParamForEachSVPtr create(const std::string& paramName);
      static GetBeiDouEphBoolParamForEachSVPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** paramName ****
      std::string paramName() const;
      void setParamName(const std::string& paramName);
    };
  }
}

