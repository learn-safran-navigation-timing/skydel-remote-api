#pragma once

#include <memory>
#include "command_base.h"
#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Get QZSS ephemeris boolean parameter value for all satellites
    ///
    /// Name      Type   Description
    /// --------- ------ -----------------------------------------------------
    /// ParamName string Refer to SetQzssEphemerisBoolParam for accepted names
    ///

    class GetQzssEphBoolParamForEachSV;
    typedef std::shared_ptr<GetQzssEphBoolParamForEachSV> GetQzssEphBoolParamForEachSVPtr;
    
    
    class GetQzssEphBoolParamForEachSV : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetQzssEphBoolParamForEachSV();

      GetQzssEphBoolParamForEachSV(const std::string& paramName);
  
      static GetQzssEphBoolParamForEachSVPtr create(const std::string& paramName);
      static GetQzssEphBoolParamForEachSVPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** paramName ****
      std::string paramName() const;
      void setParamName(const std::string& paramName);
    };
  }
}

