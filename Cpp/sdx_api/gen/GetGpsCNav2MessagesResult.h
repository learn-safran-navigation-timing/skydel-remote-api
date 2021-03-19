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
    /// Result of GetGpsCNav2Messages
    ///
    /// Name Type         Description
    /// ---- ------------ ----------------------------------------------
    /// Ids  array string List of IDs of Gps CNAV2 Messages for this PRN
    ///

    class GetGpsCNav2MessagesResult;
    typedef std::shared_ptr<GetGpsCNav2MessagesResult> GetGpsCNav2MessagesResultPtr;
    
    
    class GetGpsCNav2MessagesResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetGpsCNav2MessagesResult();

      GetGpsCNav2MessagesResult(CommandBasePtr relatedCommand, const std::vector<std::string>& ids);
  
      static GetGpsCNav2MessagesResultPtr create(CommandBasePtr relatedCommand, const std::vector<std::string>& ids);
      static GetGpsCNav2MessagesResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;


      // **** ids ****
      std::vector<std::string> ids() const;
      void setIds(const std::vector<std::string>& ids);
    };
  }
}

