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
    /// Import ionospheric grid GIVEI.
    ///
    /// Name            Type            Description
    /// --------------- --------------- ------------------------------------
    /// Overwriting     bool            Overwrite the previous grid if true.
    /// Path            string          Grid file path
    /// ServiceProvider optional string The service provider (optional)
    ///

    class ImportIonoGridGIVEI;
    typedef std::shared_ptr<ImportIonoGridGIVEI> ImportIonoGridGIVEIPtr;
    
    
    class ImportIonoGridGIVEI : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      ImportIonoGridGIVEI();

      ImportIonoGridGIVEI(bool overwriting, const std::string& path, const std::optional<std::string>& serviceProvider = {});

      static ImportIonoGridGIVEIPtr create(bool overwriting, const std::string& path, const std::optional<std::string>& serviceProvider = {});
      static ImportIonoGridGIVEIPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;

      virtual int executePermission() const override;


      // **** overwriting ****
      bool overwriting() const;
      void setOverwriting(bool overwriting);


      // **** path ****
      std::string path() const;
      void setPath(const std::string& path);


      // **** serviceProvider ****
      std::optional<std::string> serviceProvider() const;
      void setServiceProvider(const std::optional<std::string>& serviceProvider);
    };
    
  }
}

