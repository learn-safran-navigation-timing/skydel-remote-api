#pragma once

#include <memory>
#include "command_base.h"

#include <string>
#include <vector>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Get parameters for a SBAS satellite ephemeris (runtime modification only available for health parameter)
    ///
    /// Name       Type         Description
    /// ---------- ------------ ----------------------------------------------------------------------------
    /// SvId       int          The satellite's SV ID
    /// ParamArray array string An array of params.
    ///                         Accepted values are: "ClockBias", "RelativeFrequencyBias", "X", "Y", "Z",
    ///                                              "VelocityX", "VelocityY", "VelocityZ", "AccelerationX",
    ///                                              "AccelerationY", "AccelerationZ", "Health", "URA" and
    ///                                              "UraIndex"
    ///

    class GetSbasEphParamsForSV;
    typedef std::shared_ptr<GetSbasEphParamsForSV> GetSbasEphParamsForSVPtr;
    
    
    class GetSbasEphParamsForSV : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetSbasEphParamsForSV();

      GetSbasEphParamsForSV(int svId, const std::vector<std::string>& paramArray);

      static GetSbasEphParamsForSVPtr create(int svId, const std::vector<std::string>& paramArray);
      static GetSbasEphParamsForSVPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** svId ****
      int svId() const;
      void setSvId(int svId);


      // **** paramArray ****
      std::vector<std::string> paramArray() const;
      void setParamArray(const std::vector<std::string>& paramArray);
    };
    
  }
}

