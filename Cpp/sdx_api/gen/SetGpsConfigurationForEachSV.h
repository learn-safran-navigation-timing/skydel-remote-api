#pragma once

#include <memory>
#include "command_base.h"
#include <vector>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Set GPS SV configuration flag for each SVs
    ///
    /// Name      Type      Description
    /// --------- --------- --------------------------
    /// SvConfigs array int SV Config of all satellite
    ///

    class SetGpsConfigurationForEachSV;
    typedef std::shared_ptr<SetGpsConfigurationForEachSV> SetGpsConfigurationForEachSVPtr;
    
    
    class SetGpsConfigurationForEachSV : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      SetGpsConfigurationForEachSV();

      SetGpsConfigurationForEachSV(const std::vector<int>& svConfigs);
  
      static SetGpsConfigurationForEachSVPtr create(const std::vector<int>& svConfigs);
      static SetGpsConfigurationForEachSVPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** svConfigs ****
      std::vector<int> svConfigs() const;
      void setSvConfigs(const std::vector<int>& svConfigs);
    };
  }
}

