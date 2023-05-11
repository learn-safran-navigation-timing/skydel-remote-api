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
    /// Result of GetAllMessageModificationIdsForSignal.
    ///
    /// Name Type         Description
    /// ---- ------------ -------------------------------------------------------------------------
    /// Ids  array string List of event IDs which will modify the navigation message for this SV ID
    ///

    class GetAllMessageModificationIdsForSignalResult;
    typedef std::shared_ptr<GetAllMessageModificationIdsForSignalResult> GetAllMessageModificationIdsForSignalResultPtr;
    
    
    class GetAllMessageModificationIdsForSignalResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetAllMessageModificationIdsForSignalResult();

      GetAllMessageModificationIdsForSignalResult(const std::vector<std::string>& ids);

      GetAllMessageModificationIdsForSignalResult(CommandBasePtr relatedCommand, const std::vector<std::string>& ids);

      static GetAllMessageModificationIdsForSignalResultPtr create(const std::vector<std::string>& ids);

      static GetAllMessageModificationIdsForSignalResultPtr create(CommandBasePtr relatedCommand, const std::vector<std::string>& ids);
      static GetAllMessageModificationIdsForSignalResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;


      // **** ids ****
      std::vector<std::string> ids() const;
      void setIds(const std::vector<std::string>& ids);
    };
    REGISTER_COMMAND_RESULT_TO_FACTORY_DECL(GetAllMessageModificationIdsForSignalResult);
  }
}

