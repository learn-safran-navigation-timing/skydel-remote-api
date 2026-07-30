#pragma once

#include <memory>
#include "command_base.h"

#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Set the Geoid file path.
    ///
    /// Name Type   Description
    /// ---- ------ ------------------------------
    /// Path string Path to the Geoid file to use.
    ///

    class SetGeoidFilePath;
    typedef std::shared_ptr<SetGeoidFilePath> SetGeoidFilePathPtr;
    
    
    class SetGeoidFilePath : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      SetGeoidFilePath();

      SetGeoidFilePath(const std::string& path);

      static SetGeoidFilePathPtr create(const std::string& path);
      static SetGeoidFilePathPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;

      virtual int executePermission() const override;


      // **** path ****
      std::string path() const;
      void setPath(const std::string& path);
    };
    
  }
}

