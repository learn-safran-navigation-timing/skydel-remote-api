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
    /// Result of GetAllSpoofTxID.
    ///
    /// Name Type         Description
    /// ---- ------------ ------------------------------------
    /// Ids  array string ID list of all spoofer transmitters.
    ///

    class GetAllSpoofTxIDResult;
    typedef std::shared_ptr<GetAllSpoofTxIDResult> GetAllSpoofTxIDResultPtr;
    
    
    class GetAllSpoofTxIDResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetAllSpoofTxIDResult();

      GetAllSpoofTxIDResult(const std::vector<std::string>& ids);

      GetAllSpoofTxIDResult(CommandBasePtr relatedCommand, const std::vector<std::string>& ids);

      static GetAllSpoofTxIDResultPtr create(const std::vector<std::string>& ids);

      static GetAllSpoofTxIDResultPtr create(CommandBasePtr relatedCommand, const std::vector<std::string>& ids);
      static GetAllSpoofTxIDResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;


      // **** ids ****
      std::vector<std::string> ids() const;
      void setIds(const std::vector<std::string>& ids);
    };
    REGISTER_COMMAND_RESULT_TO_FACTORY_DECL(GetAllSpoofTxIDResult);
  }
}

