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
    /// Get QZSS ephemeris parameter value for all satellites
    ///
    /// Name        Type            Description
    /// ----------- --------------- -------------------------------------------------------------------------------------------
    /// ParamName   string          Refer to SetQzssEphDoubleParamForSV for accepted names
    /// DataSetName optional string Optional name of the data set to use. If no value is provided, the active data set is used.
    ///

    class GetQzssEphDoubleParamForEachSV;
    typedef std::shared_ptr<GetQzssEphDoubleParamForEachSV> GetQzssEphDoubleParamForEachSVPtr;
    
    
    class GetQzssEphDoubleParamForEachSV : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetQzssEphDoubleParamForEachSV();

      GetQzssEphDoubleParamForEachSV(const std::string& paramName, const Sdx::optional<std::string>& dataSetName = {});

      static GetQzssEphDoubleParamForEachSVPtr create(const std::string& paramName, const Sdx::optional<std::string>& dataSetName = {});
      static GetQzssEphDoubleParamForEachSVPtr dynamicCast(CommandBasePtr ptr);
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

