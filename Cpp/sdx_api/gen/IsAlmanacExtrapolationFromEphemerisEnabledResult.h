#pragma once

#include <memory>
#include "command_result.h"
#include "command_result_factory.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of IsAlmanacExtrapolationFromEphemerisEnabled.
    ///
    /// Name    Type Description
    /// ------- ---- -------------------------------
    /// Enabled bool State of almanac extrapolation.
    ///

    class IsAlmanacExtrapolationFromEphemerisEnabledResult;
    typedef std::shared_ptr<IsAlmanacExtrapolationFromEphemerisEnabledResult> IsAlmanacExtrapolationFromEphemerisEnabledResultPtr;
    
    
    class IsAlmanacExtrapolationFromEphemerisEnabledResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      IsAlmanacExtrapolationFromEphemerisEnabledResult();

      IsAlmanacExtrapolationFromEphemerisEnabledResult(bool enabled);

      IsAlmanacExtrapolationFromEphemerisEnabledResult(CommandBasePtr relatedCommand, bool enabled);

      static IsAlmanacExtrapolationFromEphemerisEnabledResultPtr create(bool enabled);

      static IsAlmanacExtrapolationFromEphemerisEnabledResultPtr create(CommandBasePtr relatedCommand, bool enabled);
      static IsAlmanacExtrapolationFromEphemerisEnabledResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;


      // **** enabled ****
      bool enabled() const;
      void setEnabled(bool enabled);
    };
    REGISTER_COMMAND_RESULT_TO_FACTORY_DECL(IsAlmanacExtrapolationFromEphemerisEnabledResult);
  }
}

