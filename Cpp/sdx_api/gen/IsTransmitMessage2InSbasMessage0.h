#pragma once

#include <memory>
#include "command_base.h"



namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Get whether SBAS should transmit message 2 instead of message 0.
    ///
    /// 
    ///

    class IsTransmitMessage2InSbasMessage0;
    typedef std::shared_ptr<IsTransmitMessage2InSbasMessage0> IsTransmitMessage2InSbasMessage0Ptr;
    
    
    class IsTransmitMessage2InSbasMessage0 : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      IsTransmitMessage2InSbasMessage0();

      static IsTransmitMessage2InSbasMessage0Ptr create();
      static IsTransmitMessage2InSbasMessage0Ptr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;
    };
    
  }
}

