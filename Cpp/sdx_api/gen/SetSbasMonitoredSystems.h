#pragma once

#include <memory>
#include "command_base.h"

#include <string>
#include <vector>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Set the systems monitored by SBAS.
    ///
    /// Name    Type         Description
    /// ------- ------------ ------------------------------------------------------------------------------------
    /// Systems array string A list containing the name of monitored systems, only "GPS" and "SBAS" are supported
    ///

    class SetSbasMonitoredSystems;
    typedef std::shared_ptr<SetSbasMonitoredSystems> SetSbasMonitoredSystemsPtr;
    
    
    class SetSbasMonitoredSystems : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      SetSbasMonitoredSystems();

      SetSbasMonitoredSystems(const std::vector<std::string>& systems);

      static SetSbasMonitoredSystemsPtr create(const std::vector<std::string>& systems);
      static SetSbasMonitoredSystemsPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** systems ****
      std::vector<std::string> systems() const;
      void setSystems(const std::vector<std::string>& systems);
    };
    
  }
}

