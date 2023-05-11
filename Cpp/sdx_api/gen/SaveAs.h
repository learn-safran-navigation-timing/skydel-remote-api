#pragma once

#include <memory>
#include "command_base.h"

#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Save configuration with new name.
    ///
    /// Name      Type   Description
    /// --------- ------ ---------------------------------------------------------------------------------------------------------
    /// Path      string Configuration path. Automatically add file suffix if missing. If folder not defined, user default folder.
    /// Overwrite bool   Overwrite existing configuration if is exists
    ///

    class SaveAs;
    typedef std::shared_ptr<SaveAs> SaveAsPtr;
    
    
    class SaveAs : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      SaveAs();

      SaveAs(const std::string& path, bool overwrite);

      static SaveAsPtr create(const std::string& path, bool overwrite);
      static SaveAsPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** path ****
      std::string path() const;
      void setPath(const std::string& path);


      // **** overwrite ****
      bool overwrite() const;
      void setOverwrite(bool overwrite);
    };
    
  }
}

