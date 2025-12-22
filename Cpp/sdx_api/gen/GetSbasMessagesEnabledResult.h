#pragma once

#include <memory>
#include "command_result.h"
#include "command_factory.h"
#include <optional>
#include <string>
#include <vector>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of GetSbasMessagesEnabled.
    ///
    /// Name            Type            Description
    /// --------------- --------------- ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    /// Messages        array int       The enabled messages
    /// ServiceProvider optional string The service provider. When not specified for a Setter command, the change is applied to all service providers. When not specified for a Getter command, the value for WAAS is returned.
    ///

    class GetSbasMessagesEnabledResult;
    typedef std::shared_ptr<GetSbasMessagesEnabledResult> GetSbasMessagesEnabledResultPtr;
    
    
    class GetSbasMessagesEnabledResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      GetSbasMessagesEnabledResult();

      GetSbasMessagesEnabledResult(const std::vector<int>& messages, const std::optional<std::string>& serviceProvider = {});

      GetSbasMessagesEnabledResult(CommandBasePtr relatedCommand, const std::vector<int>& messages, const std::optional<std::string>& serviceProvider = {});

      static GetSbasMessagesEnabledResultPtr create(const std::vector<int>& messages, const std::optional<std::string>& serviceProvider = {});

      static GetSbasMessagesEnabledResultPtr create(CommandBasePtr relatedCommand, const std::vector<int>& messages, const std::optional<std::string>& serviceProvider = {});
      static GetSbasMessagesEnabledResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;


      // **** messages ****
      std::vector<int> messages() const;
      void setMessages(const std::vector<int>& messages);


      // **** serviceProvider ****
      std::optional<std::string> serviceProvider() const;
      void setServiceProvider(const std::optional<std::string>& serviceProvider);
    };
    REGISTER_COMMAND_TO_FACTORY_DECL(GetSbasMessagesEnabledResult);
  }
}

