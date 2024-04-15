#pragma once

#include <memory>
#include "command_base.h"



namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Please note the command GetSyncTimeMaster is deprecated since 23.11. You may use GetSyncTimeMainInstance.
    /// 
    /// Get time delay to start streaming after PPS synchronization. A value of 1500
    /// means the simulation will start streaming 1.5 sec after the PPS used for
    /// synchornization.
    ///
    /// 
    ///

    class GetSyncTimeMaster;
    typedef std::shared_ptr<GetSyncTimeMaster> GetSyncTimeMasterPtr;
    
    
    class GetSyncTimeMaster : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      GetSyncTimeMaster();

      static GetSyncTimeMasterPtr create();
      static GetSyncTimeMasterPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;

      virtual int executePermission() const override;
    };
    
  }
}

