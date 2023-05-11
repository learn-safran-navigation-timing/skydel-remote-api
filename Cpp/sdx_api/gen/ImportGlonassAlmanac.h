#pragma once

#include <memory>
#include "command_base.h"

#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Import GLONASS almanac file
    ///
    /// Name Type   Description
    /// ---- ------ -----------------
    /// Path string Almanac file path
    ///

    class ImportGlonassAlmanac;
    typedef std::shared_ptr<ImportGlonassAlmanac> ImportGlonassAlmanacPtr;
    
    
    class ImportGlonassAlmanac : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      ImportGlonassAlmanac();

      ImportGlonassAlmanac(const std::string& path);

      static ImportGlonassAlmanacPtr create(const std::string& path);
      static ImportGlonassAlmanacPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** path ****
      std::string path() const;
      void setPath(const std::string& path);
    };
    
  }
}

