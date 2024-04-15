#pragma once

#include <memory>
#include "command_base.h"

#include "gen/EncryptionSignalType.h"

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Test the specific encryption signal library.
    ///
    /// Name Type                 Description
    /// ---- -------------------- -----------------------
    /// Type EncryptionSignalType Encryption signal type.
    ///

    class TestEncryptionLibrary;
    typedef std::shared_ptr<TestEncryptionLibrary> TestEncryptionLibraryPtr;
    
    
    class TestEncryptionLibrary : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      TestEncryptionLibrary();

      TestEncryptionLibrary(const Sdx::EncryptionSignalType& type);

      static TestEncryptionLibraryPtr create(const Sdx::EncryptionSignalType& type);
      static TestEncryptionLibraryPtr dynamicCast(CommandBasePtr ptr);
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

