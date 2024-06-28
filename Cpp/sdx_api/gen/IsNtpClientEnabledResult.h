#pragma once

#include <memory>
#include "command_result.h"
#include "command_factory.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of IsNtpClientEnabled.
    ///
    /// Name    Type Description
    /// ------- ---- --------------------------------------------------------------------------------
    /// Enabled bool If enabled, the NTP client will attempt to connect to the configured NTP server.
    ///

    class IsNtpClientEnabledResult;
    typedef std::shared_ptr<IsNtpClientEnabledResult> IsNtpClientEnabledResultPtr;
    
    
    class IsNtpClientEnabledResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      IsNtpClientEnabledResult();

      IsNtpClientEnabledResult(bool enabled);

      IsNtpClientEnabledResult(CommandBasePtr relatedCommand, bool enabled);

      static IsNtpClientEnabledResultPtr create(bool enabled);

      static IsNtpClientEnabledResultPtr create(CommandBasePtr relatedCommand, bool enabled);
      static IsNtpClientEnabledResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;


      // **** enabled ****
      bool enabled() const;
      void setEnabled(bool enabled);
    };
    REGISTER_COMMAND_TO_FACTORY_DECL(IsNtpClientEnabledResult);
  }
}

