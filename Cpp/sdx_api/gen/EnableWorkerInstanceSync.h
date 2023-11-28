#pragma once

#include <memory>
#include "command_base.h"



namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Enable/Disable Time Synchronization on worker instance.
    /// The worker instance will wait for the main instance to synchronize the simulators.
    ///
    /// Name    Type Description
    /// ------- ---- ----------------------------------------------------------------------------------
    /// Enabled bool If true, this simulator will wait for the main instance to synchronize simulators.
    ///

    class EnableWorkerInstanceSync;
    typedef std::shared_ptr<EnableWorkerInstanceSync> EnableWorkerInstanceSyncPtr;
    
    
    class EnableWorkerInstanceSync : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      EnableWorkerInstanceSync();

      EnableWorkerInstanceSync(bool enabled);

      static EnableWorkerInstanceSyncPtr create(bool enabled);
      static EnableWorkerInstanceSyncPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** enabled ****
      bool enabled() const;
      void setEnabled(bool enabled);
    };
    
  }
}

