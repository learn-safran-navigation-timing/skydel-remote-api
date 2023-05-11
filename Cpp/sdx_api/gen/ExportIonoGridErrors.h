#pragma once

#include <memory>
#include "command_base.h"

#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Export ionospheric grid errors.
    ///
    /// Name        Type   Description
    /// ----------- ------ -------------------------------
    /// Overwriting bool   Overwrite the old file if true.
    /// Path        string Grid file path
    ///

    class ExportIonoGridErrors;
    typedef std::shared_ptr<ExportIonoGridErrors> ExportIonoGridErrorsPtr;
    
    
    class ExportIonoGridErrors : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      ExportIonoGridErrors();

      ExportIonoGridErrors(bool overwriting, const std::string& path);

      static ExportIonoGridErrorsPtr create(bool overwriting, const std::string& path);
      static ExportIonoGridErrorsPtr dynamicCast(CommandBasePtr ptr);
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

