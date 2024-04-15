#pragma once

#include <memory>
#include "command_base.h"

#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Import ionospheric grid mask for a giver service provider.
    ///
    /// Name            Type   Description
    /// --------------- ------ ------------------------------------
    /// ServiceProvider string The service provider
    /// Overwriting     bool   Overwrite the previous mask if true.
    /// Path            string Grid file path
    ///

    class ImportIonoGridMask;
    typedef std::shared_ptr<ImportIonoGridMask> ImportIonoGridMaskPtr;
    
    
    class ImportIonoGridMask : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      ImportIonoGridMask();

      ImportIonoGridMask(const std::string& serviceProvider, bool overwriting, const std::string& path);

      static ImportIonoGridMaskPtr create(const std::string& serviceProvider, bool overwriting, const std::string& path);
      static ImportIonoGridMaskPtr dynamicCast(CommandBasePtr ptr);
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

