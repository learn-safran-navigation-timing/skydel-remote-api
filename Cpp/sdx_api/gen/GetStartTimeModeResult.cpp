
#include "gen/GetStartTimeModeResult.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetStartTimeModeResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetStartTimeModeResult::CmdName = "GetStartTimeModeResult";
    const char* const GetStartTimeModeResult::Documentation = "Result of GetStartTimeMode.";

    REGISTER_COMMAND_RESULT_TO_FACTORY_IMPL(GetStartTimeModeResult);


    GetStartTimeModeResult::GetStartTimeModeResult()
      : CommandResult(CmdName)
    {}

    GetStartTimeModeResult::GetStartTimeModeResult(const std::string& mode)
      : CommandResult(CmdName)
    {

      setMode(mode);
    }

    GetStartTimeModeResult::GetStartTimeModeResult(CommandBasePtr relatedCommand, const std::string& mode)
      : CommandResult(CmdName, relatedCommand)
    {

      setMode(mode);
    }


    GetStartTimeModeResultPtr GetStartTimeModeResult::create(const std::string& mode)
    {
      return std::make_shared<GetStartTimeModeResult>(mode);
    }

    GetStartTimeModeResultPtr GetStartTimeModeResult::create(CommandBasePtr relatedCommand, const std::string& mode)
    {
      return std::make_shared<GetStartTimeModeResult>(relatedCommand, mode);
    }

    GetStartTimeModeResultPtr GetStartTimeModeResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetStartTimeModeResult>(ptr);
    }

    bool GetStartTimeModeResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["Mode"])
        ;

    }

    std::string GetStartTimeModeResult::documentation() const { return Documentation; }


    std::string GetStartTimeModeResult::mode() const
    {
      return parse_json<std::string>::parse(m_values["Mode"]);
    }

    void GetStartTimeModeResult::setMode(const std::string& mode)
    {
      m_values.AddMember("Mode", parse_json<std::string>::format(mode, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
