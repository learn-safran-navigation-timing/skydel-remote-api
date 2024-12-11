#pragma once

#include <memory>
#include "command_base.h"



namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Enable (or disable) automatic GPU allocation to outputs.
    ///
    /// Name    Type Description
    /// ------- ---- ---------------------------------------------------------------------------------------------------------
    /// Enabled bool If enabled, Skydel will automatically assign available GPUs to each added output to optimize performance.
    ///

    class EnableAutomaticGpuAllocation;
    typedef std::shared_ptr<EnableAutomaticGpuAllocation> EnableAutomaticGpuAllocationPtr;
    
    
    class EnableAutomaticGpuAllocation : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      EnableAutomaticGpuAllocation();

      EnableAutomaticGpuAllocation(bool enabled);

      static EnableAutomaticGpuAllocationPtr create(bool enabled);
      static EnableAutomaticGpuAllocationPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;

      virtual int executePermission() const override;


      // **** enabled ****
      bool enabled() const;
      void setEnabled(bool enabled);
    };
    
  }
}

