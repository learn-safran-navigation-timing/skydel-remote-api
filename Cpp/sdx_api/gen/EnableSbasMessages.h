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
    /// Set the enabled SBAS messages. Message 63 is always enabled
    ///
    /// Name            Type            Description
    /// --------------- --------------- ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    /// Messages        array int       The enabled messages
    /// ServiceProvider optional string The service provider. When not specified for a Setter command, the change is applied to all service providers. When not specified for a Getter command, the value for WAAS is returned.
    ///

    class EnableSbasMessages;
    typedef std::shared_ptr<EnableSbasMessages> EnableSbasMessagesPtr;
    
    
    class EnableSbasMessages : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      EnableSbasMessages();

      EnableSbasMessages(const std::vector<int>& messages, const std::optional<std::string>& serviceProvider = {});

      static EnableSbasMessagesPtr create(const std::vector<int>& messages, const std::optional<std::string>& serviceProvider = {});
      static EnableSbasMessagesPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;

      virtual int executePermission() const override;


      // **** messages ****
      std::vector<int> messages() const;
      void setMessages(const std::vector<int>& messages);


      // **** serviceProvider ****
      std::optional<std::string> serviceProvider() const;
      void setServiceProvider(const std::optional<std::string>& serviceProvider);
    };
    
  }
}

