#pragma once

#include <memory>
#include "command_base.h"

#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Get the messages sequence for the signal
    ///
    /// Name   Type   Description
    /// ------ ------ -------------------------------
    /// Signal string Signal Name ("L2C" for example)
    ///

    class GetMessageSequence;
    typedef std::shared_ptr<GetMessageSequence> GetMessageSequencePtr;
    
    
    class GetMessageSequence : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetMessageSequence();

      GetMessageSequence(const std::string& signal);

      static GetMessageSequencePtr create(const std::string& signal);
      static GetMessageSequencePtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** signal ****
      std::string signal() const;
      void setSignal(const std::string& signal);
    };
    
  }
}

