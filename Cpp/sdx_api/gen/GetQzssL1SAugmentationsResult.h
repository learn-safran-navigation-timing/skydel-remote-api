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
    /// Result of GetQzssL1SAugmentations.
    ///
    /// Name Type         Description
    /// ---- ------------ --------------------------------------
    /// Ids  array string List of IDs of QZSS L1S augmentations.
    ///

    class GetQzssL1SAugmentationsResult;
    typedef std::shared_ptr<GetQzssL1SAugmentationsResult> GetQzssL1SAugmentationsResultPtr;
    
    
    class GetQzssL1SAugmentationsResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetQzssL1SAugmentationsResult();

      GetQzssL1SAugmentationsResult(const std::vector<std::string>& ids);

      GetQzssL1SAugmentationsResult(CommandBasePtr relatedCommand, const std::vector<std::string>& ids);

      static GetQzssL1SAugmentationsResultPtr create(const std::vector<std::string>& ids);

      static GetQzssL1SAugmentationsResultPtr create(CommandBasePtr relatedCommand, const std::vector<std::string>& ids);
      static GetQzssL1SAugmentationsResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;


      // **** ids ****
      std::vector<std::string> ids() const;
      void setIds(const std::vector<std::string>& ids);
    };
    REGISTER_COMMAND_RESULT_TO_FACTORY_DECL(GetQzssL1SAugmentationsResult);
  }
}

