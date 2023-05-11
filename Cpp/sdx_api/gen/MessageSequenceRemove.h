#pragma once

#include <memory>
#include "command_base.h"

#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Remove message from sequence.
    ///
    /// Name   Type   Description
    /// ------ ------ ----------------------------------------------------------------------------------------
    /// Signal string Signal Name ("L2C" for example)
    /// Index  int    Message index in sequence where to remove. Set to -1 to remove last message in sequence.
    ///

    class MessageSequenceRemove;
    typedef std::shared_ptr<MessageSequenceRemove> MessageSequenceRemovePtr;
    
    
    class MessageSequenceRemove : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      MessageSequenceRemove();

      MessageSequenceRemove(const std::string& signal, int index);

      static MessageSequenceRemovePtr create(const std::string& signal, int index);
      static MessageSequenceRemovePtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** signal ****
      std::string signal() const;
      void setSignal(const std::string& signal);


      // **** index ****
      int index() const;
      void setIndex(int index);
    };
    
  }
}

