
#include "GetStreamingBuffer.h"

#include "command_factory.h"
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
    const char* const GetStreamingBuffer::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(GetStreamingBuffer);
    REGISTER_COMMAND_TO_FACTORY_IMPL(GetStreamingBuffer);


    GetStreamingBuffer::GetStreamingBuffer()
      : CommandBase(CmdName, TargetId)
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

    const std::vector<std::string>& GetStreamingBuffer::fieldNames() const 
    { 
      static const std::vector<std::string> names {}; 
      return names; 
    }


    int GetStreamingBuffer::executePermission() const
    {
      return EXECUTE_IF_NO_CONFIG | EXECUTE_IF_IDLE | EXECUTE_IF_SIMULATING;
    }

  }
}
