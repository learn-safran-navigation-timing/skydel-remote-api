#pragma once

#include <memory>
#include "command_base.h"

#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Get Skips all encryption messages in the message sequence of the given signal.
    ///
    /// Name   Type   Description
    /// ------ ------ --------------------------------------------------------
    /// Signal string Signal key, accepted values : "PULSARX1" and "PULSARX5".
    ///

    class IsEncryptionNavMessageSkipped;
    typedef std::shared_ptr<IsEncryptionNavMessageSkipped> IsEncryptionNavMessageSkippedPtr;
    
    
    class IsEncryptionNavMessageSkipped : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      IsEncryptionNavMessageSkipped();

      IsEncryptionNavMessageSkipped(const std::string& signal);

      static IsEncryptionNavMessageSkippedPtr create(const std::string& signal);
      static IsEncryptionNavMessageSkippedPtr dynamicCast(CommandBasePtr ptr);
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

