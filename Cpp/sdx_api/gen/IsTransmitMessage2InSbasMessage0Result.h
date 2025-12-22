#pragma once

#include <memory>
#include "command_result.h"
#include "command_factory.h"
#include <optional>
#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of IsTransmitMessage2InSbasMessage0.
    ///
    /// Name             Type            Description
    /// ---------------- --------------- ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    /// TransmitMessage2 bool            Whether SBAS should transmit message type 2 instead of 0.
    /// ServiceProvider  optional string The service provider. When not specified for a Setter command, the change is applied to all service providers. When not specified for a Getter command, the value for WAAS is returned.
    ///

    class IsTransmitMessage2InSbasMessage0Result;
    typedef std::shared_ptr<IsTransmitMessage2InSbasMessage0Result> IsTransmitMessage2InSbasMessage0ResultPtr;
    
    
    class IsTransmitMessage2InSbasMessage0Result : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      IsTransmitMessage2InSbasMessage0Result();

      IsTransmitMessage2InSbasMessage0Result(bool transmitMessage2, const std::optional<std::string>& serviceProvider = {});

      IsTransmitMessage2InSbasMessage0Result(CommandBasePtr relatedCommand, bool transmitMessage2, const std::optional<std::string>& serviceProvider = {});

      static IsTransmitMessage2InSbasMessage0ResultPtr create(bool transmitMessage2, const std::optional<std::string>& serviceProvider = {});

      static IsTransmitMessage2InSbasMessage0ResultPtr create(CommandBasePtr relatedCommand, bool transmitMessage2, const std::optional<std::string>& serviceProvider = {});
      static IsTransmitMessage2InSbasMessage0ResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;


      // **** transmitMessage2 ****
      bool transmitMessage2() const;
      void setTransmitMessage2(bool transmitMessage2);


      // **** serviceProvider ****
      std::optional<std::string> serviceProvider() const;
      void setServiceProvider(const std::optional<std::string>& serviceProvider);
    };
    REGISTER_COMMAND_TO_FACTORY_DECL(IsTransmitMessage2InSbasMessage0Result);
  }
}

