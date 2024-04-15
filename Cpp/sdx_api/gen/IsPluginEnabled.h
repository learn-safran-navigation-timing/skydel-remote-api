#pragma once

#include <memory>
#include "command_base.h"

#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Get whether a plug-in is enabled for the whole system.
    ///
    /// Name Type   Description
    /// ---- ------ -----------
    /// Id   string Plug-in ID.
    ///

    class IsPluginEnabled;
    typedef std::shared_ptr<IsPluginEnabled> IsPluginEnabledPtr;
    
    
    class IsPluginEnabled : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      IsPluginEnabled();

      IsPluginEnabled(const std::string& id);

      static IsPluginEnabledPtr create(const std::string& id);
      static IsPluginEnabledPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;

      virtual int executePermission() const override;


      // **** id ****
      std::string id() const;
      void setId(const std::string& id);
    };
    
  }
}

