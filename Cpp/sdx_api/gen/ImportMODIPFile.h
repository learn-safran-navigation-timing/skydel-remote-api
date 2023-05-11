#pragma once

#include <memory>
#include "command_base.h"

#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Import MODIP data file.
    ///
    /// Name Type   Description
    /// ---- ------ -----------
    /// Path string File path.
    ///

    class ImportMODIPFile;
    typedef std::shared_ptr<ImportMODIPFile> ImportMODIPFilePtr;
    
    
    class ImportMODIPFile : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      ImportMODIPFile();

      ImportMODIPFile(const std::string& path);

      static ImportMODIPFilePtr create(const std::string& path);
      static ImportMODIPFilePtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** path ****
      std::string path() const;
      void setPath(const std::string& path);
    };
    
  }
}

