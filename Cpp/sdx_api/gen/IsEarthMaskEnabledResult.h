#pragma once

#include <memory>
#include "command_result.h"
#include "command_factory.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of IsEarthMaskEnabled.
    ///
    /// Name    Type Description
    /// ------- ---- ----------------------------------------------------------------------------------------------
    /// Enabled bool If disabled, all satellites will be visible, thereby eliminating the Earth's occlusion effect.
    ///

    class IsEarthMaskEnabledResult;
    typedef std::shared_ptr<IsEarthMaskEnabledResult> IsEarthMaskEnabledResultPtr;
    
    
    class IsEarthMaskEnabledResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      IsEarthMaskEnabledResult();

      IsEarthMaskEnabledResult(bool enabled);

      IsEarthMaskEnabledResult(CommandBasePtr relatedCommand, bool enabled);

      static IsEarthMaskEnabledResultPtr create(bool enabled);

      static IsEarthMaskEnabledResultPtr create(CommandBasePtr relatedCommand, bool enabled);
      static IsEarthMaskEnabledResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;


      // **** enabled ****
      bool enabled() const;
      void setEnabled(bool enabled);
    };
    REGISTER_COMMAND_TO_FACTORY_DECL(IsEarthMaskEnabledResult);
  }
}

