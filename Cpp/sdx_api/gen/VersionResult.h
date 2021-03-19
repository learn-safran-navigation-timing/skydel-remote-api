#pragma once

#include <memory>
#include "command_result.h"
#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of the command "GetVersion"
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


      VersionResult();

      VersionResult(CommandBasePtr relatedCommand, const std::string& version);
  
      static VersionResultPtr create(CommandBasePtr relatedCommand, const std::string& version);
      static VersionResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;


      // **** version ****
      std::string version() const;
      void setVersion(const std::string& version);
    };
  }
}

