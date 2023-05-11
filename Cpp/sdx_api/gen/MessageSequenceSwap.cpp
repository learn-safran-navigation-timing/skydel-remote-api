
#include "gen/MessageSequenceSwap.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of MessageSequenceSwap
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const MessageSequenceSwap::CmdName = "MessageSequenceSwap";
    const char* const MessageSequenceSwap::Documentation = "Swap 2 messages in sequence.";

    REGISTER_COMMAND_FACTORY(MessageSequenceSwap);


    MessageSequenceSwap::MessageSequenceSwap()
      : CommandBase(CmdName)
    {}

    MessageSequenceSwap::MessageSequenceSwap(const std::string& signal, int indexI, int indexJ)
      : CommandBase(CmdName)
    {

      setSignal(signal);
      setIndexI(indexI);
      setIndexJ(indexJ);
    }

    MessageSequenceSwapPtr MessageSequenceSwap::create(const std::string& signal, int indexI, int indexJ)
    {
      return std::make_shared<MessageSequenceSwap>(signal, indexI, indexJ);
    }

    MessageSequenceSwapPtr MessageSequenceSwap::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<MessageSequenceSwap>(ptr);
    }

    bool MessageSequenceSwap::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["Signal"])
          && parse_json<int>::is_valid(m_values["IndexI"])
          && parse_json<int>::is_valid(m_values["IndexJ"])
        ;

    }

    std::string MessageSequenceSwap::documentation() const { return Documentation; }


    int MessageSequenceSwap::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string MessageSequenceSwap::signal() const
    {
      return parse_json<std::string>::parse(m_values["Signal"]);
    }

    void MessageSequenceSwap::setSignal(const std::string& signal)
    {
      m_values.AddMember("Signal", parse_json<std::string>::format(signal, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int MessageSequenceSwap::indexI() const
    {
      return parse_json<int>::parse(m_values["IndexI"]);
    }

    void MessageSequenceSwap::setIndexI(int indexI)
    {
      m_values.AddMember("IndexI", parse_json<int>::format(indexI, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int MessageSequenceSwap::indexJ() const
    {
      return parse_json<int>::parse(m_values["IndexJ"]);
    }

    void MessageSequenceSwap::setIndexJ(int indexJ)
    {
      m_values.AddMember("IndexJ", parse_json<int>::format(indexJ, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
