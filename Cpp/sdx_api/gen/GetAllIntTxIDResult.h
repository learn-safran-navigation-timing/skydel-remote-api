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
    /// Result of GetAllIntTxID.
    ///
    /// Name Type         Description
    /// ---- ------------ ------------------------------------------
    /// Ids  array string ID list of all interferences transmitters.
    ///

    class GetAllIntTxIDResult;
    typedef std::shared_ptr<GetAllIntTxIDResult> GetAllIntTxIDResultPtr;
    
    
    class GetAllIntTxIDResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetAllIntTxIDResult();

      GetAllIntTxIDResult(const std::vector<std::string>& ids);

      GetAllIntTxIDResult(CommandBasePtr relatedCommand, const std::vector<std::string>& ids);

      static GetAllIntTxIDResultPtr create(const std::vector<std::string>& ids);

      static GetAllIntTxIDResultPtr create(CommandBasePtr relatedCommand, const std::vector<std::string>& ids);
      static GetAllIntTxIDResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;


      // **** ids ****
      std::vector<std::string> ids() const;
      void setIds(const std::vector<std::string>& ids);
    };
    REGISTER_COMMAND_RESULT_TO_FACTORY_DECL(GetAllIntTxIDResult);
  }
}

