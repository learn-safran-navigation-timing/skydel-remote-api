#pragma once

#include <memory>
#include "command_result.h"
#include "command_factory.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of IsIonoOffsetEnabled.
    ///
    /// Name      Type Description
    /// --------- ---- ---------------------------------------------
    /// IsEnabled bool True if offsets are applied on the ionosphere
    ///

    class IsIonoOffsetEnabledResult;
    typedef std::shared_ptr<IsIonoOffsetEnabledResult> IsIonoOffsetEnabledResultPtr;
    
    
    class IsIonoOffsetEnabledResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      IsIonoOffsetEnabledResult();

      IsIonoOffsetEnabledResult(bool isEnabled);

      IsIonoOffsetEnabledResult(CommandBasePtr relatedCommand, bool isEnabled);

      static IsIonoOffsetEnabledResultPtr create(bool isEnabled);

      static IsIonoOffsetEnabledResultPtr create(CommandBasePtr relatedCommand, bool isEnabled);
      static IsIonoOffsetEnabledResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;


      // **** isEnabled ****
      bool isEnabled() const;
      void setIsEnabled(bool isEnabled);
    };
    REGISTER_COMMAND_TO_FACTORY_DECL(IsIonoOffsetEnabledResult);
  }
}

