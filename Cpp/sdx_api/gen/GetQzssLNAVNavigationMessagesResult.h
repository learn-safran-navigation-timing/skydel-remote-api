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
    /// Result of GetQzssLNAVNavigationMessages
    ///
    /// Name Type         Description
    /// ---- ------------ ---------------------------------------------
    /// Ids  array string List of ids event whose will affect the SV ID
    ///

    class GetQzssLNAVNavigationMessagesResult;
    typedef std::shared_ptr<GetQzssLNAVNavigationMessagesResult> GetQzssLNAVNavigationMessagesResultPtr;
    
    
    class GetQzssLNAVNavigationMessagesResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetQzssLNAVNavigationMessagesResult();

      GetQzssLNAVNavigationMessagesResult(CommandBasePtr relatedCommand, const std::vector<std::string>& ids);
  
      static GetQzssLNAVNavigationMessagesResultPtr create(CommandBasePtr relatedCommand, const std::vector<std::string>& ids);
      static GetQzssLNAVNavigationMessagesResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;


      // **** ids ****
      std::vector<std::string> ids() const;
      void setIds(const std::vector<std::string>& ids);
    };
  }
}

