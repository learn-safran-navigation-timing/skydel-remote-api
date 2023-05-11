
#include "gen/LogRawRateResult.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of LogRawRateResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const LogRawRateResult::CmdName = "LogRawRateResult";
    const char* const LogRawRateResult::Documentation = "Result of GetLogRawRate.";

    REGISTER_COMMAND_RESULT_TO_FACTORY_IMPL(LogRawRateResult);


    LogRawRateResult::LogRawRateResult()
      : CommandResult(CmdName)
    {}

    LogRawRateResult::LogRawRateResult(int rate)
      : CommandResult(CmdName)
    {

      setRate(rate);
    }

    LogRawRateResult::LogRawRateResult(CommandBasePtr relatedCommand, int rate)
      : CommandResult(CmdName, relatedCommand)
    {

      setRate(rate);
    }


    LogRawRateResultPtr LogRawRateResult::create(int rate)
    {
      return std::make_shared<LogRawRateResult>(rate);
    }

    LogRawRateResultPtr LogRawRateResult::create(CommandBasePtr relatedCommand, int rate)
    {
      return std::make_shared<LogRawRateResult>(relatedCommand, rate);
    }

    LogRawRateResultPtr LogRawRateResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<LogRawRateResult>(ptr);
    }

    bool LogRawRateResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["Rate"])
        ;

    }

    std::string LogRawRateResult::documentation() const { return Documentation; }


    int LogRawRateResult::rate() const
    {
      return parse_json<int>::parse(m_values["Rate"]);
    }

    void LogRawRateResult::setRate(int rate)
    {
      m_values.AddMember("Rate", parse_json<int>::format(rate, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
