#pragma once

#include <memory>
#include "command_base.h"



namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Please note the command EnableSlavePps is deprecated since 23.11. You may use EnableWorkerInstanceSync.
    /// 
    /// Enable/Disable Time Synchronization on worker instance.
    /// The worker instance will wait for the main instance to synchronize the simulators.
    ///
    /// Name    Type Description
    /// ------- ---- ----------------------------------------------------------------------------------
    /// Enabled bool If true, this simulator will wait for the main instance to synchronize simulators.
    ///

    class EnableSlavePps;
    typedef std::shared_ptr<EnableSlavePps> EnableSlavePpsPtr;
    
    
    class EnableSlavePps : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      EnableSlavePps();

      EnableSlavePps(bool enabled);

      static EnableSlavePpsPtr create(bool enabled);
      static EnableSlavePpsPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;

      virtual int executePermission() const override;


      // **** enabled ****
      bool enabled() const;
      void setEnabled(bool enabled);
    };
    
  }
}

