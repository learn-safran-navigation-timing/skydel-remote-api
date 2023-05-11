#pragma once

#include <memory>
#include "command_result.h"
#include "command_result_factory.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of IsElevationMaskBelowEnabled.
    ///
    /// Name    Type Description
    /// ------- ---- ------------------------------------------------------------------
    /// Enabled bool If true, mask satellites with elevation angle below masking angle.
    ///

    class IsElevationMaskBelowEnabledResult;
    typedef std::shared_ptr<IsElevationMaskBelowEnabledResult> IsElevationMaskBelowEnabledResultPtr;
    
    
    class IsElevationMaskBelowEnabledResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      IsElevationMaskBelowEnabledResult();

      IsElevationMaskBelowEnabledResult(bool enabled);

      IsElevationMaskBelowEnabledResult(CommandBasePtr relatedCommand, bool enabled);

      static IsElevationMaskBelowEnabledResultPtr create(bool enabled);

      static IsElevationMaskBelowEnabledResultPtr create(CommandBasePtr relatedCommand, bool enabled);
      static IsElevationMaskBelowEnabledResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;


      // **** enabled ****
      bool enabled() const;
      void setEnabled(bool enabled);
    };
    REGISTER_COMMAND_RESULT_TO_FACTORY_DECL(IsElevationMaskBelowEnabledResult);
  }
}

