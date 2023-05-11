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
    /// Name    Type Description
    /// ------- ---- ---------------------------------------
    /// Enabled bool Enable master stop when slave fail flag
    ///

    class StopMasterWhenSlaveStop;
    typedef std::shared_ptr<StopMasterWhenSlaveStop> StopMasterWhenSlaveStopPtr;
    
    
    class StopMasterWhenSlaveStop : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      StopMasterWhenSlaveStop();

      StopMasterWhenSlaveStop(bool enabled);

      static StopMasterWhenSlaveStopPtr create(bool enabled);
      static StopMasterWhenSlaveStopPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** enabled ****
      bool enabled() const;
      void setEnabled(bool enabled);
    };
    
  }
}

