#pragma once

#include <memory>
#include "command_base.h"



namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Ask the main instance to broadcast its configuration to all worker instances.
    ///
    /// 
    ///

    class BroadcastConfig;
    typedef std::shared_ptr<BroadcastConfig> BroadcastConfigPtr;
    
    
    class BroadcastConfig : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      BroadcastConfig();

      static BroadcastConfigPtr create();
      static BroadcastConfigPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;
    };
    
  }
}

