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
    /// Result of GetPlugins.
    ///
    /// Name    Type         Description
    /// ------- ------------ ---------------------------------------------------------------------
    /// Plugins array string List of all Plug-ins present on the system (regardless of the state).
    ///

    class GetPluginsResult;
    typedef std::shared_ptr<GetPluginsResult> GetPluginsResultPtr;
    
    
    class GetPluginsResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      GetPluginsResult();

      GetPluginsResult(const std::vector<std::string>& plugins);

      GetPluginsResult(CommandBasePtr relatedCommand, const std::vector<std::string>& plugins);

      static GetPluginsResultPtr create(const std::vector<std::string>& plugins);

      static GetPluginsResultPtr create(CommandBasePtr relatedCommand, const std::vector<std::string>& plugins);
      static GetPluginsResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;


      // **** plugins ****
      std::vector<std::string> plugins() const;
      void setPlugins(const std::vector<std::string>& plugins);
    };
    REGISTER_COMMAND_TO_FACTORY_DECL(GetPluginsResult);
  }
}

