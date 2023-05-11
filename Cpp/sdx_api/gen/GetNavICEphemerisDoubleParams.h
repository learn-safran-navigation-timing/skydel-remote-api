#pragma once

#include <memory>
#include "command_base.h"

#include "sdx_optional.h"
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
    /// Name        Type            Description
    /// ----------- --------------- -------------------------------------------------------------------------------------------
    /// ParamName   string          Refer to SetNavICEphDoubleParamForSV for accepted names
    /// DataSetName optional string Optional name of the data set to use. If no value is provided, the active data set is used.
    ///

    class GetNavICEphemerisDoubleParams;
    typedef std::shared_ptr<GetNavICEphemerisDoubleParams> GetNavICEphemerisDoubleParamsPtr;
    
    
    class GetNavICEphemerisDoubleParams : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetNavICEphemerisDoubleParams();

      GetNavICEphemerisDoubleParams(const std::string& paramName, const Sdx::optional<std::string>& dataSetName = {});

      static GetNavICEphemerisDoubleParamsPtr create(const std::string& paramName, const Sdx::optional<std::string>& dataSetName = {});
      static GetNavICEphemerisDoubleParamsPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** paramName ****
      std::string paramName() const;
      void setParamName(const std::string& paramName);


      // **** dataSetName ****
      Sdx::optional<std::string> dataSetName() const;
      void setDataSetName(const Sdx::optional<std::string>& dataSetName);
    };
    
  }
}

