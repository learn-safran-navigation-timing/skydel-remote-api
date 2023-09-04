#pragma once

#include <memory>
#include "command_base.h"

#include "gen/EncryptionSignalType.h"
#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Set the specific encryption signal library path.
    ///
    /// Name Type                 Description
    /// ---- -------------------- -------------------------
    /// Type EncryptionSignalType Encryption signal type.
    /// Path string               Path to the library file.
    ///

    class SetEncryptionLibraryPath;
    typedef std::shared_ptr<SetEncryptionLibraryPath> SetEncryptionLibraryPathPtr;
    
    
    class SetEncryptionLibraryPath : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      SetEncryptionLibraryPath();

      SetEncryptionLibraryPath(const Sdx::EncryptionSignalType& type, const std::string& path);

      static SetEncryptionLibraryPathPtr create(const Sdx::EncryptionSignalType& type, const std::string& path);
      static SetEncryptionLibraryPathPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** type ****
      Sdx::EncryptionSignalType type() const;
      void setType(const Sdx::EncryptionSignalType& type);


      // **** path ****
      std::string path() const;
      void setPath(const std::string& path);
    };
    
  }
}

