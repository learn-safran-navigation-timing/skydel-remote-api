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
    /// Result of GetBeiDouCNav2Messages
    ///
    /// Name Type         Description
    /// ---- ------------ ---------------------------------------------------------------
    /// Ids  array string List of IDs of BeiDou CNAV2 Messages modifications for this PRN
    ///

    class GetBeiDouCNav2MessagesResult;
    typedef std::shared_ptr<GetBeiDouCNav2MessagesResult> GetBeiDouCNav2MessagesResultPtr;
    
    
    class GetBeiDouCNav2MessagesResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetBeiDouCNav2MessagesResult();

      GetBeiDouCNav2MessagesResult(CommandBasePtr relatedCommand, const std::vector<std::string>& ids);
  
      static GetBeiDouCNav2MessagesResultPtr create(CommandBasePtr relatedCommand, const std::vector<std::string>& ids);
      static GetBeiDouCNav2MessagesResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;


      // **** ids ****
      std::vector<std::string> ids() const;
      void setIds(const std::vector<std::string>& ids);
    };
  }
}

