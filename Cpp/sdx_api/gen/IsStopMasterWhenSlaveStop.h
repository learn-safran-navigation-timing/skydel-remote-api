#pragma once

#include <memory>
#include "command_base.h"



namespace Sdx
{
  namespace Cmd
  {
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


      IsStopMasterWhenSlaveStop();

      static IsStopMasterWhenSlaveStopPtr create();
      static IsStopMasterWhenSlaveStopPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;
    };
    
  }
}

