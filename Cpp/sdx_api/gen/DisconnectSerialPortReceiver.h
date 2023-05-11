#pragma once

#include <memory>
#include "command_base.h"



namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Disconnects the connected receiver. Does nothing if no receiver is connected.
    ///
    /// 
    ///

    class DisconnectSerialPortReceiver;
    typedef std::shared_ptr<DisconnectSerialPortReceiver> DisconnectSerialPortReceiverPtr;
    
    
    class DisconnectSerialPortReceiver : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      DisconnectSerialPortReceiver();

      static DisconnectSerialPortReceiverPtr create();
      static DisconnectSerialPortReceiverPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;
    };
    
  }
}

