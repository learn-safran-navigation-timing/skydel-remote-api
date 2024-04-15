#pragma once

#include <memory>
#include "command_result.h"
#include "command_factory.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of IsElevationMaskAboveEnabled.
    ///
    /// Name    Type Description
    /// ------- ---- ------------------------------------------------------------------
    /// Enabled bool If true, mask satellites with elevation angle above masking angle.
    ///

    class IsElevationMaskAboveEnabledResult;
    typedef std::shared_ptr<IsElevationMaskAboveEnabledResult> IsElevationMaskAboveEnabledResultPtr;
    
    
    class IsElevationMaskAboveEnabledResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      IsElevationMaskAboveEnabledResult();

      IsElevationMaskAboveEnabledResult(bool enabled);

      IsElevationMaskAboveEnabledResult(CommandBasePtr relatedCommand, bool enabled);

      static IsElevationMaskAboveEnabledResultPtr create(bool enabled);

      static IsElevationMaskAboveEnabledResultPtr create(CommandBasePtr relatedCommand, bool enabled);
      static IsElevationMaskAboveEnabledResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;


      // **** enabled ****
      bool enabled() const;
      void setEnabled(bool enabled);
    };
    REGISTER_COMMAND_TO_FACTORY_DECL(IsElevationMaskAboveEnabledResult);
  }
}

