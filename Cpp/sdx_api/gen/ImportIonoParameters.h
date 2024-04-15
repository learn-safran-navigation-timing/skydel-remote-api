#pragma once

#include <memory>
#include "command_base.h"

#include "sdx_optional.h"
#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Import ionospheric parameters from a Rinex file.
    ///
    /// Name Type            Description
    /// ---- --------------- ------------------------------------------------------------------------------
    /// Path string          File path
    /// Type optional string Ionospheric parameters type: "Klobuchar" or "BDGIM". The default is Klobuchar.
    ///

    class ImportIonoParameters;
    typedef std::shared_ptr<ImportIonoParameters> ImportIonoParametersPtr;
    
    
    class ImportIonoParameters : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      ImportIonoParameters();

      ImportIonoParameters(const std::string& path, const Sdx::optional<std::string>& type = {});

      static ImportIonoParametersPtr create(const std::string& path, const Sdx::optional<std::string>& type = {});
      static ImportIonoParametersPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;

      virtual int executePermission() const override;


      // **** path ****
      std::string path() const;
      void setPath(const std::string& path);


      // **** type ****
      Sdx::optional<std::string> type() const;
      void setType(const Sdx::optional<std::string>& type);
    };
    
  }
}

