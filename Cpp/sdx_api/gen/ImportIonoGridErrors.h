#pragma once

#include <memory>
#include "command_base.h"

#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Import ionospheric grid errors.
    ///
    /// Name        Type   Description
    /// ----------- ------ ------------------------------------
    /// Overwriting bool   Overwrite the previous grid if true.
    /// Path        string Grid file path
    ///

    class ImportIonoGridErrors;
    typedef std::shared_ptr<ImportIonoGridErrors> ImportIonoGridErrorsPtr;
    
    
    class ImportIonoGridErrors : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      ImportIonoGridErrors();

      ImportIonoGridErrors(bool overwriting, const std::string& path);

      static ImportIonoGridErrorsPtr create(bool overwriting, const std::string& path);
      static ImportIonoGridErrorsPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** overwriting ****
      bool overwriting() const;
      void setOverwriting(bool overwriting);


      // **** path ****
      std::string path() const;
      void setPath(const std::string& path);
    };
    
  }
}

