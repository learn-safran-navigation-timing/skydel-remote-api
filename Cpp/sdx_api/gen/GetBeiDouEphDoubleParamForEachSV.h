#pragma once

#include <memory>
#include "command_base.h"
#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Get BeiDou ephemeris parameter value for all satellites
    ///
    /// Name      Type   Description
    /// --------- ------ --------------------------------------------------------
    /// ParamName string Refer to SetBeiDouEphDoubleParamForSV for accepted names
    ///

    class GetBeiDouEphDoubleParamForEachSV;
    typedef std::shared_ptr<GetBeiDouEphDoubleParamForEachSV> GetBeiDouEphDoubleParamForEachSVPtr;
    
    
    class GetBeiDouEphDoubleParamForEachSV : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetBeiDouEphDoubleParamForEachSV();

      GetBeiDouEphDoubleParamForEachSV(const std::string& paramName);
  
      static GetBeiDouEphDoubleParamForEachSVPtr create(const std::string& paramName);
      static GetBeiDouEphDoubleParamForEachSVPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** paramName ****
      std::string paramName() const;
      void setParamName(const std::string& paramName);
    };
  }
}

