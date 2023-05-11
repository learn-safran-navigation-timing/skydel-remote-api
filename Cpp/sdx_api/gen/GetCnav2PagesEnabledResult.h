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
    /// Result of GetCnav2PagesEnabled.
    ///
    /// Name     Type      Description
    /// -------- --------- -----------------
    /// Messages array int The enabled pages
    ///

    class GetCnav2PagesEnabledResult;
    typedef std::shared_ptr<GetCnav2PagesEnabledResult> GetCnav2PagesEnabledResultPtr;
    
    
    class GetCnav2PagesEnabledResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetCnav2PagesEnabledResult();

      GetCnav2PagesEnabledResult(const std::vector<int>& messages);

      GetCnav2PagesEnabledResult(CommandBasePtr relatedCommand, const std::vector<int>& messages);

      static GetCnav2PagesEnabledResultPtr create(const std::vector<int>& messages);

      static GetCnav2PagesEnabledResultPtr create(CommandBasePtr relatedCommand, const std::vector<int>& messages);
      static GetCnav2PagesEnabledResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;


      // **** messages ****
      std::vector<int> messages() const;
      void setMessages(const std::vector<int>& messages);
    };
    REGISTER_COMMAND_RESULT_TO_FACTORY_DECL(GetCnav2PagesEnabledResult);
  }
}

