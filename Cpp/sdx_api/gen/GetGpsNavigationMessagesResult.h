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
    /// Result of GetGpsNavigationMessages
    ///
    /// Name Type         Description
    /// ---- ------------ -------------------------------------------
    /// Ids  array string List of ids event whose will affect the PRN
    ///

    class GetGpsNavigationMessagesResult;
    typedef std::shared_ptr<GetGpsNavigationMessagesResult> GetGpsNavigationMessagesResultPtr;
    
    
    class GetGpsNavigationMessagesResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetGpsNavigationMessagesResult();

      GetGpsNavigationMessagesResult(CommandBasePtr relatedCommand, const std::vector<std::string>& ids);
  
      static GetGpsNavigationMessagesResultPtr create(CommandBasePtr relatedCommand, const std::vector<std::string>& ids);
      static GetGpsNavigationMessagesResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;


      // **** ids ****
      std::vector<std::string> ids() const;
      void setIds(const std::vector<std::string>& ids);
    };
  }
}

