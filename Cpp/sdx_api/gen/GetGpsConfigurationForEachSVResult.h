#pragma once

#include <memory>
#include "command_result.h"
#include "command_factory.h"
#include "sdx_optional.h"
#include <string>
#include <vector>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of GetGpsConfigurationForEachSV.
    ///
    /// Name        Type            Description
    /// ----------- --------------- -------------------------------------------------------------------------------------------
    /// SvConfigs   array int       SV Config of all satellite
    /// DataSetName optional string Optional name of the data set to use. If no value is provided, the active data set is used.
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
      static const char* const TargetId;


      GetGpsConfigurationForEachSVResult();

      GetGpsConfigurationForEachSVResult(const std::vector<int>& svConfigs, const Sdx::optional<std::string>& dataSetName = {});

      GetGpsConfigurationForEachSVResult(CommandBasePtr relatedCommand, const std::vector<int>& svConfigs, const Sdx::optional<std::string>& dataSetName = {});

      static GetGpsConfigurationForEachSVResultPtr create(const std::vector<int>& svConfigs, const Sdx::optional<std::string>& dataSetName = {});

      static GetGpsConfigurationForEachSVResultPtr create(CommandBasePtr relatedCommand, const std::vector<int>& svConfigs, const Sdx::optional<std::string>& dataSetName = {});
      static GetGpsConfigurationForEachSVResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;


      // **** svConfigs ****
      std::vector<int> svConfigs() const;
      void setSvConfigs(const std::vector<int>& svConfigs);


      // **** dataSetName ****
      Sdx::optional<std::string> dataSetName() const;
      void setDataSetName(const Sdx::optional<std::string>& dataSetName);
    };
    REGISTER_COMMAND_TO_FACTORY_DECL(GetGpsConfigurationForEachSVResult);
  }
}

