#pragma once

#include <memory>
#include "command_base.h"

#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Set external channels path.
    ///
    /// Name Type   Description
    /// ---- ------ -----------------------------
    /// Path string Path to the sdxpand directory
    ///

    class SetExternalChannelsPath;
    typedef std::shared_ptr<SetExternalChannelsPath> SetExternalChannelsPathPtr;
    
    
    class SetExternalChannelsPath : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      SetExternalChannelsPath();

      SetExternalChannelsPath(const std::string& path);

      static SetExternalChannelsPathPtr create(const std::string& path);
      static SetExternalChannelsPathPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** path ****
      std::string path() const;
      void setPath(const std::string& path);
    };
    
  }
}

