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
    /// Result of GetVersion.
    ///
    /// Name    Type   Description
    /// ------- ------ --------------
    /// Version string Skydel version
    ///

    class VersionResult;
    typedef std::shared_ptr<VersionResult> VersionResultPtr;
    
    
    class VersionResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      VersionResult();

      VersionResult(const std::string& version);

      VersionResult(CommandBasePtr relatedCommand, const std::string& version);

      static VersionResultPtr create(const std::string& version);

      static VersionResultPtr create(CommandBasePtr relatedCommand, const std::string& version);
      static VersionResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;


      // **** version ****
      std::string version() const;
      void setVersion(const std::string& version);
    };
    REGISTER_COMMAND_TO_FACTORY_DECL(VersionResult);
  }
}

