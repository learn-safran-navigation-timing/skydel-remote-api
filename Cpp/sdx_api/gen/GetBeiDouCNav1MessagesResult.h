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
    /// Result of GetBeiDouCNav1Messages
    ///
    /// Name Type         Description
    /// ---- ------------ -------------------------------------------------
    /// Ids  array string List of IDs of BeiDou CNAV1 Messages for this PRN
    ///

    class GetBeiDouCNav1MessagesResult;
    typedef std::shared_ptr<GetBeiDouCNav1MessagesResult> GetBeiDouCNav1MessagesResultPtr;
    
    
    class GetBeiDouCNav1MessagesResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetBeiDouCNav1MessagesResult();

      GetBeiDouCNav1MessagesResult(CommandBasePtr relatedCommand, const std::vector<std::string>& ids);
  
      static GetBeiDouCNav1MessagesResultPtr create(CommandBasePtr relatedCommand, const std::vector<std::string>& ids);
      static GetBeiDouCNav1MessagesResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;


      // **** ids ****
      std::vector<std::string> ids() const;
      void setIds(const std::vector<std::string>& ids);
    };
  }
}

