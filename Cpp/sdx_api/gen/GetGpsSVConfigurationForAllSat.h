#pragma once

#include <memory>
#include "command_base.h"

#include <optional>
#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Please note the command GetGpsSVConfigurationForAllSat is deprecated since 21.3. You may use GetGpsConfigurationForEachSV.
    /// 
    /// Get GPS SV configuration flag for each SVs
    ///
    /// Name        Type            Description
    /// ----------- --------------- -------------------------------------------------------------------------------------------
    /// DataSetName optional string Optional name of the data set to use. If no value is provided, the active data set is used.
    ///

    class GetGpsSVConfigurationForAllSat;
    typedef std::shared_ptr<GetGpsSVConfigurationForAllSat> GetGpsSVConfigurationForAllSatPtr;
    
    
    class GetGpsSVConfigurationForAllSat : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      GetGpsSVConfigurationForAllSat(const std::optional<std::string>& dataSetName = {});

      static GetGpsSVConfigurationForAllSatPtr create(const std::optional<std::string>& dataSetName = {});
      static GetGpsSVConfigurationForAllSatPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;

      virtual int executePermission() const override;


      // **** dataSetName ****
      std::optional<std::string> dataSetName() const;
      void setDataSetName(const std::optional<std::string>& dataSetName);
    };
    
  }
}

