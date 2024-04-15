#pragma once

#include <memory>
#include "command_result.h"
#include "command_factory.h"
#include <map>
#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of GetSbasEphParamsForSV.
    ///
    /// Name           Type               Description
    /// -------------- ------------------ --------------------------------------------------------------------------
    /// SvId           int                The satellite's SV ID
    /// ParamValueDict dict string:double A dictionary of param value pairs.
    ///                                   Accepted keys are: "ClockBias", "RelativeFrequencyBias", "X", "Y", "Z",
    ///                                                      "VelocityX", "VelocityY", "VelocityZ", "AccelerationX",
    ///                                                      "AccelerationY", "AccelerationZ", "Health", "URA" and
    ///                                                      "UraIndex"
    ///

    class GetSbasEphParamsForSVResult;
    typedef std::shared_ptr<GetSbasEphParamsForSVResult> GetSbasEphParamsForSVResultPtr;
    
    
    class GetSbasEphParamsForSVResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      GetSbasEphParamsForSVResult();

      GetSbasEphParamsForSVResult(int svId, const std::map<std::string, double>& paramValueDict);

      GetSbasEphParamsForSVResult(CommandBasePtr relatedCommand, int svId, const std::map<std::string, double>& paramValueDict);

      static GetSbasEphParamsForSVResultPtr create(int svId, const std::map<std::string, double>& paramValueDict);

      static GetSbasEphParamsForSVResultPtr create(CommandBasePtr relatedCommand, int svId, const std::map<std::string, double>& paramValueDict);
      static GetSbasEphParamsForSVResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;


      // **** svId ****
      int svId() const;
      void setSvId(int svId);


      // **** paramValueDict ****
      std::map<std::string, double> paramValueDict() const;
      void setParamValueDict(const std::map<std::string, double>& paramValueDict);
    };
    REGISTER_COMMAND_TO_FACTORY_DECL(GetSbasEphParamsForSVResult);
  }
}

