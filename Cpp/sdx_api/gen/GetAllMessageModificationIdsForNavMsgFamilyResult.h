#pragma once

#include <memory>
#include "command_result.h"
#include "command_result_factory.h"
#include <string>
#include <vector>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of GetAllMessageModificationIdsForNavMsgFamily.
    ///
    /// Name Type         Description
    /// ---- ------------ -------------------------------------------------------------------------
    /// Ids  array string List of event IDs which will modify the navigation message for this SV ID
    ///

    class GetAllMessageModificationIdsForNavMsgFamilyResult;
    typedef std::shared_ptr<GetAllMessageModificationIdsForNavMsgFamilyResult> GetAllMessageModificationIdsForNavMsgFamilyResultPtr;
    
    
    class GetAllMessageModificationIdsForNavMsgFamilyResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetAllMessageModificationIdsForNavMsgFamilyResult();

      GetAllMessageModificationIdsForNavMsgFamilyResult(const std::vector<std::string>& ids);

      GetAllMessageModificationIdsForNavMsgFamilyResult(CommandBasePtr relatedCommand, const std::vector<std::string>& ids);

      static GetAllMessageModificationIdsForNavMsgFamilyResultPtr create(const std::vector<std::string>& ids);

      static GetAllMessageModificationIdsForNavMsgFamilyResultPtr create(CommandBasePtr relatedCommand, const std::vector<std::string>& ids);
      static GetAllMessageModificationIdsForNavMsgFamilyResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;


      // **** ids ****
      std::vector<std::string> ids() const;
      void setIds(const std::vector<std::string>& ids);
    };
    REGISTER_COMMAND_RESULT_TO_FACTORY_DECL(GetAllMessageModificationIdsForNavMsgFamilyResult);
  }
}

