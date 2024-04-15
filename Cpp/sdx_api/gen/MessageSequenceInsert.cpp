
#include "MessageSequenceInsert.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of MessageSequenceInsert
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const MessageSequenceInsert::CmdName = "MessageSequenceInsert";
    const char* const MessageSequenceInsert::Documentation = "Insert message to sequence.\n"
      "\n"
      "Name   Type   Description\n"
      "------ ------ -----------------------------------------------------------------------------------------------------------\n"
      "Signal string Signal Name (\"L2C\" for example)\n"
      "Index  int    Message index in sequence where to insert. Set to -1 to append the message type at the end of the sequence.\n"
      "Type   int    Message type to insert";
    const char* const MessageSequenceInsert::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(MessageSequenceInsert);
    REGISTER_COMMAND_TO_FACTORY_IMPL(MessageSequenceInsert);


    MessageSequenceInsert::MessageSequenceInsert()
      : CommandBase(CmdName, TargetId)
    {}

    MessageSequenceInsert::MessageSequenceInsert(const std::string& signal, int index, int type)
      : CommandBase(CmdName, TargetId)
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

    const std::vector<std::string>& MessageSequenceInsert::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Signal", "Index", "Type"}; 
      return names; 
    }


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
