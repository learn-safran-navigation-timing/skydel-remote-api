#pragma once

#include <memory>
#include "command_result.h"
#include "command_factory.h"
#include <optional>
#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of IsUsingVelocityInSbasMessage25.
    ///
    /// Name            Type            Description
    /// --------------- --------------- ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    /// UseVelocity     bool            Whether SBAS message 25 should send velocity corrections
    /// ServiceProvider optional string The service provider. When not specified for a Setter command, the change is applied to all service providers. When not specified for a Getter command, the value for WAAS is returned.
    ///

    class IsUsingVelocityInSbasMessage25Result;
    typedef std::shared_ptr<IsUsingVelocityInSbasMessage25Result> IsUsingVelocityInSbasMessage25ResultPtr;
    
    
    class IsUsingVelocityInSbasMessage25Result : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      IsUsingVelocityInSbasMessage25Result();

      IsUsingVelocityInSbasMessage25Result(bool useVelocity, const std::optional<std::string>& serviceProvider = {});

      IsUsingVelocityInSbasMessage25Result(CommandBasePtr relatedCommand, bool useVelocity, const std::optional<std::string>& serviceProvider = {});

      static IsUsingVelocityInSbasMessage25ResultPtr create(bool useVelocity, const std::optional<std::string>& serviceProvider = {});

      static IsUsingVelocityInSbasMessage25ResultPtr create(CommandBasePtr relatedCommand, bool useVelocity, const std::optional<std::string>& serviceProvider = {});
      static IsUsingVelocityInSbasMessage25ResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;


      // **** useVelocity ****
      bool useVelocity() const;
      void setUseVelocity(bool useVelocity);


      // **** serviceProvider ****
      std::optional<std::string> serviceProvider() const;
      void setServiceProvider(const std::optional<std::string>& serviceProvider);
    };
    REGISTER_COMMAND_TO_FACTORY_DECL(IsUsingVelocityInSbasMessage25Result);
  }
}

