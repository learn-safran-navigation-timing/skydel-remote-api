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
    /// Get whether SBAS message 24 should be used to replace a fast correction message (2-5) when applicable.
    ///
    /// Name            Type            Description
    /// --------------- --------------- ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    /// ServiceProvider optional string The service provider. When not specified for a Setter command, the change is applied to all service providers. When not specified for a Getter command, the value for WAAS is returned.
    ///

    class IsSbasMixedCorrectionsMessageEnabled;
    typedef std::shared_ptr<IsSbasMixedCorrectionsMessageEnabled> IsSbasMixedCorrectionsMessageEnabledPtr;
    
    
    class IsSbasMixedCorrectionsMessageEnabled : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      IsSbasMixedCorrectionsMessageEnabled(const std::optional<std::string>& serviceProvider = {});

      static IsSbasMixedCorrectionsMessageEnabledPtr create(const std::optional<std::string>& serviceProvider = {});
      static IsSbasMixedCorrectionsMessageEnabledPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;

      virtual int executePermission() const override;


      // **** serviceProvider ****
      std::optional<std::string> serviceProvider() const;
      void setServiceProvider(const std::optional<std::string>& serviceProvider);
    };
    
  }
}

