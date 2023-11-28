#pragma once

#include <memory>
#include "command_base.h"



namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Set time delay to start streaming after PPS synchronization. A value of 1500
    /// means the simulation will start streaming 1.5 sec after the PPS used for
    /// synchornization.
    ///
    /// Name Type   Description
    /// ---- ------ ----------------------------------------
    /// Time double Time delay in msec (minimum is 500 msec)
    ///

    class SetSyncTimeMainInstance;
    typedef std::shared_ptr<SetSyncTimeMainInstance> SetSyncTimeMainInstancePtr;
    
    
    class SetSyncTimeMainInstance : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      SetSyncTimeMainInstance();

      SetSyncTimeMainInstance(double time);

      static SetSyncTimeMainInstancePtr create(double time);
      static SetSyncTimeMainInstancePtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** time ****
      double time() const;
      void setTime(double time);
    };
    
  }
}

