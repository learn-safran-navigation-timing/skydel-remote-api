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
    /// Result of GetBeiDouD2NavigationMessages
    ///
    /// Name Type         Description
    /// ---- ------------ -------------------------------------------
    /// Ids  array string List of ids event whose will affect the PRN
    ///

    class GetBeiDouD2NavigationMessagesResult;
    typedef std::shared_ptr<GetBeiDouD2NavigationMessagesResult> GetBeiDouD2NavigationMessagesResultPtr;
    
    
    class GetBeiDouD2NavigationMessagesResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetBeiDouD2NavigationMessagesResult();

      GetBeiDouD2NavigationMessagesResult(CommandBasePtr relatedCommand, const std::vector<std::string>& ids);
  
      static GetBeiDouD2NavigationMessagesResultPtr create(CommandBasePtr relatedCommand, const std::vector<std::string>& ids);
      static GetBeiDouD2NavigationMessagesResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;


      // **** ids ****
      std::vector<std::string> ids() const;
      void setIds(const std::vector<std::string>& ids);
    };
  }
}

