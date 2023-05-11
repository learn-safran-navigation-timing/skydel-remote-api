
#include "gen/SetStreamingBuffer.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetStreamingBuffer
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetStreamingBuffer::CmdName = "SetStreamingBuffer";
    const char* const SetStreamingBuffer::Documentation = "Set streaming buffer size.";

    REGISTER_COMMAND_FACTORY(SetStreamingBuffer);


    SetStreamingBuffer::SetStreamingBuffer()
      : CommandBase(CmdName)
    {}

    SetStreamingBuffer::SetStreamingBuffer(int size)
      : CommandBase(CmdName)
    {

      setSize(size);
    }

    SetStreamingBufferPtr SetStreamingBuffer::create(int size)
    {
      return std::make_shared<SetStreamingBuffer>(size);
    }

    SetStreamingBufferPtr SetStreamingBuffer::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetStreamingBuffer>(ptr);
    }

    bool SetStreamingBuffer::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["Size"])
        ;

    }

    std::string SetStreamingBuffer::documentation() const { return Documentation; }


    int SetStreamingBuffer::executePermission() const
    {
      return EXECUTE_IF_NO_CONFIG | EXECUTE_IF_IDLE;
    }


    int SetStreamingBuffer::size() const
    {
      return parse_json<int>::parse(m_values["Size"]);
    }

    void SetStreamingBuffer::setSize(int size)
    {
      m_values.AddMember("Size", parse_json<int>::format(size, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
