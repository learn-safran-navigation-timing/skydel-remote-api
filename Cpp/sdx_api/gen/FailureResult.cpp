
#include "gen/FailureResult.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of FailureResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const FailureResult::CmdName = "FailureResult";
    const char* const FailureResult::Documentation = "When command failed";

    REGISTER_COMMAND_RESULT_TO_FACTORY_IMPL(FailureResult);


    FailureResult::FailureResult()
      : CommandResult(CmdName)
    {}

    FailureResult::FailureResult(const std::string& errorMsg)
      : CommandResult(CmdName)
    {

      setErrorMsg(errorMsg);
    }

    FailureResult::FailureResult(CommandBasePtr relatedCommand, const std::string& errorMsg)
      : CommandResult(CmdName, relatedCommand)
    {

      setErrorMsg(errorMsg);
    }


    FailureResultPtr FailureResult::create(const std::string& errorMsg)
    {
      return std::make_shared<FailureResult>(errorMsg);
    }

    FailureResultPtr FailureResult::create(CommandBasePtr relatedCommand, const std::string& errorMsg)
    {
      return std::make_shared<FailureResult>(relatedCommand, errorMsg);
    }

    FailureResultPtr FailureResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<FailureResult>(ptr);
    }

    bool FailureResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["ErrorMsg"])
        ;

    }

    std::string FailureResult::documentation() const { return Documentation; }


    std::string FailureResult::errorMsg() const
    {
      return parse_json<std::string>::parse(m_values["ErrorMsg"]);
    }

    void FailureResult::setErrorMsg(const std::string& errorMsg)
    {
      m_values.AddMember("ErrorMsg", parse_json<std::string>::format(errorMsg, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
