
#include "MessageSequenceRemove.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of MessageSequenceRemove
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const MessageSequenceRemove::CmdName = "MessageSequenceRemove";
    const char* const MessageSequenceRemove::Documentation = "Remove message from sequence.\n"
      "\n"
      "Name   Type   Description\n"
      "------ ------ ----------------------------------------------------------------------------------------\n"
      "Signal string Signal Name (\"L2C\" for example)\n"
      "Index  int    Message index in sequence where to remove. Set to -1 to remove last message in sequence.";
    const char* const MessageSequenceRemove::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(MessageSequenceRemove);
    REGISTER_COMMAND_TO_FACTORY_IMPL(MessageSequenceRemove);


    MessageSequenceRemove::MessageSequenceRemove()
      : CommandBase(CmdName, TargetId)
    {}

    MessageSequenceRemove::MessageSequenceRemove(const std::string& signal, int index)
      : CommandBase(CmdName, TargetId)
    {

      setSignal(signal);
      setIndex(index);
    }

    MessageSequenceRemovePtr MessageSequenceRemove::create(const std::string& signal, int index)
    {
      return std::make_shared<MessageSequenceRemove>(signal, index);
    }

    MessageSequenceRemovePtr MessageSequenceRemove::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<MessageSequenceRemove>(ptr);
    }

    bool MessageSequenceRemove::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["Signal"])
          && parse_json<int>::is_valid(m_values["Index"])
        ;

    }

    std::string MessageSequenceRemove::documentation() const { return Documentation; }

    const std::vector<std::string>& MessageSequenceRemove::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Signal", "Index"}; 
      return names; 
    }


    int MessageSequenceRemove::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string MessageSequenceRemove::signal() const
    {
      return parse_json<std::string>::parse(m_values["Signal"]);
    }

    void MessageSequenceRemove::setSignal(const std::string& signal)
    {
      m_values.AddMember("Signal", parse_json<std::string>::format(signal, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int MessageSequenceRemove::index() const
    {
      return parse_json<int>::parse(m_values["Index"]);
    }

    void MessageSequenceRemove::setIndex(int index)
    {
      m_values.AddMember("Index", parse_json<int>::format(index, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
