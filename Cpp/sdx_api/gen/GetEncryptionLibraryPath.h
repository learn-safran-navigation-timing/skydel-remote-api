#pragma once

#include <memory>
#include "command_base.h"

#include "gen/EncryptionSignalType.h"

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Get the specific encryption signal library path.
    ///
    /// Name Type                 Description
    /// ---- -------------------- -----------------------
    /// Type EncryptionSignalType Encryption signal type.
    ///

    class GetEncryptionLibraryPath;
    typedef std::shared_ptr<GetEncryptionLibraryPath> GetEncryptionLibraryPathPtr;
    
    
    class GetEncryptionLibraryPath : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      GetEncryptionLibraryPath();

      GetEncryptionLibraryPath(const Sdx::EncryptionSignalType& type);

      static GetEncryptionLibraryPathPtr create(const Sdx::EncryptionSignalType& type);
      static GetEncryptionLibraryPathPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;

      virtual int executePermission() const override;


      // **** type ****
      Sdx::EncryptionSignalType type() const;
      void setType(const Sdx::EncryptionSignalType& type);
    };
    
  }
}

