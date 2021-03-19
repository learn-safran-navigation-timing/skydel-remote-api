#pragma once

#include <memory>
#include "command_base.h"
#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Please note the command GetNavICEphemerisDoubleParams is deprecated since 21.3. You may use GetNavICEphDoubleParamForEachSV.
    /// 
    /// Get NavIC ephemeris parameter value for all satellites
    ///
    /// Name      Type   Description
    /// --------- ------ -------------------------------------------------------
    /// ParamName string Refer to SetNavICEphDoubleParamForSV for accepted names
    ///

    class GetNavICEphemerisDoubleParams;
    typedef std::shared_ptr<GetNavICEphemerisDoubleParams> GetNavICEphemerisDoubleParamsPtr;
    
    
    class GetNavICEphemerisDoubleParams : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetNavICEphemerisDoubleParams();

      GetNavICEphemerisDoubleParams(const std::string& paramName);
  
      static GetNavICEphemerisDoubleParamsPtr create(const std::string& paramName);
      static GetNavICEphemerisDoubleParamsPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** paramName ****
      std::string paramName() const;
      void setParamName(const std::string& paramName);
    };
  }
}

