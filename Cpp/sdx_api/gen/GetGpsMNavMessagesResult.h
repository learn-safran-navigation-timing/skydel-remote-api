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
    /// Result of GetGpsMNavMessages
    ///
    /// Name Type         Description
    /// ---- ------------ ---------------------------------------------
    /// Ids  array string List of IDs of Gps MNAV Messages for this PRN
    ///

    class GetGpsMNavMessagesResult;
    typedef std::shared_ptr<GetGpsMNavMessagesResult> GetGpsMNavMessagesResultPtr;
    
    
    class GetGpsMNavMessagesResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetGpsMNavMessagesResult();

      GetGpsMNavMessagesResult(CommandBasePtr relatedCommand, const std::vector<std::string>& ids);
  
      static GetGpsMNavMessagesResultPtr create(CommandBasePtr relatedCommand, const std::vector<std::string>& ids);
      static GetGpsMNavMessagesResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;


      // **** ids ****
      std::vector<std::string> ids() const;
      void setIds(const std::vector<std::string>& ids);
    };
  }
}

