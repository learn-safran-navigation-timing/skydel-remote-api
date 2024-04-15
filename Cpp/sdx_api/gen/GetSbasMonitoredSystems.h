#pragma once

#include <memory>
#include "command_base.h"



namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Get the systems monitored by SBAS.
    ///
    /// 
    ///

    class GetSbasMonitoredSystems;
    typedef std::shared_ptr<GetSbasMonitoredSystems> GetSbasMonitoredSystemsPtr;
    
    
    class GetSbasMonitoredSystems : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      GetSbasMonitoredSystems();

      static GetSbasMonitoredSystemsPtr create();
      static GetSbasMonitoredSystemsPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;

      virtual int executePermission() const override;
    };
    
  }
}

