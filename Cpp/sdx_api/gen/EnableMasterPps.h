#pragma once

#include <memory>
#include "command_base.h"



namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Enable/Disable Time Synchronization Master.
    /// The Master will control other Skydel simulators with Slave PPS Enabled.
    ///
    /// Name    Type Description
    /// ------- ---- ---------------------------------------------------------------------
    /// Enabled bool If true, this simulator will be the master to synchronize simulators.
    ///

    class EnableMasterPps;
    typedef std::shared_ptr<EnableMasterPps> EnableMasterPpsPtr;
    
    
    class EnableMasterPps : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      EnableMasterPps();

      EnableMasterPps(bool enabled);

      static EnableMasterPpsPtr create(bool enabled);
      static EnableMasterPpsPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** enabled ****
      bool enabled() const;
      void setEnabled(bool enabled);
    };
    
  }
}

