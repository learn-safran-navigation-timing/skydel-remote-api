#pragma once

#include <memory>
#include "command_base.h"



namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Please note the command SetSyncTimeMaster is deprecated since 23.11. You may use SetSyncTimeMainInstance.
    /// 
    /// Set time delay to start streaming after PPS synchronization. A value of 1500
    /// means the simulation will start streaming 1.5 sec after the PPS used for
    /// synchornization.
    ///
    /// Name Type   Description
    /// ---- ------ ----------------------------------------
    /// Time double Time delay in msec (minimum is 500 msec)
    ///

    class SetSyncTimeMaster;
    typedef std::shared_ptr<SetSyncTimeMaster> SetSyncTimeMasterPtr;
    
    
    class SetSyncTimeMaster : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      SetSyncTimeMaster();

      SetSyncTimeMaster(double time);

      static SetSyncTimeMasterPtr create(double time);
      static SetSyncTimeMasterPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** time ****
      double time() const;
      void setTime(double time);
    };
    
  }
}

