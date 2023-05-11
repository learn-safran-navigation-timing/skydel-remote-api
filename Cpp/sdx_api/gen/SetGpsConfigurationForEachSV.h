#pragma once

#include <memory>
#include "command_base.h"

#include "sdx_optional.h"
#include <string>
#include <vector>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Set GPS SV configuration flag for each SVs
    ///
    /// Name        Type            Description
    /// ----------- --------------- -------------------------------------------------------------------------------------------
    /// SvConfigs   array int       SV Config of all satellite
    /// DataSetName optional string Optional name of the data set to use. If no value is provided, the active data set is used.
    ///

    class SetGpsConfigurationForEachSV;
    typedef std::shared_ptr<SetGpsConfigurationForEachSV> SetGpsConfigurationForEachSVPtr;
    
    
    class SetGpsConfigurationForEachSV : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      SetGpsConfigurationForEachSV();

      SetGpsConfigurationForEachSV(const std::vector<int>& svConfigs, const Sdx::optional<std::string>& dataSetName = {});

      static SetGpsConfigurationForEachSVPtr create(const std::vector<int>& svConfigs, const Sdx::optional<std::string>& dataSetName = {});
      static SetGpsConfigurationForEachSVPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** svConfigs ****
      std::vector<int> svConfigs() const;
      void setSvConfigs(const std::vector<int>& svConfigs);


      // **** dataSetName ****
      Sdx::optional<std::string> dataSetName() const;
      void setDataSetName(const Sdx::optional<std::string>& dataSetName);
    };
    
  }
}

