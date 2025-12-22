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
    /// Set whether SBAS message 25 should send velocity corrections
    ///
    /// Name            Type            Description
    /// --------------- --------------- ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    /// UseVelocity     bool            Whether SBAS message 25 should send velocity corrections
    /// ServiceProvider optional string The service provider. When not specified for a Setter command, the change is applied to all service providers. When not specified for a Getter command, the value for WAAS is returned.
    ///

    class SetUsingVelocityInSbasMessage25;
    typedef std::shared_ptr<SetUsingVelocityInSbasMessage25> SetUsingVelocityInSbasMessage25Ptr;
    
    
    class SetUsingVelocityInSbasMessage25 : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      SetUsingVelocityInSbasMessage25();

      SetUsingVelocityInSbasMessage25(bool useVelocity, const std::optional<std::string>& serviceProvider = {});

      static SetUsingVelocityInSbasMessage25Ptr create(bool useVelocity, const std::optional<std::string>& serviceProvider = {});
      static SetUsingVelocityInSbasMessage25Ptr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;

      virtual int executePermission() const override;


      // **** useVelocity ****
      bool useVelocity() const;
      void setUseVelocity(bool useVelocity);


      // **** serviceProvider ****
      std::optional<std::string> serviceProvider() const;
      void setServiceProvider(const std::optional<std::string>& serviceProvider);
    };
    
  }
}

