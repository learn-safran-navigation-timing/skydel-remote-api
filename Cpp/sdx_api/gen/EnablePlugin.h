#pragma once

#include <memory>
#include "command_base.h"

#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Enable a plug-in for the whole system.
    ///
    /// Name    Type   Description
    /// ------- ------ --------------------------------------------------------------------------
    /// Id      string Plug-in ID.
    /// Enabled bool   Whether the plug-in is enabled for the whole system (true) or not (false).
    ///

    class EnablePlugin;
    typedef std::shared_ptr<EnablePlugin> EnablePluginPtr;
    
    
    class EnablePlugin : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      EnablePlugin();

      EnablePlugin(const std::string& id, bool enabled);

      static EnablePluginPtr create(const std::string& id, bool enabled);
      static EnablePluginPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;

      virtual int executePermission() const override;


      // **** id ****
      std::string id() const;
      void setId(const std::string& id);


      // **** enabled ****
      bool enabled() const;
      void setEnabled(bool enabled);
    };
    
  }
}

