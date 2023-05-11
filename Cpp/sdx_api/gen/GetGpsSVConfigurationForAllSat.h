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


      GetGpsSVConfigurationForAllSat(const Sdx::optional<std::string>& dataSetName = {});

      static GetGpsSVConfigurationForAllSatPtr create(const Sdx::optional<std::string>& dataSetName = {});
      static GetGpsSVConfigurationForAllSatPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** dataSetName ****
      Sdx::optional<std::string> dataSetName() const;
      void setDataSetName(const Sdx::optional<std::string>& dataSetName);
    };
    
  }
}

