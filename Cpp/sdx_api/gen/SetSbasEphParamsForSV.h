#pragma once

#include <memory>
#include "command_base.h"

#include <map>
#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Set parameters for a SBAS satellite ephemeris (runtime modification only available for health parameter)
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

    class SetSbasEphParamsForSV;
    typedef std::shared_ptr<SetSbasEphParamsForSV> SetSbasEphParamsForSVPtr;
    
    
    class SetSbasEphParamsForSV : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      SetSbasEphParamsForSV();

      SetSbasEphParamsForSV(int svId, const std::map<std::string, double>& paramValueDict);

      static SetSbasEphParamsForSVPtr create(int svId, const std::map<std::string, double>& paramValueDict);
      static SetSbasEphParamsForSVPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** svId ****
      int svId() const;
      void setSvId(int svId);


      // **** paramValueDict ****
      std::map<std::string, double> paramValueDict() const;
      void setParamValueDict(const std::map<std::string, double>& paramValueDict);
    };
    
  }
}

