#pragma once

#include <memory>
#include "command_base.h"

#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Set the path to the directory containing the terrain elevation data files.
    ///
    /// Name Type   Description
    /// ---- ------ ---------------------------
    /// Path string Path to the elevation data.
    ///

    class SetElevationDataPath;
    typedef std::shared_ptr<SetElevationDataPath> SetElevationDataPathPtr;
    
    
    class SetElevationDataPath : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      SetElevationDataPath();

      SetElevationDataPath(const std::string& path);

      static SetElevationDataPathPtr create(const std::string& path);
      static SetElevationDataPathPtr dynamicCast(CommandBasePtr ptr);
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

