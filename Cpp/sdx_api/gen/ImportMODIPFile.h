#pragma once

#include <memory>
#include "command_base.h"

#include <optional>
#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Import MODIP data file.
    ///
    /// Name      Type            Description
    /// --------- --------------- --------------------------------------------------------------------------------------------------------------------------------------------------
    /// Path      string          File path.
    /// IonoModel optional string Ionospheric model, accepted values are "NeQuick" and "NeQuick2-MLF2". If no value is provided, the modification will be appllied to NeQuick model.
    ///

    class ImportMODIPFile;
    typedef std::shared_ptr<ImportMODIPFile> ImportMODIPFilePtr;
    
    
    class ImportMODIPFile : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      ImportMODIPFile();

      ImportMODIPFile(const std::string& path, const std::optional<std::string>& ionoModel = {});

      static ImportMODIPFilePtr create(const std::string& path, const std::optional<std::string>& ionoModel = {});
      static ImportMODIPFilePtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;

      virtual int executePermission() const override;


      // **** path ****
      std::string path() const;
      void setPath(const std::string& path);


      // **** ionoModel ****
      std::optional<std::string> ionoModel() const;
      void setIonoModel(const std::optional<std::string>& ionoModel);
    };
    
  }
}

