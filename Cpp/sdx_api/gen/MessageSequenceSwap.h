#pragma once

#include <memory>
#include "command_base.h"

#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Swap 2 messages in sequence.
    ///
    /// Name   Type   Description
    /// ------ ------ -------------------------------
    /// Signal string Signal Name ("L2C" for example)
    /// IndexI int    Message index i in sequence.
    /// IndexJ int    Message index j in sequence.
    ///

    class MessageSequenceSwap;
    typedef std::shared_ptr<MessageSequenceSwap> MessageSequenceSwapPtr;
    
    
    class MessageSequenceSwap : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      MessageSequenceSwap();

      MessageSequenceSwap(const std::string& signal, int indexI, int indexJ);

      static MessageSequenceSwapPtr create(const std::string& signal, int indexI, int indexJ);
      static MessageSequenceSwapPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;

      virtual int executePermission() const override;


      // **** signal ****
      std::string signal() const;
      void setSignal(const std::string& signal);


      // **** indexI ****
      int indexI() const;
      void setIndexI(int indexI);


      // **** indexJ ****
      int indexJ() const;
      void setIndexJ(int indexJ);
    };
    
  }
}

