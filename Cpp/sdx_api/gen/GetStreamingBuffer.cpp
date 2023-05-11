
#include "gen/GetStreamingBuffer.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetStreamingBuffer
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetStreamingBuffer::CmdName = "GetStreamingBuffer";
    const char* const GetStreamingBuffer::Documentation = "Get streaming buffer size.";

    REGISTER_COMMAND_FACTORY(GetStreamingBuffer);


    GetStreamingBuffer::GetStreamingBuffer()
      : CommandBase(CmdName)
    {

    }

    GetStreamingBufferPtr GetStreamingBuffer::create()
    {
      return std::make_shared<GetStreamingBuffer>();
    }

    GetStreamingBufferPtr GetStreamingBuffer::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetStreamingBuffer>(ptr);
    }

    bool GetStreamingBuffer::isValid() const
    {
      
        return m_values.IsObject()
        ;

    }

    std::string GetStreamingBuffer::documentation() const { return Documentation; }


    int GetStreamingBuffer::executePermission() const
    {
      return EXECUTE_IF_NO_CONFIG | EXECUTE_IF_IDLE | EXECUTE_IF_SIMULATING;
    }

  }
}
