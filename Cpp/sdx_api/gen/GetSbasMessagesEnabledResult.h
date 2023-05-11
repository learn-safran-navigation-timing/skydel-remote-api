#pragma once

#include <memory>
#include "command_result.h"
#include "command_result_factory.h"
#include <vector>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of GetSbasMessagesEnabled.
    ///
    /// Name     Type      Description
    /// -------- --------- --------------------
    /// Messages array int The enabled messages
    ///

    class GetSbasMessagesEnabledResult;
    typedef std::shared_ptr<GetSbasMessagesEnabledResult> GetSbasMessagesEnabledResultPtr;
    
    
    class GetSbasMessagesEnabledResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetSbasMessagesEnabledResult();

      GetSbasMessagesEnabledResult(const std::vector<int>& messages);

      GetSbasMessagesEnabledResult(CommandBasePtr relatedCommand, const std::vector<int>& messages);

      static GetSbasMessagesEnabledResultPtr create(const std::vector<int>& messages);

      static GetSbasMessagesEnabledResultPtr create(CommandBasePtr relatedCommand, const std::vector<int>& messages);
      static GetSbasMessagesEnabledResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;


      // **** messages ****
      std::vector<int> messages() const;
      void setMessages(const std::vector<int>& messages);
    };
    REGISTER_COMMAND_RESULT_TO_FACTORY_DECL(GetSbasMessagesEnabledResult);
  }
}

