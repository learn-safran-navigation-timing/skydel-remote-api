#pragma once

#include <memory>
#include "command_result.h"
#include "command_factory.h"
#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of IsPluginEnabled.
    ///
    /// Name    Type   Description
    /// ------- ------ --------------------------------------------------------------------------
    /// Id      string Plug-in ID.
    /// Enabled bool   Whether the plug-in is enabled for the whole system (true) or not (false).
    ///

    class IsPluginEnabledResult;
    typedef std::shared_ptr<IsPluginEnabledResult> IsPluginEnabledResultPtr;
    
    
    class IsPluginEnabledResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      IsPluginEnabledResult();

      IsPluginEnabledResult(const std::string& id, bool enabled);

      IsPluginEnabledResult(CommandBasePtr relatedCommand, const std::string& id, bool enabled);

      static IsPluginEnabledResultPtr create(const std::string& id, bool enabled);

      static IsPluginEnabledResultPtr create(CommandBasePtr relatedCommand, const std::string& id, bool enabled);
      static IsPluginEnabledResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;


      // **** id ****
      std::string id() const;
      void setId(const std::string& id);


      // **** enabled ****
      bool enabled() const;
      void setEnabled(bool enabled);
    };
    REGISTER_COMMAND_TO_FACTORY_DECL(IsPluginEnabledResult);
  }
}

