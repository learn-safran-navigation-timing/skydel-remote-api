#pragma once

#include <memory>
#include "command_result.h"
#include "command_result_factory.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of IsLogNmeaEnabled.
    ///
    /// Name    Type Description
    /// ------- ---- --------------------------------------------------
    /// Enabled bool If true, file(s) will be created during simulation
    ///

    class IsLogNmeaEnabledResult;
    typedef std::shared_ptr<IsLogNmeaEnabledResult> IsLogNmeaEnabledResultPtr;
    
    
    class IsLogNmeaEnabledResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      IsLogNmeaEnabledResult();

      IsLogNmeaEnabledResult(bool enabled);

      IsLogNmeaEnabledResult(CommandBasePtr relatedCommand, bool enabled);

      static IsLogNmeaEnabledResultPtr create(bool enabled);

      static IsLogNmeaEnabledResultPtr create(CommandBasePtr relatedCommand, bool enabled);
      static IsLogNmeaEnabledResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;


      // **** enabled ****
      bool enabled() const;
      void setEnabled(bool enabled);
    };
    REGISTER_COMMAND_RESULT_TO_FACTORY_DECL(IsLogNmeaEnabledResult);
  }
}

