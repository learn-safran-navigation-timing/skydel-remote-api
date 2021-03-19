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
    /// Result of GetGpsCNavMessages
    ///
    /// Name Type         Description
    /// ---- ------------ ---------------------------------------------
    /// Ids  array string List of IDs of Gps CNAV Messages for this PRN
    ///

    class GetGpsCNavMessagesResult;
    typedef std::shared_ptr<GetGpsCNavMessagesResult> GetGpsCNavMessagesResultPtr;
    
    
    class GetGpsCNavMessagesResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetGpsCNavMessagesResult();

      GetGpsCNavMessagesResult(CommandBasePtr relatedCommand, const std::vector<std::string>& ids);
  
      static GetGpsCNavMessagesResultPtr create(CommandBasePtr relatedCommand, const std::vector<std::string>& ids);
      static GetGpsCNavMessagesResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;


      // **** ids ****
      std::vector<std::string> ids() const;
      void setIds(const std::vector<std::string>& ids);
    };
  }
}

