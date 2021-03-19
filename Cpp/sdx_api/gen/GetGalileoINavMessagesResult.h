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
    /// Result of GetGalileoINavMessages
    ///
    /// Name Type         Description
    /// ---- ------------ -------------------------------------------------
    /// Ids  array string List of IDs of GALILEO INAV Messages for this PRN
    ///

    class GetGalileoINavMessagesResult;
    typedef std::shared_ptr<GetGalileoINavMessagesResult> GetGalileoINavMessagesResultPtr;
    
    
    class GetGalileoINavMessagesResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetGalileoINavMessagesResult();

      GetGalileoINavMessagesResult(CommandBasePtr relatedCommand, const std::vector<std::string>& ids);
  
      static GetGalileoINavMessagesResultPtr create(CommandBasePtr relatedCommand, const std::vector<std::string>& ids);
      static GetGalileoINavMessagesResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;


      // **** ids ****
      std::vector<std::string> ids() const;
      void setIds(const std::vector<std::string>& ids);
    };
  }
}

