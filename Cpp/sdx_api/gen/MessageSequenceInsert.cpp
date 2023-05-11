
#include "gen/MessageSequenceInsert.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of MessageSequenceInsert
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const MessageSequenceInsert::CmdName = "MessageSequenceInsert";
    const char* const MessageSequenceInsert::Documentation = "Insert message to sequence.";

    REGISTER_COMMAND_FACTORY(MessageSequenceInsert);


    MessageSequenceInsert::MessageSequenceInsert()
      : CommandBase(CmdName)
    {}

    MessageSequenceInsert::MessageSequenceInsert(const std::string& signal, int index, int type)
      : CommandBase(CmdName)
    {

      setSignal(signal);
      setIndex(index);
      setType(type);
    }

    MessageSequenceInsertPtr MessageSequenceInsert::create(const std::string& signal, int index, int type)
    {
      return std::make_shared<MessageSequenceInsert>(signal, index, type);
    }

    MessageSequenceInsertPtr MessageSequenceInsert::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<MessageSequenceInsert>(ptr);
    }

    bool MessageSequenceInsert::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["Signal"])
          && parse_json<int>::is_valid(m_values["Index"])
          && parse_json<int>::is_valid(m_values["Type"])
        ;

    }

    std::string MessageSequenceInsert::documentation() const { return Documentation; }


    int MessageSequenceInsert::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string MessageSequenceInsert::signal() const
    {
      return parse_json<std::string>::parse(m_values["Signal"]);
    }

    void MessageSequenceInsert::setSignal(const std::string& signal)
    {
      m_values.AddMember("Signal", parse_json<std::string>::format(signal, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int MessageSequenceInsert::index() const
    {
      return parse_json<int>::parse(m_values["Index"]);
    }

    void MessageSequenceInsert::setIndex(int index)
    {
      m_values.AddMember("Index", parse_json<int>::format(index, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int MessageSequenceInsert::type() const
    {
      return parse_json<int>::parse(m_values["Type"]);
    }

    void MessageSequenceInsert::setType(int type)
    {
      m_values.AddMember("Type", parse_json<int>::format(type, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
