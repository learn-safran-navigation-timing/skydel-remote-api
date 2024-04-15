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
    /// Result of GetAllMultipathFor(Signal|SV|System) commands.
    ///
    /// Name Type         Description
    /// ---- ------------ ------------------------------------------------------
    /// Ids  array string IDs of multipaths for the specified argument in getter
    ///

    class GetAllMultipathForResult;
    typedef std::shared_ptr<GetAllMultipathForResult> GetAllMultipathForResultPtr;
    
    
    class GetAllMultipathForResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      GetAllMultipathForResult();

      GetAllMultipathForResult(const std::vector<std::string>& ids);

      GetAllMultipathForResult(CommandBasePtr relatedCommand, const std::vector<std::string>& ids);

      static GetAllMultipathForResultPtr create(const std::vector<std::string>& ids);

      static GetAllMultipathForResultPtr create(CommandBasePtr relatedCommand, const std::vector<std::string>& ids);
      static GetAllMultipathForResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;


      // **** ids ****
      std::vector<std::string> ids() const;
      void setIds(const std::vector<std::string>& ids);
    };
    REGISTER_COMMAND_TO_FACTORY_DECL(GetAllMultipathForResult);
  }
}

