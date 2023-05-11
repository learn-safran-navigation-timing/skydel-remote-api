#pragma once

#include <memory>
#include "command_result.h"
#include "command_result_factory.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of IsTransmitMessage2InSbasMessage0.
    ///
    /// Name             Type Description
    /// ---------------- ---- ---------------------------------------------------------
    /// TransmitMessage2 bool Whether SBAS should transmit message type 2 instead of 0.
    ///

    class IsTransmitMessage2InSbasMessage0Result;
    typedef std::shared_ptr<IsTransmitMessage2InSbasMessage0Result> IsTransmitMessage2InSbasMessage0ResultPtr;
    
    
    class IsTransmitMessage2InSbasMessage0Result : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      IsTransmitMessage2InSbasMessage0Result();

      IsTransmitMessage2InSbasMessage0Result(bool transmitMessage2);

      IsTransmitMessage2InSbasMessage0Result(CommandBasePtr relatedCommand, bool transmitMessage2);

      static IsTransmitMessage2InSbasMessage0ResultPtr create(bool transmitMessage2);

      static IsTransmitMessage2InSbasMessage0ResultPtr create(CommandBasePtr relatedCommand, bool transmitMessage2);
      static IsTransmitMessage2InSbasMessage0ResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;


      // **** transmitMessage2 ****
      bool transmitMessage2() const;
      void setTransmitMessage2(bool transmitMessage2);
    };
    REGISTER_COMMAND_RESULT_TO_FACTORY_DECL(IsTransmitMessage2InSbasMessage0Result);
  }
}

