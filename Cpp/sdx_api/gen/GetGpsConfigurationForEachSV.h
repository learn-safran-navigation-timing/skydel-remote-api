#pragma once

#include <memory>
#include "command_base.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Get GPS SV configuration flag for each SVs
    ///
    /// 
    ///

    class GetGpsConfigurationForEachSV;
    typedef std::shared_ptr<GetGpsConfigurationForEachSV> GetGpsConfigurationForEachSVPtr;
    
    
    class GetGpsConfigurationForEachSV : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetGpsConfigurationForEachSV();
  
      static GetGpsConfigurationForEachSVPtr create();
      static GetGpsConfigurationForEachSVPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;
    };
  }
}

