#pragma once

#include <memory>
#include "command_base.h"

#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Get Skips all authentication messages in the message sequence of the given signal.
    ///
    /// Name   Type   Description
    /// ------ ------ --------------------------------------------------------
    /// Signal string Signal key, accepted values : "PULSARX1" and "PULSARX5".
    ///

    class IsAuthenticationNavMessageSkipped;
    typedef std::shared_ptr<IsAuthenticationNavMessageSkipped> IsAuthenticationNavMessageSkippedPtr;
    
    
    class IsAuthenticationNavMessageSkipped : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      IsAuthenticationNavMessageSkipped();

      IsAuthenticationNavMessageSkipped(const std::string& signal);

      static IsAuthenticationNavMessageSkippedPtr create(const std::string& signal);
      static IsAuthenticationNavMessageSkippedPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;

      virtual int executePermission() const override;


      // **** signal ****
      std::string signal() const;
      void setSignal(const std::string& signal);
    };
    
  }
}

