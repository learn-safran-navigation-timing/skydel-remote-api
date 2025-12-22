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
    /// Set whether SBAS message 24 should be used to replace a fast correction message (2-5) when applicable.
    ///
    /// Name            Type            Description
    /// --------------- --------------- --------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    /// Enabled         bool            If enabled (true, default), Skydel will attempt to insert message 24 as a replacement for a message 2-5 when applicable. If disabled (false), Skydel will not attempt to include message 24 in the message sequence.
    /// ServiceProvider optional string The service provider. When not specified for a Setter command, the change is applied to all service providers. When not specified for a Getter command, the value for WAAS is returned.
    ///

    class EnableSbasMixedCorrectionsMessage;
    typedef std::shared_ptr<EnableSbasMixedCorrectionsMessage> EnableSbasMixedCorrectionsMessagePtr;
    
    
    class EnableSbasMixedCorrectionsMessage : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      EnableSbasMixedCorrectionsMessage();

      EnableSbasMixedCorrectionsMessage(bool enabled, const std::optional<std::string>& serviceProvider = {});

      static EnableSbasMixedCorrectionsMessagePtr create(bool enabled, const std::optional<std::string>& serviceProvider = {});
      static EnableSbasMixedCorrectionsMessagePtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;

      virtual int executePermission() const override;


      // **** enabled ****
      bool enabled() const;
      void setEnabled(bool enabled);


      // **** serviceProvider ****
      std::optional<std::string> serviceProvider() const;
      void setServiceProvider(const std::optional<std::string>& serviceProvider);
    };
    
  }
}

