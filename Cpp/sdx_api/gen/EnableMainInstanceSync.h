#pragma once

#include <memory>
#include "command_base.h"



namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Enable/Disable Time Synchronization on main instance.
    /// The main instance will control other Skydel simulators with main instance PPS Enabled.
    ///
    /// Name    Type Description
    /// ------- ---- ----------------------------------------------------------------------------
    /// Enabled bool If true, this simulator will be the main instance to synchronize simulators.
    ///

    class EnableMainInstanceSync;
    typedef std::shared_ptr<EnableMainInstanceSync> EnableMainInstanceSyncPtr;
    
    
    class EnableMainInstanceSync : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      EnableMainInstanceSync();

      EnableMainInstanceSync(bool enabled);

      static EnableMainInstanceSyncPtr create(bool enabled);
      static EnableMainInstanceSyncPtr dynamicCast(CommandBasePtr ptr);
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

