#pragma once

#include <memory>
#include "command_base.h"

#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Open configuration.
    ///
    /// Name                 Type   Description
    /// -------------------- ------ ----------------------------------------------------------------------------------------------------
    /// Path                 string Filename path, Automatically add file suffix if missing. If folder not defined, user default folder.
    /// DiscardCurrentConfig bool   Discard current config even if it is not saved
    ///

    class Open;
    typedef std::shared_ptr<Open> OpenPtr;
    
    
    class Open : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      Open();

      Open(const std::string& path, bool discardCurrentConfig);

      static OpenPtr create(const std::string& path, bool discardCurrentConfig);
      static OpenPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** path ****
      std::string path() const;
      void setPath(const std::string& path);


      // **** discardCurrentConfig ****
      bool discardCurrentConfig() const;
      void setDiscardCurrentConfig(bool discardCurrentConfig);
    };
    
  }
}

