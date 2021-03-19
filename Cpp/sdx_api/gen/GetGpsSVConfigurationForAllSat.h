#pragma once

#include <memory>
#include "command_base.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Please note the command GetGpsSVConfigurationForAllSat is deprecated since 21.3. You may use GetGpsConfigurationForEachSV.
    /// 
    /// Get GPS SV configuration flag for each SVs
    ///
    /// 
    ///

    class GetGpsSVConfigurationForAllSat;
    typedef std::shared_ptr<GetGpsSVConfigurationForAllSat> GetGpsSVConfigurationForAllSatPtr;
    
    
    class GetGpsSVConfigurationForAllSat : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetGpsSVConfigurationForAllSat();
  
      static GetGpsSVConfigurationForAllSatPtr create();
      static GetGpsSVConfigurationForAllSatPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;
    };
  }
}

