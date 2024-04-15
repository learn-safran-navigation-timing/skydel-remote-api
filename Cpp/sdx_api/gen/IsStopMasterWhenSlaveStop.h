#pragma once

#include <memory>
#include "command_base.h"



namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Please note the command IsStopMasterWhenSlaveStop is deprecated since 23.11. You may use IsStopMainInstanceWhenWorkerInstanceStop.
    /// 
    /// If enabled, master and all the slaves will stop if a slave stop.
    ///
    /// 
    ///

    class IsStopMasterWhenSlaveStop;
    typedef std::shared_ptr<IsStopMasterWhenSlaveStop> IsStopMasterWhenSlaveStopPtr;
    
    
    class IsStopMasterWhenSlaveStop : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;

      static const char* const Deprecated;


      IsStopMasterWhenSlaveStop();

      static IsStopMasterWhenSlaveStopPtr create();
      static IsStopMasterWhenSlaveStopPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;

      virtual Sdx::optional<std::string> deprecated() const override;

      virtual int executePermission() const override;
    };
    
  }
}

