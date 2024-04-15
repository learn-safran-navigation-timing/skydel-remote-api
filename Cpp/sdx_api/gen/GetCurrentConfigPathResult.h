#pragma once

#include <memory>
#include "command_result.h"
#include "command_factory.h"
#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of GetCurrentConfigPath.
    ///
    /// Name       Type   Description
    /// ---------- ------ ----------------------------------------------
    /// ConfigPath string The config file path currently used by Skydel.
    ///

    class GetCurrentConfigPathResult;
    typedef std::shared_ptr<GetCurrentConfigPathResult> GetCurrentConfigPathResultPtr;
    
    
    class GetCurrentConfigPathResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      GetCurrentConfigPathResult();

      GetCurrentConfigPathResult(const std::string& configPath);

      GetCurrentConfigPathResult(CommandBasePtr relatedCommand, const std::string& configPath);

      static GetCurrentConfigPathResultPtr create(const std::string& configPath);

      static GetCurrentConfigPathResultPtr create(CommandBasePtr relatedCommand, const std::string& configPath);
      static GetCurrentConfigPathResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;


      // **** configPath ****
      std::string configPath() const;
      void setConfigPath(const std::string& configPath);
    };
    REGISTER_COMMAND_TO_FACTORY_DECL(GetCurrentConfigPathResult);
  }
}

