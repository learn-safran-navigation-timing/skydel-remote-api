#pragma once

#include <memory>
#include "command_base.h"



namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Cancel the current configuration broadcast if any.
    ///
    /// 
    ///

    class CancelBroadcastConfig;
    typedef std::shared_ptr<CancelBroadcastConfig> CancelBroadcastConfigPtr;
    
    
    class CancelBroadcastConfig : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      CancelBroadcastConfig();

      static CancelBroadcastConfigPtr create();
      static CancelBroadcastConfigPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;
    };
    
  }
}

