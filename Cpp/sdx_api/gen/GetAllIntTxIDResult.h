#pragma once

#include <memory>
#include "command_result.h"
#include "command_factory.h"
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
      static const char* const TargetId;


      GetAllIntTxIDResult();

      GetAllIntTxIDResult(const std::vector<std::string>& ids);

      GetAllIntTxIDResult(CommandBasePtr relatedCommand, const std::vector<std::string>& ids);

      static GetAllIntTxIDResultPtr create(const std::vector<std::string>& ids);

      static GetAllIntTxIDResultPtr create(CommandBasePtr relatedCommand, const std::vector<std::string>& ids);
      static GetAllIntTxIDResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;


      // **** ids ****
      std::vector<std::string> ids() const;
      void setIds(const std::vector<std::string>& ids);
    };
    REGISTER_COMMAND_TO_FACTORY_DECL(GetAllIntTxIDResult);
  }
}

