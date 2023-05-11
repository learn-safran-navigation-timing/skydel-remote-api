#pragma once

#include <memory>
#include "command_base.h"

#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Insert message to sequence.
    ///
    /// Name   Type   Description
    /// ------ ------ -----------------------------------------------------------------------------------------------------------
    /// Signal string Signal Name ("L2C" for example)
    /// Index  int    Message index in sequence where to insert. Set to -1 to append the message type at the end of the sequence.
    /// Type   int    Message type to insert
    ///

    class MessageSequenceInsert;
    typedef std::shared_ptr<MessageSequenceInsert> MessageSequenceInsertPtr;
    
    
    class MessageSequenceInsert : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      MessageSequenceInsert();

      MessageSequenceInsert(const std::string& signal, int index, int type);

      static MessageSequenceInsertPtr create(const std::string& signal, int index, int type);
      static MessageSequenceInsertPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** signal ****
      std::string signal() const;
      void setSignal(const std::string& signal);


      // **** index ****
      int index() const;
      void setIndex(int index);


      // **** type ****
      int type() const;
      void setType(int type);
    };
    
  }
}

