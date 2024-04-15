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
    /// Result of GetConfigPaths.
    ///
    /// Name  Type         Description
    /// ----- ------------ --------------------------------
    /// Paths array string Paths of the configuration files
    ///

    class GetConfigPathsResult;
    typedef std::shared_ptr<GetConfigPathsResult> GetConfigPathsResultPtr;
    
    
    class GetConfigPathsResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      GetConfigPathsResult();

      GetConfigPathsResult(const std::vector<std::string>& paths);

      GetConfigPathsResult(CommandBasePtr relatedCommand, const std::vector<std::string>& paths);

      static GetConfigPathsResultPtr create(const std::vector<std::string>& paths);

      static GetConfigPathsResultPtr create(CommandBasePtr relatedCommand, const std::vector<std::string>& paths);
      static GetConfigPathsResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;


      // **** paths ****
      std::vector<std::string> paths() const;
      void setPaths(const std::vector<std::string>& paths);
    };
    REGISTER_COMMAND_TO_FACTORY_DECL(GetConfigPathsResult);
  }
}

