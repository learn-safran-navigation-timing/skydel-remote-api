#pragma once

#include <memory>
#include "command_base.h"
#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Get NavIC ephemeris parameter value for all satellites
    ///
    /// Name      Type   Description
    /// --------- ------ -------------------------------------------------------
    /// ParamName string Refer to SetNavICEphDoubleParamForSV for accepted names
    ///

    class GetNavICEphDoubleParamForEachSV;
    typedef std::shared_ptr<GetNavICEphDoubleParamForEachSV> GetNavICEphDoubleParamForEachSVPtr;
    
    
    class GetNavICEphDoubleParamForEachSV : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetNavICEphDoubleParamForEachSV();

      GetNavICEphDoubleParamForEachSV(const std::string& paramName);
  
      static GetNavICEphDoubleParamForEachSVPtr create(const std::string& paramName);
      static GetNavICEphDoubleParamForEachSVPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** paramName ****
      std::string paramName() const;
      void setParamName(const std::string& paramName);
    };
  }
}

