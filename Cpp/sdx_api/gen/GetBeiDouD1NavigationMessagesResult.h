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
    /// Result of GetBeiDouD1NavigationMessages
    ///
    /// Name Type         Description
    /// ---- ------------ -------------------------------------------
    /// Ids  array string List of ids event whose will affect the PRN
    ///

    class GetBeiDouD1NavigationMessagesResult;
    typedef std::shared_ptr<GetBeiDouD1NavigationMessagesResult> GetBeiDouD1NavigationMessagesResultPtr;
    
    
    class GetBeiDouD1NavigationMessagesResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetBeiDouD1NavigationMessagesResult();

      GetBeiDouD1NavigationMessagesResult(CommandBasePtr relatedCommand, const std::vector<std::string>& ids);
  
      static GetBeiDouD1NavigationMessagesResultPtr create(CommandBasePtr relatedCommand, const std::vector<std::string>& ids);
      static GetBeiDouD1NavigationMessagesResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;


      // **** ids ****
      std::vector<std::string> ids() const;
      void setIds(const std::vector<std::string>& ids);
    };
  }
}

