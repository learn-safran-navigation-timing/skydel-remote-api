#pragma once

#include <memory>
#include "command_base.h"



namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Get time delay to start streaming, in order to allign PPS out Signal with RF.
    /// 2000 ms is a calibrated value.
    ///
    /// 
    ///

    class GetSyncTime;
    typedef std::shared_ptr<GetSyncTime> GetSyncTimePtr;
    
    
    class GetSyncTime : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetSyncTime();

      static GetSyncTimePtr create();
      static GetSyncTimePtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;
    };
    
  }
}

