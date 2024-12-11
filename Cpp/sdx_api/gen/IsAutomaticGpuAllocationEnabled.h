#pragma once

#include <memory>
#include "command_base.h"



namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Indicates whether GPUs are automatically allocated to outputs.
    ///
    /// 
    ///

    class IsAutomaticGpuAllocationEnabled;
    typedef std::shared_ptr<IsAutomaticGpuAllocationEnabled> IsAutomaticGpuAllocationEnabledPtr;
    
    
    class IsAutomaticGpuAllocationEnabled : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      IsAutomaticGpuAllocationEnabled();

      static IsAutomaticGpuAllocationEnabledPtr create();
      static IsAutomaticGpuAllocationEnabledPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;

      virtual int executePermission() const override;
    };
    
  }
}

