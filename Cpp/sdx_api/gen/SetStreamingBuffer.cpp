
#include "SetStreamingBuffer.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetStreamingBuffer
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetStreamingBuffer::CmdName = "SetStreamingBuffer";
    const char* const SetStreamingBuffer::Documentation = "Set streaming buffer size.\n"
      "\n"
      "Name Type Description\n"
      "---- ---- -----------------------------\n"
      "Size int  Streaming buffer size in msec";
    const char* const SetStreamingBuffer::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(SetStreamingBuffer);
    REGISTER_COMMAND_TO_FACTORY_IMPL(SetStreamingBuffer);


    SetStreamingBuffer::SetStreamingBuffer()
      : CommandBase(CmdName, TargetId)
    {}

    SetStreamingBuffer::SetStreamingBuffer(int size)
      : CommandBase(CmdName, TargetId)
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

    const std::vector<std::string>& SetStreamingBuffer::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Size"}; 
      return names; 
    }


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
