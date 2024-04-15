#pragma once

#include <memory>
#include "command_result.h"
#include "command_factory.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of IsUsingVelocityInSbasMessage25.
    ///
    /// Name        Type Description
    /// ----------- ---- --------------------------------------------------------
    /// UseVelocity bool Whether SBAS message 25 should send velocity corrections
    ///

    class IsUsingVelocityInSbasMessage25Result;
    typedef std::shared_ptr<IsUsingVelocityInSbasMessage25Result> IsUsingVelocityInSbasMessage25ResultPtr;
    
    
    class IsUsingVelocityInSbasMessage25Result : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      IsUsingVelocityInSbasMessage25Result();

      IsUsingVelocityInSbasMessage25Result(bool useVelocity);

      IsUsingVelocityInSbasMessage25Result(CommandBasePtr relatedCommand, bool useVelocity);

      static IsUsingVelocityInSbasMessage25ResultPtr create(bool useVelocity);

      static IsUsingVelocityInSbasMessage25ResultPtr create(CommandBasePtr relatedCommand, bool useVelocity);
      static IsUsingVelocityInSbasMessage25ResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;


      // **** useVelocity ****
      bool useVelocity() const;
      void setUseVelocity(bool useVelocity);
    };
    REGISTER_COMMAND_TO_FACTORY_DECL(IsUsingVelocityInSbasMessage25Result);
  }
}

