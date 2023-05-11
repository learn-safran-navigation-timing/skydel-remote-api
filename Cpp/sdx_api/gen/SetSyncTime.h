#pragma once

#include <memory>
#include "command_base.h"



namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Set time delay to start streaming, in order to allign PPS out Signal with RF.
    /// 2000 ms is a calibrated value.
    ///
    /// Name Type   Description
    /// ---- ------ ----------------------------------------
    /// Time double Time delay in msec (minimum is 500 msec)
    ///

    class SetSyncTime;
    typedef std::shared_ptr<SetSyncTime> SetSyncTimePtr;
    
    
    class SetSyncTime : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      SetSyncTime();

      SetSyncTime(double time);

      static SetSyncTimePtr create(double time);
      static SetSyncTimePtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** time ****
      double time() const;
      void setTime(double time);
    };
    
  }
}

