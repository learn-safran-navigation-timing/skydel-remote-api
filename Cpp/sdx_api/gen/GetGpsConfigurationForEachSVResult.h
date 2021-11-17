#pragma once

#include <memory>
#include "command_result.h"
#include <vector>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of GetGpsConfigurationForEachSV.
    ///
    /// Name      Type      Description
    /// --------- --------- --------------------------
    /// SvConfigs array int SV Config of all satellite
    ///

    class GetGpsConfigurationForEachSVResult;
    typedef std::shared_ptr<GetGpsConfigurationForEachSVResult> GetGpsConfigurationForEachSVResultPtr;
    typedef GetGpsConfigurationForEachSVResult GetGpsSVConfigurationForAllSatResult;
    typedef std::shared_ptr<GetGpsSVConfigurationForAllSatResult> GetGpsSVConfigurationForAllSatResultPtr;
    
    class GetGpsConfigurationForEachSVResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetGpsConfigurationForEachSVResult();

      GetGpsConfigurationForEachSVResult(CommandBasePtr relatedCommand, const std::vector<int>& svConfigs);
  
      static GetGpsConfigurationForEachSVResultPtr create(CommandBasePtr relatedCommand, const std::vector<int>& svConfigs);
      static GetGpsConfigurationForEachSVResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;


      // **** svConfigs ****
      std::vector<int> svConfigs() const;
      void setSvConfigs(const std::vector<int>& svConfigs);
    };
  }
}

