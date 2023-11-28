#pragma once

#include <memory>
#include "command_base.h"



namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Get wether the main instance should send its configuration to every worker instance when simulation start.
    ///
    /// 
    ///

    class GetConfigBroadcastOnStart;
    typedef std::shared_ptr<GetConfigBroadcastOnStart> GetConfigBroadcastOnStartPtr;
    
    
    class GetConfigBroadcastOnStart : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetConfigBroadcastOnStart();

      static GetConfigBroadcastOnStartPtr create();
      static GetConfigBroadcastOnStartPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;
    };
    
  }
}

