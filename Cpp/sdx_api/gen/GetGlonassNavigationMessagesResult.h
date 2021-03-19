#pragma once

#include <memory>
#include "command_result.h"
#include <string>
#include <vector>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of GetGlonassNavigationMessages
    ///
    /// Name Type         Description
    /// ---- ------------ -------------------------------------------
    /// Ids  array string List of ids event whose will affect the PRN
    ///

    class GetGlonassNavigationMessagesResult;
    typedef std::shared_ptr<GetGlonassNavigationMessagesResult> GetGlonassNavigationMessagesResultPtr;
    
    
    class GetGlonassNavigationMessagesResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetGlonassNavigationMessagesResult();

      GetGlonassNavigationMessagesResult(CommandBasePtr relatedCommand, const std::vector<std::string>& ids);
  
      static GetGlonassNavigationMessagesResultPtr create(CommandBasePtr relatedCommand, const std::vector<std::string>& ids);
      static GetGlonassNavigationMessagesResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;


      // **** ids ****
      std::vector<std::string> ids() const;
      void setIds(const std::vector<std::string>& ids);
    };
  }
}

