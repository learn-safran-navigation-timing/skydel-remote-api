
#include "gen/GetMessageSequence.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetMessageSequence
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetMessageSequence::CmdName = "GetMessageSequence";
    const char* const GetMessageSequence::Documentation = "Get the messages sequence for the signal";

    REGISTER_COMMAND_FACTORY(GetMessageSequence);


    GetMessageSequence::GetMessageSequence()
      : CommandBase(CmdName)
    {}

    GetMessageSequence::GetMessageSequence(const std::string& signal)
      : CommandBase(CmdName)
    {

      setSignal(signal);
    }

    GetMessageSequencePtr GetMessageSequence::create(const std::string& signal)
    {
      return std::make_shared<GetMessageSequence>(signal);
    }

    GetMessageSequencePtr GetMessageSequence::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetMessageSequence>(ptr);
    }

    bool GetMessageSequence::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["Signal"])
        ;

    }

    std::string GetMessageSequence::documentation() const { return Documentation; }


    int GetMessageSequence::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string GetMessageSequence::signal() const
    {
      return parse_json<std::string>::parse(m_values["Signal"]);
    }

    void GetMessageSequence::setSignal(const std::string& signal)
    {
      m_values.AddMember("Signal", parse_json<std::string>::format(signal, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
