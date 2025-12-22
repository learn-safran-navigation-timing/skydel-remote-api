#pragma once

#include <memory>
#include "command_base.h"

#include <optional>
#include <string>
#include <vector>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Set the systems monitored by SBAS.
    ///
    /// Name            Type            Description
    /// --------------- --------------- ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    /// Systems         array string    A list containing the name of monitored systems, only "GPS" and "SBAS" are supported
    /// ServiceProvider optional string The service provider. When not specified for a Setter command, the change is applied to all service providers. When not specified for a Getter command, the value for WAAS is returned.
    ///

    class SetSbasMonitoredSystems;
    typedef std::shared_ptr<SetSbasMonitoredSystems> SetSbasMonitoredSystemsPtr;
    
    
    class SetSbasMonitoredSystems : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      SetSbasMonitoredSystems();

      SetSbasMonitoredSystems(const std::vector<std::string>& systems, const std::optional<std::string>& serviceProvider = {});

      static SetSbasMonitoredSystemsPtr create(const std::vector<std::string>& systems, const std::optional<std::string>& serviceProvider = {});
      static SetSbasMonitoredSystemsPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;

      virtual int executePermission() const override;


      // **** systems ****
      std::vector<std::string> systems() const;
      void setSystems(const std::vector<std::string>& systems);


      // **** serviceProvider ****
      std::optional<std::string> serviceProvider() const;
      void setServiceProvider(const std::optional<std::string>& serviceProvider);
    };
    
  }
}

