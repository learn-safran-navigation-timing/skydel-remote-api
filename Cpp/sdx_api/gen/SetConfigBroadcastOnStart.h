#pragma once

#include <memory>
#include "command_base.h"



namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Set wether the master should send its configuration to every slave when simulation start.
    ///
    /// Name             Type Description
    /// ---------------- ---- --------------------------------------------------------------
    /// BroadcastOnStart bool True to broadcast the configuration on start, false otherwise.
    ///

    class SetConfigBroadcastOnStart;
    typedef std::shared_ptr<SetConfigBroadcastOnStart> SetConfigBroadcastOnStartPtr;
    
    
    class SetConfigBroadcastOnStart : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      SetConfigBroadcastOnStart();

      SetConfigBroadcastOnStart(bool broadcastOnStart);

      static SetConfigBroadcastOnStartPtr create(bool broadcastOnStart);
      static SetConfigBroadcastOnStartPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** broadcastOnStart ****
      bool broadcastOnStart() const;
      void setBroadcastOnStart(bool broadcastOnStart);
    };
    
  }
}

