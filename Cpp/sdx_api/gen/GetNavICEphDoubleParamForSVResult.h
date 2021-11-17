#pragma once

#include <memory>
#include "command_result.h"
#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of GetNavICEphDoubleParamForSV.
    ///
    /// Name      Type   Description
    /// --------- ------ --------------------------------------------------------------------
    /// SvId      int    Satellite SV ID 1..14, or use 0 to apply new value to all satellites
    /// ParamName string Parameter name (see table above for accepted names)
    /// Val       double Parameter value (see table above for unit)
    ///

    class GetNavICEphDoubleParamForSVResult;
    typedef std::shared_ptr<GetNavICEphDoubleParamForSVResult> GetNavICEphDoubleParamForSVResultPtr;
    typedef GetNavICEphDoubleParamForSVResult GetNavICEphemerisDoubleParamResult;
    typedef std::shared_ptr<GetNavICEphemerisDoubleParamResult> GetNavICEphemerisDoubleParamResultPtr;
    
    class GetNavICEphDoubleParamForSVResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetNavICEphDoubleParamForSVResult();

      GetNavICEphDoubleParamForSVResult(CommandBasePtr relatedCommand, int svId, const std::string& paramName, double val);
  
      static GetNavICEphDoubleParamForSVResultPtr create(CommandBasePtr relatedCommand, int svId, const std::string& paramName, double val);
      static GetNavICEphDoubleParamForSVResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;


      // **** svId ****
      int svId() const;
      void setSvId(int svId);


      // **** paramName ****
      std::string paramName() const;
      void setParamName(const std::string& paramName);


      // **** val ****
      double val() const;
      void setVal(double val);
    };
  }
}

