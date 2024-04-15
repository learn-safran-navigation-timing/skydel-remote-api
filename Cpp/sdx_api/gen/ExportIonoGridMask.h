#pragma once

#include <memory>
#include "command_base.h"

#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Export ionospheric grid mask for a given service provider.
    ///
    /// Name            Type   Description
    /// --------------- ------ -------------------------------
    /// ServiceProvider string The service provider
    /// Overwriting     bool   Overwrite the old file if true.
    /// Path            string Grid file path
    ///

    class ExportIonoGridMask;
    typedef std::shared_ptr<ExportIonoGridMask> ExportIonoGridMaskPtr;
    
    
    class ExportIonoGridMask : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      ExportIonoGridMask();

      ExportIonoGridMask(const std::string& serviceProvider, bool overwriting, const std::string& path);

      static ExportIonoGridMaskPtr create(const std::string& serviceProvider, bool overwriting, const std::string& path);
      static ExportIonoGridMaskPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;

      virtual int executePermission() const override;


      // **** serviceProvider ****
      std::string serviceProvider() const;
      void setServiceProvider(const std::string& serviceProvider);


      // **** overwriting ****
      bool overwriting() const;
      void setOverwriting(bool overwriting);


      // **** path ****
      std::string path() const;
      void setPath(const std::string& path);
    };
    
  }
}

