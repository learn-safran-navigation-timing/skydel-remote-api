#pragma once

#include <memory>
#include "command_result.h"
#include "command_factory.h"
#include "sdx_optional.h"

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of IsLogNmeaEnabled.
    ///
    /// Name              Type          Description
    /// ----------------- ------------- -----------------------------------------------------------------------------
    /// Enabled           bool          If true, file(s) will be created during simulation
    /// SerialPortEnabled optional bool If true, the log is streamed to the serial port specified in the Preferences.
    ///

    class IsLogNmeaEnabledResult;
    typedef std::shared_ptr<IsLogNmeaEnabledResult> IsLogNmeaEnabledResultPtr;
    
    
    class IsLogNmeaEnabledResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      IsLogNmeaEnabledResult();

      IsLogNmeaEnabledResult(bool enabled, const Sdx::optional<bool>& serialPortEnabled = {});

      IsLogNmeaEnabledResult(CommandBasePtr relatedCommand, bool enabled, const Sdx::optional<bool>& serialPortEnabled = {});

      static IsLogNmeaEnabledResultPtr create(bool enabled, const Sdx::optional<bool>& serialPortEnabled = {});

      static IsLogNmeaEnabledResultPtr create(CommandBasePtr relatedCommand, bool enabled, const Sdx::optional<bool>& serialPortEnabled = {});
      static IsLogNmeaEnabledResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;


      // **** enabled ****
      bool enabled() const;
      void setEnabled(bool enabled);


      // **** serialPortEnabled ****
      Sdx::optional<bool> serialPortEnabled() const;
      void setSerialPortEnabled(const Sdx::optional<bool>& serialPortEnabled);
    };
    REGISTER_COMMAND_TO_FACTORY_DECL(IsLogNmeaEnabledResult);
  }
}

