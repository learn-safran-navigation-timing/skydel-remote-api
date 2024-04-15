
#include "GetStreamingBufferResult.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetStreamingBufferResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetStreamingBufferResult::CmdName = "GetStreamingBufferResult";
    const char* const GetStreamingBufferResult::Documentation = "Result of GetStreamingBuffer.\n"
      "\n"
      "Name Type Description\n"
      "---- ---- -----------------------------\n"
      "Size int  Streaming buffer size in msec";
    const char* const GetStreamingBufferResult::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_IMPL(GetStreamingBufferResult);


    GetStreamingBufferResult::GetStreamingBufferResult()
      : CommandResult(CmdName, TargetId)
    {}

    GetStreamingBufferResult::GetStreamingBufferResult(int size)
      : CommandResult(CmdName, TargetId)
    {

      setSize(size);
    }

    GetStreamingBufferResult::GetStreamingBufferResult(CommandBasePtr relatedCommand, int size)
      : CommandResult(CmdName, TargetId, relatedCommand)
    {

      setSize(size);
    }


    GetStreamingBufferResultPtr GetStreamingBufferResult::create(int size)
    {
      return std::make_shared<GetStreamingBufferResult>(size);
    }

    GetStreamingBufferResultPtr GetStreamingBufferResult::create(CommandBasePtr relatedCommand, int size)
    {
      return std::make_shared<GetStreamingBufferResult>(relatedCommand, size);
    }

    GetStreamingBufferResultPtr GetStreamingBufferResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetStreamingBufferResult>(ptr);
    }

    bool GetStreamingBufferResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["Size"])
        ;

    }

    std::string GetStreamingBufferResult::documentation() const { return Documentation; }

    const std::vector<std::string>& GetStreamingBufferResult::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Size"}; 
      return names; 
    }


    int GetStreamingBufferResult::size() const
    {
      return parse_json<int>::parse(m_values["Size"]);
    }

    void GetStreamingBufferResult::setSize(int size)
    {
      m_values.AddMember("Size", parse_json<int>::format(size, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
