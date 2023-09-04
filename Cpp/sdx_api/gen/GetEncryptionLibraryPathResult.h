#pragma once

#include <memory>
#include "command_result.h"
#include "command_result_factory.h"
#include "gen/EncryptionSignalType.h"
#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of GetEncryptionLibraryPath.
    ///
    /// Name Type                 Description
    /// ---- -------------------- -------------------------
    /// Type EncryptionSignalType Encryption signal type.
    /// Path string               Path to the library file.
    ///

    class GetEncryptionLibraryPathResult;
    typedef std::shared_ptr<GetEncryptionLibraryPathResult> GetEncryptionLibraryPathResultPtr;
    
    
    class GetEncryptionLibraryPathResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetEncryptionLibraryPathResult();

      GetEncryptionLibraryPathResult(const Sdx::EncryptionSignalType& type, const std::string& path);

      GetEncryptionLibraryPathResult(CommandBasePtr relatedCommand, const Sdx::EncryptionSignalType& type, const std::string& path);

      static GetEncryptionLibraryPathResultPtr create(const Sdx::EncryptionSignalType& type, const std::string& path);

      static GetEncryptionLibraryPathResultPtr create(CommandBasePtr relatedCommand, const Sdx::EncryptionSignalType& type, const std::string& path);
      static GetEncryptionLibraryPathResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;


      // **** type ****
      Sdx::EncryptionSignalType type() const;
      void setType(const Sdx::EncryptionSignalType& type);


      // **** path ****
      std::string path() const;
      void setPath(const std::string& path);
    };
    REGISTER_COMMAND_RESULT_TO_FACTORY_DECL(GetEncryptionLibraryPathResult);
  }
}

