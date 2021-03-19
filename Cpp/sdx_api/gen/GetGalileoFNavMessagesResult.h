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
    /// Result of GetGalileoFNavMessages
    ///
    /// Name Type         Description
    /// ---- ------------ -------------------------------------------------
    /// Ids  array string List of IDs of GALILEO FNAV Messages for this PRN
    ///

    class GetGalileoFNavMessagesResult;
    typedef std::shared_ptr<GetGalileoFNavMessagesResult> GetGalileoFNavMessagesResultPtr;
    
    
    class GetGalileoFNavMessagesResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetGalileoFNavMessagesResult();

      GetGalileoFNavMessagesResult(CommandBasePtr relatedCommand, const std::vector<std::string>& ids);
  
      static GetGalileoFNavMessagesResultPtr create(CommandBasePtr relatedCommand, const std::vector<std::string>& ids);
      static GetGalileoFNavMessagesResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;


      // **** ids ****
      std::vector<std::string> ids() const;
      void setIds(const std::vector<std::string>& ids);
    };
  }
}

