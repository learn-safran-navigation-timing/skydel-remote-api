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
    /// Result of GetMessageModifications
    ///
    /// Name Type         Description
    /// ---- ------------ -----------
    /// Ids  array string Signal
    ///

    class GetMessageModificationsResult;
    typedef std::shared_ptr<GetMessageModificationsResult> GetMessageModificationsResultPtr;
    
    
    class GetMessageModificationsResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetMessageModificationsResult();

      GetMessageModificationsResult(CommandBasePtr relatedCommand, const std::vector<std::string>& ids);
  
      static GetMessageModificationsResultPtr create(CommandBasePtr relatedCommand, const std::vector<std::string>& ids);
      static GetMessageModificationsResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;


      // **** ids ****
      std::vector<std::string> ids() const;
      void setIds(const std::vector<std::string>& ids);
    };
  }
}

