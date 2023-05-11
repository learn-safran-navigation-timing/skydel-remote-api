#pragma once

#include <memory>
#include "command_base.h"



namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Enable/Disable Time Synchronization Slave.
    /// The Slave will wait for the Master to synchronize the simulators.
    ///
    /// Name    Type Description
    /// ------- ---- ---------------------------------------------------------------------------
    /// Enabled bool If true, this simulator will wait for the master to synchronize simulators.
    ///

    class EnableSlavePps;
    typedef std::shared_ptr<EnableSlavePps> EnableSlavePpsPtr;
    
    
    class EnableSlavePps : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      EnableSlavePps();

      EnableSlavePps(bool enabled);

      static EnableSlavePpsPtr create(bool enabled);
      static EnableSlavePpsPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** enabled ****
      bool enabled() const;
      void setEnabled(bool enabled);
    };
    
  }
}

