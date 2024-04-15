
#include "GetMessageSequenceResult.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetMessageSequenceResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetMessageSequenceResult::CmdName = "GetMessageSequenceResult";
    const char* const GetMessageSequenceResult::Documentation = "Result of GetMessageSequence.\n"
      "\n"
      "Name     Type      Description\n"
      "-------- --------- -------------------------------\n"
      "Signal   string    Signal Name (\"L2C\" for example)\n"
      "Sequence array int List of message type";
    const char* const GetMessageSequenceResult::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_IMPL(GetMessageSequenceResult);


    GetMessageSequenceResult::GetMessageSequenceResult()
      : CommandResult(CmdName, TargetId)
    {}

    GetMessageSequenceResult::GetMessageSequenceResult(const std::string& signal, const std::vector<int>& sequence)
      : CommandResult(CmdName, TargetId)
    {

      setSignal(signal);
      setSequence(sequence);
    }

    GetMessageSequenceResult::GetMessageSequenceResult(CommandBasePtr relatedCommand, const std::string& signal, const std::vector<int>& sequence)
      : CommandResult(CmdName, TargetId, relatedCommand)
    {

      setSignal(signal);
      setSequence(sequence);
    }


    GetMessageSequenceResultPtr GetMessageSequenceResult::create(const std::string& signal, const std::vector<int>& sequence)
    {
      return std::make_shared<GetMessageSequenceResult>(signal, sequence);
    }

    GetMessageSequenceResultPtr GetMessageSequenceResult::create(CommandBasePtr relatedCommand, const std::string& signal, const std::vector<int>& sequence)
    {
      return std::make_shared<GetMessageSequenceResult>(relatedCommand, signal, sequence);
    }

    GetMessageSequenceResultPtr GetMessageSequenceResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetMessageSequenceResult>(ptr);
    }

    bool GetMessageSequenceResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["Signal"])
          && parse_json<std::vector<int>>::is_valid(m_values["Sequence"])
        ;

    }

    std::string GetMessageSequenceResult::documentation() const { return Documentation; }

    const std::vector<std::string>& GetMessageSequenceResult::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Signal", "Sequence"}; 
      return names; 
    }


    std::string GetMessageSequenceResult::signal() const
    {
      return parse_json<std::string>::parse(m_values["Signal"]);
    }

    void GetMessageSequenceResult::setSignal(const std::string& signal)
    {
      m_values.AddMember("Signal", parse_json<std::string>::format(signal, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::vector<int> GetMessageSequenceResult::sequence() const
    {
      return parse_json<std::vector<int>>::parse(m_values["Sequence"]);
    }

    void GetMessageSequenceResult::setSequence(const std::vector<int>& sequence)
    {
      m_values.AddMember("Sequence", parse_json<std::vector<int>>::format(sequence, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
