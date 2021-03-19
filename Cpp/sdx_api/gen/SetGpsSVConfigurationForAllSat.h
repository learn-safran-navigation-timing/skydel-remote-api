#pragma once

#include <memory>
#include "command_base.h"
#include <vector>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Please note the command SetGpsSVConfigurationForAllSat is deprecated since 21.3. You may use SetGpsConfigurationForEachSV.
    /// 
    /// Set GPS SV configuration flag for each SVs
    ///
    /// Name      Type      Description
    /// --------- --------- --------------------------
    /// SvConfigs array int SV Config of all satellite
    ///

    class SetGpsSVConfigurationForAllSat;
    typedef std::shared_ptr<SetGpsSVConfigurationForAllSat> SetGpsSVConfigurationForAllSatPtr;
    
    
    class SetGpsSVConfigurationForAllSat : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      SetGpsSVConfigurationForAllSat();

      SetGpsSVConfigurationForAllSat(const std::vector<int>& svConfigs);
  
      static SetGpsSVConfigurationForAllSatPtr create(const std::vector<int>& svConfigs);
      static SetGpsSVConfigurationForAllSatPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** svConfigs ****
      std::vector<int> svConfigs() const;
      void setSvConfigs(const std::vector<int>& svConfigs);
    };
  }
}

