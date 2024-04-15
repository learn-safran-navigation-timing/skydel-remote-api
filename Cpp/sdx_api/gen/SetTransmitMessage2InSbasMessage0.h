#pragma once

#include <memory>
#include "command_base.h"



namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Set whether SBAS should transmit message 2 instead of message 0.
    ///
    /// Name             Type Description
    /// ---------------- ---- ---------------------------------------------------------
    /// TransmitMessage2 bool Whether SBAS should transmit message type 2 instead of 0.
    ///

    class SetTransmitMessage2InSbasMessage0;
    typedef std::shared_ptr<SetTransmitMessage2InSbasMessage0> SetTransmitMessage2InSbasMessage0Ptr;
    
    
    class SetTransmitMessage2InSbasMessage0 : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      SetTransmitMessage2InSbasMessage0();

      SetTransmitMessage2InSbasMessage0(bool transmitMessage2);

      static SetTransmitMessage2InSbasMessage0Ptr create(bool transmitMessage2);
      static SetTransmitMessage2InSbasMessage0Ptr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;

      virtual int executePermission() const override;


      // **** transmitMessage2 ****
      bool transmitMessage2() const;
      void setTransmitMessage2(bool transmitMessage2);
    };
    
  }
}

