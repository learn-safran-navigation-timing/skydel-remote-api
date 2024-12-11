#pragma once

#include <memory>
#include "command_result.h"
#include "command_factory.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of IsAutomaticGpuAllocationEnabled.
    ///
    /// Name    Type Description
    /// ------- ---- ---------------------------------------------------------------------------------------------------------
    /// Enabled bool If enabled, Skydel will automatically assign available GPUs to each added output to optimize performance.
    ///

    class IsAutomaticGpuAllocationEnabledResult;
    typedef std::shared_ptr<IsAutomaticGpuAllocationEnabledResult> IsAutomaticGpuAllocationEnabledResultPtr;
    
    
    class IsAutomaticGpuAllocationEnabledResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      IsAutomaticGpuAllocationEnabledResult();

      IsAutomaticGpuAllocationEnabledResult(bool enabled);

      IsAutomaticGpuAllocationEnabledResult(CommandBasePtr relatedCommand, bool enabled);

      static IsAutomaticGpuAllocationEnabledResultPtr create(bool enabled);

      static IsAutomaticGpuAllocationEnabledResultPtr create(CommandBasePtr relatedCommand, bool enabled);
      static IsAutomaticGpuAllocationEnabledResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;


      // **** enabled ****
      bool enabled() const;
      void setEnabled(bool enabled);
    };
    REGISTER_COMMAND_TO_FACTORY_DECL(IsAutomaticGpuAllocationEnabledResult);
  }
}

