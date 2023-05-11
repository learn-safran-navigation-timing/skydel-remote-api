
#include "gen/GetAlmanacInitialUploadTimeOffsetResult.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetAlmanacInitialUploadTimeOffsetResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetAlmanacInitialUploadTimeOffsetResult::CmdName = "GetAlmanacInitialUploadTimeOffsetResult";
    const char* const GetAlmanacInitialUploadTimeOffsetResult::Documentation = "Result of GetAlmanacInitialUploadTimeOffset.";

    REGISTER_COMMAND_RESULT_TO_FACTORY_IMPL(GetAlmanacInitialUploadTimeOffsetResult);


    GetAlmanacInitialUploadTimeOffsetResult::GetAlmanacInitialUploadTimeOffsetResult()
      : CommandResult(CmdName)
    {}

    GetAlmanacInitialUploadTimeOffsetResult::GetAlmanacInitialUploadTimeOffsetResult(const std::string& system, int offset)
      : CommandResult(CmdName)
    {

      setSystem(system);
      setOffset(offset);
    }

    GetAlmanacInitialUploadTimeOffsetResult::GetAlmanacInitialUploadTimeOffsetResult(CommandBasePtr relatedCommand, const std::string& system, int offset)
      : CommandResult(CmdName, relatedCommand)
    {

      setSystem(system);
      setOffset(offset);
    }


    GetAlmanacInitialUploadTimeOffsetResultPtr GetAlmanacInitialUploadTimeOffsetResult::create(const std::string& system, int offset)
    {
      return std::make_shared<GetAlmanacInitialUploadTimeOffsetResult>(system, offset);
    }

    GetAlmanacInitialUploadTimeOffsetResultPtr GetAlmanacInitialUploadTimeOffsetResult::create(CommandBasePtr relatedCommand, const std::string& system, int offset)
    {
      return std::make_shared<GetAlmanacInitialUploadTimeOffsetResult>(relatedCommand, system, offset);
    }

    GetAlmanacInitialUploadTimeOffsetResultPtr GetAlmanacInitialUploadTimeOffsetResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetAlmanacInitialUploadTimeOffsetResult>(ptr);
    }

    bool GetAlmanacInitialUploadTimeOffsetResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["System"])
          && parse_json<int>::is_valid(m_values["Offset"])
        ;

    }

    std::string GetAlmanacInitialUploadTimeOffsetResult::documentation() const { return Documentation; }


    std::string GetAlmanacInitialUploadTimeOffsetResult::system() const
    {
      return parse_json<std::string>::parse(m_values["System"]);
    }

    void GetAlmanacInitialUploadTimeOffsetResult::setSystem(const std::string& system)
    {
      m_values.AddMember("System", parse_json<std::string>::format(system, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int GetAlmanacInitialUploadTimeOffsetResult::offset() const
    {
      return parse_json<int>::parse(m_values["Offset"]);
    }

    void GetAlmanacInitialUploadTimeOffsetResult::setOffset(int offset)
    {
      m_values.AddMember("Offset", parse_json<int>::format(offset, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
